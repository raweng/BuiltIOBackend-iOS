//
//  BuiltGroupMultiple.h
//  BuiltIO
//
//  Created by Reefaq on 02/06/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@class BuiltObject;
@class BuiltGroup;
NS_CLASS_DEPRECATED(10,10_6,4_0,5_0)
BUILT_ASSUME_NONNULL_BEGIN
/**
 @note This class has been deprecated.
 
 A Group is special type of field in Built.io Backend. The reason its named such is that its a set of fields grouped together. Each group field has its own schema and can contain sub-groups. GroupMultiple should be used when a group field is marked as 'multiple'.
 */

@interface BuiltGroupMultiple : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**---------------------------------------------------------------------------------------
 * @name Static Instance
 *  ---------------------------------------------------------------------------------------
 */

/**
 *  This should be used to represent a 'group field' which is marked as multiple in your class.
 *
 *  @param fieldName UID of the group field in your class schema
 *
 *  @return new BuiltGroupMultiple instance
 *  @warning This method has been deprecated.
 */
+ (instancetype) groupMultipleWithFieldName:(NSString*)fieldName;

/**---------------------------------------------------------------------------------------
 * @name Add/Remove Group
 *  ---------------------------------------------------------------------------------------
 */

/**
 *  Add Group to this object
 *
 *  @param group Instance of BuiltGroup for this object
 *  @warning This method has been deprecated.
 */
- (void)addGroup:(BuiltGroup*)group;

/**
 *  Removes Group to this object
 *
 *  @param group Instance of BuiltGroup to remove from this object
 *  @warning This method has been deprecated.
 */
- (void)removeGroup:(BuiltGroup*)group;

/**---------------------------------------------------------------------------------------
 * @name Mix Groups
 *  ---------------------------------------------------------------------------------------
 */

/**
 *  This should be used to mix array containing instances of BuiltGroup or BuiltGroupMultiple together.
 *
 *  @param groupsArray Array containing instance of BuiltGroup or BuiltGroupMultiple
 *  @warning This method has been deprecated.
 */
- (void)addByMixinGroups:(NSArray*)groupsArray;

/**---------------------------------------------------------------------------------------
 * @name Configure
 *  ---------------------------------------------------------------------------------------
 */

/**
 Configure array with builtmultiple info.
 
     //Obj-C
     [groupMultipleObject configureWithArray:@[@{@"Key_name":@"MyValue"}]];
     
     //Swift
     groupMultipleObject.configureWithArray([["Key_name":"MyValue"]])
 
 
 @param dictionary User Info
 @warning This method has been deprecated.
 */
- (void)configureWithArray:(NSArray*)array;

/**---------------------------------------------------------------------------------------
 * @name Get Group by index
 *  ---------------------------------------------------------------------------------------
 */

/**
Get BuiltGroup object of the specified index.

@param index index of which BuiltGroup need to get.
@return BuiltGroup instance with data of specified index.
@warning This method has been deprecated.
 */
- (BuiltGroup*)groupAtIndex:(NSInteger)index;

@end

BUILT_ASSUME_NONNULL_END
