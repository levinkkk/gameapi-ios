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
#import "PlaytomicLogRequest.h"

@interface PlaytomicLog : NSObject {
    NSString *trackUrl;
    NSString *sourceUrl;
    NSString *baseUrl;
    Boolean enabled;
    NSTimer *playTimer;
    NSTimer *firstPing;
    NSInteger pings;
    NSInteger views;
    NSInteger plays;
    Boolean frozen;
    NSMutableArray *queue;
    NSMutableArray *customMetrics;
    NSMutableArray *levelCounters;
    NSMutableArray *levelAverages;
    NSMutableArray *levelRangeds;
    NSDate *lastEventOccurence;
}

- (id)initWithGameId:(NSInteger)gameid 
             andGUID:(NSString*)gameguid;

- (void) view;

- (void) play;

- (void) pingServer;

- (void)customMetricName:(NSString*)name 
                andGroup:(NSString*)group 
               andUnique:(Boolean)unique;

- (void)levelCounterMetricName:(NSString*)name 
                      andLevel:(NSString*)level 
                     andUnique:(Boolean)unique;

- (void)levelCounterMetricName:(NSString*)name 
                andLevelNumber:(NSInteger)levelnumber 
                     andUnique:(Boolean)unique;

- (void)levelRangedMetricName:(NSString*)name 
                     andLevel:(NSString*)level 
                andTrackValue:(NSUInteger)trackvalue 
                    andUnique:(Boolean)unique;

- (void)levelRangedMetricName:(NSString*)name 
               andLevelNumber:(NSInteger)levelnumber 
                andTrackValue:(NSUInteger)trackvalue 
                    andUnique:(Boolean)unique;

- (void)levelAverageMetricName:(NSString*)name 
                      andLevel:(NSString*)level 
                      andValue:(NSUInteger)value 
                     andUnique:(Boolean)unique;

- (void)levelAverageMetricName:(NSString*)name 
                andLevelNumber:(NSInteger)levelnumber 
                      andValue:(NSUInteger)value 
                     andUnique:(Boolean)unique;

- (void)linkUrl:(NSString*)url 
        andName:(NSString*)name 
       andGroup:(NSString*)group 
      andUnique:(NSInteger)unique 
       andTotal:(NSInteger)total 
        andFail:(NSInteger)fail;

- (void)heatmapName:(NSString*)name 
           andGroup:(NSString*)group 
               andX:(NSInteger)x 
               andY:(NSInteger)y;

- (void)funnel;

- (void)playerLevelStartLevelid:(NSString*)levelid;

- (void)playerLevelRetryLevelid:(NSString*)levelid;

- (void)playerLevelWinLevelid:(NSString*)levelid;

- (void)playerLevelQuitLevelid:(NSString*)levelid;

- (void)playerLevelFlagLevelid:(NSString*)levelid;

- (void)freeze;

- (void)unfreeze;

- (void)forceSend;

- (void)sendEvent:(NSString*)event 
        andCommit:(Boolean)commit;

- (NSString*)clean:(NSString*)string;

- (NSInteger)getCookie:(NSString*)name;

- (void)saveCookie;

- (void)increaseViews;

- (void)increasePlays;

@end
