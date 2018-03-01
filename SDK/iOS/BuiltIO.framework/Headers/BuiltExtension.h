//
//  BuiltExtension.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

BUILT_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, BuiltRequestType) {
    BuiltRequestTypeGET,
    BuiltRequestTypePOST,
    BuiltRequestTypePUT,
    BuiltRequestTypeDELETE
};

@interface BuiltExtension : NSObject

/**
 Set parameter to pass in extension call 
 
 //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltExtension *extensionObject = [builtApplication extension];
    extensionObject.requestParams = @{@"name" : @"John"};
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var extensionObject:BuiltExtension = builtApplication.extension()
    extensionObject.requestParams = {"name" : "John"}

 */
@property (nonatomic, strong) NSDictionary* requestParams;


- (instancetype)init UNAVAILABLE_ATTRIBUTE;
//MARK: Execute -
/**---------------------------------------------------------------------------------------
 * @name execute
 *  ---------------------------------------------------------------------------------------
 */
/**
 @abstract Makes a call to an extension function asynchronously.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltExtension *extensionObject = [builtApplication extension];
     [extensionObject execute:^(BuiltResponseType responseType, id responseObject, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var extensionObject:BuiltExtension = builtApplication.extension()
     extensionObject.execute { (responseType, responseObject, error) -> Void in
     
     }
 
 
 @param dataParameters any data that you want to pass to the function.
 @param completion this block will be called after network call if success `responseObject` will contain the response from the extension method or else nil. `error` object will contain error if any.
 
*/
- (void)execute:(void (^)(BuiltResponseType responseType, id responseObject, NSError *error))completionBlock;

/**
 @abstract Makes a call to an extension function asynchronously.
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltExtension *extensionObject = [builtApplication extensionWithKey:@"new_extensionkey"];
    [extensionObject executeFunction:^(BuiltResponseType responseType, id responseObject, NSError *error) {
 
    }];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var extensionObject:BuiltExtension = builtApplication.extensionWithKey("new_extensionkey")
    extensionObject.executeFunction { (responseType, responseObject, error) -> Void in
 
 }
 
 @param completion this block will be called after network call if success `responseObject` will contain the response from the extension method or else nil. `error` object will contain error if any.
 
 */
- (void)executeFunction:(void (^)(BuiltResponseType responseType, id responseObject, NSError *error))completionBlock;

/**
 @abstract set request url and request type.
 
    //'blt5d4sample2633b' is a dummy Application API key
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltExtension *extensionObject = [builtApplication extensionWithKey:@"new_extensionkey"];
    [extensionObject setRequestURL:@"v1/person" withRequestType:BuiltRequestTypeGET];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var extensionObject:BuiltExtension = builtApplication.extensionWithKey("new_extensionkey")
    extensionObject.setRequestURL("v1/person", withRequestType:BuiltRequestTypeGET)
 
 @param requestURL url to make call
 @param requestType requestMethod by which we are making call (GET, POST, PUT, DELETE)

 
 */
-(void)setRequestURL:(NSString *)url withRequestType:(BuiltRequestType) requestType;


//MARK: Manually set headers -
/**---------------------------------------------------------------------------------------
 * @name Manually set headers
 *  ---------------------------------------------------------------------------------------
 */
/**
 Set a header for an application
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
    BuiltQuery *projectQuery = [projectClass query];
    [projectQuery setHeader:@"MyHeaderValue" forKey:@"My-Custom-Header-Key"];
 
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var projectClass:BuiltClass = builtApplication.classWithUID("project")
    var projectQuery:BuiltQuery = projectClass.query()
    projectQuery.setHeader("MyHeaderValue", forKey:"My-Custom-Header-Key")
 
 @param headerValue The header key
 @param headerKey   The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
 Set a header for an application
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
    BuiltQuery *projectQuery = [projectClass query];
    [projectQuery addHeadersWithDictionary:@{@"My-Custom-Header-Key":@"MyHeaderValue"}];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var projectClass:BuiltClass = builtApplication.classWithUID("project")
    var projectQuery:BuiltQuery = projectClass.query()
    projectQuery.addHeadersWithDictionary(["My-Custom-Header-Key":"MyHeaderValue"])
 
 
 @param headers The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
 Removes a header from this application.
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
    BuiltQuery *projectQuery = [projectClass query];
    [projectQuery removeHeaderForKey:@"My-Custom-Header-Key"];
 
    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var projectClass:BuiltClass = builtApplication.classWithUID("project")
    var projectQuery:BuiltQuery = projectClass.query()
    projectQuery.removeHeaderForKey("My-Custom-Header-Key")
 
 
 @param headerKey The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;

/**---------------------------------------------------------------------------------------
 * @name Cancel Network calls
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Cancel if any network operation is running.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltExtension *extensionObject = [builtApplication extensionWithName:@"hello"];
     [extensionObject cancelRequest];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var extensionObject:BuiltExtension = builtApplication.extensionWithName("hello")
     extensionObject.cancelRequest()
 
 */
- (void)cancelRequest;
@end

BUILT_ASSUME_NONNULL_END
