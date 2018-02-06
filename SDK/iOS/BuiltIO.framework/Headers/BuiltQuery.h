//
//  BuiltQuery.h
//  BuiltIO
//
//  Created by Reefaq on 30/09/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BuiltDefinitions.h"
#import "BuiltQueryResult.h"

BUILT_ASSUME_NONNULL_BEGIN
/**
 A class that defines a query on Built.io Backend.
 */
@interface BuiltQuery : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

@property (nonatomic, assign) BuiltNetworkCachePolicy cachePolicy;


//MARK: Manually set headers -
/**---------------------------------------------------------------------------------------
 * @name Manually set headers
 *  ---------------------------------------------------------------------------------------
 */
/**
Set a header for an application
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery setHeader:@"MyHeaderValue" forKey:@"My-Custom-Header-Key"];
     
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.setHeader("MyHeaderValue", forKey:"My-Custom-Header-Key")
 
 
@param headerValue The header key
@param headerKey   The header value
 */
- (void)setHeader:(NSString *)headerValue forKey:(NSString *)headerKey;

/**
Set a header for an application
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery addHeadersWithDictionary:@{@"My-Custom-Header-Key":@"MyHeaderValue"}];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.addHeadersWithDictionary(["My-Custom-Header-Key":"MyHeaderValue"])
 
 
@param headers The headers as dictionary which needs to be added to the application
 */
- (void)addHeadersWithDictionary:(NSDictionary *)headers;

/**
Removes a header from this application.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery removeHeaderForKey:@"My-Custom-Header-Key"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.removeHeaderForKey("My-Custom-Header-Key")
 
 
@param headerKey The header key that needs to be removed
 */
- (void)removeHeaderForKey:(NSString *)headerKey;


//MARK: AND OR over query -
/**---------------------------------------------------------------------------------------
 * @name AND OR over query
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Accepts an array of queries, and ORs them.
 
     // 'blt5d4sample2633b' is a dummy Application API key
     // 'project' is a uid of a class on Built.io Backend

     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     NSArray *subQueryArray = [NSArray arrayWithObjects:@"query",@"sub query", nil];
     [projectQuery orWithSubqueries:subQueryArray];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("task")
     var projectQuery:BuiltQuery = projectClass.query()
     var subQueryArray = ["query", "sub query"];
     projectQuery.orWithSubqueries(subQueryArray)
 
 
 @discussion The query object on which you call this method will be OR of the passed queries.
 @param queries Array of `BuiltQuery`s to apply OR on.
 */
- (void)orWithSubqueries:(NSArray *)queries;

/**
 @abstract Accepts an array of queries, and ANDs them.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     NSArray *queryArray = [NSArray arrayWithObjects:@"query",@"sub query", nil];
     [projectQuery andWithSubqueries:queryArray];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     var queryArray = ["query", "sub query"];
     projectQuery.andWithSubqueries(queryArray)
 
 
 @discussion The query object on which you call this method will be AND of the passed queries.
 @param queries Array of `BuiltQuery`s to apply AND on.
 */
- (void)andWithSubqueries:(NSArray *)queries;


//MARK: - Sorting
/**
 @abstract Sort the results in ascending order with the given key.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery orderByAscending:@"name"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.orderByAscending("name")
 
 
 @discussion The asc parameter will sort the returned objects in ascending order of the provided field uid.
 @param key The key to order by.
 */
- (void)orderByAscending:(NSString *)key;


/**
 @abstract Sort the results in descending order with the given key.
 
     //Obj-C
     BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery orderByDescending:@"name"];
     
     //Swift
     var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.orderByDescending("name")
 
 
 @discussion The desc parameter will sort the returned objects in descending order of the provided field uid.
 @param key The key to order by.
 */
- (void)orderByDescending:(NSString *)key;


//MARK: Include -
/**---------------------------------------------------------------------------------------
 * @name Include
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Gives only the count of objects returned in response.
 
     //Obj-C
     [projectQuery objectsCount];
     
     //Swift
     projectQuery.objectsCount()
 
 @discussion Gives only the count of objects returned in response.
 */
- (void)objectsCount;

/**
 @abstract Include all unpublished objects of a class.
 
     //Obj-C
     [projectQuery includeDrafts];
     
     //Swift
     projectQuery.includeDrafts()
 
 
 @discussion The "include_unpublished" parameter, when set to "true", also includes all the objects that are unpublished (published=false).
 */
- (void)includeDrafts;

/**
 @abstract Includes schemas of all returned objects alongwith objects themselves.
 
     //Obj-C
     [projectQuery includeSchema];
     
     //Swift
     projectQuery.includeSchema()
 
 
 @discussion When set to "true", this parameter allows you to include the schema portion of your class in the objects response.
 */
- (void)includeSchema;

/**
 @abstract Include the owner's profile in the objects' data.
 
     //Obj-C
     [projectQuery includeOwner];
     
     //Swift
     projectQuery.includeOwner()
 
 
 @discussion When set to "true", the returned objects will also contain a key "_owner", which will include the owner's profile in the objects' data.
 */
- (void)includeOwner;

/**
 @abstract Gives object count alongwith objects returned in response.
 
     //Obj-C
     [projectQuery includeCount];
     
     //Swift
     projectQuery.includeCount()
 
 
 @discussion Gives object count alongwith objects returned in response.
 */
- (void)includeCount;

/**
 @abstract use this method if you want only drafts to appear in the response of a query.
 
     //Obj-C
     [projectQuery onlyDrafts];
     
     //Swift
     projectQuery.onlyDrafts()
 
 */
- (void)onlyDrafts;


//MARK: Pagination -
/**---------------------------------------------------------------------------------------
 * @name Pagination
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract A limit on the number of objects to return.
 
     //Obj-C
     [projectQuery limitObjects:5];
     
     //Swift
     projectQuery.limitObjects(5)
 
 
 @discussion The limit parameter can be used for pagination. "limit" specifies the number of objects to limit to in the response.
 @param number No of objects to limit.
 */
- (void)limitObjects:(NSNumber *)number;

/**
 @abstract The number of objects to skip before returning any.
 
     //Obj-C
     [projectQuery skipObjects:2];
     
     //Swift
     projectQuery.skipObjects(2)
 
 
 @discussion The skip parameter can be used for pagination. "skip" specifies the number of objects to skip in the response.
 @param number No of objects to skip from returned objects.
 */
- (void)skipObjects:(NSNumber *)number;


//MARK: Adding Basic Constraints -
/**---------------------------------------------------------------------------------------
 * @name Adding Basic Constraints
 *  ---------------------------------------------------------------------------------------
 */

/**
 *  Include custom query using a key and a value.
 
     //Obj-C
     [projectQuery addQueryWithKey:@"key_name" andValue:@"MyValue"];
     
     //Swift
     projectQuery.addQueryWithKey("key_name", andValue:"MyValue")
 
 
@discussion Include custom query using a key and a value.
@param key   name of the query.
@param value value for the query.
 */
- (void)addQueryWithKey:(NSString *)key andValue:(id)value;

/**
 @abstract A custom dictionary can be provided to a query that can specify the conditions for retrieving objects.
 
     //Obj-C
     [projectQuery addQueryParams:@{@"Query_Key":@"Query Value"}];
     
     //Swift
     projectQuery.addQueryParams(["Query_Key":"Query Value"])
 
 
 @param queryDict A dictionary with all the necessary conditions for retrieving objects.
 @discussion If a complex query needs to be performed and if it is difficult to specify it using the query methods, a dictionary can be provided that specifies all the conditions. The dictionary should be as per the JSON format specified in the REST API docs.
 */
- (void)addQueryParams:(NSDictionary *)queryDict;

/**
Removes custom query.
 
     //Obj-C
     [projectQuery removeQueryWithKey:@"Query_Key"];
     
     //Swift
     projectQuery.removeQueryWithKey("Query_Key")
 
 
@param key name of the query.
 */
- (void)removeQueryWithKey:(NSString *)key;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be equal to the provided object.
 
     //Obj-C
     // 'bltf4fbsample851db' is a uid of an object we wish to search
     [projectQuery whereKey:@"uid" equalTo:@"bltf4fbsample851db"];
 
     //Swift
     // 'bltf4fbsample851db' is a uid of an object we wish to search
     projectQuery.whereKey("uid", equalTo:"bltf4fbsample851db")
 
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 */
- (void)whereKey:(NSString *)key equalTo:(id)object;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be not equal to the provided object.
 
     //Obj-C
     // 'bltf4fbsample851db' is a uid of an object we wish to search
     [projectQuery whereKey:@"uid" notEqualTo:@"bltf4fbsample851db"];
     
     //Swift
     // 'bltf4fbsample851db' is a uid of an object we wish to search
     projectQuery.whereKey("uid", notEqualTo:"bltf4fbsample851db")
 
 
 @param key The key to be constrained
 @param object The object that must not be equalled.
 */
- (void)whereKey:(NSString *)key notEqualTo:(id)object;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be less than the provided object.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"due_date" lessThan:@"2013-06-25T00:00:00+05:30"];
 
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("due_date", lessThan: "2013-06-25T00:00:00+05:30")

 
 @param key The key to be constrained.
 @param object The object that provides an upper bound.
 */
- (void)whereKey:(NSString *)key lessThan:(id)object;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be greater than the provided object.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"due_date" greaterThan:@"2013-06-25T00:00:00+05:30"];
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("due_date", greaterThan: "2013-06-25T00:00:00+05:30")
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 */
- (void)whereKey:(NSString *)key greaterThan:(id)object;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be less than or equal to the provided object.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"due_date" lessThanOrEqualTo:@"2013-06-25T00:00:00+05:30"];
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("due_date", lessThanOrEqualTo: "2013-06-25T00:00:00+05:30")
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 */
- (void)whereKey:(NSString *)key lessThanOrEqualTo:(id)object;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be greater than or equal to the provided object.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"due_date" greaterThanOrEqualTo:@"2013-06-25T00:00:00+05:30"];
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("due_date", greaterThanOrEqualTo: "2013-06-25T00:00:00+05:30")
 
 
 @param key The key to be constrained.
 @param object The object that must be equalled.
 */
- (void)whereKey:(NSString *)key greaterThanOrEqualTo:(id)object;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be contained in the provided array.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"severity" containedIn:@[@"Show Stopper", @"Critical"]];
     
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("severity", containedIn: ["Show Stopper","Critical"])
 
 @param key The key to be constrained.
 @param array The possible values for the key's object.
 */
- (void)whereKey:(NSString *)key containedIn:(NSArray *)array;

/**
 @abstract Add a constraint to the query that requires a particular key's object not be contained in the provided array.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"severity" notContainedIn:@[@"Show Stopper", @"Critical"]];
     
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("severity", notContainedIn: ["Show Stopper","Critical"])
 
 @param key The key to be constrained.
 @param array The list of values the key's object should not be.
 */
- (void)whereKey:(NSString *)key notContainedIn:(NSArray *)array;

/**
 @abstract Add a constraint that requires a particular key's value exists.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKeyExists:@"status"];
     
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKeyExists("status")
 
 @param key The key of which value to be constrained.
 */
- (void)whereKeyExists:(NSString *)key;

/**
 @abstract Add a constraint that requires a particular key's value not exist.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKeyDoesNotExist:@"due_date"];
     
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKeyDoesNotExist("status")
 
 
 @param key The key of which value to be constrained.
 */
- (void)whereKeyDoesNotExist:(NSString *)key;

/**
 @abstract Add a regular expression constraint for finding string values that match the provided regular expression. This may be slow for large datasets.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"name" matchesRegex:@"^browser"];
 
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("name", matchesRegex: "^browser")
 
 
 @discussion Add a regular expression constraint for finding string values that match the provided regular expression. This may be slow for large datasets.
 @param key The key to be constrained
 @param regex The regular expression pattern to match.
 */
- (void)whereKey:(NSString *)key matchesRegex:(NSString *)regex;

/**
 @abstract Add a regular expression constraint for finding string values that match the provided regular expression. This may be slow for large datasets.
 
     //Obj-C
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"name" matchesRegex:@"^browser" modifiers:@"i"];
     
     //Swift
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("name", matchesRegex: "^browser", modifiers: "i")
 
 
 @discussion Add a regular expression constraint for finding string values that match the provided regular expression. This may be slow for large datasets.
 @param key The key to be constrained
 @param regex The regular expression pattern to match.
 @param modifier Any of the following supported Regex modifiers
 */
- (void)whereKey:(NSString *)key matchesRegex:(NSString *)regex modifiers:(NSString *)modifier;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be equal to the provided object.
 
     //Obj-C
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *selectQuery = [projectClass query];
     [selectQuery whereKey:@"description" equalTo:@"test"];

     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"project" equalToResultOfSelectQuery:selectQuery forKey:@"name"];
 
     //Swift
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var selectQuery:BuiltQuery = projectClass.query()
     selectQuery.whereKey("description", equalTo: "test")
     
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("project", equalToResultOfSelectQuery:selectQuery, forKey: "name")
 
 
 @param key The key to be constrained.
 @param selectQuery The select query to be performed on another class
 @param pickedKey the key for which the values should be returned after the select query is performed
 */
- (void)whereKey:(NSString *)key equalToResultOfSelectQuery:(BuiltQuery *)selectQuery forKey:(NSString *)pickedKey;

/**
 @abstract Add a constraint to the query that requires a particular key's object to be equal to the provided object.
 
     //Obj-C
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *selectQuery = [projectClass query];
     [selectQuery whereKey:@"description" equalTo:@"test"];
     
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery whereKey:@"project" equalToResultOfDontSelectQuery:selectQuery forKey:@"name"];
     
     //Swift
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var selectQuery:BuiltQuery = projectClass.query()
     selectQuery.whereKey("description", equalTo: "test")
     
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.whereKey("project", equalToResultOfDontSelectQuery:selectQuery, forKey: "name")
 
 
 @param key The key to be constrained.
 @param dontSelectQuery The dont_select query to be performed on another class. This is the inverse of the select query. Returns all the objects that do not match the conditions.
 @param pickedKey the key for which the values should be returned after the dont_select query is performed
 */
- (void)whereKey:(NSString *)key equalToResultOfDontSelectQuery:(BuiltQuery *)dontSelectQuery forKey:(NSString *)pickedKey;

/**
Tags in which to search objects

     //Obj-C
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *selectQuery = [projectClass query];
     [selectQuery whereTagsContains:@[@"ui", @"ux", @"design"]];
 
     //Swift
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var selectQuery:BuiltQuery = projectClass.query()
     selectQuery.whereTagsContains(["ui", "ux", "design"])

@param tags Array of tags string.
 */
- (void)whereTagsContains:(NSArray *)tags;

//MARK: Selective fields using  includeOnly/includeAll -
/**---------------------------------------------------------------------------------------
 * @name Selective fields using  includeOnly/includeAll
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Specifies an array of 'only' keys in BASE object that would be included in the response.
 
 
     //Obj-C
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery includeOnlyFields:@["name"]];
 
     //Swift
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.includeOnlyFields(["name"])
 
 @discussion Specifies an array of keys in BASE object that would be included in the response.
 @param fieldUIDs Array of the 'only' keys to be included in response.
 */
- (void)includeOnlyFields:(NSArray *)fieldUIDs;

/**
 @abstract Specifies an array of keys in reference class object that would be 'excluded' from the response.
 
     //Obj-C
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery includeAllFieldsExcept:@["name"]];
     
     //Swift
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.includeAllFieldsExcept(["name"])
 
 
 @discussion Specifies an array of keys in BASE object that would be 'excluded' from the response.
 @param fieldUIDs Array of keys to be excluded from the response.
 */
- (void)includeAllFieldsExcept:(NSArray *)fieldUIDs;


//MARK: Sub Query using inQuery/notInQuery -
/**---------------------------------------------------------------------------------------
 * @name Sub query using inQuery/notInQuery
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract perform query based on referred objects
 
     //Obj-C
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery whereKey:@"name" equalTo:@"Super Project #41!"];
     
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery inQuery:projectQuery forKey:@"project"];
     
     //Swift
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.whereKey("name", equalTo: "Super Project #41")
     
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.inQuery(projectQuery, forKey:"project")
 
 @discussion fetch objects for a class by querying the fields in the referred object. Use inQuery if you want to fetch objects that match the conditions specified. Can be used for nested references.(referred object inside referred object and so on)
 @param query the query to perform on the referred object
 @param key the key of the referred object
 */
- (void)inQuery:(BuiltQuery *)query forKey:(NSString *)key;

/**
 @abstract perform query based on referred objects
 
     //Obj-C
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [projectQuery whereKey:@"name" equalTo:@"Super Project #41!"];
     
     BuiltClass *bugsClass = [builtApplication classWithUID:@"bugs"];
     BuiltQuery *bugsQuery = [bugsClass query];
     [bugsQuery notInQuery:projectQuery forKey:@"project"];
     
     //Swift
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     projectQuery.whereKey("name", equalTo: "Super Project #41")
     
     var bugsClass:BuiltClass = builtApplication.classWithUID("bugs")
     var bugsQuery:BuiltQuery = bugsClass.query()
     bugsQuery.notInQuery(projectQuery, forKey:"project")
 
 @discussion fetch objects for a class by querying the fields in the referred object. Use notinQuery if you want to fetch objects that do not match the conditions specified (negation of inQuery). Can be used for nested references.(referred object inside referred object and so on)
 @param query the query to perform on the referred object
 @param key the key of the referred object
 */
- (void)notInQuery:(BuiltQuery *)query forKey:(NSString *)key;

//MARK: Reference Query (Query Conditions on Reference fields) -
/**---------------------------------------------------------------------------------------
 * @name Reference Query (Query Conditions on Reference fields)
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Include reference objects with given key in response
 
     //Obj-C
     BuiltClass *commentClass = [builtApplication classWithUID:@"comment"];
     BuiltQuery *commentQuery = [commentClass query];
     [commentQuery includeReference:@[@"for_bug"]];
 
     //Swift
     var commentClass:BuiltClass = builtApplication.classWithUID("comment")
     var commentQuery:BuiltQuery = commentClass.query()
     commentQuery.includeReference(["for_bug"])
 
 
 @discussion The include parameter accepts the name of a reference field. By default, no reference field is bought along with the object, only the uids are. To include any reference, this parameter must be used. Nested references can be bought by "." separating the references. This will work for references which are nested inside groups or references which are nested inside other references.
 @param key Array of reference keys to include in response.
 */
- (void)includeReference:(NSArray *)key;

/**
 @abstract Specifies an array of 'only' keys in reference class object that would be included in the response.
 
     //Obj-C
     BuiltClass *commentClass = [builtApplication classWithUID:@"comment"];
     BuiltQuery *commentQuery = [commentClass query];
     [commentQuery includeReference:@[@"for_bug"] onlyFields:@[@"name",@"description"]];
     
     //Swift
     var commentClass:BuiltClass = builtApplication.classWithUID("comment")
     var commentQuery:BuiltQuery = commentClass.query()
     commentQuery.includeReference(["for_bug"], onlyFields:["name","description"])
 
 
 @discussion Specifies an array of keys in reference class object that would be included in the response.
 @param key Key who has reference to some other class object.
 @param fieldUIDs Array of the 'only' reference keys to be included in response.
 */
- (void)includeReference:(NSString *)key onlyFields:(NSArray *)fieldUIDs;

/**
 @abstract Specifies an array of keys in reference class object that would be 'excluded' from the response.
 
 
     //Obj-C
     BuiltClass *commentClass = [builtApplication classWithUID:@"comment"];
     BuiltQuery *commentQuery = [commentClass query];
     [commentQuery includeReference:@[@"for_bug"] excludingFields:@[@"description"]];
     
     //Swift
     var commentClass:BuiltClass = builtApplication.classWithUID("comment")
     var commentQuery:BuiltQuery = commentClass.query()
     commentQuery.includeReference(["for_bug"], excludingFields:["description"])
 
 
 @discussion Specifies an array of keys in reference class object that would be 'excluded' from the response.
 @param key Key who has reference to some other class object.
 @param fieldUIDs Array of the 'only' reference keys to be 'excluded' from the response.
 */
- (void)includeReference:(NSString *)key excludingFields:(NSArray *)fieldUIDs;

//MARK: Geo Queries -
/**---------------------------------------------------------------------------------------
 * @name Geo Queries
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract fetch objects that are within specified locations.
 
    //Obj-C
    BuiltClass *personClass = [builtApplication classWithUID:@"person"];
    BuiltQuery *personQuery = [personClass query];

    // create a location object
    BuiltLocation *locationObj1 = [BuiltLocation locationWithLongitude:72.82519 andLatitude:19.47468];
    BuiltLocation *locationObj2 = [BuiltLocation locationWithLongitude:72.83172 andLatitude:19.47582];
    BuiltLocation *locationObj3 = [BuiltLocation locationWithLongitude:72.82854  andLatitude:19.47161];

    [personQuery withinLocations:@[locationObj1, locationObj2, locationObj3]];
 
 
    //Swift
    var personClass:BuiltClass = builtApplication.classWithUID("person")
    var personQuery:BuiltQuery = personClass.query()

    // create a location object
    var locationObj1:BuiltLocation = BuiltLocation(longitude: 72.82519, andLatitude: 19.47468)
    var locationObj2:BuiltLocation = BuiltLocation(longitude: 72.83172, andLatitude: 19.47582)
    var locationObj3:BuiltLocation = BuiltLocation(longitude: 72.82854, andLatitude: 19.47161)

    personQuery.withinLocations([locationObj1, locationObj2, locationObj3])
 
 @param locations an array of locations. Locations can have objects of `BuiltLocation` or object uids. If object uid is passed, the location of that object will be used.
 At least three locations need to be passed so that the search area is a polygon.
 */
- (void)withinLocations:(NSArray *)locations;

/**
 @abstract fetch objects that are near a specified location within a given radius
 
 
     //Obj-C
     BuiltClass *personClass = [builtApplication classWithUID:@"person"];
     BuiltQuery *personQuery = [personClass query];
     
     // create a location object
     BuiltLocation *locationObj = [BuiltLocation locationWithLongitude:72.8 andLatitude:19.4667];
     [personQuery nearLocation:locationObj withRadius:1000];
 
     //Swift
     var personClass:BuiltClass = builtApplication.classWithUID("person")
     var personQuery:BuiltQuery = personClass.query()
     
     // create a location object
     var locationObj:BuiltLocation = BuiltLocation(longitude: 72.8, andLatitude: 19.4667)
     personQuery.nearLocation(locationObj, withRadius: 1000)
 
 
 @param location the location near which you wish to query. Location can be an object of `BuiltLocation` or an object uid. In the latter case, it will use the object's location.
 @param radius the radius within which you wish to query
 */
- (void)nearLocation:(id)location withRadius:(double)radius;

//MARK: RawQuery -
/**---------------------------------------------------------------------------------------
 * @name RawQuery
 *  ---------------------------------------------------------------------------------------
 */

/**
Set a raw query to execute.
 
     //Obj-C
     BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
     BuiltQuery *projectQuery = [projectClass query];
     [personQuery setRawQuery:[NSString stringWithFormat:@"{\"name\":%@,\"description\":{\"$regex\":%@,\"$options\":\"i\"}}",@"Project showcase #1 !",@"checking"]];

     //Swift
     var projectClass:BuiltClass = builtApplication.classWithUID("project")
     var projectQuery:BuiltQuery = projectClass.query()
     personQuery.setRawQuery("{\"name\":\"" + "Project showcase #1 !" + "\",\"description\":{\"$regex\":\"" + "checking" + "\",\"$options\":\"i\"}}")

 
@param rawQueryString Query string you get from AdvanceQuery from buil.io Backend WebUI
 */
- (void)setRawQuery:(NSString*)rawQueryString;

//MARK: Delta methods -
/**---------------------------------------------------------------------------------------
 * @name Delta methods
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Get delta objects created on and after certain time given by user
 
 
     //Obj-C
     NSDate *createDate = @"25-03-2015";// Create new instance of date in this format
     [projectQuery createdAt:createDate];
     
     //Swift
     var createDate:NSDate = "25-03-2015";// Create new instance of date in this format
     projectQuery.createdAt(createDate)
 
 
 @param date Date condition on which delta to be applied.
 @discussion Time in format of DD-MM-YYYY OR DD-MM-YYYY HH:MM:SS.
 */
- (void)createdAt:(NSDate *)date;


/**
 @abstract Get delta objects updated on and after certain time given by user
 
 
     //Obj-C
     NSDate *updateDate = @"25-03-2015";// Create new instance of date in this format
     [projectQuery updatedAt:updateDate];
     
     //Swift
     var updateDate:NSDate = "25-03-2015";// Create new instance of date in this format
     projectQuery.updatedAt(updateDate)
 
 
 @param date Date condition on which delta to be applied.
 @discussion Time in format of DD-MM-YYYY OR DD-MM-YYYY HH:MM:SS.
 */
- (void)updatedAt:(NSDate *)date;


/**
 @abstract Get delta objects deleted on and after certain time given by user
 
     //Obj-C
     NSDate *deleteDate = @"25-03-2015";// Create new instance of date in this format
     [projectQuery deletedAt:deleteDate];
     
     //Swift
     var deleteDate:NSDate = "25-03-2015";// Create new instance of date in this format
     projectQuery.deletedAt(deleteDate)
 
 
 @param date Date condition on which delta to be applied.
 @discussion Time in format of DD-MM-YYYY OR DD-MM-YYYY HH:MM:SS.
 */
- (void)deletedAt:(NSDate *)date;

/**
 @abstract Get ALL delta objects updated, deleted, created on and after certain time given by user
 
     //Obj-C
     NSDate *date = @"25-03-2015";// Create new instance of date in this format
     [projectQuery allDeltaAt:date];
     
     //Swift
     var date:NSDate = "25-03-2015";// Create new instance of date in this format
     projectQuery.allDeltaAt(date)
 
 
 @param date Date condition on which delta to be applied.
 @discussion Time in format of DD-MM-YYYY OR DD-MM-YYYY HH:MM:SS.
 */
- (void)allDeltaAt:(NSDate *)date;

//MARK: Execute Query -
/**---------------------------------------------------------------------------------------
 * @name Execute Query
 *  ---------------------------------------------------------------------------------------
 */


/**
 @abstract Execute a Query asynchronously.
 
     //Obj-C
     [projectQuery exec:^(BuiltResponseType type, BuiltQueryResult *result, NSError *error) {
     
     }];
     
     //Swift
     projectQuery.exec { (responseType, result!, error!) -> Void in
     
     }
 
 
 @discussion Executes a single or a chained query and callbacks the `QueryResult` with `ResponseType`.
 @param completionBlock CallBack called after network call.
 */
- (void)exec:(void (^) (BuiltResponseType type, BuiltQueryResult * BUILT_NULLABLE_P result, NSError * BUILT_NULLABLE_P error))completionBlock;

//MARK: - Export Excel
/**---------------------------------------------------------------------------------------
 * @name Export Excel
 *  ---------------------------------------------------------------------------------------
 */
/**
 exports excel file asyncronously from Built.io Backend server to app
 
     //Obj-C
      BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
      BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
      BuiltQuery *query = [projectClass query];
      [query exportToExcel:^(BuiltResponseType responseType, NSString * _Nonnull filePath, NSError * _Nonnull error) {
 
      }
 
      //Swift
      var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
      var projectClass:BuiltClass = builtApplication.classWithUID("project")
      let query:BuiltQuery = builtApplication.userQuery()
      query.export { (responseType, filePath, error) in
 
      }
     }
 
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSString * BUILT_NULLABLE_P filePath, NSError * BUILT_NULLABLE_P error)
 
 */
- (void)exportToExcel:(void (^) (BuiltResponseType responseType, NSString * BUILT_NULLABLE_P filePath, NSError * BUILT_NULLABLE_P error))completionBlock ;

/**
 exports excel file asyncronously from Built.io Backend server to app
 
      //Obj-C
      BuiltApplication *builtApplication = [Built applicationWithAPIKey:@"blt5d4sample2633b"];
      BuiltClass *projectClass = [builtApplication classWithUID:@"project"];
      BuiltQuery *query = [projectClass query];
      NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
      NSString *documentsDirectory = [paths objectAtIndex:0];
      NSString *folderPath = [documentsDirectory stringByAppendingPathComponent:@"/UserFolder"];
      [query exportToExcelAtPath:folderPath completion:^(BuiltResponseType responseType, NSString * _Nonnull filePath, NSError * _Nonnull error) {
 
      }
 
      //Swift
      var builtApplication:BuiltApplication = Built.applicationWithAPIKey("blt5d4sample2633b")
      var projectClass:BuiltClass = builtApplication.classWithUID("project")
      let query:BuiltQuery = projectClass.userQuery()
      let fileManager = FileManager.default
      if let documentsDirectory = fileManager.urls(for: .documentDirectory, in: .userDomainMask).first {
      let folderPath = documentsDirectory.appendingPathComponent("/UserFolder").path
      query.exportToExcel(atPath: folderPath) { (responseType, filePath, error) in
 
      }
      }
 
 @param folderPath should be valid path with read and write permission where we wish to export to.
 @param completionBlock Completion block with params (BuiltResponseType responseType, NSString * BUILT_NULLABLE_P filePath, NSError * BUILT_NULLABLE_P error)
 
 @note folderPath should have read/write permission.
 
 */
- (void)exportToExcelAtPath:(NSString*)folderPath completion:(void (^) (BuiltResponseType responseType, NSString * BUILT_NULLABLE_P filePath, NSError * BUILT_NULLABLE_P error))completionBlock;


//MARK: Cancel execution -
/**---------------------------------------------------------------------------------------
 * @name Cancel execution
 *  ---------------------------------------------------------------------------------------
 */

/**
 @abstract Advises the operation object that it should stop executing its task.
 
     //Obj-C
     [projectQuery cancelRequests];
     
     //Swift
     projectQuery.cancelRequests()
 
 
 @discussion This method does not force your operation code to stop. Instead, it updates the object’s internal flags to reflect the change in state. If the operation has already finished executing, this method has no effect. Canceling an operation that is currently in an operation queue, but not yet executing, makes it possible to remove the operation from the queue sooner than usual.
 */
- (void)cancelRequests;

@end

BUILT_ASSUME_NONNULL_END
