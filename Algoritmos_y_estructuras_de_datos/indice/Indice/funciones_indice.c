#include "header_indice.h"

void crear_arbol(t_arbol *raiz)
{
    *raiz=NULL;
}

int insertar_arbol(t_arbol *arbol, void* dato, unsigned tam_dato,
                   int (*cmp)(void*, void*))
{
    t_nodo_arbol *nue;
    int ref;

    if(*arbol)
    {
        ref=cmp(dato, (*arbol)->info);

        if(ref<0)
        {
            insertar_arbol(&(*arbol)->izq, dato, tam_dato, cmp);
            return TODO_OK;
        }

        if(ref>0)
        {
            insertar_arbol(&(*arbol)->der, dato, tam_dato, cmp);
            return TODO_OK;
        }
        else
            return DUPLICADO;
    }

    nue=malloc(sizeof(t_nodo_arbol));
    if(!nue)
        return ERROR_MEMORIA;

    nue->info=malloc(tam_dato);

    if(nue->info == NULL)
    {
        free(nue);
        return ERROR_MEMORIA;
    }

    memcpy(nue->info, dato, tam_dato);
    nue->tam=tam_dato;
    nue->der=NULL;
    nue->izq=NULL;

    *arbol=nue;

    return TODO_OK;
}


void crear_indice(t_arbol *raiz)
{
    FILE *pf;

    pf=fopen("productos.idx","wb");

    if(!pf)
    {
        return;
    }
    fclose(pf);

    recorrer_en_orden_mod(raiz,escribir_indice);
    /// Para hacerlo generico, deberia pasar el nombre del archivo como string
    /// y el tamaño como parametro, o pasar el puntero FILE a la funcion accion
}

void recorrer_en_orden_mod(t_arbol *raiz, void(*accion)(t_arbol*))
{
    if((*raiz)==NULL)
        return;

    recorrer_en_orden_mod(&(*raiz)->izq, accion);
    accion(raiz);
    recorrer_en_orden_mod(&(*raiz)->der, accion);
}

void escribir_indice(t_arbol *raiz)
{
    void *aux;
    FILE *apf;

    apf=fopen("productos.idx","ab");
    if(!apf)
    {
        return;
    }
    aux=(*raiz)->info;

    fwrite(aux, sizeof(t_productos), 1, apf);

    fclose(apf);
}

int comparar_nombre_productos( void *dato1,  void *dato2)
{
    t_productos *p1;

    p1=dato2;

    return(strcmp(dato1, p1->nombre));

}

void mostrar_arbol(t_arbol *raiz)
{
    t_productos *aux;

    aux=(*raiz)->info;

    printf("%s\n%s\n%d\n%.2fn\n\n\n",aux->nombre, aux->descripcion, aux->n_serie, aux->precio);
}
