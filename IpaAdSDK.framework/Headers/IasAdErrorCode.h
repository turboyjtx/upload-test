//
//  IasAdErrorCode.h
//  IpaAdSDK
//
//  Created by IpaAd on 2024/5/27.
//  Copyright © 2024 IpaAd. All rights reserved.
//

#ifndef IasAdErrorCode_h
#define IasAdErrorCode_h

typedef NS_ENUM(NSInteger, IasAdErrorCode) {
    IasAdErrorCodePlacementStrategyInvalidResponse             = 1001,
    IasAdErrorCodePlacementStragetyNetworkError                = 1002,
    IasAdErrorCodeADOfferLoadingFailed                         = 1003,
    IasAdErrorCodePlacementStrategyNotFound                    = 1004,
    IasAdErrorCodeADOfferNotFound                              = 1005,
    IasAdErrorCodeShowIntervalWithinPlacementPacing            = 1006,
    IasAdErrorCodeShowTimesExceedsHourCap                      = 1007,
    IasAdErrorCodeShowTimesExceedsDayCap                       = 1008,
    IasAdErrorCodeAdapterClassNotFound                         = 1009,
    IasAdErrorCodeADOfferLoadingTimeout                        = 10010,
    IasAdErrorCodeSDKNotInitalizedProperly                     = 1011,
    IasAdErrorCodeDataConsentForbidden                         = 1012,
    IasAdErrorCodeThirdPartySDKNotImportedProperly             = 1013,
    IasAdErrorCodeInvalidInputEncountered                      = 1014,
    IasAdErrorCodePlacementAdDeliverySwitchOff                 = 1015,
    IasAdErrorCodePreviousLoadNotFinished                      = 1016,
    IasAdErrorCodeNoUnitGroupsFoundInPlacement                 = 1017,
    IasAdErrorCodeUnitGroupsFilteredOut                        = 1018,
    IasAdErrorCodeFailureTooFrequent                           = 1019,
    IasAdErrorCodeLoadCapsExceeded                             = 1020,
    IasAdErrorCodeUnitGroupsExpired                            = 1021,
    IasAdErrorCodeDebuggerNoUnitGroupsFoundInPlacement         = 1029,
    IasAdErrorCodeAdSourceNotFilledCauseByCustomizeFillter     = 1030,
    IasAdErrorCodeCanNotLoadWhenAppBackground                  = 1031,
    IasAdErrorCodeCanNotLoadSharePlacement                     = 10019,
    IasAdErrorCodeADXFailedCode                                = 3001
};

#endif /* IasAdErrorCode_h */
