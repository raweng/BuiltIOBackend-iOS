//
//  BuiltClass.h
//  BuiltIO
//
//  Created by Gautam Lodhiya on 26/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@class BuiltObject;
@class BuiltQuery;
@class BuiltUserRoleMapper;

BUILT_ASSUME_NONNULL_BEGIN
/**
 *  A Class is a collection of objects.
 */
@interface BuiltClass : NSObject

/**
 To set extensionKey for the class.
 // 'blt5d4sample2633b' is a dummy Application API key
 
 //Obj-C
 BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
  BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
 projectClass.extensionKey = @"new_extension";
 
 //Swift
 var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
 var projectClass:BuiltClass = builtApplication.classWithUID("project")
 projectClass.extensionKey = "new_extension";
 
 */
@property (nonnull, nonatomic, strong) NSString *extensionKey;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

//MARK: - Headers
/**---------------------------------------------------------------------------------------
 * @name Headers
 *  ---------------------------------------------------------------------------------------
 */

/**
Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     [projectClass setHeader:@"MyValue" forKey:@"My_Custom_Header"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     projectClass.setHeader("MyValue", forKey:"My_Custom_Header")
 
@param headerValue The header key
@param headerKey   The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
Set a header for an application

     //'blt5d4sample2633b' is a dummy Application API key

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     [projectClass addHeadersWithDictionary:@{@"Custom_Key":@"Custom_Value"}];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     projectClass.addHeadersWithDictionary(["Custom_Key": "Custom_Value"])
 
@param headers The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
Removes a header from this application.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     [projectClass removeHeaderForKey:@"Custom_Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     projectClass.removeHeaderForKey("Custom_Key")
 
@param headerKey The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;

//MARK: - New Instance

/**---------------------------------------------------------------------------------------
 * @name BuiltObject Instance
 *  ---------------------------------------------------------------------------------------
 */

/**
Represents an Object of a class
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject = [projectClass object];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
 
 
@return Returns new BuiltObject instance
 */
- (BuiltObject *)object;

/**
Represents an Object of a class
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject = [projectClass  objectWithUID:@"blt73815f9c277d2d98"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.objectWithUID("blt73815f9c277d2d98")

@param uid Object UID
@return Returns new BuiltObject instance
 */
- (BuiltObject *)objectWithUID:(NSString *)uid;

/**---------------------------------------------------------------------------------------
 * @name BuiltQuery Instance
 *  ---------------------------------------------------------------------------------------
 */

/**
Represents a Query on 'Class' which can be executed to retrieve objects that pass the query condition
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *builtQuery = [projectClass query];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var builtQuery:BuiltQuery = projectClass.query()
 
@return Returns new BuiltQuery instance
 */
- (BuiltQuery *)query;


//MARK: - Info

/**---------------------------------------------------------------------------------------
 * @name Schema
 *  ---------------------------------------------------------------------------------------
 */

/**
Gets the schema of class asynchronously
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     [projectClass fetchSchema:^(BuiltResponseType responseType, NSArray *schema, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     projectClass.fetchSchema { (responseType, schema, error) -> Void in
     
     }
 
@param completionBlock Completion block with params (BuiltResponseType responseType, NSArray *schema, NSError *error)
 */
- (void)fetchSchema:(void (^)(BuiltResponseType responseType, NSArray * BUILT_NULLABLE_P schema, NSError * BUILT_NULLABLE_P error))completionBlock;

/**---------------------------------------------------------------------------------------
 * @name Cancel Network calls
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Advises the operation object that it should stop executing its task.
 @discussion This method does not force your operation code to stop. Instead, it updates the object’s internal flags to reflect the change in state. If the operation has already finished executing, this method has no effect. Canceling an operation that is currently in an operation queue, but not yet executing, makes it possible to remove the operation from the queue sooner than usual.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     [projectClass cancelRequests];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     projectClass.cancelRequests()
 
 */
- (void)cancelRequests;

@end

BUILT_ASSUME_NONNULL_END
