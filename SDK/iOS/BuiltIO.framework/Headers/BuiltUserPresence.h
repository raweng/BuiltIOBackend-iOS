//
//  BuiltUserPresence.h
//  BuiltIO
//
//  Created by Reefaq on 04/02/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//
#if !TARGET_OS_WATCH
#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BuiltRealtimeUserPresenceStatus) {
    BuiltRealtimeUserPresenceStatusOffline,
    BuiltRealtimeUserPresenceStatusOnline
};

@class BuiltUser;

@interface BuiltUserPresence : NSObject
/**
Online and Offline status of the user.

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     if (presence.status == BuiltRealtimeUserPresenceStatusOnline) {
        //user is online
     }else {
        //user is offline
     }
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     if (presence.status == BuiltRealtimeUserPresenceStatus.Online) {
        //user is online
     }else {
        //user is offline
     }

@warning Not supported in watchOS
 */
@property (nonatomic, assign, readonly) BuiltRealtimeUserPresenceStatus status;
/**
Last seen timestamp of the user.

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     NSDate *lastSeen = presence.lastSeen;
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var lastSeen:NSDate = presence.lastSeen()
 
@warning Not supported in watchOS
 */
@property (nullable, nonatomic, copy, readonly) NSDate* lastSeen;


/**
Enable or disable presence. If disabled user presence will not to shown to others.
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     presence.enable = YES;
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     presence.enable = true

@warning Not supported in watchOS
 */
@property (nonatomic, assign, getter=isEnable) BOOL enable;

/**
Save presence
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     [presence save:^(NSError *error) {
         if (error) {
            //some error occured while saving
         }else {
            //presence saved
         }
     }];
 
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     builtApplication.currentUser.presence.save { (error) -> Void in
         if (error != nil) {
            //some error occured while saving presence
         }else {
            //presence saved
         }
     }
 
@param completionBlock block called once save is completed. error object present if occured
@warning Not supported in watchOS
 */
- (void)save:(void (^) (NSError * BUILT_NULLABLE_P error))completionBlock;

@end

BUILT_ASSUME_NONNULL_END
#endif