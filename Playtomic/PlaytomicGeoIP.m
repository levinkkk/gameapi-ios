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

#import "Playtomic.h"
#import "PlaytomicGeoIP.h"
#import "PlaytomicResponse.h"
#import "JSON/JSON.h"
#import "ASI/ASIHTTPRequest.h"
#import "PlaytomicRequest.h"
#import "PlaytomicEncrypt.h"

@interface PlaytomicGeoIP() 

- (void)requestLoadFinished:(ASIHTTPRequest*)request;

@end

@implementation PlaytomicGeoIP

- (PlaytomicResponse*)load
{
    NSString *url = [NSString stringWithFormat:@"http://g%@.api.playtomic.com/v3/api.aspx?swfid=%d&js=y"
                     , [Playtomic getGameGuid]
                     , [Playtomic getGameId]];
    
    
    NSMutableDictionary * postData = [[[NSMutableDictionary alloc] init] autorelease];
    
    
    
    NSString* section = [PlaytomicEncrypt md5:[NSString stringWithFormat:@"%@%@", @"geoip-", [Playtomic getApiKey]]];
    NSString* action = [PlaytomicEncrypt md5:[NSString stringWithFormat:@"%@%@", @"geoip-lookup-", [Playtomic getApiKey]]];
    
    
    PlaytomicResponse* response = [PlaytomicRequest sendRequestUrl:url andSection:section andAction:action andPostData:postData];
    // failed on the client / connectivty side
    if(![response success])
    {
        return response;
    }
    NSDictionary *dvars = [response dictionary];
    NSMutableDictionary *md = [[NSMutableDictionary alloc] init];
    
    for(id key in dvars)
    {
        [md setObject: [dvars valueForKey:key] forKey:key];
    }
    PlaytomicResponse *playtomicResponse = [[PlaytomicResponse alloc] initWithSuccess:YES 
                                                                         andErrorCode:0 
                                                                              andDict:md];
    [playtomicResponse autorelease];
    [md release];
    return playtomicResponse;
}

- (void) loadAsync:(id<PlaytomicDelegate>)aDelegate
{
    NSString *url = [NSString stringWithFormat:@"http://g%@.api.playtomic.com/v3/api.aspx?swfid=%d&js=y"
                     , [Playtomic getGameGuid]
                     , [Playtomic getGameId]];
    
    
    NSMutableDictionary * postData = [[[NSMutableDictionary alloc] init] autorelease];
    
    
    
    NSString* section = [PlaytomicEncrypt md5:[NSString stringWithFormat:@"%@%@", @"geoip-", [Playtomic getApiKey]]];
    NSString* action = [PlaytomicEncrypt md5:[NSString stringWithFormat:@"%@%@", @"geoip-lookup-", [Playtomic getApiKey]]];
    
    delegate = aDelegate;
    [PlaytomicRequest sendRequestUrl:url andSection:section andAction:action andCompleteDelegate:self andCompleteSelector:@selector(requestLoadFinished:) andPostData:postData];
}

- (void) requestLoadFinished:(ASIHTTPRequest *)request
{
    if (!(delegate && [delegate respondsToSelector:@selector(requestLoadGeoIPFinished:)])) {
        return;
    }
    
    NSError *error = [request error];
    
    // failed on the client / connectivty side
    if(error)
    {
        [delegate requestLoadGeoIPFinished:[[[PlaytomicResponse alloc] initWithError:1] autorelease]];
        return;
    }
    
    // we got a response of some kind
    NSString *response = [request responseString];
    NSString *json = [[NSString alloc] initWithString:response];
    SBJsonParser *parser = [[SBJsonParser alloc] init];
    NSArray *data = [parser objectWithString:json error:nil];
    NSInteger status = [[data valueForKey:@"Status"] integerValue];
    
    //[request release];
    [json release];
    [parser release];
    
    // failed on the server side
    if(status != 1)
    {
        NSInteger errorcode = [[data valueForKey:@"ErrorCode"] integerValue];
        [delegate requestLoadGeoIPFinished:[[[PlaytomicResponse alloc] initWithError:errorcode] autorelease]];
        return;
    }
    
    NSDictionary *dvars = [data valueForKey:@"Data"];
    NSMutableDictionary *md = [[NSMutableDictionary alloc] init];
    
    for(id key in dvars)
    {
        [md setObject: [dvars valueForKey:key] forKey:key];
    }
    PlaytomicResponse *playtomicResponse = [[PlaytomicResponse alloc] initWithSuccess:YES 
                                                                         andErrorCode:0 
                                                                              andDict:md];
    [playtomicResponse autorelease];
    [md release];
    [delegate requestLoadGeoIPFinished: playtomicResponse];
}

@end
