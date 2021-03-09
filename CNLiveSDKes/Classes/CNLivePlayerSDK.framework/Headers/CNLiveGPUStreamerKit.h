//
//  CNLiveGPUStreamerKit.h
//  KSYLiveDemo
//  0.3.3.7  版本
//  Created by Android on 16/8/3.
//  Copyright © 2016年 Android. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveWebcastManager.h"
#import <AVFoundation/AVFoundation.h>
#import "CNLiveBgmPlayer.h"
#import <GPUImage/GPUImage.h>

@interface CNLiveGPUStreamerKit : NSObject

#pragma mark - 使用视讯云平台

/**
 @abstract      初始化(不会打断其他后台的音乐播放)
 @warning       实例化的对象必须赋值给一个全局变量
 @param         pureAudioMode           YES:纯音频推流
 @warning       必传参数
 */
-(instancetype)initCNLiveKitWithDefaultConfigWithPureAudioMode:(BOOL)mode;

/**
 @abstract      初始化(会打断其他后台的音乐播放)
 @warning       实例化的对象必须赋值给一个全局变量
 @param         pureAudioMode           YES:纯音频推流
 @warning       必传参数
 */
-(instancetype)initCNLiveKitWithInterruptConfigWithPureAudioMode:(BOOL)mode;

/**
 @abstract      活动ID，确保SP下的唯一性
 @discussion    必传参数
 */
@property (nonatomic, strong) NSString *activityId;

/**
 @abstract      主播ID
 @discussion    必传参数
 */
@property (nonatomic, strong) NSString *channelId;

/**
@abstract      ip 地址
@discussion    必传参数
*/
@property (nonatomic, copy) NSString *ip_address;

/**
@abstract      直播平台，默认七牛
@discussion    必传参数
*/
@property (nonatomic, copy) NSString *plantType;

/**
 @abstract      是否开启控制台输出日志
 @discussion    默认为开启
 */
@property (nonatomic, assign) BOOL logPrintEnable;

/**
 @abstract      屏幕方向，0：垂直即竖屏 ／1：水平即横屏 ，默认为0
 */
@property (nonatomic, assign) BOOL isHorizontalScreen;

/**
 @abstract      活动名称（非必传）
 */
@property (nonatomic, strong) NSString *activityName;

/**
 @abstract      活动状态，0：未开始 ／1：已开始 ／3：已结束 ／4 已下线，默认为0（非必传）
 */
@property (nonatomic, strong) NSString *activityStatus;

/**
 @abstract      开始时间，格式yyyyMMddHHmmss（非必传）
 */
@property (nonatomic, strong) NSString *startTime;

/**
 @abstract      结束时间，格式yyyyMMddHHmmss（非必传）
 */
@property (nonatomic, strong) NSString *endTime;

/**
 @abstract      活动封面（非必传）
 */
@property (nonatomic, strong) NSString *coverImgUrl;

/**
 @abstract      活动分类ID（非必传）
 */
@property (nonatomic, strong) NSString *activityCategory;

/**
 @abstract      扩展字段，参数格式为Map对象的Json字符串（主播昵称、头像、）（非必传）
 */
@property (nonatomic, strong) NSString *extensions;

/**
 @abstract      回调通知活动状态（错误，结束、心跳异常等状态），post 参数activityid、activitystatus值...（非必传）
 */
@property (nonatomic, strong) NSString *callbackAcitvityStatushttpPostUrl;

/**
 @abstract      启动推流
 @warning       鉴权成功后开启推流（SDK内部创建活动并开启推流）
 */
- (void)startStream:(void (^)(void))successBlock  failure:(void (^)(NSDictionary *errorDic))failureBlock;

/**
 @abstract      启动推流
 @param         url           推流地址
 @param         activityId    活动ID
 @warning       后台创建活动完成，开启推流（仅视讯云平台有效）
 */
- (void)startStreamWithUrl:(NSString *)url activityId:(NSString *)activityId success:(void (^)(void))successBlock  failure:(void (^)(NSDictionary *errorDic))failureBlock;


/**
 @abstract      暂停推流
 @warning       恢复推流时根据情况调用 startStream： 或 startStreamWithUrl：方法
 */
- (void)pauseStreaming;

/**
 *  主播端未停止推流，但是服务端认为该视频不合法，断开推流，接收到该通知主播端应结束推流（视讯云平台有效）,弃用
 */
FOUNDATION_EXPORT NSString *const CNLiveServiceConnectBreakNotification NS_AVAILABLE_IOS(7_0);

#pragma mark - 普通推流

/**
 @abstract      初始化(不会打断其他后台的音乐播放)
 @param         mode           YES:纯音频推流
 @warning       实例化的对象必须赋值给一个全局变量
 */
-(instancetype)initWithDefaultConfigWithPureAudioMode:(BOOL)mode;

/**
 @abstract      初始化(会打断其他后台的音乐播放)
 @param         mode           YES:纯音频推流
 @warning       实例化的对象必须赋值给一个全局变量
 */
-(instancetype)initWithInterruptConfigWithPureAudioMode:(BOOL)mode;

/**
 *  预览视图
 */
@property (nonatomic, readonly) UIView *preview;

/**
 @abstract   获取水印工具
 @discussion 通过它来设置水印图片/文字
 */
@property (nonatomic, readonly) CNLiveWatermark *watermark;

/**
 @abstract   获取底层推流工具
 @discussion 通过它来设置推流参数
 */
@property (nonatomic, readonly) CNLiveStreamerBase *streamerBase;

/**
 @abstract   获取音频采集工具
 */
@property (nonatomic, readonly) CNLiveAudioCapture *audioCapture;

/**
 @abstract   获取美颜工具
 */
@property (nonatomic, readonly) CNLiveBeautifyFaceFilter *beautifyFaceFilter;

/**
 @abstract   背景音乐工具
 */
@property (nonatomic, readonly) CNLiveBgmPlayer *bgmPlayer;

#pragma mark - capture & preview settings

/**
 @abstract   采集分辨率 (仅在开始采集前设置有效)
 @discussion 参见iOS的 AVCaptureSessionPresetXXX的定义 默认值为AVCaptureSessionPreset640x480
 @discussion 不同设备支持的预设分辨率可能不同, 请尽量与预览分辨率一致
 */
@property (nonatomic, assign) NSString * capPreset;

/**
 @abstract   查询实际的采集分辨率
 @discussion 参见iOS的 AVCaptureSessionPresetXXX的定义
 */
- (CGSize) captureDimension;

/**
 @abstract   预览分辨率 (仅在开始采集前设置有效)
 @discussion 内部始终将较大的值作为宽度 (若需要竖屏，请设置 videoOrientation）
 @discussion 宽高都会向上取整为4的整数倍
 @discussion 有效范围: 宽度[160, 1920] 高度[ 90,  1080], 超出范围会取边界有效值
 @discussion 当预览分辨率与采集分辨率不一致时:
 若宽高比不同, 先进行裁剪, 再进行缩放
 若宽高比相同, 直接进行缩放
 @discussion 默认值为(640, 360)
 */
@property (nonatomic, assign)   CGSize previewDimension;

/**
 @abstract   用户定义的视频 **推流** 分辨率
 @discussion 有效范围: 宽度[160, 1280] 高度[ 90,  720], 超出范围会取边界有效值
 @discussion 其他与previewDimension限定一致,
 @discussion 当与previewDimension不一致时, 同样先裁剪到相同宽高比, 再进行缩放
 @discussion 默认值为(640, 360)
 @see previewDimension
 */
@property (nonatomic, assign)   CGSize streamDimension;

/**
 @abstract      采集及编码视频帧率 (开始采集前设置有效)
 @discussion video frame per seconds 有效范围[1~30], 超出范围会取边界有效值
 @discussion 默认值为15 */
@property (nonatomic, assign) int          videoFPS;

/**
 @abstract      摄像头位置
 @discussion    前后摄像头 默认为前摄像头
 */
@property (nonatomic, assign) AVCaptureDevicePosition   cameraPosition;


/**
 @abstract      获取当前采集设备的指针
 @return        AVCaptureDevice* 预览开始前调用返回为nil，开始预览后，返回当前正在使用的摄像头
 @warning       请勿修改摄像头的像素格式，帧率，分辨率等参数，修改后会导致推流工作异常或崩溃
 */
- (AVCaptureDevice *) getCurrentCameraDevices;

/**
 @abstract      采集设备状态
 */
@property (nonatomic, readonly) CNLiveCaptureState captureState;

FOUNDATION_EXPORT NSString *const CNLiveCaptureStateDidChangeNotification NS_AVAILABLE_IOS(7_0);

#pragma mark - stream settings


/**
 @abstract      推流状态
 */
@property (nonatomic, readonly) CNLiveStreamState streamState;

FOUNDATION_EXPORT NSString *const CNLiveStreamStateDidChangeNotification NS_AVAILABLE_IOS(7_0);

/**
 * @abstract    推流错误码，用于指示推流失败的原因
 */
@property (nonatomic, readonly) CNLiveStreamErrorCode streamErrorCode;

#pragma mark - filters
/**
 @abstract   设置当前使用的滤镜
 @discussion 若filter 为nil， 则关闭滤镜
 @discussion 若filter 为GPUImageFilter的实例，则使用该滤镜做处理
 @discussion filter 也可以是GPUImageFilterGroup的实例，可以将多个滤镜组合
  */
- (void)setupFilter:(GPUImageOutput<GPUImageInput>*) filter;

#pragma mark - reconnect
/**
 @abstract 自动重连次数 关闭(0), 开启(>0), 默认为0
 @discussion 当内部发现推流错误后, 会在一段时间后尝试重连
 自动重连不会重新获取推流地址, 仍然使用上次推流的地址
 @warning  如果在推流地址有过期时间, 请勿开启
 */
@property (nonatomic, assign) int          maxAutoRetry;

/**
 @abstract 自动重连延时, 发现连接错误后, 重试的延时
 @discussion 单位为秒, 默认为2s, 最小值为0.1s
 */
@property (nonatomic, assign) double          autoRetryDelay;

/**
 @abstract 视讯云平台下重连状态（普通推流无效）
 */
@property (nonatomic, assign) CNLiveReconnectStatus reconnectStatus;

/**
 @abstract 自动重连失败通知（注*仅视讯云平台有效，普通方法推流自动重连失败收不到该通知）
 @discussion 仅推流错误码为 CNLiveStreamErrorCode_CONNECT_BREAK、
                        CNLiveStreamErrorCode_AV_SYNC_ERROR、
                        CNLiveStreamErrorCode_Connect_Server_failed、
                        CNLiveStreamErrorCode_DNS_Parse_failed、
                        CNLiveStreamErrorCode_CODEC_OPEN_FAILED、
                        CNLiveStreamErrorCode_ABNORMAL 时为可重连状态；
 */
FOUNDATION_EXPORT NSString *const CNLiveStreamReconnectStatusChangedNotification NS_AVAILABLE_IOS(7_0);

/**
 @abstract      切换摄像头
 @return        TRUE: 成功切换摄像头，开启预览后设置有效
 */
- (BOOL) switchCamera;

/**
 @abstract   当前采集设备是否支持闪光灯
 @return     YES / NO
 @discussion 通常只有后置摄像头支持闪光灯
 */
- (BOOL) isTorchSupported;

/**
 @abstract      开关闪光灯
 @discussion    切换闪光灯的开关状态 开 <--> 关
 @warning       对后摄像头设置有效
 */
- (void) toggleTorch;
- (void) setTorchMode:(AVCaptureTorchMode)mode;

/**
 @abstract   摄像头朝向
 @discussion 参见UIInterfaceOrientation
 @discussion 竖屏时: width < height
 @discussion 横屏时: width > height
 @discussion 需要与UI方向一致
 */
- (void) setVideoOrientationBy:(UIInterfaceOrientation)uiOrien;

/**
 @abstract      启动预览
 @param view    预览画面作为subview，插入到 view 的最底层
 @discussion    设置完成采集参数之后，按照设置值启动预览，启动后对采集参数修改不会生效
 @discussion    需要访问摄像头和麦克风的权限，若授权失败，其他API都会拒绝服务
 @warning:      开始推流前必须先启动预览
 */
- (void) startPreview:(UIView*) view;

/**
 @abstract      停止预览，停止采集设备，并清理会话
 @warning       若推流未结束，则先停止推流
 */
- (void) stopPreview;

/**
 @abstract      启动推流
 @param         hostURL    rtmp 服务器地址 “rtmp://xxx.xxx.xxx.xxx/appname/streamKey"
 */
- (void) startStream:(NSURL *)hostURL;

/**
 @abstract      停止推流
       备注： 推流是一定停止了，但 successBlock 和 failureBlock 回调的是请求结束活动接口是否成功
 */
- (void) stopStream:(void (^)(NSDictionary *dic))successBlock  failure:(void (^)(NSDictionary *errorDic))failureBlock;;

/**
 @abstract      开始录制本地视频(不支持边推边录)
 @param         path        本地存储路径
 */
- (void)startRecordWithFilePath:(NSString *)path;

/**
 @abstract      停止录制本地视频
 @discussion    与 - (void)startRecordWithFilePath: 搭配使用
 */
- (void)stopRecord;

/**
 @abstract   进入后台: 暂停图像采集
 @discussion 暂停图像采集和预览
 */
- (void) appEnterBackground;

/**
 @abstract   回到前台: 恢复采集
 @discussion 恢复图像采集和预览
 */
- (void) appBecomeActive;

/**
 @abstract   退出推流页面时调用
 */
- (void)quitStreaming;

#pragma mark -  mirror & rotate

/**
 @abstract 预览设置成镜像模式，默认为NO
 */
@property (nonatomic, assign) BOOL previewMirrored;

/**
 @abstract 推流设置成镜像模式,默认为NO
 */
@property (nonatomic, assign) BOOL streamerMirrored;

/**
 @abstract   根据UI的朝向旋转预览视图, 保证预览视图全屏铺满窗口
 @param      orie 旋转到目标朝向, 需要从demo中获取UI的朝向传入
 @discussion 采集到的图像的朝向还是和启动时的朝向一致
 */
- (void) rotatePreviewTo: (UIInterfaceOrientation) orie;

/**
 @abstract 根据UI的朝向旋转推流画面
 @param    orie 旋转到目标朝向, 需要从demo中获取UI的朝向传入
 */
- (void) rotateStreamTo: (UIInterfaceOrientation) orie;

/**
 @abstract   当前采集设备是否支持自动变焦
 @param      point相机对焦的位置
 */
- (void)focusAtPoint:(CGPoint )point;

/**
 @abstract   当前采集设备是否支持自动曝光
 @param      point相机曝光的位置
 */
- (void)exposureAtPoint:(CGPoint )point;

/**
 @abstract 触摸缩放因子
 */
@property (nonatomic, assign)   CGFloat pinchZoomFactor;

/**
 @abstract   摄像头防抖模式，切换摄像头后需要进行重新设置
 @discussion (iPhone前置摄像头不支持防抖功能)
 */
@property (nonatomic, assign) AVCaptureVideoStabilizationMode stabilizationMode;

/**
 *  悬浮窗
 */
- (UIView *)floatingWindowFrame:(CGRect)rect;

@end

