//
//  BuiltGroup.h
//  BuiltIO
//
//  Created by Reefaq on 02/06/15.
//  Copyright (c) 2015 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BuiltObject;
@class BuiltGroupMultiple;

/*
 A Group is special type of field in Built.io Backend. The reason its named such is that its a set of fields grouped together. Each group field has its own schema and can contain sub-groups.
 */

@interface BuiltGroup : NSObject

/**
This should be used to represent a 'group field' in your class.
 
     //ObjC
     BuiltGroup *detailGroup = [BuiltGroup groupWithFieldName:@"details"];
     
     //Swift
     var detailGroup:BuiltGroup = BuiltGroup(fieldName:"details")

@param fieldName UID of the group field in your class schema
@return new BuiltGroup instance
 */
+ (instancetype) groupWithFieldName:(NSString*)fieldName;


/**
This should be used to represent a 'group field' in your class.
 
     //ObjC
     BuiltGroup *step = [BuiltGroup group];
     
     //Swift
     var step:BuiltGroup = BuiltGroup()

@return new BuiltGroup instance without field name associated.
 */
+ (instancetype) group;


/**
 Gets the data for given property.
 
     //Assuming 'detailGroup' is a BuiltGroup instance
     
     //Obj-C
     id object = [detailGroup objectForKey:@"key"];
     
     //Swift
     var object = detailGroup.objectForKey("key")
 
 
 @param key The object's property
 @return The value for the key provided
 */
- (id)objectForKey:(NSString *)key;

/**
Sets a value for a key defined.

     //Assuming 'detailGroup' is a BuiltGroup instance
     
     //Obj-C
     [detailGroup setObject:@"value" forKey:@"key"];
     
     //Swift
     detailGroup.setObject("value", forKey:"key")

@param object object to set
@param key    key to assign on.
 */
- (void)setObject:(id)object forKey:(NSString*)key;

/**
Add Group to this object
 
     //Assuming 'detailGroup' and 'innerGroup' is a BuiltGroup instance and 'innerGroup' is a group inside detail group.
     
     //ObjC
     [detailGroup addGroup:innerGroup];
     
     //Swift
     detailGroup.addGroup(innerGroup)
 
@param group Instance of BuiltGroup for this object
 */
- (void)addGroup:(BuiltGroup*)group;

/**
Removes Group to this object if present.

     //Assuming 'detailGroup' and 'innerGroup' is a BuiltGroup instance
     
     //ObjC
     [detailGroup removeGroup:innerGroup];
     
     //Swift
     detailGroup.removeGroup(innerGroup)

 
@param group Instance of BuiltGroup to remove from this object
 */
- (void)removeGroup:(BuiltGroup*)group;

/**
Add GroupMultiple to this object
 
     //Assuming 'detailGroup' is a BuiltGroup instance
     //Assuming 'stepsGroup' is a BuiltGroupMultiple instance
     
     //ObjC
     [detailGroup addGroupMultiple:stepsGroup];
     
     //Swift
     detailGroup.addGroupMultiple(stepsGroup)


@param group Instance of BuiltGroupMultiple for this object
 */
- (void)addGroupMultiple:(BuiltGroupMultiple*)group;

/**
Removes GroupMultiple to this object
 
     //Assuming 'detailGroup' is a BuiltGroup instance
     //Assuming 'stepsGroup' is a BuiltGroupMultiple instance
     
     //ObjC
     [detailGroup removeGroupMultiple:stepsGroup];
     
     //Swift
     detailGroup.removeGroupMultiple(stepsGroup)

@param group Instance of BuiltGroupMultiple for this object
 */
- (void)removeGroupMultiple:(BuiltGroupMultiple*)group;


//MARK: - set values for reference fields
/**
Assigns a set references to a reference field of an object.
 
     //Obj-C
     BuiltGroup *detailGroup  = [BuiltGroup groupWithFieldName:@"details"];
     // setting the project reference
     [detailGroup setReference:@"bltb6202sample73a1" forKey:@"project"];
     
     //Swift
     var detailGroup:BuiltGroup = BuiltGroup(fieldName:"details")
     // setting the project reference
     detailGroup.setReference("bltb6202sample73a1", forKey:"project")


@param reference This can either be a UID of a referenced object or array of UIDs of a referenced objects.
@param key       The uid of the reference field
 */
- (void)setReference:(id)reference forKey:(NSString *)key;

/**
Fires a query on Built.io Backend and all the objects which pass the query condition are being assigned to the reference field.

     //Obj-C
     BuiltGroup *detailGroup  = [BuiltGroup groupWithFieldName:@"details"];
     // setting the project reference
     [detailGroup setReferenceWhere:@{@"name":@"Super Project #41!"} forKey:@"project"];
 
     //Swift
     var detailGroup:BuiltGroup = BuiltGroup(fieldName:"details")
     // setting the project reference
     detailGroup.setReferenceWhere(["name":"Super Project #41!"], forKey:"project")
 
@param dictionary Object specifying the conditions
@param key        The uid of the reference field
 */
- (void)setReferenceWhere:(NSDictionary *)dictionary forKey:(NSString *)key;

/**
Assigns a set references to a reference field of an object.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     
     BuiltGroup *detailGroup  = [BuiltGroup groupWithFieldName:@"details"];
     // setting the project reference
     [detailGroup setReferenceWithObject:projectObject forKey:@"project"];
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     
     var detailGroup:BuiltGroup = BuiltGroup(fieldName:"details")
     // setting the project reference
     detailGroup.setReferenceWithObject(projectObject, forKey:"project")
 
@param referenceObject This can either an instance of BuiltObject or array of BuiltObject instance.
@param key             The uid of the reference field
 */
- (void)setReferenceWithObject:(id)referenceObject forKey:(NSString *)key;

/**
Use this method only when the values of the fields inside referenced object are to be changed while creating a new object.
 
     //ObjC
     BuiltGroup *detailGroup = [BuiltGroup groupWithFieldName:@"details"];
 
     [detailGroup addUpsertForReferenceField:@"project" condition:@{@"name":@"Super Project #41"} replaceWith:@{@"name":@"Super Project A", @"description":@"New project"}];
 
     //Swift
     var detailGroup:BuiltGroup = BuiltGroup(fieldName:"details")
 
     detailGroup.addUpsertForReferenceField("project", condition:["name":"Super Project #41"], replaceWith:["name":"Super Project A", "description":"New project"])
 
 
@param referenceField      Reference uid on which UPSERT is to be performed
@param conditionDictionary A check will be performed, whether any object has the key value pair(s) supplied in the dictionary in the reference field
@param replaceDictionary   New key value pairs for the fields inside the referenced object
 */
- (void)addUpsertForReferenceField:(NSString *)referenceField condition:(NSDictionary *)conditionDictionary replaceWith:(NSDictionary *)replaceDictionary;


//MARK: - operations on fields of multiple type

/**
 Appends a value in the given field.(Applies only to fields that allow multiple values)
 
     //Obj-C
     [detailGroup pushValue:"will come at front" forKey:@"steps"];
     
     //Swift
     detailGroup.pushValue("will come at front", forKey:"steps")
 
 
 @param value Value to be pushed
 @param key   Uid of field
 */
- (void)pushValue:(id)value forKey:(NSString *)key;

/**
 Pushes a value at a specified index in the given field(Applies only to fields that allow multiple values)
 
     //Obj-C
     [detailGroup pushValue:"will come at front" atIndex:0 forKey:@"steps"];
     
     //Swift
     detailGroup.pushValue("will come at front", atIndex:0, forKey:"steps")
 
 
 @param value Value to be pushed
 @param index Index at which value should be pushed
 @param key   Uid of field
 */
- (void)pushValue:(id)value atIndex:(NSInteger)index forKey:(NSString *)key;

/**
 For the given field, it deletes the first matched value.(Applies only to fields that allow multiple values)
 
     //Obj-C
     [detailGroup pullValue:@"will come at front" forKey:@"steps"];
     
     //Swift
     detailGroup.pullValue("will come at front", forKey:"steps")
 
 @param value Values to be deleted
 @param key   Uid of field
 */
- (void)pullValue:(id)value forKey:(NSString *)key;

/**
 For the given field, it deletes the value at a given index.(Applies only to fields that allow multiple values)
 
     //Obj-C
     [detailGroup pullValueAtIndex:0 forKey:@"steps"];
     
     //Swift
     detailGroup.pullValueAtIndex(0, forKey:"steps")
 
 @param index Index at which the value should be deleted
 @param key   Uid of field
 */
- (void)pullValueAtIndex:(NSInteger)index forKey:(NSString *)key;

/**
 A value in a field that allows multiple values
        
    //considering 'name' is a multi field under a group
 
     //Obj-C
     [detailGroup updateValue:@"Go to top right corner" atIndex:0 forKey:@"name"];
     
     //Swift
     detailGroup.updateValue("Go to top right corner", atIndex: 0, forKey:"name")
 
 @param updatedValue New value to be updated
 @param index        Index at which the value is to be updated
 @param key          Uid of field
 */
- (void)updateValue:(id)updatedValue atIndex:(NSInteger)index forKey:(NSString *)key;

/**
 Get the info of the specified key of BuiltGroup object and returns instance of BuiltGroup.
 
     // consider 'about' is a group in details group
     
     //Obj-C
     BuiltGroup *aboutGroup = [detailsGroup groupForKey:@"about"];
     
     //Swift
     var aboutGroup:BuiltGroup =  detailsGroup.groupForKey("about")
 
 @param key Key containing the value of BuiltGroup
 @return Instance of BuiltGroup
 */
- (BuiltGroup*)groupForKey:(NSString*)key;

/**
 Get the info of the specified key of BuiltGroupMultiple object and returns instance of BuiltGroupMultiple.
 
     // consider 'steps' is a group multiple in details
     
     //Obj-C
     BuiltGroupMultiple *stepsGroup = [detailsGroup groupMultipleForKey:@"steps"];
     
     //Swift
     var stepsGroup:BuiltGroupMultiple =  detailsGroup.groupMultipleForKey("steps")
 
 
 @param key Key containing the value of BuiltGroupMultiple
 @return Instance of BuiltGroupMultiple
 */
- (BuiltGroupMultiple*)groupMultipleForKey:(NSString*)key;

/**
 Configure properties with builtgroup info.
 
     //Obj-C
     [groupObject configureWithDictionary:@{@"Key_name":@"MyValue"}];
     
     //Swift
     groupObject.configureWithDictionary(["Key_name":"MyValue"])
 
 
 @param dictionary User Info
 */
- (void)configureWithDictionary:(NSDictionary*)dictionary;

//MARK: - Subcripting

- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;

- (id)objectForKeyedSubscript:(id <NSCopying>)key;


@end
