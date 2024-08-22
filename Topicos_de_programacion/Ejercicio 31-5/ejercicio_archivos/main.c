#include "header.h"

int main()
{
    FILE *pf, *pf_txt;
    t_campeones registro;
    char linea[50];

//////////////CARGO EL PRIMER ARCHIVO .BIN////////////////////

    cargar_bin();

//////////////PASAR DE .BIN A .TXT DE LONGITUD FIJA////////////////////

    pf=fopen("campeones.dat","rb");

    if(pf==NULL)
        exit (1);

    pf_txt=fopen("campeones_lf.txt","wt");
    if(pf_txt==NULL)
    {
        fclose(pf);
        exit (1);
    }

    fread(&registro,sizeof(t_campeones),1,pf);

    while(!feof(pf))
    {
        fprintf(pf_txt,"%-20s %-20s %2d\n",registro.nombre, registro.apellido, registro.num);
        fread(&registro,sizeof(t_campeones),1,pf);
    }

    fclose(pf_txt);

//////////////PASAR DE .BIN A .TXT DE LONGITUD VARIABLE////////////////////

    pf_txt=fopen("campeones_lv.txt","wt");

    if(pf_txt==NULL)
    {
        fclose(pf);
        exit (1);
    }

    rewind(pf);

    fread(&registro,sizeof(t_campeones),1,pf);

    while(!feof(pf))
    {
        fprintf(pf_txt,"%s|%s|%d\n",registro.nombre, registro.apellido, registro.num);
        fread(&registro,sizeof(t_campeones),1,pf);
    }

    fclose(pf_txt);
    fclose(pf);


//////////////PASAR DE .TXT LONGITUD FIJA A .BIN////////////////////


    pf_txt=fopen("campeones_lf.txt","rt");
    if(pf_txt==NULL)
        exit (1);

    pf=fopen("campeones_lf.dat","wb");
    if(pf==NULL)
    {
        fclose(pf_txt);
        exit (1);
    }

    fgets(linea,50,pf_txt);

    while(!feof(pf_txt))
    {
        largo_fijo_a_bin(linea,&registro);
        fwrite(&registro,sizeof(t_campeones),1,pf);
        fgets(linea,50,pf_txt);
    }
    fclose(pf_txt);
    fclose(pf);


//////////////PASAR DE .TXT LONGITUD VARIABLE A .BIN////////////////////


    pf_txt=fopen("campeones_lv.txt","rt");
    if(pf_txt==NULL)
        exit (1);

    pf=fopen("campeones_lv.dat","wb");
    if(pf==NULL)
    {
        fclose(pf_txt);
        exit (1);
    }

    fgets(linea,50,pf_txt);

    while(!feof(pf_txt))
    {
        largo_variable_a_bin(linea,&registro);
        fwrite(&registro,sizeof(t_campeones),1,pf);
        fgets(linea,50,pf_txt);
    }
    fclose(pf_txt);
    fclose(pf);

    return 0;
}
