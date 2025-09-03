//
//  IasAdManager+Internal.h
//  IpaAdSDK
//
//  Created by Leo on 04/05/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

/**
 * This file contains methods&properties implemented by IasAdManager intented for internal use only.
 */
#ifndef IasAdManager_Internal_h
#define IasAdManager_Internal_h
#import <IpaAdSDK/IasAdManager.h>
#import <IpaAdSDK/IasAd.h>
#import <IpaAdSDK/IasAPI.h>

@class IasCheckLoadModel;

//The value is (subclass of) UIViewController
extern NSString *const kIasAdLoadingExtraRefreshFlagKey;//Defined in loader
extern NSString *const kIasAdLoadingExtraBannerAutoRefreshFlagKey;
extern NSString *const kIasAdLoadingExtraAutoloadFlagKey;
extern NSString *const kIasAdLoadingTrackingExtraStatusKey;
extern NSString *const kIasAdLoadingTrackingExtraFlagKey;
extern NSString *const kIasAdLoadingExtraDefaultLoadKey;

extern NSString *const kIasReadyToShowNotification;

typedef NS_ENUM(NSInteger, IasAdManagerReadyAPICaller) {
    IasAdManagerReadyAPICallerReady = 0,
    IasAdManagerReadyAPICallerShow = 1,
};


@protocol IasBaiduTemplateRenderingAttributeDelegate;

@interface IasAdManager(Internal)
#pragma mark - for inner usage
//TODO: Packing the following method in a category and hide it from the client code.
/**
 The following ps id accessing methods are thread-safe.
 */
//TOOD ZSR 无用的

@property(nonatomic, strong) id<IasBaiduTemplateRenderingAttributeDelegate> baiduTemplateRenderingAttributeValue;


/**
 nil might be returned on one of the following conditions:
 1) No offer's been successfully loaded for the placement;
 2) Pacing/caps has exceeded the limit.
 when this happens, clients are expected to behave as if ad load request has failed.
 */
-(id<IasAd>) offerWithPlacementID:(NSString*)placementID error:(NSError**)error refresh:(BOOL)refresh;

/*
 Check if ad's ready for a placement, context is a storage specific block
 */
- (BOOL)adReadyForPlacementID:(NSString*)placementID scene:(NSString*)scene caller:(IasAdManagerReadyAPICaller)caller context:(BOOL(^)(NSDictionary *__autoreleasing *extra))context;
- (BOOL)adReadyForPlacementID:(NSString*)placementID caller:(IasAdManagerReadyAPICaller)caller context:(BOOL(^)(NSDictionary *__autoreleasing *extra))context;
- (BOOL)adReadyForPlacementID:(NSString*)placementID scene:(NSString*)scene caller:(IasAdManagerReadyAPICaller)caller sendTK:(BOOL)send context:(BOOL(^)(NSDictionary *__autoreleasing *extra))context;
- (BOOL)adReadyForPlacementID:(NSString*)placementID showConfig:(IasShowConfig *)showConfig caller:(IasAdManagerReadyAPICaller)caller sendTK:(BOOL)send context:(BOOL(^)(NSDictionary *__autoreleasing *extra))context;

/*
 *For internal use only
 */
- (BOOL)adReadyForPlacementID:(NSString*)placementID;
- (BOOL)adReadyForPlacementID:(NSString*)placementID sendTK:(BOOL)send;


-(NSDictionary*)extraInfoForPlacementID:(NSString*)placementID requestID:(NSString*)requestID;
-(void) setExtraInfo:(NSDictionary*)extraInfo forPlacementID:(NSString*)placementID requestID:(NSString*)requestID;
-(void) removeExtraInfoForPlacementID:(NSString*)placementID requestID:(NSString*)requestID;
-(NSDictionary*)lastExtraInfoForPlacementID:(NSString*)placementID;
-(void) clearCacheWithPlacementModel:(IasPlacementModel*)placementModel unitGroupModel:(IasUnitGroupModel*)unitGroupModel;


#pragma mark - other
- (BOOL)getInspectAdSourceStatusPlacementModel:(IasPlacementModel*)placementModel loadingUG:(IasUnitGroupModel *)loadingUG finalWaterfall:(IasWaterfallModel*)finalWaterfall requestID:(NSString*)requestID extraInfoArray:(NSArray<NSDictionary *> *__autoreleasing *)adSourceStatusInpectionExtraInfo;

#pragma mark - Data
- (void)unionEntryAdScenarioWithPlacementID:(NSString *)placementID scene:(NSString *)scene;
- (IasCheckLoadModel*)unionCheckAdLoadStatusForPlacementID:(NSString *)placementID;
- (NSArray<NSDictionary *> *)unionGetAdValidAdsForPlacementID:(NSString *)placementID;

#pragma mark - Is Ready

- (BOOL)checkFormatWithPlacementId:(NSString *)placementId format:(IasAdFormat)format;
- (BOOL)unionReadyForPlacementID:(NSString*)placementID showConfig:(IasShowConfig *)showConfig caller:(IasAdManagerReadyAPICaller)caller ad:(id<IasAd> __strong *)adObject extraInfo:(NSDictionary *__autoreleasing *)extraInfo sendTK:(BOOL)send;
- (BOOL)unionReadyForPlacementID:(NSString*)placementID;
- (BOOL)unionReadyForPlacementID:(NSString*)placementID sendTK:(BOOL)send;

#pragma mark - Get Ad
- (id<IasAd>)adHigestPriceWithPosition:(NSInteger)position placementID:(NSString *)placementID;
- (id<IasAd>)adHigestPriceWithPlacementID:(NSString *)placementID;
- (id<IasAd>)adHigestPriceForPlacementID:(NSString*)placementID invalidateStatus:(BOOL)invalidateStatus extra:(NSDictionary*__autoreleasing*)extra atAdInfo:(NSDictionary * _Nullable )atAdInfo;


#pragma mark - auto_refresh
- (void)autoRefreshIsReadyPlacementID:(IasPlacementModel *)placementModel;

#pragma mark - real time TK

+ (NSArray *)getRealTimeNetworkArray;

#pragma mark - send_tracking
- (void)sendEntryScenarioTrackingWithPlacementID:(NSString *)placementID scene:(NSString *)scene isLoading:(BOOL)isLoading isReady:(BOOL)isReady extraInfo: (NSDictionary *)extraInfo;

@end


#endif /* IasAdManager_Internal_h */
