//
//  BuiltObject+LocalStore.h
//  BuiltIO
//
//  Created by Reefaq on 09/09/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#if !TARGET_OS_WATCH
#import <BuiltIO/BuiltIO.h>

BUILT_ASSUME_NONNULL_BEGIN

@interface BuiltObject (LocalStore)

//MARK: - Offline
/**
 Fetch the object from offline DB.
 
    //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     [projectObject offline];
     [projectObject fetch:^(BuiltResponseType responseType, BuiltObject *object, NSError *error) {
        //object is been fetched from offline db
     }];
     
     //Swift
     projectObject.offline();
     projectObject.fetch { (responseType, object!, error!) -> Void in
        //object is been fetched from offline db
     }
 
 @warning Not supported in watchOS
 */
- (void)offline;

@end

BUILT_ASSUME_NONNULL_END

#endif