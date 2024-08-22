#include "header.h"

void ingreso_de_datos(t_fecha * fechas)
{
        printf("\n ingrese dia: ");
        scanf("%d",&fechas->dia);
        printf("\n ingrese mes: ");
        scanf("%d",&fechas->mes);
        printf("\n ingrese anio: ");
        scanf("%d",&fechas->anio);
}
