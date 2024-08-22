#include "header_cola.h"

int main()
{
    FILE *pmen, *pmay;
    tcola cola1, cola2;
    t_movimientos mov;


    crear_cola(&cola1);
    crear_cola(&cola2);

    banco();

    pmen=fopen("banco_menores.dat","rb");
    pmay=fopen("banco_mayores.dat","rb");

    if(!pmen || !pmay)
    {
        fclose(pmen);
        fclose(pmay);

        return ERROR;
    }

    fread(&mov, sizeof(t_movimientos), 1, pmen);

    while(!feof(pmen))
    {
        acolar(&cola1, &mov, sizeof(t_movimientos));
        fread(&mov, sizeof(t_movimientos), 1, pmen);
    }



    fread(&mov, sizeof(t_movimientos), 1, pmay);

    while(!feof(pmay))
    {
        acolar(&cola2, &mov, sizeof(t_movimientos));
        fread(&mov, sizeof(t_movimientos), 1, pmay);
    }


    printf("MAYORES: \n");
    while(!cola_vacia(&cola1))
    {
        desacolar(&cola1, &mov, sizeof(t_movimientos));
        printf("Cliente: %s, Tipo: %c, Importe: %d\n",mov.nombre_cliente, mov.tipo_mov, mov.importe);
    }

    system("pause");
    system("cls");

    printf("MENORES                                                                                                                                                                                                                                                                                            : \n");
    while(!cola_vacia(&cola2))
    {
        desacolar(&cola2, &mov, sizeof(t_movimientos));
        printf("Cliente: %s, Tipo: %c, Importe: %d\n",mov.nombre_cliente, mov.tipo_mov, mov.importe);
    }

    return (0);
}
