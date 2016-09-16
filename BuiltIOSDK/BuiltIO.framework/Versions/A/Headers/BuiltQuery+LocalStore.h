//
//  BuiltQuery+LocalStore.h
//  BuiltIO
//
//  Created by Reefaq on 10/09/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>

@interface BuiltQuery (LocalStore)

//HOOK
/**
 *  Will fetch the result form local database with default hook name
 */
- (void)fromHook;

/**
 *  Will fetch the result form local database with objects specified hook name
 *
 *  @param hookName name of the hook
 */
- (void)fromHookWithName:(NSString*)hookName;

@end
