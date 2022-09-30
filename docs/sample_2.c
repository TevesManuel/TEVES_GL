#include <TevesGL/Teves.h>
#include <stdio.h>

TEVES_Color background;//Declare Teves Color variable
TEVES_Keyboard keyboard;//Declare Teves keyboard

void update()//Define update function
{
    TEVES_UpdateKeyboard(&keyboard);//Update the keyboard
    TEVES_Clear(background);//Clean window with TEVES_Color variable
    TEVES_SetDrawColor(TEVES_InitColor(255,255,255,255));//Setting color for drawing directly RGBA values
    TEVES_DrawRectA(10, 10, 100, 100);//Draw rect with color white
    if(TEVES_GetKey(&keyboard, TEVES_KEY_A))//Detect always if A is pressed in window
    {
        printf("A is pressed\n");
    }
    if(TEVES_GetKeyUp(&keyboard, TEVES_KEY_S))//Detect if S is released in window
    {
        printf("release S.\n");
    }
    if(TEVES_GetKeyDown(&keyboard, TEVES_KEY_S))//Detect if S is pressed in window
    {
        printf("pressed S.\n");
    }
    if(TEVES_GetKeyDownSys(&keyboard, TEVES_KEY_D))//Detect if S is pressed in system
    {
        printf("pressed D.\n");
    }
}

int main()//Define main function
{
    TEVES_Window win;//Declare window

    TEVES_Init();//Init library

    TEVES_InitWindow(&win, "Render Text Test", 400, 400, TEVES_TRUE);//Create window
    
    TEVES_SetUpdate(&win, &update);//Set update function

    TEVES_InitKeyboard(&keyboard, &win);

    background = TEVES_InitColor(0, 0, 0, 255);//Define color with RGBA

    TEVES_Loop(&win);//Init loop with update function
    
    TEVES_TERMINATE();//Shutdown library
    return TEVES_OK;
}