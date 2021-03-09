//
//  CNLivePayResult.h
//  CNLivePaySDKDemo
//
//  Created by cnliveJunBo on 17/5/3.
//  Copyright © 2017年 cnlive. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  返回值详解
 */
typedef NS_ENUM(NSUInteger, CNLiveBackExplain) {
    
    CNLive_CODE_SUCCESS = 2000,                      /**< 成功*/
    CNLive_CODE_FAIL_CANCEL = 4004,                  /**< 用户取消支付*/
    CNLive_CODE_ERROR_DEAL = 4201,                   /**< 处理中*/
    CNLive_CODE_Failure = 4005,                      /**< 失败*/
    CNLive_CODE_ERROR_CONNECT = 4202,                /**< 网络错误*/
    CNLive_CODE_ERROR_PREPAY = 4006,                 /**< 预支付请求错误*/
    CNLive_CODE_ERROR_ALI_ERROR = 4901,              /**< 支付宝相关错误*/
    CNLive_CODE_ERROR_NOTADDSDK = 4007,              /**< 缺少相关SDK*/
    CNLive_CODE_ERROR_WX_NOT_INSTALL = 4101,         /**< 未安装微信*/
    CNLive_CODE_ERROR_WX_NOT_SUPPORT_PAY = 4102,     /**< 微信不支持OpenApi*/
    CNLive_CODE_ERROR_WX_SENTFAIL = 4103,            /**< 微信发送失败*/
    CNLive_CODE_ERROR_WX_AUTHDENY = 4104,            /**< 微信授权失败*/
    CNLive_CODE_ChannelWrong = 4003,                 /**< 渠道信息错误*/
    CNLive_CODE_ERROR_CHARGE_PARAMETER = 4002,       /**< 参数信息错误*/
    CNLive_CODE_ERROR_PREORDERNULL = 4902            /**< 预支付获取订单号为空*/
};

@interface CNLivePayResult : NSObject

/**
 *  枚举详解
 */
@property (assign, nonatomic) CNLiveBackExplain explain;
/**
 *  错误描述
 */
@property (copy, nonatomic) NSString *backDescription;
/**
 *  支付渠道返回的错误码
 */
@property (copy, nonatomic) NSString *channelBackCode;
/**
 *  支付渠道
 */
@property (copy, nonatomic) NSString *channel;
/**
 *  支付渠道返回的信息
 */
@property (strong, nonatomic) NSString *channelBackInfo;

/**
 *  是否安装了银联支付App,只有使用银联支付时才会用到
 */
@property (assign, nonatomic) BOOL isPaymentAppInstalled;

@end
