
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

@class BuiltACL, BuiltQuery, BuiltLocation;

#if TARGET_OS_IOS
@class ACAccount;
#endif

BUILT_ASSUME_NONNULL_BEGIN

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
@property(nullable, nonatomic, copy) NSString *username;


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
@property(nullable, nonatomic, copy) NSString *email;


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
@property(nullable, nonatomic, copy) NSString *firstName;


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
@property(nullable, nonatomic, copy) NSString *lastName;


/**
 @abstract The password for BuiltUser
 
     //Obj-C
     userObject.password = @"password";
     
     //Swift
     userObject.password = "password"
 
 
 @discussion The password for BuiltUser
 */
@property(nullable, nonatomic, copy) NSString *password;


/**
 @abstract Password confirmation
 
     //Obj-C
     userObject.confirmPassword = @"password";
     
     //Swift
     userObject.confirmPassword = "password"
 
 
 @discussion Password confirmation to confirm that you are real you, not a bot.
 */
@property(nullable, nonatomic, copy) NSString *confirmPassword;


/**
 @abstract The authtoken after logging in
 
     //Obj-C
     NSString *authToken = userObject.authtoken;
     
     //Swift
     var authToken:String = userObject.authtoken
 
 
 @discussion The authtoken after logging in
 */
@property (nullable, nonatomic, copy, readonly) NSString *authtoken;


/**
 @abstract the old password of the user
 
     //Obj-C
     userObject.oldPassword = @"password";
     
     //Swift
     userObject.oldPassword = "password"
 
 
 @discussion the old password of the user to be provided in case user wants to update his/her password.
 */
@property (nullable, nonatomic, copy) NSString *oldPassword;

/**
 @abstract the last login of BuiltUser
 
 //Obj-C
 NSString *lastLogin = userObject.lastLoginAt;
 
 //Swift
 var lastLogin:String = userObject.lastLoginAt
 
 
 @discussion the last login time of given BuiltUser
 */
@property (nullable, nonatomic, copy, readonly) NSDate *lastLoginAt;


//MARK: - Access tokens

#if !TARGET_OS_WATCH
/**
OAuth token from twitter used to log a user into your application
 
     //Obj-C
     NSString *twitterToken = twitterUser.twitterToken;
     
     //Swift
     var twitterToken:String = twitterUser.twitterToken
 
 @warning Not supported in watchOS
 */
@property (nullable, nonatomic, copy, readonly) NSString *twitterToken;

/**
OAuth token secret from twitter used to log a user into your application
 
     //Obj-C
     NSString *twitterTokenSecret = twitterUser.twitterTokenSecret;
     
     //Swift
     var twitterTokenSecret:String = twitterUser.twitterTokenSecret
 
 @warning Not supported in watchOS
 */
@property (nullable, nonatomic, copy, readonly) NSString *twitterTokenSecret;
#endif
/**
OAuth 2.0 access token from google used to log a user into your application
 
    //Obj-C
    NSString *googleToken = goggleUser.googleToken;

    //Swift
    var googleToken:String = goggleUser.googleToken
 
 
 */
@property (nullable, nonatomic, copy, readonly) NSString *googleToken;

/**
Access token from facebook used to log a user into your application
 
     //Obj-C
     NSString *facebookToken = facebookUser.facebookToken;
     
     //Swift
     var facebookToken:String = facebookUser.facebookToken
 
 
 */
@property (nullable, nonatomic, copy, readonly) NSString *facebookToken;

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
 @abstract Register user asynchronously. Make sure that password and email are set
 
     //Obj-C
     [userObject registerUser:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.registerUser { (responseType, error!) -> Void in
     
     }
 
 @discussion Register's new user. Make sure that password and email are set. This will also enforce that the email isn't already taken.
 
 @param completionBlock Completion block with params responseType (cache or network) and error object in any.

 */
- (void)registerUser:(BuiltRequestCompletionHandler)completionBlock;


/**---------------------------------------------------------------------------------------
 * @name Login
 *  ---------------------------------------------------------------------------------------
 */

/**
Login BuiltUser asynchronously by providing email as ID and signup password
 
     //Obj-C
     BuiltUser *userObject = [builtApplication user];
     [userObject loginWithEmail:@"test@email.com" andPassword:@"password" completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var userObject:BuiltUser = builtApplication.user()
     userObject.loginWithEmail("test@email.com", andPassword:"password") { (responseType, error!) -> Void in
     
     }
 
@param email           Email address that you used to signup.
@param password        Your signup password.
@param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)loginWithEmail:(NSString *)email
                       andPassword:(NSString *)password
                        completion:(BuiltRequestCompletionHandler)completionBlock;


/**
Asynchronously login using Google OAuth 2.0 access token
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *googleUser = [builtApplication user];
     [googleUser loginWithGoogleAuthAccessToken:@"ya29.AHE___SAMPLE____VowjHEZrJA_J0k8" completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var googleUser:BuiltUser = builtApplication.user()
     googleUser.loginWithGoogleAuthAccessToken("ya29.AHE___SAMPLE____VowjHEZrJA_J0k8") { (responseType, error!) -> Void in
     
     }
 
@param accessToken     Google OAuth 2.0 Access Token
@param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)loginWithGoogleAuthAccessToken:(NSString *)accessToken
                                        completion:(BuiltRequestCompletionHandler)completionBlock;



/**
Asynchronously login using Facebook access token
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *facebookUser = [builtApplication user];
     [facebookUser loginWithFacebookAccessToken:@"ya29.AHE___SAMPLE____VowjHEZrJA_J0k8" completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var facebookUser:BuiltUser = builtApplication.user()
     facebookUser.loginWithFacebookAccessToken("ya29.AHE___SAMPLE____VowjHEZrJA_J0k8", completion: { (responseType, error!) -> Void in
     
     })
 
 
@param accessToken     Facebook OAuth Access Token
@param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)loginWithFacebookAccessToken:(NSString *)accessToken
                                      completion:(BuiltRequestCompletionHandler)completionBlock;

#if !TARGET_OS_WATCH
/**
 @abstract Asynchronously login with Twitter
 
     //Obj-C
     ACAccount *twitterUserAccount = //..ACAccount object of twitter user
     BuiltUser *twitterUser = [builtApplication user];
     [twitterUser loginWithTwitterAccount:twitterUserAccount consumerKey:@"aMpLeToKeNVowjHEZrJA_J0k8kjfs78" consumerSecret:@"aMpLeToKeNVowjHEZrJA_J0kfd878" completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var twitterUserAccount:ACAccount = //..ACAccount object of twitter user
     var twitterUser:BuiltUser = builtApplication.user()
     twitterUser.loginWithTwitterAccount(twitterUserAccount, consumerKey:"aMpLeToKeNVowjHEZrJA_J0k8kjfs78", consumerSecret:"aMpLeToKeNVowjHEZrJA_J0kfd878") { (responseType, error!) -> Void in
     
     }
 
 
 @discussion Login BuiltUser by providing twitter account and consumer key and secret
 @param twitterAccount You can use `ACAccountStore`'s accountsWithAccountType:(ACAccountType *)accountType method to retrieve existing signed in twitter accounts
 @param key consumer key of your twitter app
 @param secret consumer secret of your twitter app
 @param completionBlock callBack after performing operation
 @warning Not supported in watchOS
 */

- (void)loginWithTwitterAccount:(ACAccount *)twitterAccount
                                consumerKey:(NSString *)key
                             consumerSecret:(NSString *)secret
                                 completion:(BuiltRequestCompletionHandler)completionBlock;

#endif
/**
Asynchronously login with AnyAuth
 
    //Obj-C
    BuiltUser *anyAuthUser = [builtApplication user];
    [anyAuthUser loginWithAnyAuthName:@"login" withParameter:@{@"username": @"james",@"password":@"jamespassword"} completion:^(BuiltResponseType responseType, NSError *error){
    //compeltion block
    }];

    //Swift
    var anyAuthUser:BuiltUser = builtApplication.user()
    anyAuthUser.loginWithAnyAuthName("login", withParameter: ["username":"james","password":"jamespassword"]) { (responseType, error) -> Void in
    //compeltion block
    }

 
@param anyAuthName     AnyAuth extension function name
@param param           parameter for AnyAuth to process
@param completionBlock callBack after performing operation
 */
- (void)loginWithAnyAuthName:(NSString*)anyAuthName withParameter:(NSDictionary*)param completion:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Logout

/**---------------------------------------------------------------------------------------
 * @name Logout
 *  ---------------------------------------------------------------------------------------
 */

/**
Asynchronously logs out the currently logged in user.
 
     //Obj-C
     [userObject logout:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.logout { (responseType, error!) -> Void in
     
     }
 
@param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
 */
- (void)logout:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Refresh user
/**---------------------------------------------------------------------------------------
 * @name Refresh user
 *  ---------------------------------------------------------------------------------------
 */

/**
Asynchronously gets the currently logged in user info from server.
 
     //Obj-C
     [userObject refreshUserInfo:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.refreshUserInfo { (responseType, error!) -> Void in
     
     }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSError *error)
 */
- (void)refreshUserInfo:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Retrieve user's uid
/**---------------------------------------------------------------------------------------
 * @name Retrieve user's uid
 *  ---------------------------------------------------------------------------------------
 */


/**
Fetch user uid asynchronously by providing email
 
     //Obj-C
     [userObject fetchUserUidForEmail:@"test@email.com" completion:^(BuiltResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     userObject.fetchUserUidForEmail("test@email.com") { (responseType, userUID!, error!) -> Void in
     
     }
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param email           email of the user
@param completionBlock Completion block with params (BuiltResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidForEmail:(NSString *)email completion:(void (^)(BuiltResponseType responseType, NSString * BUILT_NULLABLE_P userUID, NSError * BUILT_NULLABLE_P error))completionBlock;


/**
Fetch user uid asynchronously by providing google email
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *userObject = [builtApplication user];
     [userObject fetchUserUidForGoogleEmail:@"test@gmail.com" completion:^(BuiltResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var userObject:BuiltUser = builtApplication.user()
     userObject.fetchUserUidForGoogleEmail("test@gmail.com") { (responseType, userUID!, error!) -> Void in
     
     }
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param email           google email of the user
@param completionBlock Completion block with params (BuiltResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidForGoogleEmail:(NSString *)email completion:(void (^)(BuiltResponseType responseType, NSString * BUILT_NULLABLE_P userUID, NSError * BUILT_NULLABLE_P error))completionBlock;

/**
Fetch user uid asynchronously by providing facebook user id
 
     //Obj-C
     [userObject fetchUserUidForFacebookUserId:@"dummy_facebook_user_id" completion:^(BuiltResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     userObject.fetchUserUidForFacebookUserId("dummy_facebook_user_id") { (responseType, userUID!, error!) -> Void in
     
     }
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param userId          Facebook user id
@param completionBlock Completion block with params (BuiltResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidForFacebookUserId:(NSString *)userId completion:(void (^)(BuiltResponseType responseType, NSString * BUILT_NULLABLE_P userUID, NSError * BUILT_NULLABLE_P error))completionBlock;

/**
Fetch user uid asynchronously by providing twiiter user id
 
     //Obj-C
     [userObject  fetchUserUidForTwitterUserId:@"dummy_twitter_user_id" completion:^(BuiltResponseType responseType, NSString *userUID, NSError *error) {
     
     }];
     
     //Swift
     userObject.fetchUserUidForTwitterUserId("dummy_twitter_user_id") { (responseType, userUID!, error!) -> Void in
     
     }
 
 
@discussion This call will allow you to retrieve the uid for a user, whether or not the user exists. A means for identifying the user needs to be provided. This comes in handy, for example, when you need to apply ACL for a user that may not exist in the system at the moment.
@param userId          Twiiter user id
@param completionBlock Completion block with params (BuiltResponseType responseType, NSString *userUID, NSError *error)
 */
- (void)fetchUserUidForTwitterUserId:(NSString *)userId completion:(void (^)(BuiltResponseType responseType, NSString * BUILT_NULLABLE_P userUID, NSError * BUILT_NULLABLE_P error))completionBlock;


//MARK: - user activation/de-activation

/**---------------------------------------------------------------------------------------
 * @name Activation  / De-activation
 *  ---------------------------------------------------------------------------------------
 */

/**
Activate a user asynchronously.
 
     //'bltba9a44506dd9e741' is a uid of an object of inbuilt Application User class
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUser *userObject = [builtApplication user];
     [userObject  activateUserWithUserId:@"bltba9a44506dd9e741" andActivationToken:@"saMpLeaTivAtioNtoKeN" completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var userObject:BuiltUser = builtApplication.user()
     userObject.activateUserWithUserId("bltba9a44506dd9e741", andActivationToken:"saMpLeaTivAtioNtoKeN") { (responseType, error!) -> Void in
     
     }
 
@param userId          user id of the user to activate
@param token           activation token
@param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)activateUserWithUserId:(NSString *)userId
                        andActivationToken:(NSString *)token
                                completion:(BuiltRequestCompletionHandler)completionBlock;

/**
Deactivates user's account on Built.io Backend asynchronously
 
     //Obj-C
     [userObject deactivate:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.deactivate { (responseType, error!) -> Void in
     
     }
 
@param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)deactivate:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Frogot Password
/**---------------------------------------------------------------------------------------
 * @name Frogot Password
 *  ---------------------------------------------------------------------------------------
 */

/**
Asynchronously send a password reset request for a specified email. If a user account exists with that email, an email will be sent to that address with instructions on how to reset their password
 
     //Obj-C
     [userObject forgotPasswordForEmail:@"test@email.com" completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     userObject.forgotPasswordForEmail("test@email.com") { (responseType, error!) -> Void in
     
     }
 
 
@param email           Email of the account to send a reset password request.
@param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)forgotPasswordForEmail:(NSString *)email completion:(BuiltRequestCompletionHandler)completionBlock;

//MARK: - Update User
/**---------------------------------------------------------------------------------------
 * @name Update User
 *  ---------------------------------------------------------------------------------------
 */

/**
Updates the existing user asynchronously
 
     //Obj-C
     NSDictionary *auth_data = @{@"google": @{@"access_token": @"<google_access_token>"}};
     
     [userObject updateUserWithAuthData:auth_data completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var auth_data = ["google": ["access_token": "<google_access_token>"]];
     userObject.updateUserWithAuthData(auth_data) { (responseType, error!) -> Void in
     
     }
 
 
@discussion Updates the existing user info. This method can also be used to update other custom fields of the user class.
@discussion User's Google Auth data can updated by providing auth_data `NSDictionary` in params. Pass `nil` if there's no need to update auth data.
@discussion For updating Google's auth data pass `NSDictionary` in following manner. `NSDictionary` *auth_data = @{@"google": @{@"access_token": @"<google_access_token>"}}
@discussion We can also update custom properties by `setCustomProperties` method on BuiltUser object, passing `NSDictionary` of fields to be updated.
@param auth            Updates the user's auth data with data provided in `NSDictionary`. This is an optional parameter.
@param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 */
- (void)updateUserWithAuthData:(NSDictionary *)auth completion:(BuiltRequestCompletionHandler)completionBlock;

- (void)saveAsDraft:(BuiltRequestCompletionHandler)completionBlock BUILTIO_DEPRECATED("Not for BuiltUser");

- (void)saveAsDraftEventually:(BuiltRequestCompletionHandler)completionBlock BUILTIO_DEPRECATED("Not for BuiltUser");


@end

BUILT_ASSUME_NONNULL_END
