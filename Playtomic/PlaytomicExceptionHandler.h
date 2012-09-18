//
//  PlaytomicExceptionHandler.h
//  ObjectiveCTest
//
//  Created by matias on 1/10/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlaytomicResponse.h"

@interface PlaytomicExceptionHandler : NSObject


+ (void) registerDefaultHandlers;

+ (void) registerDefaultHandlersWithDelegate:(id<PlaytomicDelegate>)pDelegate;

+ (void) unregisterDefaultHandlers;

+ (void) sendReportArray:(NSArray*)array;

                                 
@end
