#include "header_arbol.h"


void crear_arbol(t_arbol *raiz)
{
    *raiz=NULL;
}

int contar_hojas(t_arbol* raiz)
{
    if(*raiz==NULL)
    {
        return 0;
    }

    if((*raiz)->izq == NULL && (*raiz)->der == NULL)
    {
        return 1;
    }

    return contar_hojas(&(*raiz)->izq) + contar_hojas((&(*raiz)->der));
}

int contar_hijos_solo_x_izq(t_arbol* raiz)
{
    if(*raiz==NULL)
        return 0;

    if((*raiz)->izq!=NULL && (*raiz)->der==NULL)
    {
        return ((contar_hijos_solo_x_izq(&(*raiz)->izq))+1);
    }

    return ((contar_hijos_solo_x_izq(&(*raiz)->izq)) + (contar_hijos_solo_x_izq(&(*raiz)->der)));
}


int contar_hijos_solo_x_der(t_arbol* raiz)
{
    if(*raiz==NULL)
        return 0;

    if((*raiz)->izq==NULL && (*raiz)->der!=NULL)
    {
        return ((contar_hijos_solo_x_der(&(*raiz)->der))+1);
    }

    return ((contar_hijos_solo_x_der(&(*raiz)->izq)) + (contar_hijos_solo_x_der(&(*raiz)->der)));
}


int contar_NO_hojas(t_arbol* raiz)
{
    if(*raiz==NULL)
        return 0;

    if((*raiz)->izq != NULL || (*raiz)->der != NULL)
        return (1 + ((contar_NO_hojas(&(*raiz)->izq)) + (contar_NO_hojas(&(*raiz)->der))));

    return 0;
}


void* mayor_clave(t_arbol* raiz)
{
    if(*raiz==NULL)
        return NULL;

    if((*raiz)->der == NULL)
    {
        return (*raiz)->info;
    }


    return mayor_clave(&(*raiz)->der);
}
/*
void* buscar_no_clave(Arbol* raiz, void*(*cmp)(void* info, void* nue))
{
    if(*raiz==NULL)
    return NULL;

    return _buscar_no_clave(raiz, (*raiz)->info, cmp);
}

void* _buscar_no_clave(Arbol* raiz, void* info, void*(*cmp)(void* info, void* nue))
{
    if((*raiz)->izq == NULL && (*raiz)->der == NULL)
        return info;

    info = cmp(info, (*raiz)->info);
    info = _buscar_no_clave((*raiz)->izq, info, cmp(info, (*raiz)->info)); **
    info = _buscar_no_clave((*raiz)->der, info, cmp(info, (*raiz)->info)); **

    return info;
}
*/
///////PENDIENTE buscar mayor NO clave///////

/*
int altura_arbol(arbol* raiz)
{
    int hi, hd;

    if(*raiz==NULL)
    return 0;

    hi=_altura(raiz);
    hd=_altura(raiz);

    if(hi>=hd)
    {
        return(hi+1);
    }

    return(hd+1);
}

int _altura(arbol* raiz, int h)
{

}
*/

int altura_arbol(const t_arbol* raiz)
{
    int hi, hd;

    if(*raiz==NULL)
        return 0;

    hi=altura_arbol(&(*raiz)->izq);
    hd=altura_arbol(&(*raiz)->der);

    return((hd>hi?hd:hi) + 1);
}


int insertar_arbol(t_arbol *arbol, const void* dato, unsigned tam_dato,
                   int (*cmp)(const void*, const void*))
{
    t_nodo_arbol *nue;
    int ref;

    if(*arbol)
    {
        ref=cmp(dato, (*arbol)->info);

        if(ref<0)
            insertar_arbol(&(*arbol)->izq, dato, tam_dato, cmp);

        if(ref>0)
            insertar_arbol(&(*arbol)->der, dato, tam_dato, cmp);
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


int insertar_arbol_iter(t_arbol *arbol, const void* dato, unsigned tam_dato,
                        int (*cmp)(const void*, const void*))
{
    t_nodo_arbol *nue;
    int ref;

    while(*arbol != NULL)
    {
        ref=cmp(dato, (*arbol)->info);

        if(ref<0)
            arbol=&(*arbol)->izq;

        if(ref>0)
            arbol=&(*arbol)->der;
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

///

void recorrer_en_orden(t_arbol *arbol, void(*accion)(t_arbol*))
{
    if((*arbol)==NULL)
        return;

    recorrer_en_orden(&(*arbol)->izq, accion);
    accion(arbol);
    recorrer_en_orden(&(*arbol)->der, accion);
}

void _mostrar_raiz_int(t_arbol *raiz)
{
    t_nodo_arbol *aux=*raiz;

    printf("%d\n",*(int*)(aux)->info);
}


int cargar_arbol_desde_orden(t_arbol *arbol, void* datos, int cant_elem,
                             int(*carga_tipo_dato)(t_arbol*,void*, int, int))
{
    carga_tipo_dato(arbol, datos, 0, cant_elem);

    return TODO_OK;
}


int _carga_enteros(t_arbol* raiz, void* datos, int ini, int fin)
{
    int* vec=(int*)datos;
    int mid=(fin+ini)/2;

    t_nodo_arbol *nue;

    if(fin<ini)
        return 5;

    nue=malloc(sizeof(t_nodo_arbol));
    if(!nue)
        return 0;

    nue->info=malloc(sizeof(int));
    if(nue->info==NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, &vec[mid], sizeof(int));
    nue->tam=sizeof(int);
    nue->der=NULL;
    nue->izq=NULL;
    *raiz=nue;

    _carga_enteros(&(*raiz)->izq, datos, ini, mid-1);
    _carga_enteros(&(*raiz)->der, datos, mid+1, fin);

    return 1;
}

///

void* busqueda_binaria(t_arbol *raiz, void* dato, int (*cmp)(void* d1, void* d2))
{
    if(*raiz == NULL)
        return NULL;

    if(cmp((*raiz)->info, dato) == 0)
    {
        return (*raiz)->info;
    }

    if(cmp((*raiz)->info, dato) > 0)
    {
        return busqueda_binaria(&(*raiz)->izq, dato, cmp);
    }
    else
    {
        return busqueda_binaria(&(*raiz)->der, dato, cmp);
    }
}

///

int cmp_entero(void* d1, void* d2)
{
    int dato1=*(int*)d1, dato2=*(int*)d2;

    return dato1-dato2;
}

///

void* busqueda_binaria_no_clave(t_arbol *raiz, void* dato, int (*cmp)(void* d1, void* d2))
{
    void *hit=NULL;

    if((*raiz)==NULL)
        return hit;


    if(cmp((*raiz)->info,dato)==0)
        return raiz;

    hit=busqueda_binaria(raiz, dato, cmp);

    if(hit != NULL)
        return hit;

    return busqueda_binaria(raiz, dato, cmp);
}

///


int mayor_elem_no_clave(t_arbol *raiz, void *dato, unsigned tam,
                        int(*cmp)(void*, void*))
{
    t_arbol *mayor=raiz;

    if((*raiz)==NULL)
        return 0;

    mayor=mayor_nodo_no_clave(&(*raiz)->izq, mayor, cmp);
    mayor=mayor_nodo_no_clave(&(*raiz)->der, mayor, cmp);

    memcpy(dato, mayor, tam);

    return 1;
}


t_arbol* mayor_nodo_no_clave(t_arbol *raiz, t_arbol *mayor,
                             int(*cmp)(void*, void*))
{
    if(!(*raiz))
        return mayor;

    if(cmp((*raiz)->info, (*mayor)->info) > 0)
        mayor=raiz;

    mayor=mayor_nodo_no_clave(&(*raiz)->izq, mayor, cmp);
    mayor=mayor_nodo_no_clave(&(*raiz)->der, mayor, cmp);

    return mayor;
}


int menor_elem_no_clave(t_arbol *raiz, void *dato, unsigned tam,
                        int(*cmp)(void*, void*))
{
    t_arbol *menor=raiz;

    if((*raiz)==NULL)
        return 0;

    menor=menor_nodo_no_clave(&(*raiz)->izq, menor, cmp);
    menor=menor_nodo_no_clave(&(*raiz)->der, menor, cmp);

    memcpy(dato, menor, tam);

    return 1;
}

t_arbol* menor_nodo_no_clave(t_arbol *raiz, t_arbol *menor,
                             int(*cmp)(void*, void*))
{
    if(!(*raiz))
        return menor;

    if(cmp((*raiz)->info, (*menor)->info) < 0)
        menor=raiz;

    menor=menor_nodo_no_clave(&(*raiz)->izq, menor, cmp);
    menor=menor_nodo_no_clave(&(*raiz)->der, menor, cmp);

    return menor;
}


int buscar_elem_no_clave(t_arbol *raiz, void *dato, unsigned tam,
                         int(*cmp)(void*, void*))
{
    t_arbol *hit=NULL;

    if(!raiz)
        return 0;

    if(cmp((*raiz)->info, dato) == 0)
        hit=raiz;
    else
    {
        hit=buscar_nodo_no_clave(&(*raiz)->izq, dato, cmp);

        if(hit==NULL)
            hit=buscar_nodo_no_clave(&(*raiz)->der, dato, cmp);
    }

    if(hit==NULL)
        return 0;

    memcpy(dato, (*hit)->info, tam);

    return 1;
}


t_arbol* buscar_nodo_no_clave(t_arbol *raiz, void *dato,
                              int(*cmp)(void*, void*))
{
    t_arbol *hit=NULL;

    if((*raiz)==NULL)
        return NULL;

    if(cmp((*raiz)->info, dato))
        return raiz;

    hit=buscar_nodo_no_clave(&(*raiz)->der, hit, cmp);

    if(hit)
        return hit;

    return buscar_nodo_no_clave(&(*raiz)->izq, hit, cmp);
}




unsigned altura_arbol_2(t_arbol *raiz)
{
    int hi, hd;

    if((*raiz)==NULL)
        return 0;

    hi=altura_arbol_2(&(*raiz)->izq);
    hd=altura_arbol_2(&(*raiz)->der);

    return (hd>hi ? hi : hd)+1;
}



unsigned cant_nodos_arbol(t_arbol *raiz)
{
    if((*raiz)==NULL)
        return 0;

    return (cant_nodos_arbol(&(*raiz)->izq)+
            cant_nodos_arbol(&(*raiz)->izq)
            +1);
}

///nivel
unsigned cant_nodos_hasta_nivel(t_arbol *raiz, int n)
{
    if((*raiz)==NULL)
        return 0;

    if(n==0)
        return 1;

    return (cant_nodos_hasta_nivel(&(*raiz)->izq, n-1)
            +cant_nodos_hasta_nivel(&(*raiz)->der, n-1)
            +1);
}

///nivel
int es_completo_hasta(t_arbol *raiz, int n)
{
    if((*raiz)==NULL)
        return (n<0);

    if(n==0)
        return 1;

    return (es_completo_hasta(&(*raiz)->izq, n-1) &&
            es_completo_hasta(&(*raiz)->der, n-1));
}


int es_completo(t_arbol *raiz)
{
    return es_completo_hasta(raiz, altura_arbol_2(raiz)-1);
}


int es_balanceado(t_arbol *raiz)
{
    return es_completo_hasta(raiz, altura_arbol_2(raiz)-2);
}


int es_avl(t_arbol *raiz)
{
    int hi, hd;

    if((*raiz)==NULL)
        return 1;

    hi=altura_arbol_2(&(*raiz)->izq);
    hd=altura_arbol_2(&(*raiz)->der);

    if(abs(hi-hd)>1)
        return 0;

    return (es_avl(&(*raiz)->izq) && es_avl(&(*raiz)->der));
}


int es_completo_2(t_arbol *raiz)
{
    int h=altura_arbol_2(raiz);
    return cant_nodos_arbol(raiz) == pow(2,h)-1;
}


int es_balanceado_2(t_arbol *raiz)
{
    int h= altura_arbol(raiz);
    return cant_nodos_hasta_nivel(raiz, h-2) == pow(2,h-1)-1;
}

int es_avl_2_calc(t_arbol *raiz)
{
    int hi, hd;

    if((*raiz)==NULL)
        return 0;

    hi=es_avl_2_calc(&(*raiz)->izq);
    hd=es_avl_2_calc(&(*raiz)->der);

    if(hi<0 || hd<0 || abs(hi-hd)>1)
        return -1;

    return(hi>hd ? hi : hd) +1;
}


int es_avl_2(t_arbol *raiz)
{
    return es_avl_2_calc(raiz)>=0;
}







