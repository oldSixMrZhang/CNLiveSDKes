//
//  CNLiveBeautifyFaceFilter.h
//  CNLivePlayerSDKDemo
//
//  Created by iOS on 17/3/2.
//  Copyright © 2017年 雷浩杰. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveTypeDef.h"
#import <UIKit/UIKit.h>

/**
 *  美颜（（默认旧美颜，磨皮参数为0.5））
 */

@interface CNLiveBeautifyFaceFilter : NSObject

/**
 @abstract   CNLiveBeautyTypeSpecial 美颜特效类型，需先设置CNLiveBeautyType为CNLiveBeautyTypeSpecial
 */
- (void)setCurEffectIdx:(CNLiveSpecialEffects)curEffectIdx;   //美颜特效类型

/**
 @abstract          美颜类型
 @param beautyType  类型
 @warn  旧美颜仅grindRatio参数可调节，另两个参数设置无效
 */
- (void)setBeautyType:(CNLiveBeautyType)beautyType;

/**
 @abstract          美颜参数调节
 @param grindRatio  磨皮
 @param whitenRatio 美白
 @param intensity   特效
 */
- (void)filterAdjustingParameterWithGrindRatio:(CGFloat)grindRatio
                                   whitenRatio:(CGFloat)whitenRatio
                                     intensity:(CGFloat)intensity;


@end
