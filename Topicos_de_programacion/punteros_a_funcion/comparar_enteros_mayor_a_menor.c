#include "header.h"

int comparar_enteros_mayor_a_menor(const void *elem1, const void *elem2)
{
    return *(int*)elem2-*(int*)elem1;
}
