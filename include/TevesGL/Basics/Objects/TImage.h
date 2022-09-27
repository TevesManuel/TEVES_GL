#pragma once

#include "./../../Teves.h"

#define TEVES_IMAGE_RGB_MODE     0x00000001L
#define TEVES_IMAGE_RGBA_MODE    0x00000002L
#define TEVES_IMAGE_CENTER_ALIGN 0x00000010L
#define TEVES_IMAGE_LEFT_ALIGN   0x00000020L

struct TEVES_Image
{
    int width_px;
    int height_px;
    TEVES_Transform transform;
    unsigned int texture;
    unsigned char mode;
    TEVES_MODE align;
};
typedef struct TEVES_Image TEVES_Image;

unsigned int TEVES_Image_LoadImage(TEVES_Image * _teves_image, const char * ImagePath, TEVES_MODE _mode);
unsigned int TEVES_Image_LoadImageA(TEVES_Image * _teves_image, const char * ImagePath);
unsigned int TEVES_Image_Draw(TEVES_Image * _timage);
unsigned int TEVES_Image_DrawSpecify(TEVES_Image * _timage, float fromx, float tox, float fromy, float toy);