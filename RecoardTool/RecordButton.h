//
//  RecordButton.h
//  RecoardTool
//
//  Created by Superman on 2018/7/3.
//  Copyright © 2018年 Superman. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Mp3Recorder.h"
#import "lame.h"
#import <AVFoundation/AVFoundation.h>

@protocol RecordDelegate <NSObject>
- (void)endRecord:(NSData *)voiceData;

@optional
- (void)recording:(float) recordTime;
- (void)dragExit;
- (void)dragEnter;
@end
@interface RecordButton : UIButton<Mp3RecorderDelegate>{
    int maxTime;
    Mp3Recorder *mp3;
    NSString *title;
}

@property (nonatomic,weak) id<D3RecordDelegate> delegate;

- (void)initRecord:(id<RecordDelegate>)delegate maxtime:(int)_maxTime title:(NSString*)title;
- (void)initRecord:(id<RecordDelegate>)delegate maxtime:(int)_maxTime;
- (void)startRecord;
- (void)stopRecord;
- (void)cancelRecord;



@end
