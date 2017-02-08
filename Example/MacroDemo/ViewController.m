//
//  ViewController.m
//  MacroDemo
//
//  Created by JPGK on 17/2/8.
//  Copyright © 2017年 WYC. All rights reserved.
//

#import "ViewController.h"
#import "DCMacroDefinition.h"
#import "DCSecondVC.h"

@interface ViewController ()
@property (nonatomic, strong) UIView *randomView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self discernScreenAndDevice];
    [self discernSystemAndApp];
    [self getDocumentPathAndSaveData];
    [self printLog];
}

#pragma mark - Screen Related / Hardware Related

- (void)discernScreenAndDevice
{
    if (kiPhone_SCREEN_3_5) {
        NSLog(@"The screen size is 3.5");
    }else if (kiPhone_SCREEN_4_0){
        NSLog(@"The screen size is 4.0");
    }else if (kiPhone_SCREEN_4_7){
        NSLog(@"The screen size is 4.7");
    }else if (kiPhone_SCREEN_5_5){
        NSLog(@"The screen size is 5.5");
    }
    
    if (kiPhone) {
        NSLog(@"The Deviece is iphone");
    }else if (kiPad){
        NSLog(@"The Deviece is ipad");
    }else if (kiPod){
        NSLog(@"The Deviece is ipod");
    }
}

#pragma mark - System Related / App Related

- (void)discernSystemAndApp
{
    if (kiOS10_OR_LATER) {
        NSLog(@"The system is iOS10 or later");
    }else if (kiOS9_OR_LATER) {
        NSLog(@"The system is iOS9 or later");
    }else if (kiOS8_OR_LATER) {
        NSLog(@"The system is iOS8 or later");
    }else if (kiOS7_OR_LATER) {
        NSLog(@"The system is iOS7 or later");
    }else if (kiOS6_OR_LATER){
        NSLog(@"The system is iOS6 or later");
    }
    
    NSString *iOSVersion = kiOS_VERSION;
    NSString *appVersion = kAPP_VERSION;
    NSString *buildVersion = kAPP_BUILD_VERSION;
    NSString *appName = kAPP_NAME;
    NSString *language = kLanguage_Current;
    NSLog(@"iOSVersion = %@, appVersion = %@, buildVersion = %@, appName = %@, language = %@", iOSVersion, appVersion, buildVersion, appName, language);
}

#pragma mark - Local Document Related

- (void)getDocumentPathAndSaveData
{
    NSString *documentsPath = kDocumentsPath;
    NSString *libraryPath = kLibraryPath;
    NSString *cachesPath = kCachesPath;
    NSString *tmpPath = kTmpPath;
    NSLog(@"documentsPath = %@, libraryPath = %@, cachesPath = %@, tmpPath = %@",documentsPath, libraryPath, cachesPath, tmpPath);
    
    NSArray *array = @[@"1",@"2",@"3"];
    kUserDefaultSave(@"key", array);
    NSArray *readArr = kUserDefaultRead(@"key");
    NSLog(@"%@", readArr);
    kUserDefaultDelete(@"key");
}

#pragma mark - Log Printing Related

- (void)printLog
{
    UIImageView *iv = [[UIImageView alloc]initWithFrame:CGRectMake(100, 150, 50, 50)];
    iv.image = kImageNamed(@"bg");
    [self.view addSubview:iv];
    
    kDLog(@"Create a ImageView");
    NSLog(@"The Second Printing");
    kULog(@"The Third Printing");
    TICK;
    TOCK;
    kLogRect(iv.frame);
}

#pragma mark - UI Handling Related

- (IBAction)addRandomColorView:(id)sender {
    
    if (_randomView) {
        _randomView.backgroundColor = kColorRandom;
    }else{
        self.randomView = [[UIView alloc]initWithFrame:CGRectMake(100, 250, kSCREEN_WIDTH - 200, kSCREENH_HEIGHT - 300)];
        _randomView.backgroundColor = kColorRandom;
        kMaskForView(_randomView, 30, 5, kColorWithRGB(0xffcd02));
        [self.view addSubview:_randomView];
    }
}
- (IBAction)removeRandomView:(id)sender {
    [_randomView removeFromSuperview];
}
- (IBAction)pushNextVC:(id)sender {
    DCSecondVC *secondVC = [[DCSecondVC alloc]init];
    [self.navigationController pushViewController:secondVC animated:YES];
}



@end
