//
//  QueryResult.h
//  BuiltIO
//
//  Created by Reefaq on 30/10/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface QueryResult : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 @abstract Get array of objects returned by BuiltQuery.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSArray *result = [result getResult];// get all result in array
     }];
     
     //Swift
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var results:Array  =  QueryResult.getResult()
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
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var results:Array  =  QueryResult.getRoles()
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
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var results:Array  =  QueryResult.getUsers()
     }
 
 @return Returns an array of users returned by BuiltQuery.
 */
- (NSArray *)getUsers;

/**
 @abstract Count of number of object returned by BuiltQuery alongwith objects themselves.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSInteger totalCount = [result totalCount];// totalcount
     }];
     
     
     //Swift
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var total:Int  =  QueryResult.totalCount()
     }
 
 @return Returns the count of number of object returned by BuiltQuery.
 */
- (NSInteger)totalCount;


/**
 @abstract Gets the schema of objects returned by BuiltQuery alongwith objects themselves.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSArray *result = [result schema];
     }];
     
     //Swift
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var schema:Array  =  QueryResult.schema()
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
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var count:Int  =  QueryResult.count()
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
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var updatedObject:Array  =  QueryResult.updatedObjects()
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
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var createdObject:Array  =  QueryResult.createdObjects()
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
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var deletedObject:Array  =  QueryResult.deletedObjects()
     }
 
 @return Returns an array of deleted objects returned by BuiltDelta.
 */
- (NSArray *)deletedObjects;


/**
 @abstract Get dictionary of all created/updated/deleted objects returned by BuiltDelta.
 
     //Obj-C
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        NSDictionary *allObject = [result allObjects];
     }];
     
     //Swift
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        var allObject:Dictionary  =  QueryResult.allObjects()
     }
 
 @return Returns an dictionary of created/updated/deleted objects returned by BuiltDelta.
 */
- (NSDictionary *)allObjects;

@end
