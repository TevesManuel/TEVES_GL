#include <TevesGL/Teves.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

TEVES_Window window;
TEVES_Keyboard Keyboard;
TEVES_Window window2;
TEVES_Keyboard Keyboard2;

TEVES_Color Background_Color;
float a;

void InputFunction()
{
    TEVES_UpdateKeyboard(&Keyboard);
    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_A))
        printf("You pressed A in window 1\n");
}
void Update()
{
    Background_Color.r = 0.0f;
    Background_Color.g = 0.0f;
    Background_Color.b = 0.0f;
    Background_Color.a = 0.0f;
    InputFunction();

    TEVES_Clear(Background_Color);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(window.w/2.0f, window.h/2.0f, 0.0f);
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

    glBegin(GL_TRIANGLES);
    glColor4f(1.f, 0.f, 0.f, a); glVertex3f(window.w * 0.0f, window.h * -0.25f, 0.f);
    glColor4f(0.f, 1.f, 0.f, a); glVertex3f(window.w * 0.25f, window.h * 0.25f, 0.f);
    glColor4f(0.f, 0.f, 1.f, a); glVertex3f(window.w * -0.25f, window.h * 0.25f, 0.f);
    glEnd();
}
void InputFunction2()
{
    TEVES_UpdateKeyboard(&Keyboard2);
    if(TEVES_GetKeyDown(&Keyboard2, TEVES_KEY_A))
        printf("You pressed A in window 2\n");
}
void Update2()
{
    Background_Color.r = 0.0f;
    Background_Color.g = 0.0f;
    Background_Color.b = 0.0f;
    Background_Color.a = 0.0f;
    InputFunction2();

    TEVES_Clear(Background_Color);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(window2.w/2.0f, window2.h/2.0f, 0.0f);
    glRotatef((float) glfwGetTime() * -50.f, 0.f, 0.f, 1.f);

    glBegin(GL_TRIANGLES);
    glColor4f(1.f, 0.f, 0.f, a); glVertex3f(window2.w * 0.0f,   window2.h * -0.25f, 0.f);
    glColor4f(0.f, 1.f, 0.f, a); glVertex3f(window2.w * 0.25f,  window2.h * 0.25f, 0.f);
    glColor4f(0.f, 0.f, 1.f, a); glVertex3f(window2.w * -0.25f, window2.h * 0.25f, 0.f);
    glEnd();
}
void * main2(void * data)
{
    (void)data;
    TEVES_SetAttribute(&window2, TEVES_UNREZISABLE);
    TEVES_InitWindow(&window2, "W2", 400, 400, TEVES_TRUE);
    TEVES_SetUpdate(&window2, &Update2);
    TEVES_SyncFPS(&window2, 60);
    TEVES_InitKeyboard(&Keyboard2, &window2);
    printf("Window 2: %d\n", window2.live);
    TEVES_Loop(&window2);
    TEVES_DeleteWindow(&window2);
    return NULL;
}
int main()
{
    pthread_t thread_id;
    a = 1.0f;
    Background_Color = TEVES_InitColor(30, 30, 30, 255);
    TEVES_Init();
    TEVES_SetAttribute(&window, TEVES_UNREZISABLE);
    TEVES_InitWindow(&window, "W1", 400, 400, TEVES_TRUE);
    TEVES_SetUpdate(&window, &Update);
    TEVES_SyncFPS(&window, 60);
    TEVES_InitKeyboard(&Keyboard, &window);
    pthread_create(&thread_id, NULL, main2, NULL);
    printf("Window 1: %d\n", window.live);
    TEVES_Loop(&window);
    TEVES_DeleteWindow(&window);
    pthread_join(thread_id, NULL);
    TEVES_TERMINATE();
    return 0;
}
