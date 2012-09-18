# Playtomic iOS API

This file is the official Playtomic API for iOS games using Objective C. 

Playtomic is a real time analytics platform for casual games and services 
that go in casual games.  If you haven't used it before check it out:

- https://playtomic.com/

Documentation is available at:

- https://playtomic.com/api/ios

Support is available at:
	
- https://playtomic.com/community
- https://playtomic.com/issues
- https://playtomic.com/support has more options if you're a premium user
	
	
You may modify this SDK if you wish but be kind to our servers.  Be
careful about modifying the analytics stuff as it may give you 
borked reports.

Pull requests are welcome if you spot a bug or know a more efficient
way to implement something.

### General notes
Don't use crazy characters in your metric, level, leaderboard table etc 
names.  A very good idea is to use the same naming conventions for variables:

- alphanumeric
- keep them short (50 chars is the max)

Play time, country and source information is handled automatically, you do not 
need to do anything to collect that data.

Begin by logging a view which initializes the API, and then log any metrics you 
want.  Play time, repeat visitors etc are handled automatically.

#### Setting up
Add these frameworks to your game by clicking the projcet, then selecting 
the target, build phases, and expanding Link Binary with Libraries.

- libz.1.2.3.dylib
- CFNetwork.framework
- MobileCoreServices.framework
- SystemConfiguration.framework

#### Initialize
Get your credentials from the Playtomic dashboard (add or select game then go to API page)

[Playtomic alloc] initWithGameId: 0 andGUID:@"" andAPIKey: @""]; 

#Logging a view
Call this at the very start of your game loading:

	[[Playtomic Log] view];

This registers that the player has viewed your game.  You can track when 
the player actually starts playing (eg play button) by calling this 0 or 
more times in your game:

	[[Playtomic Log] play];
	
Log.Play can be called multiple times in a single session.

#### Custom metrics
Custom metrics can track any general events you want to follow, like 
tracking who views your credits screen or anything else.

Call this to log any custom data you want to track.

    [[Playtomic Log] customMetric:name andGroup: group andUnique: unique];
	
        (NSString*)	name = your metric name, eg "ViewedCredits"
        (NSString*)	group = optional, specify the group name for sorting in reports
        (Boolean)	unique = optional, only count unique occurrences 

#### Level metrics
Level metrics can identify problems players are having with your difficulty 
or anything else by logging information like how many people begin vs. finish
each level.  They can help you identify major problems in your player retention.

These methods log the 3 types of level metrics - counters, ranged-value 
and average-value metrics.

- Counter metrics count how many times an event occurs across levels
- Ranged-value metrics track multiple values across a single event across levels
- Average-value metrics track the average of something across levels

    [[Playtomic Log] levelCounterMetric: name andLevel: levelname andUnique: unique];
    [[Playtomic Log] levelCounterMetric: name andLevelNumber: levelnumber andUnique: unique];

        (NSString*) name = your metric name
        (NSString*) or (NSInteger) levelname / levelnumber = either a 
            level number (int > 0) or a level name
        (Boolean) unique = optional, only count unique-per-view occurrences

    [[Playtomic Log] levelAverageMetric: name andLevel: levelname andValue: value andUnique: unique];
    [[Playtomic Log] levelAverageMetric: name andLevelNumber: levelnumber andValue: value andUnique: unique];

        (NSString*) name = your metric name
        (NSString*) or (NSInteger) levelname / level number = either a 
            level number (int > 0) or a level name
        (NSInteger) value = the value you want to track
        (Boolean) unique = optional, only count unique-per-view occurrences 

    [[Playtomic Log] levelRangedMetric: name andLevel: levelname andTrackValue: value andUnique: unique];
    [[Playtomic Log] levelRangedMetric: name andLevelNumber: levenumber andTrackValue: value andUnique: unique];

        (NSString*) name = your metric name
        (NSString*) or (NSInteger) levelname / level number = either a 
            level number (int > 0) or a level name
        (NSInteger) value = the value you want to track
        (Boolean) unique = optional, only count unique-per-view occurrences 

#### Leaderboards, level sharing, data and geoip 
This stuff gets a little more complicated.  Please check the documentation 
for examples:

- https://playtomic.com/api/ios
	
##### LICENSE & DISCLAIMER
Copyright (c) 2011 Playtomic Inc.  Playtomic APIs and SDKs are licensed 
under the MIT license.  Certain portions may come from 3rd parties and 
carry their own licensing terms and are referenced where applicable.