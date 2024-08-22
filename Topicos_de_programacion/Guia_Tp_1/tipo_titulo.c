#include <string.h>
#include <ctype.h>

char* tipo_titulo(char* str)
{
    char *inic;

    strlwr(str);

    inic=str;

    if(*str>=97 && *str<=122)
            *str-=32;


    while(*str!=0)
    {
        if((*str>=97 && *str<=122 && *(str-1)==' '))
            *str-=32;

        str++;
    }
    return inic;
}
