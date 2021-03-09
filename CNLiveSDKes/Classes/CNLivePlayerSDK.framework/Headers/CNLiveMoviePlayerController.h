//
//  CNLiveMoviePlayerController.h
//  0.3.3.7.1  版本
//  Created by CNLive on 16/8/5.
//  Copyright © 2016年 CNLive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import "CNLiveTypeDef.h"

#import <libksygpulive/KSYMoviePlayerController.h>
@interface CNLiveMoviePlayerController : NSObject

/** KS3Player */
@property (nonatomic, strong) KSYMoviePlayerController *player;

#pragma mark - 视频
#pragma mark - 使用视讯云平台 直接通过节目id播放
/* 初始化点播播放器  初始化成功后才能对播放器进行设置（如：自动播放、是否开启硬件解码等）和调用准备播放视频方法（prepareToPlay）
 *
 * 当前版本只支持单实例的CNLiveMoviePlayerController对象，多实例将导致播放异常
 *
 * vId               点播视频Id
 * authSuccess       初始化成功block
 * authFailed        初始化失败block 回调一个errorInfo的字典
 *
 */
- (instancetype)initVodPlayWithVId:(NSString *)vId
                         authSuccess:(void(^)(void))authSuccessBlock
                          authFailed:(void(^)(NSDictionary *errorInfo))authFailedBlock;

/* 初始化直播播放器(* 以channelId播放)  初始化成功后才能对播放器进行设置（如：自动播放、是否开启硬件解码等）和调用准备播放视频方法（prepareToPlay）
 *
 * 当前版本只支持单实例的CNLiveMoviePlayerController对象，多实例将导致播放异常
 *
 * channelId         直播视频Id
 * agree             是否允许获取主播状态 YES：获取 NO：不获取
 * authSuccess       初始化成功block
 * authFailed        初始化失败block 回调一个errorInfo的字典
 *
 * result            获取主播状态 YES：获取状态成功 
 *                               NO：获取失败，不影响视频播放，但是获取不到主播离开、回来、直播结束等通知。可通过
 * - (void)retryToGetAnchorStatusResult:(void(^)(BOOL result))result；方法重新获取
 */
- (instancetype)initLivePlayWithChannelId:(NSString *)channelId
                             anchorStatus:(BOOL)agree
                              authSuccess:(void(^)(void))authSuccessBlock
                               authFailed:(void(^)(NSDictionary *errorInfo))authFailedBlock
                    getAnchorStatusResult:(void(^)(BOOL result))result;


/* 初始化直播播放器(* 以channelId播放)  初始化成功后才能对播放器进行设置（如：自动播放、是否开启硬件解码等）和调用准备播放视频方法（prepareToPlay）
 *
 * 当前版本只支持单实例的CNLiveMoviePlayerController对象，多实例将导致播放异常
 *
 * channelId         直播视频Id (注* 若agree为YES时，必传，用于获取主播状态； 若agree为NO，可不传)
 * activityId        活动Id
 * agree             是否允许获取主播状态 YES：获取 NO：不获取
 * authSuccess       初始化成功block
 * authFailed        初始化失败block 回调一个errorInfo的字典
 *
 * result            获取主播状态 YES：获取状态成功
 *                               NO：获取失败，不影响视频播放，但是获取不到主播离开、回来、直播结束等通知。可通过
 * - (void)retryToGetAnchorStatusResult:(void(^)(BOOL result))result；方法重新获取
 */
- (instancetype)initLivePlayWithChannelId:(NSString *)channelId
                               activityId:(NSString *)activityId
                             anchorStatus:(BOOL)agree
                              authSuccess:(void(^)(void))authSuccessBlock
                               authFailed:(void(^)(NSDictionary *errorInfo))authFailedBlock
                    getAnchorStatusResult:(void(^)(BOOL result))result;

#pragma mark - 音频
#pragma mark - 使用视讯云平台 直接通过节目id播放音频
/* 初始化点播播放器  初始化成功后才能对播放器进行设置（如：自动播放、是否开启硬件解码等）和调用准备播放视频方法（prepareToPlay）
 *
 * 当前版本只支持单实例的CNLiveMoviePlayerController对象，多实例将导致播放异常
 *
 * vId               点播音频Id
 * authSuccess       初始化成功block
 * authFailed        初始化失败block 回调一个errorInfo的字典
 *
 */
- (instancetype)initAudioVodPlayWithVId:(NSString *)vId
                       authSuccess:(void(^)(void))authSuccessBlock
                        authFailed:(void(^)(NSDictionary *errorInfo))authFailedBlock;

/* 初始化直播播放器(* 以channelId播放)  初始化成功后才能对播放器进行设置（如：自动播放、是否开启硬件解码等）和调用准备播放视频方法（prepareToPlay）
 *
 * 当前版本只支持单实例的CNLiveMoviePlayerController对象，多实例将导致播放异常
 *
 * channelId         直播视频Id (注* 若agree为YES时，必传，用于获取主播状态； 若agree为NO，可不传)
 * activityId        活动Id
 * agree             是否允许获取主播状态 YES：获取 NO：不获取
 * authSuccess       初始化成功block
 * authFailed        初始化失败block 回调一个errorInfo的字典
 *
 * result            获取主播状态 YES：获取状态成功
 *                               NO：获取失败，不影响视频播放，但是获取不到主播离开、回来、直播结束等通知。可通过
 * - (void)retryToGetAnchorStatusResult:(void(^)(BOOL result))result；方法重新获取
 */
- (instancetype)initAudioLivePlayWithChannelId:(NSString *)channelId
                               activityId:(NSString *)activityId
                             anchorStatus:(BOOL)agree
                              authSuccess:(void(^)(void))authSuccessBlock
                               authFailed:(void(^)(NSDictionary *errorInfo))authFailedBlock
                    getAnchorStatusResult:(void(^)(BOOL result))result;

/*
 * 是否开启控制台输出日志（默认YES）
 */
@property (nonatomic, assign) BOOL logPrintEnable;

/* 切换视角和码率
 *
 * 调用此方法会获取视频的不同视角或码率，并重新加载视频（获取视频的不同视角或码率需要一定的时间，在这段时间内，播放器不会停止播放，建议将播放器设为暂停状态(pause)，并展示加载视频时的UI）
 *
 * channelId        直播视频Id（同一视角可不传）
 * rate             清晰度(1:流畅、2:标清(默认)、3:高清、4:超清)
 *
 */
- (void)changeViewWithChannelId:(NSString *)channelId rate:(NSString *)rate;

///**
// 无缝切换码率,初始化新播放器加载新码率
//
// @param rate 新码率
// */
//- (void)initSeamlessPlayerWithRate:(NSString *)rate;

/* 切换视频源
 *
 * 当视频不够流畅时可调用此方法
 * 调用此方法会获取不同的视频源，并重新加载视频（获取其他视频源需要一定的时间，在这段时间内，播放器不会停止播放，建议将播放器设为暂停状态(pause)，并展示加载视频时的UI）
 *
 */
- (void)retry;

/* 重新获取主播直播状态
 *
 * result    重新获取主播直播状态,YES:成功 NO:失败
 *
 */
- (void)retryToGetAnchorStatusResult:(void(^)(BOOL result))result;

/**
 *  销毁播放器
 */
- (void)destroyPlayer;

/* 主播直播状态(只读)
 *
 */
@property (nonatomic, assign, readonly) CNLiveAnchorStatus anchorStatus;

/*
 *  主播直播状态改变通知
 */
FOUNDATION_EXPORT NSString *const CNLiveAnchorStatusChangedNotification NS_AVAILABLE_IOS(7_0);

#pragma mark - 普通播放器方法
/*
 * 初始化播放器并设置播放地址
 */
- (instancetype)initWithContentURL:(NSURL *)url;

/* 解码方式（硬解/软解/自动/使用系统接口进行解码和渲染）
 *
 * 建议系统版本高于8.0 选择硬解，或者自动选择解码方式，8.0以上的系统优先选择硬解
 * 只在[prepareToPlay]调用前设置生效
 *
 */
@property(nonatomic) CNLiveMovieVideoDecoderMode videoDecoderMode;

/**
 @abstract 是否静音
 @discussion
 * 默认不静音
 * [prepareToPlay]方法前设置即生效，也可以在播放过程中动态切换
 */
@property(nonatomic) BOOL shouldMute;

/**
 @abstract 是否循环播放
 @discussion 默认不循环
 * 只在[prepareToPlay]调用前设置生效；
 * 只有点播生效,直播场景请勿设置
 */
@property(nonatomic) BOOL shouldLoop;

/**
 @abstract 指定逆时针旋转角度，只能是0/90/180/270, 不符合上述值不进行旋转
 */
@property (nonatomic, assign) int rotateDegress;

/**
 @abstract 是否打断其他后台的音乐播放
 @discussion 也可以理解为是否允许和其他音频同时播放
 @discussion YES:开始播放时，会打断其他的后台播放音频，也会被其他音频播放打断
 @discussion NO: 可以与其他后台播放共存，相互之间不会被打断
 @discussion 默认为YES
 */
@property(nonatomic) BOOL  bInterruptOtherAudio;

/* 重新启动拉流
 *
 * url 视频播放地址，该地址可以是本地地址或者服务器地址.如果为nil，则使用前一次播放地址
 *
 */
- (void)reload:(NSURL *)aUrl;

/**
 * timeout指定拉流超时时间,单位是秒
 * prepareTimeout 建立链接超时时间，默认值是10秒
 * readTimeout 拉流超时时间，默认值是30秒
 */
- (void)setTimeout:(int)prepareTimeout readTimeout:(int)readTimeout;

/*
 * 播放视频时是否需要自动播放，默认值为YES
 */
@property (nonatomic) BOOL shouldAutoplay;

/* 准备视频播放
 *
 * MPMediaPlaybackIsPreparedToPlayDidChangeNotification， 播放器完成对视频文件的初始化时发送通知
 *
 */
- (void)prepareToPlay;

/*
 * 查询视频准备是否完成（只读）
 */
@property(nonatomic, readonly) BOOL isPreparedToPlay;

// Posted when the prepared state changes of an object conforming to the MPMediaPlayback protocol changes.
// This supersedes MPMoviePlayerContentPreloadDidFinishNotification.
MP_EXTERN NSString *const MPMediaPlaybackIsPreparedToPlayDidChangeNotification NS_DEPRECATED_IOS(3_2, 9_0);

/*
 * 播放当前视频
 */
- (void)play;

/* 暂停播放当前视频
 *
 * 播放器内部监听了UIApplicationWillEnterForegroundNotification通知，该通知发生时如果视频仍然在播放，将自动调用pause暂停当前视频播放
 *
 * 需要APP有后台执行权限，在工程Info.plist中添加后台运行模式，设置为audio。具体是添加UIBackgroundModes项，值为audio
 * 当用户点击home按钮后，播放器进入后台继续读取数据并播放音频
 * 当APP回到前台后，音频继续播放。图像渲染内容保持和音频同步
 * 如果在开启后台运行模式后，需要切换后台暂停，需要监听相关事件并主动调用pause操作
 *
 */
- (void)pause;

/* 结束当前视频的播放
 *
 * 重复多次调用将会导致崩溃
 * 调用stop结束当前播放，如果需要重新播放该视频，需要调用[prepareToPlay]([KSYMediaPlayback prepareToPlay])方法
 * 调用stop方法后，播放器开始进入关闭当前播放的操作，操作完成将发送MPMoviePlayerPlaybackDidFinishNotification通知
 *
 * MPMoviePlayerPlaybackDidFinishNotification， 当播放完成将发送该通知
 *
 */
- (void)stop;

/*
 * 当前播放器是否在播放
 */
- (BOOL)isPlaying;

/*
 * 指定播放器输出音量
 * leftVolume  left volume scalar  [0~2.0f]
 * rightVolume right volume scalar [0~2.0f]
 * 输入参数超出范围将失效
*/
-(void)setVolume:(float)leftVolume rigthVolume:(float)rightVolume;

/* 播放视频的当前时刻，单位为秒
 *
 * 视频正常播放时，如果改变currentPlaybackTime的值，将导致播放行为跳转到新的currentPlaybackTime位置播放
 * 如果在视频未播放前设置currentPlaybackTime的值，将导致播放时刻从currentPlaybackTime位置播放
 *
 */
@property(nonatomic) NSTimeInterval currentPlaybackTime;

/**
 @abstract 跳转到指定位置播放
 @param pos 跳转到的位置，单位秒
 @param isAccurate 是否精确跳转，NO时等同于currentPlaybackTime, YES时为精确跳转
 @discussion 媒体文件总时长较小且关键帧间隔较大时，需要使用精确跳转， 总时长较大或者不需要精确定位时可以使用currentPlaybackTime或者将isAccurate设置为NO进行跳转
 */
- (void)seekTo:(double)pos accurate:(BOOL)isAccurate;

/*
 * 当前视频总时长（只读），单位是秒
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/* 当前视频可播放长度（只读），单位是秒
 *
 * currentPlaybackTime 标记的是播放器当前已播放的时长。
 * playableDuration 标记的是播放器缓冲的时间，会稍大于currentPlaybackTime，与currentPlaybackTime的差值则是缓冲长度。
 *
 */
@property (nonatomic, readonly) NSTimeInterval playableDuration;

/* 包含视频播放内容的VIEW（只读）
 *
 * 可以通过frame设置view大大小
 * 使用[scalingMode]可以更改视频内容在VIEW中的显示情况
 *
 */
@property (nonatomic, readonly) UIView *view;

/* 当前播放器的播放状态（只读）
 *
 * MPMoviePlaybackStateStopped,           // 播放停止
 * MPMoviePlaybackStatePlaying,           // 正在播放
 * MPMoviePlaybackStatePaused,            // 播放暂停
 * MPMoviePlaybackStateInterrupted,       // 播放被打断
 * MPMoviePlaybackStateSeekingForward,    // 向前seeking中
 * MPMoviePlaybackStateSeekingBackward    // 向后seeking中
 *
 * MPMoviePlayerPlaybackDidFinishNotification，当播放完成时提供通知
 * MPMoviePlayerPlaybackStateDidChangeNotification，当播放状态变化时提供通知
 *
 */
@property (nonatomic, readonly) MPMoviePlaybackState playbackState;

/* 当前网络加载情况（只读）
 *
 * MPMovieLoadStateUnknown        = 0,        // 加载情况未知
 * MPMovieLoadStatePlayable       = 1 << 0,   // 加载完成，可以播放
 * MPMovieLoadStatePlaythroughOK  = 1 << 1,   // 加载完成，如果shouldAutoplay为YES，将自动开始播放
 * MPMovieLoadStateStalled        = 1 << 2,   // 如果视频正在加载中
 *
 * MPMoviePlayerLoadStateDidChangeNotification，当加载状态变化时提供通知
 *
 */
@property (nonatomic, readonly) MPMovieLoadState loadState;

/* 当前缩放显示模式
 *
 * MPMovieScalingModeNone,       // 无缩放
 * MPMovieScalingModeAspectFit,  // 同比适配，某个方向会有黑边
 * MPMovieScalingModeAspectFill, // 同比填充，某个方向的显示内容可能被裁剪
 * MPMovieScalingModeFill        // 满屏填充，与原始视频比例不一致
 *
 */
@property (nonatomic) MPMovieScalingMode scalingMode;

/* 当前视频宽高（只读）
 *
 * 监听MPMovieNaturalSizeAvailableNotification
 * 播放过程中，宽高信息可能会产生更改
 *
 */
@property (nonatomic, readonly) CGSize naturalSize;

// Posted when the playback state changes, either programatically or by the user.
MP_EXTERN NSString * const MPMoviePlayerPlaybackStateDidChangeNotification;

// Posted when movie playback ends or a user exits playback.
MP_EXTERN NSString * const MPMoviePlayerPlaybackDidFinishNotification;

MP_EXTERN NSString * const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey; // NSNumber (MPMovieFinishReason)

// Posted when the network load state changes.
MP_EXTERN NSString * const MPMoviePlayerLoadStateDidChangeNotification;

MP_EXTERN NSString * const MPMovieNaturalSizeAvailableNotification;

MP_EXTERN NSString * const MPMoviePlayerFirstVideoFrameRenderedNotification;

MP_EXTERN NSString * const MPMoviePlayerFirstAudioFrameRenderedNotification;

//Posted when the network status change
MP_EXTERN NSString * const MPMoviePlayerNetworkStatusChangeNotification;
MP_EXTERN NSString * const MPMoviePlayerCurrNetworkStatusUserInfoKey; // NSNumber (KSYNetworkStatus)
MP_EXTERN NSString * const MPMoviePlayerLastNetworkStatusUserInfoKey; // NSNumber (KSYNetworkStatus)


/* bufferTimeMax指定直播流播放时的最大缓冲时长，单位为秒
 *
 * 当buffer为负数时，关闭直播追赶
 * 该属性仅对直播流有效
 * 默认值为2秒
 *
 */
@property NSTimeInterval bufferTimeMax;

/* 已经加载的数据大小（只读）
 *
 * 已经加载的数据大小，单位是兆
 * 已经加载的全部数据大小，包括音频和视频
 * 数据包括已经播放的，和当前的cache数据
 *
 */
@property (nonatomic, readonly) double readSize;

/* buffer为空时，拉取数据所耗的时长（只读）
 *
 * 当buffer为空时，开始统计。单位为秒
 *
 * 当MPMoviePlayerLoadStateDidChangeNotification 通知发起
 * MPMovieLoadState状态为MPMovieLoadStateStalled 开始计时
 * MPMovieLoadState状态为MPMovieLoadStatePlayable 或者 MPMovieLoadStatePlaythroughOK时，结束计时
 *
 */
@property (nonatomic, readonly) NSTimeInterval bufferEmptyDuration;

/* 发起cache的次数（只读）
 *
 * 当buffer为空时，统计一次，统计的条件为
 *
 * 当MPMoviePlayerLoadStateDidChangeNotification 通知发起
 * MPMovieLoadState 状态为MPMovieLoadStateStalled
 *
 */
@property (nonatomic, readonly) NSInteger bufferEmptyCount;

/* 截图
 *
 * 当前时刻的视频UIImage 图像
 *
 */
- (UIImage *)thumbnailImageAtCurrentTime;

@end
