//
//  NSString+Keychain.h
//  XWTest
//
//  Created by CNLive-zxw on 2019/7/8.
//  Copyright © 2019 CNLive. All rights reserved.
//

#import <Foundation/Foundation.h>

// 获取UUID
#define XW_UUID [NSString xw_getUUIDInKeychain]
// 是否存在UUID
#define XW_UUID_Exist [NSString xw_existUUID]

// 获取时间戳
#define XW_Timestamp [NSString xw_getTimestampInKeychain]
// 是否存在时间戳
#define XW_Timestamp_Exist [NSString xw_existTimestamp]

// 获取UUID_时间戳 传入时间戳
#define XW_UUID_Timestamp(Timestamp) [Timestamp xw_getUUIDTimestampInKeychain]

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Keychain)

/**
 * @abstract  获取设备UUID
 *
 * 本方法是得到 UUID 后存入系统中的 keychain 的方法
 * 程序删除后重装,仍可以得到相同的唯一标示
 * 但是当系统刷机后,系统中的钥匙串会被清空,此时本方法失效
 *
 * @return  返回UUID字符串对象
 */
+ (NSString *)xw_getUUIDInKeychain;
+ (BOOL)xw_existUUID;


/**
 * @abstract  获取时间戳
 * 获取的时间戳就是第一次调用xw_getTimeInKeychain这个方法,此方法会把传入的时间戳存入系统中的 keychain
 * 我们调用此方法获取时间戳的时候,如果有,则返回;如果没有,则返回当前时间戳
 * 一定确保此方法在xw_getTimeInKeychain之后调用 *
 *
 * @return  返回时间戳字符串对象
 */
+ (NSString *)xw_getTimestampInKeychain;
+ (BOOL)xw_existTimestamp;


/**
 * @abstract  获取UUID和_和时间戳3个的拼接对象
 *
 * 本方法一定要使用时间戳字符串调用 *
 * 本方法是得到 UUID_时间戳 后存入系统中的 keychain 的方法
 * 程序删除后重装,仍可以得到相同的唯一标示
 * 但是当系统刷机后,系统中的钥匙串会被清空,此时本方法失效
 *
 * @return  返回获取UUID和_和时间戳3个的拼接对象
 */
- (NSString *)xw_getUUIDTimestampInKeychain;


//保存数据至钥匙串中
+ (void)xw_save:(NSString *)service data:(id)data;


//从钥匙串中加载数据
+ (id)xw_load:(NSString *)service;


//删除数据
+ (void)xw_delete:(NSString *)service;
+ (void)xw_deletes;

/**
 * 保存已有的UUID_TS到钥匙串
 *
 * @param UUID UUID的字符串
 * @param TS TS的字符串
 */
+ (void)xw_saveUUID:(NSString *)UUID TS:(NSString *)TS;
    
@end

NS_ASSUME_NONNULL_END
