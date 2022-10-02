#ifndef  TEVES_GL
#define TEVES_GL

#ifdef __cplusplus
extern "C"{
#endif 

//DEFINICIONES

typedef unsigned int TEVES_MODE;
typedef unsigned int TEVES_FLAG;
typedef unsigned int TEVES_BOOL;

#define TEVES_OK      0
#define TEVES_ERROR   1

#define TEVES_NULL   0

#define TEVES_TRUE   1
#define TEVES_FALSE   0

#define DEV_TEVES_SIZE_KEYBOARD_ARRAY 400

#include "./Basics/window.h"
#include "./Basics/Graphics/Color.h"
#include "./Basics/Graphics/BasicGraphics.h"
#include "./Basics/Objects/TTransform.h"
#include "./Basics/Objects/TPhysical.h"
#include "./Basics/Objects/TImage.h"
#include "./Basics/Objects/TAnimation.h"
#include "./Basics/Objects/TAnimator.h"
#include "./Basics/Objects/TFont.h"
#include "./Basics/Objects/TObject.h"
#include "./Basics/Input.h"

unsigned int TEVES_TERMINATE();
unsigned int TEVES_wait(int ms);
float TEVES_randomW(int min, int max);
float TEVES_randomA(int max);

#ifdef __cplusplus
}
#endif

#endif