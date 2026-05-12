#include "notch_filter.h"
#include <math.h>

void Notch_Init(BiquadFilter *f, float fs, float f0, float Q)
{
    float w0 = 2.0f * 3.14159265359f * f0 / fs;
    float alpha = sinf(w0) / (2.0f * Q);
    float cos_w0 = cosf(w0);

    float b0 = 1.0f;
    float b1 = -2.0f * cos_w0;
    float b2 = 1.0f;
    float a0 = 1.0f + alpha;
    float a1 = -2.0f * cos_w0;
    float a2 = 1.0f - alpha;

    f->b0 = b0 / a0;
    f->b1 = b1 / a0;
    f->b2 = b2 / a0;
    f->a1 = a1 / a0;
    f->a2 = a2 / a0;

    f->x1 = 0.0f;
    f->x2 = 0.0f;
    f->y1 = 0.0f;
    f->y2 = 0.0f;
}

float Notch_Process(BiquadFilter *f, float x)
{
    float y = f->b0 * x
            + f->b1 * f->x1
            + f->b2 * f->x2
            - f->a1 * f->y1
            - f->a2 * f->y2;

    f->x2 = f->x1;
    f->x1 = x;

    f->y2 = f->y1;
    f->y1 = y;

    return y;
}
