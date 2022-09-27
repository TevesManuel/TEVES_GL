#pragma once

struct TEVES_Color
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
};
typedef struct TEVES_Color TEVES_Color;

TEVES_Color TEVES_InitColor(int r, int g, int b, int a);
TEVES_Color TEVES_InitColorA(int rgb);
TEVES_Color TEVES_RGBA(int r, int g, int b, int a);
TEVES_Color TEVES_IntermediateColor(TEVES_Color a, TEVES_Color b);