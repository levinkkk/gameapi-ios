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

#import <Foundation/Foundation.h>
#import "PlaytomicLog.h"
#import "PlaytomicGameVars.h"
#import "PlaytomicGeoIP.h"
#import "PlaytomicLeaderboards.h"
#import "PlaytomicPlayerLevels.h"
#import "PlaytomicLink.h"
#import "PlaytomicData.h"

@class Reachability;

extern int const PLAYTOMIC_QUEUE_MAX_BYTES;

@interface Playtomic : NSObject {
    
    NSInteger gameId;
    NSString *gameGuid;
    NSString *sourceUrl;
    NSString *apiKey;
    NSString *baseUrl;
    PlaytomicLog *log;
    PlaytomicGameVars *gameVars;
    PlaytomicGeoIP *geoIP;
    PlaytomicLeaderboards *leaderboards;
    PlaytomicPlayerLevels *playerLevels;
    PlaytomicLink *link;
    PlaytomicData *data;
    
    Reachability *internetReachable;
    Reachability *hostReachable;
    
    BOOL hostActive;
    BOOL internetActive;
    NSInteger offlineQueueMaxSize;
}

- (id)initWithGameId:(NSInteger)gameid 
             andGUID:(NSString*)gameguid 
           andAPIKey:(NSString*)apikey;

- (void) checkNetworkStatus:(NSNotification *)notice;

+ (PlaytomicLog*)Log;

+ (PlaytomicGameVars*)GameVars;

+ (PlaytomicGeoIP*)GeoIP;

+ (PlaytomicLeaderboards*)Leaderboards;

+ (PlaytomicPlayerLevels*)PlayerLevels;

+ (PlaytomicLink*)Link;

+ (PlaytomicData*)Data;

+ (NSInteger)getGameId;

+ (NSString*)getGameGuid;

+ (NSString*)getApiKey;

+ (NSString*)getSourceUrl;

+ (NSString*)getBaseUrl;

+ (BOOL)getInternetActive;

+ (NSInteger)getOfflineQueueMaxSize;

+ (void)setOfflineQueueMaxSizeInKbytes:(NSInteger)size;

@end
