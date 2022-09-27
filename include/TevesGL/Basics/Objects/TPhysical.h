#pragma once

#include "./../../Teves.h"

struct TEVES_Physical
{
    float offset_x;
    float offset_y;
    float offset_w;
    float offset_h;
    TEVES_Transform hitbox;
    TEVES_Transform transform;
};
typedef struct TEVES_Physical TEVES_Physical;

unsigned int TEVES_Physical_Update(TEVES_Physical * teves_physic_object);
float TEVES_Physical_getPhysicX(TEVES_Physical * teves_physic_object);
float TEVES_Physical_getPhysicY(TEVES_Physical * teves_physic_object);
float TEVES_Physical_getPhysicW(TEVES_Physical * teves_physic_object);
float TEVES_Physical_getPhysicH(TEVES_Physical * teves_physic_object);
unsigned int TEVES_Physical_DrawHitBox(TEVES_Transform _tt);
unsigned int TEVES_Physical_DrawHitBoxW(TEVES_Transform _tt, TEVES_Color _tcolor);