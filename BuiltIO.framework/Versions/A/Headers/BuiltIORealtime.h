//
//  BuiltIORealtime.h
//  BuiltIO
//
//  Created by Reefaq on 19/01/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#ifndef BuiltIO_BuiltIORealtime_h
#define BuiltIO_BuiltIORealtime_h

/**
 *  List of supported events for realtime
 */
typedef NS_ENUM(NSUInteger, EventType){
    /**
     *  Update event is triggered when, any class/object/upload in this application is modified. Registered callback is invoked with updated class/object/upload data.
     */
    EventTypeUpdate,
    /**
     *  Delete event is triggered when, any class/object/upload in this application is deleted. Registered callback is invoked with deleted class/object/upload data.
     */
    EventTypeDelete,
    /**
     *  Create event is triggered when, a new class/object/upload is created in this application. Registered callback is invoked with created class/object/upload data.
     */
    EventTypeCreate,
    /**
     *  Broadcast event is triggered when, a message is broadcasted for all classes/objects/uploads belonging to this application. Registered callback is invoked with the broadcasted message.
     */
    EventTypeBroadcast,
    
    /**
     *  Presence event is triggered when, user presence info is changed. Registered callback is invoked with the presence object.
     */
    EventTypePresence
};
typedef void (^EventCallback)(id response, NSError* error);

@protocol BuiltRealtimeDelegate <NSObject>
/**
 *  delegate method when realtime application will connect
 *
 *  @param builtApplication instance which will connect
 */
-(void)builtRealtimeApplicationWillConnect:(BuiltApplication*)builtApplication;

/**
 *  delegate method when realtime application is connected
 *
 *  @param builtApplication instance which is connected
 */
-(void)builtRealtimeApplicationDidConnect:(BuiltApplication*)builtApplication;

/**
 *  delegate method when realtime application will disconnect
 *
 *  @param builtApplication instance which will be disconnected
 */
-(void)builtRealtimeApplicationWillDisconnect:(BuiltApplication*)builtApplication;

/**
 *  delegate method when realtime application is disconnected
 *
 *  @param builtApplication instance which is disconnected
 */
-(void)builtRealtimeApplicationDidDisconnect:(BuiltApplication*)builtApplication;

/**
 *  delegate method when realtime application received error.
 *
 *  @param builtApplication instance which got error
 *  @param error            error which occured
 */
-(void)builtRealtimeApplication:(BuiltApplication*)builtApplication didReceivedError:(NSError*)error;

/**
 *  delegate method when realtime application will reconnect.
 *
 *  @param builtApplication instance which will reconnect
 */
-(void)builtRealtimeApplicationWillReconnect:(BuiltApplication*)builtApplication;
@end

#import "BuiltApplication+Realtime.h"
#import "BuiltClass+Realtime.h"
#import "BuiltObject+Realtime.h"
#import "BuiltUpload+Realtime.h"
#import "BuiltUser+Realtime.h"
#import "BuiltUserPresence.h"

#endif
