#pragma once

#include "./Color.h"

unsigned int TEVES_ClearRGBA         (float r, float g, float b, float a);
unsigned int TEVES_ClearRGB          (float r, float g, float b);
unsigned int TEVES_Clear             (TEVES_Color _color);
unsigned int TEVES_SetDrawColor      (TEVES_Color _color);
unsigned int TEVES_SetDrawColorRGB   (int r, int g, int b);
unsigned int TEVES_SetDrawColorRGBA  (int r, int g, int b, int a);
unsigned int TEVES_DrawRect          (float x, float y, float w, float h, float angle);
unsigned int TEVES_DrawRectA         (float x, float y, float w, float h);
