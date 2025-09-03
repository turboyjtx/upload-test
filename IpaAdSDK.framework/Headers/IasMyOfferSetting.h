//
//  IasMyOfferSetting.h
//  IpaAdSDK
//
//  Created by Leo on 2019/9/23.
//  Copyright © 2019 Leo. All rights reserved.
//

#import <IpaAdSDK/IasOfferSetting.h>


@interface IasMyOfferSetting : IasOfferSetting

- (instancetype)initWithDictionary:(NSDictionary *)dictionary placementID:(NSString *)placementID;

@property (nonatomic, readwrite) NSTimeInterval resourceCacheTime;

@end
