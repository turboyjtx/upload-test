//
//  IasADXSettings.h
//  IpaAdSDK
//
//  Created by li zhixuan on 2023/10/7.
//  Copyright © 2023 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, IasADXSettingsMode) {
    IasADXSettingsModeMediation,
    IasADXSettingsModeNetwork,
};

@interface IasADXSettings : NSObject

@property (nonatomic, readonly) NSMutableDictionary *adxNetworkDict;

+ (instancetype)shareInstance;

- (void)setAdxNetworkModeWithPlacementId:(NSString *)placementId;

- (IasADXSettingsMode)adxModeWithPlacementId:(NSString *)placementId;

@end

NS_ASSUME_NONNULL_END
