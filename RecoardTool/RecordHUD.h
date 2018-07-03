//
//  RecordHUD.h
//  RecoardTool
//
//  Created by Superman on 2018/7/3.
//  Copyright © 2018年 Superman. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface RecordHUD : UIView{
    UIImageView *imgView;
    UILabel *titleLabel;
    UILabel *timeLabel;
}
@property (nonatomic, strong, readonly) UIWindow *overlayWindow;

+ (void)show;

+ (void)dismiss;

+ (void)setTitle:(NSString*)title;

+ (void)setTimeTitle:(NSString*)time;

+ (void)setImage:(NSString*)imgName;
@end
