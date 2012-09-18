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


@interface PlaytomicScore : NSObject {
    NSString *name;
    NSInteger points;
    NSDate *date;
    NSString *relativeDate;
    NSMutableDictionary *customData;
    long rank;
}

- (id)initWithName:(NSString*)pname 
         andPoints:(NSInteger)ppoints 
           andDate:(NSDate*)pdate 
   andRelativeDate:(NSString*)relativedate 
     andCustomData:(NSMutableDictionary*)customdata 
           andRank: (long)rank;

- (id)initNewScoreWithName:(NSString*)pname 
                 andPoints:(NSInteger)ppoints;

- (NSString*)getName;

- (NSInteger)getPoints;

- (NSDate*)getDate;

- (long)getRank;

- (NSString*)getRelativeDate;

- (NSMutableDictionary*)getCustomData;

- (NSString*)getCustomValue:(NSString*)key;

- (void)addCustomValue:(NSString*)key 
              andValue:(NSString*)value;

@end
