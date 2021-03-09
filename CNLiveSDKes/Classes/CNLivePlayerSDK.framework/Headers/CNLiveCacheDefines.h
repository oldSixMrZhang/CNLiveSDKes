//
//  CNLiveCacheDefines.h
//  CNLivePlayerSDKDemo
//
//  Created by iOS on 2017/10/24.
//  Copyright © 2017年 雷浩杰. All rights reserved.
//

#ifndef CNLiveCacheDefines_h
#define CNLiveCacheDefines_h

extern NSString *CacheStatusNotification;       //缓存状态通知
extern NSString *CacheErrorNotification;        //缓存异常通知
extern NSString *closePlayerNotification;       //关闭播放器通知
extern NSString *OpenPlayerNotification;        //开启播放器通知

extern NSString *CacheURLKey;                   //获取视频地址key
extern NSString *CacheFragmentsKey;
extern NSString *CacheContentLengthKey;
extern NSString *CacheFilePathKey;
extern NSString *CacheProgressKey;
extern NSString *ClosePlayerURLKey;

extern NSString *CacheErrorCodeKey;             //获取errorcode key

extern NSString *CacheSDKVersion;               //当前CNLiveHTTPCacheSDK版本号

/**
 * 错误码
 */
typedef NS_ENUM(NSInteger, CNLiveHTTPCacheErrorCode) {
    CNLiveOK                    = 0,
    CNLiveUnknownError          = 1,
    
    //cache
    CNLiveOpenCacheError        = 1001,
    CNLiveReadCacheError        = 1002,
    CNLiveWriteCacheError       = 1003,
    CNLiveCloseCacheError       = 1004,
    CNLiveDeleteCacheError      = 1005,
    CNLiveSaveConfigError       = 1006,
    
    //source
    CNLiveHeadRequestError      = 2001,
    CNLiveHTTPDownloadError     = 2002,
    
    //server
    CNLiveStartServerError      = 3001, // failed to start local http server
    CNLiveInvalidRequestError   = 3002, //malformed HTTP request
    CNLiveUnknowHTTPMethodError = 3003, //a HTTP request with a method other than GET or HEAD
};

typedef NS_ENUM(NSInteger, CNLiveCacheStrategy) {
    CNLiveMaxCacheSizeLimited    = 0,
    CNLiveMaxFilesCountLimited    = 1,
};

/**
 * 缓存任务的类型
 */
typedef NS_ENUM(NSInteger, CNLiveCacheTaskType) {
    CNLiveCacheTaskTypeHttpServer        = 0,       // HttpServer发起的任务
    CNLiveCacheTaskTypeFileDownloader    = 1,       // FileDownloader发起的任务
};

/**
 * FileDownloader任务状态
 */
typedef NS_ENUM(NSInteger, CNLiveFileDownloaderState) {
    CNLiveFileDownloaderStateUnknown      = 0,      //未知
    CNLiveFileDownloaderStatePause,                 //暂停
    CNLiveFileDownloaderStateDownloading,           //下载中
    CNLiveFileDownloaderStateInvalid,               //无效
    CNLiveFileDownloaderStateFinished               //完成
};


#endif /* CNLiveCacheDefines_h */
