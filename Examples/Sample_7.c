#include <TevesGL/Teves.h>
#include <stdio.h>
#include <stdlib.h>

TEVES_Window win;

TEVES_Color background;

TEVES_Font font;

float x = 200;
float y = 200;

void update()
{
    TEVES_Clear(background);

    TEVES_FontDrawText(&font, "Test text", x, y);
    TEVES_SetDrawColor(TEVES_InitColor(0,255,0,255));
    TEVES_DrawRectA(x, y, 10, 10);
}

int main()
{
    TEVES_Init();
    TEVES_InitWindow(&win, "Render Text Test", 400, 400, TEVES_TRUE);
    TEVES_SyncFPS(&win, 30);
    TEVES_SetUpdate(&win, &update);
    TEVES_SetAttribute(&win, TEVES_UNREZISABLE);
    TEVES_SetAttribute(&win, TEVES_ENABLE_TRANSPARENTWINDOW);
    TEVES_SetAttribute(&win, TEVES_DISABLE_TITLEBAR);
    TEVES_SetAttribute(&win, TEVES_ENABLE_ALWAYS_ON_TOP);

    background = TEVES_InitColor(0,0,0,255);
    
    TEVES_InitFontW(&font, "./arial.ttf", 80, TEVES_InitColor(258, 128, 0, 255), TEVES_FONT_ALIGN_LEFT);

    TEVES_Loop(&win);
    TEVES_TERMINATE();
}