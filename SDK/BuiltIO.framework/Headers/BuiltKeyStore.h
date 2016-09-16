//
//  BuiltKeyStore.h
//  BuiltIO
//
//  Created by Reefaq on 11/01/16.
//  Copyright © 2016 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BuiltKeyStore : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

//MARK: - Set/GetProperties

/**
 Checks whether the keystore has a given property
 
     //Obj-C
     BOOL hasKey = [builtApplication.keystore hasKey:@"key"];
     if (hasKey) {
        //Has Key
     } else {
        //Key not found
     }
     
     //Swift
     var hasKey:Bool = builtApplication.keystore.hasKey("key")
     if (hasKey) {
        //Has Key
     } else {
        //Key not found
     }
 
 @param key The property to be checked
 @return true if key exists, false if not
 */
- (BOOL)hasKey:(NSString *)key;

//MARK: - set values for object's fields
/**
 *  Use this method to add a new key value pair in group.
 
     //Obj-C
     id object = [builtApplication.keystore setObject:@"Hello" forKey:@"key"];
     
     //Swift
     var object = builtApplication.keystore.setObject("Hello", forKey:"key")
 
 *  @param object object to set
 *  @param key    key to assign on.
 */
- (void)setObject:(id)object forKey:(NSString *)key;

/**
Gets the data for given property.
 
     //Obj-C
     id object = [builtApplication.keystore objectForKey:@"key"];
     
     //Swift
     var object = builtApplication.keystore.objectForKey("key")
 
 @param key The object's property
 @return The value for the key provided
 */
- (id)objectForKey:(NSString *)key;

/**
Removes the data for given key form keystore.
 
     //Obj-C
     id object = [builtApplication.keystore removeObjectForKey:@"key"];
     
     //Swift
     var object = builtApplication.keystore.removeObjectForKey("key")
 
 *  @param key Key which need to be removed.
 */
- (void)removeObjectForKey:(NSString*)key;

/**
Removes all the data form keystore.
 
    //Obj-C
    id object = [builtApplication.keystore removeAllObjects];

    //Swift
    var object = builtApplication.keystore.removeAllObjects()
 
 */
- (void)removeAllObjects;

//MARK: - Persist
/**
Save the data.
 
     //Obj-C
     id object = [builtApplication.keystore save];
     
     //Swift
     var object = builtApplication.keystore.save()
 
 */
- (void)save;

//MARK: - Subcripting
- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;
- (id)objectForKeyedSubscript:(id <NSCopying>)key;

@end
