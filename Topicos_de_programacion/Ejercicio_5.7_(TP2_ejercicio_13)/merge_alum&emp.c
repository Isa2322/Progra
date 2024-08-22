#include "header.h"

void actualizar_sueldos(FILE*alumno, FILE*empleado, int tam_tipo,
                        int comparar(void*,void*),
                        void actualizar(void*,void*,float,float))
{
    void *alu, *emp;
    int cmp;

    alu=malloc(tam_tipo);
    emp=malloc(tam_tipo);

    if(alu==NULL || emp==NULL)
    return;

    fread(alu,tam_tipo,1,alumno);
    fread(emp,tam_tipo,1,empleado);

    while(!feof(alumno) && !feof(empleado))
    {
        cmp=comparar(alu,emp);

        if(!cmp)
        {
            actualizar(alu,emp,7,0.0728);
            fseek(empleado,-tam_tipo,SEEK_CUR);
            fwrite(emp,tam_tipo,1,empleado);
            fseek(empleado,0L,SEEK_CUR);
            fread(emp,tam_tipo,1,empleado);
            fread(alu,tam_tipo,1,alumno);
        }

        if(cmp<0)
            fread(alu,tam_tipo,1,alumno);
        else
            fread(emp,tam_tipo,1,empleado);
    }

    fseek(alumno,0L,SEEK_END);
    fseek(empleado,0L,SEEK_END);
}
