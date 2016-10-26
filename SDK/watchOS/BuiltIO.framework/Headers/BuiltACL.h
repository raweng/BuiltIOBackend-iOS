//
//  BuiltACL.h
//  BuiltIO
//
//  Created by Reefaq on 30/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltACL : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
/**---------------------------------------------------------------------------------------
 * @name Disable ACL
 *  ---------------------------------------------------------------------------------------
 */
/**
 Disables ACL on a particular BuiltObject.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     [aclObject disableACL:YES];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     aclObject.disableACL(true)
 
 @param disable When true disables ACL on BuiltObject, ables otherwise.
 */
- (void)disableACL:(BOOL)disable;

/**
 States whether ACL is enabled or disabled on BuiltObject.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     if ([aclObject isDisabled]) {
        // ACL enable
     } else {
        // ACL disable
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     if (aclObject.isDisabled) {
        // ACL enable
     } else {
        // ACL disable
     }
 
 @return Returns true/YES if ACL is enabled, false/NO otherwise.
 */
- (BOOL)isDisabled;

/**---------------------------------------------------------------------------------------
 * @name Controlling Public Access
 *  ---------------------------------------------------------------------------------------
 */
/**
 Set whether the others is allowed to read this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setPublicReadAccess:YES];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setPublicReadAccess(true)
 
 @param allowed Whether read access is allowed (YES/true or NO/false).
 */
- (void)setPublicReadAccess:(BOOL)allowed;


/**
 Gets whether the others is allowed to read this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getPublicReadAccess]) {
       // ACL public read access
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getPublicReadAccess()) {
        // ACL public read access
    }
 
 @return Returns YES if read access is granted to others. NO otherwise.
 */
- (BOOL)getPublicReadAccess;


/**
 Set whether the others is allowed to write this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setPublicWriteAccess:YES];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setPublicWriteAccess(true)
 
 @param allowed Whether write access is allowed (YES/true or NO/false).
 */
- (void)setPublicWriteAccess:(BOOL)allowed;


/**
 Gets whether the others is allowed to write this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if([aclObject getPublicWriteAccess]) {
        //ACL public write access is granted
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getPublicWriteAccess()) {
        //ACL public write access is granted
    }
 
 @return Returns YES if write access is granted to others. NO otherwise.
 */
- (BOOL)getPublicWriteAccess;


/**
 Set whether the others is allowed to delete this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setPublicDeleteAccess:YES];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setPublicDeleteAccess(true)
 
 @param allowed Whether delete access is allowed (YES/true or NO/false).
 */
- (void)setPublicDeleteAccess:(BOOL)allowed;


/**
 Gets whether the others is allowed to delete this object.
 

    //'blt5d4sample2633b' is a dummy Application API key
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getPublicDeleteAccess]) {
        // ACL public delete access
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getPublicDeleteAccess()) {
        // ACL public delete access
    }
 
 @return Returns YES if delete access is granted to others. NO otherwise.
 */
- (BOOL)getPublicDeleteAccess;


/**---------------------------------------------------------------------------------------
 * @name Controlling Access Per-User
 *  ---------------------------------------------------------------------------------------
 */
/**
 Set whether the given user id is allowed to read this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltba9sampleuser41' is a uid of an object of inbuilt Application User class
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setReadAccess:YES forUserId:@"bltba9sampleuser41"];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setReadAccess(true, forUserId:"bltba9sampleuser41")
 
 @param allowed Whether read access is allowed (YES/true or NO/false).
 @param userId The user id to assign access.
 */
- (void)setReadAccess:(BOOL)allowed forUserId:(NSString *)userId;


/**
 Gets whether the given user id is explicitly allowed to read this object.
 Even if this returns NO, the user may still be able to access it if getPublicReadAccess returns YES
 or if the user belongs to a role that has access.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltba9sampleuser41' is a uid of an object of inbuilt Application User class
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getReadAccessForUserId:@"bltba9sampleuser41"]) {
        // Read access
    } else {
        // No Read access
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getReadAccessForUserId("bltba9sampleuser41")) {
        // Read access
    } else {
        // No Read access
    }
 
 @param userId User ID for which to check read access.
 @return Returns YES if read access is granted to others. NO otherwise.
 */
- (BOOL)getReadAccessForUserId:(NSString *)userId;


/**
 Set whether the given user id is allowed to write this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltba9sampleuser41' is a uid of an object of inbuilt Application User class
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setWriteAccess:YES forUserId:@"bltba9sampleuser41"]

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setWriteAccess(true, forUserId:"bltba9sampleuser41")
 
 @param allowed Whether write access is allowed (YES/true or NO/false).
 @param userId The user id to assign access.
 */
- (void)setWriteAccess:(BOOL)allowed forUserId:(NSString *)userId;


/**
 Gets whether the given user id is explicitly allowed to write this object.
 Even if this returns NO, the user may still be able to access it if getPublicWriteAccess returns YES
 or if the user belongs to a role that has access.
 

    //'blt5d4sample2633b' is a dummy Application API key
    //'bltba9sampleuser41' is a uid of an object of inbuilt Application User class

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getWriteAccessForUserId:@"bltba9sampleuser41"]) {
        //Write access for this user
    } else {
        //No write access
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getWriteAccessForUserId("bltba9sampleuser41")) {
        //Write access for this user
    } else {
        //No write access
    }
 
 @param userId User ID for which to check write access.
 @return Returns YES if write access is granted to others. NO otherwise.
 */
- (BOOL)getWriteAccessForUserId:(NSString *)userId;


/**
 Set whether the given user id is allowed to delete this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltba9sampleuser41' is a uid of an object of inbuilt Application User class
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setDeleteAccess:YES forUserId:@"bltba9sampleuser41"];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setDeleteAccess(true , forUserId:"bltba9sampleuser41")
 
 @param allowed Whether delete access is allowed (YES/true or NO/false).
 @param userId The user id to assign access.
 */
- (void)setDeleteAccess:(BOOL)allowed forUserId:(NSString *)userId;


/**
 Gets whether the given user id is explicitly allowed to delete this object.
 Even if this returns NO, the user may still be able to access it if getPublicDeleteAccess returns YES
 or if the user belongs to a role that has access.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltba9sampleuser41' is a uid of an object of inbuilt Application User class

 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getDeleteAccessForUserId:@"bltba9sampleuser41"]) {
        //Delete access allow for this user
    } else {
        //Delete not allow
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getDeleteAccessForUserId("bltba9sampleuser41")) {
        //Delete access allow for this user");
    } else {
        //Delete not allow
    }
 
 @param userId User ID for which to check delete access.
 @return Returns YES if delete access is granted to others. NO otherwise.
 */
- (BOOL)getDeleteAccessForUserId:(NSString *)userId;

/**---------------------------------------------------------------------------------------
 * @name Controlling Role Access
 *  ---------------------------------------------------------------------------------------
 */
/**
 Gets whether the users with given role are explicitly allowed to read this object.
 Even if this returns NO, the user may still be able to access it if getPublicReadAccess returns YES
 or if the user belongs to a role that has access.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltbg2samplerole84' is a uid of an object of inbuilt Application User class

 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getRoleReadAccess:@"bltbg2samplerole84"]) {
        //Role read allow
    } else {
        //Role read not allow
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getRoleReadAccess("bltbg2samplerole84")) {
        //Role read allow
    } else {
        //Role read not allow
    }
 
 @param role_uid Role UID for which to check read access.
 @return Returns YES if read access is granted to users with role. NO otherwise.
 */
- (BOOL)getRoleReadAccess:(NSString *)role_uid;


/**
 Gets whether the users with given role are explicitly allowed to write this object.
 Even if this returns NO, the user may still be able to access it if getPublicWriteAccess returns YES
 or if the user belongs to a role that has access.
 
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltbg2samplerole84' is a uid of an object of inbuilt Application User class

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getRoleWriteAccess:@"bltbg2samplerole84"]) {
        //Role write allow
    } else {
        //Role write not allow
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getRoleWriteAccess("bltbg2samplerole84")) {
        //Role write allow
    } else {
        //Role write not allow
    }
 
 @param role_uid Role UID for which to check write access.
 @return Returns YES if write access is granted to users with role. NO otherwise.
 */
- (BOOL)getRoleWriteAccess:(NSString *)role_uid;


/**
 Gets whether the users with given role are explicitly allowed to delete this object.
 Even if this returns NO, the user may still be able to access it if getPublicDeleteAccess returns YES
 or if the user belongs to a role that has access.
 

    //'blt5d4sample2633b' is a dummy Application API key
    //'bltbg2samplerole84' is a uid of an object of inbuilt Application User class

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    if ([aclObject getRoleDeleteAccess:@"bltbg2samplerole84"]) {
        // Role delete allow
    } else {
        // Role delete not allow
    }

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    if (aclObject.getRoleDeleteAccess("bltbg2samplerole84")) {
        // Role delete allow
    } else {
        // Role delete not allow
    }
 
 @param role_uid Role UID for which to check delete access.
 @return Returns YES if delete access is granted to users with role. NO otherwise.
 */
- (BOOL)getRoleDeleteAccess:(NSString *)role_uid;


/**
 Set whether the given users with role_uid are allowed to delete this object.
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'bltbg2samplerole84' is a uid of an object of inbuilt Application User class

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setRoleReadAccess:YES forRoleUID:@"bltbg2samplerole84"];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setRoleReadAccess(true, forRoleUID:"bltbg2samplerole84")
 
 @param allowed Whether read access is allowed (YES/true or NO/false).
 @param role_uid The role uid to assign access.
 */
- (void)setRoleReadAccess:(BOOL)allowed forRoleUID:(NSString *)role_uid;


/**
 Set whether the given users with role_uid are allowed to write this object.

    //'blt5d4sample2633b' is a dummy Application API key
    //'bltbg2samplerole84' is a uid of an object of inbuilt Application User class
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject  setRoleWriteAccess:YES forRoleUID:@"bltbg2samplerole84"];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setRoleWriteAccess(true, forRoleUID:"bltbg2samplerole84")
 
 @param allowed Whether write access is allowed (YES/true or NO/false).
 @param role_uid The role uid to assign access.
 */
- (void)setRoleWriteAccess:(BOOL)allowed forRoleUID:(NSString *)role_uid;

/**
 Set whether the given users with role_uid are allowed to delete this object.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'bltbg2samplerole84' is a uid of an object of inbuilt Application User class
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltACL *aclObject = [builtApplication acl];
    [aclObject setRoleDeleteAccess:YES forRoleUID:@"bltbg2samplerole84"];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var aclObject:BuiltACL = builtApplication.acl()
    aclObject.setRoleDeleteAccess(true, forRoleUID:"bltbg2samplerole84")
 
 @param allowed Whether delete access is allowed (YES/true or NO/false).
 @param role_uid The role uid to assign access.
 */
- (void)setRoleDeleteAccess:(BOOL)allowed forRoleUID:(NSString *)role_uid;

/**---------------------------------------------------------------------------------------
 * @name Controlling Anonymous Access
 *  ---------------------------------------------------------------------------------------
 */

/**
 Set whether the anonymous users is allowed to read this object.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     [aclObject setAnonymousReadAccess:YES];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     aclObject.setAnonymousReadAccess(true)
 
 @param allowed Whether read access is allowed (YES/true or NO/false).
 */
-(void)setAnonymousReadAccess:(BOOL)allowed;

/**
 Gets whether the anonymous users is allowed to read this object.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     if ([aclObject getPublicReadAccess]) {
        // ACL public read access
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     if (aclObject.getPublicReadAccess()) {
        // ACL public read access
     }
 
 @return Returns true if read access is granted to others. false otherwise.
 */
-(BOOL)getAnonymousReadAccess;

/**
 Set whether the anonymous users is allowed to write this object.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     [aclObject setAnonymousWriteAccess:YES];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     aclObject.setAnonymousWriteAccess(true)
 
 @param allowed Whether write access is allowed (YES/true or NO/false).
 */
-(void)setAnonymousWriteAccess:(BOOL)allowed;

/**
 Gets whether the anonymous users is allowed to write this object.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     if ([aclObject getAnonymousWriteAccess]) {
        // ACL anonymous write access
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     if (aclObject.getAnonymousWriteAccess()) {
        // ACL anonymous write access
     }
 
 @return Returns true if write access is granted to others. false otherwise.
 */
-(BOOL)getAnonymousWriteAccess;

/**
 Set whether the anonymous users is allowed to delete this object.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     [aclObject setAnonymousDeleteAccess:YES];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     aclObject.setAnonymousDeleteAccess(true)
 
 @param allowed Whether delete access is allowed (YES/true or NO/false).
 */
-(void)setAnonymousDeleteAccess:(BOOL)allowed;

/**
 Gets whether the anonymous users is allowed to delete this object.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *aclObject = [builtApplication acl];
     if ([aclObject getAnonymousDeleteAccess]) {
        // ACL anonymous delete access
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var aclObject:BuiltACL = builtApplication.acl()
     if (aclObject.getAnonymousDeleteAccess()) {
        // ACL anonymous delete access
     }
 
 @return Returns true if delete access is granted to others. false otherwise.
 */
-(BOOL)getAnonymousDeleteAccess;

@end

BUILT_ASSUME_NONNULL_END