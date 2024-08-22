#include "header.h"

void unir_archivos(FILE *arch1, FILE *arch2, int tam, char *nombre,
            int (*comparar)(void*, void*),
            void actualizar(void*, void*))
{
    void *reg1, *reg2;
    FILE *pf;

    reg1=malloc(tam);
    reg2=malloc(tam);

    pf=fopen("aux.dat","wb");

    if(reg1==NULL || reg2==NULL || pf==NULL)
        return;

    while(!feof(arch1) || !feof(arch2))
    {
        fread(reg1,tam,1,arch1);
        fread(reg2,tam,1,arch2);

        if(!comparar(reg1,reg2))
            actualizar(reg1,reg2);
        else
        {
            if(comparar(reg1,reg2)<0)
            {
                fwrite(reg1,tam,1,pf);
                fread(reg1,tam,1,arch1);
            }
            else
            {
                fwrite(reg2,tam,1,pf);
                fread(reg2,tam,1,arch2);
            }
        }
    }

    if(!feof(arch1))
    {
        if(comparar(reg1,reg2))
            fwrite(reg2,tam,1,arch2);
        else
            fread(reg2,tam,1,arch2);

        while(!feof(arch2))
        {
            fwrite(reg2,tam,1,arch2);
            fread(reg2,tam,1,arch2);
        }
    }
    else
    {
        if(comparar(reg1,reg2))
            fwrite(reg1,tam,1,arch1);
        else
            fread(reg1,tam,1,arch1);

        while(!feof(arch1))
        {
            fwrite(reg1,tam,1,arch1);
            fread(reg1,tam,1,arch1);
        }
    }

    fclose(pf);
    fclose(arch1);
    fclose(arch2);

    remove(nombre);
    rename("aux.dat",nombre);
}
