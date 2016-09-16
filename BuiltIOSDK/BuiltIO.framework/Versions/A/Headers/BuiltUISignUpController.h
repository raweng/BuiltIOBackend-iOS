//
//  BuiltUISignUpController.h
//  builtDemo
//
//  Created by Reefaq on 13/03/13.
//  Copyright (c) 2013 raweng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BuiltDefinitions.h"

@class BuiltACL, BuiltApplication;

/** SignUp View Controller */
@interface BuiltUISignUpController : UIViewController

/**
 @abstract The application to which we should point to.
 */
@property (nonatomic, strong) BuiltApplication *builtApplication;

/**
 @abstract this is the logo for the app. The default logo is for Built.io Backend.
 */
@property (nonatomic, strong, readonly) UIImageView* logoImageView;

/**
 @abstract ACL that will be set to the user signing up.
 @param ACL The ACL for the object.
 */
- (void)setACL:(BuiltACL *)ACL;

@end
