#pragma once

#include "./../../Teves.h"

#define TEVES_TOBJECT_VERTEX 0
#define TEVES_TOBJECT_IMAGE  1
#define TEVES_TOBJECT_ANIM   2

struct TObject
{
    int id;
    TEVES_Animator  animator;
    TEVES_Image     image;
    TEVES_Physical  physic;
    TEVES_Transform transform;
    TEVES_MODE      mode;
    TEVES_Color     color;
    TEVES_BOOL      inCalibration;
    TEVES_BOOL      initializated;
};
typedef struct TObject TObject;

unsigned int TEVES_TObject_Update(TObject * _tobject);
unsigned int TEVES_TObject_CalibrateHitbox(TObject * _tobject, float min_v, float max_v , float step_v);
unsigned int TEVES_TObject_CalibrateTransform(TObject * _tobject, float min_v, float max_v , float step_v);