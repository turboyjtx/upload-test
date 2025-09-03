//
//  IasTracker.h
//  IpaAdSDK
//
//  Created by Leo on 19/04/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasAd.h>
#import <IpaAdSDK/IasTrackerInfo.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, IasADTrackType) {
    IasADTrackTypeADRequest = 1, // 广告源请求
    IasADTrackTypeADRecalledSuccessfully = 2, // 广告源填充
    IasADTrackTypeADRecallFailed = 3,
    IasADTrackTypeADImpression = 4, // 广告展示
    IasADTrackTypeADRefreshShow = 5,
    IasADTrackTypeADClicked = 6, // 广告点击
    IasADTrackTypeVideoPlayed = 7,
    IasADTrackTypeVideoStart = 8,
    IasADTrackTypeVideoEnd = 9,
    IasADTrackTypeLoad = 10,
    IasADTrackTypeBidSort = 11, // bid结果上报
    IasADTrackTypeLoadResult = 12,// 加载成功
    IasADTrackTypeShowAPICall = 13, // 广告show API
    IasADTrackTypeEntryScenario = 16,// 上报场景
    IasADTrackTypeEntryLaunch = 21,
    IasADTrackTypeWin = 22,     // 比价SDK竞胜
    IasADTrackTypeLoss = 23,    // 比价SDK竞败
    IasADTrackTypeWinLoss = 24,    // win loss
    IasADTrackTypeComparePrice = 26, // 多聚合比价
};



@interface IasTracker : NSObject

+ (instancetype)sharedTracker;

- (void)trackWithPlacementID:(NSString *)placementID requestID:(NSString *)requestID trackType:(IasADTrackType)trackType extra:(nullable NSDictionary *)extra;
// TK6
- (void)trackClickWithAd:(nonnull id<IasAd>)ad extra:(nullable NSDictionary *)extra;
// TK21
- (void)sendLaunchTrackWithPsId:(NSString *)psId;
// TK22
- (void)trackWinWithPlacementID:(nonnull NSString *)placementID extra:(nullable NSDictionary *)extra;
// TK23
- (void)trackLossWithPlacementID:(nonnull NSString *)placementID extra:(nullable NSDictionary *)extra;
//TK24
- (void)trackWinLossWithPlacementID:(nonnull NSString *)placementID requestId:(NSString *)requestId extra:(nullable NSDictionary *)extra;


+ (nullable NSDictionary *)headerBiddingTrackingExtraWithAd:(id<IasAd>)ad requestID:(NSString *)requestID;

+ (NSDictionary *)replaceBidPrice:(NSDictionary *)originalTKDic unitGroup:(IasUnitGroupModel *)unitGroup;
/// 公共TK参数
+ (NSDictionary *)getTKCommonParameter:(nullable IasUnitGroupModel *)unitGroup placementModel:(nullable IasPlacementModel *)placementModel extraDic:(nullable NSDictionary *)extraDic trackType:(IasADTrackType)trackType;

@end

NS_ASSUME_NONNULL_END
