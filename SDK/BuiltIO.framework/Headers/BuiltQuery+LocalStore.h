//
//  BuiltQuery+LocalStore.h
//  BuiltIO
//
//  Created by Reefaq on 10/09/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>

@interface BuiltQuery (LocalStore)

//MARK: - Offline
/**
 Fetch the objects from offline DB.
 
     //Assuming 'projectQuery' is a BuiltQuery instance
     
     //Obj-C
     [projectQuery offline];
     [projectQuery execInBackground:^(ResponseType type, QueryResult *result, NSError *error) {
        //objects is been fetched from offline db
     }];
     
     //Swift
     projectQuery.offline();
     projectQuery.execInBackground { (ResponseType, QueryResult!, NSError!) -> Void in
        //objects is been fetched from offline db
     }
 
 */
- (void)offline;


@end
