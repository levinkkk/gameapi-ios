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

@interface PlaytomicResponse : NSObject {
    Boolean responseSucceeded;
    NSInteger responseError;
    NSArray *responseData;
    NSDictionary *responseDictionary;
    NSInteger numResults;
}

- (id)initWithError:(NSInteger)errorcode;

- (id)initWithSuccess:(Boolean)success 
         andErrorCode:(NSInteger)errorcode;

- (id)initWithSuccess:(Boolean)success 
         andErrorCode:(NSInteger)errorcode 
              andData:(NSArray*)data 
        andNumResults:(NSInteger)numresults;

- (id)initWithSuccess:(Boolean)success 
         andErrorCode:(NSInteger)errorcode 
              andDict:(NSDictionary*)dict;

- (Boolean)success;

- (NSInteger)errorCode;

- (NSArray*)data;

- (NSDictionary*) dictionary;

- (NSString*)getValueForName:(NSString*)name;

- (void)setValueForName:(NSString*)name 
               andValue:(NSString*)value;

- (NSInteger)getNumResults;

@end

@protocol PlaytomicDelegate <NSObject>

@optional

// Leaderboards
//
- (void)requestSaveLeaderboardFinished:(PlaytomicResponse*)response;
- (void)requestListLeaderboardFinished:(PlaytomicResponse*)response;
- (void)requestSaveAndListLeaderboardFinished:(PlaytomicResponse*)response;

- (void)requestCreateprivateLeaderboardFinish:(PlaytomicResponse*)response;
- (void)requestLoadprivateLeaderboardFinish:(PlaytomicResponse*)response;

// GeoIP
//
- (void)requestLoadGeoIPFinished:(PlaytomicResponse*)response;

// GameVars
//
- (void)requestLoadGameVarsFinished:(PlaytomicResponse*)response;

// PlayerLevels
//
- (void)requestLoadPlayerLevelsFinished:(PlaytomicResponse*)response;
- (void)requestSavePlayerLevelsFinished:(PlaytomicResponse*)response;
- (void)requestRatePlayerLevelsFinished:(PlaytomicResponse*)response;
- (void)requestListPlayerLevelsFinished:(PlaytomicResponse*)response;

// Data
//
- (void)requestViewsDataFinished:(PlaytomicResponse*)response;
- (void)requestPlaysDataFinished:(PlaytomicResponse*)response;
- (void)requestPlaytimeDataFinished:(PlaytomicResponse*)response;
- (void)requestCustomMetricDataFinished:(PlaytomicResponse*)response;
- (void)requestLevelMetricCounterDataFinished:(PlaytomicResponse*)response;
- (void)requestLevelMetricAverageDataFinished:(PlaytomicResponse*)response;
- (void)requestLevelMetricRangeDataFinished:(PlaytomicResponse*)response;

@end

