#include <TevesGL/Teves.h>
#include <stdio.h>
#include <stdlib.h>

TEVES_Window window;
TEVES_Keyboard Keyboard;
TEVES_Color Background_Color;

TEVES_Image img;

void Update()
{
    TEVES_UpdateKeyboard(&Keyboard);

    TEVES_Clear(Background_Color);    

    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_SPACE))
    {
        if(img.transform.flipped_x && img.transform.flipped_x) 
        {
            img.transform.flipped_x = TEVES_FALSE;
            img.transform.flipped_y = TEVES_FALSE;
        }
        else
        {
            img.transform.flipped_x = TEVES_TRUE;
            img.transform.flipped_y = TEVES_TRUE;
        }
    }

    TEVES_Image_Draw(&img);
}

int main()
{    
    TEVES_Init();

    Background_Color = TEVES_InitColor(0, 0, 0, 0);

    TEVES_SetAttribute(&window, TEVES_UNREZISABLE);
    TEVES_InitWindow(&window, "TEVES WINDOW ENGINE TEST", 640, 480, TEVES_TRUE);
    TEVES_SetUpdate(&window, &Update);
    TEVES_SyncFPS(&window, 60);
    TEVES_SetAttribute(&window, TEVES_ENABLE_TRANSPARENTWINDOW);
    TEVES_SetAttribute(&window, TEVES_DISABLE_TITLEBAR);

    TEVES_InitKeyboard(&Keyboard, &window);

    //SUPPORT JPEG, PNG, BMP, TGA and PSD
    TEVES_Image_LoadImage(&img, "a.png", TEVES_IMAGE_RGBA_MODE);
    // TEVES_Image_LoadImageA(&img, "a.png");

    img.transform.x = 0.0f;
    img.transform.y = 0.0f;
    img.transform.width = window.w;
    img.transform.height = window.h;

    TEVES_Loop(&window);
    TEVES_DeleteWindow(&window);
    TEVES_TERMINATE();
    return 0;
}
