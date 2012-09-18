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


@interface PlaytomicLevel : NSObject {
    NSString *levelId;
    NSString *playerId;
    NSString *playerName;
    NSString *playerSource;
    NSString *name;
    NSString *data;
    NSString *thumb;
    NSInteger votes;
    NSInteger plays;
    NSDecimalNumber *rating;
    NSInteger score;
    NSDate *date;
    NSString *relativeDate;
    NSMutableDictionary *customData;
}

- (id)initWithName:(NSString*)pname 
    andPlayerName:(NSString*)pplayername 
      andPlayerId:(NSString*)pplayerid 
          andData:(NSString*)pdata;

- (id)initWithName:(NSString*)pname 
    andPlayerName:(NSString*)pplayername 
      andPlayerId:(NSString*)pplayerid 
  andPlayerSource:(NSString*)playersource 
          andData:(NSString*)pdata 
         andThumb:(NSString*)pthumb 
         andVotes:(NSInteger)pvotes 
         andPlays:(NSInteger)pplays 
        andRating:(NSDecimalNumber*)rpating 
         andScore:(NSInteger)pscore 
          andDate:(NSDate*)pdate 
  andRelativeDate:(NSString*)prelativedate 
    andCustomData:(NSMutableDictionary*)pcustomdata 
       andLevelId:(NSString*)levelid;

- (NSString*)getLevelId;

- (NSString*)getPlayerId;

- (NSString*)getPlayerName;

- (NSString*)getPlayerSource;

- (NSString*)getName;

- (NSString*)getData;

- (NSMutableData*)getThumbnail;

- (NSInteger)getVotes;

- (NSInteger)getPlays;

- (NSDecimalNumber*)getRating;

- (NSInteger)getScore;

- (NSDate*)getDate;

- (NSString*)getRelativeDate;

- (NSMutableDictionary*)getCustomData;

- (NSString*)getThumbnailURL;

- (NSString*)getCustomValue:(NSString*)key;

- (void)addCustomValue:(NSString*)key 
              andValue:(NSString*)value;

@end
