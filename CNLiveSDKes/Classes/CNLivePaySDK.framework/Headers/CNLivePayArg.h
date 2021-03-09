//
//  CNLivePayArg.h
//  CNLivePaySDK
//
//  Created by cnliveJunBo on 17/5/2.
//  Copyright © 2017年 cnlive. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    CNLivePayTypeWeChatPay = 1,
    CNLivePayTypeAliPay    = 3,
    CNLivePayTypeUnionpay  = 9,
    CNLivePayTypeInAppPurchase  = 1001
} CNLivePayType;

@interface CNLivePayArg : NSObject

/**
 视讯云平台获得的第三方平台帐号;
 */
@property (nonatomic, copy) NSString * account;


/**
 支付类型(微信, 支付宝, 内购)
 */
@property (nonatomic, assign) CNLivePayType type;


/**
 唯一业务系统中的订单号
 */
@property (nonatomic, copy) NSString *out_trade_no;


/**
 商品价格,以分为单位,只能是整数;
 */
@property (nonatomic, assign) int total_fee;


/**
 用户付款通知业务系统接收地址;不能有参数;
 */
@property (nonatomic, copy) NSString *notify_url;


/**
 订单信息
 */
@property (nonatomic, copy) NSString *body;


/**
 业务回传参数,传递参数用于给 notify_url 用户付款通知业务系统接收地址拼接参数;
 业务回传参数可以使用多个参数,由业务系统自行使用。但有长度限制，所有attach 的总字符长度不能超过300。 例如： attach.phone=13523455432 attach.others=o …
 */
@property (nonatomic, strong) NSDictionary *attach;


/**
 业务系统用户ID
 */
@property (nonatomic, copy) NSString *user_id;

@end
