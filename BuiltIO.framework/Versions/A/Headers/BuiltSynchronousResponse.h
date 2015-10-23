//
//  BuiltResponse.h
//  BuiltIO
//
//  Created by Gautam Lodhiya on 13/01/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@interface BuiltSynchronousResponse : NSObject
/**
Response type i.e NETWORK or CACHE
 
     //Obj-C
     BuiltSynchronousResponse *builtSyncResponse = [projectQuery exec:error];
     ResponseType responseType = builtSyncResponse.responseType
     
     //Swift
     var builtSyncResponse:BuiltSynchronousResponse = projectQuery.exec(error)
     var responseType:ResponseType = builtSyncResponse.responseType
 
 */
@property (nonatomic, readonly) ResponseType responseType;

/**
Response json data as NSDictionary or NSArray
 
     //Obj-C
     NSError *error;
     BuiltSynchronousResponse *builtSyncResponse = [projectQuery exec:error];
     QueryResult *projectQueryResult = builtSyncResponse.responseData; // for query
 
     
     //Swift
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = projectQuery.exec(error)
     var projectQueryResult:QueryResult = builtSyncResponse.responseData // for query
 
 */
@property (nonatomic, strong, readonly) id responseData;
@end
