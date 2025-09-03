//
//  IasADXAdapterManager.h
//  IpaAdSDK
//
//  Created by li zhixuan on 2023/10/19.
//  Copyright © 2023 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IasADXAdapterManager : NSObject

@property (nonatomic, readonly) NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *waterfallInfoDict;

+ (IasADXAdapterManager *)shareInstance;

- (void)requestWithPlacementId:(NSString *)placementId waterfallInfo:(NSDictionary *)waterfallInfoDict completionBlock:(void (^) (NSDictionary *data,  NSError * _Nullable error))completionBlock;

@end

NS_ASSUME_NONNULL_END
