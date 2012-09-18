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
#import "PlaytomicLevel.h"


@interface PlaytomicPlayerLevels : NSObject {
    
    id<PlaytomicDelegate> delegate;
    NSString *levelid_;    
}

// synchronous calls
//
- (PlaytomicResponse*)loadLevelid:(NSString*)levelid;

- (PlaytomicResponse*)rateLevelid:(NSString*)levelid 
                        andRating:(NSInteger)rating;

- (PlaytomicResponse*)listMode:(NSString*)mode 
                       andPage:(NSInteger)page 
                    andPerPage:(NSInteger)perpage 
                andIncludeData:(Boolean)includedata
              andIncludeThumbs:(Boolean)includethumbs
               andCustomFilter:(NSDictionary*)customfilter;

- (PlaytomicResponse*)listWithDateRangeMode:(NSString*)mode 
                                    andPage:(NSInteger)page 
                                 andPerPage:(NSInteger)perpage 
                             andIncludeData:(Boolean)data 
                           andIncludeThumbs:(Boolean)includethumbs 
                            andCustomFilter:(NSDictionary*)customfilter 
                                 andDateMin:(NSDate*)datemin 
                                 andDateMax:(NSDate*)datemax;

- (PlaytomicResponse*)saveLevel:(PlaytomicLevel*)level;

// asynchronous calls
//
- (void)loadAsyncLevelid:(NSString*)levelid 
             andDelegate:(id<PlaytomicDelegate>)delegate;

- (void)rateAsyncLevelid:(NSString*)levelid 
               andRating:(NSInteger)rating 
             andDelegate:(id<PlaytomicDelegate>)delegate;

- (void)listAsyncMode:(NSString*)mode 
              andPage:(NSInteger)page 
           andPerPage:(NSInteger)perpage 
       andIncludeData:(Boolean)includedata 
     andIncludeThumbs:(Boolean)includethumbs 
      andCustomFilter:(NSDictionary*)customfilter 
          andDelegate:(id<PlaytomicDelegate>)delegate;

- (void)listWithDateRangeAsyncMode:(NSString*)mode
                           andPage:(NSInteger)page
                        andPerPage:(NSInteger)perpage
                    andIncludeData:(Boolean)data
                  andIncludeThumbs:(Boolean)includethumbs
                   andCustomFilter:(NSDictionary*)customfilter
                        andDateMin:(NSDate*)datemin
                        andDateMax:(NSDate*)datemax
                       andDelegate:(id<PlaytomicDelegate>)delegate;

- (void)saveAsyncLevel:(PlaytomicLevel*)level 
           andDelegate:(id<PlaytomicDelegate>)delegate;

- (void)startLevel:(NSString*)levelid;

- (void)retryLevel:(NSString*)levelid;

- (void)winLevel:(NSString*)levelid;

- (void)quitLevel:(NSString*)levelid;

- (void)flagLevel:(NSString*)levelid;

@end
