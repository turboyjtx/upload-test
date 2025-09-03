//
//  IasPlacementModel.h
//  IpaAdSDK
//
//  Created by Leo on 11/04/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <IpaAdSDK/IasModel.h>
#import <IpaAdSDK/IasUnitGroupModel.h>
#import <IpaAdSDK/IasMyOfferOfferModel.h>
#import <IpaAdSDK/IasMyOfferSetting.h>
#import <IpaAdSDK/IasADXPlacementSetting.h>
#import <UIKit/UIKit.h>

#import <IpaAdSDK/IasStorage.h>
#import <IpaAdSDK/IasModelProtocol.h>
#import <IpaAdSDK/IasDynamicWaterfallParams.h>
#import <IpaAdSDK/IasPlatfromInfo.h>
#import <IpaAdSDK/IasPlacementModelExtra.h>



typedef NS_ENUM(NSInteger, IasADShowType) {
    /**
     * priority -> show times -> added time
     */
    IasADShowTypePriority = 0,
    /**
     * show times -> priority -> added time
     */
    IasADShowTypeSerial = 1
};

typedef enum : NSUInteger {
    IasLoadingRequestConcurrentFixedType = 1,
    IasLoadingRequestConcurrentEqualPriceType = 2,
} IasLoadingRequestModelType;

typedef NS_ENUM(NSInteger, IasNativeMixBannerStyleType) {
    IasNativeMixBannerStyleTypeIpaAdOne = 1,
};


typedef NS_ENUM(NSInteger, IasLoadingAdApiType) {
    IasLoadingAdApiTypeDefault = 0, // 默认
    IasLoadingAdApiTypeRefresh = 1, // 刷新
    IasLoadingAdApiTypePlayAgain = 2, 
    IasLoadingAdApiTypeAutoLoadInitiation = 3,// 自动请求: 初始化或创建广告对象
    IasLoadingAdApiTypeAutoLoadLoadFailed = 4, // 自动请求: 加载失败
    IasLoadingAdApiTypeAutoLoadNotReady  = 5,// 自动请求: isReady 为false
    IasLoadingAdApiTypeAutoLoadShowStart = 6,// 自动请求: 开始展示
    IasLoadingAdApiTypeAutoLoadShowFailed = 7,// 自动请求: 展示失败
    IasLoadingAdApiTypeFailedRetry = 8,// 非全自动加载模式: 加载失败自动请求
    IasLoadingAdApiTypeSerialMultiCachMode  = 9,// 串行多缓存
    IasLoadingAdApiTypeSharedPlacementPreload    = 10,// 共享广告位: 启动预加载
    IasLoadingAdApiTypeSharedPlacementTimer     = 11,//共享广告位: 定时任务请求
    // 共享广告位:：绑定了共享池的广告位在生命周期内首次回调Load结果后执行相同广告类型共享池的预加载
    IasLoadingAdApiTypeSharedPlacementSameFormatLoad     = 12,
    IasLoadingAdApiTypePresetCool    = 13,// 使用SDK内置策略执行WF后，额外增加使用线上冷启动策略发起请求
    IasLoadingAdApiTypePresetNormal  = 14,// 使用SDK内置策略执行WF后，额外增加使用线上非冷启动策略发起请求
};

typedef NS_ENUM(NSInteger, IasCallSuccessType) {
    IasCallSuccessShowPriorityType = 1,
    IasCallSuccessPricePriorityType = 2,
};
extern NSString *const kIasPlacementModelCacheDateKey;
extern NSString *const kIasPlacementModelCustomDataKey;

typedef NS_ENUM(NSUInteger, IasPlacementModelUserValueTimingType) {
    IasPlacementModelUserValueTimingTypeNone = 0,
    IasPlacementModelUserValueTimingTypeShow = 1,
};

typedef NS_ENUM(NSUInteger, IasPlacementModelUserValueStrategyIndexType) {
    IasPlacementModelUserValueStrategyIndexTypeLocal = 0,
    IasPlacementModelUserValueStrategyIndexTypeShowPrice = 1,
};

typedef NS_ENUM(NSUInteger, IasPlacementModelWaterfallModeType) {
    IasPlacementModelWaterfallModeTypeSerialMultiCach = 1,
    IasPlacementModelWaterfallModeTypeNormal = 2,
};


typedef NS_ENUM(NSUInteger, IasBannerAutoRefreshType) {
    IasBannerAutoRefreshTypePlacementStrategy = 1,
    IasBannerAutoRefreshTypeAdSourceStrategy = 2,
};

typedef NS_ENUM(NSInteger, IasPlacementModelBaiduReportType) {
    IasPlacementModelBaiduReportTypeUnKonw = 0,
    IasPlacementModelBaiduReportTypeNormalWin = 1 << 0,
    IasPlacementModelBaiduReportTypeNormalLoss = 1 << 1,
    IasPlacementModelBaiduReportTypeBiddingWin = 1 << 2,
    IasPlacementModelBaiduReportTypeBiddingLoss = 1 << 3,

};

typedef NS_ENUM(NSUInteger, IasPlacementSettingType) {
    IasPlacementSettingTypeNormal,
    IasPlacementSettingTypePreset,
    IasPlacementSettingTypeCool,
};

typedef NS_ENUM(NSInteger, IasPlacementModelAutoLoadType) {
    IasPlacementModelAutoLoadTypeUnKonw = 0,
    IasPlacementModelAutoLoadTypeLoadFailed = 1 << 0,
    IasPlacementModelAutoLoadTypeIsReadyFalse = 1 << 1,
    IasPlacementModelAutoLoadTypeShow = 1 << 2,
    IasPlacementModelAutoLoadTypeShowFailed = 1 << 3,

};

#pragma mark - IasPlacementModel
@interface IasPlacementModel : IasModel <IasModelProtocol, IasStorageEntityProtocol>

-(instancetype) initWithDictionary:(NSDictionary *)dictionary associatedCustomData:(NSDictionary*)customData placementID:(NSString*)placementID;
-(instancetype) initWithDictionary:(NSDictionary *)dictionary placementID:(NSString*)placementID;

@property (nonatomic, strong) NSDictionary *originalPlacementDic;
@property (nonatomic, strong) NSDictionary *cachedDic;
@property (nonatomic, strong) NSDictionary *updateCachedDic;

@property (nonatomic, assign) IasCallSuccessType callSuccessType;

@property(nonatomic, readonly) NSDictionary *associatedCustomData;
@property(nonatomic, readonly) BOOL cachesPlacementSetting;
@property(nonatomic, readonly) IasAdFormat format;
@property(nonatomic, readonly) NSString *formatString;
@property(nonatomic, readonly) NSString *placementID;
@property(nonatomic, readonly) BOOL adDeliverySwitch;
@property(nonatomic, readonly) NSInteger groupID;
@property(nonatomic, readonly) BOOL refresh;
/**
 Auto refresh is for banner.
 */
@property(nonatomic, readonly) BOOL autoRefresh;
@property(nonatomic, readonly) NSTimeInterval autoRefreshInterval;
@property (nonatomic, assign) IasBannerAutoRefreshType bannerAutoRefreshType;
/**
 * How many unit groups to be loaded concurrently
 */

@property(nonatomic, readonly) IasLoadingRequestModelType loadingRequestModelType;
@property(nonatomic, readonly) NSInteger fixedMaxConcurrentRequestCount;
@property(nonatomic, readonly) NSInteger equalPriceMaxConcurrentRequestCount;

@property(nonatomic, readonly) NSString *psID;
@property(nonatomic, readonly) NSString *sessionID;
@property(nonatomic, readonly) IasADShowType showType;
/**
 Max showing times allowed in a day with -1 meaning no limitation
 */
@property(nonatomic, readonly) NSInteger unitCapsByDay;
/**
 Max showing times allowed in a hour with -1 meaning no limitation
 */
@property(nonatomic, readonly) NSInteger unitCapsByHour;
@property(nonatomic, readonly) NSTimeInterval unitPacing;
@property(nonatomic, readonly) BOOL wifiAutoSwitch;
@property(nonatomic, readonly) BOOL autoloadingEnabled;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* allUnitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* unitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* headerBiddingUnitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* S2SHeaderBiddingUnitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* olApiUnitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* inhouseUnitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* bksUnitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* bottomListUnitGroups;
@property(atomic, readonly) NSArray<IasUnitGroupModel*>* directOfferHeaderBiddingUnitGroups;
@property(nonatomic, readonly) NSArray<IasUnitGroupModel*>* adxUnitGroups;
@property(nonatomic, readonly) NSArray<IasUnitGroupModel*>* adxOpenUnitGroups;

@property(nonatomic, readonly) NSArray<IasUnitGroupModel*>* dynamicHeaderBiddingUnitGroups;
/// 动态出价客户端竞价广告源列表
@property(nonatomic, readonly) NSArray<IasUnitGroupModel*>* dynamicBiddingC2SUnitGroups;
/// 动态出价服务端竞价广告源列表
@property(nonatomic, readonly) NSArray<IasUnitGroupModel*>* dynamicBiddingS2SUnitGroups;

@property(nonatomic, readonly) NSDictionary *dynamicHBAdUnitIds;

@property(nonatomic, readonly) NSTimeInterval bottomRreqts;     // bottomAd dalay request time

@property(nonatomic, readonly) NSTimeInterval headerBiddingRequestLongTimeout;

@property(nonatomic, readonly) NSTimeInterval headerBiddingRequestShortTimeout;

@property(nonatomic, readonly) NSString *S2SBidRequestAddress;
@property(nonatomic, readonly) NSString *waterFallBidRequestAddress;

@property(nonatomic, readonly) NSTimeInterval loadCapDuration;
@property(nonatomic, readonly) NSInteger loadCap;

@property(nonatomic, readonly) NSInteger expectedNumberOfOffers;


@property(nonatomic, readonly) NSTimeInterval bidWaitTimeout;
@property(nonatomic, readonly) NSTimeInterval reqWaitTimeout;

@property(nonatomic, readonly) NSTimeInterval loadFailureInterval;
@property(nonatomic, readonly) NSTimeInterval offerLoadingTimeout;
@property(nonatomic, readonly) NSTimeInterval statusValidDuration;//Upstatus
@property(atomic, strong) NSString *asid;//generated by server side
@property(nonatomic, readonly) NSString *trafficGroupID;

@property(nonatomic, readonly) IasPlacementModelExtra *extra;

@property(nonatomic, readonly) NSInteger defaultNetworkFirmID;
@property(nonatomic, readonly) NSTimeInterval defaultAdSourceLoadingDelay;

/*
 */
@property(nonatomic, readonly) NSTimeInterval updateTolerateInterval;
/// 自定义流量分组策略变更时，新增的超时时间ps_ct_out_cus
@property(nonatomic, readonly) NSTimeInterval waitUpdateTimeoutInterval;

@property(nonatomic, readonly) NSTimeInterval cacheValidDuration;
@property(nonatomic, readonly) NSDate *cacheDate;

@property(nonatomic, readonly) NSArray<IasMyOfferOfferModel*>* offers;
@property(nonatomic, readonly) IasMyOfferSetting *myOfferSetting;
@property(nonatomic, readonly) NSInteger usesDefaultMyOffer;
@property(nonatomic, readonly) BOOL preloadMyOffer;
//extra
@property(nonatomic, readonly) NSDictionary *callback;

@property(nonatomic, readonly) NSInteger FBHBTimeOut;

@property(nonatomic, readonly) NSDictionary* adxSettingDict;

@property(nonatomic, readonly) NSDictionary* olApiSettingDict;

@property(nonatomic, readonly) NSTimeInterval waterfallFillTime;

@property(nonatomic, readonly) NSString *currency;
@property(nonatomic, readonly) NSString *exchangeRate;

@property(nonatomic, readonly) NSArray *bURLNotificationFirms;

// v5.7.10
@property(nonatomic, readonly) NSString *campaign;


@property (nonatomic, assign) BOOL isShowSendMTG;

@property (nonatomic, assign) BOOL isMediationIDSendGDT;

@property (atomic, strong) NSDictionary *placementABDic;
@property (nonatomic, assign) BOOL isDisplayPriceSwitch;

@property (nonatomic, assign) NSInteger networkEstimatePriceNum;

@property (nonatomic, readonly) NSInteger bidImprssionExtraNum;

@property (nonatomic, strong) NSString *sharePlacementId;

@property (nonatomic, assign) BOOL hasSharePlacementId;
@property (nonatomic, assign) BOOL isSharePlacement;

@property (atomic, strong) NSDictionary *baiduReportDic;

-(Class) adManagerClass;

- (NSDictionary *)revenueToPlatforms;

/**
 In order to solve the problem of inconsistency in legal tender. If the current ecpm currency is USD, this method returns NO.
 */
//- (BOOL)needConvertPrice;

/**
 If the current legal currency of ecpm is not USD, this method will calculate the corresponding price according to the latest exchange rate.
 */
//- (NSString *)convertedPrice:(NSString *)price;

//todo: just for in-house list. It's not a good solution.
@property(nonatomic, copy) NSArray<IasUnitGroupModel*>* allUnitGroupArray;


@property(nonatomic, copy) NSArray *directOfferUnitIDArray;


// v5.7.56+
@property(nonatomic, readonly) NSInteger encryptFlag;
@property(nonatomic, readonly, copy) NSString *encryptPublicKey;
@property(nonatomic, readonly, copy) NSDictionary *encryptApiDynamicInfoDic;

/**
 Maximum waiting time for s2s HB adSource to get buyeruid
 */
@property(nonatomic, readonly) NSInteger getBuyeruIdWaitTime;

@property(nonatomic, readonly, copy) NSString *inhouseUrl;
@property(nonatomic, readonly, copy) NSString *thirdInhouseUrl; // bks url of third plantforms

@property(nonatomic, readonly) NSString *exchRateC2U;
@property (nonatomic,readonly) NSString *bidFloor;

@property (nonatomic,readonly) NSInteger s2sBidMax;

@property(nonatomic, assign) BOOL isExistHBAdSource;
@property(nonatomic, assign) BOOL loadSuccessRetrySwitch;
@property(nonatomic, assign) BOOL loadFailRetrySwitch;
@property (nonatomic,assign) BOOL requestMerge;

@property(nonatomic, readonly) NSDictionary *gspRatesDic;
@property (nonatomic,readonly) NSString *adxExtJson;

@property (nonatomic, readonly) NSArray *loaddingTypeSwitchArray;

@property (nonatomic, readonly) BOOL isSetPangleRequestId;

/// 当使用SDK预置策略（或 开屏内置广告源）请求WF时,在WF结束后IpaAd SDK根据广告位策略参数(presetwf_reload_sw)判断本次是否需要在WF结束后使用线上返回的广告位策略再执行一次WF
@property (nonatomic, assign) BOOL shouldLoadMoreWhenPresetLoaded;
@property (nonatomic, assign) BOOL hasCoolPlacementSettings;
@property (nonatomic, assign) IasPlacementSettingType type;

@property (nonatomic, assign) BOOL isUsePlacementSettingsFirst;
@property (nonatomic, assign) BOOL isSaveUserValueData;

@property (nonatomic, readonly) IasPlacementModelUserValueTimingType userValueTimingType;
@property (nonatomic, readonly) IasPlacementModelUserValueStrategyIndexType userValueStrategyIndex;
@property (nonatomic, readonly) NSInteger userValueReportCount;
@property (nonatomic, readonly) NSArray<NSArray<NSNumber *> *> *userValuePriceRanges;

@property (nonatomic, readonly) IasPlacementModelWaterfallModeType waterfallModeType;
@property (nonatomic, readonly) NSInteger serialMultiCachModeMaxConcurrentRequsetCount;
@property (nonatomic, readonly) IasLoadingRequestModelType serialMultiCachModeRequestModelType;
@property (nonatomic, readonly) NSTimeInterval LoadFailedAutoRetryLoadInterval;
@property (nonatomic, readonly) NSInteger statusNum;
@property (nonatomic, readonly) IasPlacementModelBaiduReportType baiduReportType;

@property(nonatomic, readonly) BOOL s2sSwitch;

@property (nonatomic, assign) IasNativeMixBannerStyleType nativeMixBannerStyleType;

@property (nonatomic, strong) NSValue *developerBannerSizeValue;
@property (nonatomic, assign) CGSize developerBannerSize;
@property (nonatomic, strong) NSArray *mixAdClickAreaArray;

//动态瀑布流开关
@property (nonatomic, assign) BOOL dynamicWaterfallSwitch;
@property (nonatomic, strong) IasDynamicWaterfallParams *dynamicWaterfall;

//缓存最大过期时间，默认：604800(秒），7天
@property (nonatomic, readonly) NSTimeInterval maxCacheExpirationTime;
//开屏广告SDK API传入超时时间，毫秒
//大于0：开屏广告SDK API传入超时时间优先采用广告位策略下发的该参数
//小于0或不下发：不使用该超时时间，即开关为关
@property (nonatomic, readonly) NSTimeInterval splashSdkPriorityTimeOut;


@property (nonatomic, readonly) NSTimeInterval biddingWaitOtherTime;
@property (nonatomic, readonly) NSTimeInterval adjustWaterFallHbTime;

@property (nonatomic, assign) IasPlacementModelAutoLoadType placementModelAutoLoadType;



- (CGFloat)getNetworkgspRate:(NSString *)networkFirmID;
- (void)parsingUnitGroupsWithDictionary:(NSDictionary *)dictionary;
#pragma mark -NewDepart




- (IasMyOfferOfferModel *)miniCapForMyOffers;

@end
