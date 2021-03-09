//
//  CNLiveStreamManager.h
//  CNLivePlayerSDKDemo
//
//  Created by iOS on 17/2/23.
//  Copyright © 2017年 雷浩杰. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveTypeDef.h"
#import "CNLiveWatermark.h"
#import "CNLiveStreamerBase.h"
#import "CNLiveBeautifyFaceFilter.h"
#import "CNLiveAudioCapture.h"
#import "CNLiveGPUStreamerKit.h"
#import "CNLiveMoviePlayerController.h"
#import "CNLiveBgmPlayer.h"
#import "CNLiveHTTPProxyService.h"
#import "CNLiveFileDownloader.h"
#import "CNLiveCacheDefines.h"
#import "CNLiveBarrageAnimationView.h"

@interface CNLiveWebcastManager : NSObject
//version  2.2.0

+ (CNLiveWebcastManager *)manager;

/**
 *  应用ID（只读）
 */
@property (nonatomic, readonly) NSString *appId;

/**
 *  应用KEY（只读）
 */
@property (nonatomic, readonly) NSString *appKey;

/**
 *  是否是测试环境
 */
@property (nonatomic, readonly) BOOL isTestEnvironment;

/**
 *  用户ID
 */
@property (nonatomic ,copy) NSString *userId;

/**
 *  ChannelName 网++定制
 */
@property (nonatomic ,copy) NSString *channelName;

/**
 *  tag 网++定制
 */
@property (nonatomic ,copy) NSString *tag;

/**
 *  from 网++定制
 */
@property (nonatomic ,copy) NSString *from;

/**
 @abstract      初始化直播云SDK(该方法默认正式环境)
 @param         appId              在open.cnlive.com网站申请得到的appId
 @param         appKey             在open.cnlive.com网站申请得到的appKey
 @warning       必传参数
 */
- (void)initWithAppId:(NSString *)appId appKey:(NSString *)appKey;

/**
 @abstract      初始化直播云SDK
 @param         appId              在open.cnlive.com网站申请得到的appId
 @param         appKey             在open.cnlive.com网站申请得到的appKey
 @param         isTestEnvironment  YES:测试环境  NO:正式环境
 @warning       必传参数
 */
- (void)initWithAppId:(NSString *)appId appKey:(NSString *)appKey isTestEnvironment:(BOOL)isTestEnvironment;

/**
 @abstract      获取版本号
 */
+ (NSString *)getVersion;


@end
