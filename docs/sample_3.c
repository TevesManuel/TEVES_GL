#include <TevesGL/Teves.h>
#include <stdio.h>

TEVES_Window win;//Declare window

TEVES_Color background;//Declare Teves Color variable
TEVES_Keyboard keyboard;//Declare Teves keyboard

TEVES_Image image;

float vel = 25.0f;
float velScale = 25.0f;

void update()//Define update function
{
    TEVES_UpdateKeyboard(&keyboard);//Update the keyboard
    TEVES_Clear(background);//Clean window with TEVES_Color variable
    TEVES_SetDrawColor(TEVES_InitColor(255,255,255,255));//Setting color for drawing directly RGBA values
    if(TEVES_GetKey(&keyboard, TEVES_KEY_LEFT))
        image.transform.x += vel * win.deltaTime * -1; //Move image to left
    if(TEVES_GetKey(&keyboard, TEVES_KEY_RIGHT))
        image.transform.x += vel * win.deltaTime; //Move image to right
    if(TEVES_GetKey(&keyboard, TEVES_KEY_UP))
    {
        image.transform.width += velScale * win.deltaTime; //Scale in width +
        image.transform.height += velScale * win.deltaTime; //Scale in height +
    }
    if(TEVES_GetKey(&keyboard, TEVES_KEY_DOWN))
    {
        image.transform.width += velScale * win.deltaTime * -1; //Scale in width -
        image.transform.height += velScale * win.deltaTime * -1; //Scale in height -
    }
    TEVES_Image_Draw(&image);//Draw image
}

int main()//Define main function
{
    TEVES_Init();//Init library

    TEVES_InitWindow(&win, "Render Text Test", 400, 400, TEVES_TRUE);//Create window
    
    TEVES_SetUpdate(&win, &update);//Set update function

    TEVES_InitKeyboard(&keyboard, &win);//link keyboard with window

    background = TEVES_InitColor(0, 0, 0, 255);//Define color with RGBA

    TEVES_Image_LoadImage(&image, "./sample_image.png", TEVES_IMAGE_RGBA_MODE);//Load image and specify i want transparent

    //Initialize image
    image.transform.y = win.h*0.2;
    image.transform.width = 100;
    image.transform.height = 100;

    TEVES_Loop(&win);//Init loop with update function
    
    TEVES_TERMINATE();//Shutdown library
    return TEVES_OK;
}