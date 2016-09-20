//
//  ECDetailsViewController.m
//  ECTabBarController
//
//  Created by Jame on 09/20/2016.
//  Copyright (c) 2016 Jame. All rights reserved.
//

#import "ECDetailsViewController.h"
#import "ECTabBarController.h"
#import "ECMineViewController.h"
#import "ECSameCityViewController.h"
#import "ECHomeViewController.h"
@interface ECDetailsViewController ()

@end

@implementation ECDetailsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.title = @"详情页";
    self.view.backgroundColor = [UIColor whiteColor];
    
    UILabel *label = [[UILabel alloc] init];
    label.text = @"点击屏幕可跳转到“我的”，执行testPush";
    label.frame = CGRectMake(20, 150, CGRectGetWidth(self.view.frame) - 2 * 20, 20);
    label.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    label.textAlignment = NSTextAlignmentCenter;
    [self.view addSubview:label];
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self ec_popSelectTabBarChildViewControllerAtIndex:3 completion:^(__kindof UIViewController *selectedTabBarChildViewController) {
        ECMineViewController *mineViewController = selectedTabBarChildViewController;
        [mineViewController testPush];
    }];
}

@end
