//
//  QueryResult.h
//  BuiltIO
//
//  Created by Reefaq on 30/10/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@interface QueryResult : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 @abstract Get array of objects returned by BuiltQuery.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSArray *result = [result getResult];// get all result in array
     }];
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
        var results:Array  =  queryResult.getResult()
     }
 
 @return Returns an array of objects returned by BuiltQuery.
 */
- (NSArray *)getResult;


/**
 @abstract Get array of roles returned by BuiltQuery.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSArray *result = [result getRoles];// get all result in array
     }];
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
        var results:Array  =  queryResult.getRoles()
     }
 
 @return Returns an array of roles returned by BuiltQuery.
 */
- (NSArray *)getRoles;

/**
 @abstract Get array of users returned by BuiltQuery.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSArray *result = [result getUsers];// get all result in array
     }];
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
        var results:Array  =  queryResult.getUsers()
     }
 
 @return Returns an array of users returned by BuiltQuery.
 */
- (NSArray *)getUsers;

/**
 @abstract Gets the schema of objects returned by BuiltQuery alongwith objects themselves.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSArray *result = [result schema];
     }];
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
        var schema:Array  =  queryResult.schema()
     }
 
 @return Returns schemas.
 */
- (NSArray *)schema;

/**
 @abstract Count of number of object returned by BuiltQuery.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSInteger count = [result count];
     }];
     
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
        var count:Int  =  queryResult.count()
     }
     
 
 @return Returns the count of number of object returned by BuiltQuery.
 */
- (NSInteger)count;

/**
 @abstract Get array of updated objects returned by BuiltDelta.
 
     Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSArray *updatedObject = [result updatedObjects];
     }];
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
        var updatedObject:Array  =  queryResult.updatedObjects()
     }
 
 @return Returns an array of updated objects returned by BuiltDelta.
 */
- (NSArray *)updatedObjects;


/**
 @abstract Get array of created objects returned by BuiltDelta.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
         NSArray *createdObject = [result createdObjects];
     }];
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
         var createdObject:Array  =  queryResult.createdObjects()
     }
 
 
 @return Returns an array of created objects returned by BuiltDelta.
 */
- (NSArray *)createdObjects;


/**
 @abstract Get array of deleted objects returned by BuiltDelta.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
         NSArray *deletedObject = [result deletedObjects];
     }];
     
     //Swift
     projectQuery.execInBackground { (responseType, queryResult!, error!) -> Void in
         var deletedObject:Array  =  queryResult.deletedObjects()
     }
 
 @return Returns an array of deleted objects returned by BuiltDelta.
 */
- (NSArray *)deletedObjects;

//MARK: - Deprecated API

/**
 @abstract Count of number of object returned by BuiltQuery alongwith objects themselves.
 
 @return Returns the count of number of object returned by BuiltQuery.
 @deprecated Deprecated. Use 'count' method instead.
 */
- (NSInteger)totalCount BUILTIO_DEPRECATED("Deprecated. Use 'count' instead.");

/**
 @abstract Get dictionary of all created/updated/deleted objects returned by BuiltDelta.
 
 @return Returns an dictionary of created/updated/deleted objects returned by BuiltDelta.
 @deprecated Use createdObjects, updatedObjects and deletedObjects instead.
 */
- (NSDictionary *)allObjects BUILTIO_DEPRECATED("Use createdObjects, updatedObjects and deletedObjects instead.");

@end
