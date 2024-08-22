#include "header_indice.h"

void lote()
{
    t_productos productos[10];
    int  i;

    strcpy(productos[0].nombre, "Laptop");
    strcpy(productos[0].descripcion, "Laptop de 15 pulgadas");
    productos[0].n_serie = 1000;
    productos[0].precio = 750.0;

    strcpy(productos[1].nombre, "Smartphone");
    strcpy(productos[1].descripcion, "Smartphone con 128GB");
    productos[1].n_serie = 1001;
    productos[1].precio = 500.0;

    strcpy(productos[2].nombre, "Teclado");
    strcpy(productos[2].descripcion, "Teclado mecánico");
    productos[2].n_serie = 1002;
    productos[2].precio = 100.0;

    strcpy(productos[3].nombre, "Monitor");
    strcpy(productos[3].descripcion, "Monitor 24 pulgadas");
    productos[3].n_serie = 1003;
    productos[3].precio = 200.0;

    strcpy(productos[4].nombre, "Ratón");
    strcpy(productos[4].descripcion, "Ratón inalámbrico");
    productos[4].n_serie = 1004;
    productos[4].precio = 25.0;

    strcpy(productos[5].nombre, "Impresora");
    strcpy(productos[5].descripcion, "Impresora multifunción");
    productos[5].n_serie = 1005;
    productos[5].precio = 150.0;

    strcpy(productos[6].nombre, "Auriculares");
    strcpy(productos[6].descripcion, "Auriculares Bluetooth");
    productos[6].n_serie = 1006;
    productos[6].precio = 80.0;

    strcpy(productos[7].nombre, "Tablet");
    strcpy(productos[7].descripcion, "Tablet 10 pulgadas");
    productos[7].n_serie = 1007;
    productos[7].precio = 300.0;

    strcpy(productos[8].nombre, "Cámara");
    strcpy(productos[8].descripcion, "Cámara digital");
    productos[8].n_serie = 1008;
    productos[8].precio = 400.0;

    strcpy(productos[9].nombre, "Disco Duro");
    strcpy(productos[9].descripcion, "Disco duro externo 1TB");
    productos[9].n_serie = 1009;
    productos[9].precio = 120.0;



    FILE* pf;

    pf=fopen("productos.dat","wb");

    if(pf==NULL)
        return;

    for(i=0; i<10; i++)
    {
        fwrite(&productos[i],sizeof(t_productos), 1, pf);
    }

    fclose(pf);
}
