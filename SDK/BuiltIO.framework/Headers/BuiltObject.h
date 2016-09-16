//
//  BuiltObject.h
//  BuiltIO
//
//  Created by Reefaq on 30/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"

@class BuiltLocation;
@class BuiltACL;
@class BuiltUpload;
@class BuiltSynchronousResponse;
@class BuiltGroup;
@class BuiltGroupMultiple;
/**
 An object is a instance of a Class
 */
@interface BuiltObject : NSObject

/**
The uid of the object
 
     //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     NSString *objectUID = projectObject.uid;
     
     //Swift
     var objectUID:String = projectObject.uid
 
 */
@property (nonatomic, copy) NSString *uid;

/**
ACL for the object
 
     //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     BuiltACL *builtAcl = projectObject.ACL;
     
     //Swift
     var builtAcl:BuiltACL = projectObject.ACL
 
 */
@property (nonatomic, strong) BuiltACL *ACL;

/**
Check if the object is deleted or not [Gets used in delta calls].

     //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     if (projectObject.isDeleted) {
        //object is deleted
     } else {
        //object is not yet delete
     }
     
     //Swift
     if (projectObject.isDeleted()) {
        //object is deleted
     } else {
        //object is not yet delete
     }
 
 */
@property (nonatomic, assign, readonly, getter=isDeleted) BOOL deleted;

/**
Helps to check whether its a new or existing object on Built.io Backend.

     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     if (projectObject.isNew) {
        //New Object
     } else {
        //Old Object
     }
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     if (projectObject.isNew) {
        //New Object
     } else {
        //old Object
     }
 
 
 *
 */
@property (nonatomic, assign, readonly) BOOL isNew;

/**
Tags list in Array
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     //setting tags
     projectObject.tags = @[@"ui", @"ux"];
     
     //getting tags
     NSArray *tagFileArray = [projectObject tags];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     //setting tags
     projectObject.tags = ["ui", "ux"]
     
     //getting tags
     var tagFileArray:NSArray! = projectObject.tags
 
 
 */
@property (nonatomic, strong) NSArray *tags;

/**
Created date of object.
 
    //Assuming 'projectObject' is a BuiltObject instance
 
    //Obj-C
    NSDate *objectCreatedDate = projectObject.createdAt;

    //Swift
    var objectCreatedDate:Date = projectObject.createdAt
 
 
 */
@property (nonatomic, strong, readonly) NSDate *createdAt;

/**
Last updated date of object.
 
    //Assuming 'projectObject' is a BuiltObject instance
 
    //Obj-C
    NSDate *objectUpdatedDate = projectObject.updatedAt;

    //Swift
    var objectUpdatedDate:Date = projectObject.updatedAt
 
 */
@property (nonatomic, strong, readonly) NSDate *updatedAt;

/**
Deleted date of object.
 
     //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     NSDate *objectDeletedDate = projectObject.deletedAt;
     
     //Swift
     var objectDeletedDate:Date = projectObject.deletedAt
 
 
 */
@property (nonatomic, strong, readonly) NSDate *deletedAt;

/**
BuiltLocation object representing latitute and longitude of an object
 
     //Assuming 'projectObject' is a BuiltObject instance

     //Obj-C
     BuiltLocation *builtLocation = projectObject.location;
     
     //Swift
     var builtLocation:BuiltLocation = projectObject.location
 
 */
@property (nonatomic, strong) BuiltLocation *location;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

//MARK: - Headers
/**
Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     [projectObject setHeader:@"MyHeaderValue" forKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject.setHeader("MyHeaderValue", forKey:"My-Custom-Header-Key")
 
@param headerValue The header key
@param headerKey   The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
Set a header for an application
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     [projectObject addHeadersWithDictionary:@{@"My-Custom-Header-Key":@"MyHeaderValue"}];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject.addHeadersWithDictionary(["My-Custom-Header-Key":"MyHeaderValue"])
 
 
@param headers The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
Removes a header from this application.
 
     //'blt5d4sample2633b' is a dummy Application API key
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     [projectObject removeHeaderForKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject.removeHeaderForKey("My-Custom-Header-Key")
 
 
@param headerKey The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;


//MARK: - Access object values

/**
Checks whether the object has a given property

     //Assuming 'projectObject' is a BuiltObject instance

     //Obj-C
     BOOL hashKey = [projectObject hasKey:@"key"];
     if (hashKey) {
        //Hash Key
     } else {
        //No hash key
     }
     
     //Swift
     var hashKey:Bool = projectObject.hasKey("key")
     if (hashKey) {
        //Hash Key
     } else {
        //No Hash Key
     }
 
@param key The property to be checked
@return YES if key exists, NO if not
 */
- (BOOL)hasKey:(NSString *)key;

/**
Gets the data for given property.
 
     //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     id object = [projectObject objectForKey:@"key"];
     
     //Swift
     var object = projectObject.objectForKey("key")
 
 
@param key The object's property
@return The value for the key provided
 */
- (id)objectForKey:(NSString *)key;


//MARK: - timeless
/**
Issues a timeless update, which means date of creation and updation are not modified.
 
     //'blt5d4sample2633b' is a dummy Application API key
     //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     [projectObject applyTimeless];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject.applyTimeless()
 
 */
- (void)applyTimeless;


//MARK: - set values for reference fields
/**
Assigns a set references to a reference field of an object.
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
    BuiltObject *taskObject  = [taskClass object];
    // setting the project reference
    [taskObject setReference:@"bltb6202sample73a1" forKey:@"project"];


    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var taskClass:BuiltClass = builtApplication.classWithUID("task")
    var taskObject:BuiltObject = taskClass.object()
    // setting the project reference
    taskObject.setReference("bltb6202sample73a1", forKey:"project")
 
 
@param reference This can either be a UID of a referenced object or array of UIDs of a referenced objects.
@param key       The uid of the reference field
 */
- (void)setReference:(id)reference forKey:(NSString *)key;

/**
 Assigns a set references to a reference field of an object.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";

     BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
     BuiltObject *taskObject  = [taskClass object];
     // setting the project reference
     [taskObject setReferenceWithObject:projectObject forKey:@"project"];
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"

 
     var taskClass:BuiltClass = builtApplication.classWithUID("task")
     var taskObject:BuiltObject = taskClass.object()
     // setting the project reference
     taskObject.setReferenceWithObject(projectObject, forKey:"project")
 
 
 @param reference This can either an instance of BuiltObject or array of BuiltObject instance.
 @param key The uid of the reference field
 */
- (void)setReferenceWithObject:(id)referenceObject forKey:(NSString *)key;

/**
Fires a query on Built.io Backend and all the objects which pass the query condition are being assigned to the reference field.
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
    BuiltObject *taskObject  = [taskClass object];
    [taskObject setReferenceWhere:@{@"name":@"Super Project #41!"} forKey:@"project"];


    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var taskClass:BuiltClass = builtApplication.classWithUID("task")
    var taskObject:BuiltObject = taskClass.object()
    taskObject.setReferenceWhere(["name":"Super Project #41!"], forKey:"project")
 
 
@param dictionary Object specifying the conditions
@param key        The uid of the reference field
 */
- (void)setReferenceWhere:(NSDictionary *)dictionary forKey:(NSString *)key;


//MARK: - Update/Insert
/**
Upserts the object (Updates the matching object if found on Built.io Backend or creates a new object)
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!"
     [projectObject upsert:@{@"name":@"Super Project #41!"}];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject.upsert(["name":"Super Project #41!"])
 
 
@param dictionary A check will be performed, whether any object has the key value pair(s) supplied in the dictionary
 */
- (void)upsert:(NSDictionary *)dictionary;

/**
Use this method only when the values of the fields inside referenced object are to be changed while creating a new object.
 
    //Obj-C
    BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
    BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
    BuiltObject *taskObject  = [taskClass object];
    [taskObject addUpsertForReferenceField:@"project" condition:@{@"name":@"Super Project #41!"} replaceWith:@{@"description":@"This is a very cool project"}]

    //Swift
    var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
    var taskClass:BuiltClass = builtApplication.classWithUID("task")
    var taskObject:BuiltObject = taskClass.object()
    taskObject.addUpsertForReferenceField("project", condition:["name":"Super Project #41!"], replaceWith:["description":"This is a very cool project"])
 
 
@param referenceField  Reference uid on which UPSERT is to be performed
@param conditionDictionary A check will be performed, whether any object has the key value pair(s) supplied in the dictionary in the reference field
@param replaceDictionary  New key value pairs for the fields inside the referenced object
 */
- (void)addUpsertForReferenceField:(NSString *)referenceField condition:(NSDictionary *)conditionDictionary replaceWith:(NSDictionary *)replaceDictionary;


//MARK: - object owner

/**
Check if object has owner
 
     //Assuming 'projectObject' is a BuiltObject instance

     //Obj-C
     if (projectObject.hasOwner) {
        //Object has a owner
     } else {
        //Object has no owner
     }
     
     
     //Swift
     if (projectObject.hasOwner()) {
        //Object has a owner
     } else {
        //Object has no owner
     }
 
@return YES if object has owner else NO
 */
- (BOOL)hasOwner;

/**
Returns owner if the object has owner
 
     //Assuming 'projectObject' is a BuiltObject instance

     //Obj-C
     id objectOwner = [projectObject owner];
     
     //Swift
     var owner:AnyObject = projectObject.owner()
 
 
@return Owner of the object
 */
- (id)owner;

/**
Get the UID of the owner of the object
 
     //Assuming 'projectObject' is a BuiltObject instance
 
     //Obj-C
     NSString *objectOwnerUID = [projectObject ownerUID];
     
     //Swift
     var objectOwnerUID:String = projectObject.ownerUID()
 
 
@return UID of the owner
 */
- (NSString *)ownerUID;

/**
Get the email of the owner of the object
 
    //Assuming 'projectObject' is a BuiltObject instance

     //Obj-C
     NSString *objectOwnerEmail = [projectObject ownerEmail];
     
     //Swift
     var objectOwnerEmail:String = projectObject.ownerEmail()
 
@return email of the owner of the object
 */
- (NSString *)ownerEmail;



//MARK: - increment, decrement, multiply, divide
/**
Increments the number field by a given amount (Note: Increment is done on the server)
 
    //Assuming 'personObject' is a BuiltObject instance

     //Obj-C
     [personObject incrementKey:@"age" by:@(2)];
     
     //Swift
     personObject.incrementKey("age", by:NSNumber(int: 2))
 
@param key    Uid of number field
@param number By how much amount to increment
 */
- (void)incrementKey:(NSString *)key by:(NSNumber *)number;

/**
Decrements the number field by a given amount (Note: Decrement is done on the server)
 
     //Assuming 'personObject' is a BuiltObject instance

     //Obj-C
     [personObject decrementKey:@"age" by:@(2)];
     
     //Swift
     personObject.decrementKey("age", by:NSNumber(int: 2))
 
@param key    Uid of number field
@param number By how much amount to decrement
 */
- (void)decrementKey:(NSString *)key by:(NSNumber *)number;

//MARK: - operations on fields of multiple type

/**
Appends a value in the given field.(Applies only to fields that allow multiple values)
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
     // 'bltf50esamplefeb' is uid of an object of 'task' class
     BuiltObject *taskObject = [taskClass objectWithUID:@"bltf50esamplefeb"];
     [taskObject pushValue: @{@"name": @"new task", @"description": @"newest task"} forKey:@"steps"];
 
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var taskClass:BuiltClass = builtApplication.classWithUID("task")
     // 'bltf50esamplefeb' is uid of an object of 'task' class
     var taskObject:BuiltObject = taskClass.objectWithUID("bltf50esamplefeb")
     taskObject.pushValue(NSArray(objects: ["name" : "new task", "description" : "newest task"]), forKey: "steps") 
 
 
@param value Value to be pushed
@param key   Uid of field
 */
- (void)pushValue:(id)value forKey:(NSString *)key;

/**
For the given field, it deletes the first matched value.(Applies only to fields that allow multiple values)
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
     BuiltObject *taskObject  = [taskClass object];
     [taskObject pullValue:@"will come at front" forKey:@"steps.name"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var taskClass:BuiltClass = builtApplication.classWithUID("task")
     var taskObject:BuiltObject = taskClass.object()
     taskObject.pullValue("will come at front", forKey:"steps.name")
 
@param value Values to be deleted
@param key   Uid of field
 */
- (void)pullValue:(id)value forKey:(NSString *)key;


/**
A value in a field that allows multiple values
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
     BuiltObject *taskObject  = [taskClass object];
     [taskObject updateValue:@"John" atIndex:0 forKey:@"members"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var taskClass:BuiltClass = builtApplication.classWithUID("task")
     var taskObject:BuiltObject = taskClass.object()
     taskObject.updateValue("John", atIndex: 0, forKey: "members")
 
@param updatedValue New value to be updated
@param index        Index at which the value is to be updated
@param key          Uid of field
 */
- (void)updateValue:(id)updatedValue atIndex:(NSInteger)index forKey:(NSString *)key;

//MARK: - set values for object's fields
/**
 *  Use this method to add a new key value pair in group.
 *
 *  @param object object to set
 *  @param key    key to assign on.
 */
- (void)setObject:(id)object forKey:(NSString *)key;


//MARK: - set Groups

/**
Adds Group to this object
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *bugClass = [builtApplication classWithUID:@"bug"];
     BuiltObject *bugObject  = [bugClass object];
     
     BuiltGroup *detailGroup  = [BuiltGroup groupWithField:@"details"];
     detailGroup[@"title"] = @"UI Bug";
     [bugObject addGroup:detailGroup];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var bugClass:BuiltClass = builtApplication.classWithUID("bug")

     var bugObject:BuiltObject = bugClass.object()
     var detailGroup:BuiltGroup = BuiltGroup(field: "details")
     detailGroup["title"] = "UI Bug"
     bugObject.addGroup(detailGroup)


@param group Instance of BuiltGroup for this object
 */
-(void)addGroup:(BuiltGroup*)group;

/**
Adds GroupMultiple to this object
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *bugClass = [builtApplication classWithUID:@"bug"];
     BuiltObject *bugObject  = [bugClass object];
     
     BuiltGroup *step1 = [BuiltGroup group];
     step1[@"title"] = @"Click view button";

     BuiltGroup *steps2 = [BuiltGroup group];
     step2[@"title"] = @"Click on list";
 
     BuiltGroupMultiple *stepsGroup = [BuiltGroupMultiple groupMultipleWithField:@"steps"];
     [stepsGroup addGroup:step1];
     [stepsGroup addGroup:step2];
     
     [bugObject addGroupMultiple:stepsGroup];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var bugClass:BuiltClass = builtApplication.classWithUID("bug")
     
     var bugObject:BuiltObject = bugClass.object()
 
     var step1:BuiltObject = BuiltGroup(field: "steps1")
     step1["title"] = "Click view button"

     var step2:BuiltObject = BuiltGroup(field: "steps2")
     step2["title"] = "Click on list"
 
     var stepsGroup:BuiltGroupMultiple = BuiltGroupMultiple(field: "steps")
     stepsGroup.addGroup(step1)
     stepsGroup.addGroup(step2)

      bugObject.addGroupMultiple(stepsGroup)

@param groupMultiple Instance of BuiltGroupMultiple for this object
 */
-(void)addGroupMultiple:(BuiltGroupMultiple*)groupMultiple;

/**
Get the info of the specified key of BuiltGroup object and returns instance of BuiltGroup.
 
     // 'details' is a key in bug class for group
     
     //Obj-C
     BuiltGroup *detailsGroup = [bugObject groupForKey:@"details"];
     
     //Swift
     var detailsGroup:BuiltGroup =  bugObject.groupForKey("details")

@param key Key containing the value of BuiltGroup
@return Instance of BuiltGroup
 */
-(BuiltGroup*)groupForKey:(NSString*)key;

/**
Get the info of the specified key of BuiltGroupMultiple object and returns instance of BuiltGroupMultiple.
 
     // 'steps' is a key in bug class for group multiple
     
     //Obj-C
     BuiltGroupMultiple *stepsGroup = [bugObject groupMultipleForKey:@"steps"];
     
     //Swift
     var stepsGroup:BuiltGroupMultiple =  bugObject.groupMultipleForKey("steps")

 
@param key Key containing the value of BuiltGroupMultiple
@return Instance of BuiltGroupMultiple
 */
-(BuiltGroupMultiple*)groupMultipleForKey:(NSString*)key;


//MARK: - Object fetch
/**
Fetches an object synchronously provided object UID and class UID
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //'bltf4fsamplec851db' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf4fsamplec851db"];
     NSError *error;
     BuiltSynchronousResponse *builtSyncResponse = [projectObject fetch:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf4fsamplec851db' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf4fsamplec851db")
     var error:NSErrorPointer
     var builtSyncResponse:BuiltSynchronousResponse = projectObject.fetch(error)
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.
 */
- (BuiltSynchronousResponse *)fetch:(NSError **)error  BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Fetches an object asynchronously provided object UID and class UID
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //'bltf4fsamplec851db' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf4fsamplec851db"];
     [projectObject fetchInBackgroundWithCompletion:^(ResponseType responseType, BuiltObject *object, NSError *error) {
     
     }];
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf4fsamplec851db' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf4fsamplec851db")
     projectObject.fetchInBackgroundWithCompletion { (ResponseType, BuiltObject!, NSError!) -> Void in
     
     }
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)fetchInBackgroundWithCompletion:(void (^)(ResponseType responseType, BuiltObject *object, NSError *error))completionBlock;

/**
Returns an array of BuiltObjects for the specified reference key
 
Use this method to retrieve BuiltObjects when using includeRefFieldWithKey: method of BuiltQuery. The reference field key may have an array of objects or a single object. This method will return the BuiltObjects for the included reference field.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *taskClass = [builtApplication classWithUID:@"task"];
     //'bltf4fsamplec851db' is uid of an object of 'task' class
     BuiltObject *taskObject  = [taskClass objectWithUID:@"bltf4fsamplec851db"];
     NSArray *projectsArray = [taskObject  getAllObjectsForKey:@"project" withClassUID:@"project"];
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var taskClass:BuiltClass = builtApplication.classWithUID("task")
     //'bltf4fsamplec851db' is uid of an object of 'task' class
     var taskObject:BuiltObject = taskClass.objectWithUID("bltf4fsamplec851db")
     var projectsArray:AnyObject = taskObject.getAllObjectsForKey("project", withClassUID:"project")
 
 
@param key      the reference field key
@param classUID set the class uid of the class to which the object(s) belongs
@return An array of BuiltObjects for the specified key
 */
- (NSArray *)getAllObjectsForKey:(NSString *)key withClassUID:(NSString *)classUID;


//MARK: - Object save
/**
Saves an object as draft syncronously so that it is not visible unless explicitly called for. see [including drafts]([BuiltQuery includeDrafts])
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     NSError *error;
     [projectObject saveAsDraft:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     var error:NSErrorPointer
     projectObject.saveAsDraft(error)
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.
 */
- (void)saveAsDraft:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Saves an BuiltObject syncronously to Built.io Backend servers
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     NSError *error;
     [projectObject save:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     var error:NSErrorPointer
     projectObject.save(error)
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.

 */
- (void)save:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Saves an object as draft syncronously so that it is not visible unless explicitly called for. see [including drafts]([BuiltQuery includeDrafts])
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     NSError *error;
     [projectObject saveAsDraftEventually:error];
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     var error:NSErrorPointer
     projectObject.saveAsDraftEventually(error)
 
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.
 */
- (void)saveAsDraftEventually:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Saves an BuiltObject syncronously if network is unavailable. Resumes when network becomes available.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     NSError *error;
     [projectObject saveEventually:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     var error:NSErrorPointer
     projectObject.saveEventually(error)
 
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.

 */
- (void)saveEventually:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");



/**
Saves an object as draft asyncronously so that it is not visible unless explicitly called for. see [including drafts]([BuiltQuery includeDrafts])
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     [projectObject saveAsDraftInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     projectObject.saveAsDraftInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)saveAsDraftInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;

/**
Saves an BuiltObject asyncronously to Built.io Backend servers
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     [projectObject saveInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     projectObject.saveInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)saveInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;

/**
Saves an object as draft asyncronously so that it is not visible unless explicitly called for. see [including drafts]([BuiltQuery includeDrafts])
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     [projectObject saveAsDraftEventuallyInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     projectObject.saveAsDraftEventuallyInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)saveAsDraftEventuallyInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;

/**
Saves an BuiltObject asyncronously if network is unavailable. Resumes when network becomes available.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     projectObject[@"name"] = @"Super Project #41!";
     projectObject[@"description"] = @"This is a very cool project";
     [projectObject  saveEventuallyInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectObject:BuiltObject = projectClass.object()
     projectObject["name"] = "Super Project #41!"
     projectObject["description"] = "This is a very cool project"
     projectObject.saveEventuallyInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)saveEventuallyInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;


//MARK: - Object delete
/**
Deletes the BuiltObject syncronously with specified object UID.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //'bltf50esamplefeb' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf50esamplefeb"];
     NSError *error;
     [projectObject  destroy:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf50esamplefeb' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf50esamplefeb")
     var error:NSErrorPointer
     projectObject.destroy(error)
 
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.

 */
- (void)destroy:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Deletes the BuiltObject syncronously with specified object UID. Drafts the operation if network is unavailable. Resumes after network is back.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltObject *projectObject  = [projectClass object];
     //'bltf50esamplefeb' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf50esamplefeb"];
     NSError *error;
     [projectObject  destroyEventually:error];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf50esamplefeb' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf50esamplefeb")
     var error:NSErrorPointer
     projectObject.destroyEventually(error)
 
 
@param error Pointer to an NSError that will be set if necessary.
@deprecated Synchronous methods is been deprecated.

 */
- (void)destroyEventually:(NSError **)error BUILTIO_DEPRECATED("Synchronous methods is been deprecated.");

/**
Deletes the BuiltObject asyncronously with specified object UID.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //'bltf50esamplefeb' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf50esamplefeb"];
     [projectObject  destroyInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf50esamplefeb' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf50esamplefeb")
     projectObject.destroyInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)destroyInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;

/**
Deletes the BuiltObject asyncronously with specified object UID. Drafts the operation if network is unavailable. Resumes after network is back.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //'bltf50esamplefeb' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf50esamplefeb"];
     [projectObject  destroyEventuallyInBackgroundWithCompletion:^(ResponseType responseType, NSError *error) {
     
     }];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf50esamplefeb' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf50esamplefeb")
     projectObject.destroyEventuallyInBackgroundWithCompletion { (ResponseType, NSError!) -> Void in
     
     }
 
 
@param completionBlock Completion block with params (ResponseType responseType, id responseJSON, NSError *error)
 */
- (void)destroyEventuallyInBackgroundWithCompletion:(BuiltRequestCompletionHandler)completionBlock;


//MARK: - Only and Except -
/**---------------------------------------------------------------------------------------
 * @name Only and Except
 *  ---------------------------------------------------------------------------------------
 */

/**
 Specifies an array of 'only' keys in BASE object that would be included in the response.
 
     //Obj-C
     [taskObject includeOnlyFields:@["project"]];
     
     //Swift
     taskObject.includeOnlyFields(["project"])
 
 @discussion Specifies an array of keys in BASE object that would be included in the response.
 @param fieldUIDs Array of the 'only' keys to be included in response.
 */
- (void)includeOnlyFields:(NSArray *)fieldUIDs;

/**
 Specifies an array of keys in reference class object that would be 'excluded' from the response.
 
     //Obj-C
     [taskObject includeAllFieldsExcept:@["project"]];
     
     //Swift
     taskObject.includeAllFieldsExcept(["project"])
 
 @discussion Specifies an array of keys in BASE object that would be 'excluded' from the response.
 @param fieldUIDs Array of keys to be excluded from the response.
 */
- (void)includeAllFieldsExcept:(NSArray *)fieldUIDs;

//MARK: - Reference -
/**---------------------------------------------------------------------------------------
 * @name Reference
 *  ---------------------------------------------------------------------------------------
 */

/**
 Include reference objects with given key in response
 
     //Obj-C
     [taskObject includeRefFieldWithKey:@[@"project"]];
     
     //Swift
     taskObject.includeRefFieldWithKey(["project"])
 
 @discussion The include parameter accepts the name of a reference field. By default, no reference field is bought along with the object, only the uids are. To include any reference, this parameter must be used. Nested references can be bought by "." separating the references. This will work for references which are nested inside groups or references which are nested inside other references.
 @param key Array of reference keys to include in response.
 */
- (void)includeRefFieldWithKey:(NSArray *)key;

/**
 Specifies an array of 'only' keys in reference class object that would be included in the response.
 
     //Obj-C
     [taskObject includeRefFieldWithKey:@[@"project"] andOnlyRefValuesWithKeys:@[@"name",@"description"]];
     
     //Swift
     taskObject.includeRefFieldWithKey(["project"], andOnlyRefValuesWithKeys:["name","description"])
 
 @discussion Specifies an array of keys in reference class object that would be included in the response.
 @param key Key who has reference to some other class object.
 @param values Array of the 'only' reference keys to be included in response.
 */
- (void)includeRefFieldWithKey:(NSString *)key andOnlyRefValuesWithKeys:(NSArray *)values;

/**
 Specifies an array of keys in reference class object that would be 'excluded' from the response.
 
     //Obj-C
     [taskObject includeRefFieldWithKey:@[@"project"] excludingRefValuesWithKeys:@[@"description"]];
     
     //Swift
     taskObject.includeRefFieldWithKey(["project"], excludingRefValuesWithKeys:["description"])
 
 @discussion Specifies an array of keys in reference class object that would be 'excluded' from the response.
 @param key Key who has reference to some other class object.
 @param values Array of the 'only' reference keys to be 'excluded' from the response.
 */
- (void)includeRefFieldWithKey:(NSString *)key excludingRefValuesWithKeys:(NSArray *)values;

//MARK: - Additional Options
/**
Include the owner’s profile in the objects' data.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //'bltf50esamplefeb' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf50esamplefeb"];
     [projectObject includeOwner];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf50esamplefeb' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf50esamplefeb")
     projectObject.includeOwner()
 
 
@discussion The returned objects will also contain a key “_owner”, which will include the owner’s profile in the object’s data.
 */
- (void)includeOwner;

/**
Gives object count alongwith the object returned in response.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     //'bltf50esamplefeb' is uid of an object of 'project' class
     BuiltObject *projectObject  = [projectClass objectWithUID:@"bltf50esamplefeb"];
     [projectObject includeCount];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     //'bltf50esamplefeb' is uid of an object of 'project' class
     var projectObject:BuiltObject = projectClass.objectWithUID("bltf50esamplefeb")
     projectObject.includeCount()
 
 
@discussion Gives object count alongwith the object returned in response.
 */
- (void)includeCount;

/**
Include custom query using a key and a value.
 
     //Obj-C
     [projectObject addQueryWithKey:@"query_key" andValue:@"query value"];
     
     //Swift
     projectObject.addQueryWithKey("query_key", andValue:"query value")
 
 
@discussion Include custom query using a key and a value.
@param key   name of the query.
@param value value for the query.
 */
- (void)addQueryWithKey:(NSString *)key andValue:(id)value;

/**
Removes custom query.
 
     //Obj-C
     [projectObject removeQueryWithKey:@"query_key"];
     
     //Swift
     projectObject.removeQueryWithKey("query_key")
 
@param key name of the query.
 */
- (void)removeQueryWithKey:(NSString *)key;

/**
Get the info of the specified key of BuiltUpload object and returns instance of BuiltUpload.
 
     // 'projectImage' is a key in project class for upload
 
     //Obj-C
     BuiltUpload *builtUpload = [projectObject uploadForKey:@"projectImage"];
     
     //Swift
     var builtUpload:BuiltUpload =  projectObject.uploadForKey("projectImage")
 
 
@param key Key containing the reference value of builtUpload
@return Instance of BuiltUpload.
 */
- (BuiltUpload *)uploadForKey:(NSString *)key;

/**
Get the array containing instance of BuiltUpload mentioned in key specified.
 
     // 'projectImage' is a key in project class for upload
 
     //Obj-C
     NSArray *builtUploadArray = [projectObject uploadsForKey:@"projectImage"];
     
     //Swift
     var builtUploadArray = projectObject.uploadsForKey("projectImage")
 
@param key Key containing the colection reference value of BuiltUpload.
@return Array containing instance of BuiltUpload.
 */
- (NSArray *)uploadsForKey:(NSString *)key;

/**
 Configure user properties with built object info.
 
     //Obj-C
     [projectObject configureWithDictionary:@{@"Key_name":@"MyValue"}];
     
     //Swift
     projectObject.configureWithDictionary(["Key_name":"MyValue"])
 
 
 @param dictionary User Info
 */
- (void)configureWithDictionary:(NSDictionary *)dictionary;

/**
 @abstract Advises the operation object that it should stop executing its task.
 
     //Obj-C
     [projectObject cancelRequests];
     
     //Swift
     projectObject.cancelRequests()
 
 
 @discussion This method does not force your operation code to stop. Instead, it updates the object’s internal flags to reflect the change in state. If the operation has already finished executing, this method has no effect. Canceling an operation that is currently in an operation queue, but not yet executing, makes it possible to remove the operation from the queue sooner than usual.
 */
- (void)cancelRequests;


//MARK: - Subcripting

- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;

- (id)objectForKeyedSubscript:(id <NSCopying>)key;


//MARK: Deprecated API

/**
 Use this method only when the values of the fields inside referenced object are to be changed while creating a new object.
 
 @param dictionary A check will be performed, whether any object has the key value pair(s) supplied in the dictionary in the reference field
 @param referenceField   Reference uid on which UPSERT is to be performed
 @param newDict    New key value pairs for the fields inside the referenced object
 @deprecated Please use addUpsertForReferenceField:condition:replaceWith: instead.
 */
- (void)upsert:(NSDictionary *)dictionary forReferenceField:(NSString *)referenceField newDictionary:(NSDictionary *)newDict BUILTIO_DEPRECATED("Please use addUpsertForReferenceField:condition:replaceWith: instead.");

/**
Multiply the number field by given amount (Note: Multiplication is done on the server)

@param key    Uid of number field
@param number By how much amount to multiple
@deprecated This method is been deprecated.
 */
- (void)multiplyKey:(NSString *)key by:(NSNumber *)number BUILTIO_DEPRECATED("This method is been deprecated.");

/**
Divides the number field by given amount (Note: Division is done on the server)

@param key    Uid of number field
@param number By how much amount to divide
@deprecated This method is been deprecated.
 */
- (void)divideKey:(NSString *)key by:(NSNumber *)number BUILTIO_DEPRECATED("This method is been deprecated.");

/**
 Pushes a value at a specified index in the given field(Applies only to fields that allow multiple values)
 
 @param value Value to be pushed
 @param index Index at which value should be pushed
 @param key   Uid of field
 @deprecated This method is been deprecated.
 */
- (void)pushValue:(id)value atIndex:(NSInteger)index forKey:(NSString *)key BUILTIO_DEPRECATED("This method is been deprecated.");
/**
 For the given field, it deletes the value at a given index.(Applies only to fields that allow multiple values)
 
 @param index Index at which the value should be deleted
 @param key   Uid of field
 @deprecated This method is been deprecated.
 */
- (void)pullValueAtIndex:(NSInteger)index forKey:(NSString *)key BUILTIO_DEPRECATED("This method is been deprecated.");

@end
