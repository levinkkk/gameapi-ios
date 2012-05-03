//
//  PlaytomicExceptionHandler.m
//  ObjectiveCTest
//
//  Created by matias on 1/10/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import "PlaytomicExceptionHandler.h"
#import "PlaytomicRequest.h"
#import "PlaytomicURLRequest.h"
#import "Playtomic.h"
#include <execinfo.h>

static id<PlaytomicDelegate> gDelegate = nil;

void SignalHandler(int signal)
{
    NSString* gameInfo = @"empty game info";
    if(gDelegate && [gDelegate respondsToSelector:@selector(signalRaised:)])
    {
        gameInfo = [gDelegate signalRaised:signal];
    }
    const char* sigtype[NSIG];
    sigtype[SIGABRT] = "SIGABRT";
    sigtype[SIGBUS] = "SIGBUS";
    sigtype[SIGFPE] = "SIGFPE";
    sigtype[SIGILL] = "SIGILL";
    sigtype[SIGPIPE] = "SIGPIPE";
    sigtype[SIGSEGV] = "SIGSEGV";
    
    void* callstack[128];
    const int numFrames = backtrace(callstack, 128);
    char **symbols = backtrace_symbols(callstack, numFrames);
    
    NSMutableArray *arr = [NSMutableArray arrayWithCapacity:numFrames + 1 ];
    [arr addObject:gameInfo];
    for (int i = 0; i < numFrames; ++i) 
    {
        [arr addObject:[NSString stringWithUTF8String:symbols[i]]];
    }
    
    free(symbols);
    [PlaytomicExceptionHandler sendReportArray:arr];
}

void ExceptionHandler(NSException* exception)
{
    NSString* gameInfo = @"empty game info";
    if(gDelegate && [gDelegate respondsToSelector:@selector(exceptionRaised:)])
    {
        gameInfo = [gDelegate exceptionRaised:exception];
    }
    void* callstack[128];
    const int numFrames = backtrace(callstack, 128);
    char **symbols = backtrace_symbols(callstack, numFrames);
    
    NSMutableArray *arr = [NSMutableArray arrayWithCapacity:numFrames + 1 ];
    [arr addObject:gameInfo];
    for (int i = 0; i < numFrames; ++i) 
    {
        [arr addObject:[NSString stringWithUTF8String:symbols[i]]];
    }
    free(symbols);
    [PlaytomicExceptionHandler sendReportArray:arr];
}

@implementation PlaytomicExceptionHandler

+ (void) registerDefaultHandlers
{
    signal(SIGABRT, SignalHandler);
    signal(SIGBUS, SignalHandler);
    signal(SIGFPE, SignalHandler);
    signal(SIGILL, SignalHandler);
    signal(SIGPIPE, SignalHandler);    
    signal(SIGSEGV, SignalHandler);
    signal(SIGHUP, SignalHandler);
    
    NSSetUncaughtExceptionHandler(&ExceptionHandler);
}

+ (void) registerDefaultHandlersWithDelegate:(id<PlaytomicDelegate>)pDelegate
{
    gDelegate = pDelegate;
    signal(SIGABRT, SignalHandler);
    signal(SIGBUS, SignalHandler);
    signal(SIGFPE, SignalHandler);
    signal(SIGILL, SignalHandler);
    signal(SIGPIPE, SignalHandler);    
    signal(SIGSEGV, SignalHandler);
    signal(SIGHUP, SignalHandler);
    
    NSSetUncaughtExceptionHandler(&ExceptionHandler);
}

+ (void) unregisterDefaultHandlers
{
    signal(SIGABRT, SIG_DFL);
    signal(SIGBUS, SIG_DFL);
    signal(SIGFPE, SIG_DFL);
    signal(SIGILL, SIG_DFL);
    signal(SIGPIPE, SIG_DFL);
    signal(SIGSEGV, SIG_DFL);
    signal(SIGHUP, SIG_DFL);
    
    NSSetUncaughtExceptionHandler(NULL);
}

+ (void) sendReportArray:(NSArray*)array
{
    
    NSString * stacktrace = [array description];
    stacktrace = [PlaytomicRequest EscapeString:stacktrace];
    
    NSString* url = [NSString stringWithFormat:@"%@%@.api.playtomic.com/tracker/e.aspx?swfid=%d&url=%@",
                     [Playtomic getUrlStart],
                     [Playtomic getGameGuid], [Playtomic getGameId], [Playtomic getSourceUrl]];
    
//    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
//    NSString *documentsDirectory = [paths objectAtIndex:0];
//    NSString *path = [documentsDirectory stringByAppendingPathComponent:@"crashurl"];
//    
//    NSMutableDictionary* dictionary = [[NSMutableDictionary alloc] init];
//    [dictionary setObject:url forKey:@"url"];
//    [dictionary setObject:[array description] forKey:@"stacktrace"];
//    [dictionary writeToFile:path atomically:true];
    
    PlaytomicURLRequest *request = [[PlaytomicURLRequest alloc] initWithDomain:url];
    [request setPostValue:stacktrace forKey:@"stacktrace"];
    [request startSynchronous];
    [request release];
    [PlaytomicExceptionHandler unregisterDefaultHandlers];
}

@end
