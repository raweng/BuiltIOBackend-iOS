//
//  BuiltDetailViewController.h
//  builtDemo
//
//  Created by Reefaq on 10/03/13.
//  Copyright (c) 2013 raweng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BuiltDefinitions.h"

@class BuiltClass, BuiltObject, BuiltApplication;

/**---------------------------------------------------------------------------------------
 *  Sub-class of UIViewController with support of BuiltIO SDK
 *  ---------------------------------------------------------------------------------------
 */
@interface BuiltUIDetailViewController : UIViewController

/**
 @abstract The application to which we should point to.
 */
@property (nonatomic, strong, readonly) BuiltApplication *builtApplication;

/**
 @abstract Built-Class-UID of which object UID is set.
 */
@property (nonatomic, copy, readonly) NSString* classUID;

/**
 @abstract Built-Object-UID which need to be fetched.
 */
@property (nonatomic, copy, readonly) NSString* objectUID;

/**
 @abstract Built-Object which is fetched according to objectUID set.
 */
@property (nonatomic, readonly) BuiltObject *builtObject;

/**
 *  Usual init of UIViewController with BuiltClass insantance and objectUID to fetch detail.
 *
 *  @param nibNameOrNil   nib name to load nib if present or else nil
 *  @param nibBundleOrNil buldle where nib is situated or else nil
 *  @param builtClass     BuiltClass instance of which object need to fetch.
 *  @param objectUID      UID of object which need to fetch.
 *
 *  @return UIViewControler instance
 */
- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil builtClass:(BuiltClass*)builtClass objectUID:(NSString*)objectUID;

/**
 @abstract called before whenever a network request is initialed.
 */
- (void)networkWillStartLoad;

/**
 @abstract called after a network request is finished.
 @param error An Error if network call fails else nil.
 */
- (void)networkDidFinishLoad:(NSError *)error;

@end
