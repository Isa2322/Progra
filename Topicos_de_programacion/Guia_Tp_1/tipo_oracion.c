#include <string.h>
#include <ctype.h>

char* tipo_oracion(char* str)
{
    char *inic;

    strlwr(str);

    inic=str;

    if(*str>=97 && *str<=122)
            *str-=32;


    while(*str!=0)
    {
        if(*str>=97 && *str<=122 && *(str-1)==' ' && *(str-2)==46)
            *str-=32;

        str++;
    }
    return inic;
}
