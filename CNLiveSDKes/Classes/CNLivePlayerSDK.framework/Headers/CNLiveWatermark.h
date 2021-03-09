//
//  CNLiveWatermark.h
//  CNLivePlayerSDKDemo
//
//  Created by iOS on 17/2/27.
//  Copyright © 2017年 雷浩杰. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GPUImage/GPUImage.h>

@interface CNLiveWatermark : NSObject

/**
 @abstract   水印logo的图片
 @discussion 设置为nil为清除水印图片
 @discussion 请注意背景图片的尺寸, 太大的图片会导致内存占用过高
 @see
 */
@property (nonatomic, readwrite) GPUImagePicture      *logoPic;

/**
 设置水印图片的朝向
 @param orien 图片的朝向
 */
- (void)setLogoOrientaion:(UIImageOrientation) orien;

/**
 @abstract   文字内容的图片
 @discussion 设置为nil为清除内容图片
 */
@property (nonatomic, readwrite) GPUImagePicture      *textPic;

/**
 @abstract   贴纸的图片
 @discussion 设置为nil为清除贴纸图片
 */
@property (nonatomic, readwrite) GPUImageUIElement      *aePic;

/**
 @abstract   水印logo的图片的位置和大小
 @discussion 位置和大小的单位为预览视图的百分比, 左上角为(0,0), 右下角为(1.0, 1.0)
 @discussion 如果宽为0, 则根据图像的宽高比, 和设置的高度比例, 计算得到宽度的比例
 @discussion 如果高为0, 方法同上
 */
@property (nonatomic, readwrite) CGRect               logoRect;

/**
 @abstract   水印logo的图片的透明度
 @discussion alpha为透明度(0-1),0完全透明，1完全不透明
 */
@property (nonatomic, readwrite) CGFloat              logoAlpha;

/**
 @abstract   水印文字的label
 @discussion 借用UILabel来指定文字的颜色,字体, 透明度, 对齐方式等属性
 @discussion 请注意保证背景图片的尺寸, 太大的图片会导致内存占用过高
 @warning    如果使用非等宽字体, 可能导致闪烁(默认为Courier)
 @warning    picMixer和UILabel都有alpha属性, 建议只选用其中一个, 固定另一个为1.0,
 为了减少接口, 建议直接使用UILabel的属性,
 如果两者同时使用, 最终图层的alpha为两者乘积
 */
@property (nonatomic, readwrite) UILabel             *textLabel;

/**
 @abstract   水印文字的位置和大小
 @discussion 位置和大小的单位为预览视图的百分比, 左上角为(0,0), 右下角为(1.0, 1.0)
 @discussion 如果宽为0, 则根据文字图像的宽高比, 和设置的高度比例, 计算得到宽度的比例
 @discussion 如果高为0, 方法同上
 */
@property (nonatomic, readwrite) CGRect               textRect;

/**
 @abstract   刷新水印文字的内容
 @discussion 先修改文字的内容或格式,调用该方法后生效
 */
- (void)updateTextLabel;

@end
