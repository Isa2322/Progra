#include "header.h"

void cesar(FILE *texto, FILE *alfabeto,
            void(*funcion)(FILE *, FILE*, int, int))
{
    int tam_text, tam_alfabeto;

    fseek(alfabeto,0L,SEEK_END);
    tam_alfabeto=ftell(alfabeto);
    fseek(alfabeto,0L,SEEK_SET);

    fseek(texto,0L,SEEK_END);
    tam_text=ftell(texto);
    fseek(texto,0L,SEEK_SET);

    funcion(texto, alfabeto, tam_text, tam_alfabeto);
}
