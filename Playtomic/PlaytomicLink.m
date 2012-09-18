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

#import "PlaytomicLink.h"
#import "Playtomic.h"
#import "PlaytomicLog.h"

@interface PlaytomicLink()

@property (nonatomic,retain) NSMutableDictionary *clicks;

@end

@implementation PlaytomicLink

@synthesize clicks;

- (void)trackUrl:(NSString*)url 
         andName:(NSString*)name 
        andGroup:(NSString*)group
{
    NSInteger unique = 0;
    NSInteger bunique = 0;
    NSInteger total = 0;
    NSInteger btotal = 0;
    NSString* key = [NSString stringWithFormat:@"%@.%@", url, name];
    
    NSString* baseurl = [NSString stringWithString:url];
    [baseurl stringByReplacingOccurrencesOfString:@"http://" withString:@""];
    [baseurl stringByReplacingOccurrencesOfString:@"https://" withString:@""];
    
    NSRange slash = [baseurl rangeOfString:@"/"];
    
    if(slash.location > 0)
    {
        baseurl = [baseurl substringToIndex:slash.location];
    }
    
    NSString* baseurlname = [NSString stringWithString:baseurl];
    NSRange www = [baseurlname rangeOfString:@"www."];
    
    if(www.location == 0 && www.length == 4)
    {
        baseurlname = [baseurlname substringFromIndex:www.location];
    }
    
    if([clicks objectForKey:key] == 0)
    {
        total = 1;
        unique = 1;
        [clicks setObject:0 forKey:key];
    }
    else
    {
        total = 1;
    }
    
    if([clicks objectForKey: baseurlname] == 0)
    {
        btotal = 1;
        bunique = 1;
        [clicks setObject:0 forKey:baseurlname];
    }
    else
    {
        btotal = 1;
    }
    
    [[Playtomic Log] linkUrl:baseurl 
                     andName:baseurlname 
                    andGroup:@"DomainTotals" 
                   andUnique:bunique 
                    andTotal:btotal 
                     andFail:0];
    
    [[Playtomic Log] linkUrl:url 
                     andName:name 
                    andGroup:group 
                   andUnique:unique 
                    andTotal:total 
                     andFail:0];
    
    [[Playtomic Log] forceSend];
}

- (void)dealloc {
    self.clicks = nil;
    [super dealloc];
}

@end