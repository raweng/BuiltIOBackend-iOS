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
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication clearOfflineData];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.clearOfflineData()

@warning Not supported in watchOS
 */
- (void)clearOfflineData;

/**
 Removes all the records from offline DB for the specified classes.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication clearOfflineDataOfOnly:@[@"task"]];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.clearOfflineData(ofOnly: ["task"])
 
 @param onlyClasses Array of class name which need to be removed.
 @warning Not supported in watchOS
 */
- (void)clearOfflineDataOfOnly:(NSArray*)onlyClasses;

/**
 Removes all the records from offline DB except the specified classes.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication clearOfflineDataExcept:@[@"task"]];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.clearOfflineData(ofExcept: ["task"])

 @param exceptClasses Array of class name which need not to be removed.
 @warning Not supported in watchOS
 */
- (void)clearOfflineDataExcept:(NSArray*)exceptClasses;

//MARK: - Sync

/**
 Sync all classes with the server. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication sync];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.sync()
 
 @warning Not supported in watchOS
 */
- (void)sync;

/**
 Sync all classes with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:10000];
    [builtApplication sync:date];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    let date:Date = Date.init(timeIntervalSince1970: 10000)
    builtApplication.sync(date)
 
 @param date Date from which sync need to be performed.
 @warning Not supported in watchOS
 */
- (void)sync:(NSDate*)date;

/**
 Sync only classes specified with the server. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:10000];
    [builtApplication syncOnly:@[@"task"]];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    let date:Date = Date.init(timeIntervalSince1970: 10000)
    builtApplication.syncOnly(["task"])
 
 @param onlyClasses Array of class name which should to be synced.
 @warning Not supported in watchOS
 */
- (void)syncOnly:(NSArray*)onlyClasses;

/**
 Sync only classes specified with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:10000];
    [application syncOnly:@[@"task"] date:date];

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    let date:Date = Date.init(timeIntervalSince1970: 10000)
    builtApplication.syncOnly(["task"], date: date)
 
 @param onlyClasses Array of class name which should to be synced.
 @param date        Date from which sync need to be performed.
 @warning Not supported in watchOS
 */
- (void)syncOnly:(NSArray*)onlyClasses date:(NSDate*)date;

/**
 Sync all classes except the specified list with the server. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:10000];
    [builtApplication syncExcept:@[@"project"]];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    let date:Date = Date.init(timeIntervalSince1970: 10000)
    builtApplication.syncExcept(["project"])
 
 @param exceptClasses Array of class name which should not be synced.
 @warning Not supported in watchOS
 */
- (void)syncExcept:(NSArray*)exceptClasses;

/**
 Sync all classes except the specified list with the server from the specified date. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key

    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:10000];
    [application syncExcept:@[@"project"] date:date];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    let date:Date = Date.init(timeIntervalSince1970: 10000)
    builtApplication.syncExcept(["project"], date: date)

 @param exceptClasses Array of class name which should not be synced.
 @param date          Date from which sync need to be performed.
 @warning Not supported in watchOS
 */
- (void)syncExcept:(NSArray*)exceptClasses date:(NSDate*)date;

/**
 Note: If objects are more than 1000 in a class, then this method will be recommended instead of sync.

 Sync all classes with the server with pagination. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication syncWithPagination];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.syncWithPagination()

 @warning Not supported in watchOS
 */
- (void)syncWithPagination;

/**
 Note: If objects are more than 1000 in a class, then this method will be recommended instead of syncOnly.

 Sync only classes specified with the server with pagination. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication syncOnlyWithPagination:@[@"task"]];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.syncOnly(withPagination: ["task"])

 
 @param onlyClasses Array of class name which should to be synced.
 @warning Not supported in watchOS
 */
- (void)syncOnlyWithPagination:(NSArray*)onlyClasses ;

/**
 Note: If objects are more than 1000 in a class, then this method will be recommended instead of syncExcept.

 Sync all classes except the specified list with the server with pagination. If offline is enabled in BuiltConfig it will save all records.
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    [builtApplication syncExceptWithPagination:@[@"project"]];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    builtApplication.syncExcept(withPagination: ["project"])


 @param exceptClasses Array of class name which should not be synced.
 @warning Not supported in watchOS
 */
- (void)syncExceptWithPagination:(NSArray*)exceptClasses;

@end

BUILT_ASSUME_NONNULL_END
#endif
