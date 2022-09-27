#include <TevesGL/Teves.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEVES_Window window;
TEVES_Keyboard Keyboard;

TEVES_Image background;
#define HEART_BASE_X 60
#define HEART_JUMP_X 34
TEVES_Image heart_live;
TEVES_Image heart_died;
TEVES_Image bar_lives;

TEVES_Anim  idleAnim;
TEVES_Anim  runAnim;
TEVES_Anim  attackAnim;

TObject Player;

TEVES_BOOL ViewBoxesMode;

#define FPS_PLAYER_ANIM 10
#define FPS_ENEMY_ANIM  5

unsigned int EnemiesCounter;
#define SIZE_ENEMY_ARRAY 32
TObject Enemies[SIZE_ENEMY_ARRAY];
typedef struct EnemyPropertyObject
{
    int life;
    unsigned int hitted;
    float timeonlasthit;
    TEVES_BOOL isrunning;
}EnemyPropertyObject;

EnemyPropertyObject EnemiesProperties[SIZE_ENEMY_ARRAY];

TEVES_Anim idleAnimIA;
TEVES_Anim runAnimIA;
TEVES_Anim attackAnimIA;

#define PLAYER_INITIAL_LIVES 3
struct
{
    float player_hitted_time;
    int live;
    TEVES_BOOL hitted;
}PlayerProperties;

#define DIST_HITBOX_ATTACK_W 5

float deltaX;

int positionArray;
TObject newEnemies[SIZE_ENEMY_ARRAY];
EnemyPropertyObject newObject[SIZE_ENEMY_ARRAY];

#define TIME_ANIM_HITTED 0.5f

void add_Enemy()
{
    TEVES_Animator_SetAnim(&Enemies[EnemiesCounter].animator, idleAnimIA, 10);
    Enemies[EnemiesCounter].transform.x = 0;
    Enemies[EnemiesCounter].transform.y = 362;
    Enemies[EnemiesCounter].transform.width  = 80;
    Enemies[EnemiesCounter].transform.height = 80;
    Enemies[EnemiesCounter].physic.offset_x = 1.75;
    Enemies[EnemiesCounter].physic.offset_y = 27.25;
    Enemies[EnemiesCounter].physic.offset_w = -40;
    Enemies[EnemiesCounter].physic.offset_h = -26.25;
    Enemies[EnemiesCounter].initializated = TEVES_TRUE;
    Enemies[EnemiesCounter].id = EnemiesCounter;
    EnemiesProperties[EnemiesCounter].life = 3;
    EnemiesProperties[EnemiesCounter].timeonlasthit = -TIME_ANIM_HITTED;
    EnemiesCounter++;
}

void Updates()
{
    TEVES_UpdateKeyboard(&Keyboard);

    TEVES_TObject_Update(&Player);
    for(int i = 0; i < SIZE_ENEMY_ARRAY; i++)
    {
        if(Enemies[i].initializated)
        {
            TEVES_TObject_Update(&Enemies[i]);
        }
    }

    positionArray = 0;

    memset(newEnemies, 0, sizeof(newEnemies));
    memset(newObject, 0, sizeof(newObject));
    
    for(int i = 0; i < SIZE_ENEMY_ARRAY; i++)
    {
        if(Enemies[i].initializated && EnemiesProperties[i].life > 0)
        {
            newEnemies[positionArray] = Enemies[i];
            newObject[positionArray] = EnemiesProperties[i];
            positionArray++;
        }
    }
    for(int i = 0; i < SIZE_ENEMY_ARRAY; i++)
    {
        Enemies[i] = newEnemies[i];
        Enemies[i].id = i;
        EnemiesProperties[i] = newObject[i];
        if(EnemiesProperties[i].timeonlasthit + TIME_ANIM_HITTED > window.time)
            EnemiesProperties[i].hitted = TEVES_TRUE;
        else EnemiesProperties[i].hitted = TEVES_FALSE;
        Enemies[i].animator.anim.id = i;
    }
    if(PlayerProperties.player_hitted_time + TIME_ANIM_HITTED > window.time)
        PlayerProperties.hitted = TEVES_TRUE;
    else
        PlayerProperties.hitted = TEVES_FALSE;
}
void AnimatorManager()
{
    //ANIMATOR MANAGER
    if(Player.animator.anim.AnimMode != TEVES_ANIMATION_NOT_REPETEABLE ||
    (Player.animator.anim.AnimMode == TEVES_ANIMATION_NOT_REPETEABLE && Player.animator.anim.finished))
    {
        if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_SPACE))
        {
            TEVES_Animator_SetAnim(&Player.animator, attackAnim, FPS_PLAYER_ANIM);
        }
        else if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_A) || TEVES_GetKeyDown(&Keyboard, TEVES_KEY_LEFT) ||
        TEVES_GetKeyDown(&Keyboard, TEVES_KEY_D) || TEVES_GetKeyDown(&Keyboard, TEVES_KEY_RIGHT))
        {
            TEVES_Animator_SetAnim(&Player.animator, runAnim, FPS_PLAYER_ANIM);
        }
        else if(!TEVES_GetKey(&Keyboard, TEVES_KEY_A) && !TEVES_GetKey(&Keyboard, TEVES_KEY_LEFT) &&
        !TEVES_GetKey(&Keyboard, TEVES_KEY_D) && !TEVES_GetKey(&Keyboard, TEVES_KEY_RIGHT))
        {
            TEVES_Animator_SetAnim(&Player.animator, idleAnim, FPS_PLAYER_ANIM);
        }
    }
}
void PhysicalManager()
{
    //PHISICAL MANAGER
    if(TEVES_GetKey(&Keyboard, TEVES_KEY_A) || TEVES_GetKey(&Keyboard, TEVES_KEY_LEFT))
    {
        Player.transform.x = Player.transform.x - deltaX * window.deltaTime;
        Player.transform.flipped_x = TEVES_TRUE;
    }
    if(TEVES_GetKey(&Keyboard, TEVES_KEY_D) || TEVES_GetKey(&Keyboard, TEVES_KEY_RIGHT))
    {
        Player.transform.x = Player.transform.x + deltaX * window.deltaTime;
        Player.transform.flipped_x = TEVES_FALSE;
    }
}
void IA()
{
    //IA
    for(int i = 0; i < SIZE_ENEMY_ARRAY; i++)
    {
        if(Enemies[i].initializated)
        {
            if((Enemies[i].physic.hitbox.x + Enemies[i].physic.hitbox.width) < (Player.physic.hitbox.x - DIST_HITBOX_ATTACK_W))
            {
                Enemies[i].transform.flipped_x = TEVES_FALSE;
                Enemies[i].transform.x += deltaX * window.deltaTime * 0.5f;
                if(EnemiesProperties[i].isrunning == TEVES_FALSE)
                {
                    EnemiesProperties[i].isrunning = TEVES_TRUE;
                    TEVES_Animator_SetAnim(&Enemies[i].animator, runAnimIA, FPS_ENEMY_ANIM);
                }
            }
            else if((Enemies[i].physic.hitbox.x) > (Player.physic.hitbox.x + Player.physic.hitbox.width + DIST_HITBOX_ATTACK_W))
            {
                Enemies[i].transform.flipped_x = TEVES_TRUE;
                Enemies[i].transform.x += -deltaX * window.deltaTime * 0.5f;
            
                if(EnemiesProperties[i].isrunning == TEVES_FALSE)
                {
                    EnemiesProperties[i].isrunning = TEVES_TRUE;
                    TEVES_Animator_SetAnim(&Enemies[i].animator, runAnimIA, FPS_ENEMY_ANIM);
                }
            }
            else
            {
                if(EnemiesProperties[i].isrunning == TEVES_TRUE)
                {
                    EnemiesProperties[i].isrunning = TEVES_FALSE;
                    TEVES_Animator_SetAnim(&Enemies[i].animator, attackAnimIA, FPS_ENEMY_ANIM);
                }
            }
        }
    }
}
void GraphicalManager()
{
    //GRAPHICAL MANAGER
    TEVES_Clear(TEVES_InitColor(0,0,0,255));

    //Draw Background
    glColor3f(1.0f, 1.0f, 1.0f);
    TEVES_Image_Draw(&background);

    TEVES_Image_Draw(&bar_lives);
    for(int i = 0; i < PLAYER_INITIAL_LIVES; i++)
    {
        if(PlayerProperties.live > i)
        {
            heart_live.transform.x = HEART_BASE_X + HEART_JUMP_X * i;
            TEVES_Image_Draw(&heart_live);
        }
        else
        {
            heart_died.transform.x = HEART_BASE_X + HEART_JUMP_X * i;
            TEVES_Image_Draw(&heart_died);
        }
    }
    
    //Draw Player
    // glColor4f(1.0f,0.0f,0, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    if(PlayerProperties.hitted)
        TEVES_SetDrawColorRGB(255, 0, 0);
    TEVES_Animator_Run(&Player.animator);

    //Draw Enemies
    for(int i = 0; i < SIZE_ENEMY_ARRAY; i++)
        if(Enemies[i].initializated)
        {
            // printf("Enemy %d\nx: %.2f, y: %.2f\nwidth: %.2f, height: %.2f\n", i, Enemies[i].transform.x, Enemies[i].transform.y, Enemies[i].transform.width, Enemies[i].transform.height);       
            if(EnemiesProperties[i].hitted)
                TEVES_SetDrawColorRGB(255, 0, 0);
            else
                TEVES_SetDrawColorRGB(255,255,255);
            TEVES_Animator_Run(&Enemies[i].animator);
        }

}
void DrawBoxes()
{
    if(ViewBoxesMode)
    {
        for(int i = 0; i < SIZE_ENEMY_ARRAY; i++)
        {
            if(Enemies[i].initializated)
            {
                TEVES_Transform_DrawBox(Enemies[i].transform);
                TEVES_Physical_DrawHitBox(Enemies[i].physic.hitbox); // TEVES_Transform_DrawBoxW(Enemies[i].physic.hitbox, TEVES_InitColor(0, 255, 0, 255));
            }
        }

        TEVES_Transform_DrawBox(Player.transform);
        TEVES_Physical_DrawHitBox(Player.physic.hitbox);
    }
}
void Update()
{
    Updates();

    if(TEVES_GetKeyDown(&Keyboard, TEVES_KEY_K))
    {
        if(ViewBoxesMode)
            ViewBoxesMode = TEVES_FALSE;
        else
            ViewBoxesMode = TEVES_TRUE;
    }

    AnimatorManager();

    PhysicalManager();
    
    IA();

    GraphicalManager();
    
    printf("A: %d\n", window.aot);

    DrawBoxes();
    
    // printf("fx: %d, fy: %d\n", Player.transform.flipped_x, Player.transform.flipped_y);

    //Calibrate hitbox
    // TEVES_TObject_CalibrateHitbox(&Player, -100, 100, 0.25f);
    // TEVES_TObject_CalibrateTransform(&Player, -1000, 1000, 1);
    // TEVES_TObject_Calibrate(&Enemies[0], -100, 100, 0.25f);
}

void HitEnemy(int index)
{
    EnemiesProperties[index].life--;
    EnemiesProperties[index].timeonlasthit = window.time;
    printf("Enmemy hitted: {%d}, lives: {%d}\n", index, EnemiesProperties[index].life);
}
void callback_punchAnimation(TEVES_Anim anim)
{
    (void)anim;
    for(int i = 0; i < SIZE_ENEMY_ARRAY; i++)
    {
        if(Enemies[i].initializated)
        {
            if(Player.transform.flipped_x)
            {
                if(
                    (Enemies[i].physic.hitbox.x + Enemies[i].physic.hitbox.width >
                    Player.physic.hitbox.x - DIST_HITBOX_ATTACK_W)
                    &&
                    (Enemies[i].physic.hitbox.x + Enemies[i].physic.hitbox.width < 
                    Player.physic.hitbox.x + Player.physic.hitbox.width)
                  )
                {
                    HitEnemy(i);
                }
            }
            else
            {
                if(
                    (Enemies[i].physic.hitbox.x <
                    Player.physic.hitbox.x + Player.physic.hitbox.width + DIST_HITBOX_ATTACK_W)
                    &&
                    (Enemies[i].physic.hitbox.x > 
                    Player.physic.hitbox.x)
                )
                {
                    HitEnemy(i);
                }
            }
        }
    }
    TEVES_Animator_SetAnim(&Player.animator, runAnim, 10);
}
void callback_punchAnimationIA(TEVES_Anim anim)
{
    if(Enemies[anim.id].transform.flipped_x)
    {
        if(
            Enemies[anim.id].physic.hitbox.x - DIST_HITBOX_ATTACK_W <
            Player.physic.hitbox.x + Player.physic.hitbox.width
        )
        {
            PlayerProperties.player_hitted_time = window.time;
            PlayerProperties.live--;
        }
    }
    else
    {
        if(
            Enemies[anim.id].physic.hitbox.x + Enemies[anim.id].physic.hitbox.width + DIST_HITBOX_ATTACK_W >
            Player.physic.hitbox.x
        )
        {
            PlayerProperties.player_hitted_time = window.time;
            PlayerProperties.live--;
        }
    }
    TEVES_Animator_SetAnim(&Enemies[anim.id].animator, idleAnimIA, FPS_ENEMY_ANIM);
}

int main()
{    
    // if(0x00000000L & 0x00000001L)//FALSE
    // if(0x00000001L & 0x00000001L)//TRUE
    // if(0x00000001L & 0x00000002L)//FALSE
    // if((TEVES_IMAGE_RGB_MODE | TEVES_IMAGE_CENTER_ALIGN) & TEVES_IMAGE_RGB_MODE)//TRUE
    //     printf("TRUE");
    // else
    //     printf("FALSE");
    // return 0;
    
    printf("---------------------------------------\n");
    printf("-               CONTROLS              -\n");
    printf("---------------------------------------\n");
    printf("A or Left arrow to move for left.\n");
    printf("D or Right arrow to move for right.\n");
    printf("Space for attack.\n");
    deltaX = 50.0f;
    TEVES_Init();
    TEVES_SetAttribute(&window, TEVES_UNREZISABLE);
    TEVES_SetAttribute(&window, TEVES_DISABLE_TITLEBAR);
    TEVES_SetAttribute(&window, TEVES_ENABLE_ALWAYS_ON_TOP);
    TEVES_InitWindow(&window, "TEVES WINDOW ENGINE TEST", 640, 480, TEVES_TRUE);
    TEVES_SetUpdate(&window, &Update);
    TEVES_SyncFPS(&window, 60);

    TEVES_InitKeyboard(&Keyboard, &window);
    
    TEVES_Image_LoadImageA(&background, "./media/Background.png");

    background.transform.x = 0.0f;
    background.transform.y = 0.0f;
    background.transform.width = window.w;
    background.transform.height = window.h;

    TEVES_Image_LoadImage(&heart_live, "./media/heart-live.png", TEVES_IMAGE_RGBA_MODE);
    TEVES_Image_LoadImage(&heart_died, "./media/heart-dead.png", TEVES_IMAGE_RGBA_MODE);

    heart_live.transform.x =      HEART_BASE_X;
    heart_live.transform.y =      12.99;
    heart_live.transform.width =  23;
    heart_live.transform.height = 23;

    heart_died.transform.x =      HEART_BASE_X;
    heart_died.transform.y =      12.99;
    heart_died.transform.width =  23;
    heart_died.transform.height = 23;

    TEVES_Image_LoadImage(&bar_lives, "./media/bar-lives.png", TEVES_IMAGE_RGBA_MODE);

    bar_lives.transform.x = 0;
    bar_lives.transform.y = 0;
    bar_lives.transform.width = 200;
    bar_lives.transform.height = 50;

    TEVES_Anim_LoadAnimationImage(&idleAnim, "./media/Player_Idle.png", 10, 1, TEVES_IMAGE_RGBA_MODE | 
                                                                                TEVES_IMAGE_CENTER_ALIGN);
    TEVES_Anim_LinkWindow(&idleAnim, &window);
    TEVES_Anim_LoadAnimationImage(&runAnim, "./media/Player_Run.png", 10, 1, 0);
    TEVES_Anim_LinkWindow(&runAnim, &window);
    TEVES_Anim_LoadAnimationImage(&attackAnim, "./media/Player_Attack.png", 4, 1, TEVES_IMAGE_RGBA_MODE);
    TEVES_Anim_LinkWindow(&attackAnim, &window);
    TEVES_Anim_SetNoRepeteable(&attackAnim, &callback_punchAnimation);

    TEVES_Animator_SetAnim(&Player.animator, idleAnim, FPS_PLAYER_ANIM);

    Player.transform.x = 0;
    Player.transform.y = 342;
    Player.transform.width  = 100;
    Player.transform.height = 100;

    Player.physic.offset_x = 34.25;
    Player.physic.offset_y = 51.25;
    Player.physic.offset_w = -77.50;
    Player.physic.offset_h = -48.00;

    PlayerProperties.live = PLAYER_INITIAL_LIVES;

    TEVES_Anim_LoadAnimationImage(&idleAnimIA, "./media/Enemy_Idle.png", 4, 1, TEVES_IMAGE_RGBA_MODE | 
                                                                           TEVES_IMAGE_LEFT_ALIGN);
    TEVES_Anim_LinkWindow(&idleAnimIA, &window);
    TEVES_Anim_LoadAnimationImage(&runAnimIA, "./media/Enemy_Walk.png", 6, 1, TEVES_IMAGE_RGBA_MODE | 
                                                                           TEVES_IMAGE_LEFT_ALIGN);
    TEVES_Anim_LinkWindow(&runAnimIA, &window);
    TEVES_Anim_LoadAnimationImage(&attackAnimIA, "./media/Enemy_Attack.png", 6, 1, TEVES_IMAGE_RGBA_MODE | 
                                                                           TEVES_IMAGE_LEFT_ALIGN);
    TEVES_Anim_LinkWindow(&attackAnimIA, &window);
    TEVES_Anim_SetNoRepeteable(&attackAnimIA, &callback_punchAnimationIA);


    add_Enemy();
    add_Enemy();


    Enemies[1].transform.x = 200;
    Enemies[1].transform.flipped_x = TEVES_TRUE;

    TEVES_Loop(&window);
    TEVES_DeleteWindow(&window);
    TEVES_TERMINATE();
    return 0;
}