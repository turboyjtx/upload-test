//
//  IasTrackerInfo.h
//  IpaAdSDK
//
//  Created by GUO PENG on 2023/5/6.
//  Copyright © 2023 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasModel.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, IasClickAreaType) {
    IasClickAreaNOEndCardCTAType                = 1,
    IasClickAreaNOEndCardCTAExistClickBanner    = 2,
    IasClickAreaNOEndCardBannerOutSideType      = 3,
    IasClickAreaNOEndCardAutoClickType          = 4,
    IasClickAreaNOEndCardShakeType              = 5,
    IasClickAreaEndCardCTAType                  = 6,
    IasClickAreaEndCardCTAOutSideType           = 7,
    IasClickAreaEndCardAutoClickType            = 8,
    IasClickAreaEndCardShakeType                = 9,
    IasClickAreaSkoverlyType                    = 10,
    IasClickAreaShakeBtnType                    = 11,
    IasClickAreaGuideType                       = 12,
    IasClickAreaInsensibilityType               = 13,
    IasClickAreaInvalidCloseButtonType          = 14,
    IasClickAreaOverlayTypeGestureGuidance      = 15,
    IasClickAreaOverlayTypeDragPuzzle           = 16,
    IasClickAreaOverlayTypeQAPopup              = 17,
    IasClickAreaOverlayTypeNoviceGuide          = 18,
    IasClickAreaOverlayTypeConfirmJump          = 19,
    IasClickAreaOverlayTypeFingerClickGuide     = 20,
    IasClickAreaOverlayTypeFullScreenSwipe      = 21,
    IasClickAreaSplashEndPop                    = 22,
    IasClickAreaVideoTopBanner                  = 23,
    IasClickAreaNOEndCardLeftButtonOfCTA        = 24,
    IasClickAreaNOEndCardRightButtonOfCTA       = 25,
    IasClickAreaCountdownGuideMask              = 26,
    IasClickAreaRedPacketOpenButton             = 27,
    IasClickAreaRedPacketViewArea               = 28,
    IasClickAreaRedPacketMaskArea               = 29,
    IasClickAreaRedPacketDetailReceiveButton    = 30,
    IasClickAreaRedPacketDetailReceiveOutside   = 31,
    IasClickAreaWithdrawVideoView               = 32,
    IasClickAreaWithdrawCardViewArea            = 33,
    IasClickAreaWithdrawButton                  = 34,
    IasClickAreaWithdrawBackGroundArea          = 35,
    IasClickAreaRetentionViewCTA                = 36,
    IasClickAreaRetentionViewCardArea           = 37,
    IasClickAreaRetentionViewBackGroundArea     = 38,
    IasClickAreaRetentionViewCloseButton        = 39,
    IasClickAreaEndCardLeftButtonOfCTA          = 40,
    IasClickAreaEndCardRightButtonOfCTA         = 41,
    IasClickAreaRVIncentiveTaskADFree           = 42,
    IasClickAreaOverlayTypeLuckybag             = 43,
    IasClickAreaOverlayTypeChopOnce             = 44,
    IasClickAreaOverlayTypeSlidePuzzle          = 45,
    IasClickAreaOverlayTypeGestureSlide         = 46,
    IasClickAreaOverlayTypeGesureClick          = 47,
    IasClickAreaOverlayTypeBigWhiteHand         = 48,
    IasClickAreaTypeBubbleDrop                  = 49,
};

typedef NS_ENUM(NSInteger, IasRenderVideoType) {
    IasRenderVideoTypeUnknow = 0,
    IasRenderVideoTypeNormal = 1,
    IasRenderVideoTypeNoVideoEndcard = 2,
    IasRenderVideoTypeNoVideoLayerEndcard = 3,
    IasRenderVideoTypeNoVideoRedPacketEndcard = 4,
    IasRenderVideoTypeNoVideoSlideEndcard = 5,
    IasRenderVideoTypeNoVideoCardScaleEndcard = 6,
    IasRenderVideoTypeNoVideoWebView = 7,
    IasRenderVideoTypeNoVideoNoMaterialEndcard = 8,
    IasRenderVideoTypeMTG = 9,
};

typedef NS_ENUM(NSInteger, IasNativeADSourceType) {
    IasNativeADSourceTypeUnknown = 0,
    IasNativeADSourceTypeVideo = 1,
    IasNativeADSourceTypeImage = 2
};

// 比价工具TK上报
// string  unit_id     当前IpaAd SDK缓存价格最高的广告源id
// string  bidprice    当前IpaAd SDK缓存价格最高的广告源对应的价格
// string 竞胜：第二名(竞败方)的ilrd原始数据，   竞败：竞胜方的ilrd原始数据
extern NSString *const kIasTrackerExtraMmbIlrdKey;
// 竞胜
extern NSString *const kIasTrackerExtraMmbSecPriceKey;  // double 第二名(竞败方)的价格，单位美元
extern NSString *const kIasTrackerExtraMmbSecBidderKey; // string 第二名(竞败方)的名字，max或is上获取到什么就传什么，如max、IpaAd、IpaAd adx、ironsource等
// 竞败
extern NSString *const kIasTrackerExtraMmbFirstPriceKey;  // double 竞胜方（第一名）的价格
extern NSString *const kIasTrackerExtraMmbFirstBidderKey; // string 竞胜方（第一名）的名字，max或is上获取到什么就传什么，如max、IpaAd、IpaAd adx、ironsource等
extern NSString *const kIasTrackerExtraMmbLossReasonKey;  // int 竞败原因 1. 价格过低 2. 超时 3. 其他（待sdk补充）
// string 下一次 bid 上传
extern NSString *const kIasTrackerExtraMmbWaterfallInfoKey;

@interface IasTrackerInfo : NSObject

@property (nonatomic, assign) IasClickAreaType clickAreaType;
// only RewardedVideo use
@property (nonatomic, assign) IasRenderVideoType renderVideoType;

@end

NS_ASSUME_NONNULL_END
