//
//  IasDebuggerBridgingAPI.h
//  IpaAdSDK
//
//  Created by GUO PENG on 2024/7/9.
//  Copyright © 2024 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasPlacementModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface IasDebuggerBridgingAPI : NSObject

+ (instancetype)sharedInstance;
/// 获取广告位 信息
- (void)debuggerOnlinePlacementInfo:(NSString *)debugkey completion:(void (^)(NSArray *responseArray))block;
/// 获取 WF 分组ID
- (void)debuggerOnlinePlacementWatllfull:(NSString *)debugkey placementID:(NSString *)placementID completion:(void (^)(NSDictionary *responseDic))block;
/// 获取广告源
- (void)debuggerOnlinePlacementAdSourcefull:(NSString *)debugkey placementID:(NSString *)placementID extraDic:(NSDictionary *)extraDic completion:(void (^)(IasPlacementModel *placementModel))block;


@end

NS_ASSUME_NONNULL_END
