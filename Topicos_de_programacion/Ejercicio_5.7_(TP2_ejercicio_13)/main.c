#include "header.h"

int main()
{
    FILE *pf_empleados, *pf_alumnos;

    pf_alumnos=fopen("alumnos.dat","rb");
    pf_empleados=fopen("empleados.dat","r+b");

    if(pf_empleados==NULL || pf_alumnos==NULL)
    {
        fclose(pf_alumnos);
        fclose(pf_empleados);
        return (1);
    }

    fclose(pf_alumnos);
    fclose(pf_empleados);

    return (0);
}
