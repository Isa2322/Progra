#include "header.h"

int comparar_int(const void* elem1, const void* elem2)
{
    return *((int*)elem1)-*((int*)elem2);
}