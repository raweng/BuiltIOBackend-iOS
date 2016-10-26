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
Pending users array requested for presence access.

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     NSArray *usersRequestedForPresence = presence.requests;
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var usersRequestedForPresence:NSArray = presence.requests()

@warning Not supported in watchOS
 */
@property (nullable, nonatomic, copy, readonly) NSArray* requests;

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
 Type of Privacy i.e Public or Private. If set as FLASE it will be considered Private.
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     presence.isPublic = YES;
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     presence.isPublic = true

 @warning Not supported in watchOS
 */
@property (nonatomic, assign) BOOL isPublic;

/**
Status message of the user if present.
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     presence.statusMessage = @"Hello Built.io";
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     presence.statusMessage = "Hello Built.io"

@warning Not supported in watchOS
 */
@property (nullable ,nonatomic, copy) NSString* statusMessage;

/**
List of users allowed for presence

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     NSArray *whitelistUsers = [presence whitelistUsers];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var whitelistUsers:NSArray = presence.whitelistUsers()
 
@return array of users's uid
@warning Not supported in watchOS
 */
-(nullable NSArray*)whitelistUsers;


/**
Add all users who requested to acess in whitelist

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     [presence acceptRequests];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     presence.acceptRequests()

@warning Not supported in watchOS
 */
-(void)acceptRequests;

/**
Add user in whitelist
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     BuiltUser *otherUserObject = [builtApplication userWithUID:@"blt5dsamplef62a111a"];
 
     [presence addUserInWhiteList:otherUserObject];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var otherUserObject:BuiltUser = builtApplication.userWithUID("blt5dsamplef62a111a")
 
     presence.addUserInWhiteList(otherUserObject)
 
@param user BuiltUser object to add in whitelist
@warning Not supported in watchOS
 */
-(void)addUserInWhiteList:(BuiltUser*)user;

/**
 Add user's uid in whitelist
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     [presence addUserUidInWhiteList:@"blt5dsamplef62a111a"];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     presence.addUserUidInWhiteList("blt5dsamplef62a111a")
 
 @param userUID uid of BuiltUser object
 @warning Not supported in watchOS
 */
-(void)addUserUidInWhiteList:(NSString*)userUID;

/*
Remove user from whitelist
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     BuiltUser *userObjectToRemove = [builtApplication userWithUID:@"blt5dsamplef62a111a"];
     
     [presence removeUserFromWhiteList:userObjectToRemove];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var userObjectToRemove:BuiltUser = builtApplication.userWithUID("blt5dsamplef62a111a")
     
     presence.removeUserFromWhiteList(userObjectToRemove)

@param user BuiltUser object to remove in whitelist
@warning Not supported in watchOS
 */
-(void)removeUserFromWhiteList:(BuiltUser*)user;


/**
 Remove user's uid from whitelist
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     [presence removeUserUidFromWhiteList:@"blt5dsamplef62a111a"];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     presence.removeUserUidFromWhiteList("blt5dsamplef62a111a")

 @param userUID uid of BuiltUser object
 @warning Not supported in watchOS
 */
-(void)removeUserUidFromWhiteList:(NSString*)userUID;

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