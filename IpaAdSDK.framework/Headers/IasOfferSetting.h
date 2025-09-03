//
//  IasOfferSetting.h
//  IpaAdSDK
//
//  Created by Leo on 26/8/2020.
//  Copyright © 2020 IpaAd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IpaAdSDK/IasOfferModel.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kIasOfferTrackerExtraLifeCircleID;
extern NSString *const kIasOfferTrackerExtraScene;
extern NSString *const kIasOfferTrackerGDTClickID;
extern NSString *const kIasOfferTrackerGDTWidth;
extern NSString *const kIasOfferTrackerGDTHeight;
extern NSString *const kIasOfferTrackerGDTDownX;
extern NSString *const kIasOfferTrackerGDTDownY;
extern NSString *const kIasOfferTrackerGDTUpX;
extern NSString *const kIasOfferTrackerGDTUpY;
extern NSString *const kIasOfferTrackerGDTRequestWidth;
extern NSString *const kIasOfferTrackerGDTRequestHeight;
extern NSString *const kIasOfferTrackerRelativeDownX;
extern NSString *const kIasOfferTrackerRelativeDownY;
extern NSString *const kIasOfferTrackerRelativeUpX;
extern NSString *const kIasOfferTrackerRelativeUpY;
extern NSString *const kIasOfferTrackerTimestamp;
extern NSString *const kIasOfferTrackerMilliTimestamp;
extern NSString *const kIasOfferTrackerEndTimestamp;
extern NSString *const kIasOfferTrackerEndMilliTimestamp;
extern NSString *const kIasOfferTrackerVideoTimePlayed;
extern NSString *const kIasOfferTrackerVideoMilliTimePlayed;
extern NSString *const kIasOfferTrackerKYAbsoluteCoord;
extern NSString *const kIasOfferTrackerKYRelativeCoord;
extern NSString *const kIasOfferTrackerDeeplinkType;
extern NSString *const kIasOfferTrackerOPDPType;

typedef NS_ENUM(NSInteger, IasAdShakeAnimationType) {
    IasAdShakeAnimationTypeRock = 1,
    IasAdShakeAnimationTypeJoggle = 2,
    IasAdShakeAnimationTypeShakeShake = 3,
};

typedef NS_ENUM(NSInteger, IasAdSplashCTAType) {
    IasAdSplashCTATypeNormal = 1,
    IasAdSplashCTATypeBottomSemicircle = 2,
};


typedef NS_ENUM(NSInteger, IasOnlyDisplaySendWinType) {
    IasOnlyDisplaySendWinUnknownType = 0,
    IasOnlyDisplaySendWinOnType = 1,
    IasOnlyDisplaySendWinOffType = 2,
};

typedef NS_ENUM(NSInteger, IasRewardPictureAnimateType) {
    IasRewardPictureAnimateUnknownType = 0,
    IasRewardPictureNOAnimateType,
    IasRewardPictureClickAnimateType,
    IasRewardPictureRedPacketAnimateType,
    IasRewardPictureSlideAnimateType,
    IasRewardPictureCardScaleAnimateType,
};

typedef NS_ENUM(NSInteger, IasRewardPictureWebType) {
    IasRewardPictureWebJointType = 1,
    IasRewardPictureWebOtherType,
};

typedef NS_ENUM(NSInteger, IasBannerClickType) {
    IasBannerClickTypeTap = 1,
    IasBannerClickTypeInsideSlideTap,
    IasBannerClickTypeAllClick,
};

typedef NS_ENUM(NSUInteger, IasCtaAnimationType) {
    IasCtaAnimationTypeBreath = 1,// 呼吸
    IasCtaAnimationTypeSway,// 中心点摆动
    IasCtaAnimationTypeStreak,// 斜边划过
    IasCtaAnimationTypeBreathAndStreaks,// 呼吸&划过
    IasCtaAnimationTypeHandClick,// 小手点击
};

typedef NS_ENUM(NSInteger, IasDirectOfferUnitType) {
    IasDirectOfferUnitPictureType = 0,
    IasDirectOfferUnitVideoType = 1,
};

typedef NS_ENUM(NSUInteger, IasVideoPlaySetting) {
    IasVideoPlayAlwaysAutoPlaySetting  = 0,
    IasVideoPlayOnlyWiFiAutoPlaySetting,
    IasVideoPlayClickAutoPlaySetting,
};

typedef NS_ENUM(NSUInteger, IasCTAStyleType) {
    IasCTAStyleTypeBothOne             = 1,  // 主素材和endcard都是单CTA，老样式（默认值）
    IasCTAStyleTypeOnlyMainMaterialOne = 2,  // 主素材是单CTA，endcard是双CTA
    IasCTAStyleTypeOnlyMainMaterialTwo = 3,  // 主素材是双CTA，endcard是单CTA
    IasCTAStyleTypeBothTwo             = 4   // 主素材和endcard都是双CTA
};

typedef NS_ENUM(NSUInteger, IasEndcardStyleType) {
    IasEndcardStyleTypeNormal               = 1,  // 或非1-5的取值，或不含该配置，代表按原有endcard逻辑进行展示
    IasEndcardStyleTypeCountdownGuideMask   = 2,  // 代表在endcard上要展示倒计时引导蒙层
    IasEndcardStyleTypeRedPacket            = 3,  // 代表在endcard上要展示红包样式
    IasEndcardStyleTypeWithdraw             = 4,  // 代表在endcard上要展示双endcard的提现样式
    IasEndcardStyleTypeUniversal            = 5   // 代表在endcard上要展示双endcard的通用挽留页样式
};

typedef NS_ENUM(NSUInteger, IasEndCardRedPacketStyleType) {
    IasEndCardRedPacketStyleTypeOpenDetail  = 1,  // 则进入红包领取页，不会执行广告点击逻辑
    IasEndCardRedPacketStyleTypeDismiss     = 2,  // 则执行广告点击逻辑，进入广告跳转，并将红包隐藏/销毁，显示底部正常endcard
};

typedef NS_ENUM(NSUInteger, IasRedPacketClickableAreaType) {
    IasRedPacketClickableAreaTypeAllNotClickable     = 0,  // 代表红包区域及背景蒙层不可点
    IasRedPacketClickableAreaTypeOnlyMaskClickable   = 1,  // 代表红包区域不可点，点击背景蒙层执行广告点击
    IasRedPacketClickableAreaTypeAllClickable        = 2,  // 代表点击红包区域及背景蒙层执行广告点击
};

typedef NS_ENUM(NSUInteger, IasRedPacketDetailClickableAreaType) {
    IasRedPacketDetailClickableAreaTypeAllNotClickable  = 0,  // 代表领取页其他区域不可点
    IasRedPacketDetailClickableAreaTypeAllClickable     = 1,  // 代表领取页点击其他区域执行广告点击
};

typedef NS_ENUM(NSUInteger, IasWithdrawClickableAreaType) {
    IasWithdrawClickableAreaTypeCardAndButton     = 1,  // 代表卡片及按钮区域点击进入广告跳转，其他区域不可点
    IasWithdrawClickableAreaTypeAllClickable      = 2,  // 代表全屏可点
};

typedef NS_ENUM(NSUInteger, IasSecondEndcardClickableAreaType) {
    IasSecondEndcardClickableAreaTypeOnlyCTA       = 1,  // 代表仅挽留页卡片CTA可点
    IasSecondEndcardClickableAreaTypeOnlyEndcard   = 2,  // 代表整个挽留页卡片可点
    IasSecondEndcardClickableAreaTypeExceptClose   = 3,  // 代表全屏可点，除了关闭按钮
    IasSecondEndcardClickableAreaTypeAllClickable  = 4,  // 代表全屏可点，以及首次关闭按钮可点
};

typedef NS_ENUM(NSUInteger, IasOfferMediaViewExpressType) {
    IasOfferMediaViewExpressTypeLeftImage = 1,
    IasOfferMediaViewExpressTypeLeftText,
    IasOfferMediaViewExpressTypeAboveImage,
    IasOfferMediaViewExpressTypeAboveText,
    IasOfferMediaViewExpressTypeTextFloating,
    IasOfferMediaViewExpressTypeDefault,
};

typedef NS_ENUM(NSUInteger, IasShakeTriggerModeType) {
    IasShakeTriggerModeTypeMultiDirectional     = 1,  // 多向来回判断
    IasShakeTriggerModeTypeUnidirectional       = 2,  // 单向判断
};

typedef NS_ENUM(NSUInteger, IasCloseButtonStyleType) {
    IasCloseButtonStyleTypeUnavailable     = 1,  // 不生效次级按钮样式
    IasCloseButtonStyleTypeActive          = 2,  // 生效次级按钮样式
};

typedef NS_ENUM(NSUInteger, IasMaterialLayoutType) {
    IasMaterialLayoutTypeFullScreenMainMaterial,          // 全屏主素材
    IasMaterialLayoutTypeHalfScreenMainMaterial,          // 半屏主素材
    IasMaterialLayoutTypeHalfScreenMainMaterialOnlyCTA,   // 半屏主素材仅显示CTA
    IasMaterialLayoutTypeEndCard,                         // endcard素材
    IasMaterialLayoutTypeSplashMaterial,                  // 开屏素材
};

typedef NS_ENUM(NSUInteger, IasCTAButtonLayoutType) {
    IasCTAButtonLayoutTypeOneCTA,             // 单CTA
    IasCTAButtonLayoutTypeDoubleCTA,          // 双CTA
    IasCTAButtonLayoutTypeWithCloseButton,    // 一个CTA一个关闭按钮
    IasCTAButtonLayoutTypeBottomSemicircle,    // 开屏底部半圆CTA
};

typedef NS_ENUM(NSUInteger, IasVideoCountdownStyle) {
    IasVideoCountdownStyleNumerical       = 1, // 仅展示数字倒计时
    IasVideoCountdownStyleProgressBar     = 2, // 仅展示播放进度条
    IasVideoCountdownStyleNeitherShow     = 3, // 数字倒计时和播放进度条均不展示
    IasVideoCountdownStyleBothShow        = 4  // 数字倒计时和播放进度条都展示
};

typedef NS_ENUM(NSUInteger, IasInterstitialTemplateType) {
    IasInterstitialTemplateTypeHalfScreen            = 1, // 半屏插屏
    IasInterstitialTemplateTypeFullScreen            = 2, // 全屏插屏
    IasInterstitialTemplateTypeHalfScreenEnvelope    = 3, // 半屏信封插屏
    IasInterstitialTemplateTypeFullScreenEnvelope    = 4  // 全屏信封插屏
};
/// 广告位活动氛围样式
typedef NS_ENUM(NSUInteger, IasEventsAtmosphereType) {
    IasEventsAtmosphereTypeNone            = 1, // 无
    IasEventsAtmosphereTypeBubbleDrop            = 2, // 气泡掉落（开屏、插屏)
    IasEventsAtmosphereTypeECAmbience    = 3, //  异形电商氛围（插屏半屏）
};

/// 开屏拼接推荐
typedef NS_ENUM(NSUInteger, IasSplashSpliceType) {
    IasSplashSpliceTypeNone            = 1, // 无
    IasSplashSpliceTypeHotRecommend           = 2, // 热门推荐
};

@class IasOfferModel,IasGuideClickOverlayItem,IasRVIncentiveTaskConfig;
@interface IasOfferSetting : IasModel

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, strong) NSString *placementID;
//setting for banner
@property (nonatomic, strong) NSString *bannerSize;
@property (nonatomic, assign) NSTimeInterval resourceDownloadTimeout;
@property (nonatomic, assign) NSTimeInterval bannerAppearanceInterval;
@property (nonatomic, assign) NSTimeInterval bannerDisapearInterval;
@property (nonatomic, assign) NSTimeInterval closeButtonAppearanceInterval;
@property (nonatomic, assign) IasAdFormat format;
@property (nonatomic, assign) IasVideoClickable videoClickable;
@property (nonatomic, assign) IasEndCardClickable endCardClickable;
@property (nonatomic, assign) IasLoadStorekitTime storekitTime;
@property (nonatomic, assign) IasOfferLayoutType layoutType;
@property (nonatomic, assign) IasClickMode clickMode;
@property (nonatomic, assign) IasLoadType loadType;
@property (nonatomic, assign) IasUserAgentType impressionUAType;
@property (nonatomic, assign) IasUserAgentType clickUAType;
@property (nonatomic, assign) IasDeepLinkClickMode deeplinkClickMoment;
@property (nonatomic, assign) IasSplashType splashType;
@property (nonatomic, assign) IasSplashImageScaleType splashImageScaleType;
@property (nonatomic, assign) IasAdShakeAnimationType adShakeAnimationType;
@property (nonatomic, assign) NSInteger lastOfferidsNum;
@property (nonatomic, assign) NSInteger splashCountDownTime;
@property (nonatomic, assign) NSInteger splashOrientation;
/// The minimum value of the close button delayed display
@property (nonatomic, assign) NSInteger closeBtnDelayMinTime;
/// The maximum value of the close button delayed display
@property (nonatomic, assign) NSInteger closeBtnDelayMaxTime;
@property (nonatomic, assign) NSInteger closeBtnDelayRate;
@property (nonatomic, assign) NSInteger onRewardTime;
@property (nonatomic, assign) CGFloat closeBtnNoFirstClickArea;
@property (nonatomic, assign) CGFloat closeBtnFirstClickArea;
@property (nonatomic, assign) CGFloat closeBtnNoFirstClickAreaScal;
@property (nonatomic, assign) CGFloat closeBtnFirstClickAreaScal;
@property (nonatomic, assign) BOOL unMute;
@property (nonatomic, assign) BOOL skipable;
@property (nonatomic, assign) BOOL showBannerCloseBtn;
@property (nonatomic, assign) BOOL isGuideClick;
@property (nonatomic, assign) BOOL rewardWhenFailed;
@property (nonatomic, assign) BOOL showEndCard;
// Whether to enable the shake function. 1 means open, 2 means not open
@property (nonatomic, assign) BOOL splashShakeSw;
// The minimum value of the gyroscope that can trigger a shake click. Default is 0.1
@property (nonatomic, assign) CGFloat shakeStrength;
// Shake the time interval that a tap can trigger again. The default is 5s
@property (nonatomic, assign) NSInteger shakeTime;
@property (nonatomic, assign) NSTimeInterval clickCacheTime;
@property (nonatomic, assign) BOOL clickNotice;
//6.1.32https://confluence.magicgame001.com/pages/viewpage.action?pageId=47126246
@property (nonatomic, assign) BOOL overlaySwitch;
@property (nonatomic, assign) NSTimeInterval overlayDuration;
@property (nonatomic, assign) NSTimeInterval overlayShowTime;
@property (nonatomic, assign) BOOL overlayUserDismissible;
@property (nonatomic, assign) BOOL storeKitSwitch;
@property (nonatomic, assign) NSTimeInterval monitoringShowTime;
///是否预加载Mraid素材，yes是预加载，no是不预加载
@property (nonatomic, assign) BOOL mraidPreLoadSwitch;
/// 是否失败重发networkTK
@property (nonatomic, assign) BOOL retryNetworkTkSwitch;
/// 仅在展示时发送Win
@property (nonatomic, assign) IasOnlyDisplaySendWinType onlyDisplaySendWinType;
/// 自动点击 6.2.2_5
@property (nonatomic, assign) BOOL isAutoClickImage;
@property (nonatomic, assign) NSTimeInterval autoClickImageTipDuration;
@property (nonatomic, assign) NSTimeInterval autoClickImageTriggerDuration;
@property (nonatomic, assign) BOOL isAutoClickVideo;
@property (nonatomic, assign) NSTimeInterval autoClickVideoTipDuration;
@property (nonatomic, assign) NSTimeInterval autoClickVideoTriggerDuration;
@property (nonatomic, assign) BOOL isAutoClickEndCard;
@property (nonatomic, assign) NSTimeInterval autoClickEndCardTipDuration;
@property (nonatomic, assign) NSTimeInterval autoClickEndCardTriggerDuration;
@property (nonatomic, assign) IasRewardPictureAnimateType rewardPictureAnimateType;
@property (nonatomic, assign) NSTimeInterval rewardPictureOnRewardDuration;
@property (nonatomic, assign) IasRewardPictureWebType rewardPictureWebType;
@property (nonatomic, assign) IasBannerClickType bannerTriggerClickType;
@property (nonatomic, assign) IasAdOfferInterType interType;
@property (nonatomic, assign) IasDirectOfferUnitType unitType;
@property (nonatomic, assign) IasOfferMediaViewExpressType expressType;
// click guide animation Switch
@property (nonatomic, assign) BOOL guideClickOverlaySwitch;
// click guide animation list
@property (nonatomic, strong) NSArray<IasGuideClickOverlayItem *> *overlayItemArray;
// Q&A pop-up option answer
@property (nonatomic, strong) NSString *qaAnswerText;
// The probability of an invalid close button
@property (nonatomic, assign) BOOL closeButtonInvalidSwitch;
@property (nonatomic, assign) BOOL enableInterstitialStyleEnvelope;
@property (nonatomic, assign) BOOL isImpressionInterstitialStyleEnvelope;
/// 摇一摇图标外面的文案
@property (nonatomic, strong) NSString *shakeText;
/// 摇一摇图标里面的文案
@property (nonatomic, strong) NSString *shakeInternalText;
/// 摇一摇缩小后文案
@property (nonatomic, strong) NSString *shakeSmallText;
/// 摇一摇图片URL字符串
@property (nonatomic, strong) NSString *shakeImageURLString;
@property (nonatomic, assign) BOOL isShowDetentionPage;
/// 开屏结束弹窗倒计时 当下发为0的时，全屏开屏结束后不展示弹窗
@property (nonatomic, assign) NSTimeInterval splashPopTime;
/// 视频播放N秒后出现Banner(顶部)
@property (nonatomic, assign) NSTimeInterval topBannerStartTime;
/// Banner弹出播放时长(顶部)
@property (nonatomic, assign) NSTimeInterval topBannerShowTime;
/// 开屏 控制广告点击跳转后，是否销毁广告
@property (nonatomic, assign) BOOL isClickCloseAd;
/// 开屏倒计时结束后， 视频是否继续播放 1-是,2-否, 默认：2 
@property (nonatomic, assign) BOOL countDownPlaySwitch;
// offer 维度 readyRate
@property (nonatomic, assign) NSInteger readyRate;
///表示video下载到ready rate后是否继续下载，1或不下发表示继续下载，2表示暂停下载。默认不下发
@property (nonatomic, assign) NSInteger videoContinueType;
///表示视频展示后，观看到多少比例开始继续下载（针对边下边播场景）。默认0或不下发表示开始播放就开始下载。
@property (nonatomic, assign) NSInteger cdRate;
// 1:部分下载；2:下载剩余全部
@property (nonatomic, assign) NSInteger particalDownloadState;
/// CTA按钮动画效果
@property (nonatomic, assign) IasCtaAnimationType ctaAnimationType;
/// CTA按钮样式
@property (nonatomic, assign) IasCTAStyleType ctaStyleType;
/// CTA 左按钮文案
@property (nonatomic, strong) NSString *ctaLeftButtonText;
/// EndCard样式
@property (nonatomic, assign) IasEndcardStyleType endcardStyleType;
/// EndCard新样式倒计时，若 >0，则展示倒计时， 若 <0，不展示倒计时及关闭按钮区域，但按绝对值进行倒计时；当 =0，不进行倒计时，直接展示假关闭按钮
@property (nonatomic, assign) NSTimeInterval endcardCountdownNew;
/// EndCard红包样式交互
@property (nonatomic, assign) IasEndCardRedPacketStyleType endCardRedPacketStyleType;
/// EndCard红包样式可点区域
@property (nonatomic, assign) IasRedPacketClickableAreaType redPacketClickableAreaType;
/// EndCard红包样式详情页可点区域
@property (nonatomic, assign) IasRedPacketDetailClickableAreaType redPacketDetailClickableAreaType;
/// EndCard红包样式可点区域策略原始值，两位数数值
@property (nonatomic, assign) NSInteger redPacketClickableAreaOriginalValue;
/// 红包标题
@property (nonatomic, strong) NSString *redTitleText;
/// 红包祝福语
@property (nonatomic, strong) NSString *redBlessingsText;
/// 免责声明链接
@property (nonatomic, strong) NSString *disclaimerUrl;
/// 领取提醒
@property (nonatomic, strong) NSString *redReceiveNoticeText;
/// 领取按钮文案
@property (nonatomic, strong) NSString *redReceiveButtonText;
/// EndCard提现样式可点区域
@property (nonatomic, assign) IasWithdrawClickableAreaType withdrawClickableAreaType;
/// EndCard通用挽留页倒计时，若 >0，则展示倒计时。 若 <0，不展示倒计时及关闭按钮区域，但按绝对值进行倒计时；当 =0，不进行倒计时，直接展示假关闭按钮
@property (nonatomic, assign) NSTimeInterval secondEndcardCountdown;
/// EndCard通用挽留页可点区域
@property (nonatomic, assign) IasSecondEndcardClickableAreaType secondEndcardClickableAreaType;
/// 提现样式视频素材
@property (nonatomic, strong) NSString *withdrawVideoUrl;
/// 提现样式icon素材
@property (nonatomic, strong) NSString *withdrawIconUrl;
/// 提现样式挽留卡片标题
@property (nonatomic, strong) NSString *withdrawTitleText;
/// 提现样式挽留卡片素材
@property (nonatomic, strong) NSString *withdrawImageUrl;
/// 提现样式挽留卡片按钮文案
@property (nonatomic, strong) NSString *withdrawButtonText;
/// 原生视频自动播放设置，目前仅adx支持配置
@property (nonatomic, assign) IasVideoPlaySetting videoPlaySetting;
/// 触发摇一摇的方案 1：多向来回判断，2：单向判断，默认为1
@property (nonatomic, assign) IasShakeTriggerModeType shakeTriggerModeType;
/// 摇一摇监测时间 整数形式，单位毫秒
@property (nonatomic, assign) NSInteger shakeMonitorTime;
/// 摇一摇加速度设置-触发阈值  小数形式数组 例如[16.5, 15, 10]
@property (nonatomic, strong) NSArray<NSNumber *> *shakeTriggerThresholdArray;
/// 关闭按钮-次级按钮样式（激励视频、插屏下的图片和视频素材，SDK Version 6.3.70 及以上支持） ，默认值为 1
@property (nonatomic, assign) IasCloseButtonStyleType closeButtonStyleType;
/// 关闭按钮-次级按钮文案
@property (nonatomic, strong) NSString *closeButtonStyleText;
/// 视频广告倒计时的样式展示规则，默认值为：1
@property (nonatomic, assign) IasVideoCountdownStyle videoCountdownStyle;
/// 激励视频领取奖励倒计时,单位秒
@property (nonatomic, assign) NSInteger rvRewardTipCountdown;
/// 是否对html广告做自动点击拦截，=1或没有该字段或该字段没有值，则需要对html渲染的广告做屏蔽； =2，不做拦截屏蔽。
@property (nonatomic, assign) NSInteger filterAutoClick;
/// 激励任务类型
@property (nonatomic, assign) IasRVTncentiveTaskType rvIncentiveTaskType;
/// 播放 N 秒展示
@property (nonatomic, assign) NSInteger rvIncentiveTaskDisplayTiming;
/// 减少/跳过时长(秒)
@property (nonatomic, assign) NSInteger rvIncentiveTaskReduceOrFreeTime;
/// 浮层持续时间(秒)
@property (nonatomic, assign) NSInteger rvIncentiveTaskHoldingTime;
/// 广告位活动氛围样式
@property (nonatomic, assign) IasEventsAtmosphereType eventsAtmosphereType;
/// 开屏拼接推荐氛围样式
@property (nonatomic, assign) IasSplashSpliceType splashSpliceType;
/// 开屏底部CTA样式
@property (nonatomic, assign) IasAdSplashCTAType splashCTAType;

- (CGFloat)getClickArea:(NSInteger)sizeType;
- (CGFloat)getClickAreaScal:(NSInteger)sizeType;
/// CTA按钮渲染类型，根据ctaStyleType和closeButtonStyleType来控制
- (IasCTAButtonLayoutType)getCTAButtonLayoutType:(IasMaterialLayoutType)materialLayoutType offerModel:(IasOfferModel *)offerModel;
- (BOOL)isExistRewardPictureAnimate;
- (IasInterstitialTemplateType)getInterstitialTemplateType;

@end

NS_ASSUME_NONNULL_END
