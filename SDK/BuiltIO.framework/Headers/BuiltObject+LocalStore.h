//
//  BuiltObject+LocalStore.h
//  BuiltIO
//
//  Created by Reefaq on 09/09/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>

@interface BuiltObject (LocalStore)

//MARK: - Offline
/**
 Fetch the object from offline DB.
 
    //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     [projectObject offline];
     [projectObject fetchInBackgroundWithCompletion:^(ResponseType responseType, BuiltObject *object, NSError *error) {
        //object is been fetched from offline db
     }];
     
     //Swift
     projectObject.offline();
     projectObject.fetchInBackgroundWithCompletion { (ResponseType, BuiltObject!, NSError!) -> Void in
        //object is been fetched from offline db
     }
 
 */
- (void)offline;

@end
