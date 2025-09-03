//
//  IasBidInfo.h
//  IpaAdSDK
//
//  Created by Leo on 2020/4/27.
//  Copyright © 2020 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasModel.h>

@class IasUnitGroupModel;

NS_ASSUME_NONNULL_BEGIN

#define kIasBiddingInitiatingFailedCode -2
#define kIasBiddingNetworkTimeoutCode -3
#define KIasBiddingS2SConnectionErrorCode -4
#define kIasBiddingBiddingFailedByCapCode -5
#define kIasBiddingBiddingFailedByPacingCode -6
#define kIasBiddingBiddingFailedIntervalCode -7
#define kIasBiddingBiddingFailedByExcludedCode -8
#define kIasBiddingBiddingFailedIntegrationErrorCode -9
#define kIasBiddingBiddingFailedBidFloor -11
#define kIasBiddingBiddingFailedHighPrices -12

typedef NS_ENUM(NSInteger, IasHBAdvanceRequestType) {
    IasHBAdvanceRequestUnknownType = 0,
    IasHBAdvanceRequestYesType,
    IasHBAdvanceRequestNOType,
};

typedef NS_ENUM(NSInteger, IasADXMixType) {
    IasADXMixTypeDefault              = -1, // 下发-1或与原广告位类型一致表示不混用
    IasADXMixTypeNativeSelfRender     = 0,  // 原生（自定义渲染）
    IasADXMixTypeBanner               = 2,  // Banner
    IasADXMixTypeSplash               = 4,  // Splash
    IasADXMixTypeVideo                = 5,  // 视频
    IasADXMixTypeNativeExpress        = 7   // 原生（模板）
};

@interface IasBidInfo : IasModel

@property (atomic, readonly) NSString *unitID;
@property (nonatomic, readonly) NSDate *expireDate;
@property (nonatomic, readonly) NSDictionary *offerDataDict;
@property (nonatomic, readonly) NSString *bidId;
@property (nonatomic, readonly) NSString *tpBidId;
@property (nonatomic, readonly) IasBiddingCurrencyType currencyType;
@property (nonatomic, readonly) id customObject;
@property (nonatomic, readonly) NSString *placementID;
@property (nonatomic, readonly) NSString *adapterClassString;
@property (nonatomic, readonly) NSString *lURL;
@property (nonatomic, readonly) NSString *nURL;
@property (nonatomic, readonly) NSString *bURL;
@property (nonatomic, readonly) NSString *bURLWin;
@property (nonatomic, readonly) NSString *reqURL;
@property (nonatomic, readonly) BOOL bidResultCanRequest;
@property (nonatomic, readonly) IasUnitGroupType unitGroupType;
@property (nonatomic, readonly, getter=isValid) BOOL valid;
@property (nonatomic, readonly, getter=isExpired) BOOL expired;
@property (nonatomic, readonly, getter=isSendNotif) BOOL sendNotif;
@property (nonatomic, readonly, getter=isNoPrice) BOOL noPrice;
@property (nonatomic, assign) NSInteger networkFirmID;
@property (nonatomic, strong) NSString *ksOriginPrice;
@property (nonatomic, strong) NSString *networkOriginPrice;
@property (nonatomic, strong) NSString *sortPriorityLevel;
@property (nonatomic, strong) NSString *price;
@property (nonatomic, strong) NSString *ecpmApi;
@property (nonatomic, strong) NSString *precision;
///用来发送win/loss,转换三方平台所需要币种汇率
@property (nonatomic, strong) NSString *curRate;
@property (nonatomic, readwrite) NSTimeInterval bidTime;
@property (nonatomic, readwrite) BOOL bidPriceSmallerlast;
@property (nonatomic, readwrite) BOOL bidResultIsFailed;
@property (nonatomic, strong) NSError *error;
// for load success retry send tk&da auto_req
@property (nonatomic, readwrite) BOOL isLoadSuccessRetry;
@property (nonatomic, assign) IasHBAdvanceRequestType HBAdvanceRequestType;
@property (nonatomic, assign) BOOL isC2SNotNeedLoad;
@property (nonatomic, strong) id c2sCustomObject;
@property (nonatomic, strong) id c2SCustomEvent;
// for send win notification
@property (nonatomic, strong) NSString *nextUGPrice;
@property (nonatomic, strong) NSString *nextUGPriceNetworkName;
@property (nonatomic, strong) NSString *nextUGID;
@property (nonatomic, weak) IasUnitGroupModel *nextUG;
// for send loss notification
@property (nonatomic, weak) IasUnitGroupModel *winUG;

// only for Adx DirectOffer
@property (nonatomic, strong) NSString *offerID;
@property (nonatomic, strong) NSString *offerDspID;
@property (nonatomic, assign) BOOL isAdxNetworkDeveloperSend;
/// adx 折扣策略
@property (nonatomic, assign) CGFloat adxRate;
@property (nonatomic, copy) NSDictionary *bidResult;
// 用于ecpm加密的密钥数据
// 服务端密钥的唯一标识
@property (nonatomic, readonly, assign) NSInteger serverKeyId;
// ecpm加密后的(ecpm+unitid)数据
@property (nonatomic, strong) NSString *clientSideEcpmKeyString;
// adx模板最终需要渲染的广告类型
@property (nonatomic, assign) IasADXMixType adxMixType;

@property (nonatomic, assign) BOOL abnormalWinLoss;
@property (nonatomic, strong) NSString *abnormalPrice;
/// 第一次生成bidInfo时候,requestID
@property (nonatomic, strong) NSString *original_requestID;
/// C2S
/// - Parameters:
///   - placementID: placementID
///   - unitGroupUnitID: unitGroupUnitID
///   - adapterClassString: adapterClassString
///   - price:used to estimate prices and callback prices,The currency is in US dollars or Chinese yuan
///   - sortPrice: the sort price used in waterfall request,The currency is in US dollars or Chinese yuan
///   - currencyType: currency type
///   - expirationInterval: expiration Interval
///   - customObject: customObject, as ad source object
+ (instancetype)bidInfoC2SWithPlacementID:(NSString *)placementID
                          unitGroupUnitID:(NSString *)unitGroupUnitID
                       adapterClassString:(NSString *)adapterClassString
                                    price:(NSString *)price
                                sortPrice:(NSString *)sortPrice
                             currencyType:(IasBiddingCurrencyType)currencyType
                       expirationInterval:(NSTimeInterval)expirationInterval
                             customObject:(_Nullable id)customObject;

/// C2S
/// - Parameters:
///   - placementID: placementID
///   - unitGroupUnitID: unitGroupUnitID
///   - adapterClassString: adapterClassString
///   - price:used to estimate prices and callback prices,The currency is in US dollars or Chinese yuan
///   - currencyType: currency type
///   - expirationInterval: expiration Interval
///   - customObject: customObject, as ad source object
+ (instancetype)bidInfoC2SWithPlacementID:(NSString *)placementID
                          unitGroupUnitID:(NSString *)unitGroupUnitID
                       adapterClassString:(NSString *)adapterClassString
                                    price:(NSString *)price
                             currencyType:(IasBiddingCurrencyType)currencyType
                       expirationInterval:(NSTimeInterval)expirationInterval
                             customObject:(_Nullable id)customObject;

/// S2S
- (instancetype)initS2SWithDictionary:(NSDictionary *)dictionary
                          placementID:(NSString *)placementID
                       unitGroupModel:(IasUnitGroupModel *)unitGroupModel
                         currencyType:(IasBiddingCurrencyType)currencyType;

/// adx cache 
- (instancetype)initWithCacheDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)serializationToDictionary;

- (void)hasBeenSendNotif;
- (void)saveOfferModelDspID:(NSString *)offerDspID withOfferID:(NSString *)offerID;
- (void)encryptedC2SFilledPriceWithRequestID:(NSString *)requestID publicKey:(NSString *)publicKey;
- (void)releasCustomObject;
//- (NSString *)getBidInfoPrice;
//- (NSString *)getBidInfoSortPriorityLevel;
+ (NSString *)getExchRateC2U:(NSString *)placementID;

@end

NS_ASSUME_NONNULL_END
