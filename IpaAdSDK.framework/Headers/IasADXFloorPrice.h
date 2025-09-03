//
//  IasADXFloorPrice.h
//  IpaAdSDK
//
//  Created by li zhixuan on 2023/10/19.
//  Copyright © 2023 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kIasADXFloorPriceLoadFullWaterfall;
extern NSString *const kIasADXFloorPriceLoadIpaAdWaterfall;
extern NSString *const kIasADXFloorPriceLoadIpaAdWaterfallLastStopPrice;

typedef NS_ENUM(NSUInteger, IasADXFloorPriceType) {
    IasADXFloorPriceTypeC = 1,
    IasADXFloorPriceTypeG,
};

@interface IasADXFloorPrice : NSObject

@property (nonatomic, assign) IasADXFloorPriceType type;
@property (nonatomic, strong) NSString *value;

@property (nonatomic, strong) NSDictionary *extra;

@end

NS_ASSUME_NONNULL_END
