//
//  ViewController.m
//  RecoardTool
//
//  Created by Superman on 2018/7/2.
//  Copyright © 2018年 Superman. All rights reserved.
//

#import "ViewController.h"
#import "RecordHUD.h"
#import "RecordButton.h"

@interface ViewController ()<RecordDelegate>
@property (strong, nonatomic)  RecordButton *btn;
@property (strong, nonatomic)  RecordButton *centerBtn;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _btn=[[RecordButton alloc]initWithFrame:CGRectMake(([UIScreen mainScreen].bounds.size.width-80)/2, 100, 80, 50)];
    [_btn setTitle:@"录音" forState:UIControlStateNormal];
    [_btn setTitleColor:[UIColor grayColor] forState:UIControlStateNormal];
    _btn.backgroundColor=[UIColor yellowColor];
    [self.view addSubview:_btn];
    
    _centerBtn=[[RecordButton alloc]initWithFrame:CGRectMake(([UIScreen mainScreen].bounds.size.width-100)/2, CGRectGetMaxY(_btn.frame)+50, 100, 60)];
    [_centerBtn setTitle:@"开始录音" forState:UIControlStateNormal];
    [_centerBtn setTitleColor:[UIColor grayColor] forState:UIControlStateNormal];
    _centerBtn.backgroundColor=[UIColor yellowColor];
    [self.view addSubview:_centerBtn];
    
    [_btn initRecord:self maxtime:10 title:@"上滑取消录音"];
    [_centerBtn initRecord:self maxtime:5];
}

-(void)endRecord:(NSData *)voiceData{
    NSError *error;
    play = [[AVAudioPlayer alloc]initWithData:voiceData error:&error];
    NSLog(@"%@",error);
    play.volume = 1.0f;
    [play play];
    NSLog(@"yesssssssssss..........%f",play.duration);
    [_btn setTitle:@"按住录音" forState:UIControlStateNormal];
}

//不改btn的话这些就不要了
-(void)dragExit{
    [_btn setTitle:@"按住录音" forState:UIControlStateNormal];
}


-(void)dragEnter{
    [_btn setTitle:@"松开发送" forState:UIControlStateNormal];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
