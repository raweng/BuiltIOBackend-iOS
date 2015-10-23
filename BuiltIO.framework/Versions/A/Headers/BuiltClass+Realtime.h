//
//  BuiltClass+Realtime.h
//  BuiltIO
//
//  Created by Reefaq on 22/01/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>
#import "BuiltIORealtime.h"

@interface BuiltClass (Realtime)

/**
Registers a event listener on Class.

For list of supported events, check [EventType](/Constants/EventType.html)
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //just for example we are using EventTypeUpdate.
     [projectClass on:EventTypeUpdate callback:^(id response, NSError *error) {
        if (error) {
            //some error occured while listening
        }else {
            //Class schema type NSDictionary instance in response which is recently updated
        }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //just for example we are using EventType.Update.
     projectClass.on(EventType.Update, callback: { (response, error) -> Void in
        if (error != nil) {
            //some error occured while listening
        }else {
            //Class schema type NSDictionary instance in response which is recently updated
        }
     })
 
 
 *  @param eventType event types i.e Create/Upate/Delete/Broadcast explained above
 *  @param callback  response object if success or error object
 */
- (void)on:(EventType)eventType callback:(EventCallback)callback;

/**
Unregisters a single or all event listener(s) from Class.
 
     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //just for example we are using EventTypeUpdate.
     [projectClass off:EventTypeUpdate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while unregister
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //just for example we are using EventType.Update.
     projectClass.off(EventType.Update, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while unregister
         }
     })

 
@param eventType Create/Update/Delete/Broadcast
@param callback  response object if success or error object
 */
- (void)off:(EventType)eventType callback:(EventCallback)callback;

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
 */
- (void)broadcastWithMessage:(NSString*)message callback:(EventCallback)callback;

@end
