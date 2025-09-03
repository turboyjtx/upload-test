//
//  IasAdAdapter.h
//  IpaAdSDK
//
//  Created by Leo on 05/07/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#ifndef IasAdAdapter_h
#define IasAdAdapter_h

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kIasADapterCustomInfoStatisticsInfoKey;
extern NSString *const kIasAdapterCustomInfoPlacementModelKey;
extern NSString *const kIasAdapterCustomInfoUnitGroupModelKey;
extern NSString *const kIasAdapterCustomInfoRequestIDKey;
extern NSString *const kIasAdapterCustomInfoExtraKey;
extern NSString *const kIasAdapterCustomInfoBuyeruIdKey;
extern NSString *const kIasAdapterCustomInfoBidInfoKey;
extern NSString *const kIasAdapterCustomInfoBidResultKey;
extern NSString *const kIasAdapterCustomInfoBidPlacementIDKey;
extern NSString *const kIasDynamicHBFloorPriceKey;
extern NSString *const kIasAdapterNetworkEstimatePriceNumKey;
extern NSString *const kIasAdapterNetworkEstimatePriceSwitchKey;
extern NSString *const kIasAdapterCustomInfoBaiduInfoKey;
extern NSString *const kIasAdapterCustomInfoAdmobRequestAgentInfoKey;
extern NSString *const kIasAdapterCustomInfoKuaishouInfoKey;


extern NSString *const kIasHeaderBiddingParametersUnitIdKey;
extern NSString *const kIasHeaderBiddingParametersNetworkFirmIdKey;
extern NSString *const kIasHeaderBiddingParametersAdFormatKey;
extern NSString *const kIasHeaderBiddingParametersAdSourceIdKey;
extern NSString *const kIasHeaderBiddingParametersEcpofferKey;
extern NSString *const kIasHeaderBiddingParametersGetOfferKey;
extern NSString *const kIasHeaderBiddingParametersExpressType;
extern NSString *const kIasHeaderBiddingParametersUnitTypeKey;
extern NSString *const kIasHeaderBiddingParametersDisplayManagerVersionKey;
extern NSString *const kIasHeaderBiddingParametersTplVersionKey;
extern NSString *const kIasHeaderBiddingParametersAppIdKey;
extern NSString *const kIasHeaderBiddingParametersAppKey;
extern NSString *const kIasHeaderBiddingParametersAccountIdKey;
extern NSString *const kIasHeaderBiddingParametersBuyeruIdKey;
extern NSString *const kIasHeaderBiddingParametersBidTokenKey;
extern NSString *const kIasHeaderBiddingParametersAdWidthKey;
extern NSString *const kIasHeaderBiddingParametersAdHeightKey;

extern NSString *const kIasHeaderBiddingParametersDirectOfferKey;
extern NSString *const kIasDirectOfferHeaderBiddingUnitGroupsKey;

extern NSString *const kIasHeaderBiddingParametersDirectOfferSizeKey;


extern NSString *const kIasHeaderBiddingParametersBidFormatKey;
extern NSString *const kIasHeaderBiddingParametersBidderTypeKey;
extern NSString *const kIasHeaderBiddingParametersUnitGroupKey;

extern NSString *const kIasHeaderBiddingParametersSDKInfoKey;
extern NSString *const kIasHeaderBiddingParametersADPAcceptTypeKey;
extern NSString *const kIasHeaderBiddingParametersADXVASTMaxVersionKey;
extern NSString *const kIasHeaderBiddingParametersADXMixTypeKey;

extern NSString *const kIasHeaderBiddingParametersAdmobBidTypeKey;
extern NSString *const kIasHeaderBiddingParametersNetworkIdKey;


@interface IasAdAdapter : NSObject


@end

@protocol IasAd;
@class IasPlacementModel;
@class IasUnitGroupModel;
@class IasMyOfferOfferModel;
@class IasBidInfo;
@class IasWaterfallModel;
@class IasInHouseBidRequest;

typedef NS_ENUM(NSInteger, IasBiddingLossType) {
    IasBiddingLossWithLowPriceInNormal = 103,
    IasBiddingLossWithLowPriceInHB = 102,
    IasBiddingLossWithBiddingTimeOut = 2,
    IasBiddingLossWithExpire = 5,
    IasBiddingLossWithFloorFilter = 104
};

@protocol IasAdAdapter <NSObject>

#pragma mark - Initialize network SDK and start load ad with network SDK

/// Adapter initialization method
/// - Parameters:
///   - serverInfo: Data from the server
///   - localInfo: Data from the local
- (nonnull instancetype)initWithNetworkCustomInfo:(nonnull NSDictionary *)serverInfo
                                localInfo:(nonnull NSDictionary *)localInfo;

#pragma mark - Normal
/// Adapter sends a load request, means the ad source sends an ad load request
/// - Parameters:
///   - serverInfo: Data from the server
///   - localInfo: Data from the local
///   - completion: completion
- (void)loadADWithInfo:(nonnull NSDictionary *)serverInfo
             localInfo:(nonnull NSDictionary *)localInfo
            completion:(nonnull void (^)(NSArray<NSDictionary *> * _Nonnull array, NSError * _Nonnull error))completion;

/// Check whether the ad source is ready
/// - Parameters:
///   - customObject: ad source object
///   - info: info
+ (BOOL)adReadyWithCustomObject:(nonnull id)customObject info:(nonnull NSDictionary *)info;

+ (BOOL)isSupportAdType:(IasUnitGroupModel *)unitGroupModel;

@optional

@property (nonatomic,copy) void (^metaDataDidLoadedBlock)(void);

/*
 * Create a rewarded instance for download event and FOR DOWNLOAD EVENT ONLY.
 */
+ (id<IasAd>)readyFilledAdWithPlacementModel:(IasPlacementModel *)placementModel
                                  requestID:(NSString *)requestID
                                   priority:(NSInteger)priority
                                  unitGroup:(IasUnitGroupModel *)unitGroup
                             finalWaterfall:(IasWaterfallModel *)finalWaterfall
                                  localInfo:(NSDictionary *)localInfo;
+ (BOOL)adReadyForInfo:(NSDictionary *)info;

@end
#endif /* IasAdAdapter_h */

NS_ASSUME_NONNULL_END
