//
//  BuiltInstallation.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#if !TARGET_OS_WATCH

#import <Foundation/Foundation.h>
#import "BuiltObject.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltInstallation : BuiltObject

/**
 @abstract APNS device token
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     NSString *deviceToken = installation.deviceToken;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     var deviceToken:String = installation.deviceToken
 
 @warning Not supported in watchOS
 */
@property (nonatomic, copy) NSString *deviceToken;

/**
 
 @abstract subscription channels
 
     //'blt5d4sample2633b' is a dummy Application API key

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
        
     //setting channels
     installation.channels = @[@"project.object.create", @"project.object.update"];
 
     //getting channels
     NSArray *channelsArray = installation.channels;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     
     //setting channels
     installation.channels = ["project.object.create", "project.object.update"]
 
     //getting channels
     var channelsArray:AnyObject! = installation.channels
 
 @discussion You can use the following as channel names:
 
 **{class_uid}.object.create**
 
 Use this activity channel, when you want to send notification, after any object is created inside the class with the uid class_uid
 
 **{class_uid}.object.update**
 
 Use this activity channel, when you want to send notification, after any object is updated inside the class with the uid class_uid
 
 **{class_uid}.object.delete**
 
 Use this activity channel, when you want to send notification, after any object is deleted inside the class with the uid class_uid
 
 **{class_uid}.{object_uid}.update**
 
 Use this activity channel, when you want to send notification, after an object with the uid object_uid is updated inside the class with the uid class_uid
 
 **{class_uid}.{object_uid}.delete**
 
 Use this activity channel, when you want to send notification, after an object with the uid object_uid is deleted inside the class with the uid class_uid
 
 **upload.create**
 
 Use this activity channel, when you want to send a notification after an upload is created.
 
 **{upload_uid}.update**
 
 Use this activity channel, when you want to send a notification after an upload is updated.
 
 **{upload_uid}.delete**
 
 Use this activity channel, when you want to send a notification after an upload is deleted.
 
 **upload.update**
 
 Use this activity channel, when you want to send a notification after any upload is updated.
 
 **upload.delete**
 
 Use this activity channel, when you want to send a notification after any upload is deleted.
 
 
 **Developer-Defined Channels**
 
 
 These are the custom-channel names that the application developer can use subscribe/unsubscribe the installations to. This can be any random name. You can directly subscribe the installation to a channel, it is not required to create a channel first and then make the installation subscribe to it
 
 @warning Not supported in watchOS
 */
@property (nonatomic, copy) NSArray *channels;


/**
 @abstract time zone of the installation

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     NSTimeZone *timeZome = installation.timezone;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     var timeZone:TimeZone = installation.timezone
 
 @discussion sets a time zone to the ionstalltion object. Default is the current system time zone.
 @warning Not supported in watchOS
 */
@property (nonatomic, strong) NSTimeZone *timezone;

/**
 @abstract location for an installation

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     BuiltLocation *builtLocation = installation.geoLocation;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     var builtLocation:BuiltLocation =  installation.geoLocation
 
 @warning Not supported in watchOS
 */
@property (nonatomic, strong) BuiltLocation *geoLocation;

/**
 @abstract Credentials name for an installation. Default value is "default"
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     NSString *credentilasName = installation.credentialsName;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     var credentialsName:String =  installation.credentialsName
 
 @warning Not supported in watchOS
 */
@property (nonatomic, strong) NSString *credentialsName;


- (instancetype)init UNAVAILABLE_ATTRIBUTE;

//MARK: - Headers
/**---------------------------------------------------------------------------------------
 * @name Headers
 *  ---------------------------------------------------------------------------------------
 */

/**
Set a header for an application

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     [installation setHeader:@"MyHeaderValue" forKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     installation.setHeader("MyHeaderValue", forKey:"My-Custom-Header-Key")
 
@param headerValue The header key
@param headerKey   The header value
@warning Not supported in watchOS
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     [installation addHeadersWithDictionary:@{@"My-Custom-Header": @"MyValue"}]
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     installation.addHeadersWithDictionary(["My-Custom-Header":"MyValue"])
 
@param headers The headers as dictionary which needs to be added to the application
@warning Not supported in watchOS
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
Removes a header from this application.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     [installation removeHeaderForKey:@"My-Custom-Header"]
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     installation.removeHeaderForKey("My-Custom-Header")
 
@param headerKey The header key that needs to be removed
@warning Not supported in watchOS
 */
- (void)removeHeaderForKey:(NSString *)headerKey;

/**---------------------------------------------------------------------------------------
 * @name Clear/Disable Installation
 *  ---------------------------------------------------------------------------------------
 */

/**
Clear installation data on disk
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication currentInstallation];
     [installation clearInstallation];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.currentInstallation()
     installation.clearInstallation()
 
@warning Not supported in watchOS
 */
- (void)clearInstallation;


//MARK: - Disable installation
/**
Disable installation
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication currentInstallation];
     [installation disableInstallation:YES];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.currentInstallation()
     installation.disableInstallation(true)
 
 @warning Not supported in watchOS
 */
- (void)disableInstallation:(BOOL)shouldDisable;


//MARK: - Clear Badge
/**---------------------------------------------------------------------------------------
 * @name Clear Badge
 *  ---------------------------------------------------------------------------------------
 */

/**
 Clear the badge count
 
 This method notifies Built.io Backend to set the notification badge count to zero.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     [installation clearBadge];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     installation.clearBadge()
 
@warning Not supported in watchOS
 */
- (void)clearBadge;

//MARK: - Create/Update Installation

/**---------------------------------------------------------------------------------------
 * @name Create/Update Installation
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Asynchronously create a new installation
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltInstallation *installation = [builtApplication installation];
    NSError *error;
    NSArray subscriptionChannels = @[@"object.create", @"object.delete"];
    [installation createInstallationWithSubscriptionChannels:subscriptionChannels completion:^(BuiltResponseType responseType, NSError *error) {

    }];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var installation:BuiltInstallation = builtApplication.installation()
    var subscriptionChannels = ["object.create", "object.delete"]
    installation.createInstallationWithSubscriptionChannels(subscriptionChannels) { (responseType, error!) -> Void in

    }
 
 
 @discussion Create a new installation with the device token.
 @param channels Array of channel we wish to subscribe to.
 @param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 @warning Not supported in watchOS
 */
- (void)createInstallationWithSubscriptionChannels:(NSArray *)channels completion:(BuiltRequestCompletionHandler)completionBlock;

/**
 @abstract Asynchronously update the current installation with the logged in user, location and time zone.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     [installation updateInstallation:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     installation.updateInstallation { (responseType, error!) -> Void in
     
     }
 
 @discussion this method associates the installation with the user and updates the location and timezone if set. Call this method after the user is logged in if user is to be associated with the installation.
 @param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 @warning Not supported in watchOS
 */
- (void)updateInstallation:(BuiltRequestCompletionHandler)completionBlock;


//MARK: - Subscribe Unsubscribe to Channels
/**---------------------------------------------------------------------------------------
 * @name Subscribe/Unsubscribe to Channels
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Asynchronously subscribe an installation to more channels.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     NSArray subscriptionChannels = @[@"Sports",@"Technology"];
     
     [installation  subscribeToChannels:subscriptionChannels completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     var subscriptionChannels = ["Sports", "Technology"]
     installation.subscribeToChannels(subscriptionChannels) { (responseType, error!) -> Void in
     
     }
 
 @discussion Using this method you can add more channels to your subscription list.
 @param channels Array of channel we wish to subscribe to.
 @param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 @warning Not supported in watchOS
 */
- (void)subscribeToChannels:(NSArray *)channels completion:(BuiltRequestCompletionHandler)completionBlock;


/**
 @abstract Asynchronously unsubscribe an installation from channels
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltInstallation *installation = [builtApplication installation];
     NSArray unsubscriptionChannels = @[@"Sports", @"Technology"];
     [installation  unsubscribeToChannels:unsubscriptionChannels completion:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var installation:BuiltInstallation = builtApplication.installation()
     var unsubscriptionChannels = ["Sports", "Technology"]
     installation.unsubscribeToChannels(unsubscriptionChannels) { (responseType, error!) -> Void in
     
     }
 
 
 @discussion Using this method you can unsubscribe from channels.
 @param channels Array of channel we wish to unsubscribe to.
 @param completionBlock Completion block with params (BuiltResponseType responseType, id responseJSON, NSError *error)
 @warning Not supported in watchOS
 */
-(void)unsubscribeToChannels:(NSArray *)channels completion:(BuiltRequestCompletionHandler)completionBlock;

@end

BUILT_ASSUME_NONNULL_END

#endif