//
//  BuiltAnalyticsEvent.h
//  BuiltIO
//
//  Created by Reefaq on 10/11/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltAnalyticsEvent : NSObject

-(instancetype)init UNAVAILABLE_ATTRIBUTE;

/**---------------------------------------------------------------------------------------
 * @name Properties
 *  ---------------------------------------------------------------------------------------
 */

/**
UID of the event
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    BuiltAnalyticsEvent *bugEvent = [analytics eventWithUID:@"create_bug"];
    NSString *eventUID = [bugEvent eventUID];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var analytics:BuiltAnalytics = builtApplication.analytics()
    var bugEvent:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug")
    var eventUID:String = bugEvent.eventUID
 
 */
@property (nonatomic, copy, readonly) NSString *eventUID;

/**
 @abstract Properties will allow you to segment your events in your BuiltAnalytics reports.

 Property keys must be <code>NSString</code> objects and values must be
 <code>NSString</code>, <code>NSNumber</code>, <code>NSNull</code>,
 <code>NSArray</code>, <code>NSDictionary</code>, <code>NSDate</code> or
 <code>NSURL</code> objects.
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    BuiltAnalyticsEvent *bugEvent = [analytics eventWithUID:@"create_bug"];
    NSDictionary *properties = [bugEvent properties];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var analytics:BuiltAnalytics = builtApplication.analytics()
    var bugEvent:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug")
    var properties:Dictionary = bugEvent.properties
 
 */
@property (nonatomic, copy) NSDictionary *properties;


/**---------------------------------------------------------------------------------------
 * @name Track events
 *  ---------------------------------------------------------------------------------------
 */
/**
 @abstract use this method to trigger the event and add it to batch queue.
 @discussion The analytics will be saved to Built.io Backend regularly depending upon the `batchsize`.
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    BuiltAnalyticsEvent *bugEvent = [analytics eventWithUID:@"create_bug"];
    [bugEvent trigger];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var analytics:BuiltAnalytics = builtApplication.analytics()
    var bugEvent:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug")
    bugEvent.trigger()
 
 */
- (void)trigger;

/**
Use this method to trigger the event immediatley instead if adding in batch queue.
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    BuiltAnalyticsEvent *bugEvent = [analytics eventWithUID:@"create_bug"];
    [bugEvent triggerImmediately];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var analytics:BuiltAnalytics = builtApplication.analytics()
    var bugEvent:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug")
    bugEvent.triggerImmediately()
 
 */
- (void)triggerImmediately;
@end

BUILT_ASSUME_NONNULL_END