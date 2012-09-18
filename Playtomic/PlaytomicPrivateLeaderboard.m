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

#import "PlaytomicPrivateLeaderboard.h"

@interface PlaytomicPrivateLeaderboard ()

@property(retain,nonatomic)     NSString* tableId;
@property(retain,nonatomic)     NSString* name;
@property(retain,nonatomic)     NSString* permalink;
@property(assign,nonatomic)     BOOL      hightest;
@property(retain,nonatomic)     NSString* realName;

@end

@implementation PlaytomicPrivateLeaderboard

@synthesize tableId;
@synthesize name;
@synthesize permalink;
@synthesize hightest;
@synthesize realName;

- (id)initWithName:(NSString*)pname andHighest:(BOOL)phighest
{
    self = [self init];
    if(self)
    {
        name = pname;
        hightest = phighest;
    }
    return self;
}

- (id)initWithName:(NSString*)pname 
        andTableId:(NSString*)ptableid
      andPermalink:(NSString*)ppermalink 
       andHighest:(BOOL)phighest 
       andRealName:(NSString*)prealname
{
    self = [self init];
    if(self)
    {
        name = pname;
        hightest = phighest;
        permalink = ppermalink;
        tableId = ptableid;
        realName = prealname;
    }
    return self;
}

@end
