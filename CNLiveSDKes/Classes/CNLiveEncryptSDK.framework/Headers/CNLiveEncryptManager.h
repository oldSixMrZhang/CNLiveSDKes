//
//  CNLiveEncryptManager.h
//  CNLiveEncryptSDKDemo
//
//  Created by 张旭 on 2018/5/29.
//  Copyright © 2018年 cnlive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CNLiveEncryptManager : NSObject

/**
 单例

 @return 返回单例对象
 */
+ (instancetype)manager;

/**
 初始化上传云SDK
 
 @param appId               在open.cnlive.com网站申请得到的appId
 */
- (void)setAppId:(NSString *)appId;

/**
 网++加密 预验证API1 将明文参数字典转为API1所需的 加密参数字典

 @param params 明文参数字典
 @return API1所需加密参数字典
 */
- (NSDictionary *)preValidationEncryptWithParams:(NSDictionary *)params;

/**
 网++加密 验证API2 将明文参数字典 和 preValidationEncryptWithParams返回dic转为API2所需的 加密参数字典

 @param params 明文参数字典
 @param preValiDic 预验证API1返回的dic
 @return API2所需加密参数字典
 */
- (NSDictionary *)validationEncryptWithParams:(NSDictionary *)params preValiDic:(NSDictionary *)preValiDic;

/**
 是否打开控制台打印log,Default is YES

 @param enableLog 是:打开log  否:关闭log
 */
+ (void)isEnableLog:(BOOL)enableLog;

/**
 获取SDK版本号

 @return SDK版本号
 */
+ (NSString *)getSDKVersion;

@end
