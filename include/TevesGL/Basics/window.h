#pragma once

#include <time.h>

#ifndef _glfw3_h_
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#endif

#define TEVES_REZISABLE                 0x0001
#define TEVES_UNREZISABLE               0x0002
#define TEVES_ENABLE_TRANSPARENTWINDOW  0x0003
#define TEVES_DISABLE_TRANSPARENTWINDOW 0x0004
#define TEVES_ENABLE_TITLEBAR           0x0005
#define TEVES_DISABLE_TITLEBAR          0x0006
#define TEVES_ENABLE_AUTOREFRESH        0x0007
#define TEVES_DISABLE_AUTOREFRESH       0x0008
#define TEVES_ENABLE_EXITBUTTON         0x0009
#define TEVES_DISABLE_EXITBUTTON        0x0010
#define TEVES_ENABLE_ALWAYS_ON_TOP      0x0011
#define TEVES_DISABLE_ALWAYS_ON_TOP     0x0012
#define TEVES_DISABLE_TASKBARVISIBLE    0x0013
#define TEVES_ENABLE_TASKBARVISIBLE     0x0014

struct TEVES_Window
{
    GLFWwindow * winGLFW;
    int w;
    int h;
    const char * Title;
    int x;
    int y;
    void (*UpdateFunction)();
    float fps;
    unsigned int targetFPS;
    unsigned int isSyncFPS;
    unsigned int autoRefresh;
    unsigned int live;
    unsigned int paused;
    unsigned int onClose;
    unsigned int exitbuttonpermiss;
    unsigned int aot;
    unsigned int menubarview;
    float time;
    float deltaTime;//retraso FPS(Tiempo entre Frame & Frame)
    float deltaTimeC;//DeltaTime Count 
    float rFPS;//retraso FPS(Tiempo entre Frame & Frame)
    clock_t t_FPS;//Time intro FPS
};
typedef struct TEVES_Window TEVES_Window;
typedef int TEVES_DATA;
typedef int TEVES_STATE;

unsigned int TEVES_Init                   ();
unsigned int TEVES_InitWindow             (TEVES_Window * win,const char * Title, int w, int h, int IsAnUser);
unsigned int TEVES_SetUpdate              (TEVES_Window * win,  void (*function)());
unsigned int TEVES_Loop                   (TEVES_Window * win);
unsigned int TEVES_DeleteWindow           (TEVES_Window * win);
unsigned int TEVES_SetAttribute           (TEVES_Window * win, TEVES_DATA attr);
unsigned int TEVES_SyncFPS                (TEVES_Window * win, unsigned int FPS);
unsigned int TEVES_DisableSyncFPS         (TEVES_Window * win);
unsigned int TEVES_WindowGetPos           (TEVES_Window * win, int * x, int * y);
unsigned int TEVES_WindowSetPos           (TEVES_Window * win, unsigned int x, unsigned int y);
unsigned int TEVES_WindowGetSize          (TEVES_Window * win, int * w, int * h);
unsigned int TEVES_WindowSetSize          (TEVES_Window * win, unsigned int w, unsigned int h);
unsigned int TEVES_WindowRefresh          (TEVES_Window * win);
unsigned int TEVES_CloseWindow            (TEVES_Window * win);
unsigned int TEVES_SetPauseWindow         (TEVES_Window * win, TEVES_STATE state);