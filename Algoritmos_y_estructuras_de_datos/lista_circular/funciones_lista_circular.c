#include "header_lista_circular.h"

void crear_lista(t_lista *lista)
{
    *lista=NULL;
}


///


int lista_vacia(const t_lista *lista)
{
    return *lista == NULL;
}


///


int insertar_pila(t_lista *lista, const void* info_nue, unsigned tam_info_nue)
{
    t_nodo *nue;

    nue=malloc(sizeof(t_nodo));

    if(nue==NULL)
    {
        return SIN_MEM;
    }

    nue->info=malloc(tam_info_nue);

    if(nue->info==NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info, info_nue, tam_info_nue);
    nue->tam_info=tam_info_nue;


    if(*lista==NULL)
    {
        nue->sig=nue;
    }
    else
    {
        nue->sig=(*lista)->sig;
    }

    (*lista)->sig=nue;

    return TODO_OK;
}


int insertar_cola(t_lista *lista, const void* info_nue, unsigned tam_info_nue)
{
    t_nodo *nue;

    nue=malloc(sizeof(t_nodo));

    if(nue==NULL)
    {
        return SIN_MEM;
    }

    nue->info=malloc(tam_info_nue);

    if(nue->info==NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info, info_nue, tam_info_nue);
    nue->tam_info=tam_info_nue;

    if(*lista==NULL)
    {
        nue->sig=nue;
    }
    else
    {
        nue->sig=(*lista)->sig;
        (*lista)->sig=nue;
    }

    (*lista)=nue;

    return TODO_OK;
}


///


int desapilar(t_lista *lista, void* info_nue, unsigned tam_info_nue)
{
    t_nodo *aux;

    aux=*lista;

    if(aux==NULL)
        return VACIA;

    aux=aux->sig;

    (*lista)->sig=aux;

    memcpy(info_nue, aux->info, MINIMO(tam_info_nue, aux->tam_info));
    aux->tam_info=tam_info_nue;

    free(aux->info);
    free(aux);

    return TODO_OK;
}


///


int desacolar(t_lista *lista, void* info_nue, unsigned tam_info_nue)
{
    t_nodo *aux;

    aux=*lista;

    if(aux==NULL)
        return VACIA;

    aux=(*lista)->sig;

    (*lista)->sig=aux->sig;

    memcpy(info_nue, aux->info, MINIMO(tam_info_nue, aux->tam_info));

    free(aux->info);
    free(aux);

    return TODO_OK;
}


///


void vaciar_cola(t_lista *lista)
{
    t_nodo *aux;

    aux=(*lista)->sig;
    (*lista)->sig=aux->sig;

    while(aux!=(*lista))
    {
        free(aux->info);
        free(aux);

        aux=(*lista)->sig;
        (*lista)->sig=aux->sig;
    }

    free(aux->info);
    free(aux);
}


///


void vaciar_pila(t_lista *lista)
{
    t_nodo *aux;

    aux=(*lista)->sig;
    (*lista)->sig=aux->sig;

    while(aux!=(*lista))
    {
        free(aux->info);
        free(aux);

        aux=(*lista)->sig;
        (*lista)->sig=aux->sig;
    }

    free(aux->info);
    free(aux);
}
