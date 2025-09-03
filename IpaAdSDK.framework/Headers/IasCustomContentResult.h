//
//  IasCustomContentResult.h
//  IpaAdSDK
//
//  Created by 抽筋的灯 on 2024/10/11.
//  Copyright © 2024 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class IasCustomContentInfo;
@interface IasCustomContentResult : NSObject

@property (nonatomic, copy, readonly) NSArray<IasCustomContentInfo *> *contentInfoArray;

- (instancetype)initContentResultWithInfoArray:(NSArray *)contentInfoArray;

@end

NS_ASSUME_NONNULL_END
