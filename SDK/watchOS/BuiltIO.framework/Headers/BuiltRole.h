//
//  BuiltRole.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltObject.h"
@class BuiltQuery;

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltRole : BuiltObject

/**
 Get the name of the role.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'blt8h2sample1463j' is a dummy role uid
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithUID:@"blt8h2sample1463j"];
     NSString *roleName = role.roleName;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithUID("blt8h2sample1463j")
     var roleName:String = role.roleName
 
 */
@property(nonatomic, copy, readonly) NSString *roleName;

/**
 Array of users that are included in a `BuiltRole`.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     NSMutableArray *usersArray = role.users;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     var userArray = role.users
 
 */
@property(nonatomic, strong) NSMutableArray *users;

/**
 Array of other roles that are included in a `BuiltRole`. A role may have other roles included in it.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     NSMutableArray *rolesArray = role.roles;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     var roleArray = role.roles
 
 */
@property(nonatomic, strong) NSMutableArray *roles;


- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**---------------------------------------------------------------------------------------
 * @name Check for Users / Roles
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Checks whether a role exists inside this role.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'blt8h2sample1463j' is a dummy role uid
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     if ([role hasRole:@"blt8h2sample1463j"]) {
        //Role exist"
     } else {
        //Role not exist"
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     if (role.hasRole("blt8h2sample1463j")) {
        //Role exist
     } else {
        //Role not exist
     }
 
 
 @param roleUID The uid of the role.
 @return Returns whether the role exists or not.
 */
- (BOOL)hasRole:(NSString *)roleUID;

/**
 @abstract Checks whether a user exists inside this role.
 
     //'blt5d4sample2633b' is a dummy Application API key

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
 
     //'bltba9userdd9e741' is a uid of an object of inbuilt Application User class
     if ([role hasUser:@"bltba9userdd9e741"]) {
        //User exist
     } else {
        //User not exist
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
 
     //'bltba9userdd9e741' is a uid of an object of inbuilt Application User class
     if (role.hasUser("bltba9userdd9e741")) {
        //User exist
     } else {
        //User not exist
     }
 
 
 @param userUid The uid of the user.
 @return Returns whether the user exists or not.
 */
- (BOOL)hasUser:(NSString *)userUid;

/**---------------------------------------------------------------------------------------
 * @name Set Name
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Set the name for the role. This value must be set before the role has been saved, and cannot be set once the role has been saved. A role's name can only contain alphanumeric characters, _, -, and spaces.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'blt8h2sample1463j' is a dummy role uid

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithUID:@"role_uid"];
     [role setName:@"Manager"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithUID("role_uid")
     role.setName("Manager")
 
 @param name name of the role.
 */
- (void)setName:(NSString *)name;

/**---------------------------------------------------------------------------------------
 * @name Add Users
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Adds a user to a role
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'bltba9a44506dd9e741' is a uid of an object of inbuilt Application User class

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     [role addUser:@"bltba9a44506dd9e741"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     role.addUser("bltba9a44506dd9e741")
 
 
 @param userUid User's uid that needs to be added to the role.
 */
- (void)addUser:(NSString *)userUid;

/**
@abstract Adds a user's to a role

     //'blt5d4sample2633b' is a dummy Application API key
     //'bltba9a44506dd9e741', 'bltfn5e54207ab7r451' is a uid of an object of inbuilt Application User class
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     [role addUsers:@[@"bltba9a44506dd9e741", @"bltfn5e54207ab7r451"]];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     role.addUsers(["bltba9a44506dd9e741", "bltfn5e54207ab7r451"])

 
@param userArray Array containing User's uid or BuiltUser object that needs to be added to the role.
 */
- (void)addUsers:(NSArray*)userArray;

/**
 @abstract Adds users through query in given role.
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltRole *role = [builtApplication roleWithName:@"Manager"];
    BuiltQuery *query = [builtApplication userQuery];
    [query whereKey:@"email" matchesRegex:@".john" modifiers:@"i"];
    [role setUsersWithQuery:query];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var role:BuiltRole = builtApplication.roleWithName("Manager")
    var query:BuiltQuery = builtApplication.userQuery()
    query.whereKey("email", matchesRegex: ".john", modifiers: "i")
    role.setUsersWithQuery(query)
 
@param query BuiltQuery contains condition to select group of users to assign for current role.
 
    @note BuiltQuery object must be created from 'built_io_application_user' class,
 which we can create using method 'userQuery' from BuiltApplication class.

 */
-(void)setUsersWithQuery:(BUILT_NONNULL BuiltQuery *)query;

/**---------------------------------------------------------------------------------------
 * @name Remove Users
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Removes a user from a role
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'bltba9a44506dd9e741' is a uid of an object of inbuilt Application User class

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     [role removeUser:@"bltba9a44506dd9e741"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     role.removeUser("bltba9a44506dd9e741")
 
 @param userUid User's uid that needs to be removed from the role.
 */
- (void)removeUser:(NSString *)userUid;

/**
 @abstract Removes users from a role
    
     //'blt5d4sample2633b' is a dummy Application API key
     //'bltba9a44506dd9e741', 'bltfn5e54207ab7r451' is a uid of an object of inbuilt Application User class
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     [role removeUsers:@[@"bltba9a44506dd9e741", @"bltfn5e54207ab7r451"]];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     role.removeUsers(["bltba9a44506dd9e741", "bltfn5e54207ab7r451"])

 
@param userArray Array containing User's uid or BuiltUser object that needs to be removed from the role.
 */
- (void)removeUsers:(NSArray*)userArray;

/**---------------------------------------------------------------------------------------
 * @name Add Roles
 *  ---------------------------------------------------------------------------------------
 */

/**
@abstract Adds a role to this role.
 
     //'blt5d4sample2633b' is a dummy Application API key

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     [role addRole:@"blt4d5sample1962c"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     role.addRole("blt4d5sample1962c")
 
 @param roleUid uid of the role that has to be added to this role.
 */
- (void)addRole:(NSString *)roleUid;

/**
@abstract Adds role's to this role.
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     [role addRoles:@[@"blt4d5sample1962c", @"blt4d5sample1854a"]];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     role.addRoles(["blt4d5sample1962c", "blt4d5sample1854a"])

 
@param roleArray Array of role uid or role object that has to be added to this role.
 */
- (void)addRoles:(NSArray*)roleArray;

/**---------------------------------------------------------------------------------------
 * @name Remove Roles
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Removes a role from this role if it exists.
 
     //'blt5d4sample2633b' is a dummy Application API key

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     [role removeRole:@"blt4d5sample1962c"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     role.removeRole("blt4d5sample1962c")
 
 
 @param roleUid uid of the role that has to be removed from this role.
 */
- (void)removeRole:(NSString *)roleUid;

/**
 @abstract Removes roles from this role if it exists.
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *role = [builtApplication roleWithName:@"Manager"];
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     [role removeRoles:@[@"blt4d5sample1962c", @"blt4d5sample1854a"]];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var role:BuiltRole = builtApplication.roleWithName("Manager")
     //'blt4d5sample1962c' is a dummy role uid which we want to remove
     role.removeRoles(["blt4d5sample1962c", "blt4d5sample1854a"])

 @param roleArray Array of role uid or role object that has to be removed from this role.
 */
- (void)removeRoles:(NSArray*)roleArray;

@end

BUILT_ASSUME_NONNULL_END
