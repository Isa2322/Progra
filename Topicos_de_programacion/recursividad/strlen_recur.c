#include "header.h"

int strlen_recur(char* cad)
{
    if(*cad=='\0')
        return 0;

    return 1+strlen_recur(cad+1);
}
