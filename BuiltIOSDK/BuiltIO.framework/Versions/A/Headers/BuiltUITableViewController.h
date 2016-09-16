//
//  BuiltTableViewController.h
//  builtDemo
//
//  Created by Reefaq on 27/02/13.
//  Copyright (c) 2013 raweng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BuiltDefinitions.h"

@class BuiltClass, BuiltObject, BuiltQuery, BuiltApplication;

typedef NS_ENUM(NSUInteger, AutoLoadType) {
    AutoLoadTypeNone = 0,
    AutoLoadTypeLoadMoreViewAtEndOfRow
};

/**---------------------------------------------------------------------------------------
 * Sub-protocol of UITableViewDataSource with modified methods for BuiltUITableViewController
 *  ---------------------------------------------------------------------------------------
 */

@protocol BuiltUITableViewDataSource <UITableViewDataSource>

/**
 @abstract Deprecated the use of this method. It will be internally handled by BuiltUITableViewController. Currently only 1 section is supported.
 @param tableView An object representing the table view requesting this information.
 */
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView UNAVAILABLE_ATTRIBUTE;

/**
 @abstract Deprecated the use of this method. It will be internally handled by BuiltUITableViewController
 @param tableView The table-view object requesting this information.
 @param section An index number identifying a section in tableView.
 */
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section UNAVAILABLE_ATTRIBUTE;

/**
 @abstract Deprecated the use of this method. Use tableView:cellForRowAtIndexPath:builtObject: instead.
 @param tableView A table-view object requesting the cell.
 @param indexPath An index path locating a row in tableView.
 */
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath UNAVAILABLE_ATTRIBUTE;

/**
 @abstract tableView:cellForRowAtIndexPath:builtObject:
 @discussion  Same as UITableViewDatasource method tableView:cellForRowAtIndexPath: i.e Asks the data source for a cell to insert in a particular location of the table view; Additionally it gives BuiltObject of that particular location. (required)
 @param tableView A table-view object requesting the cell.
 @param indexPath An index path locating a row in tableView.
 @param builtObject A built-object associated at indexpath.
 @return An object inheriting from UITableViewCell that the table view can use for the specified row. An assertion is raised if you return nil.
 */
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath builtObject:(BuiltObject* )builtObject;
@optional

/**
 @abstract searchTableView:cellForRowAtIndexPath:builtObject:
 @discussion Same as tableView:cellForRowAtIndexPath:builtObject: but it purposely for searchTableView. This method is called when showSearchBar is set as TRUE in BuiltUITableViewController's instance. tableView:cellForRowAtIndexPath:builtObject: and SearchTableView:cellForRowAtIndexPath:builtObject: is purposely differentiated to avoid conditional coding when used.
 @param tableView A search table-view object requesting the cell.
 @param indexPath An index path locating a row in search tableView.
 @param builtObject A built-object associated at indexpath of search result.
 @return An object inheriting from UITableViewCell that the search table view can use for the specified row. An assertion is raised if you return nil.
 */
- (UITableViewCell *)searchTableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath builtObject:(BuiltObject* )builtObject;

@end


/**---------------------------------------------------------------------------------------
 * Sub-class of UITableViewController with support of BuiltIO SDK
 *  ---------------------------------------------------------------------------------------
 */

@interface BuiltUITableViewController : UITableViewController <BuiltUITableViewDataSource>

/**
 @abstract The application to which we should point to.
 */
@property (nonatomic, readonly) BuiltApplication *builtApplication;

/**
 @abstract UID of Built Class which needs to be bound.
 */
@property (nonatomic, copy, readonly) NSString* classUID;

@property (nonatomic, readonly) NSInteger totalObjectsCount;
@property (nonatomic, readonly) NSInteger totalPages;
@property (nonatomic, readonly) NSInteger currentPage;
@property (nonatomic, assign)   NSInteger fetchLimit; //default is 10
@property (nonatomic, assign)   AutoLoadType autoLoadType; //default is AutoLoadTypeLoadMoreViewAtEndOfRow
@property (nonatomic, assign, getter = isPullToRefreshEnabled) BOOL enablePullToRefresh; //default is YES
@property (nonatomic, readonly) BOOL isLoading;
@property (nonatomic, readonly) BuiltQuery *builtQuery;
@property (nonatomic, assign, getter = isShowingSearchBar) BOOL showSearchBar; //if YES you have to implement searchTableView:cellForRowAtIndexPath:builtObject:
@property (nonatomic, copy)     NSString* searchFieldUID;
@property (nonatomic, readonly) UISearchDisplayController* searchController;

@property (nonatomic, assign)   UITableViewRowAnimation insertTableViewRowAnimation; // default UITableViewRowAnimationTop
@property (nonatomic, assign)   UITableViewRowAnimation deleteTableViewRowAnimation; // default UITableViewRowAnimationBottom
@property (nonatomic, assign)   UITableViewRowAnimation reloadTableViewRowAnimation; // default UITableViewRowAnimationNone

/**
 @abstract a mutable array of all the objects in the tableview.
 */
@property (nonatomic, strong)   NSMutableArray* objectCollection;

/**
 @abstract Initializes a table-view controller to manage a table view of a given style and binds with Built Class of a given classUID.
 @discussion Same as UITableViewController; Additionally it binds table-view controller with a given classUID. 
 @param style A constant that specifies the style of table view that the controller object is to manage (UITableViewStylePlain or UITableViewStyleGrouped).
 @param bltApplication application needs to be pointed to.
 @return An initialized UITableViewController object or nil if the object couldn't be created
 */
- (instancetype)initWithStyle:(UITableViewStyle)style withBuiltClass:(BuiltClass *)builtClass;

/**
 @abstract Returns the BuiltObject of given indexPath.
 @param indexPath The index path locating the BuiltObject in the receiver
 @return An built-object from the set of records fetch by datasource of the table or nil if indexPath is out of range.
 */
- (BuiltObject *)builtObjectAtIndexPath:(NSIndexPath *)indexPath;

/**
 @abstract Returns an array of all the objects in the table view.
 @return An array of BuiltObjects
 @discussion Deprecated. Use objectCollection instead.
 */
- (NSArray *)allObjects DEPRECATED_ATTRIBUTE;

/**
 @abstract called before whenever a network request is initialed.
 */
- (void)networkWillStartLoad;

/**
 @abstract called after a network request is finished.
 @param error An Error if network call fails else nil.
 */
- (void)networkDidFinishLoad:(NSError *)error;

/**
 @abstract Loads next set of messages respect to fetchLimit.
 */
- (void)loadNextPage;

/**
 @abstract refresh the records by clearing all records from table-view and re-fetching first set of data from the server as per the fetchLimit.
 */
- (void)refresh;

/**
 @abstract total number of rows in table-view.
 @return total number of rows in table-view.
 */
-(NSInteger)numberOfRows;

/**
 @abstract clear all records and rows from table-view.
 */
- (void)clearAll;

/**
 @abstract delete the built-object from server at a given index-path and updates the table-view.
 @param deleteIndexPath The index path locating the BuiltObject in the receiver
 */
- (void)deleteBuiltObjectAtIndexPath:(NSIndexPath*)deleteIndexPath;

@end
