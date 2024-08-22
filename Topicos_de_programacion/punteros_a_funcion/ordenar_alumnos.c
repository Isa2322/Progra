#include "header.h"

int ordenar_alumnos(void * alu1,  void * alu2)
{
    int ap, nom, dni;

    t_alu *elem1, *elem2;

    elem1=(t_alu*)alu1;
    elem2=(t_alu*)alu2;

    ap=strcmp(elem1->ap,elem2->ap);
    nom=strcmp(elem1->nom,elem2->nom);
    dni=(elem1->dni)-(elem2->dni);

    if(ap==0)
    {
        if(nom==0)
        {
            return dni;
        }
        else
        {
            return nom;
        }
    }
    else
    {
        return ap;
    }
}
