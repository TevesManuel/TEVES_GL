#include <TevesGL/Teves.h>

TEVES_Color background;//Declare Teves Color variable

void update()//Define update function
{
    TEVES_Clear(background);//Clean window with TEVES_Color variable
    TEVES_SetDrawColor(TEVES_InitColor(255,255,255,255));//Setting color for drawing directly RGBA values
    TEVES_DrawRectA(10, 10, 100, 100);//Draw rect with color white
}

int main()//Define main function
{
    TEVES_Window win;//Declare window

    TEVES_Init();//Init library

    TEVES_InitWindow(&win, "Render Text Test", 400, 400, TEVES_TRUE);//Create window
    
    TEVES_SetUpdate(&win, &update);//Set update function

    background = TEVES_InitColor(0, 0, 0, 255);//Define color with RGBA


    TEVES_Loop(&win);//Init loop with update function
    
    TEVES_TERMINATE();//Shutdown library
    return TEVES_OK;
}