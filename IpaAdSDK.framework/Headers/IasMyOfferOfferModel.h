//
//  IasMyOfferOfferModel.h
//  IpaAdMyOffer
//
//  Created by Leo on 2019/9/23.
//  Copyright © 2019 Leo. All rights reserved.
//

#import <IpaAdSDK/IasOfferModel.h>
#import <IpaAdSDK/IasMyOfferSetting.h>

NS_ASSUME_NONNULL_BEGIN

@interface IasMyOfferOfferModel : IasOfferModel

- (instancetype)initWithDictionary:(NSDictionary *)dictionary placeholders:(NSDictionary *)placeholders format:(NSInteger)format setting:(IasMyOfferSetting *)setting;

@property (nonatomic, readwrite) IasScreenOrientation imageOrientation;
@property (nonatomic, readwrite) IasScreenOrientation videoOrientation;
@property (nonatomic, strong) NSString *videoStartTKURL;
@property (nonatomic, strong) NSString *video25TKURL;
@property (nonatomic, strong) NSString *video50TKURL;
@property (nonatomic, strong) NSString *video75TKURL;
@property (nonatomic, strong) NSString *videoEndTKURL;
@property (nonatomic, strong) NSString *endCardShowTKURL;
@property (nonatomic, strong) NSString *endCardCloseTKURL;
@property (nonatomic, strong) NSString *impURL;
@property (nonatomic, strong) NSString *impTKURL;
@property (nonatomic, strong) NSString *clickTKURL;
@property (nonatomic, assign) NSInteger dailyCap;
@property (nonatomic, assign) NSTimeInterval pacing;
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *placeholders;

@property (nonatomic, readwrite) IasClickMode performsAsynchronousRedirection;
@property (nonatomic, readwrite) IasAdOfferInterType interType;
@property (nonatomic, readwrite) IasUserAgentType impressionUAType;
@property (nonatomic, readwrite) IasUserAgentType clickUAType;
@property (nonatomic, strong) IasMyOfferSetting *myOfferSetting;
@property (nonatomic, strong) NSDictionary *offerDict;

/// when check placement myoffers cap mini come into effect, see -[IasPlacement miniCapForMyOffers]
@property (nonatomic, assign) NSInteger currentCap;

@end

NS_ASSUME_NONNULL_END
