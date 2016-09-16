//
//  BuiltObject+Realtime.h
//  BuiltIO
//
//  Created by Reefaq on 02/02/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>
#import "BuiltIORealtime.h"

@interface BuiltObject (Realtime)

/**
Registers a event listener on Object in general or in particular depending on implementation.
 
For list of supported events, check [EventType](/Constants/EventType.html)

     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject = [projectClass object];
 
     //just for example we are using EventTypeCreate.
     [projectObject on:EventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while listening
         }else {
            //BuiltObject instance in response which is recently created
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
 
     //just for example we are using EventType.Create.
     projectObject.on(EventType.Create, callback: { (response, error) -> Void in
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
Unregisters event listener(s) from Object in general or in particular depending on implementation.

For list of supported events, check [EventType](/Constants/EventType.html)

     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject = [projectClass object];
     
     //just for example we are using EventTypeCreate.
     [projectObject off:EventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while unregister
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
 
     //just for example we are using EventType.Create.
     projectObject.off(EventType.Create, callback: { (response, error) -> Void in
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
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject = [projectClass object];
     [projectObject broadcastWithMessage:@"Hello world" callback:^(id response, NSError *error) {
         if (error) {
            // error while sending message
         }else {
            // sent broadcast message successfully
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject.broadcastWithMessage("Hello World", callback: { (response, error) -> Void in
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
