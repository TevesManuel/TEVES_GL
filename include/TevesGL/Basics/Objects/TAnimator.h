#pragma once

#include "./TAnimation.h"

struct TEVES_Animator
{
    TEVES_Transform transform;
    unsigned int _fps;
    TEVES_Anim anim;
};
typedef struct TEVES_Animator TEVES_Animator;

unsigned int TEVES_Animator_SetAnim(TEVES_Animator * _tanim, TEVES_Anim anim, unsigned int _fps);
unsigned int TEVES_Animator_Run(TEVES_Animator * _tanim);