//
//  DCSecondVC.m
//  MacroDemo
//
//  Created by JPGK on 17/2/8.
//  Copyright © 2017年 WYC. All rights reserved.
//

#import "DCSecondVC.h"
#import "DCMacroDefinition.h"

@interface DCSecondVC ()

@end

@implementation DCSecondVC

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    
    //custom backitem
    kCustomBackBarButtonItem(self, YES);
    //adaptive label
    [self adapteLabelByText];
}
- (void)backToFront
{
    NSLog(@"返回键的触发事件");
    [self.navigationController popViewControllerAnimated:YES];
}
- (void)adapteLabelByText
{
    UILabel *contentLabel = [[UILabel alloc]initWithFrame:CGRectMake(50, 150, kSCREEN_WIDTH - 100, 0)];
    contentLabel.textColor = kColorRandom;
    contentLabel.font = [UIFont systemFontOfSize:12];
    contentLabel.numberOfLines = 0;
    contentLabel.text = @"DC_蜗牛的博客:http://blog.csdn.net/wangyanchang21,\
    Ice 是一种面向对象的中间件，为构建面向对象的Client-Sever应用提供了工具、API 和库支持。Ice 应用适合于异构平台环境中使用：客户和服务器可以采用不同的编程语言，可以运行在不同的操作系统和机器架构上，并且可以使用多种网络技术进行通信。无论部署环境如何，这些应用的源码都是可移植的。\
    Ice 是 RPC 通信领域里最稳定、强大、高性能、跨平台、多语言支持的老牌开源中间件, 特别适合于当前互联网领域中一个平台存在多种开发语言编程,以及网站和 App 应用并存的复杂大型项目。Ice 实现了语言和平台中立, 高效通信, 通过与具体编程语言无关的中立语言 SlIce (Specification Language For Ice)来描述服务的接口,从而达到对象接口与其实现相分离的目的。";
    [self.view addSubview:contentLabel];
    
    CGSize textAutoSize = kAutoHeightSize_iOS7(contentLabel.text, contentLabel.font, kSCREEN_WIDTH - 100);
    contentLabel.frame = CGRectMake(CGRectGetMinX(contentLabel.frame), CGRectGetMinY(contentLabel.frame), CGRectGetWidth(contentLabel.frame), textAutoSize.height);
    NSLog(@"The auto height is %f", textAutoSize.height);
}


@end
