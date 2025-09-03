//
//  IasADXObject.h
//  IpaAdSDK
//
//  Created by li zhixuan on 2023/10/7.
//  Copyright © 2023 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasAd.h>



NS_ASSUME_NONNULL_BEGIN

extern NSString *kIasADXObjectNetwokName;
extern NSString *kIasADXObjectWaterfallInfo;

//for win, usd for price,type string
extern NSString *kIasADXObjectSecondLossPrice;
//for loss, usd for price,type string
extern NSString *kIasADXObjectWinPrice;
extern NSString *kIasADXObjectLossReason;

//for Loss Reason
extern NSString *kIasADXObjectLossReasonBidLowPrice;
extern NSString *kIasADXObjectLossReasonLowPrice;

@interface IasADXObject : NSObject

- (instancetype)initWithAd:(id<IasAd>)ad;

- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

- (void)remove;

@end

NS_ASSUME_NONNULL_END
