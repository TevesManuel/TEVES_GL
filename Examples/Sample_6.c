#include "./TevesGL/Teves.h"
#include <stdio.h>
#include <stdlib.h>

TEVES_Window window;
TEVES_Keyboard Keyboard;
TEVES_Color Background_Color;

float a = 1.0f;

float a_object = 1.0f;
int vm;

int isDEBUG = TEVES_FALSE;
float vel_window = 200.0f;

void InputFunction()
{
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_A))
    {
        if(isDEBUG)
            printf("You has been pressed A key.\n");
        TEVES_SetAttribute(&window, TEVES_REZISABLE);
    }
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_Q))
    {
        if(isDEBUG)
            printf("You has been pressed Q key.\n");
        TEVES_SetAttribute(&window, TEVES_UNREZISABLE);
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_D))
    {
        if(isDEBUG)
            printf("You has been pressed D key.\n");
        TEVES_DisableSyncFPS(&window);
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_S))
    {
        if(isDEBUG)
            printf("You has been pressed S key.\n");
        TEVES_SyncFPS(&window, 60);
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_W))
    {
        if(isDEBUG)
            printf("You has been pressed W key.\n");
        TEVES_SyncFPS(&window, 30);
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_R))
    {
        if(isDEBUG)
            printf("You has been pressed R key.\n");
        a += 0.25f;
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_F))
    {
        if(isDEBUG)
            printf("You has been pressed F key.\n");
        a -= 0.25f;
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_T))
    {
        if(isDEBUG)
            printf("You has been pressed T key.\n");
        Background_Color.a = Background_Color.a + 255/4;
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_G))
    {
        if(isDEBUG)
            printf("You has been pressed G key.\n");
        Background_Color.a = Background_Color.a - 255/4;
    }
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_Y))
    {
        if(isDEBUG)
            printf("You has been pressed Y key.\n");
        TEVES_SetAttribute(&window, TEVES_ENABLE_TRANSPARENTWINDOW);
    }
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_H))
    {
        if(isDEBUG)
            printf("You has been pressed H key.\n");
        TEVES_SetAttribute(&window, TEVES_DISABLE_TRANSPARENTWINDOW);
    }
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_U))
    {
        if(isDEBUG)
            printf("You has been pressed U key.\n");
        TEVES_SetAttribute(&window, TEVES_ENABLE_TITLEBAR);
    }
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_J))
    {
        if(isDEBUG)
            printf("You has been pressed J key.\n");
        TEVES_SetAttribute(&window, TEVES_DISABLE_TITLEBAR);
    }
    if(TEVES_GetMouseUp(&window, TEVES_MOUSEBUTTON_LEFT, &vm))
    {
        printf("Click\n");
    }
    if(TEVES_GetKey(&Keyboard, TEVES_KEY_UP))
    {
        // printf("You has been pressed Up Arrow Key.\n");
        int x;
        int y;
        TEVES_WindowGetPos(&window, &x, &y);
        TEVES_WindowSetPos(&window, x, (y-(vel_window * window.deltaTime)));
    }
    if(TEVES_GetKey(&Keyboard, TEVES_KEY_LEFT))
    {
        // printf("You has been pressed Left Arrow Key.\n");
        int x;
        int y;
        TEVES_WindowGetPos(&window, &x, &y);
        TEVES_WindowSetPos(&window, (x-(vel_window * window.deltaTime)), y);
    }
    if(TEVES_GetKey(&Keyboard, TEVES_KEY_RIGHT))
    {
        // printf("You has been pressed Right Arrow Key.\n");
        int x;
        int y;
        TEVES_WindowGetPos(&window, &x, &y);
        TEVES_WindowSetPos(&window, (x+(vel_window * window.deltaTime)), y);
    }
    if(TEVES_GetKey(&Keyboard, TEVES_KEY_DOWN))
    {
        // printf("You has been pressed Down Arrow Key.\n");
        int x;
        int y;
        TEVES_WindowGetPos(&window, &x, &y);
        TEVES_WindowSetPos(&window, x, (y+(vel_window * window.deltaTime)));
    }
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_0))
    {
        if(isDEBUG)
            isDEBUG = TEVES_FALSE;
        else
            isDEBUG = TEVES_TRUE;
    }
    // printf("X: %d, Y: %d\n", window.x, window.y);
    // printf("FPS: %f\nDeltaTime: %f\nDeltaTime Count: %f\n", window.fps, window.deltaTime, window.deltaTimeC);
}
void Update()
{
    TEVES_UpdateKeyboard(&Keyboard);

    Background_Color.r = 0.0f;
    Background_Color.g = 0.0f;
    Background_Color.b = 0.0f;
    Background_Color.a = 0.0f;
    InputFunction();
    if(TEVES_GetKey(&Keyboard, TEVES_KEY_SPACE))
    {
        // printf("Detect\n");
    }
    if(TEVES_GetKeyUp(&Keyboard, TEVES_KEY_SPACE))
    {
        printf("A\n");
        TEVES_SetPauseWindow(&window, TEVES_FALSE);
    }
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_SPACE))
    {
        printf("B\n");
        TEVES_SetPauseWindow(&window, TEVES_TRUE);
    }

    TEVES_Clear(Background_Color);    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(window.w/2.0f, window.h/2.0f, 0.0f);
    glRotatef((float) window.deltaTimeC * 100.f, 0.f, 0.f, 1.f);
    
    glBegin(GL_TRIANGLES);
        glColor4f(1.f, 0.f, 0.f, a); glVertex3f(window.w * 0.0f,   window.h * -0.33f, 0.f);
        glColor4f(0.f, 1.f, 0.f, a); glVertex3f(window.w * 0.33f,  window.h * 0.33f, 0.f);
        glColor4f(0.f, 0.f, 1.f, a); glVertex3f(window.w * -0.33f, window.h * 0.33f, 0.f);
    glEnd();

    glPopMatrix();

    TEVES_WindowRefresh(&window);
    // printf("w: %d, h: %d\n", window.w, window.h);
    // printf("Window pos: (%d, %d)\n", window.x, window.y);
}

int main()
{
    printf("-----------------------------------------\n");
    printf("-                 MANUAL                -\n");
    printf("-----------------------------------------\n");
    printf("       Q      -> Change to no rezisable window.\n");
    printf("       A      -> Change to rezisable window.\n");
    printf("       W      -> Sync 30 FPS.\n");
    printf("       S      -> Sync 60 FPS.\n");
    printf("       D      -> Unlock FPS.\n");
    printf("       R      -> + Alpha triangle.\n");
    printf("       F      -> - Alpha triangle.\n");
    printf("       T      -> + Alpha background.\n");
    printf("       G      -> - Alpha background.\n");
    printf("       Y      -> Enable transparent window.\n");
    printf("       H      -> Disable transparent window.\n");
    printf("       U      -> Enable titlebar.\n");
    printf("       J      -> Disable titlebar.\n");
    printf("       0      -> Switch debug mode (default off).\n");
    printf("       Arrows -> Move window.\n");
    Background_Color = TEVES_InitColor(30, 30, 30, 255);
    TEVES_Init();
    TEVES_SetAttribute(&window, TEVES_UNREZISABLE);
    TEVES_InitWindow(&window, "TEVES WINDOW ENGINE TEST", 640, 480, TEVES_TRUE);
    TEVES_SetUpdate(&window, &Update);
    TEVES_SyncFPS(&window, 60);
    TEVES_SetAttribute(&window, TEVES_DISABLE_AUTOREFRESH);

    TEVES_InitKeyboard(&Keyboard, &window);

    TEVES_Loop(&window);
    TEVES_DeleteWindow(&window);
    TEVES_TERMINATE();
    return 0;
}
