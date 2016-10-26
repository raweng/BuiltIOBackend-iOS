//
//  Built.h
//  BuiltIO
//
//  Created by Gautam Lodhiya on 25/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@class BuiltApplication;
@class BuiltConfig;

BUILT_ASSUME_NONNULL_BEGIN
/**
 The Built module acts as the entry point for the SDK.
 */
@interface Built : NSObject

//MARK: - Static methods

/**---------------------------------------------------------------------------------------
 * @name Initializing App
 *  ---------------------------------------------------------------------------------------
 */

/**
Represents an application

    //'blt5d4sample2633b' is a dummy Application API key

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")

@param apiKey Your application api-key to uniquely identify the app

@return New instance of application object for provided api-key
 */
+ (BuiltApplication *)applicationWithAPIKey:(NSString*)apiKey;

/**
 Represents an application
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.host = @"api.built.io";
     config.isSSL = YES;
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b" withConfig:config];
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.host = "api.built.io"
     config.isSSL = true
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b" withConfig:config)
 
 @param apiKey Your application api-key to uniquely identify the app.
 @param config BuiltConfig to initalize application.
 
 @return New instance of application object for provided api-key and config
 */
+ (BuiltApplication*)applicationWithAPIKey:(NSString*)apiKey withConfig:(BuiltConfig*)config;

#if !TARGET_OS_WATCH

/**---------------------------------------------------------------------------------------
 * @name Reachability
 *  ---------------------------------------------------------------------------------------
 */

/**
 Reachability change helper to notify whenever internet connection is connected or disconnected.
 
 Below is the example of using this method.
 
     //Obj-C
     [Built reachabilityStatusChangeHandler:^(BuiltReachabilityStatus status) {
         if (status == BuiltReachabilityStatusNotReachable) {
         // No Internet connection
         }else  if (status == BuiltReachabilityStatusReachableViaWiFi) {
         // Reachable via Wifi
         }else  if (status == BuiltReachabilityStatusReachableViaWWAN) {
         // Reachable via 2G/3G/Cellular network
         }
     }]

    //Swift
     Built.reachabilityStatusChangeHandler { (status) -> Void in
         if (status == BuiltReachabilityStatus.NotReachable){
         // No Internet Connection
         }else if (status == BuiltReachabilityStatus.ReachableViaWiFi){
         // Reachable via Wifi
         }else if (status == BuiltReachabilityStatus.ReachableViaWWAN){
         // Reachable via 2G/3G/Cellular network
         }
     }
 
 @param changeBlock invoked when network rechability has changed
 @warning Not supported in watchOS
 */
+ (void)reachabilityStatusChangeHandler:(BuiltRechabilityChangeHandler)changeHandler;
#endif

/**---------------------------------------------------------------------------------------
 * @name Cancel All Network Calls
 *  ---------------------------------------------------------------------------------------
 */

/**
 Cancels all queued and executing operations of an application except realtime
 
 Below is the example of using this method.
 
     //Obj-C
     [Built cancelAllRequestsOfApplication:builtApplication];
     
     //Swift
     Built.cancelAllRequestsOfApplication(builtApplication)
 
 @param application BuiltApplication instance object of which all network operation needs to be cancel.
 */
+ (void)cancelAllRequestsOfApplication:(BuiltApplication*)application;


@end

BUILT_ASSUME_NONNULL_END
