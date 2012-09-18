/* Playtomic iOS API
 -----------------------------------------------------------------------
 Documentation is available at:
 https://playtomic.com/api/ios
 
 Support is available at:
 https://playtomic.com/community
 https://playtomic.com/issues
 https://playtomic.com/support has more options if you're a premium user
 
 Github repositories:
 https://github.com/playtomic
 
 You may modify this SDK if you wish but be kind to our servers.  Be
 careful about modifying the analytics stuff as it may give you
 borked reports.
 
 Pull requests are welcome if you spot a bug or know a more efficient
 way to implement something.
 
 Copyright (c) 2011 Playtomic Inc.  Playtomic APIs and SDKs are licensed
 under the MIT license.  Certain portions may come from 3rd parties and
 carry their own licensing terms and are referenced where applicable.
 */

#import "Playtomic.h"
#import "Reachability.h"

@interface Playtomic ()
@property (nonatomic,readwrite) NSInteger gameId;
@property (nonatomic,copy) NSString *gameGuid;
@property (nonatomic,copy) NSString *sourceUrl;
@property (nonatomic,copy) NSString *baseUrl;
@property (nonatomic,copy) NSString *apiKey;
@property (retain) PlaytomicLog *log;
@property (retain) PlaytomicGameVars *gameVars;
@property (retain) PlaytomicGeoIP *geoIP;
@property (retain) PlaytomicLeaderboards *leaderboards;
@property (retain) PlaytomicPlayerLevels *playerLevels;
@property (retain) PlaytomicLink *link;
@property (retain) PlaytomicData *data;
@property (assign) BOOL hostActive;
@property (assign) BOOL internetActive;
@property (assign) NSInteger offlineQueueMaxSize;
@end

@implementation Playtomic

@synthesize gameId;
@synthesize gameGuid;
@synthesize sourceUrl;
@synthesize baseUrl;
@synthesize log;
@synthesize gameVars;
@synthesize geoIP;
@synthesize leaderboards;
@synthesize playerLevels;
@synthesize link;
@synthesize data;
@synthesize hostActive;
@synthesize internetActive;
@synthesize offlineQueueMaxSize;
@synthesize apiKey;

static Playtomic *instance = nil;

+ (void)initialize
{
    if (instance == nil)
    {
        instance = [[self alloc] init];
    }
}

+ (PlaytomicLog*)Log
{
	return instance.log;
}

+ (PlaytomicGameVars*)GameVars
{
	return instance.gameVars;
}

+ (PlaytomicGeoIP*)GeoIP
{
    return instance.geoIP;
}

+ (PlaytomicLeaderboards*)Leaderboards
{
    return instance.leaderboards;
}

+ (PlaytomicPlayerLevels*)PlayerLevels
{
    return instance.playerLevels;
}

+ (PlaytomicLink*)Link
{
    return instance.link;
}

+ (PlaytomicData*)Data
{
    return instance.data;
}

+ (NSInteger)getGameId
{
    return instance.gameId;
}

+ (NSString*)getGameGuid
{
    return instance.gameGuid;
}

+ (NSString*)getApiKey
{
    return instance.apiKey;
}

+ (NSString*)getSourceUrl
{
    return instance.sourceUrl;
}

+ (NSString*)getBaseUrl
{
    return instance.baseUrl;
}

+ (BOOL)getInternetActive
{
    // When the status is not connected we recheck
    // because after some testing with a device
    // (not in simulator) we have noticed that
    // NSNotificationCenter is not calling
    // every time wifi and internet get reachable
    //
    if (instance.internetActive == NO || instance.hostActive == NO)
    {
        [instance checkNetworkStatus:nil];
    }
    return instance.internetActive && instance.hostActive;
}

+ (NSInteger)getOfflineQueueMaxSize
{
    return instance.offlineQueueMaxSize;
}

+ (void)setOfflineQueueMaxSizeInKbytes:(NSInteger)size
{
    // we save the size in bytes
    //
    if (size < 0)
    {
        size = 0;
    }
    size = size * 1024;
    if (size > PLAYTOMIC_QUEUE_MAX_BYTES)
    {
        instance.offlineQueueMaxSize = PLAYTOMIC_QUEUE_MAX_BYTES;
    }
    else
    {
        instance.offlineQueueMaxSize = size;
    }
}

- (id)initWithGameId:(NSInteger)gameid 
             andGUID:(NSString*)gameguid 
           andAPIKey:(NSString*)apikey
{
    NSString *model = [[UIDevice currentDevice] model];
    NSString *system = [[UIDevice currentDevice] systemName];
    NSString *version = [[UIDevice currentDevice] systemVersion];
    
    model = [model stringByReplacingOccurrencesOfString:@" " withString:@"+"];
    system = [system stringByReplacingOccurrencesOfString:@" " withString:@"+"];
    version = [version stringByReplacingOccurrencesOfString:@" " withString:@"+"];
    
    instance.gameId = gameid;
    instance.gameGuid = gameguid;
    instance.sourceUrl = [NSString stringWithFormat:@"http://ios.com/%@/%@/%@", model, system, version];
    instance.baseUrl = @"ios.com";
    instance.apiKey = apikey;

    instance.log = [[[PlaytomicLog alloc] initWithGameId:gameid andGUID:gameguid]autorelease ];
    instance.gameVars = [[[PlaytomicGameVars alloc] init] autorelease];
    instance.geoIP = [[[PlaytomicGeoIP alloc] init] autorelease];
    instance.leaderboards = [[[PlaytomicLeaderboards alloc] init] autorelease ];
    instance.playerLevels = [[[PlaytomicPlayerLevels alloc] init] autorelease];
    instance.link = [[[PlaytomicLink alloc] init]autorelease ];
    instance.data = [[[PlaytomicData alloc] init] autorelease];
   
    // check for internet connection
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(checkNetworkStatus:) name:kReachabilityChangedNotification object:nil];
    
    internetReachable = [[Reachability reachabilityForInternetConnection] retain];
    [internetReachable startNotifier];
    
    // check if a pathway to a random host exists
    hostReachable = [[Reachability reachabilityWithHostName:@"www.playtomic.com"] retain];
    [hostReachable startNotifier];
    
    instance.hostActive = YES;
    instance.internetActive = YES;
    instance.offlineQueueMaxSize = PLAYTOMIC_QUEUE_MAX_BYTES; // 1 MB 
  
    return instance;    
}

- (void) checkNetworkStatus:(NSNotification *)notice
{
    // called after network status changes
    
    //NSLog(@"checkNetworkStatus was called.");
    
    NetworkStatus internetStatus = [internetReachable currentReachabilityStatus];
    switch (internetStatus)
    
    {
        case NotReachable:
        {
            //NSLog(@"The internet is down.");
            instance.internetActive = NO;
            
            break;
            
        }
        case ReachableViaWiFi:
        {
            //NSLog(@"The internet is working via WIFI.");
            instance.internetActive = YES;
            
            break;
            
        }
        case ReachableViaWWAN:
        {
            //NSLog(@"The internet is working via WWAN.");
            instance.internetActive = YES;
            
            break;
            
        }
    }
    
    NetworkStatus hostStatus = [hostReachable currentReachabilityStatus];
    switch (hostStatus)
    
    {
        case NotReachable:
        {
            //NSLog(@"A gateway to the host server is down.");
            instance.hostActive = NO;
            
            break;
            
        }
        case ReachableViaWiFi:
        {
            //NSLog(@"A gateway to the host server is working via WIFI.");
            instance.hostActive = YES;
            
            break;
            
        }
        case ReachableViaWWAN:
        {
            //NSLog(@"A gateway to the host server is working via WWAN.");
            instance.hostActive = YES;
            
            break;
            
        }
    }
    
}

- (void)dealloc {
    self.gameGuid = nil;
    self.sourceUrl = nil;
    self.baseUrl = nil;
    self.log = nil;
    self.gameVars = nil;
    self.geoIP = nil;
    self.leaderboards = nil;
    self.playerLevels = nil;
    self.link = nil;
    self.data = nil;    
    
    if (hostReachable)
    {
        [hostReachable release];
        hostReachable = nil;
    }

    if (internetReachable)
    {
        [internetReachable release];
        internetReachable = nil;
    }
    
    [super dealloc];
}


@end
