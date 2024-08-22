#include "header_cola_dinamica.h"

void crear_cola(t_cola* cola)
{
    cola->pri=NULL;
    cola->ult=NULL;
}


//////////////////////////


int cola_vacia(const t_cola* cola)
{
    return cola->pri==NULL;
}


///////////////////////


int cola_llena(const t_cola* cola, unsigned tam)
{
    t_nodo* cola_aux;
    void* dato_aux;

    cola_aux= (t_nodo*)malloc((sizeof(t_nodo)));

    if(!cola_aux)
    {
        return SIN_MEM;
    }

    dato_aux= malloc(tam);

    if(!dato_aux)
    {
        free(cola_aux);
        return SIN_MEM;
    }

    free(cola_aux);
    free(dato_aux);
    return TODO_OK;
}

int poner_en_cola(t_cola* cola,const void* elemento, unsigned tam)
{
    t_nodo* nue;

    nue=malloc(sizeof(t_nodo)); //puedo castearlo a t_nodo*

    if(!nue)
        return SIN_MEM;

    nue->elem=malloc(tam);

    if(!nue->elem)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->elem, elemento, tam);
    nue->tam=tam;

    nue->sig=NULL;

    if(cola->pri==NULL)
    {
        cola->pri=nue;
    }
    else
    {
        cola->ult->sig=nue;
    }

    cola->ult=nue;

    return TODO_OK;
}
/*
poner en cola
1   reservo memoria para nodo y dato
2   si no hay memoria ->return
2.5 variable auxiliar nue
3   copio el dato, copio el tamanio
4   al siguiente de nue le pongo NULL
4.5 if(pri==NULL) pri<-nue, else, sig de ult<-nue
5   siguiente de ult->nue
6   ult->nue
*/

int mostrar_primero(t_cola* cola, void* elem, unsigned tam)
{
    if(!cola->pri)
        return COLA_VACIA;

     memcpy(elem, cola->pri->elem, MINIMO(tam, cola->pri->tam));

     return TODO_OK;
}

/*
    SACAR DE COLA

    1 Cola vacia?
    2 Si vacia -> salir
    3 elim <-nodo a eliminar ,primero de la cola
    4 pri <- siguiente elm
    5 copio la inof de elim en el dato parametro memcpy(dato param, elim info, MIN(tam_param, tam_elem))
    6 libero dato, libero nodo
*/

int sacar_de_cola(t_cola* cola, void* elemento, unsigned tam)
{
    t_nodo* elim;

    if(!cola->pri)
        return COLA_VACIA;

    elim = cola->pri;
    cola->pri=elim->sig;

    memcpy(elemento, elim->elem, MINIMO(tam, elim->tam));
    free(elim->elem);
    free(elim);

    return TODO_OK;
}


//////////////////////////


int vaciar_cola(t_cola* cola)
{
    t_nodo* aux;

    if(cola->pri)
        return COLA_VACIA;

    while(!cola->pri)
    {
        aux= cola->pri;
        cola->pri=aux->sig;
        free(aux->elem);
        free(aux);
    }

    return TODO_OK;
}
