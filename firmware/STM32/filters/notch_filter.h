#ifndef NOTCH_FILTER_H
#define NOTCH_FILTER_H

typedef struct
{
    float b0, b1, b2;
    float a1, a2;
    float x1, x2;
    float y1, y2;
} BiquadFilter;

void Notch_Init(BiquadFilter *f, float fs, float f0, float Q);
float Notch_Process(BiquadFilter *f, float x);

#endif
