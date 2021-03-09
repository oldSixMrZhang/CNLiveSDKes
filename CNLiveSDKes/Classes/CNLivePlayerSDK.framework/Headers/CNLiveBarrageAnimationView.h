//
//  barrageAnimationView.h
//
//  Created by CNLive on 16/8/3.
//  Copyright © 2016年 CNLive. All rights reserved.
//

#import <UIKit/UIKit.h>

//承载弹幕动画的view
@interface CNLiveBarrageAnimationView : UIView

/*
 * 获取SDK版本号
 */
+ (NSString *)getVersion;

/* 初始化 barrageAnimationView
 *
 * frame中height此时设置是无效的
 * height将根据提供的行数和用来做弹幕动画的label的height决定
 *
 */
- (instancetype)initWithFrame:(CGRect)frame;

/* 设置弹幕的行数
 *
 * 弹幕启动后设置无效
 * 默认1行
 *
 */
- (void)setLinage:(NSInteger)linage;

/* 设置弹幕文字到弹幕载体边缘的间隔
 *
 * 弹幕启动后设置无效
 * 默认为0
 *
 */
- (void)setHorizontalSpace:(CGFloat)hSpace;

/* 设置弹幕与弹幕之间上下的间隔
 *
 * 弹幕启动后设置无效
 * 默认为0
 *
 */
- (void)setVerticalSpace:(CGFloat)vSpace;

/* 设置弹幕动画的持续时间
 *
 * 弹幕启动后设置无效
 * 默认5秒
 *
 */
- (void)setAnimationDuration:(CGFloat)duration;

/* 设置弹幕的样式
 *
 * 弹幕启动后设置无效
 *
 * 通过传入label的属性来设置弹幕的样式
 *
 * 目前支持设置的属性有如下
 * frame中的height
 * backgroundColor
 * font
 * textColor
 * layer.cornerRadius
 * layer.masksToBounds
 * layer.borderColor
 * layer.borderWidth
 *
 */
- (void)setBarrageLabelStyle:(UILabel *)styleLabel;

/* 启动弹幕
 *
 * 未启动时也会保留传入的弹幕内容
 *
 */
- (void)startAnimation;

/* 关闭弹幕
 *
 * 调用时正在做动画的弹幕将立即消失
 * 等待做动画的弹幕继续保留
 * 再次调用startAnimation将继续展示
 *
 */
- (void)stopAnimation;

// 传入需要展示的弹幕内容
- (void)showBarrageContent:(NSString *)content;

@end
