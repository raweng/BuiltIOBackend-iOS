//
//  BuiltQueryResult.h
//  BuiltIO
//
//  Created by Reefaq on 30/10/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltQueryResult : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 @abstract Get array of objects returned by BuiltQuery.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
        NSArray *result = [result getResult];// get all result in array
     }];
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
        var results:Array  =  queryResult.getResult()
     }
 
 @return Returns an array of objects returned by BuiltQuery.
 */
- (BUILT_NULLABLE NSArray *)getResult;


/**
 @abstract Get array of roles returned by BuiltQuery.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
        NSArray *result = [result getRoles];// get all result in array
     }];
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
        var results:Array  =  queryResult.getRoles()
     }
 
 @return Returns an array of roles returned by BuiltQuery.
 */
- (BUILT_NULLABLE NSArray *)getRoles;

/**
 @abstract Get array of users returned by BuiltQuery.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
        NSArray *result = [result getUsers];// get all result in array
     }];
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
        var results:Array  =  queryResult.getUsers()
     }
 
 @return Returns an array of users returned by BuiltQuery.
 */
- (BUILT_NULLABLE NSArray *)getUsers;

/**
 @abstract Gets the schema of objects returned by BuiltQuery alongwith objects themselves.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
        NSArray *result = [result schema];
     }];
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
        var schema:Array  =  queryResult.schema()
     }
 
 @return Returns schemas.
 */
- (BUILT_NULLABLE NSArray *)schema;

/**
 @abstract Count of number of object returned by BuiltQuery.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
        NSInteger count = [result count];
     }];
     
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
        var count:Int  =  queryResult.count()
     }
     
 
 @return Returns the count of number of object returned by BuiltQuery.
 */
- (NSInteger)count;

/**
 @abstract Get array of updated objects returned by BuiltDelta.
 
     Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
        NSArray *updatedObject = [result updatedObjects];
     }];
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
        var updatedObject:Array  =  queryResult.updatedObjects()
     }
 
 @return Returns an array of updated objects returned by BuiltDelta.
 */
- (BUILT_NULLABLE NSArray *)updatedObjects;


/**
 @abstract Get array of created objects returned by BuiltDelta.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
         NSArray *createdObject = [result createdObjects];
     }];
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
         var createdObject:Array  =  queryResult.createdObjects()
     }
 
 
 @return Returns an array of created objects returned by BuiltDelta.
 */
- (BUILT_NULLABLE NSArray *)createdObjects;


/**
 @abstract Get array of deleted objects returned by BuiltDelta.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
         NSArray *deletedObject = [result deletedObjects];
     }];
     
     //Swift
     projectQuery.exec { (responseType, queryResult!, error!) -> Void in
         var deletedObject:Array  =  queryResult.deletedObjects()
     }
 
 @return Returns an array of deleted objects returned by BuiltDelta.
 */
- (BUILT_NULLABLE NSArray *)deletedObjects;

@end

BUILT_ASSUME_NONNULL_END
