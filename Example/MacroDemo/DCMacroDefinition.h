//
//  DCMacroDefinition.h
//  DCMacrosDemo
//
//  Created by MyMac on 16/3/4.
//  Copyright © 2016年 MyMac. All rights reserved.
//

#ifndef DCMacroDefinition_h
#define DCMacroDefinition_h


/*************************  屏幕相关  *************************/

/** 常用的高度 */
#define kTabBar_Height        49.0f
#define kStatusBar_Height     20.0f
#define kNavigationBar_Height 44.0f
#define kKeyboard_English_Height (216.f)
#define kKeyboard_Chinese_Height (252.f)

/** 获取屏幕尺寸、宽度、高度(包含横屏获取的方法) */
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上
#define kSCREEN_WIDTH ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define kSCREENH_HEIGHT ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define kSCREEN_SIZE ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define kSCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define kSCREENH_HEIGHT [UIScreen mainScreen].bounds.size.height
#define kSCREEN_SIZE [UIScreen mainScreen].bounds.size
#endif

/*************************  硬件相关  *************************/

/** 设备是否为iPhone 4/4S 分辨率320x480，像素640x960，@2x */
#define kiPhone_SCREEN_3_5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
/** 设备是否为iPhone 5C/5/5S 分辨率320x568，像素640x1136，@2x */
#define kiPhone_SCREEN_4_0 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
/** 设备是否为iPhone 6 分辨率375x667，像素750x1334，@2x */
#define kiPhone_SCREEN_4_7 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
/** 设备是否为iPhone 6 Plus 分辨率414x736，像素1242x2208，@3x */
#define kiPhone_SCREEN_5_5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

/** 判断是否为iPhone */
#define kiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
/** 判断是否是iPad */
#define kiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
/** 判断是否为iPod */
#define kiPod ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

/** 判断是否 Retina屏 */
#define kRetina ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)] && ([UIScreen mainScreen].scale == 2.0f))

/** 判断是真机还是模拟器 */
#if TARGET_OS_IPHONE
//  iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//  iPhone Simulator
#endif


/*************************  系统相关  *************************/

/** 获取系统版本 */
#define kiOS_VERSION ([[UIDevice currentDevice] systemVersion])

/** 是否为iOS6 */
#define kiOS6_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0) ? YES : NO)
/** 是否为iOS7 */
#define kiOS7_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0) ? YES : NO)
/** 是否为iOS8 */
#define kiOS8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) ? YES : NO)
/** 是否为iOS9 */
#define kiOS9_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0) ? YES : NO)
/** 是否为iOS10 */
#define kiOS10_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0) ? YES : NO)


/** 获取APP版本 */
#define kAPP_VERSION ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
/** 获取APP build版本 */
#define kAPP_BUILD_VERSION ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])
/** 获取APP名称 */
#define kAPP_NAME ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"])
/** 获取当前语言 */
#define kLanguage_Current ([[NSLocale preferredLanguages] objectAtIndex:0])


/*************************  本地文档相关  *************************/

/** 定义UIImage对象 */
#define kImageNamed(name) ([UIImage imageNamed:[NSString stringWithFormat:@"%@",name]])
/** 定义UIImage对象并从本地文件读取加载图片 */
#define kImageLoad(file,type) ([UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:type]])
//建议使用前者加载图片,性能高于后者

/** 获取Documents目录 */
#define kDocumentsPath ([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject])
/** 获得Documents下指定文件名的文件路径 */
#define kFilePath(filename) ([[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject] stringByAppendingPathComponent:filename];)
/** 获取Library目录 */
#define kLibraryPath ([NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject])
/** 获取Caches目录 */
#define kCachesPath ([NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject])
/** 获取Tmp目录 */
#define kTmpPath NSTemporaryDirectory()
// 保存到plist文件
#define kPlistForWrite(dic,s) [dic writeToFile:filePath(s) atomically:YES];
// 读取plist文件到字典
#define kPlistForRead(s) [[[NSMutableDictionary alloc] initWithContentsOfFile:filePath(s)] mutableCopy]
//程序的本地化,引用国际化的文件
#define kMyLocal(x, ...) NSLocalizedString(x, nil)
/** NSLocalizedString宏做的其实就是在当前bundle中查找资源文件名“Localizable.strings”(参数:键＋注释) */
#define kLocalString(x, ...) NSLocalizedString(x, nil)
/** NSLocalizedStringFromTable宏做的其实就是在当前bundle中查找资源文件名“xxx.strings”(参数:键＋文件名＋注释) */
#define kAppLocalString(x, ...) NSLocalizedStringFromTable(x, @"someName", nil)

//NSUserDefaults本地保存
#define kUserDefaultSave(key,value) [[NSUserDefaults standardUserDefaults]setObject:value forKey:key];\
[[NSUserDefaults standardUserDefaults]synchronize];\
//NSUserDefaults本地读取
#define kUserDefaultRead(key) [[NSUserDefaults standardUserDefaults] objectForKey:key];
//NSUserDefaults本地删除
#define kUserDefaultDelete(key) [[NSUserDefaults standardUserDefaults]removeObjectForKey:key];\
[[NSUserDefaults standardUserDefaults]synchronize];\

/*************************  颜色相关  *************************/

/** 默认颜色 */
#define kColorDefault [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]
/** 带有RGBA的颜色设置 */
#define kColorWithRGBA(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]
/** 根据RGB16进制值获取颜色（16进制->10进制） */
#define kColorWithRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
/** 获取随机色 */
#define kColorRandom ([UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0f])


/*************************  界面显示操作  *************************/

/** 由弧度获取角度 */
#define kDegreeFromRadian(radian) (radian * 180.0)/(M_PI)
/** 由角度获取弧度 */
#define kRadianFromDegree(degree) (M_PI * (degree) / 180.0)

// View 圆角和加边框
#define kMaskForView(View, Radius, Width, Color)\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// 加载xib
#define kLoadNib(x) [[NSBundle mainBundle] loadNibNamed:@(x) owner:nil options:nil][0]

//适文本自适应
//iOS7,获取文本自适应高度的 size
#define kAutoHeightSize_iOS7(text, font, fixedWidth) [text boundingRectWithSize:CGSizeMake(fixedWidth, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading attributes:@{NSFontAttributeName:font} context:nil].size;
//iOS7,获取文本自适应宽度的 size
#define kAutoWidthSize_iOS7(text, font, fixedHeight) [text boundingRectWithSize:CGSizeMake(MAXFLOAT, fixedHeight) options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading attributes:@{NSFontAttributeName:font} context:nil].size;
//iOS6,获取文本自适应高度的 size
#define kAutoHeightSize_iOS6(text, font , fixedWidth) [text sizeWithFont:font] constrainedToSize:CGSizeMake(fixedWidth, MAXFLOAT)];
//iOS7,获取文本自适应宽度的 size
#define kAutoWidthSize_iOS6(text, font , fixedHeight) [text sizeWithFont:[font constrainedToSize:CGSizeMake(MAXFLOAT, fixedHeight)];

/** 默认导航栏返回按钮 */
#define kCustomBackBarButtonItem(viewController, usePopGesture)\
{\
UIButton *backBtn = [UIButton buttonWithType:UIButtonTypeCustom];\
backBtn.frame = CGRectMake(0, 0, 12, 20);\
[backBtn setBackgroundImage:[UIImage imageNamed:@"Basic_BackArrow.png"] forState:UIControlStateNormal];\
[backBtn setBackgroundImage:[UIImage imageNamed:@"Basic_BackArrow.png"] forState:UIControlStateHighlighted];\
[backBtn addTarget:self action:@selector(backToFront) forControlEvents:UIControlEventTouchUpInside];\
UIBarButtonItem *leftBackButton = [[UIBarButtonItem alloc] initWithCustomView:backBtn];\
leftBackButton.style = UIBarButtonItemStylePlain;\
leftBackButton.tintColor = [UIColor redColor];\
viewController.navigationItem.leftBarButtonItem = leftBackButton;\
if(usePopGesture){\
viewController.navigationController.interactivePopGestureRecognizer.enabled = YES;\
viewController.navigationController.interactivePopGestureRecognizer.delegate = (id)viewController;\
}\
}\

/*************************  单例类实例化  *************************/

/** NSFileManager 实例化 */
#define kSingletonFileManager [NSFileManager defaultManager]
/** NSUserDefaults 实例化 */
#define kSingletonUserDefalut [NSUserDefaults standardUserDefaults]
/** NSNotificationCenter 实例化 */
#define kSingletonNotificationCenter [NSNotificationCenter defaultCenter]
/** UIApplication 实例化 */
#define kSingletonApplication [UIApplication sharedApplication]
/** NSRunLoop 实例化 */
#define kSingletonMainRunLoop [NSRunLoop mainRunLoop]
/** NSBundle 实例化 */
#define kSingletonMainBundle [NSBundle mainBundle]
//weakself
#define kWeakSelf(type)  __weak typeof(type) weak##type = type;
//strongself
#define kStrongSelf(type)  __strong typeof(type) type = weak##type;

/*************************  打印日志  *************************/

/** 调试（DEBUG）状态，打开LOG功能 */
#ifdef DEBUG
#define kLog(...) NSLog(__VA_ARGS__);
/** 发布（RELEASE）状态，关闭LOG功能 */
#else
#define kLog(...)
#endif

/** 调试（DEBUG）状态下打印当前方法名，行数以及自定义的内容 */
#ifdef DEBUG
#define kDLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DLog(...)
#endif

/** 重写NSLog,Debug模式下打印当前执行文件和当前行数及自定义内容 */
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"[%s:%d行] %s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif

/** DEBUG  模式下打印日志,当前行 并弹出一个警告 */
#ifdef DEBUG
#define kULog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }
#else
#define ULog(...)
#endif


//输出代码执行时间的宏
#define TICK NSDate *startTime = [NSDate date];
#define TOCK NSLog(@"Time:%f", -[startTime timeIntervalSinceNow]);
/** 快速查看一段代码的执行时间 */
/** 用法
 TICK
 do your work here
 TOCK
 */


/** 打印rect,size,point */
#ifdef DEBUG
#define kLogPoint(point)    NSLog(@"%s = { x:%.4f, y:%.4f }", #point, point.x, point.y)
#define kLogSize(size)      NSLog(@"%s = { w:%.4f, h:%.4f }", #size, size.width, size.height)
#define kLogRect(rect)      NSLog(@"%s = { x:%.4f, y:%.4f, w:%.4f, h:%.4f }", #rect, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)
#endif


/*************************  内存相关  *************************/

/** 使用ARC和不使用ARC */
#if __has_feature(objc_arc)
//  compiling with ARC
#else
//  compiling without ARC
#endif

/** 释放对象 */
#if !__has_feature(objc_arc)

/** 释放一个对象 */
#define kRelease_safely(__POINTER) { [__POINTER release]; __POINTER = nil; }

/** 释放一个对象 */
#define kDelete_safely(__POINTER) if(__POINTER) { [__POINTER release], __POINTER = nil; }

#endif


#pragma mark -
#pragma mark - 单例

/*************************  ARC和MRC环境下的单例宏代码  *************************/

/** 定义.h文件中类方法 */
#define singleton_h(name) + (instancetype)shared##name;


/*************************  单例化一个类  *************************/

#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [[self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}


/*************************  使用GCD实现单例  *************************/

/** 当前是MRC环境 */
#if !__has_feature(objc_arc)

#define singleton_m_GCD(name) \
static id _instance = nil; \
+ (instancetype)shared##name \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [[self alloc] init]; \
} \
}); \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
}); \
return _instance; \
} \
\
- (oneway void)release \
{ \
} \
\
- (instancetype)autorelease \
{ \
return _instance; \
} \
\
- (instancetype)retain \
{ \
return _instance; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
} \
\
-(NSUInteger)retainCount \
{ \
return 1; \
}


#else /** 当前是ARC环境 */

#define singleton_m_GCD(name) \
static id _instance = nil; \
+ (instancetype)shared##name \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [[self alloc] init]; \
} \
}); \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
}); \
return _instance; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
}

#endif


/*************************  使用@synchronized实现单例  *************************/

/** 当前是MRC环境 */
#if !__has_feature(objc_arc)

#define singleton_m_synchronized(name) \
static id _instance = nil; \
+ (instancetype)shared##name \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [[self alloc] init]; \
} \
} \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
} \
return _instance; \
} \
\
-(oneway void)release \
{ \
} \
\
- (instancetype)autorelease \
{ \
return _instance; \
} \
\
- (instancetype)retain \
{ \
return _instance; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
} \
\
- (NSUInteger)retainCount \
{ \
return 1; \
}

#else 

/** 当前是ARC环境 */
#define singleton_m_synchronized(name) \
static id _instance = nil; \
+ (instancetype)shared##name \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [[self alloc] init]; \
} \
} \
return _instance; \
} \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (_instance == nil) \
{ \
_instance = [super allocWithZone:zone]; \
} \
} \
return _instance; \
} \
\
+ (id)copyWithZone:(struct _NSZone *)zone \
{ \
return _instance; \
}

#endif





#endif

