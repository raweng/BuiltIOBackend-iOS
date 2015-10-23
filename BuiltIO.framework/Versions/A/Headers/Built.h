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
Represents an application with custom hostname

     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b" hostName:@"api.built.io"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b", hostName:"api.built.io")
 
 
@param apiKey apiKey Your application api-key to uniquely identify the app
@param hostName hostname Built.io Backend hostname
@return New instance of application object for provided api-key and hostname
 */
+ (BuiltApplication*)applicationWithAPIKey:(NSString*)apiKey hostName:(NSString*)hostName;

/**
Represents an application with custom hostname and SSL
 
     //'blt5d4sample2633b' is a dummy Application API key
     
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b" hostName:@"api.built.io" isSSL:YES];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b", hostName:"api.built.io", isSSL:true)


@param apiKey   apiKey Your application api-key to uniquely identify the app
@param hostName hostname Built.io Backend hostname
@param isSSL    The protocol to be used (http/https) in terms of boolean
@return New instance of application object for provided api-key, hostname and ssl
 */
+ (BuiltApplication*)applicationWithAPIKey:(NSString*)apiKey hostName:(NSString*)hostName isSSL:(BOOL)isSSL;

/**
 Disable UserMetrics calls
 
 //This should be initiated at very first i.e before initializing BuiltApplication instance from applicationWithAPIKey: methods
 
     //Obj-C
     [Built userMetricsDisable:YES];
     
     //Swift
     Built.userMetricsDisable(true)
 
 
 @param disable if set true, BuiltApplication instance created after will not send user metrics calls. Default is false.
 */
+ (void)userMetricsDisable:(BOOL)disable;

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
 */
+ (void)reachabilityStatusChangeHandler:(BuiltRechabilityChangeHandler)changeHandler;

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
