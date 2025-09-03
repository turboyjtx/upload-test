//
//  IasBidInfoCacheManager.h
//  IpaAdSDK
//
//  Created by Leo on 2020/4/28.
//  Copyright © 2020 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasBidInfo.h>


NS_ASSUME_NONNULL_BEGIN

#define IasHeaderBiddingListKey @"headerBiddingList"
#define IasHbParmeterErrorsKey @"hbParmeterErrors"
#define IasCurrentUnitGroupsKey @"currentUnitGroups"

@class IasUnitGroupModel;
@class IasPlacementModel;
@class IasBidWaterFallModel;
@class IasBidNotifSendModel;
@class IasWaterfallModel;
//@class IasWinLossSendTool;

typedef NS_ENUM(NSUInteger, IasLossType) {
    IasLossAdExpiteType = 1,
    IasLossAdCheckCacheType,
    IasLossAdWaterFallFinshType,
    IasLossAdBidFloorFilterType,
    IasLossAdC2SHBTimeOutType,
    IasLossAdLoadedType,
    IasLossAdUserRemove,
    IasLossAdLoadFailedtype
};
typedef void(^StartBidBlock)(NSDictionary * headerBiddingListDic);

@interface IasBidInfoCacheManager : NSObject

+ (instancetype)sharedManager;

- (void)saveBidInfo:(IasBidInfo*)bidInfo;
- (void)invalidateBidInfoForPlacementID:(NSString*)placementID unitGroupModel:(IasUnitGroupModel*)unitGroupModel;
- (IasBidInfo*)getBidInfoCachedForPlacementID:(NSString*)placementID unitGroup:(IasUnitGroupModel*)unitGroup;

- (NSArray<IasUnitGroupModel*>*)unitGroupWithHistoryBidInfoAvailableForPlacementID:(NSString*)placementID unitGroups:(NSArray<IasUnitGroupModel*>*)unitGroupsToInspect inhouseUnitGroups:(NSArray<IasUnitGroupModel*>*)inhouseUnitGroupsToInspect s2sUnitGroups:(NSArray<IasUnitGroupModel*>*)s2sUnitGroupsToInspect bksUnitGroups:(NSArray<IasUnitGroupModel*>*)bksUnitGroupsToInspect  directUnitGroups:(NSArray<IasUnitGroupModel*>*)directUnitGroups requestID:(NSString*)requestID placementModel:(IasPlacementModel *)placementModel;

/**
 Used for send hb loss notification
 */
- (BOOL)saveWithBidNotifSendModel:(IasBidNotifSendModel*)bidNotifSendModel forRequestID:(NSString*)requestID;
- (IasBidNotifSendModel*)getBidNotifSendModelForRequestID:(NSString*)requestID;

//- (void)saveNoPriceCacheWitBidWaterFallModel:(IasBidWaterFallModel*)bidWaterfallModel;
//- (void)removeNoPriceCacheWithTpBidId:(NSString*)tpBidId unitId:(NSString*)unitId;
//- (IasBidWaterFallModel *)getBidWaterFallModelWithTpBidId:(NSString*)tpBidId unitId:(NSString*)unitId;


+ (NSString *)getPriceToSendHBNotifiForUnitGroup:(IasUnitGroupModel*)unitGroupModel;
+ (NSString *)getSortPriorityPriceToSendHBNotifiForUnitGroup:(IasUnitGroupModel*)unitGroupModel;
//+ (NSString *)priceForBidInfo:(IasBidInfo*)bidInfo;

- (void)removeBidInfoWithDiskForPlacementID:(NSString*)placementID bidInfos:(NSArray<IasBidInfo*>*)bidInfos;


#pragma mark - bid List
- (void)saveBidRequestHBList:(NSDictionary *)hbListExtra forKeyStr:(NSString *)keyStr;
- (NSDictionary *)getBidRequestHbListForKeyStr:(NSString *)keyStr;

@end

NS_ASSUME_NONNULL_END
