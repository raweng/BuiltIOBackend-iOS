//
//  BuiltSyncResult.h
//  BuiltIO
//
//  Created by Reefaq on 14/01/16.
//  Copyright © 2016 raweng. All rights reserved.
//

#if !TARGET_OS_WATCH
#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BuiltSyncStatus) {
    BuiltSyncStatusSyncing = 0,
    BuiltSyncStatusSynced,
    BuiltSyncStatusSyncingFailed,
};

typedef NS_ENUM(NSUInteger, BuiltSyncType) {
    BuiltSyncTypeApp = 0,
    BuiltSyncTypeClass,
};

FOUNDATION_EXPORT NSString * const BuiltSyncAppNotification;

FOUNDATION_EXPORT NSString * const BuiltSyncClassNotification;

@interface BuiltSyncResult : NSObject

/**
Name of class if sync type is class.
 
    //Assuming 'syncResultObject' is a BuiltSyncResult instance

    //Obj-C
    NSString *className = syncResultObject.className;

    //Swift
    var className:String = syncResultObject.className
 
 @warning Not supported in watchOS
 */
@property (nullable, nonatomic, copy) NSString *className;

/**
 Sync type i.e App or Class.
 
 @warning Not supported in watchOS
 */
@property (nonatomic, assign) BuiltSyncType type;

/**
Status of the Sync.
 
    BuiltSyncStatusSyncing = 0,
    BuiltSyncStatusSyncingInProgress,
    BuiltSyncStatusSynced,
    BuiltSyncStatusSyncingFailed,

 @warning Not supported in watchOS
 */
@property (nonatomic, assign) BuiltSyncStatus status;

/**
Dictionary object containing Class data or App data containing list of objects that is been created, updated, deleted.
    
For App sync, dictionary would be class name as key and value as dictionary of created, updated, deleted
 
For Class sync, dictionary would be created, updated, deleted as key containing BuiltObject's instance.
 
@warning Not supported in watchOS
 */
@property (nullable, nonatomic, copy) NSDictionary *result;

/**
 Error object if sync fails.
 
 @warning Not supported in watchOS
 */
@property (nullable, nonatomic, copy) NSError *error;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

@end

BUILT_ASSUME_NONNULL_END

#endif

