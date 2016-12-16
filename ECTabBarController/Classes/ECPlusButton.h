//
//  ECPlusButton.h
//  ECTabBarController
//
//  Created by Jame on 09/20/2016.
//  Copyright (c) 2016 Jame. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ECConstants.h"
@class ECPlusButton;

@protocol ECPlusButtonSubclassing

@required
+ (id)plusButton;
@optional

/*!
 * 用来自定义加号按钮的位置，如果不实现默认居中。
 * @attention 以下两种情况下，必须实现该协议方法，否则 ECTabBarController 会抛出 exception 来进行提示：
                 1. 添加了 PlusButton 且 TabBarItem 的个数是奇数。
                 2. 实现了 `+plusChildViewController`。
 * @return 用来自定义加号按钮在 TabBar 中的位置。
 *
 */
+ (NSUInteger)indexOfPlusButtonInTabBar;

/*!
 * 该方法是为了调整 PlusButton 中心点Y轴方向的位置，建议在按钮超出了 tabbar 的边界时实现该方法。
 * @attention 如果不实现该方法，内部会自动进行比对，预设一个较为合适的位置，如果实现了该方法，预设的逻辑将失效。
 * @return 返回值是自定义按钮中心点Y轴方向的坐标除以 tabbar 的高度，
           内部实现时，会使用该返回值来设置 PlusButton 的 centerY 坐标，公式如下：
              `PlusButtonCenterY = multiplierOfTabBarHeight * taBarHeight + constantOfPlusButtonCenterYOffset;`
           也就是说：如果 constantOfPlusButtonCenterYOffset 为0，同时 multiplierOfTabBarHeight 的值是0.5，表示 PlusButton 居中，小于0.5表示 PlusButton 偏上，大于0.5则表示偏下。
 *
 */
+ (CGFloat)multiplierOfTabBarHeight:(CGFloat)tabBarHeight;

/*!
 * 见 `+multiplierOfTabBarHeight:` 注释：
 * `PlusButtonCenterY = multiplierOfTabBarHeight * taBarHeight + constantOfPlusButtonCenterYOffset;`
 * 也就是说： constantOfPlusButtonCenterYOffset 大于0会向下偏移，小于0会向上偏移。
 * @attention 实现了该方法，但没有实现 `+multiplierOfTabBarHeight:` 方法，在这种情况下，会在预设逻辑的基础上进行偏移。
 */
+ (CGFloat)constantOfPlusButtonCenterYOffsetForTabBarHeight:(CGFloat)tabBarHeight;

/*!
 * 实现该方法后，能让 PlusButton 的点击效果与跟点击其他 UITabBarButton 效果一样，跳转到该方法指定的 UIViewController 。
 * @attention 必须同时实现 `+indexOfPlusButtonInTabBar` 来指定 PlusButton 的位置。
 * @return 指定 PlusButton 点击后跳转的 UIViewController。
 *
 */
+ (UIViewController *)plusChildViewController;

#pragma mark - Deprecated API

+ (CGFloat)multiplerInCenterY EC_DEPRECATED("Deprecated in 1.6.0. Use `+multiplierOfTabBarHeight:` instead.");

@end

@class ECTabBar;

FOUNDATION_EXTERN UIButton<ECPlusButtonSubclassing> *ECExternPlusButton;
FOUNDATION_EXTERN UIViewController *ECPlusChildViewController;

@interface ECPlusButton : UIButton

+ (void)registerPlusButton;

- (void)plusChildViewControllerButtonClicked:(UIButton<ECPlusButtonSubclassing> *)sender;

@end

#pragma mark - Deprecated API

@interface ECPlusButton (ECDeprecated)

+ (void)registerSubclass EC_DEPRECATED("Deprecated in 1.6.0. Use `+[ECPlusButton registerPlusButton]` instead.");

@end
