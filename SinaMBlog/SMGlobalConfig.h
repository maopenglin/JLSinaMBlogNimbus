//
//  TVGlobalConfig.h
//  SinaMBlogNimbus
//
//  Created by Lee jimney on 10/30/13.
//  Copyright (c) 2013 jimneylee. All rights reserved.
//

#import <Foundation/Foundation.h>

#define APP_NAME [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]
#define APP_VERSION [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]

//"error":"applications over the unaudited use restrictions!"
//报错参考此处：http://open.weibo.com/qa/index.php?qa=159&qa_1=%E7%94%A8%E6%88%B7%E6%8E%88%E6%9D%83%E5%90%8E%E5%87%BA%E7%8E%B0applications-over-unaudited-restrictions%E9%94%99%E8%AF%AF%E6%80%8E%E4%B9%88%E8%A7%A3%E5%86%B3%EF%BC%9F
//#error @"please set your sina app key"
#define SinaWeiboV2AppKey @"2045436852"
#define SinaWeiboV2RedirectUri @"http://www.sina.com"

// baidu map key
#define BaiduMapEngineKey @"8502D0F8B5F266104698378D6A9010C31F850B49"

// iOS 系统版本
#define IOS_IS_AT_LEAST_6 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0)
#define IOS_IS_AT_LEAST_7 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)

// Cell布局相关 
#define CELL_PADDING_10 10
#define CELL_PADDING_8 8
#define CELL_PADDING_6 6
#define CELL_PADDING_4 4
#define CELL_PADDING_2 2

// TableView 视图背景
#define TABLE_VIEW_BG_COLOR RGBCOLOR(237, 234, 234)
#define CELL_CONTENT_VIEW_BG_COLOR RGBCOLOR(247, 247, 247)
#define CELL_RETWEET_CONTENT_VIEW_BG_COLOR RGBCOLOR(251, 251, 251)
#define CELL_CONTENT_VIEW_BORDER_COLOR RGBCOLOR(234, 234, 234)

// 微博时间线信息类型
typedef enum {
    MBlogTimeLineType_Public,       // 随便看看
    MBlogTimeLineType_Friends,      // 当前登录用户及关注好友的微博
    MBlogTimeLineType_User,         // 用户发布的微博
    MBlogTimeLineType_AtMe,         // @当前登录用户的微博
    MBlogTimeLineType_Comments,     // 返回最新N条评论列表（发送的和接收到的）
    MBlogTimeLineType_CommentsToMe, // 评论我的微博
    MBlogTimeLineType_CommentsByMe, // 我发出的评论
    MBlogTimeLinetype_DirectMsgs    // 登录用户的私信列表
}MBlogTimeLineType;

// 微博发送类型
typedef enum
{
    MBlogPostType_AtUser,
    MBlogPostType_AboutTrend,
    MBlogPostType_Common
}MBlogPostType;

//微博搜索类型
typedef enum
{
    SearchType_Statuses,
    SearchType_Users,
    SearchType_Topics
}SearchType;

@interface SMGlobalConfig : NSObject

///////////////////////////////////////////////////////////////////////////////////////////////////
// OAuth
+ (void)setCurrentLoginedUserName:(NSString*)userName;
+ (NSString *)getCurrentLoginedUserName;
+ (void)setCurrentLoginedUserId:(NSString*)userId;
+ (NSString *)getCurrentLoginedUserId;
+ (void)setCurrentLoginedAccessToken:(NSString*)accessToken;
+ (NSString *)getCurrentLoginedAccessToken;
+ (void)setCurrentLoginedExpiresIn:(NSString*)expiresIn;
+ (NSString *)getCurrentLoginedExpiresIn;

///////////////////////////////////////////////////////////////////////////////////////////////////
// UI
+ (void)showHUDMessage:(NSString*)msg addedToView:(UIView*)view;
+ (UIBarButtonItem*)createRefreshBarButtonItemWithTarget:(id)target action:(SEL)action;
+ (UIBarButtonItem*)createPostBarButtonItemWithTarget:(id)target action:(SEL)action;
+ (UIBarButtonItem*)createBarButtonItemWithTitle:(NSString*)buttonTitle target:(id)target action:(SEL)action;
+ (UILabel*)getNavigationBarTitleViewWithTitle:(NSString*)title;

// Emotion
+ (NSArray* )emotionsArray;
+ (NSString*)pathForEmotionCode:(NSString*)code;
+ (NSString*)pathForEmotionCodeForHtml:(NSString*)code;

// 草稿箱数据
+ (NSArray*)getDraftArray;
+ (void)saveToDraft:(NSMutableDictionary*)dic;
+ (BOOL)removeDraftWithIndex:(int)index;
+ (NSDictionary*)convertNSDataToUIImageForDraft:(NSDictionary*)dic;
+ (NSDictionary*)convertUIImageToNSDataForDraft:(NSDictionary*)dic;

@end
