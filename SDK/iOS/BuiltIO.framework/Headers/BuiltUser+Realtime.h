//
//  BuiltUser+Realtime.h
//  BuiltIO
//
//  Created by Reefaq on 03/02/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//
#if !TARGET_OS_WATCH
#import <BuiltIO/BuiltIO.h>
#import "BuiltIORealtime.h"

BUILT_ASSUME_NONNULL_BEGIN

@class BuiltUserPresence;

@interface BuiltUser (Realtime)

/**
 Registers a event listener on User in general or in particular depending on implementation.
 
 For list of supported events, check [BuiltRealtimeEventType](/Constants/BuiltRealtimeEventType.html)
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *person = [builtApplication user];
 
     //just for example we are using BuiltRealtimeEventTypeCreate.
     [person on:BuiltRealtimeEventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while listening
         }else {
            //BuiltObject instance in response which is recently created
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var person:BuiltUser = builtApplication.user()
 
     //just for example we are using BuiltRealtimeEventType.Create.
     person.on(BuiltRealtimeEventType.Create, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while listening
         }else {
            //BuiltObject instance in response which is recently created
         }
     })
 
@param eventType event types i.e Create/Upate/Delete/Broadcast explained above
@param callback  response object if success or error object
 */
- (void)on:(BuiltRealtimeEventType)eventType callback:(EventCallback)callback;

/**
 Unregisters event listener from User in general or in particular depending on implementation.
 
 For list of supported events, check [BuiltRealtimeEventType](/Constants/BuiltRealtimeEventType.html)
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *person = [builtApplication user];
 
     //just for example we are using BuiltRealtimeEventTypeCreate.
     [person off:BuiltRealtimeEventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while unregister
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var person:BuiltUser = builtApplication.user()
 
     //just for example we are using BuiltRealtimeEventType.Create.
     person.off(BuiltRealtimeEventType.Create, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while unregister
         }
     })

@param eventType Create/Update/Delete/Broadcast
@param callback  response object if success or error object
 */
- (void)off:(BuiltRealtimeEventType)eventType callback:(EventCallback)callback;

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

@warning Not supported in watchOS
 */
@property (nonatomic, strong, readonly) BuiltUserPresence* presence;

/**
Fetch presence of user by initating network call.

     //Obj-C
     [userObject getPresence:^(NSError *error) {
         if (error) {
            //error occured while fetching
         }else {
            //userObject.presence is updated
         }
     }];
 
     //Swift
     userObject.getPresence { (error) -> Void in
         if (error != nil) {
            //error occured while fetching
         }else {
            //userObject.presence is updated
         }
     }

 
@param completionBlock block called once fetch is completed
@warning Not supported in watchOS
 */
- (void)getPresence:(void (^) (NSError * BUILT_NULLABLE_P error))completionBlock;

@end

BUILT_ASSUME_NONNULL_END
#endif
