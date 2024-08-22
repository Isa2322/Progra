#include "header_lista.h"


void crear_lista(t_lista *lista)
{
    *lista=NULL;
}


////////////////////////////////////////////////////


int lista_vacia(const t_lista *lista)
{
    return *lista == NULL;
}


////////////////////////////////////////////////////


int lista_llena(const t_lista *lista, unsigned tam_elem)
{
    t_nodo *aux;
    void *info;

    aux=malloc(sizeof(t_nodo));

    if(aux==NULL)
    {
        return SIN_MEM;
    }

    info=malloc(tam_elem);

    if(info == NULL)
    {
        free(aux);
        return SIN_MEM;
    }

    free(aux);
    free(info);

    return TODO_OK;
}


////////////////////////////////////////////////////


void vaciar_lista(t_lista *lista)
{
    t_nodo *aux;

    while(*lista!=NULL)
    {
        aux=*lista;
        *lista=aux->sig;
        free(aux->info);
        free(aux);
    }
}


////////////////////////////////////////////////////


int poner_al_inicio(t_lista *lista, void* info_nue, unsigned tam_info_nue)
{
    t_nodo *nue=*lista;

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
        nue->sig=NULL;
    }
    else
    {
        nue->sig=*lista;
    }
    *lista=nue;

    return TODO_OK;
}


////////////////////////////////////////////////////


int poner_al_final(t_lista *lista, void* info_nue, unsigned tam_info_nue)
{
    t_nodo *nue;

    while(*lista!=NULL)
    {
        lista=&(*lista)->sig; //PREGUNTAR!!!!!
    }

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
    nue->sig=NULL;
    *lista=nue;


    return TODO_OK;
}


////////////////////////////////////////////////////


int sacar_primero(t_lista *lista, void *elem, unsigned tam_elem)
{
    t_nodo *aux;

    aux=*lista;

    if(aux==NULL)
        return VACIA;

    *lista=aux->sig;

    memcpy(elem, aux->info, MINIMO(tam_elem, aux->tam_info));
    free(aux->info);
    free(aux);

    return TODO_OK;
}


////////////////////////////////////////////////////


int sacar_ultimo(t_lista *lista, void *elem, unsigned tam_elem)
{
    if(*lista==NULL)
        return VACIA;

    while((*lista)->sig!=NULL)
    {
        lista=&(*lista)->sig;
    }

    memcpy(elem, (*lista)->info, MINIMO(tam_elem, (*lista)->tam_info));

    free((*lista)->info);
    free(*lista);
    *lista=NULL;

    return TODO_OK;
}


////////////////////////////////////////////////////


int ver_primero(t_lista *lista, void *elem, unsigned tam_elem)
{
    if(*lista==NULL)
        return VACIA;

    memcpy(elem, (*lista)->info, MINIMO(tam_elem, (*lista)->tam_info));

    return TODO_OK;

}


////////////////////////////////////////////////////


int poner_luego_de_n(t_lista *lista, void* info_nue, unsigned tam_info_nue, int parametro)
{
    t_nodo *nue;

    while(*lista!=NULL && parametro>0)
    {
        lista=&(*lista)->sig;
        parametro--;
    }

    if(parametro>0)
        return INSUFICIENTES_ELEMENTOS;

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
    nue->sig=(*lista)->sig;
    (*lista)->sig=nue;

    return TODO_OK;
}


////////////////////////////////////////////////////


int sacar_siguiente_a_n(t_lista *lista, void *elem, unsigned tam_elem, int parametro)
{
    t_lista *aux=lista;

    if(*lista==NULL)
        return VACIA;

    while((*lista)->sig!=NULL && parametro>0)
    {
        lista=&(*lista)->sig;
        parametro--;
    }

    if(parametro>0)
        return INSUFICIENTES_ELEMENTOS;

    memcpy(elem, (*lista)->info, MINIMO(tam_elem, (*lista)->tam_info));

    *aux=(*lista)->sig;

    (*lista)->sig=(*aux)->sig;



    free((*lista)->info);
    free(*lista);
    *lista=NULL;

    return TODO_OK;
}


////////////////////////////////////////////////////


void my_map(t_lista* lista, void accion(void*))
{
    t_nodo *ini=*lista;

    while((*lista)!=NULL)
    {
        accion(lista);
        (*lista)=(*lista)->sig;
    }

    *lista=ini;
}


////////////////////////////////////////////////////


void mostrar_jugadores(t_lista *lista)
{
    t_jugadores *aux=(*lista)->info;
    t_jugadores xd=*aux;
    printf("Nombre: %s %s\n", aux->nombre, aux->apellido);
    printf("Posicion: %s\n", aux->posicion);
    printf("Equipo: %s\n", aux->equipo);
    printf("Numero: %u\n", aux->numero);
    printf("\n");
}


////////////////////////////////////////////////////


void cambiar_numeros(void *lista)
{
    t_jugadores *aux;
    t_lista *l_aux;

    l_aux=lista;

    aux=(*l_aux)->info;

    aux->numero=99;
}


////////////////////////////////////////////////////


void eliminar_sig(t_lista *lista)
{
    t_nodo *aux=(*lista)->sig;

    (*lista)->sig=aux->sig;

    free(aux->info);
    free(aux);
}

////////////////////////////////////////////////////


void my_filter(t_lista *lista, int filtro(void*))
{
    t_nodo *ini=*lista, *aux;
    int ref=1;

    while(*lista != NULL && ref == 1)
    {
        if(filtro((*lista)->info))
        {
            (*lista)=ini->sig;
            free(ini->info);
            free(ini);
            ini=*lista;
        }
        else
        {
            ref=0;
            ini=*lista;
        }
    }

    ///(*lista)=(*lista)->sig;


    while((*lista)->sig != NULL)
    {
        if(filtro(((*lista)->sig)->info))
        {
            aux=(*lista)->sig;

            (*lista)->sig=aux->sig;

            free(aux->info);
            free(aux);
        }
        else
        {
            (*lista)=(*lista)->sig;
        }

    }

    (*lista)->sig=NULL;
    *lista=ini;
}


int filtro_solo_arqueros(void *nodo)
{
    t_jugadores *aux;
    aux=nodo;

    if(strcmp(aux->posicion,"Portero")==0)
        return 0;///si es

    return 1;///no es
}

int filtro_solo_defensores(void *nodo)
{
    t_jugadores *aux;
    aux=nodo;

    if(strcmp(aux->posicion,"Defensa")==0)
        return 0;///si es

    return 1;///no es
}

int filtro_solo_volantes(void *nodo)
{
    t_jugadores *aux;
    aux=nodo;

    if(strcmp(aux->posicion,"Mediocampista")==0)
        return 0;///si es

    return 1;///no es
}

int filtro_solo_delanteros(void *nodo)
{
    t_jugadores *aux;
    aux=nodo;

    if(strcmp(aux->posicion,"Delantero")==0)
        return 0;///si es

    return 1;///no es
}

void mostrar(t_lista *lista)
{
    t_nodo *ini=*lista;

    while((*lista)!=NULL)
    {
        mostrar_jugadores(lista);
        printf("\n\n\n");
        *lista=(*lista)->sig;
    }

    *lista=ini;
}


////////////////////////////////

void* buscar_menor(t_lista *lista, int (*cmp)(void*, void*))
{
    t_nodo *ini=*lista;
    void *min=(*lista)->info;
    t_jugadores mesi1, mesi2;

    (*lista)=(*lista)->sig;

    while((*lista) != NULL)
    {
        mesi1=*(t_jugadores*)min;
        mesi2=*(t_jugadores*)(*lista)->info;

        if(cmp(min, (*lista)->info) > 0)
        {
            min=(*lista)->info;
        }

        (*lista)=(*lista)->sig;
    }

    *lista=ini;
    return min;
}


////////////////////////////////


void ordenar_lista_asc(t_lista *lista, int (*cmp)(void*, void*))
{
    t_nodo *ini=*lista, *aux, *inicio=*lista;

        aux=buscar_menor(lista, cmp);
        aux->sig=(*lista);
        inicio=aux;
        (*lista)=(*lista)->sig;
        ini=inicio->sig;

    while(*lista != NULL)
    {
        aux=buscar_menor(lista, cmp);
        aux->sig=ini;
        (*lista)=(*lista)->sig;
    }

    *lista=inicio;
}


////////////////////////////////


int cmp_dorsal(void* nodo_1, void* nodo_2)
{
    t_jugadores *jug1=nodo_1, *jug2=nodo_2;

    return (jug1->numero - jug2->numero);
}
