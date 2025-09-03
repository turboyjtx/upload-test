//
//  IasStorage.h
//  IpaAdSdkDemo
//
//  Created by li zhixuan on 2022/11/19.
//

#import <Foundation/Foundation.h>

@class IasDatabaseStorage;
@class IasMemoryStorage;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, IasStorageEntitySaveType) {
    IasStorageEntitySaveTypeMemory,
    IasStorageEntitySaveTypeDatabase,
};

@protocol IasStorageEntityProtocol <NSObject>

- (id)identifier;
+ (IasStorageEntitySaveType)saveType;

@end

@protocol IasStorageProtocol <NSObject>

- (void)createEntityClazz:(Class)clazz;
- (BOOL)saveWithEntity:(id<IasStorageEntityProtocol>)entity entityClazz:(Class)clazz;
- (id<IasStorageEntityProtocol>)readEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;
- (BOOL)removeEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;

- (void)readEntityFromDBWithIdentifier:(id)identifier entityClazz:(Class)clazz completion:(void (^ __nullable)(id<IasStorageEntityProtocol> entity))completion;

@end

@interface IasStorage : NSObject<IasStorageProtocol>

@property (nonatomic, readonly) IasDatabaseStorage *database;
@property (nonatomic, readonly) IasMemoryStorage *memory;

+ (IasStorage *)shareInstance;

- (void)createEntityClazz:(Class)clazz;

- (BOOL)saveWithEntity:(id<IasStorageEntityProtocol>)entity entityClazz:(Class)clazz;
- (id<IasStorageEntityProtocol>)readEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;
- (BOOL)removeEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;
- (void)readEntityFromDBWithIdentifier:(id)identifier entityClazz:(Class)clazz completion:(void (^ __nullable)(id<IasStorageEntityProtocol> entity))completion;

@end

NS_ASSUME_NONNULL_END
