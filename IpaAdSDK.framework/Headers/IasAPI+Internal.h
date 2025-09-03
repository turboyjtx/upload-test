//
//  IasAPI+Internal.h
//  IpaAdSDK
//
//  Created by Leo on 08/05/2018.
//  Copyright © 2018 Leo. All rights reserved.
//

#ifndef IasAPI_Internal_h
#define IasAPI_Internal_h
#import <IpaAdSDK/IasAPI.h>


#define IasADLoadingErrorDomain @"com.ipaad.IasADLoadingErrorDomain"
#define IasADShowingErrorDomain @"com.ipaad.IasAdShowingErrorDomain"
#define IasSDKAdLoadingErrorMsg @"com.ipaad.AdLoadingError"
#define IasSDKAdLoadFailedErrorMsg @"IpaAdSDK has failed to load ad."

// AD Loading Notification
#define kIasADLoadingStartLoadNotification @"IasADLoadingStartLoadNotification"
#define kIasADLoadingOfferSuccessfullyLoadedNotification @"ADLoadingOfferSuccessfullyLoadedNotification"
#define kIasADLoadingFailedToLoadNotification @"IasADLoadingFailedToLoadNotification"
#define kIasADLoadingNotificationUserInfoRequestIDKey @"request_id"
#define kIasADLoadingNotificationUserInfoPlacementIDKey @"placement_id"
#define kIasADLoadingNotificationUserInfoPlacementKey @"placement_model"
#define kIasADLoadingNotificationUserInfoUnitGroupKey @"unit_group_model"
#define kIasADLoadingNotificationUserInfoErrorKey @"error"
#define kIasADLoadingNotificationUserInfoExtraKey @"extra"
#define kIasADLoadingNotificationUserInfoLoadingTypeKey @"loading_type"

/**
 Adopters are expected to implement logic for network offers, for which storage mechanisms must be devise.
 */
@protocol IasNativeAdapter<NSObject>
/**
 The class of the renderer used to render the AD view. This method is a class-method because by the time this information is needed the adapter instance will have been released.
 */
+ (Class)rendererClass;
/**
 Adopter should implement this method for the initialization of a adapter instance, which will store the passed info for further use.
 
 */
- (instancetype)initWithNetworkCustomInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo;

/**
 Adopter should implement this method to load network offers.
 
 @param completion might need to be stored and invoked after ad's succeffully loaded.
 Parameters passed to the completion block include a dictionary and an error objects. The error object encapsulates the error info if loading request failed somehow; the dictionary contains all publicly accessible assets (such as title and text) for the native ad, which should be stored using the keys predefined by the SDK.
 */
- (void)loadADWithInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo completion:(void(^)(NSArray<NSDictionary*>* assets, NSError *error))completion;

@property (nonatomic,copy) void (^metaDataDidLoadedBlock)(void);
@end

@interface IasAPI(Internal)

@property (nonatomic, strong) IasSharePlacementConfig *sharePlacementConfig;

+ (NSString *)hbTestModeDeviceID;
- (void)setVersion:(NSString*)version forNetwork:(NSString*)network;
- (NSString*)versionForNetworkFirmID:(NSInteger)networkFirmID;
- (BOOL)initFlagForNetwork:(NSString*)networkName;
- (void)setInitFlagForNetwork:(NSString*)networkName;
- (BOOL)cacheFlagForNetwork:(NSString*)networkName;
- (void)setCacheFlagForNetwork:(NSString*)networkName;
- (void)inspectInitFlagForNetwork:(NSString*)networkName usingBlock:(NSInteger(^)(NSInteger currentValue))block;
- (void)setInitFlag:(NSInteger)flag forNetwork:(NSString*)networkName;

@end

#endif /* IasAPI_Internal_h */
