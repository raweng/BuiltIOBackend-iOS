//
//  BuiltApplication+LocalStore.h
//  BuiltIO
//
//  Created by Hardik Pithadia on 02/11/15.
//  Copyright © 2015 raweng. All rights reserved.
//

#if !TARGET_OS_WATCH
#import <BuiltIO/BuiltIO.h>

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltApplication (LocalStore)

//MARK: - Clear Hook
/**
Removes all the records from offline DB.
@warning Not supported in watchOS
 */
- (void)clearOfflineData;

/**
 Removes all the records from offline DB for the specified classes.
 
 @param onlyClasses Array of class name which need to be removed.
 @warning Not supported in watchOS
 */
- (void)clearOfflineDataOfOnly:(NSArray*)onlyClasses;

/**
 Removes all the records from offline DB except the specified classes.
 
 @param exceptClasses Array of class name which need not to be removed.
 @warning Not supported in watchOS
 */
- (void)clearOfflineDataExcept:(NSArray*)exceptClasses;

//MARK: - Sync

/**
 Sync all classes with the server. If offline is enabled in BuiltConfig it will save all records.
 
 @warning Not supported in watchOS
 */
- (void)sync;

/**
 Sync all classes with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
 
 @param date Date from which sync need to be performed.
 @warning Not supported in watchOS
 */
- (void)sync:(NSDate*)date;

/**
 Sync only classes specified with the server. If offline is enabled in BuiltConfig it will save all records.
 
 @param onlyClasses Array of class name which should to be synced.
 @warning Not supported in watchOS
 */
- (void)syncOnly:(NSArray*)onlyClasses;

/**
 Sync only classes specified with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
 
 @param onlyClasses Array of class name which should to be synced.
 @param date        Date from which sync need to be performed.
 @warning Not supported in watchOS
 */
- (void)syncOnly:(NSArray*)onlyClasses date:(NSDate*)date;

/**
 Sync all classes except the specified list with the server. If offline is enabled in BuiltConfig it will save all records.
 
 @param exceptClasses Array of class name which should not be synced.
 @warning Not supported in watchOS
 */
- (void)syncExcept:(NSArray*)exceptClasses;

/**
 Sync all classes except the specified list with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
 
 @param exceptClasses Array of class name which should not be synced.
 @param date          Date from which sync need to be performed.
 @warning Not supported in watchOS
 */
- (void)syncExcept:(NSArray*)exceptClasses date:(NSDate*)date;

@end

BUILT_ASSUME_NONNULL_END
#endif
