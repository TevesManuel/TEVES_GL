#pragma once

#include "./../../Teves.h"

#define TEVES_ANIMATION_REPETEABLE     0
#define TEVES_ANIMATION_NOT_REPETEABLE 1

struct TEVES_Anim
{
    int width_px;
    int height_px;
    TEVES_Transform transform;
    unsigned int texture;
    TEVES_MODE mode;
    unsigned int AnimMode;
    unsigned int current_frame;
    unsigned int frames;
    unsigned int rows;
    unsigned int current_row;
    unsigned int finished;
    float * time;
    float time_to_new_frame;
    int id;
    void (*callback)(struct TEVES_Anim);
    TEVES_Image frame;
};
typedef struct TEVES_Anim TEVES_Anim;

unsigned int TEVES_Anim_LoadAnimationImage(TEVES_Anim * _tanim, const char * filepath, unsigned int frames, unsigned int rows, TEVES_MODE _mode);
unsigned int TEVES_Anim_LinkWindow(TEVES_Anim * _tanim, TEVES_Window * win);
unsigned int TEVES_Anim_Run(TEVES_Anim * _tanim, unsigned int fps);
unsigned int TEVES_Anim_SetNoRepeteable(TEVES_Anim * _tanim, void (*_callbackFunction)(TEVES_Anim));
unsigned int TEVES_Anim_restart(TEVES_Anim * _tanim);