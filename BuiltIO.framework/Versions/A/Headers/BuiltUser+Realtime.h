//
//  BuiltUser+Realtime.h
//  BuiltIO
//
//  Created by Reefaq on 03/02/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>
#import "BuiltIORealtime.h"

@class BuiltUserPresence;

@interface BuiltUser (Realtime)

/**
 Registers a event listener on User in general or in particular depending on implementation.
 
 For list of supported events, check [EventType](/Constants/EventType.html)
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *person = [builtApplication user];
 
     //just for example we are using EventTypeCreate.
     [person on:EventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while listening
         }else {
            //BuiltObject instance in response which is recently created
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var person:BuiltUser = builtApplication.user()
 
     //just for example we are using EventType.Create.
     person.on(EventType.Create, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while listening
         }else {
            //BuiltObject instance in response which is recently created
         }
     })
 
@param eventType event types i.e Create/Upate/Delete/Broadcast explained above
@param callback  response object if success or error object
 */
- (void)on:(EventType)eventType callback:(EventCallback)callback;

/**
 Unregisters event listener from User in general or in particular depending on implementation.
 
 For list of supported events, check [EventType](/Constants/EventType.html)
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *person = [builtApplication user];
 
     //just for example we are using EventTypeCreate.
     [person off:EventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while unregister
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var person:BuiltUser = builtApplication.user()
 
     //just for example we are using EventType.Create.
     person.off(EventType.Create, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while unregister
         }
     })

@param eventType Create/Update/Delete/Broadcast
@param callback  response object if success or error object
 */
- (void)off:(EventType)eventType callback:(EventCallback)callback;

/**
 Sending a broadcast message to Object in general or in particular depending on implementation.
 
     // 'blt5d4sample2633b' is dummy Application API key
     
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *person = [builtApplication user];

     [person broadcastWithMessage:@"Hello world" callback:^(id response, NSError *error) {
         if (error) {
            // error while sending message
         }else {
            // sent broadcast message successfully
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var person:BuiltUser = builtApplication.user()
 
     person.broadcastWithMessage("Hello World", callback: { (response, error) -> Void in
         if (error != nil) {
            // error while sending message
         }else {
            // sent broadcast message successfully
         }
     })
 
@param message  message to broadcast
@param callback callback called once broadcast message is send if error occurs error object will be received.
 */
- (void)broadcastWithMessage:(NSString*)message callback:(EventCallback)callback;

//MARK: Presence
/**
Gets BuiltUserPresence instance associated with users

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()

 */
@property (nonatomic, strong, readonly) BuiltUserPresence* presence;

/**
Fetch presence of user by initating network call.

     //Obj-C
     [userObject getPresenceOnCompletion:^(NSError *error) {
         if (error) {
            //error occured while fetching
         }else {
            //userObject.presence is updated
         }
     }];
 
     //Swift
     userObject.getPresenceOnCompletion { (error) -> Void in
         if (error != nil) {
            //error occured while fetching
         }else {
            //userObject.presence is updated
         }
     }

 
@param completionBlock block called once fetch is completed
 */
- (void)getPresenceOnCompletion:(void (^) (NSError *error))completionBlock;

/**
Request for user's presence

     // 'blt5d4sample2633b' is dummy Application API key
     // 'blt5dsamplef62a111a' is dummy object uid of an application user to whom we want to send a request
     
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *userObject = [builtApplication userWithUID:@"blt5dsamplef62a111a"];
     [userObject requestPresenceAccessOnCompletion:^(NSError *error) {
         if (error) {
            //error occured while requesting for presence
         }else {
            //requested for presence
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var userObject:BuiltUser = builtApplication.userWithUID("blt5dsamplef62a111a")
     userObject.requestPresenceAccessOnCompletion { (error) -> Void in
         if (error != nil) {
            //error occured while requesting for presence
         }else {
            //requested for presence
         }
     }
 
@param completionBlock block called once request is performed
 */
- (void)requestPresenceAccessOnCompletion:(void (^) (NSError *error))completionBlock;

//MARK: Deprecated API

/**
 Used as listerner when presence is changed
 
 @param callbackBlock block called once presence is changed
 @deprecated Please use on:callback: with enum EventTypePresence instead.
 */
- (void)onPresenceChange:(void (^) (void))callbackBlock BUILTIO_DEPRECATED("Please use on:callback: with enum EventTypePresence instead.");

/**
 Request for user's presence
 
 @param completionBlock block called once request is performed
 @deprecated Please use requestPresenceAccessOnCompletion: instead.
 */
- (void)requestForPresenceOnCompletion:(void (^) (NSError *error))completionBlock BUILTIO_DEPRECATED("Please use requestPresenceAccessOnCompletion: instead.");


@end
