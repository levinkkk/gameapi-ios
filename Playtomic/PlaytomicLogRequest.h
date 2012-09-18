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

extern NSString * const PLAYTOMIC_QUEUE_SIZE;
extern NSString * const PLAYTOMIC_QUEUE_ITEM;
extern NSString * const PLAYTOMIC_QUEUE_READY;
extern int const PLAYTOMIC_QUEUE_MAX_BYTES;

@class PlaytomicURLRequest;

@interface PlaytomicLogRequest : NSObject {
    NSString *data;
    NSString *trackUrl;
    PlaytomicURLRequest* _request;
    BOOL mustReleaseOnRequestFinished;
}

- (id)initWithTrackUrl:(NSString*)url;
- (void)send;
- (void)queueEvent:(NSString*)event;
- (void)massQueue:(NSMutableArray*)eventqueue;

@end
