//
//  IasAppSettingManager.h
//  IpaAdSDK
//
//  Created by Leo on 09/04/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasAPI+Internal.h>
#import <IpaAdSDK/IasModel.h>


NS_ASSUME_NONNULL_BEGIN
//The keyed value stores the flag as to whether or not clients are expected to upload the offer metadata
extern NSString *const kIasAppSettingGDPAFlag;
extern NSString *const kIasAppSettingGDPRPolicyURLKey;
extern NSString *const kIasSDKCustomChannel;

extern NSString *const kIasGeoLongitudeKey;
extern NSString *const kIasGeoDimensionKey;

@class IasTrackingSetting;
@class IasADXSetting;
@class IasOnlineApiSetting;
@class IasPlacementModel;
@class IasSharePlacementSetting;
@class IasSharePlacementItem;

@interface IasAppSettingManager : NSObject

+(instancetype)sharedManager;

- (void)checkShareAdPlacementSetting;

- (void)setPropertyValue;

/**
 * The following setting accessing methods are thread-safe.
 */
- (BOOL)currentSettingExpired;
- (NSTimeInterval)splashTolerateTimeout;
- (BOOL)usesServerDataConsentSet;
- (BOOL)complyWithCOPPA;
- (BOOL)complyWithCCPA;
- (NSTimeInterval)psIDInterval;
- (NSTimeInterval)psIDIntervalForHotLaunch;
- (IasDataConsentSet)serverDataConsentSet;
- (IasDataConsentSet)commonTkDataConsentSet;
- (NSUInteger)myOfferMaxResourceLength;
- (NSArray *)preinitInfoArr;
- (NSDictionary *)userValueDQLWithPlacement:(IasPlacementModel *)placementId;

@property(nonatomic, strong) NSDictionary *currentSetting;

@property(nonatomic, readonly) NSDictionary *defaultSetting;

@property(nonatomic, readonly) IasTrackingSetting *trackingSetting;

@property(nonatomic, readonly) IasADXSetting *adxSetting;

@property(nonatomic, readonly) IasOnlineApiSetting *onlineApiSetting;

@property(nonatomic, readonly) NSString *ABTestID;

@property(nonatomic, readonly) NSString *s2sAddress;
@property(nonatomic, readonly) BOOL needToReportCrash;

@property(nonatomic, assign,getter=isAdmobMediationStatus) BOOL admobMediationStatus;

@property (nonatomic, strong) NSDictionary *appListDic;

@property(atomic,strong) IasSharePlacementSetting *sharePlacementSetting_impl;

/*
 *up id
 */
@property(nonatomic, readonly) NSString* IasID;
/**
 * sysid
 */
@property(nonatomic, readonly) NSString* SYSID;
/**
 * bkupid
 */
@property(nonatomic, readonly) NSString* BKUPID;
/// 是否允许adx原生自渲染提供图片宽高获取能力(sdk6.2.94) 1：允许，2：不允许，默认为2
@property (nonatomic, assign) BOOL isPermitAdGetImagWH;

@property(nonatomic, readonly) NSString *clickNotificationName;
@property(nonatomic, readonly) NSString *showNotificationName;
// 6.1.10
@property (nonatomic, strong) NSString *showDelayUrl;
@property (nonatomic, strong) NSString *showDelayText;

@property (nonatomic, readonly) NSDictionary *requestFailIntervalRuleDic;

@property (nonatomic, strong) NSDictionary *appSettingABDic;

@property (nonatomic, strong) NSDictionary *cachedDic;
@property (nonatomic, strong) NSDictionary *updateCachedDic;

@property (nonatomic, strong) NSArray *guidedClickFodderArray;
@property (nonatomic, strong) NSArray *redPacketFodderArray;
@property (nonatomic, strong) NSArray *cardFodderArray;

@property (nonatomic, strong) NSArray <UIImage *>*cardImageFodderArray;

@property (nonatomic, strong) NSArray *allAnimationFodderArray;

- (NSString *)wxAppOpenid;
- (NSString *)wxOpenUniversallink;

//+(NSDictionary*)parameters;

- (nullable NSArray *)cardImageFodder;
@end



@interface IasTrackingSetting:IasModel
+(instancetype) defaultSetting;
@property(nonatomic, readonly) NSString *trackerAddress;
@property(nonatomic, readonly) NSInteger trackerNumberThreadhold;
@property(nonatomic, readonly) NSTimeInterval trackerInterval;
@property(nonatomic, readonly) BOOL sendsDataEveryInterval;
@property(nonatomic, readonly) NSString *agentEventAddress;
@property(nonatomic, readonly) NSInteger agentEventNumberThreadhold;
@property(nonatomic, readonly) NSTimeInterval agentEventInterval;
@property(nonatomic, readonly) NSArray<NSString*>* agentEventDropNetworks;
@property(nonatomic, readonly) NSDictionary<NSString*, NSArray<NSString*>*>* agentEventDropFormats;
@property(nonatomic, readonly) NSDictionary<NSString*, NSArray<NSString*>*>* agentEventRTFormats;

@property(nonatomic, readonly) NSDictionary<NSString*, NSDictionary*>* trackRealTimeFormatDic;
@property(nonatomic, readonly) NSDictionary<NSString*, NSDictionary*>* agentRealTimeFormatDic;



/*
 *for batch upload
 */
@property(nonatomic, readonly) NSInteger agentEventBatNumberThreadhold;
@property(nonatomic, readonly) NSInteger agentEventBatInterval;


//TCP
@property(nonatomic, readonly) NSString *trackerTCPAddress;
@property(nonatomic, readonly) NSInteger trackerTCPPort;
@property(nonatomic, readonly) NSInteger trackerTCPType;
@property(nonatomic, readonly) NSString *trackerTCPRate;

//TC
@property(nonatomic, readonly) NSArray<NSString*>* tcHosts;
@property(nonatomic, readonly) NSDictionary<NSString*, NSArray<NSString*>*>* tcTKSkipFormats;
@property(nonatomic, readonly) NSArray<NSString*>* tcTKSkipNetworks;



@end

@interface IasADXSetting:IasModel
+(instancetype) defaultSetting;
@property(nonatomic, readonly) NSString *reqHttpAddress;
@property(nonatomic, readonly) NSString *reqTCPAdress;

@property(nonatomic, readonly) NSInteger reqTCPPort;
@property(nonatomic, readonly) NSInteger reqNetType;

@property(nonatomic, readonly) NSString *bidHttpAddress;
@property(nonatomic, readonly) NSString *bidTCPAdress;
@property(nonatomic, readonly) NSInteger bidTCPPort;
@property(nonatomic, readonly) NSInteger bidNetType;

@property(nonatomic, readonly) NSString *trackerHttpAdress;
@property(nonatomic, readonly) NSString *trackerTCPAdress;
@property(nonatomic, readonly) NSInteger trackerTCPPort;
@property(nonatomic, readonly) NSInteger trackerNetType;

@end

@interface IasOnlineApiSetting:IasModel
+(instancetype) defaultSetting;
@property(nonatomic, readonly) NSString *reqHttpAddress;

@property(nonatomic, readonly) NSString *reqTCPAdress;
@property(nonatomic, readonly) NSInteger reqTCPPort;
@property(nonatomic, readonly) NSInteger reqNetType;

@property(nonatomic, readonly) NSString *trackerHttpAdress;
@property(nonatomic, readonly) NSString *trackerTCPAdress;
@property(nonatomic, readonly) NSInteger trackerTCPPort;
@property(nonatomic, readonly) NSInteger trackerNetType;

@end

#pragma mark - IasSharePlacementSetting
@interface IasSharePlacementItem : IasModel

@property (nonatomic, strong) NSString *placementId;
@property (nonatomic, assign) IasAdFormat format;
@property (nonatomic, assign) NSTimeInterval timingLoadInterval;
@property (nonatomic, assign) NSInteger cacheNumberThreshold;
@property (nonatomic, strong) NSString *ecpmThreshold;

@end

#pragma mark - IasSharePlacementSetting

typedef NS_ENUM(NSUInteger, IasSharePlacementSettingPreLoadType) {
    IasSharePlacementSettingPreLoadTypeStart = 1,
    IasSharePlacementSettingPreLoadTypeBinding,
};

@interface IasSharePlacementSetting : IasModel
+ (instancetype)defaultSetting;
@property (nonatomic, assign) NSTimeInterval loadInterval;
@property (nonatomic, assign) NSInteger loadNubmer;
@property (nonatomic, assign) NSTimeInterval shortTimeOutInterval;

@property (nonatomic, strong) NSMutableDictionary<NSString *, IasSharePlacementItem *> *itemDict;
@property (nonatomic, strong) NSMutableArray<IasSharePlacementItem *> *sharePlacementList;

@property (nonatomic, assign) IasSharePlacementSettingPreLoadType preLoadType;

@end
NS_ASSUME_NONNULL_END
