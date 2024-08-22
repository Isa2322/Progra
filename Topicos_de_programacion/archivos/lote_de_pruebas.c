#include "header.h"

void lote_de_pruebas()
{
    FILE *pf;

    t_campeones vec[11]=
    {
        {"Emiliano","Martinez",23},
        {"Nahuel","Molina",26},
        {"Cristian","Romero",13},
        {"Nicolas","Otamendi",19},
        {"Nicolas","Tagliafico",3},
        {"Rodrigo","De Paul",7},
        {"Enzo","Fernandez",24},
        {"Alexis","MacAllister",20},
        {"Lionel","Messi",10},
        {"Julian","Alvarez",9},
        {"Angel","Di Maria",11},
    };

    pf=fopen("campeones.dat","wb");

    if(pf==NULL)
        exit (1);

    fwrite(vec,sizeof(vec),1,pf);

    fclose(pf);


}
