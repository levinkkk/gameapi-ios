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
#import "PlaytomicScore.h"

@interface PlaytomicLeaderboards : NSObject {
    
    id<PlaytomicDelegate> delegate;
    
}

// synchronous calls
//
- (PlaytomicResponse*)saveTable:(NSString*)table 
                       andScore:(PlaytomicScore*)score 
                     andHighest:(Boolean)highest 
             andAllowDuplicates:(Boolean)allowduplicates;

- (PlaytomicResponse*)listTable:(NSString*)table 
                     andHighest:(Boolean)highest 
                        andMode:(NSString*)mode 
                        andPage:(NSInteger)page 
                     andPerPage:(NSInteger)perpage 
                andCustomFilter:(NSDictionary*)customfilter;

- (PlaytomicResponse*)saveAndListTable:(NSString*)table 
                              andScore:(PlaytomicScore*)score 
                            andHighest:(Boolean)highest 
                    andAllowDuplicates:(Boolean)allowduplicates 
                               andMode:(NSString*)mode 
                            andPerPage:(NSInteger)perpage 
                       andCustomFilter:(NSDictionary*)customfilter;

-(PlaytomicResponse*)createPrivateLeaderboardName:(NSString*)name 
                                       andHighest:(Boolean)highest;

-(PlaytomicResponse*)loadPrivateLeaderboardTableId:(NSString*)tableid;

// asynchronous calls
//
- (void)saveAsyncTable:(NSString*)table 
              andScore:(PlaytomicScore*)score 
            andHighest:(Boolean)highest 
    andAllowDuplicates:(Boolean)allowduplicates 
           andDelegate:(id<PlaytomicDelegate>)delegate;

- (void)listAsyncTable:(NSString*)table 
            andHighest:(Boolean)highest 
               andMode:(NSString*)mode 
               andPage:(NSInteger)page 
            andPerPage:(NSInteger)perpage 
       andCustomFilter:(NSDictionary*)customfilter 
           andDelegate:(id<PlaytomicDelegate>)delegate;

- (void)saveAndListAsyncTable:(NSString*)table 
                     andScore:(PlaytomicScore*)score 
                   andHighest:(Boolean)highest 
           andAllowDuplicates:(Boolean)allowduplicates 
                      andMode:(NSString*)mode 
                   andPerPage:(NSInteger)perpage 
              andCustomFilter:(NSDictionary*)customfilter 
                  andDelegate:(id<PlaytomicDelegate>)delegate;

-(void)createPrivateLeaderboardAsyncName:(NSString*)name 
                              andHighest:(Boolean)highest 
                             andDelegate:(id<PlaytomicDelegate>)delegate;

-(void)loadPrivateLeaderboardTableAsyncId:(NSString*)tableid 
                              andDelegate:(id<PlaytomicDelegate>)delegate;
@end

