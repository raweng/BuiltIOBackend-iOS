//
//  BuiltApplication+Realtime.h
//  BuiltIO
//
//  Created by Reefaq on 19/01/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#if !TARGET_OS_WATCH
#import <BuiltIO/BuiltIO.h>
#import "BuiltIORealtime.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltApplication (Realtime)

/**
Enable realtime for current BuiltApplication instance.
 
    // 'blt5d4sample2633b' is dummy Application API key
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication enableRealtimeWithDelegate:self];

    //Swift
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication enableRealtimeWithDelegate:self];

@param delegate objects confirms to BuiltRealtimeDelegate.
@warning Not supported in watchOS
 */
- (void)enableRealtimeWithDelegate:(id<BuiltRealtimeDelegate>)delegate;

/**
 *  Disable realtime for current BuiltApplication instance.
 */
- (void)disableRealtime;

/**
Registers a event listener on notifications.class channel.

For list of supported events, check [BuiltRealtimeEventType](/Constants/BuiltRealtimeEventType.html)

        //ObjC
        BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
        //just for example we are using BuiltRealtimeEventTypeCreate.
        [builtApplication on:BuiltRealtimeEventTypeCreate callback:^(id response, NSError *error) {
            if (error) {
                //some error occured while listening
            }else {
                //Class schema type NSDictionary instance in response which is recently created
            }
        }];

        //Swift
        var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
        //just for example we are using BuiltRealtimeEventType.Create.
        builtApplication.on(BuiltRealtimeEventType.Create, callback: { (response, error) -> Void in
            if (error != nil) {
                //some error occured while listening
            }else {
                //Class schema type NSDictionary instance in response which is recently created
            }
        })
 

@param eventType event types i.e Create/Upate/Delete/Broadcast explained above
@param callback  response object if success or error object
@warning Not supported in watchOS
 */
- (void)on:(BuiltRealtimeEventType)eventType callback:(EventCallback)callback;

/**
Unregisters a event listener from notifications.class channel.
 
For list of supported events, check [BuiltRealtimeEventType](/Constants/BuiltRealtimeEventType.html)

     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     //just for example we are using BuiltRealtimeEventTypeCreate.
     [builtApplication off:BuiltRealtimeEventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while listening
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     //just for example we are using BuiltRealtimeEventType.Create.
     builtApplication.off(BuiltRealtimeEventType.Create, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while listening
         }
     })

@param eventType Create/Update/Delete/Broadcast
@param callback  response object if success or error object
@warning Not supported in watchOS
 */
- (void)off:(BuiltRealtimeEventType)eventType callback:(EventCallback)callback;

/**
Sending a broadcast message to notifications.class channel.

    // 'blt5d4sample2633b' is dummy Application API key

    //ObjC
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication broadcastWithMessage:@"Hello world" callback:^(id response, NSError *error) {
        if (error) {
            // error while sending message
        }else {
            // sent broadcast message successfully
        }
    }];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.broadcastWithMessage("Hello World", callback: { (response, error) -> Void in
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