//
//  IasADXPlacementSetting.h
//  IpaAdSDK
//
//  Created by Leo on 20/8/2020.
//  Copyright © 2020 IpaAd. All rights reserved.
//

#import <IpaAdSDK/IasOfferSetting.h>


@interface IasADXPlacementSetting : IasOfferSetting

- (instancetype)initWithPlacementDictionary:(NSDictionary *)placementDictionary infoDictionary:(NSDictionary *)infoDictionary placementID:(NSString *)placementID;

@end
