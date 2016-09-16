//
//  BuiltGroupMultiple.h
//  BuiltIO
//
//  Created by Reefaq on 02/06/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BuiltObject;
@class BuiltGroup;

/**
 A Group is special type of field in Built.io Backend. The reason its named such is that its a set of fields grouped together. Each group field has its own schema and can contain sub-groups. GroupMultiple should be used when a group field is marked as 'multiple'.
 */

@interface BuiltGroupMultiple : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 *  This should be used to represent a 'group field' which is marked as multiple in your class.
 *
 *  @param fieldName UID of the group field in your class schema
 *
 *  @return new BuiltGroupMultiple instance
 */
+ (instancetype) groupMultipleWithFieldName:(NSString*)fieldName;

/**
 *  Add Group to this object
 *
 *  @param group Instance of BuiltGroup for this object
 */
- (void)addGroup:(BuiltGroup*)group;

/**
 *  Removes Group to this object
 *
 *  @param group Instance of BuiltGroup to remove from this object
 */
- (void)removeGroup:(BuiltGroup*)group;

/**
 *  This should be used to mix array containing instances of BuiltGroup or BuiltGroupMultiple together.
 *
 *  @param groupsArray Array containing instance of BuiltGroup or BuiltGroupMultiple
 */
- (void)addByMixinGroups:(NSArray*)groupsArray;

/**
 Configure array with builtmultiple info.
 
     //Obj-C
     [groupMultipleObject configureWithArray:@[@{@"Key_name":@"MyValue"}]];
     
     //Swift
     groupMultipleObject.configureWithArray([["Key_name":"MyValue"]])
 
 
 @param dictionary User Info
 */
- (void)configureWithArray:(NSArray*)array;

/**
Get BuiltGroup object of the specified index.

@param index index of which BuiltGroup need to get.
@return BuiltGroup instance with data of specified index.
 */
- (BuiltGroup*)groupAtIndex:(NSInteger)index;


@end
