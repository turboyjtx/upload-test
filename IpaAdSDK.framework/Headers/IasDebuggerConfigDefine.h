//
//  IasDebuggerConfigDefine.h
//  IpaAdSDK
//
//  Created by GUO PENG on 2022/8/10.
//  Copyright © 2022 IpaAd. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
#pragma mark - NetWorkType
typedef NS_ENUM(NSUInteger, IasAdNetWorkType) {
    IasAdNetWorkMetaType = 1,
    IasAdNetWorkAdmobType = 2,
    IasAdNetWorkInmobiType = 3,
    IasAdNetWorkApplovinType = 5,
    IasAdNetWorkMintegralType = 6,
    IasAdNetWorkGDTType = 8,
    IasAdNetWorkChartboostType = 9,
    IasAdNetWorkTapjoyType = 10,
    IasAdNetWorkIronsourceType = 11,
    IasAdNetWorkUnityAdsType = 12,
    IasAdNetWorkVungleType = 13, // 1
    IasAdNetWorkCSJType = 15,
    IasAdNetWorkBaiduType = 22,
    IasAdNetWorkNendType = 23,
    IasAdNetWorkMaioType = 24,
    IasAdNetWorkStartAppType = 25,
    IasAdNetWorkKuaiShouType = 28,
    IasAdNetWorkSigmobType = 29,
    IasAdNetWorkMyTargetType = 32, // 1
    IasAdNetWorkFyberType = 37,
    IasAdNetWorkPangleType = 50,
    IasAdNetWorkKlevinType = 51,
    IasAdNetWorkPubNativeType = 58,
    IasAdNetWorkBigoType = 59,
    IasAdNetWorkAdxType = 66,
    IasAdNetWorkKwaiType = 77,
};

#pragma mark - Pangle

typedef NS_ENUM(NSUInteger, IasPangleSplashAdType) {
    IasPangleSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasPangleInterstitialAdType) {
    IasPangleInterstitialAdDefaultType =  0,
};

typedef NS_ENUM(NSUInteger, IasPangleRewardVideoAdType) {
    IasPangleRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasPangleBannerAdType) {
    IasPangleBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasPangleNativeAdType) {
    IasPangleNativeAdDefaultType = 0,
};



#pragma mark - CSJ

typedef NS_ENUM(NSUInteger, IasCSJSplashAdType) {
    IasCSJSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasCSJInterstitialAdType) {
    IasCSJInterstitialAdNewType =  3,

};

typedef NS_ENUM(NSUInteger, IasCSJRewardVideoAdType) {
    IasCSJRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasCSJBannerAdType) {
    IasCSJBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasCSJNativeAdType) {
    IasCSJNativeAdDrawTemplateType = 201,
    IasCSJNativeAdDrawSelfRenderType = 202,
    IasCSJNativeAdFeedTemplateType = 101,
    IasCSJNativeAdFeedSelfRenderType = 102,
};


#pragma mark - Meta
typedef NS_ENUM(NSUInteger, IasMetaSplashAdType) {
    IasMetaSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMetaInterstitialAdType) {
    IasMetaInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMetaRewardVideoAdType) {
    IasMetaRewardVideoAdDefaultType = 0,
    IasMetaRewardVideoAdInterstitialType,
};

typedef NS_ENUM(NSUInteger, IasMetaBannerAdType) {
    IasMetaBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMetaNativeAdType) {
    IasMetaNativeAdSelfRenderType = 1,
    IasMetaNativeAdNativeBannerTemplateType = 2,
    IasMetaNativeAdTemplateType = 3,
    IasMetaNativeAdNativeBannerSelfRenderType = 4,
};

#pragma mark - Mytarget

typedef NS_ENUM(NSUInteger, IasMytargetSplashAdType) {
    IasMytargetSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMytargetInterstitialAdType) {
    IasMytargetInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMytargetRewardVideoAdType) {
    IasMytargetRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasMytargetBannerAdType) {
    IasMytargetBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMytargetNativeAdType) {
    IasMytargetNativeAdDefaultType = 0,
};

#pragma mark - AdMob
typedef NS_ENUM(NSUInteger, IasAdMobSplashAdType) {
    IasAdMobSplashAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasAdMobInterstitialAdType) {
    IasAdMobInterstitialAdPictureType = 1,
    IasAdMobInterstitialAdVideoType = 2,
};

typedef NS_ENUM(NSUInteger, IasAdMobRewardVideoAdType) {
    IasAdMobRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasAdMobBannerAdType) {
    IasAdMobBannerAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasAdMobNativeAdType) {
    IasAdMobNativeAdPictureType = 1,
    IasAdMobNativeAdVideoType = 2,
};

#pragma mark - Applovin
typedef NS_ENUM(NSUInteger, IasApplovinSplashAdType) {
    IasApplovinSplashAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasApplovinInterstitialAdType) {
    IasApplovinInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasApplovinRewardVideoAdType) {
    IasApplovinRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasApplovinBannerAdType) {
    IasApplovinBannerAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasApplovinNativeAdType) {
    IasApplovinNativeAdDefaultType = 0,
};

#pragma mark - Baidu

typedef NS_ENUM(NSUInteger, IasBaiduSplashAdType) {
    IasBaiduSplashAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasBaiduInterstitialAdType) {
    IasBaiduInterstitialAdFullScreenVideoType = 2,
    IasBaiduInterstitialAdTemplateType = 3,


};

typedef NS_ENUM(NSUInteger, IasBaiduRewardVideoAdType) {
    IasBaiduRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasBaiduBannerAdType) {
    IasBaiduBannerAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasBaiduNativeAdType) {
    IasBaiduNativeAdSelfRenderType = 1,
    IasBaiduNativeAdTemplateType = 4,
};

#pragma mark - Chartboost
typedef NS_ENUM(NSUInteger, IasChartboostSplashAdType) {
    IasChartboostSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasChartboostInterstitialAdType) {
    IasChartboostInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasChartboostRewardVideoAdType) {
    IasChartboostRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasChartboostBannerAdType) {
    IasChartboostBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasChartboostNativeAdType) {
    IasChartboostNativeAdDefaultType = 0,
};

#pragma mark - Fyber
typedef NS_ENUM(NSUInteger, IasFyberSplashAdType) {
    IasFyberSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasFyberInterstitialAdType) {
    IasFyberInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasFyberRewardVideoAdType) {
    IasFyberRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasFyberBannerAdType) {
    IasFyberBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasFyberNativeAdType) {
    IasFyberNativeAdDefaultType = 0,
};

#pragma mark - GDT
typedef NS_ENUM(NSUInteger, IasGDTSplashAdType) {
    IasGDTSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasGDTInterstitialAdType) {
    IasGDTInterstitialAdPopupVideoType = 1,
    IasGDTInterstitialAdFullScreenVideoType = 2,

};

typedef NS_ENUM(NSUInteger, IasGDTRewardVideoAdType) {
    IasGDTRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasGDTBannerAdType) {
    IasGDTBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasGDTDebugNativeAdType) {
    IasGDTNativeAdTemplateType = 1,
    IasGDTNativeAdSelfRenderType = 2,
    IasGDTNativeAdVideoTemplateType = 3,
    IasGDTNativeAdVideoSelfRenderType = 4,
};

#pragma mark - Inmobi
typedef NS_ENUM(NSUInteger, IasInmobiSplashAdType) {
    IasInmobiSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasInmobiInterstitialAdType) {
    IasInmobiInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasInmobiRewardVideoAdType) {
    IasInmobiRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasInmobiBannerAdType) {
    IasInmobiBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasInmobiNativeAdType) {
    IasInmobiNativeAdDefaultType = 0,
};

#pragma mark - Ironsource
typedef NS_ENUM(NSUInteger, IasIronsourceSplashAdType) {
    IasIronsourceSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasIronsourceInterstitialAdType) {
    IasIronsourceInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasIronsourceRewardVideoAdType) {
    IasIronsourceRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasIronsourceBannerAdType) {
    IasIronsourceBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasIronsourceNativeAdType) {
    IasIronsourceNativeAdDefaultType = 0,
};

#pragma mark - Klevin
typedef NS_ENUM(NSUInteger, IasKlevinSplashAdType) {
    IasKlevinSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasKlevinInterstitialAdType) {
    IasKlevinInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasKlevinRewardVideoAdType) {
    IasKlevinRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasKlevinBannerAdType) {
    IasKlevinBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasKlevinNativeAdType) {
    IasKlevinNativeAdDefaultType = 0,
};

#pragma mark - KuaiShou
typedef NS_ENUM(NSUInteger, IasKuaiShouSplashAdType) {
    IasKuaiShouSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasKuaiShouInterstitialAdType) {
    IasKuaiShouInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasKuaiShouRewardVideoAdType) {
    IasKuaiShouRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasKuaiShouBannerAdType) {
    IasKuaiShouBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasKuaiShouNativeAdType) {
    IasKuaiShouNativeAdFeedSelfRenderType = 101,
    IasKuaiShouNativeAdFeedTemplateType = 102,
    IasKuaiShouNativeAdDrawFeedType = 200,
};

#pragma mark - Maio
typedef NS_ENUM(NSUInteger, IasMaioSplashAdType) {
    IasMaioSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMaioInterstitialAdType) {
    IasMaioInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasMaioRewardVideoAdType) {
    IasMaioRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasMaioBannerAdType) {
    IasMaioBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMaioNativeAdType) {
    IasMaioNativeAdDefaultType = 0,
};

#pragma mark - Mintegral
typedef NS_ENUM(NSUInteger, IasMintegralSplashAdType) {
    IasMintegralSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMintegralInterstitialAdType) {
    IasMintegralInterstitialAdVideoType = 2,
};

typedef NS_ENUM(NSUInteger, IasMintegralRewardVideoAdType) {
    IasMintegralRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasMintegralBannerAdType) {
    IasMintegralBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasMintegralNativeAdType) {
    IasMintegralNativeAdSelfRenderType = 1,
    IasMintegralNativeAdTemplateType = 2,
};

#pragma mark - Nend
typedef NS_ENUM(NSUInteger, IasNendSplashAdType) {
    IasNendSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasNendInterstitialAdType) {
    IasNendInterstitialAdDefaultType = 1,
    IasNendInterstitialAdVideoType = 2,
    IasNendInterstitialAdFullScreenType = 3,
};

typedef NS_ENUM(NSUInteger, IasNendRewardVideoAdType) {
    IasNendRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasNendBannerAdType) {
    IasNendBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasNendNativeAdType) {
    IasNendNativeAdDefaultType = 0,
};

#pragma mark - Sigmob
typedef NS_ENUM(NSUInteger, IasSigmobSplashAdType) {
    IasSigmobSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasSigmobInterstitialAdType) {
    IasSigmobInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasSigmobRewardVideoAdType) {
    IasSigmobRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasSigmobBannerAdType) {
    IasSigmobBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasSigmobNativeAdType) {
    IasSigmobNativeAdDefaultType = 0,
};

#pragma mark - StartApp
typedef NS_ENUM(NSUInteger, IasStartAppSplashAdType) {
    IasStartAppSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasStartAppInterstitialAdType) {
    IasStartAppInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasStartAppRewardVideoAdType) {
    IasStartAppRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasStartAppBannerAdType) {
    IasStartAppBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasStartAppNativeAdType) {
    IasStartAppNativeAdDefaultType = 0,
};

#pragma mark - Tapjoy
typedef NS_ENUM(NSUInteger, IasTapjoySplashAdType) {
    IasTapjoySplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasTapjoyInterstitialAdType) {
    IasTapjoyInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasTapjoyRewardVideoAdType) {
    IasTapjoyRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasTapjoyBannerAdType) {
    IasTapjoyBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasTapjoyNativeAdType) {
    IasTapjoyNativeAdDefaultType = 0,
};

#pragma mark - UnityAds
typedef NS_ENUM(NSUInteger, IasUnityAdsSplashAdType) {
    IasUnityAdsSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasUnityAdsInterstitialAdType) {
    IasUnityAdsInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasUnityAdsRewardVideoAdType) {
    IasUnityAdsRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasUnityAdsBannerAdType) {
    IasUnityAdsBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasUnityAdsNativeAdType) {
    IasUnityAdsNativeAdDefaultType = 0,
};

#pragma mark - Vungle
typedef NS_ENUM(NSUInteger, IasVungleSplashAdType) {
    IasVungleSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasVungleInterstitialAdType) {
    IasVungleInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasVungleRewardVideoAdType) {
    IasVungleRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasVungleBannerAdType) {
    IasVungleBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasVungleNativeAdType) {
    IasVungleNativeAdDefaultType = 0,
};

#pragma mark - ADX
typedef NS_ENUM(NSUInteger, IasADXSplashAdType) {
    IasADXSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasADXInterstitialAdType) {
    IasADXInterstitialAdFullScreenType = 1,
    IasADXInterstitialAdHalfScreenType = 2,
};

typedef NS_ENUM(NSUInteger, IasADXRewardVideoAdType) {
    IasADXRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasADXBannerAdType) {
    IasADXBannerAdType_320_50 = 1,
    IasADXBannerAdType_320_90 = 2,
    IasADXBannerAdType_300_250 = 3,
    IasADXBannerAdType_728_90 = 4,
};

typedef NS_ENUM(NSUInteger, IasADXNativeAdType) {
    IasADXNativeAdTypeExpressLeftPicRightText = 1,
    IasADXNativeAdTypeExpressLeftTextRightPic = 2,
    IasADXNativeAdTypeExpressTopPicBottomText = 3,
    IasADXNativeAdTypeExpressTopTextBottomPic = 4,
    IasADXNativeAdTypeExpressTextSuperposedLayer = 5,
    IasADXNativeAdTypeSelfRender = 6,
};

#pragma mark - PubNative
typedef NS_ENUM(NSUInteger, IasPubNativeInterstitialAdType) {
    IasPubNativeInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasPubNativeRewardVideoAdType) {
    IasPubNativeRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasPubNativeBannerAdType) {
    IasPubNativeBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasPubNativeNativeAdType) {
    IasPubNativeNativeAdDefaultType = 0,
};


#pragma mark - Bigo
typedef NS_ENUM(NSUInteger, IasBigoSplashAdType) {
    IasBigoSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, IasBigoInterstitialAdType) {
    IasBigoInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasBigoRewardVideoAdType) {
    IasBigoRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasBigoBannerAdType) {
    IasBigoBannerAdSmallType = 1,// 320x50
    IasBigoBannerAdLargeType = 2,// 300x250
};

typedef NS_ENUM(NSUInteger, IasBigoNativeAdType) {
    IasBigoNativeAdDefaultType = 0,
};

#pragma mark - Kwai
typedef NS_ENUM(NSUInteger, IasKwaiInterstitialAdType) {
    IasKwaiInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, IasKwaiRewardVideoAdType) {
    IasKwaiRewardVideoAdDefaultType = 0,
};

NS_ASSUME_NONNULL_END
