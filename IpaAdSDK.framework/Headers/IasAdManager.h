//
//  IasAdManager.h
//  IpaAdSDK
//
//  Created by Leo on 04/05/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <IpaAdSDK/IasUnitGroupModel.h>
#import <IpaAdSDK/IasADXFloorPrice.h>
#import <IpaAdSDK/IasAdLoadingDelegate.h>

NS_ASSUME_NONNULL_BEGIN

//TODO ZSR 这个类是否存在一些无用的代码？？

extern NSString *const kIasAdAssetsNativeCustomEventKey;
extern NSString *const kIasAdAssetsCustomEventKey;
extern NSString *const kIasAdAssetsCustomObjectKey;
extern NSString *const kIasExtraInfoRootViewControllerKey;
extern NSString *const kIasAdAssetsDelegateObjKey;
extern NSString *const kIasAdAssetsCustomNativeAdKey;
extern NSString *const kIasAdAssetsCustomShowVcKey;

extern NSString *const kIasAdLoadingExtraMediaExtraKey;
extern NSString *const kIasAdLoadingExtraNetworkPlacementIDKey;
extern NSString *const kIasAdLoadingExtraAdmobContentURLStringsKey;

/*
 * Banner's ad size, the value is a NSValue wrapped CGSize; for banner ad loading,
 * we only support (320.0f, 50.0f) now, so the value you pass via this key will be ignored.
 */
extern NSString *const kIasExtraInfoAdSizeKey;
extern NSString *const kIasAdLoadingExtraGDTEnableDefaultAudioSessionKey;

typedef BOOL(^AdSourceCustomizeFillterBlock)(NSDictionary *extra);

@protocol IasAdLoadingDelegate;

@interface IasAdManager : NSObject

@property (nonatomic,strong) NSDictionary *extra;
@property (nonatomic,strong) NSMutableDictionary *exludeUnitIDDic;
@property (nonatomic,strong) NSMutableDictionary *exludeNetworkFirmIDDic;
@property (nonatomic,strong) NSMutableDictionary *showingUnitIdDic;

@property(nonatomic, copy) AdSourceCustomizeFillterBlock adSourceCustomizeFillter;

/// singleton object
+ (instancetype)sharedManager;

/// Called when load ad
/// @param placementID - IpaAd's ad placement id
/// @param extra - Local configuration parameter
/// @param delegate - delegate object
- (void)loadAd:(NSString *)placementID
                        extra:(NSDictionary *)extra
                     delegate:(id<IasAdLoadingDelegate>)delegate;

- (void)loadAd:(NSString *)placementID
                        extra:(NSDictionary *)extra
                      tkExtra:(nullable NSDictionary *)tkExtra
                adxFloorPrice:(nullable IasADXFloorPrice *)adxFloorPrice
                     delegate:(id<IasAdLoadingDelegate>)delegate;

//TODO ZSR 这种过滤的逻辑是不是可以记录到FilterService里面
- (void)setExludePlacementid:(NSString *)placementid
                 unitIDArray:(NSArray <NSString *> *)unitIDArray;

- (void)setMultipleLoadingDelegate:(id<IasAdMultipleLoadingDelegate>)delegate placementId:(NSString *)placementId;



//TODO ZSR 这种过滤的逻辑是不是可以记录到FilterService里面
/// Set the network that needs to be excluded when loading an placement, will take effect on the next load
/// @param placementid  - IpaAd's ad placement id
/// @param networkFirmIDArray - need to be excluded networkFirmIds
///
- (void)setExludePlacementid:(NSString *)placementid
          networkFirmIDArray:(NSArray <NSNumber *> *)networkFirmIDArray;

- (NSDictionary *)extraInfoForPlacementID:(NSString*)placementID
                                requestID:(NSString*)requestID;

//TODO ZSR 这种过滤的逻辑是不是可以记录到FilterService里面
- (void)setAdSourceCustomizeFillterPlacementIDArray:(NSArray <NSString *> *)placementIDArray;

- (void)entryAdScenarioWithPlacementID:(NSString *)placementID scenarioID:(NSString *)scenarioID;
- (NSArray<NSDictionary *> *)getAdValidAdsForPlacementID:(NSString *)placementID;


/// Notify us after custom close ad only
/// @param placementID  - IpaAd's ad placement id
- (void)customCloseADEventWithPlacementID:(NSString *)placementID;


// 比价工具, 竞胜竞败接口 TODO ZSR 待优化
+ (void)trackWinWithPlacementID:(nonnull NSString *)placementID extra:(nullable NSDictionary*)extra;
+ (void)trackLossWithPlacementID:(nonnull NSString *)placementID extra:(nullable NSDictionary*)extra;

@end

NS_ASSUME_NONNULL_END
