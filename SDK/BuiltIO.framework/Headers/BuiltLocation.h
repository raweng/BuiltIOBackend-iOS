//
//  BuiltLocation.h
//  BuiltIO
//
//  Created by Reefaq on 09/10/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Location represents a geological location.
 */
@interface BuiltLocation : NSObject

/**
Longitude of the location in degrees
 
     //Obj-C
     BuiltLocation *locationObject = [BuiltLocation locationWithLongitude:19.48571 andLatitude:72.04571];
     double longitude = locationObject.longitude;
     
     //Swift
     var locationObject:BuiltLocation = BuiltLocation(longitude:19.48571, andLatitude:72.04571)
     locationObject.longitude
 
 */
@property (nonatomic, assign) double longitude;

/**
Latitude of the location in degrees
 
     //Obj-C
     BuiltLocation *locationObject = [BuiltLocation locationWithLongitude:19.48571 andLatitude:72.04571];
     double latitude = locationObject.latitude;
     
     //Swift
     var locationObject:BuiltLocation = BuiltLocation(longitude:19.48571, andLatitude:72.04571)
     locationObject.latitude
 
 */
@property (nonatomic, assign) double latitude;


- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
Returns a `BuiltLocation` object for the given longitude and latitude
 
     //Obj-C
     BuiltLocation *locationObject = [BuiltLocation locationWithLongitude:19.48571 andLatitude:72.04571];
     
     
     //Swift
     var locationObject:BuiltLocation = BuiltLocation(longitude:19.48571, andLatitude:72.04571)
 
 
@param longitude longitude of the location in degrees
@param latitude latitude of the location in degrees
@return `BuiltLocation` object with the given longitude and latitude
 */
+ (BuiltLocation *)locationWithLongitude:(double)longitude andLatitude:(double)latitude;

/**
Gets the current location and returns as in `BuiltLocation` object.
 
     //Obj-C
     [BuiltLocation currentLocationOnCompletion:^(BuiltLocation *currentLocation, NSError *error) {
         double latitude = currentLocation.latitude;
         double longitude = currentLocation.longitude;
     }];
     
     //Swift
     BuiltLocation.currentLocationOnCompletion { (BuiltLocation!, NSError!) -> Void in
         var latitude:Double = BuiltLocation.latitude
         var longitude:Double = BuiltLocation.longitude
     }
 
@param successBlock will have the `BuiltLocation` object with current longitude and latitude.
@param errorBlock will have an `NSError` object in case the current location was not available.
 */
+ (void)currentLocationOnCompletion:(void (^) (BuiltLocation *currentLocation, NSError *error))completionBlock;

@end
