//
//  IasPlatfromInfo.h
//  IpaAdSDK
//
//  Created by GUO PENG on 2024/5/24.
//  Copyright © 2024 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, IasRevenueToPlatform) {
    IasRevenueToPlatformAdjust = 1,
    IasRevenueToPlatformAppsflyer = 2,
    IasRevenueToPlatformTenjin
};


@interface IasPlatfromInfo : NSObject

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@property(nonatomic) IasRevenueToPlatform platform;
@property(nonatomic) NSInteger dataType;
@property(nonatomic, copy) NSString *token;

@end

NS_ASSUME_NONNULL_END
