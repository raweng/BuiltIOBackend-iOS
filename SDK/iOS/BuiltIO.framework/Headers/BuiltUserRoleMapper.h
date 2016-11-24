//
//  BuiltUserRoleMapper.h
//  BuiltIO
//
//  Created by Priyanka Mistry on 27/10/16.
//  Copyright © 2016 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN
@class BuiltRole;
@class BuiltUser;
@class BuiltACL;

@interface BuiltUserRoleMapper : NSObject

/**
 The uid of the object
 
 //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSString *objectUID = mapperObject.uid;
 
     //Swift
     var objectUID:String = mapperObject.uid
 
 */
@property (nullable, nonatomic, copy) NSString *uid;

/**
 The roleUid of the object
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSString *objectUID = mapperObject.roleUid;
 
     //Swift
     var objectUID:String = mapperObject.roleUid
 
 */
@property (nonatomic, copy) NSString *roleUid;

/**
 The role object for role_uid (When object is fetched using includeReference of role uid it returns role object)
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     BuiltRole *roleObj = mapperObject.role;
 
     //Swift
     var roleObj:BuiltRole = mapperObject.role
 
 */
@property (nonatomic, strong) BuiltRole *mapperRole;

/**
 The userUid of the object
 
    //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSString *objectUID = mapperObject.userUid;
 
     //Swift
     var objectUID:String = mapperObject.userUid
 
 */
@property (nonatomic, strong) NSString *userUid;

/**
 The user object for user_uid (When object is fetched using includeReference of user uid it returns user object)
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     BuiltUser *userObj = mapperObject.user;
 
     //Swift
     var userObj:BuiltUser = mapperObject.user
 
 */
@property (nonatomic, strong) BuiltUser *mapperUser;

/**
 ACL for the object
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     BuiltACL *builtAcl = mapperObject.ACL;
 
     //Swift
     var builtAcl:BuiltACL = mapperObject.ACL
 
 */
@property (nonatomic, strong) BuiltACL *ACL;
/**
 Check if the object is deleted or not [Gets used in delta calls].
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     if (mapperObject.isDeleted) {
     //object is deleted
     } else {
     //object is not yet delete
     }
 
     //Swift
     if (mapperObject.isDeleted()) {
     //object is deleted
     } else {
     //object is not yet delete
     }
 
 */
@property (nonatomic, assign, readonly, getter=isDeleted) BOOL deleted;

/**
 Created date of object.
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSDate *objectCreatedDate = mapperObject.createdAt;
 
     //Swift
     var objectCreatedDate:Date = mapperObject.createdAt
 
 
 */
@property (nonatomic, readonly) NSDate *createdAt;

/**
 Last updated date of object.
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSDate *objectUpdatedDate = mapperObject.updatedAt;
 
     //Swift
     var objectUpdatedDate:Date = mapperObject.updatedAt
 
 */
@property (nonatomic, readonly) NSDate *updatedAt;

/**
 Deleted date of object.
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSDate *objectDeletedDate = mapperObject.deletedAt;
 
     //Swift
     var objectDeletedDate:Date = mapperObject.deletedAt
 
 
 */
@property (nonatomic, readonly) NSDate *deletedAt;

/**
 Gets the data for given property.
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     id object = [mapperObject objectForKey:@"key"];
 
     //Swift
     var object = mapperObject.objectForKey("key")
 
 
 @param key The object's property
 @return The value for the key provided
 */
- (BUILT_NULLABLE id)objectForKey:(NSString *)key;

//MARK: - object owner
/**---------------------------------------------------------------------------------------
 * @name Owner
 *  ---------------------------------------------------------------------------------------
 */

/**
 Check if object has owner
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     if (mapperObject.hasOwner) {
     //Object has a owner
     } else {
     //Object has no owner
     }
 

     //Swift
     if (mapperObject.hasOwner()) {
     //Object has a owner
     } else {
     //Object has no owner
     }
 
 @return YES if object has owner else NO
 */
- (BOOL)hasOwner;

/**
 Returns owner if the object has owner
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     id objectOwner = [mapperObject owner];
 
     //Swift
     var owner:AnyObject = mapperObject.owner()
 
 
 @return Owner of the object
 */
- (BUILT_NULLABLE id)owner;

/**
 Get the UID of the owner of the object
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSString *objectOwnerUID = [mapperObject ownerUID];
 
     //Swift
     var objectOwnerUID:String = mapperObject.ownerUID()
 
 
 @return UID of the owner
 */
- (BUILT_NULLABLE NSString *)ownerUID;

/**
 Get the email of the owner of the object
 
     //Assuming 'mapperObject' is a BuiltUserRoleMapper instance
 
     //Obj-C
     NSString *objectOwnerEmail = [mapperObject ownerEmail];
 
     //Swift
     var objectOwnerEmail:String = mapperObject.ownerEmail()
 
 @return email of the owner of the object
 */
- (BUILT_NULLABLE NSString *)ownerEmail;

//MARK: - Object fetch
/**---------------------------------------------------------------------------------------
 * @name Object fetch
 *  ---------------------------------------------------------------------------------------
 */

/**
 Fetches an object asynchronously provided object UID
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapperObject  = [builtApplication userRoleMapperWithUID:@"bltf50esamplefeb"];
     [mapperObject  fetch:^(BuiltResponseType responseType, NSError *error) {
 
     }];
 
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var mapperObject:BuiltUserRoleMapper = builtApplication.userRoleMapperWithUID("bltf50esamplefeb")
     mapperObject.fetch { (responseType, error!) -> Void in
 
 }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
 */
-(void)fetch:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Object save
/**---------------------------------------------------------------------------------------
 * @name Save
 *  ---------------------------------------------------------------------------------------
 */

/**
 Saves an mapper object as draft asyncronously so that it is not visible unless explicitly called for. see [including drafts]([BuiltQuery includeDrafts])
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapper = [builtApplication userRoleMapper];
     mapper.roleUid = @"blt5d4sample2634567j";
     mapper.userUid = @"blt345hsamplehg567u";
     [mapper saveAsDraft:^(BuiltResponseType responseType, NSError *error) {
 
     }];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var mapper:BuiltUserRoleMapper = builtApplication.userRoleMapper()
     mapper.roleUid = "blt5d4sample2634567j"
     mapper.userUid = "blt345hsamplehg567u"
     mapper.saveAsDraft { (responseType, error!) -> Void in
 
 }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
 */
- (void)saveAsDraft:(BuiltRequestCompletionHandler)completionBlock;

/**
 Saves an BuiltUserRoleMapper asyncronously to Built.io Backend servers
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapper = [builtApplication userRoleMapper];
     mapper.roleUid = @"blt5d4sample2634567j";
     mapper.userUid = @"blt345hsamplehg567u";
     [mapper save:^(BuiltResponseType responseType, NSError *error) {
 
 }];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var mapper:BuiltUserRoleMapper = builtApplication.userRoleMapper()
     mapper.roleUid = "blt5d4sample2634567j"
     mapper.userUid = "blt345hsamplehg567u"
     mapper.save { (responseType, error!) -> Void in
 
 }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
*/
- (void)save:(BuiltRequestCompletionHandler)completionBlock;

/**
 Saves a mapper object as draft asyncronously so that it is not visible unless explicitly called for. see [including drafts]([BuiltQuery includeDrafts])
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapper = [builtApplication userRoleMapper];
     mapper.roleUid = @"blt5d4sample2634567j";
     mapper.userUid = @"blt345hsamplehg567u";
     [mapper saveAsDraftEventually:^(BuiltResponseType responseType, NSError *error) {
 
    }];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var mapper:BuiltUserRoleMapper = builtApplication.userRoleMapper()
     mapper.roleUid = "blt5d4sample2634567j"
     mapper.userUid = "blt345hsamplehg567u"
     mapper.saveAsDraftEventually { (responseType, error!) -> Void in
 
    }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
 */
- (void)saveAsDraftEventually:(BuiltRequestCompletionHandler)completionBlock;

/**
 Saves BuiltUserRoleMapper asyncronously if network is unavailable. Resumes when network becomes available.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapper = [builtApplication userRoleMapper];
     mapper.roleUid = @"blt5d4sample2634567j";
     mapper.userUid = @"blt345hsamplehg567u";
     [mapper saveEventually:^(BuiltResponseType responseType, NSError *error) {
 
     }];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var mapper:BuiltUserRoleMapper = builtApplication.userRoleMapper()
     mapper.roleUid = "blt5d4sample2634567j"
     mapper.userUid = "blt345hsamplehg567u"
     mapper.saveEventually { (responseType, error!) -> Void in
 
     }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
 */
- (void)saveEventually:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Object delete
/**---------------------------------------------------------------------------------------
 * @name Delete
 *  ---------------------------------------------------------------------------------------
 */
/**
 Delete the BuiltUserRoleMapper asyncronously with specified object UID.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapperObject  = [builtApplication userRoleMapperWithUID:@"bltf50esamplefeb"];
     [mapperObject  destroy:^(BuiltResponseType responseType, NSError *error) {
 
     }];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var mapperObject:BuiltUserRoleMapper = builtApplication.userRoleMapperWithUID("bltf50esamplefeb")
     mapperObject.destroy { (responseType, error!) -> Void in
 
      }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
 */
- (void)destroy:(BuiltRequestCompletionHandler)completionBlock;

/**
 Delete the BuiltUserRoleMapper asyncronously with specified object UID. Drafts the operation if network is unavailable. Resumes after network is back.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapperObject  = [builtApplication userRoleMapperWithUID:@"bltf50esamplefeb"];
     [mapperObject  destroyEventually:^(BuiltResponseType responseType, NSError *error) {
 
     }];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var mapperObject:BuiltUserRoleMapper = builtApplication.userRoleMapperWithUID("bltf50esamplefeb")
     mapperObject.destroyEventually { (responseType, error!) -> Void in
 
     }

 @param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)destroyEventually:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Reference
/**---------------------------------------------------------------------------------------
 * @name Include Reference
 *  ---------------------------------------------------------------------------------------
 */

/**
 Include reference objects with given key in response
 
     //Obj-C
     [mapperObject includeReference:@[@"role_uid"]];
 
     //Swift
     mapperObject.includeReference(["role_uid"])
 
 @discussion The include parameter accepts the name of a reference field. By default, no reference field is bought along with the object, only the uids are. To include any reference, this parameter must be used. Nested references can be bought by "." separating the references. This will work for references which are nested inside groups or references which are nested inside other references.
 @param key Array of reference keys to include in response.
 */
- (void)includeReference:(NSArray *)key;

/**
 Specifies an array of 'only' keys in reference class object that would be included in the response.
 
     //Obj-C
     [mapperObject includeReference:@[@"role_uid"] onlyFields:@[@"role_uid"]];
 
     //Swift
     mapperObject.includeReference(["role_uid"], onlyFields:["role_uid"])
 
 @discussion Specifies an array of keys in reference class object that would be included in the response.
 @param key Key who has reference to some other class object.
 @param fieldUIDs Array of the 'only' reference keys to be included in response.
 */
- (void)includeReference:(NSString *)key onlyFields:(NSArray *)fieldUIDs;

/**
 Specifies an array of keys in reference class object that would be 'excluded' from the response.
 
     //Obj-C
     [mapperObject includeReference:@[@"role_uid"] excludingFields:@[@"user_uid"]];
 
     //Swift
     mapperObject.includeReference(["role_uid"], excludingFields:["user_uid"])
 
 @discussion Specifies an array of keys in reference class object that would be 'excluded' from the response.
 @param key Key who has reference to some other class object.
 @param fieldUIDs Array of the 'only' reference keys to be 'excluded' from the response.
 */
- (void)includeReference:(NSString *)key excludingFields:(NSArray *)fieldUIDs;

//MARK: - Additional Options
/**---------------------------------------------------------------------------------------
 * @name Additional Options
 *  ---------------------------------------------------------------------------------------
 */

/**
 Include the owner’s profile in the objects' data.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUserRoleMapper *mapperObject  = [builtApplication userRoleMapperWithUID:@"bltf50esamplefeb"];
     [mapperObject includeOwner];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     BuiltUserRoleMapper *mapperObject  = [builtApplication userRoleMapperWithUID:@"bltf50esamplefeb"];
     mapperObject.includeOwner()
 
 @discussion The returned objects will also contain a key “_owner”, which will include the owner’s profile in the object’s data.
 */
- (void)includeOwner;

/**---------------------------------------------------------------------------------------
 * @name Configure
 *  ---------------------------------------------------------------------------------------
 */

/**
 Configure user properties with mapper object info.
 
     //Obj-C
     [mapperObject configureWithDictionary:@{@"role_uid":@"MyValue"}];
 
     //Swift
     mapperObject.configureWithDictionary(["role_uid":"MyValue"])
 
 @param dictionary User Info
 */
- (void)configureWithDictionary:(NSDictionary *)dictionary;

/**---------------------------------------------------------------------------------------
 * @name Cancel Network calls
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Advises the operation object that it should stop executing its task.
 
     //Obj-C
     [mapperObject cancelRequests];
 
     //Swift
     mapperObject.cancelRequests()
 
 
 @discussion This method does not force your operation code to stop. Instead, it updates the object’s internal flags to reflect the change in state. If the operation has already finished executing, this method has no effect. Canceling an operation that is currently in an operation queue, but not yet executing, makes it possible to remove the operation from the queue sooner than usual.
 */
- (void)cancelRequests;


@end

BUILT_ASSUME_NONNULL_END
