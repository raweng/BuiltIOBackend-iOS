//
//  BuiltApplication+LocalStore.h
//  BuiltIO
//
//  Created by Hardik Pithadia on 02/11/15.
//  Copyright © 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>

@interface BuiltApplication (LocalStore)

//MARK: - Clear Hook
/**
Removes all the records from offline DB.
 */
- (void)clearOfflineData;

/**
 *  Removes all the records from offline DB for the specified classes.
 *
 *  @param onlyClasses Array of class name which need to be removed.
 */
- (void)clearOfflineDataOfOnly:(NSArray*)onlyClasses;

/**
 *  Removes all the records from offline DB except the specified classes.
 *
 *  @param exceptClasses Array of class name which need not to be removed.
 */
- (void)clearOfflineDataExcept:(NSArray*)exceptClasses;

//MARK: - Sync

/**
 *  Sync all classes with the server. If offline is enabled in BuiltConfig it will save all records.
 */
- (void)sync;

/**
 *  Sync all classes with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
 *
 *  @param date Date from which sync need to be performed.
 */
- (void)sync:(NSDate*)date;

/**
 *  Sync only classes specified with the server. If offline is enabled in BuiltConfig it will save all records.
 *
 *  @param onlyClasses Array of class name which should to be synced.
 */
- (void)syncOnly:(NSArray*)onlyClasses;

/**
 *  Sync only classes specified with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
 *
 *  @param onlyClasses Array of class name which should to be synced.
 *  @param date        Date from which sync need to be performed.
 */
- (void)syncOnly:(NSArray*)onlyClasses date:(NSDate*)date;

/**
 *  Sync all classes except the specified list with the server. If offline is enabled in BuiltConfig it will save all records.
 *
 *  @param exceptClasses Array of class name which should not be synced.
 */
- (void)syncExcept:(NSArray*)exceptClasses;

/**
 *  Sync all classes except the specified list with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
 *
 *  @param exceptClasses Array of class name which should not be synced.
 *  @param date          Date from which sync need to be performed.
 */
- (void)syncExcept:(NSArray*)exceptClasses date:(NSDate*)date;

@end
