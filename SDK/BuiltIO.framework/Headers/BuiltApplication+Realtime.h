//
//  BuiltApplication+Realtime.h
//  BuiltIO
//
//  Created by Reefaq on 19/01/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>
#import "BuiltIORealtime.h"

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
 */
- (void)enableRealtimeWithDelegate:(id<BuiltRealtimeDelegate>)delegate;

/**
 *  Disable realtime for current BuiltApplication instance.
 */
- (void)disableRealtime;

/**
Registers a event listener on notifications.class channel.

For list of supported events, check [EventType](/Constants/EventType.html)

        //ObjC
        BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
        //just for example we are using EventTypeCreate.
        [builtApplication on:EventTypeCreate callback:^(id response, NSError *error) {
            if (error) {
                //some error occured while listening
            }else {
                //Class schema type NSDictionary instance in response which is recently created
            }
        }];

        //Swift
        var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
        //just for example we are using EventType.Create.
        builtApplication.on(EventType.Create, callback: { (response, error) -> Void in
            if (error != nil) {
                //some error occured while listening
            }else {
                //Class schema type NSDictionary instance in response which is recently created
            }
        })
 

@param eventType event types i.e Create/Upate/Delete/Broadcast explained above
@param callback  response object if success or error object
 */
- (void)on:(EventType)eventType callback:(EventCallback)callback;

/**
Unregisters a event listener from notifications.class channel.
 
For list of supported events, check [EventType](/Constants/EventType.html)

     //ObjC
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     //just for example we are using EventTypeCreate.
     [builtApplication off:EventTypeCreate callback:^(id response, NSError *error) {
         if (error) {
            //some error occured while listening
         }
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     //just for example we are using EventType.Create.
     builtApplication.off(EventType.Create, callback: { (response, error) -> Void in
         if (error != nil) {
            //some error occured while listening
         }
     })

@param eventType Create/Update/Delete/Broadcast
@param callback  response object if success or error object
 */
- (void)off:(EventType)eventType callback:(EventCallback)callback;

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
 */
- (void)broadcastWithMessage:(NSString*)message callback:(EventCallback)callback;

//MARK: Deprecated

/**
Set realtime host, port and ssl

@param realtimeHost realtime host
@param port         realtime port
@param ssl          realtime ssl
@deprecated Please use BuiltConfig instead.
 */
-(void)setRealtimeHost:(NSString *)realtimeHost withPort:(NSInteger)port isSSL:(BOOL)ssl BUILTIO_DEPRECATED("Please use BuiltConfig instead.");

@end
