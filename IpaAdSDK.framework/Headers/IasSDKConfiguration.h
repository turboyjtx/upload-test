//
//  IasSDKConfiguration.h
//  IpaAdSDK
//
//  Created by Ben on 2022/6/20.
//  Copyright © 2022 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasNetwokBaseConfigure.h>

NS_ASSUME_NONNULL_BEGIN

@interface IasSDKConfiguration : NSObject

/// pre initialize SDK by configure array
@property (nonatomic,strong) NSArray <IasNetwokBaseConfigure *> *preInitArray;

@end

NS_ASSUME_NONNULL_END
