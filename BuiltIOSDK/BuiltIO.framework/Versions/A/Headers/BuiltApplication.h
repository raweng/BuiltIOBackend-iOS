//
//  BuiltApplication.h
//  BuiltIO
//
//  Created by Gautam Lodhiya on 25/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@class BuiltClass;
@class BuiltAnalytics;
@class BuiltExtension;
@class BuiltInstallation;
@class BuiltNotification;
@class BuiltRole;
@class BuiltUser;
@class BuiltUpload;
@class BuiltQuery;
@class BuiltACL;
@class BuiltSynchronousResponse;

/**
 *  Represents an Application
 */
@interface BuiltApplication : NSObject

/**
 Returns the api-key of application
 
 @warning This property is readonly i.e you can just read the value but can't set its value
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    NSString *apiKeyString = builtApplication.apiKey;
     
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var apiKeyString:NSString = builtApplication.apiKey
 
 */
@property (nonatomic, copy, readonly) NSString *apiKey;

/**
 Returns the account name of application
 
 @warning This property is readonly i.e you can just read the value but can't set its value
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     NSString *accountNameString = builtApplication.accountName;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var accountNameString:NSString = builtApplication.accountName
 
 */
@property (nonatomic, copy, readonly) NSString *accountName;

/**
 Returns the name of application
 
 @warning This property is readonly i.e you can just read the value but can't set its value
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    NSString *applicationNameString = builtApplication.applicationName;
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var applicationNameString:NSString = builtApplication.applicationName

 */
@property (nonatomic, copy, readonly) NSString *applicationName;

/**
 Returns the current built user [User Session]
 
 @warning This property is readonly i.e you can just read the value but can't set its value
 
    //'blt5d4sample2633b' is a dummy Application API key

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltUser *currentLoggedInUser = builtApplication.currentUser;

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var currentLoggedInUser:BuiltUser = builtApplication.currentUser
 
 */
@property (nonatomic, strong, readonly) BuiltUser *currentUser;

/**
 Returns the current installation object that is saved on the disk.
 
 @warning This property is readonly i.e you can just read the value but can't set its value

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *savedInstallationObject = builtApplication.currentInstallation;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var savedInstallationObject:BuiltInstallation = builtApplication.currentInstallation
 
 */
@property (nonatomic, strong, readonly) BuiltInstallation *currentInstallation;

/**
 Cache Policy for application
 
 A set of cache policies are avaliable for use which are listed below.
 
 ONLY_NETWORK (Default)
 This is the default cache policy which will always get the data from an network call.
 
 CACHE_ONLY
 This policy which will always get the data from an cache.
 
 CACHE_ELSE_NETWORK
 This policy will try to first get the data from cache, on failure would make a network call.
 
 NETWORK_ELSE_CACHE
 It will try to make a network call, on failure would fetch it from cache.
 
 CACHE_THEN_NETWORK
 This policy would first get the data from cache as well would make a network call to get the updated copy.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
 
     //Setting CachePolicy
     builtApplication.cachePolicy = NETWORK_ONLY;
     
     //Getting CachePolicy
     builtApplication.cachePolicy;
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")

     //Setting CachePolicy
     builtApplication.cachePolicy = CachePolicy.NETWORK_ONLY
 
     //Getting CachePolicy
     builtApplication.cachePolicy
 
 
 */
@property (nonatomic, assign) CachePolicy cachePolicy;

/**
 Returns the URL in which application is created.
 
 @warning This property is readonly i.e you can just read the value but can't set its value
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     NSString *apiURLString = builtApplication.url;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var apiURLString:NSString = builtApplication.url
 
 */
@property (nonatomic, copy, readonly) NSString *url;

/**
 Get/Set the version of Built.io Backend which is used in the final URL.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     builtApplication.version = @"v2";
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.version = "v2"
 
 */
@property (nonatomic, copy) NSString *version;


/**
 *  If FALSE then loggedin user id will be attached with the event for user base analytics if set TRUE user info is not been tracked by analytics. By default its FALSE. Value is passsed to BuiltAnalytics's trackAnonymously property when analytics instance is created.
 
 
     // 'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     if ([builtApplication isAnonymousTrackingEnabled]) {
        builtApplication.trackAnonymously = YES;
     } else {
        builtApplication.trackAnonymously = NO;
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     if (builtApplication.isAnonymousTrackingEnabled) {
        // Anonymously tracking events
     } else {
        // User based tracking
     }
 
 */
@property (nonatomic, assign, getter=isAnonymousTrackingEnabled) BOOL trackAnonymously;


//MARK: - Initialization

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

//MARK: - Headers
/**
 
 Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication setHeader:@"MyValue" forKey:@"My-Custom-Header"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.setHeader("MyValue", forKey: "My-Custom-Header")
 
 @param headerValue  The header key
 @param headerKey    The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
 Set a header for an application
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication addHeadersWithDictionary:@{@"My-Custom-Header": @"MyValue"}];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.addHeadersWithDictionary(["My-Custom-Header":"MyValue"])
 
 
 @param headers  The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
 Removes a header from this application.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication removeHeaderForKey:@"My-Custom-Header"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.removeHeaderForKey("My-Custom-Header")
 
 @param headerKey    The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;

///**
// *  Sets authentication token in app header
// *  @param token    The user's token that needs to be set
// */
//- (void)setAuthToken:(NSString *)token;
//
///**
// *  Removes a header from this application
// */
//- (void)removeAuthToken;

/**
 Sets the current tenant for this application
 
    //'blt5d4sample2633b' is a dummy Application API key
    //'xyz' is bummy tenant name

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication setTenant:@"xyz"];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.setTenant("xyz")
 
 
 @param tenantUID    The tenant uid value
 */
- (void)setTenant:(NSString *)tenantUID;

/**
 Removes the tenant from application

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication removeTenant];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.removeTenant()
 
 */
- (void)removeTenant;

//MARK: - Helper methods

/**
 Represents a class in this application
 
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
 
 @param classUID The uid of class
 @return Returns an instance of Class
 */
- (BuiltClass *)classWithUID:(NSString *)classUID;

/**
 Represents a analytics in this application.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltAnalytics *analytics = [builtApplication analytics];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var analytics:BuiltAnalytics = builtApplication.analytics()
 
 
 @return Returns an instance of a BuiltAnalytics.
 */
- (BuiltAnalytics*)analytics;

/**
 Represents extension in this application
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltExtension *extensionObject = [builtApplication extensionWithName:@"hello"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var extensionObject:BuiltExtension = builtApplication.extensionWithName("hello")
 
 @param extensionName name of extension
 @return Returns an instance of a BuiltExtension.
 */
- (BuiltExtension *)extensionWithName:(NSString*)extensionName;

/**
Class for creating new installation and for subscribing/unsubscribing for push notifications against a channel.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
 
 
@return Returns an instance of BuiltInstallation.
 */
- (BuiltInstallation *)installation;

/**
Class for updating installation and for subscribing/unsubscribing for push notifications against a channel.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installationWithUID:@"install_uid"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installationWithUID("install_uid")
 
 
@param installationUID uid of installation needed.
@return Returns an instance of BuiltInstallation.
 */
- (BuiltInstallation *)installationWithUID:(NSString*)installationUID;

/**
Class for creating a notification for this application.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notification = [builtApplication notification];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notification:BuiltNotification = builtApplication.notification()
 
 
@return Returns an instance of BuiltNotification.
 */
- (BuiltNotification *)notification;

/**
Represents a new role with speficied name to create on Built.io Backend.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *managerRole = [builtApplication roleWithName:"Managers"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var managerRole:BuiltRole = builtApplication.roleWithName("Managers")
 
 
@param roleName name of the role to create.
@return Returns an instance of BuiltRole.
 */
- (BuiltRole *)roleWithName:(NSString*)roleName;

/**
Represents a role on Built.io Backend
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'blt9a1sample5476j' is a dummy role UID
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltRole *builtRole = [builtApplication roleWithUID:@"blt9a1sample5476j"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var builtRole:BuiltRole = builtApplication.roleWithUID("blt9a1sample5476j")
 
@param roleUID uid if role which is needed.
@return Returns an instance of BuiltRole.
 */
- (BuiltRole *)roleWithUID:(NSString*)roleUID;

/**
Represents a new user of this application
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *person = [builtApplication user];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var person:BuiltUser = builtApplication.user()
 
@return Returns an instance of BuiltUser.
 */
- (BuiltUser *)user;

/**
Represents a user of this application
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'bltba9a44506dd9e741' is a uid of an object of inbuilt Application User class
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *person = [builtApplication userWithUID:@"bltba9a44506dd9e741"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var person:BuiltUser = builtApplication.userWithUID("bltba9a44506dd9e741")
 
 
@param userUID uid of user needed.
@return Returns an instance of BuiltUser.
 */
- (BuiltUser *)userWithUID:(NSString*)userUID;

/**
Represents a new file to-upload on Built.io Backend
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
 
@return Returns an instance of BuiltUpload.
 */
- (BuiltUpload *)upload;

/**
Represents a file uploaded on Built.io Backend
 
     //'blt5d4sample2633b' is a dummy Application API key
     //'blt111sample2655c' is a uid of an upload
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication uploadWithUID:@"blt111sample2655c"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.uploadWithUID("blt111sample2655c")
 
 
@param uploadUID uid of file.
@return Returns an instance of BuiltUpload.
 */
- (BuiltUpload *)uploadWithUID:(NSString*)uploadUID;

/**
Provides BuiltQuery object.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltQuery *userQuery = [builtApplication userQuery];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var userQuery:BuiltQuery = builtApplication.userQuery()
 
@return Query object for user class
 */
- (BuiltQuery *)userQuery;

/**
Provides BuiltQuery object.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltQuery *userRoleQuery = [builtApplication userRoleQuery];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var userRoleQuery:BuiltQuery = builtApplication.userRoleQuery()
 
@return Query object for Role class
 */
- (BuiltQuery *)userRoleQuery;

/**
Returns new ACL object with empty setting
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltACL *acl = [builtApplication acl];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var acl:BuiltACL = builtApplication.acl()
 
@return new BuiltACL object
 */
- (BuiltACL *)acl;

//MARK: - Instance methods

/**
Gets the application variables.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication variableForKey:@"key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.variableForKey("key")
 
 
@param key application variable key of which value needed.
@return value of the specified key
 */
- (NSString *)variableForKey:(NSString *)key;

/**
Synchronously fetches the application info.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     NSError *error;
     BuiltSynchronousResponse *builtSyncResponse = [builtApplication fetchApplicationInfo:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = builtApplication.fetchApplicationInfo(error)
 
 
@param error Pointer to an NSError that will be set if necessary
@return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data holding NSDictionary of the application info.
 */
- (BuiltSynchronousResponse *)fetchApplicationInfo:(NSError **)error;

/**
Asynchronously fetches the application info.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication fetchApplicationInfoInBackgroundWithCompletion:^(ResponseType responseType, NSDictionary *info, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.fetchApplicationInfoInBackgroundWithCompletion { (ResponseType, [NSObject : AnyObject]!, NSError!) -> Void in
     
     }
 
 
@param successBlock invoked when request processed sucessfully.
@param errorBlock   invoked when request process fails. error parameter contains the error info.
@param finallyBlock invoked when request is finished. Will get invoked after sucess or failure.
 */
- (void)fetchApplicationInfoInBackgroundWithCompletion:(void (^)(ResponseType responseType, NSDictionary *info, NSError *error))completionBlock;

/**
Synchronously fetches last activity of all classes of application.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     NSError *error;
     BuiltSynchronousResponse *builtSyncResponse = [builtApplication fetchLastActivityOfClasses:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = builtApplication.fetchLastActivityOfClasses(error)
 
 
@param error Pointer to an NSError that will be set if necessary.
@return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data holding NSDictionary with list of class uid as key and its respective last updated time.
 */
- (BuiltSynchronousResponse *)fetchLastActivityOfClasses:(NSError **)error;

/**
Asynchronously fetches last activity of all classes of application.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication fetchLastActivityOfClassesInBackgroundWithCompletion:^(ResponseType responseType, NSDictionary *lastActivityDictionary, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.fetchLastActivityOfClassesInBackgroundWithCompletion { (ResponseType, [NSObject : AnyObject]!, NSError!) -> Void in
     
     }
 
 
@param completionBlock invoked when request is finished. lastActivityDictionary in block will contain list of class uid as key and its respective last updated time.
 */
- (void)fetchLastActivityOfClassesInBackgroundWithCompletion:(void (^)(ResponseType responseType, NSDictionary *lastActivityDictionary, NSError *error))completionBlock;

/**
Gets the schema of all class in application synchronously
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     NSError *error;
     BuiltSynchronousResponse *builtSyncResponse = [builtApplication fetchClassesSchema:error];
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var error:NSError
     var builtSyncResponse:BuiltSynchronousResponse = builtApplication.fetchClassesSchema(error)

@param error Pointer to an NSError that will be set if necessary.
@return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data holding NSArray of schema info.
 */
- (BuiltSynchronousResponse *)fetchClassesSchema:(NSError **)error;

/**
Gets the schema of all class in application asynchronously
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication fetchClassesSchemaInBackgroundWithCompletion:^(ResponseType responseType, NSArray *schema, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.fetchClassesSchemaInBackgroundWithCompletion { (responseType, schema, error) -> Void in
     
     }
 
@param completionBlock Completion block with params responseType (cache or network), array of schemas and error object in any.
 */
- (void)fetchClassesSchemaInBackgroundWithCompletion:(void (^)(ResponseType responseType, NSArray *schema, NSError *error))completionBlock;

/**
 @abstract Advises the operation object that it should stop executing its task.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     [builtApplication cancelRequests];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     builtApplication.cancelRequests()
 
 @discussion This method does not force your operation code to stop. Instead, it updates the object’s internal flags to reflect the change in state. If the operation has already finished executing, this method has no effect. Canceling an operation that is currently in an operation queue, but not yet executing, makes it possible to remove the operation from the queue sooner than usual.
 */
- (void)cancelRequests;

//MARK: Deprecated API

/**
 Changes the host config
 
 @param hostname Built.io Backend hostname
 @param ssl The protocol to be used (http/https) in terms of boolean
 @deprecated Please use Built's applicationWithAPIKey:hostName:isSSL: instead.
 */
- (void)setHostname:(NSString *)hostname isSSL:(BOOL)ssl BUILTIO_DEPRECATED("Please use Built's applicationWithAPIKey:hostName:isSSL: instead.");

@end
