#include "header.h"

int comparar_enteros_menor_a_mayor(const void *elem1, const void *elem2)
{
    return *(int*)elem1-*(int*)elem2;
}
