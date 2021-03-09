//
//  CNLiveFileDownloader.h
//  CNLivePlayerSDKDemo
//
//  Created by iOS on 2017/10/24.
//  Copyright © 2017年 雷浩杰. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveCacheDefines.h"

/** 视频下载器，一个视频文件对应一个下载器，用于开播前预先缓存视频 目前只支持mp4格式**/

@interface CNLiveFileDownloader : NSObject

/**
 * 初始化下载器
 * @param urlString      视频原始地址（未经过代理处理的）
 * @param progressBlock  视频缓存进度回调
 */
- (instancetype)initWithUrlString:(NSString *)urlString
                    progressBlock:(void(^)(float progress))progressBlock;

/**
 * 开始缓存
 */
- (void)startDownload;

/**
 * 暂停缓存
 */
- (void)pauseDownload;

/**
 * 当前缓存的url
 */
- (NSString *)urlString;

/**
 * 获取视频缓存状态
 */
- (CNLiveFileDownloaderState)downloaderState;

/**
 * 播放地址为url的视频时，调用此方法
 */
+ (void)handleOpenPlayerForUrl:(NSString *)url
                 progressBlock:(void(^)(float progress))progressBlock;

/**
 * 停止播放地址为url的视频时，调用此方法
 */
+ (void)handleClosePlayerForUrl:(NSString *)url
                  progressBlock:(void(^)(float progress))progressBlock;

@end
