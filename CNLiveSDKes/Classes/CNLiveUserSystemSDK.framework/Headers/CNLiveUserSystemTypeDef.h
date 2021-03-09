//
//  CNLiveUserSystemTypeDef.h
//  CNLiveUserSystemDemo
//
//  Created by iOS on 16/9/12.
//  Copyright © 2016年 zhulin. All rights reserved.
//

#ifndef CNLiveUserSystemTypeDef_h
#define CNLiveUserSystemTypeDef_h

//获取验证码
typedef NS_ENUM(NSUInteger, VerificationCodeType) {
    VerificationCodeTypeShortcutLogin = 0,      //快捷登录
    VerificationCodeTypeRegister,               //注册或修改手机号
    VerificationCodeTypeRetrievePassword        //找回或修改密码
};

//修改单项用户信息类型
typedef NS_ENUM(NSUInteger, UserInfoType) {
    UserInfoTypeNickName = 0,                   //昵称
    UserInfoTypeGender,                         //性别（f/m/n）
    UserInfoTypeEmail,                          //邮箱
    UserInfoTypeLocation,                       //联系方式（地址）
};

//校验验证码
typedef NS_ENUM(NSInteger, CheckVerificationCodeType) {
    CheckVerificationCodeTypeRegister          = 0,//注册前校验验证码
    CheckVerificationCodeTypeShortcutLogin         //快捷登录前校验验证码
};

#endif /* CNLiveUserSystemTypeDef_h */
