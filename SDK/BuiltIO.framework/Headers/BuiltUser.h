
//
//  BuiltUser.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"
#import "BuiltObject.h"

@class BuiltACL, ACAccount, BuiltQuery, BuiltLocation, BuiltSynchronousResponse;

@interface BuiltUser : BuiltObject

//MARK: - Properties
/**
 @abstract The username for BuiltUser
 
     //Obj-C

     //getter
     NSString *userName = userObject.username;
     //setter
     userObject.username = @"johnjoseph";
     
     //Swift
     /getter
     var userName:String = userObject.username
     //setter
     userObject.username = "johnjoseph"
 
 
 @discussion The username for BuiltUser
 */
@property(nonatomic, copy) NSString *username;


/**
 @abstract The email for BuiltUser
 
     //Obj-C
     //getter
     NSString *userEmail = userObject.email;
     //setter
     userObject.email = @"test@email.com";
 
     //Swift
     //getter
     var userEmail:String = userObject.email
     //setter
     userObject.email = "test@email.com"
 
 
 @discussion The email for BuiltUser
 */
@property(nonatomic, copy) NSString *email;


/**
 @abstract The firstname for BuiltUser
 
     //Obj-C
     
     //getter
     NSString *firstName = userObject.firstName;
     //setter
     userObject.firstName = @"John";
     
     //Swift
     
     //getter
     var firstName:String = userObject.firstName
     //setter
     userObject.firstName = "John"
 
 @discussion The firstname for BuiltUser
 */
@property(nonatomic, copy) NSString *firstName;


/**
 @abstract The lastName for BuiltUser
 
     //Obj-C
 
     //getter
     NSString *lastName = userObject.lastName;
     //setter
     userObject.lastName = @"Joseph";
     
     //Swift
 
     //getter
     var lastName:String = userObject.lastName
     //setter
     userObject.lastName = "Joseph"

 
 
 @discussion The lastName for BuiltUser
 */
@property(nonatomic, copy) NSString *lastName;


/**
 @abstract The password for BuiltUser
 
     //Obj-C
     userObject.password = @"password";
     
     //Swift
     userObject.password = "password"
 
 
 @discussion The password for BuiltUser
 */
@property(nonatomic, copy) NSString *password;


/**
 @abstract Password confirmation
 
     //Obj-C
     userObject.confirmPassword = @"password";
     
     //Swift
     userObject.confirmPassword = "password"
 
 
 @discussion Password confirmation to confirm that you are real you, not a bot.
 */
@property(nonatomic, copy) NSString *confirmPassword;


/**
 @abstract The authtoken after logging in
 
     //Obj-C
     NSString *authToken = userObject.authtoken;
     
     //Swift
     var authToken:String = userObject.authtoken
 
 
 @discussion The authtoken after logging in
 */
@property (nonatomic, copy, readonly) NSString *authtoken;


/**
 @abstract the old password of the user
 
     //Obj-C
     userObject.oldPassword = @"password";
     
     //Swift
     userObject.oldPassword = "password"
 
 
 @discussion the old password of the user to be provided in case user wants to update his/her password.
 */
@property (nonatomic, copy) NSString *oldPassword;

//MARK: - Access tokens
/**
OAuth token from twitter used to log a user into your application
 
     //Obj-C
     NSString *twitterToken = twitterUser.twitterToken;
     
     //Swift
     var twitterToken:String = twitterUser.twitterToken
 
 */
@property (nonatomic, copy, readonly) NSString *twitterToken;

/**
OAuth token secret from twitter used to log a user into your application
 
     //Obj-C
     NSString *twitterTokenSecret = twitterUser.twitterTokenSecret;
     
     //Swift
     var twitterTokenSecret:String = twitterUser.twitterTokenSecret
 
 
 */
@property (nonatomic, copy, readonly) NSString *twitterTokenSecret;

/**
OAuth 2.0 access token from google used to log a user into your application
 
    //Obj-C
    NSString *googleToken = goggleUser.googleToken;

    //Swift
    var googleToken:String = goggleUser.googleToken
 
 
 */
@property (nonatomic, copy, readonly) NSString *googleToken;

/**
Access token from facebook used to log a user into your application
 
     //Obj-C
     NSString *facebookToken = facebookUser.facebookToken;
     
     //Swift
     var facebookToken:String = facebookUser.facebookToken
 
 
 */
@property (nonatomic, copy, readonly) NSString *facebookToken;

////MARK: - User Session

/**---------------------------------------------------------------------------------------
 * @name User Session
 *  ---------------------------------------------------------------------------------------
 */

/**
Mark user as current user which is persisted on disk.
 
     //Obj-C
     [userObject setAsCurrentUser];
     
     //Swift
     userObject.setAsCurrentUser()
 
 */
- (void)setAsCurrentUser;

/**
Clears User Session
 
     //Obj-C
     [userObject removeFromCurrentUser];
     
     //Swift
     userObject.removeFromCurrentUser()
 
 */
- (void)removeFromCurrentUser;

/**
Checks whether the user is currently logged in.
 
     //Obj-C
     if ([userObject isAuthenticated]) {
        //Authenticated
     } else {
       //Not authenticated
     }
     
     //Swift
     if (userObject.isAuthenticated()) {
        //Authenticated
     } else {
        //Not authenticated
     }
 
 
@return returns TRUE/FALSE
 */
- (BOOL)isAuthenticated;



/**---------------------------------------------------------------------------------------
 * @name Register
 *  ---------------------------------------------------------------------------------------
 */
/**
 @abstract Register the user synchronously. Make sure that password and email are set
 
     //Obj-C
     NSError *error;
     [userObject registerUser:error];
     
     //Swift
     var error:NSErrorPointer
     userObject.registerUser(error)
 
 
 @discussion Register's new user. Make sure that password and email are set. This will also enforce that the email isn't already taken.
 @param error Pointer to an NSError that will be set if necessary.
 @deprecated Synchronous methods is been deprecated.
 */
- (void)registerUser:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
 @abstract Register user asynchronously. Make sure that password and email are set
 
     //Obj-C
     [userObject registerUserInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.registerUserInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
 
 @discussion Register's new user. Make sure that password and email are set. This will also enforce that the email isn't already taken.
 @param successBlock callback in case of success.
 @param errorBlock callback in case of failure.
 */
- (void)registerUserInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;


/**---------------------------------------------------------------------------------------
 * @name Login
 *  ---------------------------------------------------------------------------------------
 */

/**
Login BuiltUser synchronously by providing email as ID and signup password
 
     //Obj-C
     BuiltUser *userObject = [builtApplication user];
     [userObject loginWithEmail:@"test@email.com" andPassword:@"password" error:error];
     
     
     //Swift
     var userObject:BuiltUser = builtApplication.user()
     var error:NSErrorPointer
     userObject.loginWithEmail("test@email.com", andPassword:"password", error:error)
 
 
@param email           Email address that you used to signup.
@param password        Your signup password.
@param error           Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.

 */
- (void)loginWithEmail:(NSString *)email
         andPassword:(NSString *)password
               error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Login BuiltUser asynchronously by providing email as ID and signup password
 
     //Obj-C
     BuiltUser *userObject = [builtApplication user];
     [userObject loginInBackgroundWithEmail:@"test@email.com" andPassword:@"password" completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var userObject:BuiltUser = builtApplication.user()
     userObject.loginInBackgroundWithEmail("test@email.com", andPassword:"password") { (ResponseType, NSError!) -> Void in
     
     }
 
@param email           Email address that you used to signup.
@param password        Your signup password.
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)loginInBackgroundWithEmail:(NSString *)email
                       andPassword:(NSString *)password
                        completion:(BuiltRequestCompletionHandler)completionBlock;


/**
Synchronously login using Google OAuth 2.0 access token
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *googleUser = [builtApplication user];
     NSError *error;
     [googleUser loginWithGoogleAuthAccessToken:@"ya29.AHE___SAMPLE____VowjHEZrJA_J0k8" error:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var googleUser:BuiltUser = builtApplication.user()
     var error:NSErrorPointer
     googleUser.loginWithGoogleAuthAccessToken("ya29.AHE___SAMPLE____VowjHEZrJA_J0k8", error:error)
 
 
@param accessToken     Google OAuth 2.0 Access Token
@param error           Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.
 */
- (void)loginWithGoogleAuthAccessToken:(NSString *)accessToken
                               error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Asynchronously login using Google OAuth 2.0 access token
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *googleUser = [builtApplication user];
     [googleUser loginInBackgroundWithGoogleAuthAccessToken:@"ya29.AHE___SAMPLE____VowjHEZrJA_J0k8" completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var googleUser:BuiltUser = builtApplication.user()
     googleUser.loginInBackgroundWithGoogleAuthAccessToken("ya29.AHE___SAMPLE____VowjHEZrJA_J0k8") { (ResponseType, NSError!) -> Void in
     
     }
 
@param accessToken     Google OAuth 2.0 Access Token
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)loginInBackgroundWithGoogleAuthAccessToken:(NSString *)accessToken
                                        completion:(BuiltRequestCompletionHandler)completionBlock;


/**
Synchronously login using Facebook access token
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *facebookUser = [builtApplication user];
     NSError *error;
     [facebookUser loginWithFacebookAccessToken:@"ya29.AHE___SAMPLE____VowjHEZrJA_J0k8" error:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var facebookUser:BuiltUser = builtApplication.user()
     var error:NSErrorPointer
     facebookUser.loginWithFacebookAccessToken("ya29.AHE___SAMPLE____VowjHEZrJA_J0k8", error:error)
 
 
@param accessToken     Facebook OAuth Access Token
@param error           Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.
 */
- (void)loginWithFacebookAccessToken:(NSString *)accessToken
                             error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Asynchronously login using Facebook access token
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *facebookUser = [builtApplication user];
     [facebookUser loginInBackgroundWithFacebookAccessToken:@"ya29.AHE___SAMPLE____VowjHEZrJA_J0k8" completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var facebookUser:BuiltUser = builtApplication.user()
     facebookUser.loginInBackgroundWithFacebookAccessToken("ya29.AHE___SAMPLE____VowjHEZrJA_J0k8", completion: { (ResponseType, NSError!) -> Void in
     
     })
 
 
@param accessToken     Facebook OAuth Access Token
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)loginInBackgroundWithFacebookAccessToken:(NSString *)accessToken
                                      completion:(BuiltRequestCompletionHandler)completionBlock;


/**
 @abstract Synchronously login with Twitter
 
     //Obj-C
     ACAccount *twitterUserAccount = //..ACAccount object of twitter user
     BuiltUser *twitterUser = [builtApplication user];
     NSError *error;
     [twitterUser loginWithTwitterAccount:twitterUserAccount consumerKey:@"aMpLeToKeNVowjHEZrJA_J0k8kjfs78" consumerSecret:@"aMpLeToKeNVowjHEZrJA_J0kfd878" error:error];
     
     //Swift
     var twitterUserAccount:ACAccount = //..ACAccount object of twitter user
     var twitterUser:BuiltUser = builtApplication.user()
     var error:NSErrorPointer
     var twitterDetails:AnyObject = twitterUser.loginWithTwitterAccount(twitterUserAccount, consumerKey:"aMpLeToKeNVowjHEZrJA_J0k8kjfs78", consumerSecret:"aMpLeToKeNVowjHEZrJA_J0kfd878", error:error)
 
 
 @discussion Login BuiltUser by providing twitter account and consumer key and secret
 @param twitterAccount You can use `ACAccountStore`'s accountsWithAccountType:(ACAccountType *)accountType method to retrieve existing signed in twitter accounts
 @param key consumer key of your twitter app
 @param secret consumer secret of your twitter app
 @param error Pointer to an NSError that will be set if necessary.
 @deprecated Synchronous methods is been deprecated.
 */
- (void)loginWithTwitterAccount:(ACAccount *)twitterAccount
                  consumerKey:(NSString *)key
               consumerSecret:(NSString *)secret
                        error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
 @abstract Asynchronously login with Twitter
 
     //Obj-C
     ACAccount *twitterUserAccount = //..ACAccount object of twitter user
     BuiltUser *twitterUser = [builtApplication user];
     [twitterUser loginInBackgroundWithTwitterAccount:twitterUserAccount consumerKey:@"aMpLeToKeNVowjHEZrJA_J0k8kjfs78" consumerSecret:@"aMpLeToKeNVowjHEZrJA_J0kfd878" completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var twitterUserAccount:ACAccount = //..ACAccount object of twitter user
     var twitterUser:BuiltUser = builtApplication.user()
     twitterUser.loginInBackgroundWithTwitterAccount(twitterUserAccount, consumerKey:"aMpLeToKeNVowjHEZrJA_J0k8kjfs78", consumerSecret:"aMpLeToKeNVowjHEZrJA_J0kfd878") { (ResponseType, NSError!) -> Void in
     
     }
 
 
 @discussion Login BuiltUser by providing twitter account and consumer key and secret
 @param twitterAccount You can use `ACAccountStore`'s accountsWithAccountType:(ACAccountType *)accountType method to retrieve existing signed in twitter accounts
 @param key consumer key of your twitter app
 @param secret consumer secret of your twitter app
 @param completionBlock callBack after performing operation
 */

- (void)loginInBackgroundWithTwitterAccount:(ACAccount *)twitterAccount
                                consumerKey:(NSString *)key
                             consumerSecret:(NSString *)secret
                                 completion:(BuiltRequestCompletionHandler)completionBlock;


/**
Asynchronously login with AnyAuth
 
    //Obj-C
    BuiltUser *anyAuthUser = [builtApplication user];
    [anyAuthUser loginInBackgroundWithAnyAuthName:@"login" withParameter:@{@"username": @"james",@"password":@"jamespassword"} completion:^(ResponseType responseType, NSError *error){
    //compeltion block
    }];

    //Swift
    var anyAuthUser:BuiltUser = builtApplication.user()
    anyAuthUser.loginInBackgroundWithAnyAuthName("login", withParameter: ["username":"james","password":"jamespassword"]) { (responseType, error) -> Void in
    //compeltion block
    }

 
@param anyAuthName     AnyAuth extension function name
@param param           parameter for AnyAuth to process
@param completionBlock callBack after performing operation
 */
- (void)loginInBackgroundWithAnyAuthName:(NSString*)anyAuthName withParameter:(NSDictionary*)param completion:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Logout

/**---------------------------------------------------------------------------------------
 * @name Logout
 *  ---------------------------------------------------------------------------------------
 */

/**
Synchronously logs out the currently logged in user.
 
     //Obj-C
     NSError *error;
     [userObject logout:error];
     
     //Swift
     var error:NSErrorPointer
     userObject.logout(error)
 
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.
 */
- (void)logout:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Asynchronously logs out the currently logged in user.
 
     //Obj-C
     [userObject logoutInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.logoutInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
@param completionBlock Completion block with params (ResponseType responseType, NSError *error)
 */
- (void)logoutInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Refresh user
/**---------------------------------------------------------------------------------------
 * @name Refresh user
 *  ---------------------------------------------------------------------------------------
 */

/**
 Synchronously gets the currently logged in user info from server.
 
     //Obj-C
     NSError *error;
     [userObject lrefreshUserInfo:error];
     
     //Swift
     var error:NSErrorPointer
     userObject.refreshUserInfo(error)
 
 @param error Pointer to an NSError that will be set if necessary.
 @deprecated Synchronous methods is been deprecated.
 */
- (void)refreshUserInfo:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Asynchronously gets the currently logged in user info from server.
 
     //Obj-C
     [userObject refreshUserInfoInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.refreshUserInfoInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
 @param completionBlock Completion block with params (ResponseType responseType, NSError *error)
 */
- (void)refreshUserInfoInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Retrieve user's uid
/**---------------------------------------------------------------------------------------
 * @name Retrieve user's uid
 *  ---------------------------------------------------------------------------------------
 */

/**
Fetch user uid synchronously by providing email
 
     //Obj-C
     NSError *error;
     BuiltSynchronousResponse *builtSynResponse = [userObject  fetchUserUidForEmail:@"test@email.com" error:error];
     
     //Swift
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = userObject.fetchUserUidForEmail("test@email.com", error:error)
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param email           email of the user
@param error           Pointer to an NSError that will be set if necessary.
@return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data holding uid of user as NSString if request is successful.
@deprecated Synchronous methods is been deprecated.
 */
- (BuiltSynchronousResponse *)fetchUserUidForEmail:(NSString *)email error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Fetch user uid asynchronously by providing email
 
     //Obj-C
     [userObject fetchUserUidInBackgroundForEmail:@"test@email.com" completion:^(ResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     userObject.fetchUserUidInBackgroundForEmail("test@email.com") { (ResponseType, String!, NSError!) -> Void in
     
     }
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param email           email of the user
@param completionBlock Completion block with params (ResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidInBackgroundForEmail:(NSString *)email completion:(void (^)(ResponseType responseType, NSString *userUID, NSError *error))completionBlock;

/**
Fetch user uid synchronously by providing google email
 
     //Obj-C
     NSError *error;
     BuiltSynchronousResponse *builtSynResponse = [userObject  fetchUserUidForGoogleEmail:@"test@gmail.com" error:error];
     
     
     //Swift
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = userObject.fetchUserUidForGoogleEmail("test@gmail.com", error:error)
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param email           google email of the user
@param error           Pointer to an NSError that will be set if necessary.
@return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data holding uid of user as NSString if request is successful.
@deprecated Synchronous methods is been deprecated.
 */
- (BuiltSynchronousResponse *)fetchUserUidForGoogleEmail:(NSString *)email error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Fetch user uid asynchronously by providing google email
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *userObject = [builtApplication user];
     [userObject fetchUserUidInBackgroundForGoogleEmail:@"test@gmail.com" completion:^(ResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var userObject:BuiltUser = builtApplication.user()
     userObject.fetchUserUidInBackgroundForGoogleEmail("test@gmail.com") { (ResponseType, String!, NSError!) -> Void in
     
     }
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param email           google email of the user
@param completionBlock Completion block with params (ResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidInBackgroundForGoogleEmail:(NSString *)email completion:(void (^)(ResponseType responseType, NSString *userUID, NSError *error))completionBlock;

/**
Fetch user uid synchronously by providing facebook user id
 
     //Obj-C
     NSError *error;
     BuiltSynchronousResponse *builtSynResponse = [userObject fetchUserUidForFacebookUserId:@"dummy_facebook_user_id" error:error];
     
     //Swift
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = userObject.fetchUserUidForFacebookUserId("dummy_facebook_user_id", error:error)
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param userId          Facebook user id
@param error           Pointer to an NSError that will be set if necessary.
@return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data holding uid of user as NSString if request is successful.
@deprecated Synchronous methods is been deprecated.

 */
- (BuiltSynchronousResponse *)fetchUserUidForFacebookUserId:(NSString *)userId error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Fetch user uid asynchronously by providing facebook user id
 
     //Obj-C
     [userObject fetchUserUidInBackgroundForFacebookUserId:@"dummy_facebook_user_id" completion:^(ResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     userObject.fetchUserUidInBackgroundForFacebookUserId("dummy_facebook_user_id") { (ResponseType, String!, NSError!) -> Void in
     
     }
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param userId          Facebook user id
@param completionBlock Completion block with params (ResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidInBackgroundForFacebookUserId:(NSString *)userId completion:(void (^)(ResponseType responseType, NSString *userUID, NSError *error))completionBlock;

/**
Fetch user uid synchronously by providing twiiter user id
 
     //Obj-C
     NSError *error;
     BuiltSynchronousResponse *builtSynResponse = [userObject  fetchUserUidForTwitterUserId:@"dummy_twitter_user_id" error:error];
     
     //Swift
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = userObject.fetchUserUidForTwitterUserId("dummy_twitter_user_id", error:error)
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param userId          Twiiter user id
@param error           Pointer to an NSError that will be set if necessary.
@return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data holding uid of user as NSString if request is successful.
@deprecated Synchronous methods is been deprecated.
 */
- (BuiltSynchronousResponse *)fetchUserUidForTwitterUserId:(NSString *)userId error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Fetch user uid asynchronously by providing twiiter user id
 
     //Obj-C
     [userObject  fetchUserUidInBackgroundForTwitterUserId:@"dummy_twitter_user_id" completion:^(ResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     userObject.fetchUserUidInBackgroundForTwitterUserId("dummy_twitter_user_id") { (ResponseType, String!, NSError!) -> Void in
     
     }
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param userId          Twiiter user id
@param completionBlock Completion block with params (ResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidInBackgroundForTwitterUserId:(NSString *)userId completion:(void (^)(ResponseType responseType, NSString *userUID, NSError *error))completionBlock;


//MARK: - user activation/de-activation

/**---------------------------------------------------------------------------------------
 * @name Activation  / De-activation
 *  ---------------------------------------------------------------------------------------
 */

/**
Activate a user synchronously.
 
     //'bltba9a44506dd9e741' is a uid of an object of inbuilt Application User class
 
     //Obj-C
     NSError *error;
     [userObject  activateUserWithUserId:@"bltba9a44506dd9e741" andActivationToken:@"saMpLeaTivAtioNtoKeN" error:error];
     
     //Swift
     var error:NSErrorPointer
     userObject.activateUserWithUserId("bltba9a44506dd9e741", andActivationToken:"saMpLeaTivAtioNtoKeN", error:error)
 
 
@param userId          user id of the user to activate
@param token           activation token
@param error           Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.

 */
- (void)activateUserWithUserId:(NSString *)userId
            andActivationToken:(NSString *)token
                         error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Activate a user asynchronously.
 
     //'bltba9a44506dd9e741' is a uid of an object of inbuilt Application User class
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *userObject = [builtApplication user];
     [userObject  activateUserInBackgroundWithUserId:@"bltba9a44506dd9e741" andActivationToken:@"saMpLeaTivAtioNtoKeN" completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var userObject:BuiltUser = builtApplication.user()
     userObject.activateUserInBackgroundWithUserId("bltba9a44506dd9e741", andActivationToken:"saMpLeaTivAtioNtoKeN") { (ResponseType, NSError!) -> Void in
     
     }
 
@param userId          user id of the user to activate
@param token           activation token
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)activateUserInBackgroundWithUserId:(NSString *)userId
                        andActivationToken:(NSString *)token
                                completion:(BuiltRequestCompletionHandler)completionBlock;

/**
Deactivates user's account on Built.io Backend synchronously
 
     //Obj-C
     NSError *error;
     [userObject deactivate:error];
     
     //Swift
     var error:NSErrorPointer
     userObject.deactivate(error)
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.

 */
- (void)deactivate:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Deactivates user's account on Built.io Backend asynchronously
 
     //Obj-C
     [userObject deactivateInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.deactivateInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)deactivateInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Frogot Password
/**---------------------------------------------------------------------------------------
 * @name Frogot Password
 *  ---------------------------------------------------------------------------------------
 */

/**
Synchronously send a password reset request for a specified email. If a user account exists with that email, an email will be sent to that address with instructions on how to reset their password
 
 
     //Obj-C
     NSError *error;
     [userObject forgotPasswordForEmail:@"test@email.com" error:error];
     
     //Swift
     var error:NSErrorPointer
     userObject.forgotPasswordForEmail("test@email.com", error:error)
 
 
@param email           Email of the account to send a reset password request.
@param error           Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.
 */
- (void)forgotPasswordForEmail:(NSString *)email error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Asynchronously send a password reset request for a specified email. If a user account exists with that email, an email will be sent to that address with instructions on how to reset their password
 
     //Obj-C
     [userObject forgotPasswordInBackgroundForEmail:@"test@email.com" completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.forgotPasswordInBackgroundForEmail("test@email.com") { (ResponseType, NSError!) -> Void in
     
     }
 
 
@param email           Email of the account to send a reset password request.
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)forgotPasswordInBackgroundForEmail:(NSString *)email completion:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Update User
/**---------------------------------------------------------------------------------------
 * @name Update User
 *  ---------------------------------------------------------------------------------------
 */

/**
Updates the existing user synchronously
 
     //Obj-C
     NSError *error;
     NSDictionary *auth_data = @{@"google": @{@"access_token": @"<google_access_token>"}};
     [userObject updateUserWithAuthData:auth_data error:error];
     
     
     //Swift
     var error:NSErrorPointer
     var auth_data = ["google": ["access_token": "<google_access_token>"]]
     userObject.updateUserWithAuthData(auth_data, error: error)
 
 
@discussion Updates the existing user info. This method can also be used to update other custom fields of the user class.
@discussion User's Google Auth data can updated by providing auth_data `NSDictionary` in params. Pass `nil` if there's no need to update auth data.
@discussion For updating Google's auth data pass `NSDictionary` in following manner. `NSDictionary` *auth_data = @{@"google": @{@"access_token": @"<google_access_token>"}}
@discussion We can also update custom properties by `setCustomProperties` method on BuiltUser object, passing `NSDictionary` of fields to be updated.
@param auth            Updates the user's auth data with data provided in `NSDictionary`. This is an optional parameter.
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
@deprecated Synchronous methods is been deprecated.
 */
- (void)updateUserWithAuthData:(NSDictionary *)auth error:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Updates the existing user asynchronously
 
     //Obj-C
     NSDictionary *auth_data = @{@"google": @{@"access_token": @"<google_access_token>"}};
     
     [userObject updateUserInBackgroundWithAuthData:auth_data completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var auth_data = ["google": ["access_token": "<google_access_token>"]];
     userObject.updateUserInBackgroundWithAuthData(auth_data) { (ResponseType, NSError!) -> Void in
     
     }
 
 
@discussion Updates the existing user info. This method can also be used to update other custom fields of the user class.
@discussion User's Google Auth data can updated by providing auth_data `NSDictionary` in params. Pass `nil` if there's no need to update auth data.
@discussion For updating Google's auth data pass `NSDictionary` in following manner. `NSDictionary` *auth_data = @{@"google": @{@"access_token": @"<google_access_token>"}}
@discussion We can also update custom properties by `setCustomProperties` method on BuiltUser object, passing `NSDictionary` of fields to be updated.
@param auth            Updates the user's auth data with data provided in `NSDictionary`. This is an optional parameter.
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)updateUserInBackgroundWithAuthData:(NSDictionary *)auth completion:(BuiltRequestCompletionHandler)completionBlock;


- (void)saveAsDraft:(NSError **)error BUILTIO_DEPRECATED("Not for BuiltUser");

- (void)saveAsDraftEventually:(NSError **)error BUILTIO_DEPRECATED("Not for BuiltUser");

- (void)saveAsDraftInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock BUILTIO_DEPRECATED("Not for BuiltUser");

- (void)saveAsDraftEventuallyInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock BUILTIO_DEPRECATED("Not for BuiltUser");

@end
