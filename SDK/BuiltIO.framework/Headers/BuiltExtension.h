//
//  BuiltExtension.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@class BuiltSynchronousResponse;

@interface BuiltExtension : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 @abstract Makes a call to an extension function synchronously.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltExtension *extensionObject = [builtApplication extensionWithName:@"hello"];
     NSError *error;
     BuiltSynchronousResponse *builtSyncResponse = [extensionObject executeWithData:@{@"name":@"Rohit"} error:&error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var extensionObject:BuiltExtension = builtApplication.extensionWithName("hello")
     let error:NSError
     var  builtSyncResponse:BuiltSynchronousResponse = extensionObject.executeWithData(["name":"Rohit"], error:error)

 @param dataParameters any data that you want to pass to the function
 @param Pointer to an NSError that will be set if necessary.
 @return Returns BuiltSynchronousResponse wrapper comprising response type (cache or network) and response data from the extension method or else nil. This result could be a NSDictionary, an NSArray, NSNumber or NSString.
 @deprecated Synchronous methods is been deprecated.

 */
- (BuiltSynchronousResponse *)executeWithData:(NSDictionary *)dataParameters error:(NSError **)error  BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
 @abstract Makes a call to an extension function asynchronously.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltExtension *extensionObject = [builtApplication extensionWithName:@"hello"];
     [extensionObject executeInBackgroundWithData:@{@"name":@"Rohit"} completion:^(ResponseType responseType, id responseObject, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var extensionObject:BuiltExtension = builtApplication.extensionWithName("hello")
     extensionObject.executeInBackgroundWithData(["name":"Rohit"]) { (responseType, responseObject, error) -> Void in
     
     }
 
 
 @param dataParameters any data that you want to pass to the function.
 @param completion this block will be called after network call if success `responseObject` will contain the response from the extension method or else nil. `error` object will contain error if any.
 
 */
- (void)executeInBackgroundWithData:(NSDictionary *)dataParameters
                         completion:(void (^)(ResponseType responseType, id responseObject, NSError *error))completionBlock;

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
