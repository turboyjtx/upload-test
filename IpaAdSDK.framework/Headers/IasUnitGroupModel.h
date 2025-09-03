//
//  IasUnitGroupModel.h
//  IpaAdSDK
//
//  Created by Leo on 11/04/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <IpaAdSDK/IasModel.h>
#import <UIKit/UIKit.h>
#import <IpaAdSDK/IasMyOfferOfferModel.h>
#import <IpaAdSDK/IasBidInfo.h>
#import <IpaAdSDK/IasModelProtocol.h>
#import <IpaAdSDK/IasAdapter.h>
#import <IpaAdSDK/IasStorage.h>

#define IasBaiDuUnitIDKey @"IasBaiDuUnitIDKey"
#define IasBaiDuplacementIdKey @"IasBaiDuplacementIdKey"
#define IasBaiDuUpdateExposureNotificationKey @"IasBaiDuUpdateExposureNotificationKey"


typedef NS_ENUM(NSInteger, IasRenderingType) {
    IasRenderingIpaAdType = 1,    //IpaAd SDK渲染，默认
    IasRenderingSelfType = 2,     // 开发者自渲染
};

typedef NS_ENUM(NSInteger, IasMixRewardGiveOutType) {
    IasMixRewardGiveOutTypeClose = 1,
    IasMixRewardGiveOutTypeClick = 2,
};

typedef NS_ENUM(NSInteger, IasRequestFiledType) {
    IasRequestFiledAdFodderDataType = 1,
    IasRequestFiledAdMetaDataType = 2,
};


typedef NS_ENUM(NSInteger, IasAdListType) {
    IasAdListTypeNormal = 1,
    IasAdListTypeC2S = 2,
    IasAdListTypeS2S = 3,
    IasAdListTypeAdx = 4,
    IasAdListTypeDsp = 5,
    IasAdListTypeOnLine = 6,
    IasAdListTypeInhouse = 7,
    IasAdListTypeDirect = 8,
    IasAdListTypeDynamicBid = 9,
    IasAdListTypeBottom = 10,
    IasAdListTypeBKS = 11,
    IasAdListTypeDynamicBidC2S = 12,
    IasAdListTypeDynamicBidS2S = 13,

};


typedef NS_ENUM(NSInteger, IasNetworkEstimatePriceType) {
    IasNetworkEstimatePriceTypeSort = 0,
    IasNetworkEstimatePriceTypeEstimate,
    IasNetworkEstimatePriceTypeReal,
    IasNetworkEstimatePriceTypeRealPriceNil,
    IasNetworkEstimatePriceTypeTimeOut,

};

typedef NS_ENUM(NSInteger, IasShowAutoLoadType) {
    IasShowAutoOneAdSupportLoadType = 1,
    IasShowAutoOneAdNotSupportLoadType,
    IasShowAutoOneNetWorkNotSupportLoadType,
};
/// ad type：0 Native, 1 Rewarded, 2 Banner, 3 Interstitial, 4 Splash
typedef NS_ENUM(NSInteger, IasUnitGroupJointAdType) {
    IasUnitGroupJointAdOtherType = -1,
    IasUnitGroupJointAdNativeType = 0,
    IasUnitGroupJointAdRewardedType = 1,
    IasUnitGroupJointAdBannerType = 2,
    IasUnitGroupJointAdInterstitialType = 3,
    IasUnitGroupJointAdSplashType = 4,
};

typedef NS_ENUM(NSInteger, IasNetworkCurrencyType) {
    IasNetworkCurrencyCNYType = 0,
    IasNetworkCurrencyUSDType,
};

typedef NS_ENUM(NSInteger, IasNUrlAuctionBidToWinType) {
    IasNUrlAuctionBidToWinTypeUseCurrentPrice = 1,
    IasNUrlAuctionBidToWinTypeUseZeroPrice = 2
};



typedef NS_ENUM(NSInteger, IasNativeMaterialType) {
    IasNativeMaterialTypeCrossPic = 1,
    IasNativeMaterialTypeVerticalPic = 2,
    IasNativeMaterialTypeCrossVideo = 3,
    IasNativeMaterialTypeVerticalVideo = 4,
    IasNativeMaterialTypeThreePic = 5,
    IasNativeMaterialTypeBanner = 6,
    IasNativeMaterialTypeOther = 7,
};


typedef NS_ENUM(NSInteger, IasCallBackPriceType) {
    IasCallBackPriceTypeCurrentPrice        = 1,   // 返回price
    IasCallBackPriceTypeSortPriorityLevel   = 2,   // 返回sortPriorityLevel，本期先当price处理，后续再补充。
    IasCallBackPriceTypeZeroPrice           = 3    // 返回0
};

@interface IasUnitGroupModel : IasModel <IasModelProtocol, IasStorageEntityProtocol>
-(instancetype) initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, assign) IasRequestFiledType requestFiledType;
@property (nonatomic, assign) IasAdListType adListType;

@property(nonatomic, strong) NSString *tpBidID;

@property(nonatomic, readonly, weak) Class adapterClass;
@property(nonatomic, readonly) NSString *adapterClassString;
@property(nonatomic, readonly) NSInteger capByDay;
@property(nonatomic, readonly) NSInteger capByHour;
@property(nonatomic, assign) NSTimeInterval networkCacheTime;
@property(nonatomic, readonly) NSInteger networkFirmID;

@property(nonatomic, readonly) NSString *networkName;
@property (nonatomic, strong) NSString *unitName;
@property(nonatomic, readonly) NSInteger networkRequestNum;
@property(nonatomic, readonly) NSTimeInterval networkDataTimeout; //  5.1.0 双回调数据超时
@property(nonatomic, readonly) NSTimeInterval networkTimeout;
@property(nonatomic, readonly) NSTimeInterval skipIntervalAfterLastLoadingFailure;
@property(nonatomic, readonly) NSTimeInterval skipIntervalAfterLastBiddingFailure;
/// 废弃
@property(nonatomic, readonly) NSString *unitGroupID;
@property(nonatomic, readonly) NSString *unitID;
@property(nonatomic, readonly) NSDictionary *content;
@property(nonatomic, readonly) NSTimeInterval showingInterval;//minimum interval between previous request & last impression
@property(nonatomic, readonly) CGSize adSize;
@property(nonatomic, readonly) NSTimeInterval autoRefreshInterval;

@property(nonatomic, readonly) BOOL splashZoomOut;
@property(nonatomic, strong) NSString *price;
@property(nonatomic, strong) NSString *ecpmByCurrency;
@property(nonatomic, readonly) NSInteger ecpmLevel;
@property(nonatomic, readonly) NSTimeInterval headerBiddingRequestTimeout;
@property(nonatomic, strong) NSString *bidPrice;
@property(nonatomic, strong) NSString *bidToken;
@property(nonatomic, readonly) BOOL headerBidding;
@property(atomic, assign) IasUnitGroupType unitGroupType;
@property(nonatomic, readonly) NSTimeInterval bidTokenTime;
@property(nonatomic, readonly) NSTimeInterval statusTime;
@property(nonatomic, readonly) NSString *clickTkAddress;
@property(nonatomic, readonly) NSTimeInterval clickTkDelayMin;
@property(nonatomic, readonly) NSTimeInterval clickTkDelayMax;
@property(nonatomic, readonly) BOOL postsNotificationOnShow;
@property(nonatomic, readonly) BOOL postsNotificationOnClick;
@property(nonatomic, strong) NSString *precision;
@property(nonatomic, readonly) BOOL canAutoReady;
@property(nonatomic, readonly) BOOL waterfallTimeOutSW;
@property(nonatomic, readonly) BOOL reportBidPriceSW;
@property(nonatomic, assign) BOOL bidRealTimeLoadSW;
@property(nonatomic, readonly) BOOL returnHBEcpmSW;
@property(nonatomic, strong) IasBidInfo *bidInfo;

@property(nonatomic, readonly, getter=isBidInfoNoPrice) BOOL bidInfoNoPrice;
@property(nonatomic, readonly) BOOL unitGroupS2SSW;

@property(nonatomic) BOOL s2sRewardEnabled;

// v5.7.61+
@property(nonatomic, readonly) NSInteger weight;

@property(nonatomic, copy) NSString *directOfferOid;
// v6.1.10
@property (nonatomic,readonly) NSTimeInterval showDelay;

@property(nonatomic, assign) IasShowAutoLoadType showAutoLoadType;


@property(nonatomic) NSInteger priority; // when ad is filterd

/// ad type：0 Native, 1 Rewarded, 2 Banner, 3 Interstitial, 4 Splash
@property(nonatomic, assign) IasUnitGroupJointAdType jointAdType;

@property(nonatomic, assign) BOOL isHBAdvanceRequest;

@property (nonatomic,strong) NSString *bidFloor;

// 新价格
@property (nonatomic, strong) NSString *sortPriorityLevel;

//reference 6.1.42
@property(nonatomic) NSInteger s2sSendLossPosition;

@property (nonatomic, strong) NSString *bidinfoEcpmStr;

@property (nonatomic, assign) IasNetworkCurrencyType networkCurrencyType;

/// 仅在展示时发送Win
@property (nonatomic, assign) BOOL onlyDisplaySendWin;


@property (nonatomic, assign) BOOL networkEstimatePriceSwitch;

@property (nonatomic, assign) IasNetworkEstimatePriceType networkEstimatePriceType;

@property (nonatomic, strong) NSString *networkEstimatePresentShowEcpmPrice;


@property (nonatomic, strong) NSArray *mixAdClickAreaArray;
@property (nonatomic, strong) NSArray<NSString *> *contentURLStrings;

/// C2S 广告加载成功 时间戳
@property (nonatomic, strong) NSDate *adDataSucceedDate;
/// C2S 渲染成功 时间戳
@property (nonatomic, strong) NSDate *adRenderSucceedDate;
/// 广告 开始请求 时间戳
@property (nonatomic, strong) NSDate *requestStartDate;

/// IpaAd SDK允许京媒平台竞价广告源返回的最大bid price
@property (nonatomic, assign) CGFloat permitMaxBidPrice;
/// 对京媒平台竞价广告源返回的bid price进行价格扣量的系数
@property (nonatomic, assign) CGFloat quantityDiscountRate;

/// 是否使用IpaAd的账号，注意：暂时只有京媒平台使用（sdk6_2_95）
@property (nonatomic, assign) BOOL isUseIpaAdAccount;

#pragma mark - NewDepart

@property (nonatomic, readonly) IasAdapter *adapter;

@property (nonatomic, strong) NSDictionary *dictionary;

/// see -[IasUnitGroup updateSamePriceWeight]
@property (atomic, assign, readonly) CGFloat samePriceWeight;

@property (nonatomic, readonly) NSInteger adsMaxCacheNum;

@property (nonatomic, assign) BOOL isPermitSendWin;

@property (nonatomic, assign) BOOL isPermitSendLoss;

@property (nonatomic, strong) NSString *admobRequestAgent;
@property (nonatomic, assign) BOOL isNativeShakeSwitch;

// v6.2.69
@property(nonatomic, readonly) NSInteger admobBibType;
@property(nonatomic, readonly) BOOL isAdmobHybrid;
@property(nonatomic, readonly) NSInteger networkId;


@property (nonatomic, strong) NSString *customExtString;
@property (nonatomic, strong) NSArray<NSNumber *> *supportExpressType;

// v6.2.96
// 混用原生渲染类型
@property(nonatomic, readonly) IasRenderingType renderingType;
@property(nonatomic, readonly) IasAdOfferInterType interType;

@property (nonatomic, assign) BOOL isHBInfoDaSwitch;

@property (nonatomic, assign) IasMixRewardGiveOutType mixRewardGiveOutType;

// 动态竞价底价开关，默认下发为2，关
@property (nonatomic, readonly) BOOL isDynamicBidFloorSwitch;

//优量汇堆栈信息上报开关（sdk6.3.45新增），暂时只有优量汇用到，枚举说明
//1：开启（默认）
//2：关闭
@property (nonatomic, readonly) BOOL isGdtStackSwitch;

@property (nonatomic, assign) IasNUrlAuctionBidToWinType nUrlAuctionBidToWinType;

// 用于标记每次广告位策略请求标识，每个广告源在每次广告位策略请求中都会获得唯一的unique_id
@property (nonatomic, strong) NSString *uniqueId;
// 用于ecpm加密的密钥数据
// 服务端密钥对应的唯一标识
@property (nonatomic, assign) NSInteger serverKeyId;
// 客户端密钥对应的唯一标识
@property (nonatomic, assign) NSInteger clientKeyId;
// 客户端竞价广告源非对称加密算法的公钥
@property (nonatomic, strong) NSString *clientPubKey;
// ecpm加密后的(ecpm+unitid)数据
@property (nonatomic, strong) NSString *clientSideEcpmKeyString;
// 动态出价底价
@property (nonatomic, strong) NSString *dynamicFloorPrice;
#pragma mark - 三方广告信息
/// 原生广告素材类型(百度需要)
@property (nonatomic, assign) IasNativeMaterialType nativeMaterialType;
/// 广告源请求时间戳
@property (nonatomic, strong) NSNumber *requestTimesTamp;
/// 三方广告 请求ID
@property (nonatomic, strong) NSString *network_requestID;

@property (nonatomic, strong) NSDictionary *winAdInfoDic;
///三方广告 加密价格
@property (nonatomic, strong) NSString *network_en_p;
// 竞价成功
@property (nonatomic, assign) IasCallBackPriceType adSourceBidSuccessCallBackPriceType;
// 广告源请求开始
@property (nonatomic, assign) IasCallBackPriceType adSourceRequestCallBackPriceType;
// 广告源填充成功或者失败
@property (nonatomic, assign) IasCallBackPriceType adSourceRequestResultRCallBackPriceType;
// 查询广告缓存
@property (nonatomic, assign) IasCallBackPriceType checkAdCacheCallBackPriceType;
// 广告展示及展示后行为
@property (nonatomic, assign) IasCallBackPriceType showCallBackPriceType;

@property (nonatomic, assign) BOOL shouldAdapterLoadedSendWin;

- (BOOL)validateForCapsWithPlacementId:(NSString *)placementId;
- (BOOL)validateForPacingWithPlacementId:(NSString *)placementId;

/// same price need a order, use samePriceWeight to order, when ad cache return
/// @param newWeight when water fall load, will calculate new weight
- (void)updateSamePriceWeight:(CGFloat)newWeight;

- (BOOL)saveWithUnitGroup:(IasUnitGroupModel *)unitGroup;
- (void)updateWithUnitGroup:(IasUnitGroupModel *)unitGroup;
- (void)removeWithUnitGroup:(IasUnitGroupModel *)unitGroup;
/// 注意:获取最新加载生成的 UnitGroupModel
- (IasUnitGroupModel *)readUnitGroupWithIdentifier:(NSString *)identifier;

- (BOOL)isAuthNetworkPrivacy;

- (BOOL)isC2SType;
- (BOOL)isS2SType;

@end
