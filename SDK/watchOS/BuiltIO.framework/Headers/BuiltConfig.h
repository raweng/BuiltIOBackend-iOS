//
//  BuiltConfig.h
//  BuiltIO
//
//  Created by Reefaq on 01/12/15.
//  Copyright © 2015 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltConfig : NSObject

/**---------------------------------------------------------------------------------------
 * @name Backend API Host
 *  ---------------------------------------------------------------------------------------
 */

//MARK: - Built.io host
/**
Host name of Built.io Backend api server.
 
    //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.host = @"api.built.io";

    //Swift
     var config:BuiltConfig = BuiltConfig()
     config.host = "api.built.io"
 
 */
@property (nonatomic, copy) NSString *host;

/**
SSL state of Built.io Backend api server.
 
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.isSSL = YES;
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.isSSL = true
 
 */
@property (nonatomic, assign) BOOL isSSL;

/**
 API version of Built.io Backend api server.
 
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.version = @"v2";
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.isSSL = "v2"
 
 */
@property (nonatomic, copy) NSString *version;


/**
 Returns the URL in which application will point to.
 
 @warning This property is readonly i.e you can just read the value but can't set its value
 
     //Obj-C
     NSString *URLString = config.url;
     
     //Swift
     var URLString:NSString = config.url
 
 @deprecated Please use BuiltConfig instead.
 
 */
@property (nonatomic, copy, readonly) NSString *url;

#if TARGET_OS_IOS
/**---------------------------------------------------------------------------------------
 * @name Backend Realtime API Host
 *  ---------------------------------------------------------------------------------------
 */

//MARK: - Built.io realtime host
/**
 Realtime host name of Built.io Backend api server.
 
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.realtimeHost = @"realtime.built.io";
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.realtimeHost = "realtime.built.io"
 
@warning Not supported in watchOS
 */
@property (nonatomic, copy) NSString *realtimeHost;

/**
 Realtime port number of Built.io Backend api server.
 
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.realtimePort = 443;
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.realtimePort = 443
 
 @warning Not supported in watchOS
 */
@property (nonatomic, assign) NSInteger realtimePort;

/**
 Realtime SSL state of Built.io Backend api server.
 
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.realtimeSSL = YES;
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.realtimeSSL = true
 
 @warning Not supported in watchOS
 */
@property (nonatomic, assign) BOOL realtimeSSL;
#endif

//MARK: - Usermetrics
/**---------------------------------------------------------------------------------------
 * @name Usermetrics
 *  ---------------------------------------------------------------------------------------
 */

/**
 Enable UserMetrics for application
 
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.enableUserMetrics = YES;
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.enableUserMetrics = true
 
 */
@property (nonatomic, assign, getter=isUserMetricsEnabled) BOOL enableUserMetrics;

#if TARGET_OS_IOS
//MARK: - offline

/**---------------------------------------------------------------------------------------
 * @name Offline
 *  ---------------------------------------------------------------------------------------
 */


/**
 Enable offline mode for application. When enabled, it will save and mantain all records from application Sync, BuiltQuery and save operation of BuiltObject to offline DB.
 
     //Obj-C
     BuiltConfig *config = [[BuiltConfig alloc] init];
     config.offline = YES;
     
     //Swift
     var config:BuiltConfig = BuiltConfig()
     config.offline = true
 
 @warning Not supported in watchOS
 */
@property (nonatomic, assign, getter=isOffline) BOOL offline;
#endif

@end

BUILT_ASSUME_NONNULL_END
