//
//  BuiltDefinitions.h
//  BuiltIO
//
//  Created by Reefaq on 16/10/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#ifndef BuiltIO_BuiltDefinitions_h
#define BuiltIO_BuiltDefinitions_h

    #ifndef NS_ENUM
    #   define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
    #endif

    #ifndef NS_OPTIONS
    #   define NS_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
    #endif

    #ifndef BUILTIO_DEPRECATED
    #  ifdef __deprecated_msg
    #    define BUILTIO_DEPRECATED(_MSG) __deprecated_msg(_MSG)
    #  else
    #    ifdef __deprecated
    #      define BUILTIO_DEPRECATED(_MSG) __attribute__((deprecated))
    #    else
    #      define BUILTIO_DEPRECATED(_MSG)
    #    endif
    #  endif
    #endif

    typedef NS_ENUM(NSUInteger, CachePolicy) {
        NETWORK_ONLY = 0,
        CACHE_ONLY,
        CACHE_ELSE_NETWORK,
        NETWORK_ELSE_CACHE,
        CACHE_THEN_NETWORK
    };

    typedef NS_ENUM(NSUInteger, ResponseType){
        CACHE = 0,
        NETWORK,
        HOOK
    };

    typedef NS_ENUM(NSUInteger, BuiltReachabilityStatus) {
        BuiltReachabilityStatusUnknown          = -1,
        BuiltReachabilityStatusNotReachable     = 0,
        BuiltReachabilityStatusReachableViaWWAN = 1,
        BuiltReachabilityStatusReachableViaWiFi = 2,
    };

    typedef void (^BuiltRequestCompletionHandler)(ResponseType responseType, NSError *error);

    typedef void (^BuiltRechabilityChangeHandler)(BuiltReachabilityStatus status);

#endif
