//
//  IasSDKGlobalSetting.h
//  IpaAdSDK
//
//  Created by IpaAd on 8/23/23.
//  Copyright © 2023 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasAdLoadingDelegate.h>

NS_ASSUME_NONNULL_BEGIN
@class IasCustomContentInfo, IasCustomContentResult;
extern NSString *const kIasDeviceDataInfoOSVersionNameKey; //System version name
extern NSString *const kIasDeviceDataInfoOSVersionCodeKey; //System version code
extern NSString *const kIasDeviceDataInfoPackageNameKey; //Application package name
extern NSString *const kIasDeviceDataInfoAppVersionNameKey; //Application version name
extern NSString *const kIasDeviceDataInfoAppVersionCodeKey; //Application version code
extern NSString *const kIasDeviceDataInfoBrandKey; //Phone brands
extern NSString *const kIasDeviceDataInfoModelKey; //Phone model
extern NSString *const kIasDeviceDataInfoScreenKey; //Screen Resolution
extern NSString *const kIasDeviceDataInfoNetworkTypeKey; //Network Type
extern NSString *const kIasDeviceDataInfoMNCKey; //Mobile Network Code
extern NSString *const kIasDeviceDataInfoMCCKey; //Mobile Country Code
extern NSString *const kIasDeviceDataInfoLanguageKey; //Language
extern NSString *const kIasDeviceDataInfoTimeZoneKey; //Time zone
extern NSString *const kIasDeviceDataInfoUserAgentKey; //User Agent
extern NSString *const kIasDeviceDataInfoOrientKey; //Screen orientation
extern NSString *const kIasDeviceDataInfoIDFAKey; //idfa
extern NSString *const kIasDeviceDataInfoIDFVKey; //idfv

typedef NS_ENUM(NSUInteger, IasSplashAdClickResultType) {
    IasSplashAdClickResultTypeDidCloseAd         = 1,  // After clicking on the jump button, close the splash ad
    IasSplashAdClickResultTypePauseCountdown     = 2,  // Pause the countdown after clicking the jump button, and continue the countdown when the splash ad is visible
};

/// Debug values for testing geography.
typedef NS_ENUM(NSInteger, IasUMPDebugGeography) {
    IasUMPDebugGeographyDisabled = 0,  ///< Disable geography debugging.
    IasUMPDebugGeographyEEA = 1,       ///< Geography appears as in EEA for debug devices.
    IasUMPDebugGeographyNotEEA = 2,    ///< Geography appears as not in EEA for debug devices.
};

typedef NS_ENUM(NSInteger, IasSystemPlatformType) {
    IasSystemPlatformTypeUnknown = 0,
    IasSystemPlatformTypeIOS = 1,
    IasSystemPlatformTypeUnity = 2,
    IasSystemPlatformTypeCocos2dx = 3,
    IasSystemPlatformTypeCocosCreator = 4,
    IasSystemPlatformTypeReactNative = 5,
    IasSystemPlatformTypeFlutter = 6,
    IasSystemPlatformTypeAdobeAir = 7
};

@interface IasSDKGlobalSetting : NSObject

+ (instancetype)sharedManager;

/*
 channel & customData has to be set before init
 */
@property (nonatomic, strong) NSString *channel;
@property (nonatomic, strong) NSString *subchannel;
@property (nonatomic, strong) NSDictionary *customData;
/// Splash Shake Text String, Only for DirectlyAd
@property (nonatomic, strong) NSString *directlySplashAdShakeTextString;
/// Splash CTA Button BackgroundColor, Only for DirectlyAd
@property (nonatomic, strong) UIColor *directlySplashAdCTAButtonBackgroundColor;
/// Splash Shake Custom View, Only for DirectlyAd
@property (nonatomic, strong) UIView *directlySplashAdCustomShakeView;
/// Splash CTA Custom View, Only for DirectlyAd
@property (nonatomic, strong) UIView *directlySplashAdCustomCTAView;
/// Splash Video Mute Icon hidden, Not hidden by default,  Only for DirectlyAd
@property (nonatomic, assign) BOOL directlySplashAdVideoMuteIconHidden;
/// Whether to pause the countdown after clicking on the  Splash ad to jump, the default is NO, Only for IpaAd ADX、DirectlyAd and Cross Promotion
@property (nonatomic, assign) IasSplashAdClickResultType splashAdClickResultType;

// ump test ids
@property (nonatomic, nullable,strong) NSArray<NSString *> *umpTestDeviceIdentifiers;
/// Debug geography.
@property (nonatomic, assign) IasUMPDebugGeography umpGeography;
/// set header bidding test mode,only support incoming device idfa.
/// setLogEnabled must be turned on before use
@property (nonatomic, strong) NSString *headerBiddingTestModeDeviceID;
/// system platform Information
@property (nonatomic, assign) IasSystemPlatformType systemPlatformType;

@property (nonatomic, strong) IasSharePlacementConfig *sharePlacementConfig;
/// set whether WX is installed
@property (nonatomic, assign) BOOL isInstallWX;
/// for setLocationLongitude:dimension:
@property (nonatomic, readonly) NSDictionary *locationDictionary;

/// set custom data for the ad placement
/// @param customData - custom data
/// @param placementID - placement id
- (void)setCustomData:(NSDictionary *)customData forPlacementID:(NSString *)placementID;

/// get custom data
- (NSDictionary *)customDataForPlacementID:(NSString *)placementID;

/// set Wechat appID and universalLink, for register WechatOpenSDK
/// @param appID - Wechat appID
/// @param universalLink - Wechat universalLink
- (void)setWeChatAppID:(NSString *)appID universalLink:(NSString *)universalLink;

- (void)addCustomAdapterConfigArray:(NSArray <IasCustomNetworkMode *>*)array;

/// set exlude appleid list for sdk to filter offers
- (void)setExludeAppleIdArray:(NSArray *)appleIdArray;

/// get exlude appleid list
- (NSArray *)exludeAppleIdArray;

/// set denied Upload Info list for sdk to Control report
- (void)setDeniedUploadInfoArray:(NSArray *)uploadInfoArray;

/// get denied Upload Info list
- (NSArray *)deniedUploadInfoArray;

/// Determine whether the Denied key is included
/// @param key - key string
- (BOOL)isContainsForDeniedUploadInfoArray:(NSString *)key;

- (void)setPresetPlacementConfigPathBundle:(NSBundle *)bundle;

/// set location longitude
- (void)setLocationLongitude:(double)longitude dimension:(double)dimension;

- (void)setDebuggerConfig:(void(^_Nullable)(IasDebuggerConfig * _Nullable debuggerConfig))debuggerConfigBlock;

- (void)setDeviceInfoConfig:(void(^_Nullable)(IasDeviceInfoConfig * _Nullable deviceInfoConfig))deviceInfoConfigBlock;

/// Delete all ads cached for the placementId
- (void)removeAllCacheWithPlacementId:(NSString *)placementId;
- (void)removeAllCacheWithPlacementId:(NSString *)placementId index:(NSInteger)index;
- (void)removeAllCacheWithPlacementId:(NSString *)placementId adInfoDictArray:(NSArray<NSDictionary *> *)adInfoDictArray;

- (void)setAuthNetworkArray:(NSArray <NSString *> *)networkFilmIdArray;

- (IasCustomContentInfo *)customContentReviewResult:(NSArray<IasCustomContentInfo *> *)infos;

- (IasCustomContentResult *)customContentResultReviewByInfos:(NSArray<IasCustomContentInfo *> *)infos;

@end

NS_ASSUME_NONNULL_END
