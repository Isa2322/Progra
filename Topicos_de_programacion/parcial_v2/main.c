#include "header.h"

int main()
{
    void **vec;
    FILE *pf1, *pf2;
    char op;
    int tipo, tam;

    vec=malloc(2*sizeof(void));

    pf1=fopen("arch1.txt","rt");
    pf2=fopen("arch2.txt","rt");

    if(pf1==NULL || pf2==NULL)
    {
        fclose(pf1);
        fclose(pf2);
        free(vec);
        return 1;
    }

    op=carga_vec(pf1, pf2, vec, &tipo, &tam);
    fclose(pf1);
    fclose(pf2);

    /*
        int=1
        float=2
        double=1
    */

    if(op=='0')
    {
        free(vec[0]);
        free(vec[1]);
        free(vec);
        return (1);
    }

    suma_y_resta(vec,tam,tipo,op);

    free(vec[0]);
    free(vec[1]);
    free(vec);

    return 0;
}
