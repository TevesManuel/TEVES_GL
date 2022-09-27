#include <TevesGL/Teves.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL2_IMPLEMENTATION
#define NK_KEYSTATE_BASED_INPUT 

#ifndef NK_NUKLEAR_H_
#include "nuklear.h"
#include "nuklear_glfw_gl2.h"
#endif

TEVES_Window window;
TEVES_Color Background_Color;
struct nk_context * ctx;
struct nk_colorf bg;

char destination[] = "";

#define TEVES_CALCULATOREXAMPLE_ADD 1
#define TEVES_CALCULATOREXAMPLE_SUB 2
#define TEVES_CALCULATOREXAMPLE_MUL 3
#define TEVES_CALCULATOREXAMPLE_DIV 4

float n1;
float n2;
float r;
int   N1_SETTED;
int   OPERATION;

void clearDisplay();
void addNumber();

void addNumber(const char * x)
{
    printf("Entry is (%c)\n", *x);
    if((atof(destination) == 0.0f && *x != '.' && destination[1] != '.'))
        memset(destination, 0, sizeof(destination));
    strcat(destination, x);
}
void clearDisplay()
{
    memset(destination, 0, sizeof(destination));
    addNumber("0");
}
void Update()
{
    TEVES_ClearRGB(0,0,0);
    int x = 0;
    int y = 0;
    int w = window.w;
    int h = window.h;

    nk_glfw3_new_frame();

    if (nk_begin(ctx, "Show", nk_rect(x, y, w, h), NK_WINDOW_BORDER))
    {
        nk_layout_row_dynamic(ctx, h/6, 1);
        nk_label(ctx, destination, NK_TEXT_CENTERED);
        
        nk_layout_row_dynamic(ctx, h/6, 4);
        if (nk_button_label(ctx, "7"))
        {
            addNumber("7");
        }
        if (nk_button_label(ctx, "8"))
        {
            addNumber("8");
        }
        if (nk_button_label(ctx, "9"))
        {
            addNumber("9");
        }
        if (nk_button_label(ctx, "+"))
        {
            n1 = atof(destination);
            clearDisplay();
            N1_SETTED = TEVES_TRUE;
            OPERATION = TEVES_CALCULATOREXAMPLE_ADD;
        }
        nk_layout_row_dynamic(ctx, h/6, 4);
        if (nk_button_label(ctx, "4"))
        {
            addNumber("4");
        }
        if (nk_button_label(ctx, "5"))
        {
            addNumber("5");
        }
        if (nk_button_label(ctx, "6"))
        {
            addNumber("6");
        }
        if (nk_button_label(ctx, "-"))
        {
            n1 = atof(destination);
            clearDisplay();
            N1_SETTED = TEVES_TRUE;
            OPERATION = TEVES_CALCULATOREXAMPLE_SUB;
        }
        nk_layout_row_dynamic(ctx, h/6, 4);
        if (nk_button_label(ctx, "1"))
        {
            addNumber("1");
        }
        if (nk_button_label(ctx, "2"))
        {
            addNumber("2");
        }
        if (nk_button_label(ctx, "3"))
        {
            addNumber("3");
        }
        if (nk_button_label(ctx, "X"))
        {
            n1 = atof(destination);
            clearDisplay();
            N1_SETTED = TEVES_TRUE;
            OPERATION = TEVES_CALCULATOREXAMPLE_MUL;
        }
        nk_layout_row_dynamic(ctx, h/6, 5);
        if (nk_button_label(ctx, "0"))
        {
            addNumber("0");
        }
        if (nk_button_label(ctx, "."))
        {
            addNumber(".");
        }
        if (nk_button_label(ctx, "/"))
        {
            n1 = atof(destination);
            clearDisplay();
            N1_SETTED = TEVES_TRUE;
            OPERATION = TEVES_CALCULATOREXAMPLE_DIV;
        }
        if (nk_button_label(ctx, "C"))
        {
            OPERATION = TEVES_OK;
            n1        = TEVES_OK;
            n2        = TEVES_OK;
            r         = TEVES_OK;
            clearDisplay();
        }
        if (nk_button_label(ctx, "="))
        {
            if(N1_SETTED)
            {
                if(OPERATION == TEVES_CALCULATOREXAMPLE_ADD)
                {
                    n2 = atof(destination);
                    r = n1 + n2;
                    memset(destination, 0, sizeof(destination));
                    printf("ADD CASE(%.2f, %.2f): %f\n", n1, n2, r);
                    sprintf(destination, "%.2f", r);
                }
                if(OPERATION == TEVES_CALCULATOREXAMPLE_SUB)
                {
                    n2 = atof(destination);
                    r = n1 - n2;
                    memset(destination, 0, sizeof(destination));
                    printf("SUB CASE(%.2f, %.2f): %f\n", n1, n2, r);
                    sprintf(destination, "%.2f", r);
                }
                if(OPERATION == TEVES_CALCULATOREXAMPLE_MUL)
                {
                    n2 = atof(destination);
                    r = n1 * n2;
                    memset(destination, 0, sizeof(destination));
                    printf("MULTIPLICATION CASE(%.2f, %.2f): %f\n", n1, n2, r);
                    sprintf(destination, "%.2f", r);
                }
                if(OPERATION == TEVES_CALCULATOREXAMPLE_DIV)
                {
                    n2 = atof(destination);
                    r = n1 / n2;
                    memset(destination, 0, sizeof(destination));
                    printf("DIVISION CASE(%.2f, %.2f): %f\n", n1, n2, r);
                    sprintf(destination, "%.2f", r);
                }
            }
        }
    }
    // printf("RESULT: %s\n", destination);
    nk_end(ctx);
    nk_glfw3_render(NK_ANTI_ALIASING_ON);
}
int main(int argc, char * argv[])
{
    (void)argc;
    (void)argv;
    Background_Color = TEVES_InitColor(30, 30, 30, 255);
    TEVES_Init();
    TEVES_SetAttribute(&window, TEVES_UNREZISABLE);
    TEVES_InitWindow(&window, "TEVES CALCULATOR | NUKLEAR EXAMPLE", 400, 400, TEVES_TRUE);
    // TEVES_SetAttribute(&window, TEVES_ENABLE_TRANSPARENTWINDOW);
    // TEVES_SetAttribute(&window, TEVES_DISABLE_TITLEBAR);
    TEVES_SetAttribute(&window, TEVES_REZISABLE);
    // TEVES_WindowSetPos(&window, 0, 0);
    clearDisplay();

    ctx = nk_glfw3_init(window.winGLFW, NK_GLFW3_INSTALL_CALLBACKS);

    
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(&atlas);
    struct nk_font *font;
    const char *font_path = "./arial.ttf";
    font = nk_font_atlas_add_from_file(atlas, font_path, 82.0f, NULL);
    nk_glfw3_font_stash_end();

    nk_init_default(ctx, &font->handle);

    TEVES_SetUpdate(&window, &Update);
    TEVES_SyncFPS(&window, 60);
    TEVES_Loop(&window);
    TEVES_DeleteWindow(&window);
    
    TEVES_TERMINATE();
    nk_glfw3_shutdown();

    return 0;
}