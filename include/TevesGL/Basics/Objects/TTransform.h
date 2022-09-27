#pragma once

#include "./../../Teves.h"

struct TEVES_Transform
{
    float x;
    float y;
    float width;
    float height;
    unsigned int flipped_x;
    unsigned int flipped_y;
};
typedef struct TEVES_Transform TEVES_Transform;

unsigned int TEVES_Transform_DrawBox(TEVES_Transform _tt);
unsigned int TEVES_Transform_DrawBoxW(TEVES_Transform _tt, TEVES_Color _tcolor);