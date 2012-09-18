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
#import "PlaytomicResponse.h"

@interface PlaytomicData : NSObject {
    
    id<PlaytomicDelegate> delegate;
    SEL requestFinished;
    
}

// synchronous
//
- (PlaytomicResponse*) views;

- (PlaytomicResponse*) viewsMonth:(NSInteger)month 
                          andYear:(NSInteger)year;

- (PlaytomicResponse*) viewsDay:(NSInteger)day 
                       andMonth:(NSInteger)month andYear:(NSInteger)year;

- (PlaytomicResponse*) plays;

- (PlaytomicResponse*) playsMonth:(NSInteger)month 
                          andYear:(NSInteger)year;

- (PlaytomicResponse*) playsDay:(NSInteger)day 
                       andMonth:(NSInteger)month andYear:(NSInteger)year;

- (PlaytomicResponse*) playtime;

- (PlaytomicResponse*) playtimeMonth:(NSInteger)month 
                             andYear:(NSInteger)year;

- (PlaytomicResponse*) playtimeDay:(NSInteger)day 
                          andMonth:(NSInteger)month 
                           andYear:(NSInteger)year;

- (PlaytomicResponse*) generalMode:(NSString*)mode 
                           andType:(NSString*)type
                            andDay:(NSInteger)day 
                          andMonth:(NSInteger)month 
                           andYear:(NSInteger)year;

- (PlaytomicResponse*) customMetricName:(NSString*)name;

- (PlaytomicResponse*) customMetricName:(NSString*)name 
                               andMonth:(NSInteger)month 
                                andYear:(NSInteger)year;

- (PlaytomicResponse*) customMetricName:(NSString*)name 
                                 andDay:(NSInteger)day 
                               andMonth:(NSInteger)month 
                                andYear:(NSInteger)year;

- (PlaytomicResponse*) levelCounterMetricName:(NSString*)name 
                                     andLevel:(NSString*)level;

- (PlaytomicResponse*) levelCounterMetricName:(NSString*)name 
                                     andLevel:(NSString*)level 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelCounterMetricName:(NSString*)name 
                                     andLevel:(NSString*)level 
                                       andDay:(NSInteger)day 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelCounterMetricName:(NSString*)name 
                               andLevelNumber:(NSInteger)level;

- (PlaytomicResponse*) levelCounterMetricName:(NSString*)name 
                               andLevelNumber:(NSInteger)level 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelCounterMetricName:(NSString*)name 
                               andLevelNumber:(NSInteger)level 
                                       andDay:(NSInteger)day 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelAverageMetricName:(NSString*)name 
                                     andLevel:(NSString*)level;

- (PlaytomicResponse*) levelAverageMetricName:(NSString*)name 
                                     andLevel:(NSString*)level 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelAverageMetricName:(NSString*)name 
                                     andLevel:(NSString*)level 
                                       andDay:(NSInteger)day 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelAverageMetricName:(NSString*)name 
                               andLevelNumber:(NSInteger)level;

- (PlaytomicResponse*) levelAverageMetricName:(NSString*)name 
                               andLevelNumber:(NSInteger)level 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelAverageMetricName:(NSString*)name 
                               andLevelNumber:(NSInteger)level 
                                       andDay:(NSInteger)day 
                                     andMonth:(NSInteger)month 
                                      andYear:(NSInteger)year;

- (PlaytomicResponse*) levelRangedMetricName:(NSString*)name 
                                    andLevel:(NSString*)level;

- (PlaytomicResponse*) levelRangedMetricName:(NSString*)name 
                                    andLevel:(NSString*)level 
                                    andMonth:(NSInteger)month 
                                     andYear:(NSInteger)year;

- (PlaytomicResponse*) levelRangedMetricName:(NSString*)name 
                                    andLevel:(NSString*)level 
                                      andDay:(NSInteger)day 
                                    andMonth:(NSInteger)month 
                                     andYear:(NSInteger)year;

- (PlaytomicResponse*) levelRangedMetricName:(NSString*)name 
                              andLevelNumber:(NSInteger)level;

- (PlaytomicResponse*) levelRangedMetricName:(NSString*)name 
                              andLevelNumber:(NSInteger)level 
                                    andMonth:(NSInteger)month 
                                     andYear:(NSInteger)year;

- (PlaytomicResponse*) levelRangedMetricName:(NSString*)name 
                              andLevelNumber:(NSInteger)level 
                                      andDay:(NSInteger)day 
                                    andMonth:(NSInteger)month 
                                     andYear:(NSInteger)year;

- (PlaytomicResponse*) levelMetricType:(NSString*)type 
                               andName:(NSString*)name 
                              andLevel:(NSString*)level 
                                andDay:(NSInteger)day 
                              andMonth:(NSInteger)month 
                               andYear:(NSInteger)year;

- (PlaytomicResponse*) getDataUrl:(NSString*)url;

- (NSString*) clean:(NSString*)string;

// asynchronous
//
- (void) viewsAsync:(id<PlaytomicDelegate>)delegate;

- (void) viewsAsyncMonth:(NSInteger)month 
                 andYear:(NSInteger)year 
             andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) viewsAsyncDay:(NSInteger)day 
              andMonth:(NSInteger)month 
               andYear:(NSInteger)year 
           andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) playsAsync:(id<PlaytomicDelegate>)delegate;

- (void) playsAsyncMonth:(NSInteger)month 
                 andYear:(NSInteger)year 
             andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) playsAsyncDay:(NSInteger)day 
              andMonth:(NSInteger)month 
               andYear:(NSInteger)year 
           andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) playtimeAsync:(id<PlaytomicDelegate>)delegate;

- (void) playtimeAsyncMonth:(NSInteger)month 
                    andYear:(NSInteger)year 
                andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) playtimeAsyncDay:(NSInteger)day 
                 andMonth:(NSInteger)month 
                  andYear:(NSInteger)year 
              andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) generalAsyncMode:(NSString*)mode 
                  andType:(NSString*)type
                   andDay:(NSInteger)day andMonth:(NSInteger)month 
                  andYear:(NSInteger)year 
              andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) customMetricAsyncName:(NSString*)name 
                   andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) customMetricAsyncName:(NSString*)name 
                      andMonth:(NSInteger)month 
                       andYear:(NSInteger)year 
                   andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) customMetricAsyncName:(NSString*)name 
                        andDay:(NSInteger)day 
                      andMonth:(NSInteger)month 
                       andYear:(NSInteger)year 
                   andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelCounterMetricAsyncName:(NSString*)name 
                            andLevel:(NSString*)level 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelCounterMetricAsyncName:(NSString*)name 
                            andLevel:(NSString*)level 
                            andMonth:(NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelCounterMetricAsyncName:(NSString*)name 
                            andLevel:(NSString*)level 
                              andDay:(NSInteger)day 
                            andMonth:(NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelCounterMetricAsyncName:(NSString*)name 
                      andLevelNumber:(NSInteger)level 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelCounterMetricAsyncName:(NSString*)name 
                      andLevelNumber:(NSInteger)level 
                            andMonth:(NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelCounterMetricAsyncName:(NSString*)name 
                      andLevelNumber:(NSInteger)level 
                              andDay:(NSInteger)day 
                            andMonth:(NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelAverageMetricAsyncName:(NSString*)name 
                            andLevel:(NSString*)level 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelAverageMetricAsyncName:(NSString*)name 
                            andLevel:(NSString*)level 
                            andMonth:(NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelAverageMetricAsyncName:(NSString*)name 
                            andLevel:(NSString*)level 
                              andDay:(NSInteger)day 
                            andMonth:(NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelAverageMetricAsyncName:(NSString*)name 
                      andLevelNumber:(NSInteger)level 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelAverageMetricAsyncName:(NSString*)name 
                      andLevelNumber:(NSInteger)level 
                            andMonth: (NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelAverageMetricAsyncName:(NSString*)name 
                      andLevelNumber:(NSInteger)level 
                              andDay:(NSInteger)day 
                            andMonth:(NSInteger)month 
                             andYear:(NSInteger)year 
                         andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelRangedMetricAsyncName:(NSString*)name 
                           andLevel:(NSString*)level 
                        andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelRangedMetricAsyncName:(NSString*)name 
                           andLevel:(NSString*)level 
                           andMonth:(NSInteger)month 
                            andYear:(NSInteger)year 
                        andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelRangedMetricAsyncName:(NSString*)name 
                           andLevel:(NSString*)level 
                             andDay:(NSInteger)day 
                           andMonth:(NSInteger)month 
                            andYear:(NSInteger)year 
                        andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelRangedMetricAsyncName:(NSString*)name 
                     andLevelNumber:(NSInteger)level 
                        andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelRangedMetricAsyncName:(NSString*)name 
                     andLevelNumber:(NSInteger)level 
                           andMonth:(NSInteger)month 
                            andYear:(NSInteger)year 
                        andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelRangedMetricAsyncName:(NSString*)name 
                     andLevelNumber:(NSInteger)level 
                             andDay:(NSInteger)day 
                           andMonth:(NSInteger)month 
                            andYear:(NSInteger)year 
                        andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) levelMetricAsyncType:(NSString*)type 
                      andName:(NSString*)name 
                     andLevel:(NSString*)level 
                       andDay:(NSInteger)day 
                     andMonth:(NSInteger)month 
                      andYear:(NSInteger)year 
                  andDelegate:(id<PlaytomicDelegate>)delegate;

- (void) getDataAsyncUrl:(NSString*)url 
             andDelegate:(id<PlaytomicDelegate>)delegate;

@end