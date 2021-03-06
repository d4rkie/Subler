//
//  MP42H264FileImporter.h
//  Subler
//
//  Created by Damiano Galassi on 07/12/10.
//  Copyright 2010 Damiano Galassi All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MP42FileImporter.h"

typedef struct framerate_t {
    uint32_t code;
    uint32_t timescale;
    uint32_t duration;
} framerate_t;
typedef struct

{
    struct
    {
        int size_min;
        int next;
        int cnt;
        int idx[17];
        int poc[17];
    } dpb;
    
    int cnt;
    int cnt_max;
    int *frame;
} h264_dpb_t;

@interface MP42H264Importer : MP42FileImporter {
    FILE* inFile;
    int64_t size;

    NSData *avcC;
    uint32_t timescale;
    uint32_t mp4FrameDuration;
    MP4SampleId samplesWritten;
    h264_dpb_t h264_dpb;

    NSThread *dataReader;
    NSInteger readerStatus;

    NSMutableArray *samplesBuffer;
    NSMutableArray *activeTracks;

    CGFloat progress;
}

@end