//
//  BuiltNotification.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

/** Notification class for sending notifications*/
@interface BuiltNotification : NSObject

/**
 @abstract notification message to send

     //'blt5d4sample2633b' is a dummy Application API key

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];
 
     //setting message
     notificationObject.message = @"Hi !!";
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     
     //setting message
     notificationObject.message = "Hi !!"
 
 */
@property (nonatomic, copy) NSString *message;

/**
 @abstract date time at which to send the notification
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];

     //to send notification after 300 sec i.e 5 minutes
     notificationObject.sendAt = [NSDate dateWithTimeInterval:300 sinceDate:[NSDate date]];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     notificationObject.sendAt = NSDate(timeInterval:300 sinceDate:NSDate.date())
 
 */
@property (nonatomic, copy) NSDate *sendAt;

/**
 @abstract set this property to TRUE to send the notification local to the users' timezones. Useful only with the `sendAt` property. Defaults to FALSE.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];
     notificationObject.localPush = NO;
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     notificationObject.localPush = false
 
 */
@property (nonatomic, assign) BOOL localPush;


- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
Set a header for an application

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];
     [notificationObject setHeader:@"MyHeaderValue" forKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     notificationObject.setHeader("MyHeaderValue", forKey:"My-Custom-Header-Key")
 
 
@param headerValue The header key
@param headerKey   The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];
     [notificationObject addHeadersWithDictionary:@{@"My-Custom-Header-Key":@"MyHeaderValue"}];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     notificationObject.addHeadersWithDictionary(["My-Custom-Header-Key":"MyHeaderValue"])
 
 
@param headers The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
Removes a header from this application.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];
     [notificationObject removeHeaderForKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     notificationObject.removeHeaderForKey("My-Custom-Header-Key")
 
 
@param headerKey The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;

/**
Sends notification synchronously.
 
     // 'blt5d4sample2633b' is a dummy Application API key
     // 'bltba9userdd9e741' and 'bltfa4userebax157' is a uid of an object of inbuilt Application User class
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];
     NSError *error;
     NSArray *userNotiArray = [NSArray arrayWithObjects:@"bltba9userdd9e741",@"bltfa4userebax157", nil];
     [notificationObject sendNotificationToUsers:userNotiArray error:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     var error:NSErrorPointer
     var userNotiArray = ["bltba9userdd9e741", "bltfa4userebax157"]
     notificationObject.sendNotificationToUsers(userNotiArray, error:error)
 
 
 @discussion set the `message` property before calling this method. You may also set `sendAt` property to specify a delivery time .
 @param users array of users' uids
 @param error Pointer to an NSError that will be set if necessary.
 */
- (void)sendNotificationToUsers:(NSArray *)users error:(NSError **)error;

/**
Send notification asynchronously.
 
     // 'blt5d4sample2633b' is a dummy Application API key
     // 'bltba9userdd9e741' and 'bltfa4userebax157' is a uid of an object of inbuilt Application User class

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltNotification *notificationObject = [builtApplication notification];
     NSArray *userNotiArray = [NSArray arrayWithObjects:@"blt5d4sample2633b",@"bltba9userdd9e741", nil];
     [notificationObject sendNotificationToUsersInBackground:userNotiArray completion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var notificationObject:BuiltNotification = builtApplication.notification()
     var userNotiArray = ["blt5d4sample2633b", "bltba9userdd9e741"]
     notificationObject.sendNotificationToUsersInBackground(userNotiArray) { (ResponseType, NSError!) -> Void in
     
     }
 
 @discussion set the `message` property before calling this method. You may also set `sendAt` property to specify a delivery time .
 @param users array of users' uids
 @param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)sendNotificationToUsersInBackground:(NSArray *)users completion:(BuiltRequestCompletionHandler)completionBlock;

@end
