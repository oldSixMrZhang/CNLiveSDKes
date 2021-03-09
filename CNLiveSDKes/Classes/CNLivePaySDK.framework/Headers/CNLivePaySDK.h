//
//  CNLivePaySDK.h
//  CNLivePaySDK
//
//  Created by cnliveJunBo on 17/5/1.
//  Copyright © 2017年 cnlive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLivePayArg.h"
#import "CNLivePayResult.h"
#import <UIKit/UIKit.h>

typedef void(^CNLCompletionBlock)(CNLivePayResult *cnlivePayResult);

@interface CNLivePaySDK : NSObject

/**
 是否测试环境
 */
@property (nonatomic, readonly, assign) BOOL isTestEnvironment;

/**
 获取SDK当前版本号

 @return 返回SDK当前版本号
 */
+ (NSString *)getVersion;


/**
 获取支付核心类单例

 @return 返回支付核心类单例
 */
+ (instancetype)sharedCNLivePayManager;


/**
 注册支付SDK(所以支付都必须注册,默认上线环境)

 @param appid  从视讯云平台获取到的appId
 @param appkey 从视讯云平台获取到的appKey
 @warning      必须传参数 appid appkey
 @discussion   您在使用支付SDK所有功能之前，您必须先调用此方法初始化SDK。在App整个生命周期中，您只需要执行一次初始化。

 @return 是否注册成功
 */
- (BOOL)registerApp:(NSString *)appid AppKey:(NSString *)appkey;


/**
 注册支付SDK(所以支付都必须注册,同上,区别:可选择测试环境还是上线环境)
 
 @param appid             从视讯云平台获取到的appId
 @param appkey            从视讯云平台获取到的appKey
 @param isTestEnvironment 是否是测试环境,YES为测试环境,NO为上线环境;
 @warning                 必须传参数 appid appkey
 @discussion              您在使用支付SDK所有功能之前，您必须先调用此方法初始化SDK。在App整个生命周期中，您只需要执行一次初始化。
 
 @return 是否注册成功
 */
- (BOOL)registerApp:(NSString *)appid AppKey:(NSString *)appkey isTestEnvironment:(BOOL)isTestEnvironment;


/**
 注册微信支付(只有使用了微信支付才会使用到此方法,上方的注册方法也得调用)

 @param wxAppId 微信平台申请到的appId

 @return 是否注册成功
 */
- (BOOL)registerWXApiWithWXAppId:(NSString *)wxAppId universalLink:(NSString *)universalLink;


/**
 APP是否已安装检测接口，通过该接口得知用户是否安装银联支付的APP。

 @return 返回是否已经安装了银联支付APP
 */
- (BOOL)isPaymentAppInstalled;


/**
 支付方法(微信, 支付宝, 银联)

 @param payArg          支付所需参数结构体;
 @param schemeStr       支付宝、银联 支付时需要的appScheme,需要与info配置的scheme对应;其他支付不需要可传空字符串;
 @param viewController  银联支付时需要传此参数,启动支付控件的viewController(银联专属,其他支付方式无需传此参数,可传nil)
 @param completionBlock 支付结果回调;
 @discussion            支付宝 客户端,网页 支付结果回调都在此方法中的block回调中;
                        微信支付,银联支付结果回调在此方法中的block回调中;
 */
- (void)pay:(CNLivePayArg *)payArg appScheme:(NSString *)schemeStr viewController:(UIViewController*)viewController completion:(CNLCompletionBlock)completionBlock;


/**
 支付方法(内购)
 
 @param payArg          支付所需参数结构体;
 @param isDebug         是否是测试环境,上线时务必改成NO;开发环境请填YES,内购支付会到沙盒环境下验证支付结果,验证成功才算支付成功,并且会给用户付款通知业务系统接收地址异步通知时返回参数 sandbox=1 后台可以此作为标记判断加不加商品;真实环境请填NO,内购支付会到真实环境下验证支付结果,验证成功才算支付成功;
 @param productId       内购时商品的ID,只有内购时用到,其他支付可传nil;
 @param completionBlock 支付结果回调;
 @discussion            内购支付结果回调在此方法中的block回调中;
 */
- (void)pay:(CNLivePayArg *)payArg isDebug:(BOOL)isDebug productId:(NSString *)productId completion:(CNLCompletionBlock)completionBlock;


/**
 处理支付渠道通过URL启动App时传递的数据
 在 appdelegate
 iOS 8.0 以前
 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
 iOS 9.0及以后
 - (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options;
 中实现此方法,否则支付结果回调无法实现;

 @param url             支付渠道在启动第三方应用时传递过来的URL

 @return                成功返回YES，失败返回NO;
 */
- (BOOL)handleOpenURL:(NSURL *)url;

/**
 * 处理<微信>通过Universal Link启动App时传递的数据
 *
 * 需要在 application:continueUserActivity:restorationHandler:中调用。
 * @param userActivity 微信启动第三方应用时系统API传递过来的userActivity
 * @return 成功返回YES，失败返回NO。
 */
- (BOOL)handleOpenUniversalLink:(NSUserActivity *)userActivity;

@end
