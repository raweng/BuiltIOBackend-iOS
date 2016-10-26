//
//  BuiltUpload.h
//  BuiltIO
//
//  Created by Reefaq on 29/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BuiltDefinitions.h"

@class BuiltACL;
@class BuiltApplication;

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltUpload : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
/**----------------------------------------------------------------------------------------
 * @name Properties
 *-----------------------------------------------------------------------------------------
 */
/**
 @abstract the filename of the uploaded file
 
     //assuming 'uploadObject' is BuiltUpload instance
 
     //Obj-C
     NSString *uploadedFileName = uploadObject.fileName;
     
     //Swift
     var uploadedFileName:String = uploadObject.fileName
 
 */
@property (nonatomic, copy, readonly) NSString *fileName;

/**
 @abstract the filesize of the uploaded file
 
     //assuming 'uploadObject' is BuiltUpload instance
 
     //Obj-C
     unsigned int fileSize = uploadObject.filesize;
     
     //Swift
     var fileSize:UInt32 = uploadObject.filesize
 
 */
@property (nonatomic, assign, readonly) unsigned int filesize;

/**
 @abstract the contentType of the uploaded file
 
     //assuming 'uploadObject' is BuiltUpload instance
    
     //Obj-C
     NSString *contentType = [uploadObject contentType];
     
     //Swift
     var contentType:String = uploadObject.contentType
 
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/**
 @abstract the uid of the uploaded file
 
     //assuming 'uploadObject' is BuiltUpload instance
 
     //Obj-C
     NSString *uploadedFileUID = [uploadObject uid];
     
     //Swift
     var uploadedFileUID:String = uploadObject.uid
 
 */
@property (nonatomic, copy, readonly) NSString *uid;

/**
 @abstract the tags associated with the uploaded file

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
 
     //setting tags
     uploadObject.tags = @[@"pic", @"photo"];
 
     //getting tags
     NSArray *tagFileArray = [uploadObject tags];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     
     //setting tags
     uploadObject.tags = ["pic", "photo"]
 
     //getting tags
     var tagFileArray:AnyObject! = uploadObject.tags
 
 */
@property (nullable, nonatomic, copy) NSArray *tags;

/**
 @abstract the ACL applied to the uploaded file
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     BuiltACL *acl = [uploadObject ACL];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     var acl:BuiltACL = uploadObject.ACL
 
 */
@property (nonatomic, strong) BuiltACL *ACL;

/**
 @abstract the url of the uploaded file
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     NSString *profileImageURL = [uploadObject url];
     
     //Swift
     var profileImageURL:String = uploadObject.url
 
 */
@property (nonatomic, copy, readonly) NSString *url;

/**
 @abstract enable/disable file cache
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     
     //to set value
     uploadObject.enableCache = YES;
 
     //to check value
     if ([uploadObject isCachingEnabled]) {
        //caching is enabled
     } else {
        //caching is disabled
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
 
     //to set value
     uploadObject.enableCache = true
 
     //to check value
     if (uploadObject.isCachingEnabled()) {
        //caching is enabled
     } else {
        //caching is disabled
     }
 
 */
@property (nonatomic, assign, getter=isCachingEnabled) BOOL enableCache;

/**---------------------------------------------------------------------------------------
 * @name Attaching/Removing Headers.
 *  ---------------------------------------------------------------------------------------
 */
/**
 @abstract Additional headers if required
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject setHeader:@"MyHeaderValue" forKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.setHeader("MyHeaderValue", forKey:"My-Custom-Header-Key")
 
 @param header header value
 @param key header key
 */
- (void)setHeader:(NSString *)header forKey:(NSString *)key;

/**
 
@abstract Remove a header for a specific key
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject removeHeaderForKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.removeHeaderForKey("My-Custom-Header-Key")

@param key Key for which to remove the header value

 */
- (void)removeHeaderForKey:(NSString *)key;

/**--------------------------------------------------------------------------------------
 @name Add file/data/image for uploading
 -----------------------------------------------------------------------------------------
 */

/**
 
@abstract set file to be uploaded

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     NSString *imageFilePath = [[NSBundle mainBundle] pathForResource:@"profileimage" ofType:@"png"];
     [uploadObject setFilepath:imageFilePath withFileName:@"profile"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     var imageFilePath:NSString = NSBundle.mainBundle().pathForResource("profileimage", ofType: "png")
     uploadObject.setFilepath(imageFilePath, withFileName:"profile")

@param filePath path of the file from NSBundle
@param key add file against a key.

 */
- (void)setFilepath:(NSString *)filePath withFileName:(NSString *)key;


/**
 
 @abstract set data of file to be uploaded
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     NSString *imageFilePath = [[NSBundle mainBundle] pathForResource:@"profileimage" ofType:@"png"];
     NSData *myData = [NSData dataWithContentsOfFile:imageFilePath];
     [uploadObject setData:myData forKey:@"profile"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     var imageFilePath:NSString = NSBundle.mainBundle().pathForResource("profileimage", ofType: "png")
     var myData = NSData(contentsOfFile:imageFilePath)
     uploadObject.setData(myData, forKey:"profile")

@param data `NSData` representation of any object to be uploaded
@param key add data against a key.

 */
- (void)setData:(NSData *)data forKey:(NSString *)key;


/**
Accepts NSDictionary insance as parameter to configure upload object.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject configureWithDictionary:@{@"my property":@"property_key", @"my property":@"property_key"}];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.configureWithDictionary(["my property":"property_key", "my property":"property_key"])

 @param dictionary json response data to configure
 */
- (void)configureWithDictionary:(NSDictionary *)dictionary;


/**
 @abstract set image file to be uploaded
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     UIImage *image = [UIImage imageNamed:@"profileimage"];
     [uploadObject setImage:image forKey:@"profile"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     var image = UIImage(named:"profileimage")
     uploadObject.setImage(image, forKey:"profile")

 @param image `UIImage` object to be uploaded
 @param key add image against a key.

 */
- (void)setImage:(UIImage *)image forKey:(NSString *)key;

/**
 @abstract remove attacted file for upload.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject removeAttachedFile];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.removeAttachedFile()
 
 */
- (void)removeAttachedFile;

/**---------------------------------------------------------------------------------------
 * @name Save files with Built.io Backend
 *  ---------------------------------------------------------------------------------------
 */


/**
 @abstract Upload one or more images/files to Built.io Backend asynchronously.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject save:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.save { (responseType, error) -> Void in
 
     }

 @param successBlock callback when the file is successfully uploaded.
 @param errorBlock CallBack in case of failure.
 @param finalBlock finalBlock to be always executed eventually.

 }
 
 */
- (void)save:(BuiltRequestCompletionHandler)completionBlock;


/**
 @abstract Deletes the upload with specified UID asynchronously.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject destroy:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.destroy { (responseType, error) -> Void in
     
     }
 
 @param completionBlock callBack in case of success/error.
 */
- (void)destroy:(BuiltRequestCompletionHandler)completionBlock;


/**
 @abstract Fetches a file asynchronously when provided UID.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject fetch:^(BuiltResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.fetch { (responseType, error) -> Void in
     
     }

 @param successBlock CallBack in case of success.
 @param errorBlock CallBack in case of failure.
 @param finalBlock finalBlock to be always executed eventually.

 */
- (void)fetch:(BuiltRequestCompletionHandler)completionBlock;


/**
 @abstract if an upload contains an image, use this method to download the image asynchronously.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject downloadImage:^(BuiltResponseType responseType, UIImage *image, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.downloadImage { (responseType, image, error) -> Void in
     
     }
 
 @param successBlock on successful download, the success block contains the UIImage object.
 @param errorBlock in case of errors, this block is called.
 */
//#if TARGET_OS_IPHONE
- (void)downloadImage:(void (^)(BuiltResponseType responseType, UIImage * BUILT_NULLABLE_P image, NSError * BUILT_NULLABLE_P error))completionBlock;
//#elif TARGET_OS_MAC
//- (void)downloadImageOnCompletion:(void (^)(BuiltResponseType responseType, NSImage *image, NSError *error))completionBlock;
//#endif

/**
 @abstract if an upload contains a file other than image, use this method to download the file asynchronously.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject downloadData:^(BuiltResponseType responseType, NSData *data, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.downloadData { (responseType, data, error) -> Void in
 
 }
 
 @param completionBlock on successful download, the data param will contain NSData object.
 */
- (void)downloadData:(void (^)(BuiltResponseType responseType, NSData * BUILT_NULLABLE_P data, NSError * BUILT_NULLABLE_P error))completionBlock;


/** --------------------------------------------------------------------------------------
 @name Cancel
 -----------------------------------------------------------------------------------------
 */
/**
 @abstract cancel ongoing file uploading network requests
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltUpload *uploadObject = [builtApplication upload];
     [uploadObject cancel];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var uploadObject:BuiltUpload = builtApplication.upload()
     uploadObject.cancel()
 
 */
- (void)cancel;

@end

BUILT_ASSUME_NONNULL_END
