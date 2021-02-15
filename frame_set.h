#ifndef FRAME_H
#define FRAME_H
#include <stdint.h>
#include <stdio.h>

#define TOO_FAR 1000
#define NEAR 800
#define EMPTY_LINE {TOO_FAR, TOO_FAR, TOO_FAR, TOO_FAR, TOO_FAR, TOO_FAR, TOO_FAR, TOO_FAR}
#define EMPTY_FRAME {{EMPTY_LINE,EMPTY_LINE,EMPTY_LINE,EMPTY_LINE,EMPTY_LINE,EMPTY_LINE,EMPTY_LINE,EMPTY_LINE}}
#define EMPTY_SET {EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME, EMPTY_FRAME}



typedef struct {
    uint16_t frame[8][8];
} Frame;

typedef struct{
    Frame set[10];
} FrameSet10;



void move_cube_AB_10(FrameSet10 *s);
void move_cube_BA_10(FrameSet10 *s);
void print_set(FrameSet10 *s);

#endif