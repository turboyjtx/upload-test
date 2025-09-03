//
//  IasTempWaterfallWrapper.h
//  IpaAdSDK
//
//  Created by GUO PENG on 2022/10/20.
//  Copyright © 2022 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasAd.h>


NS_ASSUME_NONNULL_BEGIN
@class IasUnitGroupModel;
@class IasPlacementModel;
@class IasWaterfallModel;


typedef enum : NSUInteger {
    IaswaterfallModuleTypeStart = 1,
    IasWaterfallModuleTypeNext,
    IasWaterfallModuleTypeAdvance,
    IasWaterfallModuleTypeDynamic,
} IasWaterfallModuleType;

typedef enum : NSUInteger {
    IasLoadedCallbackTypeAdSourceStatusCached,
    IasLoadedCallbackTypeNormalRequest
} IasLoadedCallbackType;



@interface IasWaterfallInfoModel : NSObject
//use in delegate call back success

@property (nonatomic, assign) BOOL isSharePlacementSucceeded;

@property (nonatomic, strong) NSString *requestID;

@property (nonatomic, assign) IasWaterfallModuleType waterfallModuleType;

@property(nonatomic, assign) BOOL waterFallfinished;

@property(nonatomic, assign) BOOL finished;

@property(nonatomic, strong) NSDate *loadStartDate;

@property(nonatomic, assign, getter=isFilled) BOOL filled;

@property(nonatomic, strong) IasWaterfallModel *waterfall;
@property(nonatomic, strong) IasWaterfallModel *finalWaterfall;
@property(nonatomic, strong) IasWaterfallModel *defaultWaterfall;

@property(nonatomic, assign) BOOL headerBiddingFired;
@property(nonatomic, assign) BOOL headerBiddingFailed;
@property(nonatomic, assign) BOOL hasBeenShowInWaterfall;

@property(nonatomic, assign) NSInteger numberOfCachedOffers;

@property(nonatomic, assign) BOOL isFillTimeout;
// TODO: ADX 位置??
@property(nonatomic, strong) id<IasAd> _Nullable adxOfferCached;

@property(nonatomic, assign) IasLoadedCallbackType loadedCallbackType;

@property (nonatomic, assign) NSInteger highestPriorityOfShownAd;


- (void)finish;
- (void)fill;
- (void)hasBeenShow;
- (void)markUnfinished;
- (void)destroy;


- (void)removeAdxOfferCached;

/// 获取所有瀑布流 已填充最低价格
- (IasUnitGroupModel*)filledUnitGroupWithMaximumPrice;
- (IasUnitGroupModel *)filledUnitGroupPriceNextLoadWithExpectedIndex:(NSInteger)expectedIndex isNeedBeyondEmpty:(BOOL)isNeedBeyondEmpty;

+ (instancetype)waterfallInfoWithWaterfallModel:(IasWaterfallModel *)waterfallModel;



@end

NS_ASSUME_NONNULL_END
