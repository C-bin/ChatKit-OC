//
//  AVIMMessage.h
//  AVOSCloudIM
//
//  Created by Qihe Bian on 12/4/14.
//  Copyright (c) 2014 LeanCloud Inc. All rights reserved.
//

#import "AVIMCommon.h"

typedef NS_ENUM(int8_t, AVIMMessageIOType) {
    AVIMMessageIOTypeIn = 1,
    AVIMMessageIOTypeOut,
};

typedef NS_ENUM(int8_t, AVIMMessageStatus) {
    AVIMMessageStatusNone = 0,
    AVIMMessageStatusSending = 1,
    AVIMMessageStatusSent,
    AVIMMessageStatusDelivered,
    AVIMMessageStatusFailed,
};

NS_ASSUME_NONNULL_BEGIN

@interface AVIMMessage : NSObject <NSCopying, NSCoding>

/*!
 * 表示接收和发出的消息
 */
@property (nonatomic, assign, readonly) AVIMMessageIOType ioType;

/*!
 * 表示消息状态
 */
@property (nonatomic, assign, readonly) AVIMMessageStatus status;

/*!
 * 消息 id
 */
@property (nonatomic, copy, readonly, nullable) NSString *messageId;

/*!
 * 消息发送/接收方 id
 */
@property (nonatomic, copy, readonly, nullable) NSString *clientId;

/*!
 * 消息所属对话的 id
 */
@property (nonatomic, copy, readonly, nullable) NSString *conversationId;

/*!
 * 消息文本
 */
@property (nonatomic, copy, nullable) NSString *content;

/*!
 * 发送时间（精确到毫秒）
 */
@property (nonatomic, assign) int64_t sendTimestamp;

/*!
 * 接收时间（精确到毫秒）
 */
@property (nonatomic, assign) int64_t deliveredTimestamp;

/*!
 * 是否是暂态消息
 */
@property (nonatomic, assign, readonly) BOOL transient;

- (nullable NSString *)payload;

/*!
 创建文本消息。
 @param content － 消息文本.
 */
+ (instancetype)messageWithContent:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
