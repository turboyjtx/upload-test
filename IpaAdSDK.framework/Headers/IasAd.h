//
//  IasAd.h
//  IpaAdSDK
//
//  Created by Leo on 28/06/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#ifndef IasAd_h
#define IasAd_h
#import <IpaAdSDK/IasPlacementModel.h>
#import <IpaAdSDK/IasUnitGroupModel.h>


@class IasWaterfallModel,IasAdCustomEvent,IasCustomContentResult;

@protocol IasAd<NSObject>

- (void)setupPriority:(NSInteger) priority placementModel:(IasPlacementModel*)placementModel requestID:(NSString*)requestID assets:(NSDictionary*)assets unitGroup:(IasUnitGroupModel*)unitGroup finalWaterFall:(IasWaterfallModel *)finalWaterFall;
-(void) renewAdWithPlacementModel:(IasPlacementModel*)placementModel requestID:(NSString*)requestID;

- (void)releasCustomObject;
@property(nonatomic, readonly) IasPlacementModel *placementModel;
@property(nonatomic, readonly) IasUnitGroupModel *unitGroup;
@property(nonatomic, strong) NSMutableArray<NSDictionary*> *unitGroupInfos;

/**
 Priority is calculate by the index of the unit group in the placement's unit group list; zero is the highest
 */
@property(nonatomic, readonly) NSInteger priority;
@property(nonatomic, readonly) NSInteger priorityLevel;//the order in witch this ad has been requested
@property(nonatomic, readonly) NSString *requestID;

@property(nonatomic, readonly) NSString *originalRequestID;
@property(nonatomic, assign) NSInteger showTimes;
@property(nonatomic, readonly) NSDate *expireDate;
@property(nonatomic, readonly) NSDate *cacheDate;
/**
 * Third-party network native ad object.
 */
@property(nonatomic, readonly) id customObject;
@property(nonatomic, readonly) NSString *unitID;
@property(nonatomic, readonly) NSString *appID;
- (NSString *)ecpm;
- (NSString *)bidFloor;

@optional
-(instancetype) initWithPriority:(NSInteger) priority placementModel:(IasPlacementModel*)placementModel requestID:(NSString*)requestID assets:(NSDictionary*)assets unitGroup:(IasUnitGroupModel*)unitGroup finalWaterFall:(IasWaterfallModel *)finalWaterFall;
-(BOOL) expired;
-(BOOL) ready;
@property(nonatomic, readonly) BOOL filledByReady;
@property(nonatomic, readonly) BOOL filledByAutoloadOnClose;
@property(nonatomic, readonly) NSInteger fillByfreshType;
@property(nonatomic) BOOL defaultPlayIfRequired;
@property(nonatomic) BOOL defaultAdxOfferCached;
@property(nonatomic, readonly) BOOL renewed;
@property(nonatomic, readonly) NSString *price;

@property (nonatomic, strong) NSString *sortPriorityLevel;

@property(nonatomic, readonly) NSString *bidId;
@property(nonatomic, readonly) NSString *tpBidId;
@property(nonatomic, readonly, weak) IasWaterfallModel *finalWaterfall;
@property(nonatomic, readonly) NSInteger autoReqType;
@property(nonatomic) BOOL adReportClicked;

@property (nonatomic, assign) BOOL isSharePlacementOffer;

/// placementMode maybe is share placement, so this save true placment id,
@property (nonatomic, strong) NSString *placementId;

@property (nonatomic, strong) IasAdCustomEvent *customEvent;
@property (nonatomic, strong) NSString *scene;
@property (nonatomic, strong) NSString *showCustomExt;
@property (nonatomic, strong) IasCustomContentResult *customContentResult;
@property (nonatomic) BOOL adHasReportImpression;

//是否开发者指定展示广告对象
@property(nonatomic) BOOL isUserSetAd;

@end

#endif /* IasAd_h */
