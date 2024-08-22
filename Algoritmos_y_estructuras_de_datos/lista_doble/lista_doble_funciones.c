#include "lista_doble_header.h"

void crear_lista(t_lista *lista)
{
    *lista=NULL;
}

int insertar_en_orden(t_lista *lista, const void* elem, unsigned tam_elem, int (*cmp(const void* elem_1, const void* elem_2)))
{
    t_nodo *aux_sig, *aux_ant, *nue, *act=*lista;

    if(act == NULL)
    {
        aux_ant=NULL;
        aux_sig=NULL;
    }
    else
    {
        while(cmp(elem, act->info)<0 && (act->ant)!=NULL)
            act=act->ant;

        while(cmp(elem, act->info)>0 && (act->sig)!=NULL)
            act=act->sig;

        if(cmp(elem, act->info) > 0)
        {
            aux_sig=act;
            aux_ant=act->ant;
        }
        else
        {
            aux_sig=act->sig;
            aux_ant=act;
        }
    }

    nue=malloc(sizeof(t_nodo));

    if(nue == NULL)
        return 1;

    nue->info=malloc(tam_elem);

    if(nue->info==NULL)
    {
        free(nue);
        return 1;
    }

    memcpy(nue->info, elem, tam_elem);
    nue->tam_info=tam_elem;

    nue->sig=aux_sig;
    nue->ant=aux_ant;

    if(aux_sig==NULL)
        aux_sig=nue;

    if(aux_ant==NULL)
        aux_ant=nue;

    *lista=nue;

    return 0;
}

int comparar_int(int* elem1, int* elem2)
{
    return(*elem1-*elem2);
}

int mostrar_izq_der(const t_lista *lista, void(*mostrar)(const void*))
{
    t_nodo *act=*lista;

    int cant=0;

    if(act!=NULL)
    {
        while(act->ant!=NULL)
            act=act->ant;

        do
        {
            mostrar(act->info);
            act=act->sig;
            cant++;
        } while(act->sig!=NULL);
    }
    return cant;
}


int mostrar_der_izq(const t_lista *lista, void(*mostrar)(const void*))
{
    t_nodo *act=*lista;
    int cant=0;

    if(act!=NULL)
    {
        while(act->sig!=NULL)
              act=act->sig;

        do
        {
            mostrar(act->info);
            act=act->ant;
            cant++;
        } while(act->ant!=NULL);
    }
    return cant;
}
