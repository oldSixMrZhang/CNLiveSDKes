//
//  CNLiveTypeDef.h
//  CNLiveLiveDemo
//
//  Created by Android on 16/8/3.
//  Copyright © 2016年 Android. All rights reserved.
//

#ifndef CNLiveTypeDef_h
#define CNLiveTypeDef_h

#pragma mark - Video Dimension

/// 采集分辨率（弃用）
typedef NS_ENUM(NSUInteger, CNLiveVideoDimension) {
    /// 16 : 9 宽高比，1280 x 720 分辨率
    CNLiveVideoDimension_16_9__1280x720 = 0,
    /// 16 : 9 宽高比，960 x 540 分辨率
    CNLiveVideoDimension_16_9__960x540,
    /// 4 : 3 宽高比，640 x 480 分辨率
    CNLiveVideoDimension_4_3__640x480,
    /// 16 : 9 宽高比，640 x 360 分辨率
    CNLiveVideoDimension_16_9__640x360,
    /// 4 : 3 宽高比，320 x 240 分辨率
    CNLiveVideoDimension_5_4__352x288,
    
    /// 缩放自定义分辨率 从设备支持的最近分辨率缩放获得, 若设备没有对应宽高比的分辨率，则裁剪后进行缩放
    CNLiveVideoDimension_UserDefine_Scale,
    /// 裁剪自定义分辨率 从设备支持的最近分辨率裁剪获得
    CNLiveVideoDimension_UserDefine_Crop,
    /// 注意： 选择缩放自定义分辨率时可能会有额外CPU代价
    
    /// 默认分辨率，默认为 4 : 3 宽高比，640 x 480 分辨率
    CNLiveVideoDimension_Default = CNLiveVideoDimension_4_3__640x480,
};


#pragma mark - Video Codec ID
/*!
 * @abstract  视频编码器类型
 */
typedef NS_ENUM(NSUInteger, CNLiveVideoCodec) {
    /// 视频编码器 - h264 软件编码器
    CNLiveVideoCodec_X264 = 0,
    /// 视频编码器 - CNLive265 软件编码器
    CNLiveVideoCodec_QY265,
    /// 视频编码器 - iOS VT264硬件编码器 (iOS 8.0以上支持)
    CNLiveVideoCodec_VT264,
    /// 视频编码器 - iOS VT265硬件编码器 (iOS 11.0 以上)
    CNLiveVideoCodec_VT265,
    /// 视频编码器 - 由SDK自动选择（ VT264 > X264）
    CNLiveVideoCodec_AUTO = 100,
    /// 视频编码器 - gif
    CNLiveVideoCodec_GIF,
};

/*!
 * @abstract  音频编码器类型
 */
typedef NS_ENUM(NSUInteger, CNLiveAudioCodec) {
    /// aac音频软件编码器 - AAC_HE
    CNLiveAudioCodec_AAC_HE = 0,
    /// aac音频软件编码器 - AAC_LC
    CNLiveAudioCodec_AAC,
    /// iOS自带的audiotoolbox音频编码器 - AAC_LC (CPU占用较低,但推荐码率:64kbps单声道,128kbps双声道)
    CNLiveAudioCodec_AT_AAC,
    /// aac软件编码器 - AAC_HE_V2 (仅双声道音频可用;如果输入数据为单声道,则自动退化为 AAC_HE)
    CNLiveAudioCodec_AAC_HE_V2,
};

/*!
 * @abstract  网络自适应模式类型
 */
typedef NS_ENUM(NSUInteger, CNLiveBWEstimateMode) {
    /// 默认模式 (综合模式,比较平稳)
    CNLiveBWEstMode_Default = 0,
    /// 流畅优先模式(消极上调, 极速下调)
    CNLiveBWEstMode_Negtive,
    
    /// 禁用网络自适应网络调整
    CNLiveBWEstMode_Disable = 1000,
};

/// 直播场景 (CNLive内部会根据场景的特征进行参数调优)
typedef NS_ENUM(NSUInteger, CNLiveLiveScene) {
    /// 默认通用场景(不确定场景时使用)
    CNLiveLiveScene_Default = 0,
    /// 秀场场景, 主播上半身为主
    CNLiveLiveScene_Showself,
    /// 游戏场景
    CNLiveLiveScene_Game,
    // others comming soon
};

/// 录制场景
typedef NS_ENUM(NSUInteger, CNLiveRecScene) {
    /// 恒定码率场景
    CNLiveRecScene_ConstantBitRate = 0,
    /// 恒定质量场景
    CNLiveRecScene_ConstantQuality,
};

/// 视频编码性能档次 (视频质量 和 设备资源之间的权衡)
typedef NS_ENUM(NSUInteger, CNLiveVideoEncodePerformance) {
    /// 低功耗:  cpu资源消耗低一些,视频质量差一些
    CNLiveVideoEncodePer_LowPower= 0,
    /// 均衡档次: 性价比比较高
    CNLiveVideoEncodePer_Balance,
    /// 高性能: 画面质量高
    CNLiveVideoEncodePer_HighPerformance,
};

#pragma mark - QYPublisher State

/*!
 * @abstract  采集设备状态
 */
typedef NS_ENUM(NSUInteger, CNLiveCaptureState) {
    /// 设备空闲中
    CNLiveCaptureStateIdle,
    /// 设备工作中
    CNLiveCaptureStateCapturing,
    /// 设备授权被拒绝
    CNLiveCaptureStateDevAuthDenied,
    /// 关闭采集设备中
    CNLiveCaptureStateClosingCapture,
    /// 参数错误，无法打开（比如设置的分辨率，码率当前设备不支持）
    CNLiveCaptureStateParameterError,
    /// 设备正忙，请稍后尝试 ( 该状态在发出通知0.5秒后被清除 ）
    CNLiveCaptureStateDevBusy,
};

/*!
 * @abstract  推流状态
 */
typedef NS_ENUM(NSUInteger, CNLiveStreamState) {
    /// 初始化时状态为空闲
    CNLiveStreamStateIdle = 0,
    /// 连接中
    CNLiveStreamStateConnecting,
    /// 已连接
    CNLiveStreamStateConnected,
    /// 断开连接中
    CNLiveStreamStateDisconnecting,
    /// 推流出错
    CNLiveStreamStateError,
    /// 结束推流成功
    CNLiveStopStreamSuccess,
    /// 结束推流失败
    CNLiveStopStreamFailure,
};

/*!
 * @abstract  推流错误码，用于指示推流失败的原因
 */
typedef NS_ENUM(NSUInteger, CNLiveStreamErrorCode) {
    /// 正常无错误
    CNLiveStreamErrorCode_NONE = 0,
    /// (obsolete)
    CNLiveStreamErrorCode_CNLiveAUTHFAILED __deprecated_enum_msg("auth removed"),
    /// 当前帧编码失败
    CNLiveStreamErrorCode_ENCODE_FRAMES_FAILED,
    /// 无法打开配置指示的CODEC
    CNLiveStreamErrorCode_CODEC_OPEN_FAILED,
    /// 连接出错，检查地址
    CNLiveStreamErrorCode_CONNECT_FAILED,
    /// 网络连接中断
    CNLiveStreamErrorCode_CONNECT_BREAK = 5,
    /// rtmp 推流域名不存在 (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_NonExistDomain,
    /// rtmp 应用名不存在(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_NonExistApplication,
    /// rtmp 流名已存在(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_AlreadyExistStreamName,
    /// rtmp 被黑名单拒绝(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_ForbiddenByBlacklist,
    /// rtmp 内部错误(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_InternalError = 10,
    /// rtmp URL 地址已过期(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_URLExpired,
    /// rtmp URL 地址签名错误(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_SignatureDoesNotMatch,
    /// rtmp URL 中AccessKeyId非法(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_InvalidAccessKeyId,
    /// rtmp URL 中参数错误(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_BadParams,
    /// rtmp URL 中的推流不在发布点内（CNLive 自定义）
    CNLiveStreamErrorCode_RTMP_ForbiddenByRegion = 15,
    /// (obsolete)
    CNLiveStreamErrorCode_FRAMES_THRESHOLD,
    /// (obsolete)
    CNLiveStreamErrorCode_NO_INPUT_SAMPLE,
    /// 对于URL中的域名解析失败
    CNLiveStreamErrorCode_DNS_Parse_failed,
    /// 对于URL对应的服务器连接失败(无法建立TCP连接)
    CNLiveStreamErrorCode_Connect_Server_failed,
    /// 跟RTMP服务器完成握手后,向{appname}/{streamname} 推流失败
    CNLiveStreamErrorCode_RTMP_Publish_failed = 20,
    /// 音视频同步失败 (输入的音频和视频的时间戳的差值超过5s)
    CNLiveStreamErrorCode_AV_SYNC_ERROR,
    /// 非法地址(地址为空或url中的协议或本地文件的后缀SDK不支持, 请检查)
    CNLiveStreamErrorCode_INVALID_ADDRESS,
    /// 网络不通
    CNLiveStreamErrorCode_NETWORK_UNREACHABLE,
    /// 获取user id失败 (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_GetUserIdFailed,
    /// AK和user id不匹配 (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_AkAndUserIsNotMatch = 25,
    /// 获取服务器信息失败 (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_GetServerInfoFailed,
    /// 非法的外部url (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_IllegalOutsideUrl,
    /// 外部鉴权失败 (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_OutsideAuthFailed,
    /// 简单鉴权失败(CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_SimpleAuthFailed,
    /// 无效的鉴权类型 (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_InvalidAuthType = 30,
    /// 非法的user id (CNLive 自定义)
    CNLiveStreamErrorCode_RTMP_IllegalUserId,
    /// 异常
    CNLiveStreamErrorCode_ABNORMAL,

};

#pragma mark - 美颜
typedef NS_ENUM(NSUInteger, CNLiveReconnectStatus) {
    CNLiveReconnectStatusStart = 0,
    CNLiveReconnectStatusSuccess,
    CNLiveReconnectStatusFailed
};

#pragma mark - 美颜

typedef NS_ENUM(NSUInteger, CNLiveBeautyType) {
    ///无
    CNLiveBeautyTypeNone = 0,
    ///旧美颜
    CNLiveBeautyTypeOld,
    ///红润美颜
    CNLiveBeautyTypeRuddy,
    ///美颜特效
    CNLiveBeautyTypeSpecial
};

typedef NS_ENUM(NSUInteger, CNLiveSpecialEffects) {
    ///小清新
    CNLiveSpecialEffectsFresh = 0,
    ///靓丽
    CNLiveSpecialEffectsPretty,
    ///甜美可人
    CNLiveSpecialEffectsSweet,
    ///怀旧
    CNLiveSpecialEffectsNostalgia,
    ///蓝调
    CNLiveSpecialEffectsBlues,
    ///老照片
    CNLiveSpecialEffectsOldPicture,
    ///樱花
    CNLiveSpecialEffectsCherry,
    ///樱花（光线较暗）
    CNLiveSpecialEffectsCherryDark,
    ///红润（光线较暗）
    CNLiveSpecialEffectsRuddyDark,
    ///阳光（光线较暗）
    CNLiveSpecialEffectsSunlightDark,
    ///红润
    CNLiveSpecialEffectsRuddy,
    ///阳光
    CNLiveSpecialEffectsSunlight,
    ///自然
    CNLiveSpecialEffectsNature
};

#pragma mark - 音频播放状态
typedef NS_ENUM(NSUInteger, CNLiveBgmPlayerState) {
    /// 初始状态
    CNLiveBgmPlayerStateInit,
    /// 背景音正在播放
    CNLiveBgmPlayerStateStarting,
    /// 背景音停止
    CNLiveBgmPlayerStateStopped,
    /// 背景音正在播放
    CNLiveBgmPlayerStatePlaying,
    /// 背景音暂停
    CNLiveBgmPlayerStatePaused,
    /// 背景音播放出错
    CNLiveBgmPlayerStateError,
    /// 背景音被打断
    CNLiveBgmPlayerStateInterrupted
};

#pragma mark - 旁路录制
/*!
 * @abstract  旁路录制状态
 */
typedef NS_ENUM(NSInteger, CNLiveRecordState) {
    /// 初始状态
    CNLiveRecordStateIdle,
    /// 录像中
    CNLiveRecordStateRecording,
    /// 录像停止
    CNLiveRecordStateStopped,
    /// 录像失败
    CNLiveRecordStateError,
};

/*!
 * @abstract  旁路录制错误码
 */
typedef NS_ENUM(NSInteger, CNLiveRecordError) {
    /// 无错误
    CNLiveRecordErrorNone,
    /// 地址错误
    CNLiveRecordErrorPathInvalid,
    /// 格式不支持
    CNLiveRecordErrorFormatNotSupport,
    /// 内部错误
    CNLiveRecordErrorInternal,
};


#pragma mark - player
/**
 * 视频解码模式
 */
typedef NS_ENUM(NSUInteger, CNLiveMovieVideoDecoderMode) {
    ///视频解码方式采用软解
    CNLiveMovieVideoDecoderMode_Software = 0,
    ///视频解码方式采用硬解
    CNLiveMovieVideoDecoderMode_Hardware,
    ///自动选择解码方式，8.0以上的系统优先选择硬解
    CNLiveMovieVideoDecoderMode_AUTO,
    ///使用系统接口进行解码和渲染，只适用于8.0及以上系统，低于8.0的系统自动使用软解
    CNLiveMovieVideoDecoderMode_DisplayLayer,
};

/**
 *  主播直播状态
 */
typedef NS_ENUM(NSUInteger, CNLiveAnchorStatus) {
    ///主播直播中
    CNLiveAnchorStatusLiving = 0,
    ///主播已离开
    CNLiveAnchorStatusLeaving,
    ///直播已结束
    CNLiveAnchorStatusEnd,
};

/**
 *  播放时网络状态
 */
typedef NS_ENUM(NSInteger, CNLiveNetworkStatus) {
    CNLiveNotReachable = 0,
    CNLiveReachableViaWiFi = 2,
    CNLiveReachableViaWWAN = 1
};

#endif /* CNLiveTypeDef_h */
