//
//  CNLiveStreamerBase.h
//  CNLivePlayerSDKDemo
//
//  Created by iOS on 17/2/27.
//  Copyright © 2017年 雷浩杰. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveTypeDef.h"
#import <UIKit/UIKit.h>

@interface CNLiveStreamerBase : NSObject

/**
 @abstract   视频帧率 默认:15
 @discussion 当实际送入的视频帧率过高时会主动丢帧,有效范围[1~30]
 */
@property (nonatomic, assign) int           videoFPS;

/**
 @abstract   视频帧率最小值，默认与videoFPS相同
 @discussion video frame per seconds 有效范围[1~30], 超出会提示参数错误
 @discussion 不设置该值时表示网络自适应不使用动态帧率
 */
@property (nonatomic, assign) int           videoMinFPS;

/**
 @abstract   视频帧率最大值，默认与videoFPS相同
 @discussion video frame per seconds 有效范围[1~30], 超出会提示参数错误
 @discussion 不设置该值时表示网络自适应不使用动态帧率
 */
@property (nonatomic, assign) int           videoMaxFPS;

/**
 @abstract      视频编码器
 @discussion    video codec used for encode
 */
@property (nonatomic, assign) CNLiveVideoCodec videoCodec;

/**
 @abstract   音频编码器 (默认为AAC-HE)
 @discussion audio codec used for encode
 @see        KSYAudioCodec
 */
@property (nonatomic, assign) CNLiveAudioCodec audioCodec;

/**
 @abstract      视频编码起始码率（单位:kbps）
 @discussion    开始推流时的视频码率，开始推流后，根据网络情况在 [Min, Max]范围内调节
 @discussion    视频码率上调则画面更清晰，下调则画面更模糊
 */
@property (nonatomic, assign) int          videoInitBitrate;   // kbit/s of video

/**
 @abstract      视频编码最高码率（单位:kbps）
 @discussion    视频码率自适应调整的上限, 为目标码率
 */
@property (nonatomic, assign) int          videoMaxBitrate;   // kbit/s of video

/**
 @abstract      视频编码最低码率（单位:kbps）
 @discussion    视频码率自适应调整的下限
 */
@property (nonatomic, assign) int          videoMinBitrate;   // kbit/s of video

/**
 @abstract   质量等级（默认:20）
 @discussion 视频恒定质量等级，范围0～51，值越小，质量越好
 */
@property (nonatomic, assign) int          videoCrf;

/**
 @abstract      最大关键帧间隔（单位:秒, 默认:3）
 @discussion    即GOP长度 画面静止时,隔n秒插入一个关键帧
 */
@property (nonatomic, assign) float          maxKeyInterval;   // seconds

/**
 @abstract      音频编码码率（单位:kbps）
 @discussion    音频目标编码码率 (比如48,96,128等)
 */
@property (nonatomic, assign) int          audiokBPS;   // kbit/s of audio

/**
 @abstract   带宽估计模式
 @discussion 带宽估计的策略选择 (开始推流前设置有效)
 */
@property (nonatomic, assign) CNLiveBWEstimateMode bwEstimateMode;

/**
 @abstract   本次直播的目标场景 (默认为KSYLiveScene_Default)
 @discussion KSY内部会根据场景的特征进行参数调优,开始推流前设置有效
 */
@property (nonatomic, assign) CNLiveLiveScene              liveScene;

/**
 @abstract   本次录制的目标场景 (默认为KSYRecScene_ConstantBitRate)
 @discussion 开始录制前设置有效
 */
@property (nonatomic, assign) CNLiveRecScene              recScene;

/**
 @abstract   视频编码性能档次 ( 默认为 CNLiveVideoEncodePer_LowPower)
 @discussion 视频质量和设备资源之间的权衡,开始推流前设置有效
 */
@property (nonatomic, assign) CNLiveVideoEncodePerformance videoEncodePerf;

/**
 @abstract   查询当前是否处于推流状态 (建立连接中, 或连接中)
 */
- (BOOL) isStreaming;

/**
 @abstract  静音推流 (仍然有音频输出发送, 只是音量为0)
 @param     bMute YES / ON
 */
- (void)muteStream:(BOOL)bMute;

/**
 @abstract 截图功能，目前只支持jpg格式
 @param    jpegCompressionQuality 设置图像的压缩比例
 @param    filename 图片的文件名
 */
- (void)takePhotoWithQuality:(CGFloat)jpegCompressionQuality
                     fileName:(NSString *)filename;

/**
 @abstract 获取当前编码的截图
 @param    completion 通过完成代码块获取到截图完成的图像
 */
- (void)getSnapshotWithCompletion:(void (^)(UIImage*))completion;

#pragma mark - 旁路录制
/**
 @abstract   旁路录像地址
 @discussion 开始录像后, 将直播的内容同步存储一份到本地文件
 eg: /private/var/mobile/Containers/Data/Application/APPID/tmp/test.mp4
 @discussion 如果只要存储本地文件,请继续使用原来的startStream接口
 @see hostURL, startStream
 */
@property (nonatomic, readonly) NSURL* bypassRecordURL;

/**
   @abstract 启动旁路录像
   @param      url    本地录像文件地址:/private/var/..../test.mp4
   @return     是否能尝试启动写入, 不能表明真正开始录像了,真正开始请确认bypassRecordState的值
   @discussion 启动推流后才能开始写入文件，使用时请注意录制时长，避免内存不够
   @discussion 文件中的内容和直播内容完全一致
   */
- (BOOL)startBypassRecord:(NSURL *)url;

/**
 @abstract 停止旁路录像
 */
- (void)stopBypassRecord;

/** 旁路录像的文件时长 */
@property (nonatomic, readonly) double bypassRecordDuration;

/** 旁路录像的状态 */
@property (nonatomic, readonly) CNLiveRecordState bypassRecordState;

/** 旁路录像的错误码 */
@property (nonatomic, readonly) CNLiveRecordError bypassRecordErrorCode;

/** 旁路录像的错误名称 */
@property (nonatomic, readonly) NSString* bypassRecordErrorName;

/**
 @abstract   当旁路录制的状态变化时
 @discussion 只有设置 loop为NO时才有效, 在开始播放前设置有效
 */
@property(nonatomic, copy) void(^bypassRecordStateChange)(CNLiveRecordState recordState);


@end
