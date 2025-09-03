//
//  IasAdapter.h
//  IpaAdSdkDemo
//
//  Created by li zhixuan on 2022/11/18.
//

#import <Foundation/Foundation.h>
#import <IpaAdSDK/IasAdAdapter.h>


NS_ASSUME_NONNULL_BEGIN

@protocol IasAdapterDelegate;

#pragma mark - IasAdapterProtocol
@protocol IasAdapterProtocol <NSObject>

@property (nonatomic, weak) id<IasAdapterDelegate> delegate;
// 无用
//- (void)loadWithUserInfo:(NSDictionary<id, id> *)userInfo;
- (void)show;

@end

#pragma mark - IasAdapterDelegate
@protocol IasAdapterDelegate <NSObject>

- (void)adapter:(id<IasAdapterProtocol>)adapter adDidLoadCompletionWithUserInfo:(NSDictionary *)userInfo error:(nullable NSError *)error;

@end

#pragma mark - IasAdapter
@interface IasAdapter : NSObject<IasAdAdapter>

- (instancetype)initWithClass:(Class)clazz;

- (BOOL)adReadyForInfo:(NSDictionary *)info;
- (id<IasAd>)readyFilledAdWithPlacementModel:(IasPlacementModel *)placementModel
                                  requestID:(NSString *)requestID
                                   priority:(NSInteger)priority
                                  unitGroup:(IasUnitGroupModel *)unitGroup
                                  localInfo:(NSDictionary *)localInfo;

@end

NS_ASSUME_NONNULL_END
