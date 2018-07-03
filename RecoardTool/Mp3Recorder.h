//
//  Mp3Recorder.h
//  RecoardTool
//
//  Created by Superman on 2018/7/3.
//  Copyright © 2018年 Superman. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol Mp3RecorderDelegate <NSObject>
- (void)failRecord;
- (void)beginConvert;
- (void)recording:(float)recordTime volume:(float)volume;
- (void)endConvertWithData:(NSData *)voiceData;
@end

@interface Mp3Recorder : NSObject{
    double lowPassResults;
    float recordTime;
    NSTimer *playTimer;
}
@property (nonatomic, weak) id<Mp3RecorderDelegate> delegate;

- (id)initWithDelegate:(id<Mp3RecorderDelegate>)delegate;
- (void)startRecord;
- (void)stopRecord;
- (void)cancelRecord;

@end
