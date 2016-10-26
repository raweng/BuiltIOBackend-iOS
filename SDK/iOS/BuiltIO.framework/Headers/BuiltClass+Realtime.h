//
//  BuiltClass+Realtime.h
//  BuiltIO
//
//  Created by Reefaq on 22/01/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#if !TARGET_OS_WATCH
#import <BuiltIO/BuiltIO.h>
#import "BuiltIORealtime.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltClass (Realtime)

/**
Registers a event listener on Class.

For list of supported events, check [BuiltRealtimeEventType](/Constants/BuiltRealtimeEventType.html)
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //just for example we are using BuiltRealtimeEventTypeUpdate.
     [projectClass on:BuiltRealtimeEventTypeUpdate callback:^(id response, NSError *error) {
        if (error) {
            //some error occured while listening
        }else {
            //Class schema type NSDictionary instance in response which is recently updated
        }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //just for example we are using BuiltRealtimeEventType.Update.
     projectClass.on(BuiltRealtimeEventType.Update, callback: { (response, error) -> Void in
        if (error != nil) {
            //some error occured while listening
        }else {
            //Class schema type NSDictionary instance in response which is recently updated
        }
     })
 
 
 @param eventType event types i.e Create/Upate/Delete/Broadcast explained above
 @param callback  response object if success or error object
 @warning Not supported in watchOS
 
 */
- (void)on:(BuiltRealtimeEventType)eventType callback:(EventCallback)callback;

/**
Unregisters a single or all event listener(s) from Class.
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //just for example we are using BuiltRealtimeEventTypeUpdate.
     [projectClass off:BuiltRealtimeEventTypeUpdate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while unregister
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //just for example we are using BuiltRealtimeEventType.Update.
     projectClass.off(BuiltRealtimeEventType.Update, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while unregister
         }
     })

 
@param eventType Create/Update/Delete/Broadcast
@param callback  response object if success or error object
@warning Not supported in watchOS
 */
- (void)off:(BuiltRealtimeEventType)eventType callback:(EventCallback)callback;

/**
Sending a broadcast message to all the classes of particular class if class object is created by classUID.
 
     // 'blt5d4sample2633b' is dummy Application API key
     
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     [projectClass broadcastWithMessage:@"Hello world" callback:^(id response, NSError *error) {
         if (error) {
            // error while sending message
         }else {
            // sent broadcast message successfully
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     projectClass.broadcastWithMessage("Hello World", callback: { (response, error) -> Void in
         if (error != nil) {
            // error while sending message
         }else {
            // sent broadcast message successfully
         }
     })
 
@param message  message to broadcast
@param callback callback called once broadcast message is send if error occurs error object will be received.
@warning Not supported in watchOS
 */
- (void)broadcastWithMessage:(NSString*)message callback:(EventCallback)callback;

@end

BUILT_ASSUME_NONNULL_END

#endif