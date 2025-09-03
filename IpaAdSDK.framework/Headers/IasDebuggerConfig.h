//
//  IasTestSchemaMode.h
//  IpaAdSDK
//
//  Created by GUO PENG on 2022/8/2.
//  Copyright © 2022 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasDebuggerConfigDefine.h>




NS_ASSUME_NONNULL_BEGIN


@interface IasDebuggerConfig : NSObject

@property(nonatomic, assign,readonly) BOOL isDebugger;

@property(nonatomic, assign) IasAdNetWorkType netWorkType;

@property(nonatomic, strong) NSString *deviceIdfaStr;

#pragma mark - CSJ
@property(nonatomic, assign) IasCSJSplashAdType csj_splashAdType;

@property(nonatomic, assign) IasCSJInterstitialAdType csj_interstitialAdType;

@property(nonatomic, assign) IasCSJRewardVideoAdType csj_rewardVideoAdType;

@property(nonatomic, assign) IasCSJBannerAdType csj_bannerAdType;

@property(nonatomic, assign) IasCSJNativeAdType csj_nativeAdType;


#pragma mark - Pangle

@property(nonatomic, assign) IasPangleSplashAdType pangle_splashAdType;

@property(nonatomic, assign) IasPangleInterstitialAdType pangle_interstitialAdType;

@property(nonatomic, assign) IasPangleRewardVideoAdType pangle_rewardVideoAdType;

@property(nonatomic, assign) IasPangleBannerAdType pangle_bannerAdType;

@property(nonatomic, assign) IasPangleNativeAdType pangle_nativeAdType;

#pragma mark - Meta

@property(nonatomic, assign) IasMetaInterstitialAdType meta_interstitialAdType;

@property(nonatomic, assign) IasMetaRewardVideoAdType meta_rewardVideoAdType;

@property(nonatomic, assign) IasMetaBannerAdType meta_bannerAdType;

@property(nonatomic, assign) IasMetaNativeAdType meta_nativeAdType;

#pragma mark - Mytarget

@property(nonatomic, assign) IasMytargetInterstitialAdType mytarget_interstitialAdType;

@property(nonatomic, assign) IasMytargetRewardVideoAdType mytarget_rewardVideoAdType;

@property(nonatomic, assign) IasMytargetBannerAdType mytarget_bannerAdType;

@property(nonatomic, assign) IasMytargetNativeAdType mytarget_nativeAdType;

#pragma mark - AdMob

@property(nonatomic, assign) IasAdMobSplashAdType adMob_splashAdType;

@property(nonatomic, assign) IasAdMobInterstitialAdType adMob_interstitialAdType;

@property(nonatomic, assign) IasAdMobRewardVideoAdType adMob_rewardVideoAdType;

@property(nonatomic, assign) IasAdMobBannerAdType adMob_bannerAdType;

@property(nonatomic, assign) IasAdMobNativeAdType adMob_nativeAdType;

#pragma mark - Applovin

@property(nonatomic, assign) IasApplovinInterstitialAdType applovin_interstitialAdType;

@property(nonatomic, assign) IasApplovinRewardVideoAdType applovin_rewardVideoAdType;

@property(nonatomic, assign) IasApplovinBannerAdType applovin_bannerAdType;


#pragma mark - Baidu
@property(nonatomic, assign) IasBaiduSplashAdType baidu_splashAdType;

@property(nonatomic, assign) IasBaiduInterstitialAdType baidu_interstitialAdType;

@property(nonatomic, assign) IasBaiduRewardVideoAdType baidu_rewardVideoAdType;

@property(nonatomic, assign) IasBaiduBannerAdType baidu_bannerAdType;

@property(nonatomic, assign) IasBaiduNativeAdType baidu_nativeAdType;

#pragma mark - Chartboost

@property(nonatomic, assign) IasChartboostInterstitialAdType chartboost_interstitialAdType;

@property(nonatomic, assign) IasChartboostRewardVideoAdType chartboost_rewardVideoAdType;

@property(nonatomic, assign) IasChartboostBannerAdType chartboost_bannerAdType;


#pragma mark - Fyber

@property(nonatomic, assign) IasFyberInterstitialAdType fyber_interstitialAdType;

@property(nonatomic, assign) IasFyberRewardVideoAdType fyber_rewardVideoAdType;

@property(nonatomic, assign) IasFyberBannerAdType fyber_bannerAdType;


#pragma mark - GDT

@property(nonatomic, assign) IasGDTSplashAdType gdt_splashAdType;

@property(nonatomic, assign) IasGDTInterstitialAdType gdt_interstitialAdType;

@property(nonatomic, assign) IasGDTRewardVideoAdType gdt_rewardVideoAdType;

@property(nonatomic, assign) IasGDTBannerAdType gdt_bannerAdType;

@property(nonatomic, assign) IasGDTDebugNativeAdType gdt_nativeAdType;

#pragma mark - Inmobi

@property(nonatomic, assign) IasInmobiInterstitialAdType inmobi_interstitialAdType;

@property(nonatomic, assign) IasInmobiRewardVideoAdType inmobi_rewardVideoAdType;

@property(nonatomic, assign) IasInmobiBannerAdType inmobi_bannerAdType;

@property(nonatomic, assign) IasInmobiNativeAdType inmobi_nativeAdType;


#pragma mark - Ironsource

@property(nonatomic, assign) IasIronsourceInterstitialAdType ironsource_interstitialAdType;

@property(nonatomic, assign) IasIronsourceRewardVideoAdType ironsource_rewardVideoAdType;

#pragma mark - Klevin
@property(nonatomic, assign) IasKlevinSplashAdType klevin_splashAdType;

@property(nonatomic, assign) IasKlevinInterstitialAdType klevin_interstitialAdType;

@property(nonatomic, assign) IasKlevinRewardVideoAdType klevin_rewardVideoAdType;


@property(nonatomic, assign) IasKlevinNativeAdType klevin_nativeAdType;

#pragma mark - KuaiShou
@property(nonatomic, assign) IasKuaiShouSplashAdType kuaiShou_splashAdType;

@property(nonatomic, assign) IasKuaiShouInterstitialAdType kuaiShou_interstitialAdType;

@property(nonatomic, assign) IasKuaiShouRewardVideoAdType kuaiShou_rewardVideoAdType;

@property(nonatomic, assign) IasKuaiShouBannerAdType kuaiShou_bannerAdType;

@property(nonatomic, assign) IasKuaiShouNativeAdType kuaiShou_nativeAdType;
#pragma mark - Maio

@property(nonatomic, assign) IasMaioInterstitialAdType maio_interstitialAdType;

@property(nonatomic, assign) IasMaioRewardVideoAdType maio_rewardVideoAdType;

#pragma mark - Mintegral
@property(nonatomic, assign) IasMintegralSplashAdType mintegral_splashAdType;

@property(nonatomic, assign) IasMintegralInterstitialAdType mintegral_interstitialAdType;

@property(nonatomic, assign) IasMintegralRewardVideoAdType mintegral_rewardVideoAdType;

@property(nonatomic, assign) IasMintegralBannerAdType mintegral_bannerAdType;

@property(nonatomic, assign) IasMintegralNativeAdType mintegral_nativeAdType;

#pragma mark - Nend
@property(nonatomic, assign) IasNendInterstitialAdType nend_interstitialAdType;

@property(nonatomic, assign) IasNendRewardVideoAdType nend_rewardVideoAdType;

@property(nonatomic, assign) IasNendBannerAdType nend_bannerAdType;


@property(nonatomic, assign) IasNendNativeAdType nend_nativeAdType;

#pragma mark - Sigmob
@property(nonatomic, assign) IasSigmobSplashAdType sigmob_splashAdType;

@property(nonatomic, assign) IasSigmobInterstitialAdType sigmob_interstitialAdType;

@property(nonatomic, assign) IasSigmobRewardVideoAdType sigmob_rewardVideoAdType;

@property(nonatomic, assign) IasSigmobNativeAdType sigmob_nativeAdType;

#pragma mark - StartApp


@property(nonatomic, assign) IasStartAppInterstitialAdType startApp_interstitialAdType;

@property(nonatomic, assign) IasStartAppRewardVideoAdType startApp_rewardVideoAdType;

@property(nonatomic, assign) IasStartAppBannerAdType startApp_bannerAdType;


#pragma mark - Tapjoy

@property(nonatomic, assign) IasTapjoyInterstitialAdType tapjoy_interstitialAdType;

@property(nonatomic, assign) IasTapjoyRewardVideoAdType tapjoy_rewardVideoAdType;


#pragma mark - UnityAds

@property(nonatomic, assign) IasUnityAdsInterstitialAdType unityAds_interstitialAdType;

@property(nonatomic, assign) IasUnityAdsRewardVideoAdType unityAds_rewardVideoAdType;

@property(nonatomic, assign) IasUnityAdsBannerAdType unityAds_bannerAdType;


#pragma mark - Vungle

@property(nonatomic, assign) IasVungleInterstitialAdType vungle_interstitialAdType;

@property(nonatomic, assign) IasVungleRewardVideoAdType vungle_rewardVideoAdType;

@property(nonatomic, assign) IasVungleBannerAdType vungle_bannerAdType;

@property(nonatomic, assign) IasVungleNativeAdType vungle_nativeAdType;

#pragma mark - ADX

@property(nonatomic, assign) IasADXSplashAdType adx_splashAdType;

@property(nonatomic, assign) IasADXInterstitialAdType adx_interstitialAdType;

@property(nonatomic, assign) IasADXRewardVideoAdType adx_rewardVideoAdType;

@property(nonatomic, assign) IasADXBannerAdType adx_bannerAdType;

@property(nonatomic, assign) IasADXNativeAdType adx_nativeAdType;

#pragma mark - Pubnative
@property(nonatomic, assign) IasPubNativeInterstitialAdType pubnative_interstitialAdType;

@property(nonatomic, assign) IasPubNativeRewardVideoAdType pubnative_rewardVideoAdType;

@property(nonatomic, assign) IasPubNativeBannerAdType pubnative_bannerAdType;

@property(nonatomic, assign) IasPubNativeNativeAdType pubnative_nativeAdType;


#pragma mark - Bigo
@property(nonatomic, assign) IasBigoSplashAdType bigo_splashAdType;

@property(nonatomic, assign) IasBigoInterstitialAdType bigo_interstitialAdType;

@property(nonatomic, assign) IasBigoRewardVideoAdType bigo_rewardVideoAdType;

@property(nonatomic, assign) IasBigoBannerAdType bigo_bannerAdType;

@property(nonatomic, assign) IasBigoNativeAdType bigo_nativeAdType;


#pragma mark - api
- (NSDictionary *)getCurrentNetWorkConfig;




@end

NS_ASSUME_NONNULL_END
