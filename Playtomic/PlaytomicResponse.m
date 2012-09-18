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

#import "PlaytomicResponse.h"

@interface PlaytomicResponse ()
@property (nonatomic, readwrite) NSInteger responseError;
@property (nonatomic, readwrite) Boolean responseSucceeded;
@property (nonatomic, retain) NSArray *responseData;
@property (nonatomic, retain) NSDictionary *responseDictionary;
@property (nonatomic, readwrite) NSInteger numResults;
@end


@implementation PlaytomicResponse

@synthesize responseError;
@synthesize responseSucceeded;
@synthesize responseData;
@synthesize responseDictionary;
@synthesize numResults;

- (id)initWithError:(NSInteger)errorcode
{
    self.responseSucceeded = NO;
    self.responseError = errorcode;
    return self;
}

- (id)initWithSuccess:(Boolean)success 
         andErrorCode:(NSInteger)errorcode
{
    self.responseSucceeded = success;
    self.responseError = errorcode;
    return self;
}

- (id)initWithSuccess:(Boolean)success 
         andErrorCode:(NSInteger)errorcode 
              andData:(NSArray*)data 
        andNumResults:(NSInteger)numresults
{
    self.responseSucceeded = success;
    self.responseError = errorcode;
    self.responseData = data;
    self.numResults = numresults;
    return self;
}

- (id)initWithSuccess:(Boolean)success 
         andErrorCode:(NSInteger)errorcode 
              andDict:(NSDictionary*)dict
{
    //NSLog(@"Creating PlaytomicResponse with success %d and error %d", success, errorcode);
    self.responseSucceeded = success;
    self.responseError = errorcode;
    self.responseDictionary = dict;
    return self;
}

- (Boolean)success
{
    return self.responseSucceeded;
}

- (NSInteger)errorCode
{
    return self.responseError;
}

- (NSArray*)data
{
    return self.responseData;
}

- (NSDictionary*) dictionary
{
    return self.responseDictionary;
}

- (NSString*)getValueForName:(NSString*)name
{
    return [self.responseDictionary valueForKey:name];
}

- (void)setValueForName:(NSString*)name 
               andValue:(NSString*)value
{
    if(self.responseDictionary == nil)
    {
        NSMutableDictionary *dict = [[NSMutableDictionary alloc] init];
        self.responseDictionary = dict;
        [dict release];
    }
    
    [self.responseDictionary setValue:value forKey:name];
}

- (NSInteger)getNumResults
{
    return self.numResults;
}

- (void)dealloc {
    self.responseData = nil;
    self.responseDictionary = nil;    
    [super dealloc];
}

@end
