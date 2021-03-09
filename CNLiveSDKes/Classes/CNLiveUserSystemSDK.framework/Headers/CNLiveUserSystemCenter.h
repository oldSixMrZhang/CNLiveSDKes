//
//  CNLiveUserSystemCenter.h
//  CNLiveUserSystemDemo
//
//  Created by iOS on 16/9/12.
//  Copyright © 2016年 zhulin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveUserSystemTypeDef.h"
#import <UIKit/UIKit.h>

@interface CNLiveUserSystemCenter : NSObject

/**
 @abstract      初始化
 @param         appId                   注册成功获得应用ID
 @param         appKey                  注册成功获得应用key
 @param         appSecret               注册成功获得应用secret
 @param         isTestEnvironment       测试环境开关
 @warning       必传参数
 必须在 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions; 方法中调用
  */
 + (void)setAppId:(NSString *)appId appKey:(NSString *)appKey appSecret:(NSString *)appSecret isTestEnvironment:(BOOL)isTestEnvironment;

/**
 用户ID

 @param userId 用户ID
 */
+ (void)setUserId:(NSString *)userId;

/**
 渠道ID
 
 @param fromID 渠道ID
 */
+ (void)setFromID:(NSString *)fromID;

/**
 @abstract      初始化
 @param         appId                   注册成功获得应用ID
 @param         appKey                  注册成功获得应用key
 @param         appSecret               注册成功获得应用secret
 @warning       必传参数
 必须在 - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions; 方法中调用
 *此方法环境默认为正式环境,建议使用如下方法初始化.
 + (void)setAppId:(NSString *)appId appKey:(NSString *)appKey appSecret:(NSString *)appSecret isTestEnvironment:(BOOL)isTestEnvironment;
 
 */
+ (void)setAppId:(NSString *)appId appKey:(NSString *)appKey appSecret:(NSString *)appSecret;

/**
 @abstract      注册
 @param         userName                邮箱或手机
 @param         password                密码
 @param         verificationCode        手机验证码（手机号注册时必填）
 @param         invitationCode          邀请码（非必填）
 @param         frmId                   渠道ID（非必填）
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)registerWithUserName:(NSString *)userName password:(NSString *)password verificationCode:(NSString *)verificationCode invitationCode:(NSString *)invitationCode frmId:(NSString *)frmId success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      第三方登录
 @param         plat                    第三方平台编号（如plat: 1:sina weibo 2:qq 3:weixin 4:renren 注:如qq登录,plat=@"2"）
 @param         thirdPartyId            第三方用户ID
 @param         nickName                用户昵称
 @param         gender                  性别，m：男、f：女、n：未知（非必填）
 @param         location                用户所在地（非必填）
 @param         faceUrl                 头像，约100*100（非必填）
 @param         frmId                   渠道ID（非必填）
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)thirdPartyLoginWithThirdPartyPlatType:(NSString *)plat thirdPartyId:(NSString *)thirdPartyId nickName:(NSString *)nickName gender:(NSString *)gender location:(NSString *)location faceUrl:(NSString *)faceUrl frmId:(NSString *)frmId success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      快捷登录(旧)
 @param         userName                手机号
 @param         verificationCode        验证码
 @param         frmId                   渠道ID（非必填）
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)shortcutLoginWithUserName:(NSString *)userName verificationCode:(NSString *)verificationCode frmId:(NSString *)frmId success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;

/**
 @abstract      快捷登录(新)
 @param         userName                手机号
 @param         countryCode             手机号国家码
 @param         verificationCode        验证码
 @param         frmId                   渠道ID（非必填）
 @param         success                 成功回调
 @param         failure                 失败回调
 */+ (void)shortcutLoginWithUserName:(NSString *)userName countryCode:(NSString *)countryCode verificationCode:(NSString *)verificationCode frmId:(NSString *)frmId success:(void (^)(id))success failure :(void (^)(NSDictionary *))failure;

/**
 @abstract      登录
 @param         userName                手机号或邮箱
 @param         password                密码
 @param         frmId                   渠道ID（非必填）
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)loginWithUserName:(NSString *)userName password:(NSString *)password frmId:(NSString *)frmId success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      发送验证码(旧)
 @param         mobile                  手机号
 @param         type                    发送验证码类型（详见VerificationCodeType）
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)verificationCodeType:(VerificationCodeType)type mobile:(NSString *)mobile success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;

/**
 @abstract      发送验证码(新)
 @param         type                    发送验证码类型（详见VerificationCodeType）
 @param         mobile                  手机号
 @param         countryCode             手机号国家码
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)verificationCodeType:(VerificationCodeType)type mobile:(NSString *)mobile countryCode:(NSString *)countryCode success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      更新用户附加信息
 @param         uid                     用户ID
 @param         extInfo                 扩展信息（格式由对方自己组织，平台只负责存储和原样读取，NSString类型）
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)updateOtherInfoWithUid:(NSString *)uid extInfo:(NSString *)extInfo success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      修改用户单项信息
 @param         type                    修改类型（nickName-昵称，gender-性别，email-邮箱, location-联系方式（地址））
 @param         uid                     用户ID
 @param         info                    对应的信息（注gender对应f/m/n）
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)modifyUserInfoType:(UserInfoType)type uid:(NSString *)uid modifyInfo:(NSString *)info success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      更新手机号(旧)
 @param         uid                     用户ID
 @param         mobile                  手机号
 @param         verificationCode        验证码
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)updateMobileWithUid:(NSString *)uid mobile:(NSString *)mobile verificationCode:(NSString *)verificationCode success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;

/**
 @abstract      更新手机号(新)
 @param         uid                     用户ID
 @param         mobile                  手机号
 @param         countryCode             手机号国家码
 @param         verificationCode        验证码
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+(void)updateMobileWithUid:(NSString *)uid mobile:(NSString *)mobile countryCode:(NSString *)countryCode verificationCode:(NSString *)verificationCode success:(void (^)(id))success failure:(void (^)(NSDictionary *))failure;

/**
 @abstract      绑定第三方账号
 @param         uid                     用户ID
 @param         plat                    第三方平台编号（如platform: 1:sina weibo 2:qq  3:weixin 4:renren                注:如绑定qq,thirdPartyPlat = @"2"）
 @param         thirdPartyId            第三方用户ID
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)bindingThirdPartyWithUid:(NSString *)uid thirdPartyPlatType:(NSString *)plat thirdPartyId:(NSString *)thirdPartyId success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      修改密码（通过手机号修改）
 @param         mobile                  手机号
 @param         verificationCode        验证码
 @param         newPassword             新密码
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)changePasswordWithMobile:(NSString *)mobile verificationCode:(NSString *)verificationCode newPassword:(NSString *)newPassword success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      上传头像
 @param         uid                     用户ID
 @param         icon                    头像 (图片质量 0.5)
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)uploadIconWithUid:(NSString *)uid icon:(UIImage *)icon success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;

/**
 @abstract      上传头像 新增
 @param         uid                     用户ID
 @param         compressionQuality      头像质量 0-1 Default 0.5
 @param         icon                    头像
 @param         success                 成功回调
 @param         failure                 失败回调
 
 */
+ (void)uploadIconWithUid:(NSString *)uid icon:(UIImage *)icon compressionQuality:(CGFloat)compressionQuality success:(void (^)(id))success failure:(void (^)(NSDictionary *))failure;

/**
 @abstract      查询用户信息
 @param         uid                     用户ID
 @param         srcUid                  被查询用户ID
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)queryUserInfoWithUid:(NSString *)uid srcUid:(NSString *)srcUid success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      查询多条用户信息
 @param         uid                     用户ID
 @param         srcUids                 被查询用户IDs
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)queryMoreUserInfosWithUid:(NSString *)uid srcUids:(NSArray *)srcUids success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 @abstract      用户反馈
 @param         contentId               举报内容ID
 @param         message                 举报内容(app自己组织-不能带特殊字符&号等)
 @param         success                 成功回调
 @param         failure                 失败回调
 */
+ (void)feedbackWithContentId:(NSString *)contentId message:(NSString *)message success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 通过邮箱修改密码

 @param email 邮箱
 @param newPwd 新密码
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)modifyPwdWithEmail:(NSString *)email newPwd:(NSString *)newPwd success:(void (^)(id result))success failure :(void (^)(NSDictionary *errorDic))failure;


/**
 通过原密码修改密码

 @param uid 用户ID
 @param pwd 原密码
 @param newPwd 新密码
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)oldPwdChangePasswordWithUid:(NSString *)uid pwd:(NSString *)pwd newPwd:(NSString *)newPwd success:(void (^)(id result))success failure :(void (^)(NSDictionary *errorDic))failure;


/**
 注册前校验手机验证码(旧)

 @param mobile 手机号
 @param verificationCode 验证码
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)registerCheckVerificationCodeWithMobile:(NSString *)mobile verificationCode:(NSString *)verificationCode success:(void (^)(id result))success failure :(void (^)(NSDictionary *errorDic))failure;

/**
 注册前校验手机验证码(新)
 
 @param mobile 手机号
 @param countryCode 手机号国家码
 @param verificationCode 验证码
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)registerCheckVerificationCodeWithMobile:(NSString *)mobile countryCode:(NSString *)countryCode verificationCode:(NSString *)verificationCode success:(void (^)(id result))success failure :(void (^)(NSDictionary *errorDic))failure;

/**
 快捷登录前校验手机验证码(旧)

 @param mobile 手机号
 @param verificationCode 验证码
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)shortcutLoginCheckVerificationCodeWithMobile:(NSString *)mobile verificationCode:(NSString *)verificationCode success:(void (^)(id result))success failure :(void (^)(NSDictionary *errorDic))failure;

/**
 快捷登录前校验手机验证码(新)
 
 @param mobile 手机号
 @param countryCode 手机号国家码
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)shortcutLoginCheckVerificationCodeWithMobile:(NSString *)mobile countryCode:(NSString *)countryCode verificationCode:(NSString *)verificationCode success:(void (^)(id result))success failure :(void (^)(NSDictionary *errorDic))failure;

/**
 验证第三方账号是否注册,若注册则直接登录返回用户信息,若未注册返回errorCode

 @param plat  第三方平台编号（如plat: 1:sina weibo 2:qq 3:weixin 4:renren 注:如qq登录,plat=@"2"）
 @param thirdPartyId 第三方用户ID
 @param frmId 渠道ID（非必填）
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)thirdPartyCheckLoginWithThirdPartyPlatType:(NSString *)plat thirdPartyId:(NSString *)thirdPartyId frmId:(NSString *)frmId success:(void (^)(id result))success failure :(void (^)(NSDictionary *errorDic))failure;


/**
 第三方注册强制绑定手机号登录: 手机号+密码+验证码+三方账号

 @param plat  第三方平台编号（如plat: 1:sina weibo 2:qq 3:weixin 4:renren 注:如qq登录,plat=@"2"）
 @param thirdPartyId 第三方用户ID
 @param nickName 用户昵称
 @param gender 性别，m：男、f：女、n：未知（非必填）
 @param location 用户所在地（非必填）
 @param faceUrl 头像，约100*100（非必填）
 @param mobile 手机号
 @param verificationCode 验证码 (验证码类型为快捷登录VerificationCodeTypeShortcutLogin)
 @param pawd 注册密码
 @param frmId 渠道ID（非必填）
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)thirdPartyBindMobileLoginWithThirdPartyPlatType:(NSString *)plat thirdPartyId:(NSString *)thirdPartyId nickName:(NSString *)nickName gender:(NSString *)gender location:(NSString *)location faceUrl:(NSString *)faceUrl mobile:(NSString *)mobile verificationCode:(NSString *)verificationCode pawd:(NSString *)pawd frmId:(NSString *)frmId success:(void (^)(id result))success failure:(void (^)(NSDictionary *errorDic))failure;


/**
 *  获取SDK版本号 v2.2.0
 */
+ (NSString *)getVersion;



@end
