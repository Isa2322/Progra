#include "header.h"

int main()
{
    tpila pila1, pila2, pila3;

    int result, carry=0, op1, op2;

    crear_tpila(&pila1);
    crear_tpila(&pila2);
    crear_tpila(&pila3);

    lote_de_pruebas(&pila3, &pila2);

    //////////////////////////////////////////////////

    while(!pila_vacia(&pila2))
    {
        desapilar_pila(&pila2, &result, sizeof(int));
        apilar_pila(&pila1, &result, sizeof(int));
    }

    while(!pila_vacia(&pila3))
    {
        desapilar_pila(&pila3, &result, sizeof(int));
        apilar_pila(&pila2, &result, sizeof(int));
    }

    //////////////////////////////////////////////////

    while(!pila_vacia(&pila1) && !pila_vacia(&pila2))
    {
        desapilar_pila(&pila1, &op1, sizeof(int));
        desapilar_pila(&pila2, &op2, sizeof(int));

        result= op1+op2;

        result+=carry;

        if(result>9)
        {
            carry=1;
            result-=10;
        }
        else
        {
            carry=0;
        }


        apilar_pila(&pila3, &result, sizeof(result));
    }

    if(!pila_vacia(&pila1))
    {
        desapilar_pila(&pila2, &op2, sizeof(int));
        op2+=carry;
        carry=0;

        while(!pila_vacia(&pila2))
        {
            desapilar_pila(&pila2, &op2, sizeof(int));
            apilar_pila(&pila3, &op2, sizeof(int));

        }
    }

    if(!pila_vacia(&pila2))
    {
        desapilar_pila(&pila1, &op1, sizeof(int));
        op1+=carry;
        carry=0;

        while(!pila_vacia(&pila1))
        {
            desapilar_pila(&pila1, &op1, sizeof(int));
            apilar_pila(&pila3, &op1, sizeof(int));

        }
    }

    if(carry!=0)
    {
        apilar_pila(&pila3, &carry, sizeof(int));
    }


    while(!pila_vacia(&pila3))
    {
        desapilar_pila(&pila3, &result, sizeof(result));
        printf("%d \n",result);
    }

    return (0);

}
