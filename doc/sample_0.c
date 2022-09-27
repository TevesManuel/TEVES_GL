#include <TevesGL/Teves.h>

int main()
{
    TEVES_Init();//Init the library
    printf("The library work.\n");
    TEVES_TERMINATE();//Shutdown library
    return TEVES_OK;
}