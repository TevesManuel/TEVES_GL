#pragma once

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include "./../../Teves.h"

#define TEVES_FONT_ALIGN_LEFT   0x00000000L
#define TEVES_FONT_ALIGN_CENTER 0x00000001L
#define TEVES_FONT_ALIGN_RIGHT  0x00000002L

typedef struct TEVES_Font
{
    FT_Library ft;
    FT_Face face;
    TEVES_Color _color;
    TEVES_BOOL iscolorated;
    unsigned int letterspace;
    TEVES_MODE mode;
}TEVES_Font;

unsigned int TEVES_InitFont    (TEVES_Font * tfont, const char * font_path, unsigned int font_size, TEVES_MODE _mode);
unsigned int TEVES_InitFontW   (TEVES_Font * tfont, const char * font_path, unsigned int font_size, TEVES_Color _color, TEVES_MODE _mode);
unsigned int TEVES_FontDrawChar(TEVES_Font * tfont, char a, float x, float y);
unsigned int TEVES_FontDrawText(TEVES_Font * tfont, const char * a, float x, float y);
unsigned int TEVES_FontSetColor(TEVES_Font * tfont, TEVES_Color _color);