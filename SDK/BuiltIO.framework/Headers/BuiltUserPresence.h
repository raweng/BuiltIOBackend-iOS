//
//  BuiltUserPresence.h
//  BuiltIO
//
//  Created by Reefaq on 04/02/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

typedef NS_ENUM(NSUInteger, PresenceStatus) {
    PresenceStatusOffline,
    PresenceStatusOnline
};


@class BuiltUser;

@interface BuiltUserPresence : NSObject
/**
Online and Offline status of the user.

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     if (presence.status == PresenceStatusOnline) {
        //user is online
     }else {
        //user is offline
     }
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     if (presence.status == PresenceStatus.Online) {
        //user is online
     }else {
        //user is offline
     }
 
 */
@property (nonatomic, assign, readonly) PresenceStatus status;
/**
Last seen timestamp of the user.

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     NSDate *lastSeen = presence.lastSeen;
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var lastSeen:NSDate = presence.lastSeen()
 
 */
@property (nonatomic, copy, readonly) NSDate* lastSeen;

/**
Pending users array requested for presence access.

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     NSArray *usersRequestedForPresence = presence.requests;
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var usersRequestedForPresence:NSArray = presence.requests()

 
 */
@property (nonatomic, copy, readonly) NSArray* requests;

/**
Enable or disable presence. If disabled user presence will not to shown to others.
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     presence.enable = YES;
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     presence.enable = true

 
 */
@property (nonatomic, assign, getter=isEnable) BOOL enable;

/**
 *  Type of Privacy i.e Public or Private. If set as FLASE it will be considered Private.
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

 
 */
@property (nonatomic, copy) NSString* statusMessage;

/**
List of users allowed for presence

     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     NSArray *whitelistUsers = [presence whitelistUsers];
     
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     var whitelistUsers:NSArray = presence.whitelistUsers()

 
@return array of users's uid
 */
-(NSArray*)whitelistUsers;


/**
 *  Add all users who requested to acess in whitelist
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
 */
-(void)addUserInWhiteList:(BuiltUser*)user;

/**
 *  Add user's uid in whitelist
 *
 *  @param userUID uid of BuiltUser object
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
 */
-(void)removeUserFromWhiteList:(BuiltUser*)user;


/**
 *  Remove user's uid from whitelist
 *
 *  @param userUID uid of BuiltUser object
 */
-(void)removeUserUidFromWhiteList:(NSString*)userUID;

/**
Save presence
 
     //Obj-C
     BuiltUserPresence *presence = [userObject presence];
     [presence saveOnCompletion:^(NSError *error) {
         if (error) {
            //some error occured while saving
         }else {
            //presence saved
         }
     }];
 
     //Swift
     var presence:BuiltUserPresence = userObject.presence()
     builtApplication.currentUser.presence.saveOnCompletion { (error) -> Void in
         if (error != nil) {
            //some error occured while saving presence
         }else {
            //presence saved
         }
     }
 
@param completionBlock block called once save is completed. error object present if occured
 */
- (void)saveOnCompletion:(void (^) (NSError *error))completionBlock;

//MARK: Deprecated API

/**
 * Type of Privacy i.e Public or Private. If set as FLASE it will be considered Private.
 *
 * @deprecated Enum is been removed. Please use isPublic property instead.
 */
@property (nonatomic, assign) id privacyType __attribute__((deprecated));


@end
