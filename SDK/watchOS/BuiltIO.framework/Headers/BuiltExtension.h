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

@interface BuiltExtension : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 @abstract Makes a call to an extension function asynchronously.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltExtension *extensionObject = [builtApplication extensionWithName:@"hello"];
     [extensionObject executeWithData:@{@"name":@"Rohit"} completion:^(BuiltResponseType responseType, id responseObject, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var extensionObject:BuiltExtension = builtApplication.extensionWithName("hello")
     extensionObject.executeWithData(["name":"Rohit"]) { (responseType, responseObject, error) -> Void in
     
     }
 
 
 @param dataParameters any data that you want to pass to the function.
 @param completion this block will be called after network call if success `responseObject` will contain the response from the extension method or else nil. `error` object will contain error if any.
 
 */
- (void)executeWithData:(BUILT_NULLABLE NSDictionary *)dataParameters
                         completion:(void (^)(BuiltResponseType responseType, id BUILT_NULLABLE_P responseObject, NSError * BUILT_NULLABLE_P error))completionBlock;

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