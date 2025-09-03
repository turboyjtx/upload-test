//
//  IasAdLoadingDelegate.h
//  IpaAdSDK
//
//  Created by Leo on 04/07/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#ifndef IasAdLoadingDelegate_h
#define IasAdLoadingDelegate_h

@class IasAdRequestingInfo;

@protocol IasAdMultipleLoadingDelegate<NSObject>

- (void)didFinishMultipleLoadingAD:(NSString *)placementID
                                   requestingInfo:(IasAdRequestingInfo *)requestingInfo;
@end

@protocol IasAdLoadingDelegate<NSObject>

/// Callback when the successful loading of the ad
- (void)didFinishLoadingAD:(NSString *)placementID;



/// Callback of ad loading failure
- (void)didFailToLoadAD:(NSString*)placementID
                                 error:(NSError*)error;

- (void)didRevenue:(NSString *)placementID
                              extra:(NSDictionary *)extra;


/// Ad start load
- (void)didStartLoadingADSource:(NSString *)placementID
                                         extra:(NSDictionary*)extra;
/// Ad load success
- (void)didFinishLoadingADSource:(NSString *)placementID
                                          extra:(NSDictionary*)extra;
/// Ad load fail
- (void)didFailToLoadADSource:(NSString*)placementID
                                       extra:(NSDictionary*)extra
                                       error:(NSError*)error;

/// Ad start bidding
- (void)didStartBiddingADSource:(NSString *)placementID
                                         extra:(NSDictionary*)extra;

/// Ad bidding success
- (void)didFinishBiddingADSource:(NSString *)placementID
                                          extra:(NSDictionary*)extra;

/// Ad bidding fail
- (void)didFailBiddingADSource:(NSString*)placementID
                                        extra:(NSDictionary*)extra
                                        error:(NSError*)error;

@end
#endif /* IasAdLoadingDelegate_h */
