//
//  IasNetworkBaseManager.h
//  IpaAdSDK
//
//  Created by IpaAd on 11/11/20.
//  Copyright © 2020 IpaAd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasAdAdapter.h>
#import <IpaAdSDK/IasUnitGroupModel.h>
#import <IpaAdSDK/IasAPI+Internal.h>




NS_ASSUME_NONNULL_BEGIN
#define IasDefaultVersion @"9999.99999999"
@interface IasNetworkBaseManager : NSObject

+ (void)initWithCustomInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo;

//+ (void)startInitNetworkSDK:(NSDictionary *)serverInfo target:(id<IasAdapterLoaderProtocol>)target targetKey:(NSString *)targetKey;

+ (instancetype)sharedManager;

- (NSString *)versionsString;

- (NSArray *)recommendVersionsArray;

@end

NS_ASSUME_NONNULL_END
