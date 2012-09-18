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

#import "PlaytomicLogRequest.h"
#import "Playtomic.h"
#import "PlaytomicLog.h"
#import "PlaytomicURLRequest.h"

NSString * const PLAYTOMIC_QUEUE_SIZE = @"playtomic.queue.size";
NSString * const PLAYTOMIC_QUEUE_BYTES = @"playtomic.queue.bytes";
NSString * const PLAYTOMIC_QUEUE_ITEM = @"playtomic.queue.item_%d";
NSString * const PLAYTOMIC_QUEUE_READY = @"playtomic.queue.ready";
int const PLAYTOMIC_QUEUE_MAX_BYTES = 1048577; // actually the max size is 1048576.
                                          // the 1048577 value allow us to do
                                          // if (queueSize < PLAYTOMIC_QUEUE_MAX_SIZE) {...}


@interface PlaytomicLogRequest ()

@property (nonatomic,copy) NSString *data;
@property (nonatomic,copy) NSString *trackUrl;
@property (assign) BOOL mustReleaseOnRequestFinished;
@property (retain) PlaytomicURLRequest* _request;


- (void)requestFailed:(PlaytomicURLRequest *)request;

@end

@implementation PlaytomicLogRequest

@synthesize data;
@synthesize trackUrl;
@synthesize mustReleaseOnRequestFinished;
@synthesize _request;

- (id)initWithTrackUrl:(NSString*)url
{
    self.trackUrl = url;
    self.data = @"";
    self.mustReleaseOnRequestFinished = true;
    return self;
}

- (void)queueEvent:(NSString*)event
{
    if([self.data length] == 0)
    {
        self.data = event;
    }
    else
    {
        self.data = [self.data stringByAppendingString:@"~"];
        self.data = [self.data stringByAppendingString:event];
    }
}

- (void)massQueue:(NSMutableArray*)eventqueue
{
    while([eventqueue count] > 0)
    {
        id event = [[[eventqueue objectAtIndex:0] retain] autorelease];
        [eventqueue removeObjectAtIndex:0];
        
        if([self.data length] == 0)
        {
            self.data = event;
        }
        else
        {
            self.data = [self.data stringByAppendingString:@"~"];
            self.data = [self.data stringByAppendingString:event];
            
            if([self.data length] > 300)
            {
                [self send];                
                PlaytomicLogRequest* request = [[PlaytomicLogRequest alloc] initWithTrackUrl:trackUrl];
                [request massQueue:eventqueue];
                return;
            }
        } 
    }
    
    [self send];
}

- (void)send
{
	NSString *fullurl = [NSString stringWithFormat:@"%@%@%@" ,[Playtomic getUrlStart], self.trackUrl, self.data];
    //fullurl = [fullurl stringByAppendingString:self.data];
    
    NSLog(@"url=%@", fullurl);
    
    if ([Playtomic getIsWiFiActive])
    {    
        //NSLog(@"Internet is active");
        
        self._request = [[[PlaytomicURLRequest alloc] initWithDomain:fullurl] autorelease];
        [_request setCompleteSelector:@selector(requestFinished:)];
        [_request setDelegate:self];
        [_request setFailedSelected:@selector(requestFailed:)];
        [_request startAsynchronous];
        //[request autorelease];
    }
    else
    {
        //NSLog(@"Internet is not active");     
        
        [self requestFailed:nil];
    }
}

- (void)requestFinished:(PlaytomicURLRequest*)request
{
    //NSLog(@"request finished");
    
    // try to send data we have failed to send in a previous call to send
    //    
    NSUserDefaults *dataToSendLater = [NSUserDefaults standardUserDefaults];
    NSInteger queueSize = [dataToSendLater integerForKey:PLAYTOMIC_QUEUE_SIZE];
    
    //NSLog(@"messages in queue %d", queueSize);
    
    if (queueSize > 0)
    {
        // we send only one message by call
        //
        BOOL ready = [dataToSendLater boolForKey:PLAYTOMIC_QUEUE_READY];
        if (ready)
        {
            [dataToSendLater setBool:NO forKey:PLAYTOMIC_QUEUE_READY];
            
            // this is managed as filo list
            //
            NSString *key = [NSString stringWithFormat:PLAYTOMIC_QUEUE_ITEM, queueSize];
            NSString *savedData = [dataToSendLater objectForKey:key];
            queueSize--;
            [dataToSendLater setInteger:queueSize forKey:PLAYTOMIC_QUEUE_SIZE];   
            [dataToSendLater removeObjectForKey:key];
            
            PlaytomicLogRequest* request = [[PlaytomicLogRequest alloc] initWithTrackUrl:trackUrl] ;
            [request queueEvent:savedData];
            request.mustReleaseOnRequestFinished = YES;
            [request send];
            
            //NSLog(@"message re-send: %@", trackUrl);
        }
        else
        {
            [dataToSendLater setBool:YES forKey:PLAYTOMIC_QUEUE_READY];        
        }
    }   
    if (self.mustReleaseOnRequestFinished)
    {
        [self release];
    }
}

- (void)requestFailed:(PlaytomicURLRequest *)request
{
    //NSLog(@"request failed %@", [request error]);
    
    // save data to send later
    //
    // this is managed as filo list
    //    
    NSUserDefaults *dataToSendLater = [NSUserDefaults standardUserDefaults];
    NSInteger queueSize = [dataToSendLater integerForKey:PLAYTOMIC_QUEUE_SIZE];
    NSInteger queueBytes = [dataToSendLater integerForKey:PLAYTOMIC_QUEUE_BYTES];
    if (queueBytes < [Playtomic getOfflineQueueMaxSize])
    {        
        queueSize++;
        [dataToSendLater setInteger:queueSize forKey:PLAYTOMIC_QUEUE_SIZE];
        NSString *key = [NSString stringWithFormat:PLAYTOMIC_QUEUE_ITEM, queueSize];
        NSString *dataToSave = self.data;
        NSRange foundRange = [dataToSave rangeOfString:@"&date="];
        if (foundRange.location == NSNotFound) 
        {
            long seconds = (long)[[NSDate date] timeIntervalSince1970];
            dataToSave = [NSString stringWithFormat:@"%@&date=%ld", dataToSave, seconds];
        }
        [dataToSendLater setObject:dataToSave forKey:key];
        queueBytes += [dataToSave length] * 2;
        [dataToSendLater setInteger:queueBytes forKey:PLAYTOMIC_QUEUE_BYTES];
        [dataToSendLater setBool:YES forKey:PLAYTOMIC_QUEUE_READY];
    }

    if (self.mustReleaseOnRequestFinished)
    {
        [self release];
    }
}

- (void)dealloc {
    self._request = nil;
    self.data = nil;
    self.trackUrl = nil;
    [super dealloc];
}

@end

