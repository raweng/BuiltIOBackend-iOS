//
//  BuiltErrorCodes.h
//  builtDemo
//
//  Created by Akshay Mhatre on 04/06/13.
//  Copyright (c) 2013 raweng. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BuiltErrorCodes : NSObject

//Domain
FOUNDATION_EXPORT NSString *const kBuiltErrorDomain;

//101-299 Server error
FOUNDATION_EXPORT NSInteger const kErrorUnauthorizedAccess;//105
FOUNDATION_EXPORT NSInteger const kErrorForgotPasswordUserNotFound;//107
FOUNDATION_EXPORT NSInteger const kErrorApplicationNotFound;//109
FOUNDATION_EXPORT NSInteger const kErrorInvalidClass;//118
FOUNDATION_EXPORT NSInteger const kErrorObjectCreateFailed;//119
FOUNDATION_EXPORT NSInteger const kErrorInvalidObjectClassUid;//120
FOUNDATION_EXPORT NSInteger const kErrorObjectUpdateFailed;//121
FOUNDATION_EXPORT NSInteger const kErrorObjectDeleteFailed;//122
FOUNDATION_EXPORT NSInteger const kErrorObjectUpsertFailed;//123
FOUNDATION_EXPORT NSInteger const kErrorNotificationCreateFailed;//124
FOUNDATION_EXPORT NSInteger const kErrorNotificationDeleteFailed;//125
FOUNDATION_EXPORT NSInteger const kErrorInvalidNotification;//126
FOUNDATION_EXPORT NSInteger const kErrorAppUserCreateFailed;//127
FOUNDATION_EXPORT NSInteger const kErrorAppUserUpdateFailed;//128
FOUNDATION_EXPORT NSInteger const kErrorAppUserDeleteFailed;//129
FOUNDATION_EXPORT NSInteger const kErrorAppUserNotFound;//130
FOUNDATION_EXPORT NSInteger const kErrorAppUserLoggedInFailed;//131
FOUNDATION_EXPORT NSInteger const kErrorAppUserLoggedOutFailed;//132
FOUNDATION_EXPORT NSInteger const kErrorAccessDenied;//133
FOUNDATION_EXPORT NSInteger const kErrorNotificationCredentialsCreateFailed;//134
FOUNDATION_EXPORT NSInteger const kErrorNotificationCredentialsUpdateFailed;//135
FOUNDATION_EXPORT NSInteger const kErrorInstallationNotCreated;//136
FOUNDATION_EXPORT NSInteger const kErrorInstallationNotUpdated;//137
FOUNDATION_EXPORT NSInteger const kErrorInstallationFailedSubscribe;//138
FOUNDATION_EXPORT NSInteger const kErrorInstallationFailedUnsubscribe;//139
FOUNDATION_EXPORT NSInteger const kErrorChannelsNotProvidedForSubUnsubcribe;//140
FOUNDATION_EXPORT NSInteger const kErrorInvalidParameters;//141
FOUNDATION_EXPORT NSInteger const kErrorUploadCreateFailed;//142
FOUNDATION_EXPORT NSInteger const kErrorUploadUpdateFailed;//143
FOUNDATION_EXPORT NSInteger const kErrorUploadDeleteFailed;//144
FOUNDATION_EXPORT NSInteger const kErrorUploadNotFound;//145
FOUNDATION_EXPORT NSInteger const kErrorAppUserInvalidActivationToken;//147
FOUNDATION_EXPORT NSInteger const kErrorAppUserInvalidEmail;//148
FOUNDATION_EXPORT NSInteger const kErrorAppUserResetPasswordFail;//149
FOUNDATION_EXPORT NSInteger const kErrorAppSettingsFail;//150
FOUNDATION_EXPORT NSInteger const kErrorApplicationUsersDeleteAll;//152
FOUNDATION_EXPORT NSInteger const kErrorCustomNotificationNotFound;//153
FOUNDATION_EXPORT NSInteger const kErrorCustomNotificationNotCreated;//154
FOUNDATION_EXPORT NSInteger const kErrorCustomNotificationNotUpdated;//155
FOUNDATION_EXPORT NSInteger const kErrorAppUserAclAccessDenied;//162
FOUNDATION_EXPORT NSInteger const kErrorMarkerCreateFailed;//167
FOUNDATION_EXPORT NSInteger const kErrorMarkerUpdateFailed;//168
FOUNDATION_EXPORT NSInteger const kErrorMarkerDeleteFailed;//169
FOUNDATION_EXPORT NSInteger const kErrorInvalidMarker;//170
FOUNDATION_EXPORT NSInteger const kErrorEventCreationFailed;//171
FOUNDATION_EXPORT NSInteger const kErrorAppUserUidRetrieveFailed;//176
FOUNDATION_EXPORT NSInteger const kErrorUserUidRetrieveFailed;//177
FOUNDATION_EXPORT NSInteger const kErrorUploadDefaultAclUpdateFailed;//185
FOUNDATION_EXPORT NSInteger const kErrorAppUserAccountInactive;//190
FOUNDATION_EXPORT NSInteger const kErrorAppUserRegisterEmailTaken;//191
FOUNDATION_EXPORT NSInteger const kErrorAppUserRegisterPasswordInvalid;//192
FOUNDATION_EXPORT NSInteger const kErrorInternalServerError;//194
FOUNDATION_EXPORT NSInteger const kErrorNotFoundError;//195
FOUNDATION_EXPORT NSInteger const kErrorAccountNameBlank;//196
FOUNDATION_EXPORT NSInteger const kErrorClassUidBlank;//197
FOUNDATION_EXPORT NSInteger const kErrorInvalidApiKey;//198
FOUNDATION_EXPORT NSInteger const kErrorDeleteUserNotFound;//200
FOUNDATION_EXPORT NSInteger const kErrorRegistrationNotCreated;//217
FOUNDATION_EXPORT NSInteger const kErrorRegistrationNotUpdated;//218
FOUNDATION_EXPORT NSInteger const kErrorRegistrationNotFound;//219
FOUNDATION_EXPORT NSInteger const kErrorApiLimitReached;//232

//>450 - Cache Error
FOUNDATION_EXPORT NSInteger const kErrorNoCacheData;//450

//>500 - Socket Error
FOUNDATION_EXPORT NSInteger const kErrorRealtimeAuthFailed;//500
FOUNDATION_EXPORT NSInteger const kErrorRealtimeRegistrationFailed;//501
FOUNDATION_EXPORT NSInteger const kErrorRealtimeSubcriptionFailed;//502
FOUNDATION_EXPORT NSInteger const kErrorRealtimeBroadcastFailed;//503
FOUNDATION_EXPORT NSInteger const kErrorRealtimeCallFailed;//504
FOUNDATION_EXPORT NSInteger const kErrorRealtimePresenceSetFailed;//505
FOUNDATION_EXPORT NSInteger const kErrorRealtimePresenceGetFailed;//506
FOUNDATION_EXPORT NSInteger const kErrorRealtimePresenceRequestFailed;//507
FOUNDATION_EXPORT NSInteger const kErrorRealtimeStateSetFailed;//508
FOUNDATION_EXPORT NSInteger const kErrorRealtimeNotEnabled;//550

//>900 TwitterAcccount
FOUNDATION_EXPORT NSInteger const kErrorTwitterAccountNotFound;//900
FOUNDATION_EXPORT NSInteger const kErrorTwitterAccountPremissionDenied;//901
FOUNDATION_EXPORT NSInteger const kErrorTwitterOAuthVerificationFailed;//902

@end

