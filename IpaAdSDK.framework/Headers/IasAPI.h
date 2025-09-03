//
//  IasAPI.h
//  IpaAdSDK
//
//  Created by Leo on 09/04/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <IpaAdSDK/IasNetwokBaseConfigure.h>
#import <IpaAdSDK/IasSDKConfiguration.h>
#import <IpaAdSDK/IasDebuggerConfig.h>
#import <IpaAdSDK/IasDeviceInfoConfig.h>
#import <IpaAdSDK/IasCustomNetworkMode.h>
#import <IpaAdSDK/IasSharePlacementConfig.h>
#import <IpaAdSDK/IasSDKGlobalSetting.h>
#import <IpaAdSDK/IasAdErrorCode.h>
#import <IpaAdSDK/IasCustomContentResult.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kIasADDelegateExtraNetworkFirmIdKey;
extern NSString *const kIasADDelegateExtraAdSourceIdKey;
extern NSString *const kIasADDelegateExtraIsHeaderBiddingKey;
extern NSString *const kIasADDelegateExtraAdSourcePriceKey;
extern NSString *const kIasADDelegateExtraPriorityKey;
extern NSString *const kIasADDelegateExtraBidFloorKey;
extern NSString *const kIasADDelegateExtraRequestIDKey;
extern NSString *const kIasADDelegateExtraCustomExtKey;
extern NSString *const kIasADDelegateExtraECPMLevelKey; // the eCPM level of the ad source
extern NSString *const kIasADDelegateExtraSegmentIDKey; //segment ID
extern NSString *const kIasADDelegateExtraScenarioIDKey; // Advertising Scene ID,Only Rewarded Video and Interstitial support
extern NSString *const kIasADDelegateExtraChannelKey; // Channel Information
extern NSString *const kIasADDelegateExtraSubChannelKey; // sub-channel information
extern NSString *const kIasADDelegateExtraCustomRuleKey; // Json string of the Placement + App dimension custom rule
extern NSString *const kIasADDelegateExtraIDKey; // a unique ID generated for each impression
extern NSString *const kIasADDelegateExtraAdunitIDKey; // IpaAd placement ID
extern NSString *const kIasADDelegateExtraPublisherRevenueKey; // impression revenue
extern NSString *const kIasADDelegateExtraCurrencyKey; // currency unit, for example: "USD"
extern NSString *const kIasADDelegateExtraCountryKey; // country code, for example: "CN"
extern NSString *const kIasADDelegateExtraFormatKey; // ad source types
extern NSString *const kIasADDelegateExtraPrecisionKey; // eCPM precision
extern NSString *const kIasADDelegateExtraNetworkTypeKey; // Network Type
extern NSString *const kIasADDelegateExtraNetworkPlacementIDKey; // the ad placement ID of a third-party Ads Network
extern NSString *const kIasADDelegateExtraScenarioRewardNameKey; // reward name of the ad Scenario,Only Rewarded Video support
extern NSString *const kIasADDelegateExtraScenarioRewardNumberKey; // number of reward for the ad Scenario，Only Rewarded Video support
extern NSString *const kIasADDelegateExtraPlacementRewardNameKey;
extern NSString *const kIasADDelegateExtraPlacementRewardNumberKey;
extern NSString *const kIasADDelegateExtraExtInfoKey; // additional information of IpaAd Adx & OnlineAPI Offer,output as Json string
extern NSString *const kIasADDelegateExtraOfferIDKey;
extern NSString *const kIasADDelegateExtraCreativeIDKey;
extern NSString *const kIasADDelegateExtraIsDeeplinkKey;
extern NSString *const kIasADDelegateExtraUserCustomData;
extern NSString *const kIasADDelegateExtraPlacementTypeKey;
extern NSString *const kIasADDelegateExtraSharedPlacementIdKey;
extern NSString *const kIasADDelegateExtraNetworkNameKey;
extern NSString *const kIasADDelegateExtraShowCustomExtKey;
extern NSString *const kIasADDelegateExtraCustomContentResultKey;
extern NSString *const kIasADDelegateExtraTpBidIDKey;
extern NSString *const kIasADDelegateExtraABTestIDKey;
extern NSString *const kIasADDelegateExtraDismissTypeKey;
extern NSString *const kIasADDebuggerKey;
extern NSString *const kIasADDelegateExtraServerKeyIdKey;
extern NSString *const kIasADDelegateExtraClientSideEcpmKey;
extern NSString *const kIasADDelegateExtraUsdExchangeRmbRateKey;
extern NSString *const kIasADDelegateExtraRmbExchangeUsdRateKey;

// TODO待优化
extern NSString *const kIasNetworkNameFyber;
extern NSString *const kIasNetworkNameStartApp;
extern NSString *const kIasNetworkNameFacebook;
extern NSString *const kIasNetworkNameTanx;
extern NSString *const kIasNetworkNameInmobi;
extern NSString *const kIasNetworkNameAdmob;
extern NSString *const kIasNetworkNameMintegral;
extern NSString *const kIasNetworkNameApplovin;
extern NSString *const kIasNetworkNameGDT;
extern NSString *const kIasNetworkNameTapjoy;
extern NSString *const kIasNetworkNameChartboost;
extern NSString *const kIasNetworkNameIronSource;
extern NSString *const kIasNetworkNameVungle;
extern NSString *const kIasNetworkNameAdColony;
extern NSString *const kIasNetworkNameUnityAds;
extern NSString *const kIasNetworkNameTT;
extern NSString *const kIasNetworkNamePangle;
extern NSString *const kIasNetworkNameBaidu;
extern NSString *const kIasNetworkNameNend;
extern NSString *const kIasNetworkNameMaio;
extern NSString *const kIasNetworkNameSigmob;
extern NSString *const kIasNetworkNameMyOffer;
extern NSString *const kIasNetworkNameKS;
extern NSString *const kIasNetworkNameOgury;
extern NSString *const kIasNetworkNameGoogleAdManager;
extern NSString *const kIasNetworkNameADX;
extern NSString *const kIasNetworkNameHelium;
extern NSString *const kIasNetworkNameMintegralOnlineApi;
extern NSString *const kIasNetworkNameGDTOnlineApi;
extern NSString *const kIasNetworkNameKidoz;
extern NSString *const kIasNetworkNameMyTarget;
extern NSString *const kIasNetworkNameMobrain;
extern NSString *const kIasNetworkNameYandex;
extern NSString *const kIasNetworkNamePubNative;
extern NSString *const kIasNetworkNameBigo;
extern NSString *const kIasNetworkNameAdxPublic;
extern NSString *const kIasNetworkNameJADYun;
extern NSString *const kIasNetworkNameKwai;
extern NSString *const kIasNetworkNameIMA;
extern NSString *const kIasNetworkNameMax;
extern NSString *const kIasNetworkNameklevin;
extern NSString *const kIasNetworkNameQumeng;


extern NSString *const kIasCustomDataUserIDKey;//string
extern NSString *const kIasCustomDataAgeKey;//Integer
extern NSString *const kIasCustomDataGenderKey;//Integer
extern NSString *const kIasCustomDataNumberOfIAPKey;//Integer
extern NSString *const kIasCustomDataIAPAmountKey;//Double
extern NSString *const kIasCustomDataIAPCurrencyKey;//string
extern NSString *const kIasCustomDataChannelKey;//string
extern NSString *const kIasCustomDataSubchannelKey;//string
extern NSString *const kIasCustomDataSegmentIDKey;//int

extern NSString *const kIasAdLoadingExtraBUAdLoadTypeKey;
extern NSString *const kIasNetWorkVideoStatusKey;

typedef NS_ENUM(NSInteger, IasNetworkFirmIDType) {
    IasNetworkFirmIDTypeFacebook = 1,
    IasNetworkFirmIDTypeAdmob = 2,
    IasNetworkFirmIDTypeInmobi = 3,
    IasNetworkFirmIDTypeApplovin = 5,
    IasNetworkFirmIDTypeMintegral = 6,
    IasNetworkFirmIDTypeGDT = 8,
    IasNetworkFirmIDTypeChartboost = 9,
    IasNetworkFirmIDTypeTapjoy = 10,
    IasNetworkFirmIDTypeIronSource = 11,
    IasNetworkFirmIDTypeUnityAds = 12,
    IasNetworkFirmIDTypeVungle = 13,
    IasNetworkFirmIDTypeAdColony = 14,
    IasNetworkFirmIDTypeCSJ = 15,
    IasNetworkFirmIDTypeBaidu = 22,
    IasNetworkFirmIDTypeNend = 23,
    IasNetworkFirmIDTypeMaio = 24,
    IasNetworkFirmIDTypeStartApp = 25,
    IasNetworkFirmIDTypeKuaishou = 28,
    IasNetworkFirmIDTypeSigmob = 29,
    IasNetworkFirmIDTypeMyTarget = 32,
    IasNetworkFirmIDTypeGoogleAdManager = 33,
    IasNetworkFirmIDTypeYandex = 34,
    IasNetworkFirmIDTypeCrossPromotion = 35,
    IasNetworkFirmIDTypeOgury = 36,
    IasNetworkFirmIDTypeFyber = 37,
    IasNetworkFirmIDTypeHelium = 40,
    IasNetworkFirmIDTypeMintegralOnlineApi = 41,
    IasNetworkFirmIDTypeGDTOnlineApi = 42,
    IasNetworkFirmIDTypeKidoz = 45,
    IasNetworkFirmIDTypePangle = 50,
    IasNetworkFirmIDTypeKlevin = 51,
    IasNetworkFirmIDTypePubNative = 58,
    IasNetworkFirmIDTypeBigo = 59,
    IasNetworkFirmIDTypeIpaAdADX = 66,
    IasNetworkFirmIDTypeJD = 72,
    IasNetworkFirmIDTypeIMA = 76,
    IasNetworkFirmIDTypeKwai = 77,
    IasNetworkFirmIDTypeTanx = 82
};

typedef NS_ENUM(NSInteger, IasUserLocation) {
    IasUserLocationUnknown = 0,
    IasUserLocationInEU = 1,
    IasUserLocationOutOfEU = 2
};

typedef NS_ENUM(NSInteger, IasDataConsentSet) {
    //Let it default to forbidden if not set
    IasDataConsentSetUnknown = 0,
    IasDataConsentSetPersonalized = 1,
    IasDataConsentSetNonpersonalized = 2
};

typedef NS_ENUM(NSInteger, IasBUAdLoadType) {
    IasBUAdLoadTypeUnknown                    = -1,//Unknown
    IasBUAdLoadTypePreload                    = 1,//Preload resources
    IasBUAdLoadTypeLoad                       = 3,//Load resources in real time
};

typedef NS_ENUM(NSInteger, IasPersonalizedAdState) {
    IasPersonalizedAdStateType = 1,
    IasNonpersonalizedAdStateType = 2
};

typedef NS_OPTIONS(NSInteger, IasLogType) {
    IasLogTypeNone = 0,
    IasLogTypeInternal = 1 << 0,
    IasLogTypeExternal = 1 << 1,
    IasLogTypeTemporary = 1 << 2,
    IasLogTypeProcess = 1 << 3,
    IasLogTypeSave = 1 << 4
};

// Position of the logo icon in the containing ad.
typedef NS_ENUM(NSInteger, IasAdLogoPosition) {
    IasAdLogoPositionBottomRightCorner = 0,  ///< Bottom right corner.
    IasAdLogoPositionBottomLeftCorner,   ///< Bottom Left Corner.
    IasAdLogoPositionTopRightCorner,     ///< Top right corner.
    IasAdLogoPositionTopLeftCorner,      ///< Top left corner.
};

@interface IasConsentPrivacySetting : NSObject

/// Set this to @c YES to enable the consent flow. You must also provide your privacy policy and terms of service URLs in this object, and you must provide a
///* @c NSUserTrackingUsageDescription string in your @code Info.plist @endcode file.
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/// URL for your company’s privacy policy. This is required
@property (nonatomic, copy, nullable) NSURL *privacyPolicyURL;

/// URL for your company’s terms of service. This is optional
@property (nonatomic, copy, nullable) NSURL *termsOfServiceURL;

@end

@interface IasShowConfig : NSObject

@property (nonatomic, readonly) NSString *scene;
@property (nonatomic, readonly) NSString *showCustomExt;
@property (nonatomic, readonly) IasCustomContentResult *customContentResult;

@property (nonatomic, strong) NSDictionary *atAdInfo;

- (instancetype)initWithScene:(nullable NSString *)scene showCustomExt:(nullable NSString *)showCustomExt;
- (instancetype)initWithScene:(nullable NSString *)scene showCustomExt:(nullable NSString *)showCustomExt customContentResult:(nullable IasCustomContentResult *)customContentResult;

@end

@interface IasAPI : NSObject

/// singleton object
+ (instancetype)sharedInstance;

/// Initialize SDK
/// @param appID - appid string
/// @param appKey appkey string
/// @param error - see what's the matter.
- (BOOL)initWithAppID:(NSString *)appID
                appKey:(NSString *)appKey
                 error:(NSError **)error;

/// Initialize SDK
/// @param appID - appid string
/// @param appKey appkey string
/// @param sdkConfigure preinit network configure
/// @param error - see what's the matter.
- (BOOL)initWithAppID:(NSString *)appID
                appKey:(NSString *)appKey
         sdkConfigures:(IasSDKConfiguration *)sdkConfigure
                 error:(NSError **)error;

/// map network firm id list
+ (NSDictionary<NSNumber*, NSString*>*)networkNameMap;

/// Whether the network platform integration integrity information is normal
+ (void)integrationChecking;

/// set location longitude
- (void)setLocationLongitude:(double)longitude dimension:(double)dimension DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setLocationLongitude:dimension: instead ");

/// set whether WX is installed
/// @param isInstallWX - install status
- (void)setWXStatus:(BOOL)isInstallWX DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager].isInstallWX instead ");

/// consentString might be nil.
/// This method is thread-safe.
- (void)setDataConsentSet:(IasDataConsentSet)dataConsentSet
            consentString:(NSDictionary<NSString*, NSString*>*)consentString;

/// Whether the device is located in data protected area.
- (BOOL)inDataProtectionArea;

/// get user location
/// @param callback - location type
- (void)getUserLocationWithCallback:(void(^)(IasUserLocation location))callback;

/// get Area
/// @param success - arear string
/// @param failure - error message
- (void)getAreaSuccess:(void(^)(NSString *areaCodeStr))success
               failure: (void(^)(NSError *error))failure;

/// get ps id
- (NSString *)psID;

/// Log enabled
/// @param logEnabled - log status
+ (void)setLogEnabled:(BOOL)logEnabled;

/// Log enabled
/// @param cacheEnabled log localCache status
+ (void)logLocalCacheEnabled:(BOOL)cacheEnabled;

+ (void)setDebuggerConfig:(void(^_Nullable)(IasDebuggerConfig * _Nullable debuggerConfig))debuggerConfigBlock DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setDebuggerConfig: instead ");

+ (void)setDeviceInfoConfig:(void(^_Nullable)(IasDeviceInfoConfig * _Nullable deviceInfoConfig))deviceInfoConfigBlock DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setDeviceInfoConfig: instead ");

+ (void)addCustomAdapterConfigArray:(NSArray <IasCustomNetworkMode *>*)array DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] addCustomAdapterConfigArray: instead ");

/// print test info log
/// include idfa,idfv
+ (void)testModeInfo;
    
/**
 * Show the data consent dialog using the specified constroller as the presenting view controller.
 * viewController might be nil, for which the root view controller of the window will be used instead.
 */
- (void)presentDataConsentDialogInViewController:(UIViewController *)viewController
                               dismissalCallback:(void(^)(void))dismissCallback DEPRECATED_MSG_ATTRIBUTE("use showGDPRConsentDialogInViewController:dismissalCallback: instead ");

- (void)presentDataConsentDialogInViewController:(UIViewController *)viewController
                          loadingFailureCallback:(void(^)(NSError *error))loadingFailureCallback
                               dismissalCallback:(void(^)(void))dismissCallback DEPRECATED_MSG_ATTRIBUTE("use showGDPRConsentDialogInViewController:dismissalCallback: instead ");

/// show UMP GDPR Auth
- (void)showGDPRConsentDialogInViewController:(UIViewController *)viewController
                         dismissalCallback:(void(^)(void))dismissCallback;

@property (nonatomic, readonly) IasDataConsentSet dataConsentSet;
@property (nonatomic, readonly) NSDictionary<NSString*, NSString*>* consentStrings;
@property (nonatomic, readonly) NSString *appID;
@property (nonatomic, readonly) NSString *appKey;
/*
 channel & customData has to be set before init
 */
@property (nonatomic, strong) NSString *channel DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager].channel instead ");
@property (nonatomic, strong) NSString *subchannel DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager].subchannel instead ");
@property (nonatomic, strong) NSDictionary *customData DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager].customData instead ");

@property (nonatomic, readonly,class) NSDate *firstLaunchDate;

/// Indicates preferred location of logo icon. Default is IasAdLogoPositionBottomRightCorner.
@property (nonatomic, assign) IasAdLogoPosition preferredAdLogoPosition;

/// set custom data for the ad placement
/// @param customData - custom data
/// @param placementID - placement id
- (void)setCustomData:(NSDictionary *)customData forPlacementID:(NSString *)placementID DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setCustomData:forPlacementID: instead ");

/// get custom data
- (NSDictionary *)customDataForPlacementID:(NSString *)placementID DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] customDataForPlacementID: instead ");

/// get SDK version
- (NSString *)version;

/// set exlude appleid list for sdk to filter offers
- (void)setExludeAppleIdArray:(NSArray *)appleIdArray DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setExludeAppleIdArray: instead ");

/// get exlude appleid list
- (NSArray *)exludeAppleIdArray DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] exludeAppleIdArray: instead ");

/// set denied Upload Info list for sdk to Control report
- (void)setDeniedUploadInfoArray:(NSArray *)uploadInfoArray DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setDeniedUploadInfoArray: instead ");

/// get denied Upload Info list
- (NSArray *)deniedUploadInfoArray DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] deniedUploadInfoArray: instead ");

/// Determine whether the Denied key is included
/// @param key - key string
- (BOOL)isContainsForDeniedUploadInfoArray:(NSString *)key DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] isContainsForDeniedUploadInfoArray: instead ");

/// set header bidding test mode,only support incoming device idfa.
/// setLogEnabled must be turned on before use
+ (void)setHeaderBiddingTestModeWithDeviceID:(NSString *)idfa DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager].headerBiddingTestModeDeviceID instead ");

/// set personalized recommendation state
/// @param state - 1 is to close personalized recommendation, other values or not set to open
- (void)setPersonalizedAdState:(IasPersonalizedAdState)state;

/// get personalized recommendation state
- (IasPersonalizedAdState)getPersonalizedAdState;

- (void)setConsentPrivacySetting:(IasConsentPrivacySetting *)settings;

/// Set System Platform Information
- (void)setSystemPlatformType:(IasSystemPlatformType)type DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager].systemPlatformType instead ");

/// set Wechat appID and universalLink, for register WechatOpenSDK
/// @param appID - Wechat appID
/// @param universalLink - Wechat universalLink
- (void)setWeChatAppID:(NSString *)appID universalLink:(NSString *)universalLink DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setWeChatAppID:universalLink: instead ");

- (void)setPresetPlacementConfigPathBundle:(NSBundle *)bundle DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager] setPresetPlacementConfigPathBundle: instead ");

- (void)setSharePlacementConfig:(IasSharePlacementConfig *)config DEPRECATED_MSG_ATTRIBUTE("use [IasSDKGlobalSetting sharedManager].sharePlacementConfig instead ");

/// 展示指定Networks
- (void)setAllowedShowNetworkFimIdArray:(NSArray <NSString *>*)networkFilmIdArray forPlacementID:(NSString *)placementID;
/// 不展示指定Networks
- (void)setForbidShowNetworkFirmIdArray:(NSArray<NSString *>*)networkFilmIdArray forPlacementID:(NSString *)placementID;
/// 不加载指定Networks
- (void)setForbidLoadNetworkFirmIdArray:(NSArray<NSString *>*)networkFilmIdArray;


NS_ASSUME_NONNULL_END
@end


