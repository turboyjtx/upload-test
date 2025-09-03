//
//  IasTempWaterfall.h
//  IpaAdSDK
//
//  Created by GUO PENG on 2022/10/20.
//  Copyright © 2022 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasUnitGroupModel.h>
#import <IpaAdSDK/IasPlacementModel.h>




typedef NS_ENUM(NSInteger, IasWaterfallType) {
    IasWaterfallTypeWaterfall = 0,
    IasWaterfallTypeFinal = 2
};

typedef NS_ENUM(NSInteger, IasUnitGroupFinishType) {
    IasUnitGroupFinishTypeFinished = 0,
    IasUnitGroupFinishTypeTimeout = 1,
    IasUnitGroupFinishTypeFailed = 2
};

NS_ASSUME_NONNULL_BEGIN

@interface IasWaterfallModel : NSObject

@property(nonatomic, strong) NSString *requestID;
@property(nonatomic, strong) NSString *placementID;
@property(nonatomic, strong) NSMutableArray <IasUnitGroupModel*> *unitGroups;
// HB提前请求 UG
@property(nonatomic, strong) NSMutableArray <IasUnitGroupModel*> *advanceSendUGArray;
// 动态出价 UG
@property(nonatomic, strong) NSMutableArray <IasUnitGroupModel*> *dynamicSendUGArray;
// 发送请求的 UG
@property(nonatomic, strong) NSMutableArray <IasUnitGroupModel*> *requestSentUnitGroups;
// 请求 超时 数量
@property(nonatomic, assign) NSUInteger numberOfTimeoutRequests;
// 瀑布流类型
@property(nonatomic, assign) IasWaterfallType type;
// 瀑布流 是否结束
@property(nonatomic, assign, getter=isLoading) BOOL loading;
// TODO 请求类型
@property(nonatomic, assign) IasLoadingAdApiType loadingApiType;
// TODO 广告位策略
@property (nonatomic, weak) IasPlacementModel *placement;

// init
- (instancetype)initWithUnitGroups:(nullable NSArray<IasUnitGroupModel*>*)unitGroups placementID:(NSString*)placementID requestID:(NSString*)requestID;

- (instancetype)initWithPlacementID:(NSString*)placementID requestID:(NSString*)requestID;

/// 添加 排序后请求 UG
- (void)addRankedAndShuffledUnitGroups:(NSArray<IasUnitGroupModel *> *)unitGroups;
/// 标记 UG 为已发起请求
- (void)requestUnitGroup:(IasUnitGroupModel*)unitGroup;
/// 标记 UG 为 发送请求完成
- (void)finishUnitGroup:(IasUnitGroupModel*)unitGroup withType:(IasUnitGroupFinishType)type;
/// 添加 待发送的 UG
- (void)addUnitGroup:(IasUnitGroupModel*)unitGroup;
/// 插入待发送的UG 内部会排序
- (void)insertUnitGroup:(IasUnitGroupModel*)unitGroup;
- (void)insertUnitGroupArray:(NSArray<IasUnitGroupModel*>*)unitGrous;
/// 移除 已完成的请求UG
- (void)removeFinishedRequestObject:(IasUnitGroupModel *)unitGroup;
/// 获取 已填充的UG
- (NSArray *)getRequestFilledUnitGroups;

/// 根据 unitID 获取UG
- (IasUnitGroupModel*)unitGroupWithUnitID:(NSString*)unitID;
/// 获取价格最大的 UG
- (IasUnitGroupModel*)unitGroupWithMaximumPrice;
/// 获取价格最小的 UG
- (IasUnitGroupModel*)unitGroupWithMinimumPrice;
/// 获取 瀑布流中所有 UG
- (NSMutableArray<IasUnitGroupModel *> *)getWaterfallAllUnitGroups;
/// 获取瀑布流中为发送请求的 UG
- (NSMutableArray<IasUnitGroupModel *> *)getWaterfallAllNotRequestUnitGroups;
/// 获取ug在final waterfall中的优先级
- (NSInteger)getPriorityInFinalWaterfallWithUnitGroup:(IasUnitGroupModel *)unitGroup;
/// 请求中最大价格(过滤指定的UG)
- (IasUnitGroupModel *)requestingUnitGroupMaxPriceWithFilteredUnitID:(NSString *)unitID;

#pragma mark - 提前请求
/// 获取 HB 提前请求 发送数量
- (NSInteger)getAdvanceSendCount;
///  获取 HB 提前请求 最大价格
- (IasUnitGroupModel*)advanceUnitGroupWithMaximumPrice;
/// HB 提前请求 插入 待发送 数组
- (void)insertAdvanceUnitGroup:(IasUnitGroupModel*)unitGroup;
/// 标记 UG 为 已发送
- (void)markAdvanceRequestSendUnitGroup:(IasUnitGroupModel*)unitGroup;
/// 标记 UG为 已填充
- (void)markAdvanceRequestFillUnitGroup:(IasUnitGroupModel*)unitGroup;
/// 获取 提前请求 已填充的 UG 数组
- (NSArray *)getAdvanceRequestFillUnitGroups;

#pragma mark - 动态出价
/// 获取 动态出价 提前请求 发送数量
- (NSInteger)getDynamicSendCount;
/// 获取 动态出价  已填充的 UG 数组
- (NSArray *)getDynamicRequestFillUnitGroups;
/// 获取 动态出价  最大价格
- (IasUnitGroupModel*)dynamicUnitGroupWithMaximumPrice;
/// 标记 UG 为 已发送
- (void)markDynamicRequestSendUnitGroup:(IasUnitGroupModel*)unitGroup;
/// 动态出价 插入 待发送 数组
- (void)insertDynamicUnitGroup:(IasUnitGroupModel*)unitGroup;
/// 标记 UG为 已填充
- (void)markDynamicRequestFillUnitGroup:(IasUnitGroupModel*)unitGroup;

#pragma mark - other
- (IasUnitGroupModel*)firstPendingNonHBUnitGroupWithNetworkFirmID:(NSInteger)nwFirmID;

- (NSString *)getNextPrice:(NSString *)price array:(NSArray *)priceArray;
/// 获取 同价格 UG 数量
- (NSInteger)getEqualPriceRequestsQueuedWithSpacing:(NSInteger)divisionSpacing;
/// 判断 瀑布流是否继续请求
- (BOOL)canContinueLoading:(BOOL)waitForSentRequests;
/// 遍历 请求超时 的 UG
- (void)enumerateTimeoutUnitGroupWithBlock:(void(^)(IasUnitGroupModel*unitGroup))block;

@end

NS_ASSUME_NONNULL_END
