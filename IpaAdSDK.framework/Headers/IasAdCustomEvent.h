//
//  IasAdCustomEvent.h
//  IpaAdSDK
//
//  Created by Leo on 05/07/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IpaAdSDK/IasAd.h>
#import <IpaAdSDK/IasTracker.h>
#import <IpaAdSDK/IasBidInfo.h>
#import <IpaAdSDK/IasAdManager+Internal.h>

@class IasSafeThreadDictionary;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kIasSDKFailedToLoadSplashADMsg;
extern NSString *const kIasSDKFailedToLoadBannerADMsg;
extern NSString *const kIasSDKFailedToLoadInterstitialADMsg;
extern NSString *const kIasSDKFailedToLoadNativeADMsg;
extern NSString *const kIasSDKFailedToLoadRewardedVideoADMsg;
extern NSString *const kIasSDKSplashADTooLongToLoadPlacementSettingMsg;
extern NSString *const kIasSDKImportIssueErrorReason;
extern NSString *const kIasAdAssetsAppIDKey;

extern NSString *const kIasAdCustomEventNotificationKey;

typedef NS_OPTIONS(NSInteger, IasCustomEventType) {
    IasCustomEventLoaded = 0,
    IasCustomEventLoadFail = 1,
    IasCustomEventShow = 2,
    IasCustomEventShowFail = 3,
    IasCustomEventClick = 4,
    IasCustomEventClose = 5,
    IasCustomEventDetailViewWillPresentScreen = 6,
    IasCustomEventCloseBeforeViewAppear = 7, 
};

typedef NS_OPTIONS(NSInteger, IasAdCloseType) {
    IasAdCloseUnknow = 1,            // ad close type unknow
    IasAdCloseSkip = 2,              // ad skip to close
    IasAdCloseCountdown = 3,         // ad countdown to close
    IasAdCloseClickcontent = 4,      // ad clickcontent to close
    IasAdCloseShowfail = 99          // ad showfail to close
};

typedef NS_ENUM(NSInteger, IasADXDeepLinkInstallStatus) {
    IasADXDeepLinkInstallStatusUnknow = 0,
    IasADXDeepLinkInstallStatusYES = 1,
    IasADXDeepLinkInstallStatusNO = 2,
    IasADXDeepLinkInstallStatusElse = 3
};

#define IasAdRequestCallBackMode @"ad_s_reqf_mode"

@interface IasAdCustomEvent : NSObject

@property (atomic, copy) void(^requestCompletionBlock)( NSArray<NSDictionary *> * _Nullable assets,  NSError * _Nullable error);
@property (nonatomic, copy) void (^customEventMetaDataDidLoadedBlock)(void);
@property (nonatomic, readonly) NSMutableArray<NSDictionary *> *assets;
@property (nonatomic, readonly) NSDate *showDate;
@property (nonatomic, readonly) NSString *psIDOnShow;
@property (nonatomic, strong) NSNumber *sdkTime;
@property (nonatomic, strong) NSDictionary *serverInfo;
@property (nonatomic, strong) NSDictionary *localInfo;
@property (nonatomic, strong) NSDate *displaySuccessDate;
@property (nonatomic, strong) NSString *networkUnitId;
@property (nonatomic, strong) NSDictionary *networkCustomInfo;
@property (nonatomic, strong) NSString *networkAdvertisingID;
@property (nonatomic, strong) IasSafeThreadDictionary *networkExtarInfoDic;
@property (nonatomic, strong) IasTrackerInfo *trackerExtraInfo;
@property (nonatomic, assign) IasRequestFiledType requestFiledType;
@property (nonatomic, assign) IasOfferClickAdType clickType;
@property (nonatomic, assign) IasAdCloseType closeType;
@property (nonatomic, assign) NSInteger requestNumber;
/**
 * Failed or successful, a request's considered finished.
 */
@property (nonatomic, assign) NSInteger numberOfFinishedRequests;
@property (nonatomic, assign) BOOL isC2SBiding;
@property (nonatomic, assign) BOOL rewardGranted;
@property (nonatomic, weak) id<IasAd> ad;
@property (nonatomic, weak) id adapter;
@property (nonatomic, weak) id delegate;
@property (nonatomic, strong) id _Nullable protectLifeCycleObject;



- (instancetype)initWithUnitID:(NSString *)unitID serverInfo:(NSDictionary *)serverInfo localInfo:(NSDictionary *)localInfo;
+ (NSDictionary *)serverInfoWithPlacementModel:(IasPlacementModel *)placementModel requestID:(NSString *)requestID unitGroup:(IasUnitGroupModel *)unitGroup;
+ (NSInteger)calculateAdPriority:(id<IasAd>)ad;
- (NSDictionary *)delegateExtra;
- (NSDictionary *)getDelegateExtraWithCaller:(IasAdManagerReadyAPICaller)caller;
- (void)handleAssets:(NSDictionary *)assets;
- (void)handleLoadingFailure:(NSError *)error;
- (void)handleClose;
- (void)handleShow;
- (void)handleShowFailed;
- (void)handleFailToPlayVideoWithError:(NSError *)error extra:(NSDictionary *)extraDic;

- (void)trackClick;
- (void)notifyAdapterShow;
- (NSDictionary *)trackCustomExtraInfo;

- (void)saveShowAPIContext;
- (void)unionTrackAdWithTrackType:(IasADTrackType)trackType extraBlock:(void (^) (IasSafeThreadDictionary *trackingExtra))block;
- (void)unionTrackAdClickWithBlock:(void (^) (IasSafeThreadDictionary *trackingExtra))block;
- (void)unionTrackAdShowWithBlock:(void (^) (IasSafeThreadDictionary *trackingExtra))block;

- (IasADXDeepLinkInstallStatus)getDeepLinkInstallStatus;
- (IasNativeADSourceType)adSourceType;

- (void)getNetworkExtendInfo:(id)networkAd;

@end

NS_ASSUME_NONNULL_END
