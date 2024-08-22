#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int dni;
    char nom[20];
    char apell[20];
} t_alum;

int main()
{
    int i;

    t_alum vec[5]= {{12345678,"juan","perez"},{1237895,"lionel","messi"},{4657892,"federico","ayala"},{1321254,"alberto","fernandez"},{7965634,"mario","santacruz"}};
    t_alum alumno;
    FILE *pf, *pftf, *pftv;
//    pf=fopen("alumno.dat","wb");
//    fwrite(vec,sizeof(vec),1,pf);
//    fclose(pf);
//
//    pf=fopen("alumno.dat","rb");
//    pftv=fopen("alumno_tv.txt","wt");
//
//    fread(&alumno,sizeof(t_alum),1,pf);
//
//    while(feof(pf)==0)
//    {
//        fprintf(pftv,"%d - %s - %s\n",alumno.dni, alumno.nom, alumno.apell);
//        fprintf(stdout,"%d - %s - %s\n",alumno.dni, alumno.nom, alumno.apell);
//        fread(&alumno,sizeof(t_alum),1,pf);
//    }
//    fclose(pftv);
//    rewind(pf);
//
//    pftf=fopen("alumno_tf.txt","wt");
//
//    fread(&alumno,sizeof(t_alum),1,pf);
//
//    while(feof(pf)==0)
//    {
//        fprintf(pftf,"%8d - %10s - %10s\n",alumno.dni, alumno.nom, alumno.apell);
//        fread(&alumno,sizeof(t_alum),1,pf);
//    }
//
//    fclose(pftf);
//    fclose(pf);


    return 0;
}
