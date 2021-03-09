//
//  CNLiveAudioCapture.h
//  CNLivePlayerSDKDemo
//
//  Created by iOS on 17/2/27.
//  Copyright © 2017年 雷浩杰. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * @abstract  噪声抑制等级
 */
typedef NS_ENUM(NSInteger, CNLiveAudioNoiseSuppress){
    /// 关闭
    CNLiveAudioNoiseSuppress_OFF = -1,
    /// 温和
    CNLiveAudioNoiseSuppress_LOW = 0,
    /// 中等
    CNLiveAudioNoiseSuppress_MEDIUM = 1,
    /// 激进
    CNLiveAudioNoiseSuppress_HIGH = 2,
    /// 非常激进
    CNLiveAudioNoiseSuppress_VERYHIGH = 3,
};

@interface CNLiveAudioCapture : NSObject

/**
 @abstract   是否有耳机麦克风可用
 @return     是/否有耳机麦克风
 */
+ (BOOL)isHeadsetPluggedIn;

/**
 @abstract 是否播放采集的声音 (又称"耳返")
 @warning 如果在没有插入耳机的情况下启动, 容易出现很刺耳的声音
 */
@property(nonatomic, assign) BOOL bPlayCapturedAudio;

/**
 @abstract  设置mic采集的声音音量
 @discussion 调整范围 0.0~1.0
 */
@property(nonatomic, assign) float micVolume;

/**
 @abstract  设置耳返音量
 @discussion 调整范围 0.0~1.0
 */
@property(nonatomic, assign) Float32 bPlayVolume;

/**
 @abstract 混响类型
 @discussion 目前提供了4种类型的混响场景, type和场景的对应关系如下
 
- 0 关闭
- 1 录音棚
- 2 KTV
- 3 小舞台
- 4 演唱会
*/
@property(nonatomic, assign) int reverbType;

/**
 @abstract 音效类型
 @discussion 目前提供了4种音效类型, type和音效的对应关系如下
 
 - 0 关闭
 - 1 大叔
 - 2 萝莉
 - 3 庄严
 - 4 机器人
 */
@property (nonatomic, assign) int audioEffectType;

/**
 @abstract 噪声抑制处理的等级(默认为CNLiveAudioNoiseSuppress_OFF)
 @discussion 当启用噪声抑制处理后, 内部会进行输出音频数据的
 */
@property(nonatomic, assign) CNLiveAudioNoiseSuppress noiseSuppressionLevel;

@end
