//
//  IasOfferModel.h
//  IpaAdSDK
//
//  Created by Leo on 21/8/2020.
//  Copyright © 2020 IpaAd. All rights reserved.
//

#import <IpaAdSDK/IasModel.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

extern NSString *const kIasOfferBannerSize320_50;
extern NSString *const kIasOfferBannerSize320_90;
extern NSString *const kIasOfferBannerSize300_250;
extern NSString *const kIasOfferBannerSize728_90;

@interface IasVideoPlayingTKItem : NSObject

@property (nonatomic, copy) NSArray<NSString *> *urls;
@property (nonatomic) NSInteger triggerTime;
@property (nonatomic) BOOL sent;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end

#define IasADCTATAG 10000
#define IasADTEXTTAG 10001
#define IasADTITLETAG 10002
#define IasADICONTAG 10003
#define IasADSHAKETAG 10004
#define IasADWEBTAG 10005
#define IasADCTABACKTAG 10006
#define IasADMAINIMAGETAG 10007
#define IasADMEDIAVIEWTAG 10008
#define IasADDOMAINTAG 10009
#define IasADLOGOTAG 100010
#define IasADSPLASHENDPOPTAG 2023101301
#define IasADRATINGTAG 2023102501
#define IasADADVERTISERTAG 2023102502

#define IasADCTALEFTBUTTONTAG  2024042201
#define IasADCTARIGHTBUTTONTAG 2024042202

#define IasADREDPACKETOPENBUTTONTAG  2024042501
#define IasADREDPACKETMASKTAG 2024042502
#define IasADREDPACKETVIEWTAG 2024042503
#define IasADREDPACKETDETAILRECEIVEBUTTONTAG 2024042504
#define IasADREDPACKETDETAILVIEWTAG 2024042505
#define IasADRETENTIONVIEWCTATAG 2024042506
#define IasADRETENTIONVIEWCARDAREATAG 2024042507
#define IasADRETENTIONVIEWBACKGROUNDAREATAG 2024042508
#define IasADRETENTIONVIEWCLOSEBUTTONTAG 2024042509
#define IasADWITHDRAWVIDEOVIEWTAG 2024042510
#define IasADWITHDRAWCARDVIEWAREATAG 2024042511
#define IasADWITHDRAWONLYBUTTONTAG 2024042512
#define IasADWITHDRAWBACKGROUNDAREATAG 2024042513

#define IasADSplashBottomSemicircle 202409251025


// v5.7.24
typedef NS_ENUM(NSInteger, IasOfferInterActableArea) {
    IasOfferInterActableAreaAll,
    IasOfferInterActableAreaVisibleItems,
    IasOfferInterActableAreaCTA
};

typedef NS_ENUM(NSUInteger, IasOfferModelResourceType) {
    IasOfferModelResourceTypeVideo,
    IasOfferModelResourceTypeImage,
    IasOfferModelResourceTypeAudio,
};

typedef NS_ENUM(NSUInteger, IasCoordinateModeType) {
    IasCoordinateModeTypeRandom = 1,
    IasCoordinateModeTypeFixationCode,
    IasCoordinateModeTypeNotReplace,
};

@class IasCampaignExp,IasAdWebViewManager;
@interface IasOfferModel : IasModel

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, assign) BOOL isCustomModel;

/// offermodel的唯一标识，在初始化时SDK默认生成
@property (nonatomic, copy) NSString *offerIdentifier;
@property (nonatomic, copy) NSString *requestID;
@property (nonatomic, copy) NSString *resourceID;
@property (nonatomic, copy) NSString *unitID;
@property (nonatomic, copy) NSString *offerID;
@property (nonatomic, copy) NSString *offerDspID;
@property (nonatomic, copy) NSString *localResourceID;
/// 当SK加载失败,直接跳转appStore 链接
@property (nonatomic, copy) NSString *appStoreUrlString;
@property (nonatomic, copy, nullable) NSString *pkgName;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *iconURL;
@property (nonatomic, copy) UIImage *iconImage;// 部分network只返回iconimage 没有iconurl 如inmobi信息流
@property (nonatomic, copy) NSString *fullScreenImageURL;
@property (nonatomic, copy) NSString *logoURL;//adv_u
@property (nonatomic, copy) NSString *CTA;
@property (nonatomic, copy) NSString *videoURL;
@property (nonatomic, copy) NSString *storeURL;
@property (nonatomic, copy) NSString *jumpUrl;
@property (nonatomic, copy) NSString *clickURL;
@property (nonatomic, copy) NSString *deeplinkUrl;
/// html 广告宽
@property (nonatomic, assign) NSInteger offerBannerW;
/// html 广告高
@property (nonatomic, assign) NSInteger offerBannerH;
@property (nonatomic, strong) UIImage *native_mix_iconImage;
@property (nonatomic, strong) UIImage *native_mix_fullScreenImage;
@property (nonatomic, assign) NSInteger rating;
@property (nonatomic, assign) IasLinkType linkType;
@property (nonatomic, assign) IasInterstitialType interstitialType;//check the offer for video or image
@property (nonatomic, assign) IasOfferInterActableArea interActableArea;
@property (nonatomic, assign) IasOfferModelType offerModelType;
@property (nonatomic, assign) IasOfferCrtType crtType;
@property (nonatomic, assign) NSInteger offerFirmID;
@property (nonatomic, assign) BOOL offerIMCapSw;
@property (nonatomic, assign) BOOL offerCLCapSw;
@property (nonatomic, assign) BOOL resourceIMCapSw;
@property (nonatomic, assign) BOOL resourceCLCapSw;
// ad attributes
@property (nonatomic, copy) NSString *adPublisher;
@property (nonatomic, copy) NSString *adVersion;
@property (nonatomic, copy) NSString *adPrivacy;
@property (nonatomic, copy) NSString *adPermission;
//banner(myoffer:5.6.6)
@property (nonatomic, copy) NSString *bannerImageUrl;
@property (nonatomic, copy) NSString *bannerBigImageUrl;
@property (nonatomic, copy) NSString *rectangleImageUrl;
@property (nonatomic, copy) NSString *homeImageUrl;
@property (nonatomic, strong) NSArray<NSString *> *resourceURLs;
@property (nonatomic, strong) NSArray<NSString *> *resourceImageURLs;
@property (nonatomic, strong) NSArray<NSString *> *resourceAudioURLs;
@property (nonatomic, strong) NSArray<NSString *> *clickTKUrl;
@property (nonatomic, strong) NSArray<NSString *> *openSchemeFailedTKUrl;
@property (nonatomic, assign) NSInteger displayDuration;
@property (nonatomic, assign) NSInteger videoCurrentTime;
@property (nonatomic, assign) NSInteger videoResumeTime;
@property (nonatomic, strong, nullable) NSDictionary *tapInfoDict;
// If it is YES, it means that the feedback has been done.
@property (nonatomic, assign) BOOL feedback;
// v5.7.47 +
@property (nonatomic, strong) NSArray<NSString *> *deeplinkSuccessUrl;
@property (nonatomic, strong) NSDictionary *ias_deeplinkSuccessUrl;
@property (nonatomic, strong) NSArray<NSString *> *deeplinkStartTKUrl;
@property (nonatomic, strong) NSDictionary *ias_deeplinkStartTKUrl;
// v5.7.56+
@property (nonatomic, assign) IasSplashImageScaleType splashImageScaleType;
// Whether to enable the shake function. 1 means open, 2 means not open
@property (nonatomic, assign) BOOL splashShakeSw;
// The minimum value of the gyroscope that can trigger a shake click. Default is 0.1
@property (nonatomic, assign) CGFloat shakeStrength;
// Shake the time interval that a tap can trigger again. The default is 5s
@property (nonatomic, assign) NSInteger shakeTime;
@property (nonatomic, assign) BOOL canMute;
// ad type：0 Native, 1 Rewarded, 2 Banner, 3 Interstitial, 4 Splash
@property (nonatomic, assign) IasAdFormat format;
// for SKAdNetwork
@property (nonatomic, strong) IasCampaignExp *campaignExp;
//6.1.32https://confluence.magicgame001.com/pages/viewpage.action?pageId=47126246
@property (nonatomic, assign) BOOL storeKitSwitch;
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *urlJavascriptDic;
@property (nonatomic, assign) NSInteger networkFirmID;
@property (nonatomic, assign) BOOL isGuideClick;
@property (nonatomic, strong) IasAdWebViewManager *adWebManager;
// 标记广告协议 0: 默认，1:Mraid，2:Vast
@property(nonatomic, assign) IasOfferAdpType adpType;
/// 微信小程序ID
@property (nonatomic, copy) NSString *wxUserName;
/// 打开微信小程序的路径
@property (nonatomic, copy, nullable) NSString *wxPath;
/// 素材是否来源于bid
@property (nonatomic, assign) BOOL isFodderSourceBid;
// 视频文件大小，MB
@property (nonatomic, assign) double videoSize;
@property (nonatomic, assign) BOOL splashVideoPlayFinishCloseSw;
/// 坐标回传模式
/// 1-非真实点击随机坐标：以前的逻辑（6.3.30及以上默认值）
/// 2-非真实点击-999：非真实点击时，坐标替换-999
/// 3-非真实点击不换坐标：非真实点击时，删掉宏不更换坐标
@property (nonatomic, assign) IasCoordinateModeType coordinateModeType;
@property (nonatomic, assign) BOOL isNativeMixAd;
// deeplink映射的包名
@property (nonatomic, copy, nullable) NSString *deeplinkPackage;
/// 图片素材宽，单位像素
@property (nonatomic, assign) double imageWidth;
/// 图片素材高，单位像素
@property (nonatomic, assign) double imageHeight;
/// 视频素材宽，单位像素
@property (nonatomic, assign) double videoWidth;
/// 视频素材宽，单位像素
@property (nonatomic, assign) double videoHeight;

- (NSString *_Nullable)getResourceURLkey:(NSString *_Nullable)urlStr;

- (BOOL)showAdAttributes;
@property (nonatomic, assign) BOOL isMaterialPortrait;

#pragma mark - 素材缺少判断
- (BOOL)isLoseAll;
- (BOOL)isShowAllUI;
- (BOOL)isLoseIcon;
- (BOOL)isLoseTitle;
- (BOOL)isLoseDes;
- (BOOL)isLoseVideo;
- (BOOL)isLoseMainImage;

@end


NS_ASSUME_NONNULL_END
