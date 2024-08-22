#include "header_cola.h"

int banco()
{
    tcola cola;
    FILE *pf, *pmen, *pmay;
    t_movimientos aux1, aux2;
    char nombre[20];
    int suma=0;

    pf=fopen("banco.dat","rb");
    pmen=fopen("banco_menores.dat","wb");
    pmay=fopen("banco_mayores.dat","wb");

    if(!pf || !pmen || !pmay)
    {
        fclose(pf);
        fclose(pmen);
        fclose(pmay);

        return ERROR;
    }

    crear_cola(&cola);

    fread(&aux1, sizeof(t_movimientos), 1, pf);

    while(!feof(pf) && cola_vacia(&cola))
    {
        strcpy(nombre, aux1.nombre_cliente);
        acolar(&cola, &aux1, sizeof(t_movimientos));

        suma+=aux1.importe;

        fread(&aux1, sizeof(t_movimientos), 1, pf);

        while(!feof(pf) && !strcmp(aux1.nombre_cliente,nombre))
        {
            acolar(&cola, &aux1, sizeof(t_movimientos));
            suma+=aux1.importe;
            fread(&aux1, sizeof(t_movimientos), 1, pf);
        }

        if(suma>=6000)
        {
            while(!cola_vacia(&cola))
            {
                desacolar(&cola, &aux2, sizeof(t_movimientos));
                fwrite(&aux2, sizeof(t_movimientos), 1, pmay);
            }
        }
        else
        {
             while(!cola_vacia(&cola))
            {
                desacolar(&cola, &aux2, sizeof(t_movimientos));
                fwrite(&aux2, sizeof(t_movimientos), 1, pmen);
            }
        }

        vaciar_cola(&cola);
        suma=0;
    }

    fclose(pf);
    fclose(pmen);
    fclose(pmay);


    return TODO_OK;
}
