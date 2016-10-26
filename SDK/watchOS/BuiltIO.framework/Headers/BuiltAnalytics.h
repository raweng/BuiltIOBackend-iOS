//
//  BuiltAnalytics.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@class BuiltAnalyticsEvent;

BUILT_ASSUME_NONNULL_BEGIN
/**
 Class for integrating BuiltAnalytics support for apps.
 Use BuiltAnalytics class to track an event to analyse the datapoints, the usecase and usage behaviour throughout the app.


    // 'blt5d4sample2633b' is a dummy Application API key
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];

    // Set super properties that are to be sent with every event
    NSDictionary *superProperties = @{@"company_name": @"raweng"};
    [analytics registerSuperProperties:superProperties];

    //Create event
    BuiltEvent *loginEvent = [analytics eventWithUID:@"logged_in"];

    //Track event
    [loginEvent trigger];
 
 */
@interface BuiltAnalytics : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**---------------------------------------------------------------------------------------
 * @name Initializing
 *  ---------------------------------------------------------------------------------------
 */

/**
 Represents a analytics event in this application.
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     BuiltAnalyticsEvent *bugEvent = [analytics eventWithUID:@"create_bug"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics =  builtApplication.analytics()
     var bugEvent:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug")
 
 @param eventName name of event
 @return Returns an instance of a BuiltAnalyticsEvent.
 */
- (BuiltAnalyticsEvent*)eventWithUID:(NSString*)eventUID;

//MARK: - Headers
/**---------------------------------------------------------------------------------------
 * @name Headers
 *  ---------------------------------------------------------------------------------------
 */

/**
 Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     [analytics setHeader:@"MyValue" forKey:@"My-Custom-Header"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics =  builtApplication.analytics()
     analytics.setHeader("MyValue", forKey:"My-Custom-Header")
 
 @param headerValue The header key
 @param headerKey   The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
 Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     [analytics addHeadersWithDictionary:@{@"My-Custom-Header": @"MyValue"}];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics =  builtApplication.analytics()
     analytics.addHeadersWithDictionary(["My-Custom-Header":"MyValue"])
 
 @param headers The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
 Removes a header from this application.
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     [analytics removeHeaderForKey:@"My-Custom-Header"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics =  builtApplication.analytics()
     analytics.removeHeaderForKey("My-Custom-Header")
 
 @param headerKey The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;

//MARK: - Properties
/**---------------------------------------------------------------------------------------
 * @name Properties
 *  ---------------------------------------------------------------------------------------
 */

/**
 *  Threshold batch size for event to flush. If set below 2 then event will be triggered immediately or else it will send when its greater than or equal to batch size.

    // 'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    analytics.batchSize = 10;
    NSInteger batchSize = analytics.batchSize; //Read the batch size

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var analytics:BuiltAnalytics =  builtApplication.analytics()
    analytics.batchSize = 10
    let batchSize:Integer = analytics.batchSize //Read the batch size
 
 
 */
@property (nonatomic, assign) NSInteger batchSize;

/**
 *  If FALSE then loggedin user id will be attached with the event for user base analytics if set TRUE user info is not been tracked by analytics. By default its FALSE. Value is inhereted from BuiltApplication's trackAnonymously property when instance is created.
 

    // 'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    if ([analytics isAnonymousTrackingEnabled]) {
        analytics.trackAnonymously = YES;
    } else {
        analytics.trackAnonymously = NO;
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var analytics:BuiltAnalytics =  builtApplication.analytics()
    if (analytics.isAnonymousTrackingEnabled) {
        // Anonymously tracking events
    } else {
        // User based tracking
    }
 
 */
@property (nonatomic, assign, getter=isAnonymousTrackingEnabled) BOOL trackAnonymously;

//MARK: - Register super/dynamic properties

/**---------------------------------------------------------------------------------------
 * @name Register super/dynamic properties
 *  ---------------------------------------------------------------------------------------
 */

/**
Registers super properties, overwriting ones that have already been set.
 
 @discussion Super properties, once registered, are automatically sent as properties for
 all event tracking calls. They save you having to maintain and add a common
 set of properties to your events. Property keys must be <code>NSString</code>
 objects and values must be <code>NSString</code>, <code>NSNumber</code>,
 <code>NSNull</code>, <code>NSArray</code>, <code>NSDictionary</code>,
 <code>NSDate</code> or <code>NSURL</code> objects.
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    [analytics registerSuperProperties:@{@"Custom_Key":@"Custom_Value"}];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var analytics:BuiltAnalytics =  builtApplication.analytics()
    analytics.registerSuperProperties(["Custom_Key":"Custom_Value"])
 
@param superProperties super properties dictionary
 */
- (void)registerSuperProperties:(NSDictionary *)superProperties;

/**
Registers dynamic properties, this will be common properties when will set when event is about to trigger. Dynamic change properties i.e Wifi status etc can be terms as Dynamic properties.
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     [analytics registerDynamicPropertiesWithBlock:^NSDictionary *(NSString *eventUID) {
        if([eventUID isEqualToString:@"home"]) {
            return @{@"Custom_Key":@"Custom_Value"};
        }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics =  builtApplication.analytics()
     analytics.registerDynamicPropertiesWithBlock { (eventUID) -> [NSObject : AnyObject]! in
        if([eventUID isEqualToString:@"home"]) {
            return ["Custom_Key":"Custom_Value"]
        }
     }
 
@discussion Property keys must be <code>NSString</code>
 objects and values must be <code>NSString</code>, <code>NSNumber</code>,
 <code>NSNull</code>, <code>NSArray</code>, <code>NSDictionary</code>,
 <code>NSDate</code> or <code>NSURL</code> objects.
 
@param dynamicPropertyBlock block that will execute to register properties.
 */
- (void)registerDynamicPropertiesWithBlock:(NSDictionary* (^) (NSString* eventUID))dynamicPropertyBlock;

//MARK: - Trigger events

/**---------------------------------------------------------------------------------------
 * @name Trigger events
 *  ---------------------------------------------------------------------------------------
 */

/**
Trigger multiple events
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     BuiltAnalyticsEvent *eventBug1 = [analytics eventWithUID:@"create_bug1"];
     BuiltAnalyticsEvent *eventBug2 = [analytics eventWithUID:@"create_bug2"];
     [analytics triggerEventsFromArray:@[eventBug1, eventBug2]];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics =  builtApplication.analytics()
     var eventBug1:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug1")
     var eventBug2:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug2")
     analytics.triggerEventsFromArray([eventBug1, eventBug2])

 
@param events multiple event object, terminated by nil.
 */
-(void)triggerEventsFromArray:(NSArray*)events;


/**
Trigger multiple events
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltAnalytics *analytics = [builtApplication analytics];
    BuiltAnalyticsEvent *eventBug1 = [analytics eventWithUID:@"create_bug1"];
    BuiltAnalyticsEvent *eventBug2 = [analytics eventWithUID:@"create_bug2"];
    [analytics triggerEventsImmediatelyFromArray:@[eventBug1, eventBug2]];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics =  builtApplication.analytics()
     var eventBug1:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug1")
     var eventBug2:BuiltAnalyticsEvent = analytics.eventWithUID("create_bug2")
     analytics.triggerEventsImmediatelyFromArray([eventBug1, eventBug2])

@param events array object.
 */
-(void)triggerEventsImmediatelyFromArray:(NSArray*)events;

/**---------------------------------------------------------------------------------------
 * @name Forcefully Send
 *  ---------------------------------------------------------------------------------------
 */

/**
Forcefully send all events at background to the server.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     [analytics flush];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics = builtApplication.analytics()
     analytics.flush()
 
 */
-(void)flush;

/**---------------------------------------------------------------------------------------
 * @name Cancel
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Advises the operation object that it should stop executing its task.
 @discussion This method does not force your operation code to stop. Instead, it updates the object’s internal flags to reflect the change in state. If the operation has already finished executing, this method has no effect. Canceling an operation that is currently in an operation queue, but not yet executing, makes it possible to remove the operation from the queue sooner than usual.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     [analytics cancel];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics = builtApplication.analytics()
     analytics.cancel()
 
 */
- (void)cancel;

@end

BUILT_ASSUME_NONNULL_END