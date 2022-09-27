#pragma once
#ifndef _glfw3_h_
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#endif

//<-------- KEYBOARD KEYS
#define TEVES_KEY_A         GLFW_KEY_A
#define TEVES_KEY_B         GLFW_KEY_B
#define TEVES_KEY_C         GLFW_KEY_C
#define TEVES_KEY_D         GLFW_KEY_D
#define TEVES_KEY_E         GLFW_KEY_E
#define TEVES_KEY_F         GLFW_KEY_F
#define TEVES_KEY_G         GLFW_KEY_G
#define TEVES_KEY_H         GLFW_KEY_H
#define TEVES_KEY_I         GLFW_KEY_I
#define TEVES_KEY_J         GLFW_KEY_J
#define TEVES_KEY_K         GLFW_KEY_K
#define TEVES_KEY_L         GLFW_KEY_L
#define TEVES_KEY_M         GLFW_KEY_M
#define TEVES_KEY_N         GLFW_KEY_N
#define TEVES_KEY_O         GLFW_KEY_O
#define TEVES_KEY_P         GLFW_KEY_P
#define TEVES_KEY_Q         GLFW_KEY_Q
#define TEVES_KEY_R         GLFW_KEY_R
#define TEVES_KEY_S         GLFW_KEY_S
#define TEVES_KEY_T         GLFW_KEY_T
#define TEVES_KEY_U         GLFW_KEY_U
#define TEVES_KEY_V         GLFW_KEY_V
#define TEVES_KEY_W         GLFW_KEY_W
#define TEVES_KEY_X         GLFW_KEY_X
#define TEVES_KEY_Y         GLFW_KEY_Y
#define TEVES_KEY_Z         GLFW_KEY_Z
#define TEVES_KEY_0         GLFW_KEY_0
#define TEVES_KEY_1         GLFW_KEY_1
#define TEVES_KEY_2         GLFW_KEY_2
#define TEVES_KEY_3         GLFW_KEY_3
#define TEVES_KEY_4         GLFW_KEY_4
#define TEVES_KEY_5         GLFW_KEY_5
#define TEVES_KEY_6         GLFW_KEY_6
#define TEVES_KEY_7         GLFW_KEY_7
#define TEVES_KEY_8         GLFW_KEY_8
#define TEVES_KEY_9         GLFW_KEY_9
#define TEVES_KEY_0_R       GLFW_KEY_KP_0
#define TEVES_KEY_1_R       GLFW_KEY_KP_1
#define TEVES_KEY_2_R       GLFW_KEY_KP_2
#define TEVES_KEY_3_R       GLFW_KEY_KP_3
#define TEVES_KEY_4_R       GLFW_KEY_KP_4
#define TEVES_KEY_5_R       GLFW_KEY_KP_5
#define TEVES_KEY_6_R       GLFW_KEY_KP_6
#define TEVES_KEY_7_R       GLFW_KEY_KP_7
#define TEVES_KEY_8_R       GLFW_KEY_KP_8
#define TEVES_KEY_9_R       GLFW_KEY_KP_9
#define TEVES_KEY_UP        GLFW_KEY_UP
#define TEVES_KEY_LEFT      GLFW_KEY_LEFT
#define TEVES_KEY_RIGHT     GLFW_KEY_RIGHT
#define TEVES_KEY_DOWN      GLFW_KEY_DOWN
#define TEVES_KEY_SPACE     GLFW_KEY_SPACE
#define TEVES_KEY_F1        GLFW_KEY_F1
#define TEVES_KEY_F2        GLFW_KEY_F2
#define TEVES_KEY_F3        GLFW_KEY_F3
#define TEVES_KEY_F4        GLFW_KEY_F4
#define TEVES_KEY_F5        GLFW_KEY_F5
#define TEVES_KEY_F6        GLFW_KEY_F6
#define TEVES_KEY_F7        GLFW_KEY_F7
#define TEVES_KEY_F8        GLFW_KEY_F8
#define TEVES_KEY_F9        GLFW_KEY_F9
#define TEVES_KEY_F10       GLFW_KEY_F10
#define TEVES_KEY_F11       GLFW_KEY_F11
#define TEVES_KEY_F12       GLFW_KEY_F12
#define TEVES_KEY_BACKSPACE GLFW_KEY_BACKSPACE
#define TEVES_KEY_DELETE    GLFW_KEY_DELETE
#define TEVES_KEY_LCONTROL  GLFW_KEY_LEFT_CONTROL
#define TEVES_KEY_RCONTROL  GLFW_KEY_RIGHT_CONTROL
#define TEVES_KEY_LSHIFT    GLFW_KEY_LEFT_SHIFT
#define TEVES_KEY_RSHIFT    GLFW_KEY_RIGHT_SHIFT
#define TEVES_KEY_TAB       GLFW_KEY_TAB
#define TEVES_KEY_LALT      GLFW_KEY_LEFT_ALT
#define TEVES_KEY_RALT      GLFW_KEY_RIGHT_ALT
#define TEVES_KEY_ENTER     GLFW_KEY_ENTER
#define TEVES_KEY_ESCAPE    GLFW_KEY_ESCAPE
//KEYBOARD KEYS ------>
//<----- MOUSE BUTTONS
#define TEVES_MOUSEBUTTON_LEFT     GLFW_MOUSE_BUTTON_LEFT
#define TEVES_MOUSEBUTTON_RIGHT    GLFW_MOUSE_BUTTON_RIGHT
#define TEVES_MOUSEBUTTON_MIDDLE   GLFW_MOUSE_BUTTON_MIDDLE
#define TEVES_MOUSEBUTTON_1        GLFW_MOUSE_BUTTON_1
#define TEVES_MOUSEBUTTON_2        GLFW_MOUSE_BUTTON_2
#define TEVES_MOUSEBUTTON_3        GLFW_MOUSE_BUTTON_3
#define TEVES_MOUSEBUTTON_4        GLFW_MOUSE_BUTTON_4
#define TEVES_MOUSEBUTTON_5        GLFW_MOUSE_BUTTON_5
#define TEVES_MOUSEBUTTON_6        GLFW_MOUSE_BUTTON_6
#define TEVES_MOUSEBUTTON_7        GLFW_MOUSE_BUTTON_7
#define TEVES_MOUSEBUTTON_8        GLFW_MOUSE_BUTTON_8
//MOUSE BUTTONS ------>
typedef int TEVES_KEY_CODE;
typedef int TEVES_MOUSE_BUTTON;

#define DEV_TEVES_SIZE_KEYBOARD_ARRAY 400

typedef struct TEVES_Keyboard
{
    TEVES_Window * win;
    int fr [DEV_TEVES_SIZE_KEYBOARD_ARRAY];
    int nfr[DEV_TEVES_SIZE_KEYBOARD_ARRAY];
}TEVES_Keyboard;

//KEYBOARD
unsigned int TEVES_GetKey         (TEVES_Keyboard * tk, TEVES_KEY_CODE key);
unsigned int TEVES_GetKeyDown     (TEVES_Keyboard * tk, TEVES_KEY_CODE key);
unsigned int TEVES_GetKeyUp       (TEVES_Keyboard * tk, TEVES_KEY_CODE key);
unsigned int TEVES_UpdateKeyboard (TEVES_Keyboard * tk);
unsigned int TEVES_InitKeyboard   (TEVES_Keyboard * tk, TEVES_Window * win);

unsigned int TEVES_GetKeyWnd      (TEVES_Window * win, TEVES_KEY_CODE key);
unsigned int TEVES_GetKeyDownWnd  (TEVES_Window * win, TEVES_KEY_CODE key, int * rv);
unsigned int TEVES_GetKeyUpWnd    (TEVES_Window * win, TEVES_KEY_CODE key, int * rv);

unsigned int TEVES_GetKeySys     (TEVES_Keyboard * tk, TEVES_KEY_CODE x);
unsigned int TEVES_GetKeyUpSys   (TEVES_Keyboard * tk, TEVES_KEY_CODE x);
unsigned int TEVES_GetKeyDownSys     (TEVES_Keyboard * tk, TEVES_KEY_CODE x);

//MOUSE
unsigned int TEVES_GetMouse(TEVES_Window * win, TEVES_MOUSE_BUTTON button);
unsigned int TEVES_GetMouseDown(TEVES_Window * win, TEVES_MOUSE_BUTTON button, int * rv);
unsigned int TEVES_GetMouseUp(TEVES_Window * win, TEVES_MOUSE_BUTTON button, int * rv);