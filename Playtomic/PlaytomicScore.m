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

#import "PlaytomicScore.h"


@interface PlaytomicScore ()
@property (nonatomic,copy) NSString *name;
@property (nonatomic,readwrite) NSInteger points;
@property (nonatomic,copy) NSDate *date;
@property (nonatomic,copy) NSString *relativeDate;
@property (nonatomic,retain) NSMutableDictionary *customData;
@property (nonatomic,readwrite) long rank;
@end

@implementation PlaytomicScore

@synthesize name;
@synthesize points;
@synthesize date;
@synthesize relativeDate;
@synthesize customData;
@synthesize rank;

- (id)initNewScoreWithName:(NSString *)pname 
                 andPoints:(NSInteger)ppoints
{
    self.name = pname;
    self.points = ppoints;
    NSMutableDictionary *data = [[NSMutableDictionary alloc] init];
    self.customData = data;
    [data release];
    return self; 
}

- (id)initWithName:(NSString*)pname 
         andPoints:(NSInteger)ppoints 
           andDate:(NSDate*)pdate 
   andRelativeDate:(NSString*)relativedate 
     andCustomData:(NSMutableDictionary*)customdata 
           andRank:(long)prank
{
    self.name = pname;
    self.points = ppoints;
    self.date = pdate;
    self.relativeDate = relativedate;
    self.customData = customdata;
    self.rank = prank;
    return self;
}

- (NSString*)getName
{
    return self.name;
}

- (NSInteger)getPoints
{
    return self.points;
}

- (NSDate*)getDate
{
    return self.date;
}

- (NSString*)getRelativeDate
{
    return self.relativeDate;
}

- (long)getRank
{
    return self.rank;
}

- (NSMutableDictionary*)getCustomData
{
    return self.customData;
}

- (NSString*)getCustomValue:(NSString*)key
{
    return [self.customData valueForKey:key];
}

- (void)addCustomValue:(NSString*)key 
              andValue:(NSString*)value
{
    [self.customData setObject:value 
                        forKey:key];
}

- (void)dealloc {
    self.name = nil;
    self.date = nil;
    self.relativeDate = nil;
    self.customData = nil;
    [super dealloc];
}

@end