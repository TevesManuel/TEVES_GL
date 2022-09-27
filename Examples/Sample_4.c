#include <TevesGL/Teves.h>
#include <stdio.h>
#include <stdlib.h>

TEVES_Window window;
TEVES_Keyboard Keyboard;
TEVES_Color Background_Color;

unsigned int texture;

int width, height, nrChannels;

TEVES_Anim anim;

void Update()
{
    TEVES_UpdateKeyboard(&Keyboard);
    glColor3f(1.0f, 1.0f, 1.0f);

    TEVES_Clear(Background_Color);       

    TEVES_Anim_Run(&anim, 10);
    if(anim.finished)
        TEVES_Anim_restart(&anim);
    // printf("GLFWTIME: %.2f, WTIME: %.2f, ATIME: %.2f\n", glfwGetTime(), window.time, *anim.time);//==
}

void callback(TEVES_Anim anim_callback)
{
    (void)anim_callback;
    printf("Anim finished\n");
    // TEVES_Anim_restart(&anim);
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

    // TEVES_SetAttribute(&window, TEVES_ENABLE_TRANSPARENTWINDOW);
    // TEVES_SetAttribute(&window, TEVES_DISABLE_TITLEBAR);

    TEVES_Anim_LoadAnimationImage(&anim, "./media/Animation.png", 8, 2, TEVES_IMAGE_RGBA_MODE);
    // TEVES_Anim_LoadAnimationImage(&anim, "./media/Animation2.png", 8, 2, TEVES_IMAGE_RGBA_MODE);
    TEVES_Anim_LinkWindow(&anim, &window);    
    TEVES_Anim_SetNoRepeteable(&anim, &callback);
    
    anim.transform.x = 0;
    anim.transform.y = 0;
    anim.transform.width = window.w;
    anim.transform.height = window.h;

    TEVES_Loop(&window);
    TEVES_DeleteWindow(&window);
    TEVES_TERMINATE();
    return 0;
}
