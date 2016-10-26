//
//  BuiltDefinitions.h
//  BuiltIO
//
//  Created by Reefaq on 16/10/14.
//  Copyright (c) 2014 raweng. All rights reserved.
//

#ifndef BuiltIO_BuiltDefinitions_h
#define BuiltIO_BuiltDefinitions_h

//MARK: - Support-Macros

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

    #if __has_feature(nullability)
    #  define BUILT_NONNULL nonnull
    #  define BUILT_NULLABLE nullable
    #  define BUILT_NONNULL_P _Nonnull
    #  define BUILT_NULLABLE_P _Nullable
    #else
    #  define BUILT_NONNULL
    #  define BUILT_NULLABLE
    #  define BUILT_NONNULL_P
    #  define BUILT_NULLABLE_P
    #endif

    #if __has_feature(assume_nonnull)
    #  ifdef NS_ASSUME_NONNULL_BEGIN
    #    define BUILT_ASSUME_NONNULL_BEGIN NS_ASSUME_NONNULL_BEGIN
    #  else
    #    define BUILT_ASSUME_NONNULL_BEGIN _Pragma("clang assume_nonnull begin")
    #  endif
    #  ifdef NS_ASSUME_NONNULL_END
    #    define BUILT_ASSUME_NONNULL_END NS_ASSUME_NONNULL_END
    #  else
    #    define BUILT_ASSUME_NONNULL_END _Pragma("clang assume_nonnull end")
    #  endif
    #else
    #  define BUILT_ASSUME_NONNULL_BEGIN
    #  define BUILT_ASSUME_NONNULL_END
    #endif

//MARK: - Enums

    typedef NS_ENUM(NSUInteger, BuiltNetworkCachePolicy) {
        NETWORK_ONLY = 0,
        CACHE_ONLY,
        CACHE_ELSE_NETWORK,
        NETWORK_ELSE_CACHE,
        CACHE_THEN_NETWORK
    };

    typedef NS_ENUM(NSUInteger, BuiltResponseType){
        CACHE = 0,
        NETWORK,
        LOCALSTORE
    };

    typedef NS_ENUM(NSUInteger, BuiltReachabilityStatus) {
        BuiltReachabilityStatusUnknown          = -1,
        BuiltReachabilityStatusNotReachable     = 0,
        BuiltReachabilityStatusReachableViaWWAN = 1,
        BuiltReachabilityStatusReachableViaWiFi = 2,
    };

//MARK: - TypeDef

    typedef void (^BuiltRequestCompletionHandler)(BuiltResponseType responseType, NSError * BUILT_NULLABLE_P error);

    typedef void (^BuiltRechabilityChangeHandler)(BuiltReachabilityStatus status);


//MARK: - Macros

#ifndef Built_IOS_UNAVAILABLE
#  ifdef __IOS_UNAVILABLE
#    define Built_IOS_UNAVAILABLE __IOS_UNAVAILABLE
#  else
#    define Built_IOS_UNAVAILABLE
#  endif
#endif

#ifndef Built_IOS_UNAVAILABLE_WARNING
#  if TARGET_OS_IOS
#    define Built_IOS_UNAVAILABLE_WARNING _Pragma("GCC warning \"This class is unavailable on iOS.\"")
#  else
#    define Built_IOS_UNAVAILABLE_WARNING
#  endif
#endif

#ifndef Built_OSX_UNAVAILABLE
#  if Built_TARGET_OS_OSX
#    define Built_OSX_UNAVAILABLE __OSX_UNAVAILABLE
#  else
#    define Built_OSX_UNAVAILABLE
#  endif
#endif

#ifndef Built_OSX_UNAVAILABLE_WARNING
#  if Built_TARGET_OS_OSX
#    define Built_OSX_UNAVAILABLE_WARNING _Pragma("GCC warning \"This class is unavailable on OS X.\"")
#  else
#    define Built_OSX_UNAVAILABLE_WARNING
#  endif
#endif

#ifndef Built_WATCH_UNAVAILABLE
#  ifdef __WATCHOS_UNAVAILABLE
#    define Built_WATCH_UNAVAILABLE __WATCHOS_UNAVAILABLE
#  else
#    define Built_WATCH_UNAVAILABLE
#  endif
#endif

#ifndef Built_WATCH_UNAVAILABLE_WARNING
#  if TARGET_OS_WATCH
#    define Built_WATCH_UNAVAILABLE_WARNING _Pragma("GCC warning \"This class is unavailable on watchOS.\"")
#  else
#    define Built_WATCH_UNAVAILABLE_WARNING
#  endif
#endif

#ifndef Built_TV_UNAVAILABLE
#  ifdef __TVOS_PROHIBITED
#    define Built_TV_UNAVAILABLE __TVOS_PROHIBITED
#  else
#    define Built_TV_UNAVAILABLE
#  endif
#endif

#ifndef Built_TV_UNAVAILABLE_WARNING
#  if TARGET_OS_TV
#    define Built_TV_UNAVAILABLE_WARNING _Pragma("GCC warning \"This class is unavailable on tvOS.\"")
#  else
#    define Built_TV_UNAVAILABLE_WARNING
#  endif
#endif

#endif
