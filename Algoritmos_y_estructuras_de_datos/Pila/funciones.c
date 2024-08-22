#include "header.h"

void crear_tpila(tpila* pila)
{
    pila->tope=TAMANO;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int pila_vacia(const tpila* pila)
{
    return(pila->tope==TAMANO);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int pila_llena(const tpila* pila, unsigned tam_elem)
{
    return(pila->tope<(tam_elem+sizeof(unsigned)));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void vaciar_pila(tpila* pila)
{
    pila->tope=TAMANO;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int apilar_pila(tpila* pila, const void* elem, unsigned tam)
{
    // me fijo si hay espacio en el vector para el elemento + el separador
    if(pila->tope<(tam+sizeof(unsigned)))
    {
        return SIN_MEM;
    }

    pila->tope-=tam; //le resto al tope los bytes ocupados por el elemento
    memcpy(pila->pila + pila->tope, elem, tam);//copio los elementos al vector
    pila->tope-=sizeof(unsigned); //resto al tope el tamaño del separador
    memcpy(pila->pila + pila->tope, &tam ,sizeof(unsigned)); //copio el tamaño de los elementos al vector (separador)

    return TODO_OK;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int desapilar_pila(tpila* pila, void* elem, unsigned tam)
{
    unsigned aux;

    if((pila->tope==TAMANO))
    {
        return SIN_ELEM;
    }

    memcpy(&aux, pila->pila + pila->tope, sizeof(unsigned));

    pila->tope+=sizeof(unsigned);

    memcpy(elem, pila->pila+pila->tope, MINIMO(aux,tam));

    pila->tope+=tam;

    return TODO_OK;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ordenar_archivo(tpila* pila1, FILE* pf)
{
    tpila pila2;

   int num, aux, tope;

   crear_tpila(&pila2);

   fread(&num, sizeof(num), 1, pf);

   apilar_pila(pila1, &num, sizeof(int));
   tope=num;

   while(!feof(pf))
   {
       fread(&num, sizeof(int), 1, pf);

       if(num<=tope)
       {
           do
           {
               desapilar_pila(pila1, &aux, sizeof(int));

               if(aux>num)
               {
                    apilar_pila(&pila2, &aux, sizeof(int));
               }
               else
               {
                    apilar_pila(pila1, &aux, sizeof(int));
               }


           } while (num<aux && !pila_vacia(pila1));

           apilar_pila(pila1, &num, sizeof(int));

           while(!pila_vacia(&pila2))
           {
               desapilar_pila(&pila2, &aux, sizeof(int));
               apilar_pila(pila1, &aux, sizeof(int));
           }

           tope=aux;

       }
       else
       {
           apilar_pila(pila1, &num, sizeof(int));
           tope=num;
       }

   }

   fclose(pf);

   while(!pila_vacia(pila1))
   {
       desapilar_pila(pila1, &aux, sizeof(int));

       printf("%d \n",aux);
   }

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int ver_tope(const tpila *pila, void *elem, unsigned tam)
{
    unsigned tam_info;

    if(pila->tope == TAMANO)
    {
        return 1;
    }

    memcpy(&tam_info, pila->pila+ pila->tope, sizeof(unsigned));
    memcpy(elem, pila->pila + pila->tope + sizeof(unsigned), MINIMO(tam, tam_info));

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void sumar(tpila* pila1, tpila* pila2)
{
    tpila pila3;
    int aux1, aux2, res;

    while(pila_vacia(pila1))
    {
        desapilar_pila(pila1,&aux1, sizeof(int));
        apilar_pila(&pila3,&aux1, sizeof(int));
    }

    while(pila_vacia(pila2))
    {
        desapilar_pila(pila2,&aux1, sizeof(int));
        apilar_pila(pila1,&aux1, sizeof(int));
    }

    while(pila_vacia(pila1) && pila_vacia(&pila3))
    {
        desapilar_pila(pila1, &aux1, sizeof(int));
        desapilar_pila(&pila3, &aux2, sizeof(int));

        res=aux1+aux2;

        apilar_pila(pila2, &res, sizeof(int));
    }

    while(pila_vacia(pila1) && !pila_vacia(&pila3))
    {
        desapilar_pila(pila1, &aux1, sizeof(int));

        apilar_pila(pila2, &aux1, sizeof(int));
    }

    while(!pila_vacia(pila1) && pila_vacia(&pila3))
    {
        desapilar_pila(&pila3, &aux1, sizeof(int));

        apilar_pila(pila2, &aux1, sizeof(int));
    }


}
