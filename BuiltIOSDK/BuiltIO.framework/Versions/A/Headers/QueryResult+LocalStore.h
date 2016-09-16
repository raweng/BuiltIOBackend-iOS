//
//  QueryResult+LocalStore.h
//  BuiltIO
//
//  Created by Reefaq on 09/09/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <BuiltIO/BuiltIO.h>

@interface QueryResult (LocalStore)

//MARK: - Hook
- (void)hook;
- (void)hookWithName:(NSString*)hookName;

//MARK: - UnHook
- (void)unHook;
- (void)unHookWithName:(NSString*)hookName;

@end
