//
//  IasModel.h
//  IpaAdSDK
//
//  Created by Leo on 11/04/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, IasAdFormat) {
    IasAdFormatNative = 0,
    IasAdFormatRewardedVideo = 1,
    IasAdFormatBanner = 2,
    IasAdFormatInterstitial = 3,
    IasAdFormatSplash = 4,
    IasAdFormatMediaVideo = 50
};

typedef NS_ENUM(NSInteger, IasEndCardClickable) {
    IasEndCardClickableFullscreen = 1,
    IasEndCardClickableCTA,
    IasEndCardClickableBanner
};

typedef NS_ENUM(NSInteger, IasScreenOrientation) {
    IasScreenOrientationPortrait,
    IasScreenOrientationLandscape
};

typedef NS_ENUM(NSInteger, IasInterstitialType) {
    IasInterstitialVideo = 1,
    IasInterstitialPicture
};

typedef NS_ENUM(NSInteger, IasLinkType) {
    IasLinkTypeAppStore = 1,
    IasLinkTypeSafari,
    IasLinkTypeWebView,
    IasLinkTypeInnerSafari = 5,
    IasLinkTypeWXMiniProgram = 6
};

typedef NS_ENUM(NSInteger, IasOfferLayoutType) {
    IasOfferLayoutTypeNormal = 0,
    IasOfferLayoutTypeExpress
};

typedef NS_ENUM(NSInteger, IasClickMode) {
    IasClickModeSync = 1,
    IasClickModeAsync
};

typedef NS_ENUM(NSInteger, IasLoadType) {
    IasLoadTypeBrowser = 1,
    IasLoadTypeInternalBrowser
};

typedef NS_ENUM(NSInteger, IasUserAgentType) {
    IasUserAgentWebView = 1,
    IasUserAgentSystem
};

typedef NS_ENUM(NSInteger, IasLoadStorekitTime) {
    IasLoadStorekitTimePreload = 1,
    IasATLoadStorekitTimeClick,
    IasATLoadStorekitTimeNone
};
typedef NS_ENUM(NSInteger, IasVideoClickable) {
    IasVideoClickableNone = 1,
    IasVideoClickableWithCTA
};

typedef NS_ENUM(NSInteger, IasNetworkFirmId) {
    IasNetworkFirmIdADX =  66,
    IasNetworkFirmIdMyOffer = 35,
    IasNetworkFirmIdGDTOnline = 42,
    IasNetworkFirmIdDirectOffer =  67,
};

typedef NS_ENUM(NSInteger, IasOfferModelType) {
    IasOfferModelMyOffer = 1,
    IasOfferModelADX =  2,
    IasOfferModelOnlineApi =  3,
    IasOfferModelDirectOffer =  4,
};

typedef NS_ENUM(NSInteger, IasOfferCrtType) {
    IasOfferCrtTypeOneImage = 1,
    IasOfferCrtTypeImages = 2,
    IasOfferCrtTypeOneImageWithText = 3,
    IasOfferCrtTypeImagesWithText = 4,
    IasOfferCrtTypeVideo = 5,
    IasOfferCrtTypeXHTML = 6
};

typedef NS_ENUM(NSInteger, IasDeepLinkClickMode) {
    IasDeepLinkModeNone = 1,
    IasDeepLinkModePreClickUrl = 2,
    IasDeepLinkModeLastClickUrl = 3
};

typedef NS_ENUM(NSInteger, IasClickType) {
    IasClickTypeClickUrl = 1,
    IasClickTypeDeepLinkUrl,
    IasClickTypeClickJumpUrl
};

typedef NS_ENUM(NSInteger, IasUnitGroupType) {
    IasUnitGroupTypeNormal = 1,
    IasUnitGroupTypeAdx,
    IasUnitGroupTypeC2S,
    IasUnitGroupTypeS2S,
    IasUnitGroupTypeInHouse,
    IasUnitGroupTypeBKS,
    IasUnitGroupTypeDirectOffer,
    IasUnitGroupTypeDefault,
    IasUnitGroupTypeDynamicHB,
    IasUnitGroupTypeDynamicC2S,
    IasUnitGroupTypeDynamicS2S,

};

typedef NS_ENUM(NSInteger, IasSplashType) {
    IasSplashTypeSplice = 1,
    IasSplashTypeFullScreen
};

typedef NS_ENUM(NSInteger, IasSplashImageScaleType) {
    IasSplashImageScaleTypeFit = 1,
    IasSplashImageScaleTypeFill
};

typedef NS_ENUM(NSInteger, IasBiddingCurrencyType) {
    IasBiddingCurrencyTypeUS        = 1,
    IasBiddingCurrencyTypeCNY       = 2,
    IasBiddingCurrencyTypeCNYCents  = 3
};

typedef NS_ENUM(NSInteger, IasOfferClickAdType) {
    IasOfferClickAdTypeUserClick = 1,
    IasOfferClickAdTypeAutoClickAfterDelay =  2,
    IasOfferClickAdTypeAutoClickAfterFinish = 3,
    IasOfferClickAdTypeShakeClick = 4,
    IasOfferClickAdTypeAutoClickImageClick = 5,
    IasOfferClickAdTypeAutoClickVideoClick = 6,
    IasOfferClickAdTypeAutoClickEndCardClick = 7,
    IasOfferClickAdTypeStoresKitClick = 8,
    IasOfferClickAdTypeSKOverlyClick = 9,
    IasOfferClickAdTypeInvalidCloseButtonClick = 10,
    IasOfferClickAdTypeGuideOverlyClick = 11,
    IasOfferClickAdTypeAdWithoutSlideClick = 12,
    IasOfferClickAdTypeAdInsideSlideClick = 13,
    IasOfferClickAdTypeEndCardFloatingLayerGuideClick = 14,
    IasOfferClickAdTypeEndCardRetentionPageClick = 15,
    IasOfferClickAdTypeRewardedVideoTaskClick = 16,
    IasOfferClickAdTypeBubbleDropClick = 17,
};

typedef NS_ENUM(NSInteger, IasOfferAdpType) {
    IasOfferAdpTypeNormal = 0,
    IasOfferAdpTypeMraid = 1,
    IasOfferAdpTypeVast = 2
};

typedef NS_ENUM(NSInteger, IasOfferADPAcceptType) {
    IasOfferADPAcceptTypeMraid = 1,
    IasOfferADPAcceptTypeVast = 2
};

typedef NS_ENUM(NSInteger, IasGuideClickOverlayType) {
    IasGuideClickOverlayTypeUnknown            = 0,
    IasGuideClickOverlayTypeGestureGuidance    = 1,
    IasGuideClickOverlayTypeDragPuzzle         = 2,
    IasGuideClickOverlayTypeQAPopup            = 3,
    IasGuideClickOverlayTypeNoviceGuide        = 4,
    IasGuideClickOverlayTypeConfirmJump        = 5,
    IasGuideClickOverlayTypeFingerClickGuide   = 6,
    IasGuideClickOverlayTypeFullScreenSwipe    = 7,
    IasGuideClickOverlayTypeLuckybag           = 8,
    IasGuideClickOverlayTypeChopOnce           = 9,
    IasGuideClickOverlayTypeSlidePuzzle        = 10,
    IasGuideClickOverlayTypeGestureSlide       = 11,
    IasGuideClickOverlayTypeGesureClick        = 12,
    IasGuideClickOverlayTypeBigWhiteHand       = 13
};

typedef NS_ENUM(NSInteger, IasRVTncentiveTaskType) {
    IasRVTncentiveTaskTypeNone              = 1,
    IasRVTncentiveTaskTypeReduceDuration    = 2,
    IasRVTncentiveTaskTypeADFree            = 3
};

typedef NS_ENUM(NSInteger, IasAdOfferInterType) {
    IasAdOfferInterTypeFull = 1,
    IasAdOfferInterTypeHalf
};

typedef NS_ENUM(NSInteger, IasADXMixFormat) {
    IasADXMixFormatNative = 1,
    IasADXMixFormatRewardedVideo = 2,
    IasADXMixFormatBanner = 3,
    IasADXMixFormatInterstitial = 4,
    IasADXMixFormatSplash = 5,
};

@interface IasModel : NSObject

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
