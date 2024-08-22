#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    unsigned tam_info;
    void* info;
    struct sNodo* izq;
    struct sNodo* der;
} tNodo;

typedef tNodo* tArbol;

int insertarElementoArbol(tArbol* raiz, void* elemento, unsigned tam_info, int cmp(void*, void*));
int insertarElementoArbolIte(tArbol* raiz, void* elemento, unsigned tam_info, int cmp(void*, void*));


int main()
{
    return 0;
}

int insertarElementoArbol(tArbol* raiz, void* elemento, unsigned tam_info, int cmp(void*, void*))
{
    if(!*raiz)
    {
        tNodo* nue = malloc(sizeof(tNodo));
        if(!nue)
            return 0;
        nue->info = malloc(tam_info);
        if(!nue->info)
        {
            free(nue);
            return 0;
        }

        memcpy(nue->info, elemento, tam_info);
        nue->tam_info = tam_info;
        nue->izq = NULL;
        nue->der = NULL;
        *raiz = nue;
        return 1;
    }

    int rc = cmp(elemento, (*raiz)->info);

    if(rc > 0)
        insertarElementoArbol(&(*raiz)->der, elemento, tam_info, cmp);
    else if(rc < 0)
        insertarElementoArbol(&(*raiz)->izq, elemento, tam_info, cmp);
    else return 0;
}

int insertarElementoArbolIte(tArbol* raiz, void* elemento, unsigned tam_info, int cmp(void*, void*))
{
    int rc;

    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue) return 0;
    nue->info = malloc(tam_info);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    while(!(*raiz) && (rc = cmp(elemento, (*raiz)->info) != 0))
{
    if(rc > 0)
            raiz = &(*raiz)->der;
        else if(rc < 0)
            raiz = &(*raiz)->izq;
    }

    if(rc == 0)
    return 0;

           memcpy(nue->info, elemento, tam_info);
           nue->tam_info = tam_info;
           nue->izq = NULL;
           nue->der = NULL;
           *raiz = nue;
           return 1;

}

/*
tEmpleado vecEmpleados[]= {
        {1, "Alex", "Armstrong", {1000,1}},
        {2, "Bruce", "Banner", {2000,2}},
        {3, "Charles", "Chaplin", {3000,3}},
        {4, "Danny", "DeVito", {4000,4}},
        {5, "Edward", "Elric", {5000,5}},
        {7, "Giorno", "Giovanna", {7000,7}},
        {8, "Helga", "Hufflepuff", {8000,8}},
        {10, "Jonathan", "Joestar",{10000,10}},
        {11, "Keira", "Knightley", {11000,11}},
        {12, "Lex", "Luthor", {12000,12}},
        {10, "Marylin", "Monroe", {13000,13}},
        {15, "Ozzy", "Ozbourne", {15000,15}},
        {16, "Peter", "Parker", {16000,16}},
        {18, "Rita", "Repulsa", {18000,18}},
        {19, "Steven", "Spielberg", {19000,19}},
        {20, "Tina", "Turner", {20000,20}},
        {22, "Vincent", "Valentine", {22000,22}},
        {23, "Walter", "White", {23000,23}}
    };


int compararIDEmpleados(const void* estructura, const void* clave){
    return ((tEmpleado*)estructura)->id - *((int*)clave);
}


void mostrarEmpleado(const void* empleado){
    printf("%3d - %20s, %-20s - %7d.%02d\n", ((tEmpleado*)empleado)->id, ((tEmpleado*)empleado)->apellido, ((tEmpleado*)empleado)->nombre, ((tEmpleado*)empleado)->sueldo.entero, ((tEmpleado*)empleado)->sueldo.decimal);
}

*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo {
    unsigned tam_info;
    void* info;
    struct sNodo* izq;
    struct sNodo* der;
} tNodo;

typedef tNodo* tArbol;
typedef int(*Cmp)(void*, void*);

int main()
{
    return 0;
}

int insertarElementoArbol(tArbol* raiz, void* elemento, unsigned tam_info, Cmp cmp)
{
    if(!*raiz)
    {
        tNodo* nue = malloc(sizeof(tNodo));
        if(!nue) return 0;
        nue->info = malloc(tam_info);
        if(!nue->info) {free(nue); return 0;}

        memcpy(nue->info, elemento, tam_info);
        nue->tam_info = tam_info;
        nue->izq = NULL;
        nue->der = NULL;
        *raiz = nue;
        return 1;
    }

    int rc = cmp(elemento, (*raiz)->info);

    if(rc > 0)
        insertarElementoArbol(&(*raiz)->der, elemento, tam_info, cmp);
    else if(rc < 0)
        insertarElementoArbol(&(*raiz)->izq, elemento, tam_info, cmp);

    return 0;
}

int insertarElementoArbolIte(tArbol* raiz, void* elemento, unsigned tam_info, Cmp cmp)
{
    int rc = 0;

    tNodo* nue = malloc(sizeof(tNodo));
    if(!nue) return 0;
    nue->info = malloc(tam_info);
    if(!nue->info) {free(nue); return 0;}

    while((!*raiz) && (rc = cmp(elemento, (*raiz)->info) != 0))
    {
        if(rc > 0)
            raiz = &(*raiz)->der;
        else if(rc < 0)
            raiz = &(*raiz)->izq;
    }

    if(rc == 0)
        return 0;

    memcpy(nue->info, elemento, tam_info);
    nue->tam_info = tam_info;
    nue->izq = NULL;
    nue->der = NULL;
    *raiz = nue;
    return 1;
}
*/
