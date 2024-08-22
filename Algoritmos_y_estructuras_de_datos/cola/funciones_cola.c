#include "header_cola.h"

void crear_cola(tcola* cola)
{
    cola->tam_disp=MAX;
    cola->pri=1;
    cola->ult=1;
}


////////////////////////////////////////////////////////////////////////


int cola_vacia(const tcola* cola)
{
    return cola->tam_disp==MAX;
}


////////////////////////////////////////////////////////////////////////


int cola_llena(const tcola* cola, unsigned tam_dato)
{
    return cola->tam_disp<(tam_dato+sizeof(unsigned));
}


////////////////////////////////////////////////////////////////////////


void vaciar_cola(tcola* cola)
{
    cola->tam_disp=MAX;

    cola->pri=cola->ult;
}


////////////////////////////////////////////////////////////////////////


int acolar(tcola* cola, const void* elem, unsigned tam_elem)
{
    unsigned ini, fin;

    if(cola->tam_disp<(tam_elem+sizeof(unsigned)))
        return ERROR;

    cola->tam_disp-=(tam_elem+sizeof(unsigned));
    ini=MINIMO(MAX-(cola->ult),sizeof(unsigned));

    if(ini>0) //si es cero es porque no queda lugar en el vector (tam=ultimo)
    {
        memcpy(cola->vec+cola->ult, (char*)&tam_elem, ini); //copio la diferencia entre el tam y el ultimo
    }

    fin=sizeof(unsigned)-ini; //verifico si quedo parte del elemento sin copiar

    if(fin>0)
    {
        memcpy(cola->vec, ((char*)&tam_elem)+ini, fin); // copio lo que resta en caso de que me falte
    }

    cola->ult= fin>0? fin: cola->ult+ini; //fin es lo que me pase del vector, si me pase entonceces es el nuevo ult
                                          //si fin==0 entonces aun no me pase y seteo el nuevo ult

    ini= MINIMO(MAX-(cola->ult), tam_elem);

    if(ini>0)
    {
        memcpy(cola->vec+cola->ult, ((char*)elem), ini);
    }

    fin=tam_elem-ini;

    if(fin>0)
    {
        memcpy(cola->vec, ((char*)elem)+ini, fin);
    }
    cola->ult = fin>0? fin: cola->ult+ini;


    return TODO_OK;
}


////////////////////////////////////////////////////////////////////////


int desacolar(tcola* cola, void* elem, unsigned tam_elem)
{
    unsigned tam_aux, ini, fin;

    if(cola->tam_disp==MAX)
    {
        return ERROR;
    }

    cola->tam_disp+=(sizeof(unsigned)+tam_elem);

    ini=MINIMO(MAX-cola->pri, sizeof(unsigned));

    if(ini>0)
    {
        memcpy(((char*)&tam_aux), cola->vec+cola->pri, ini);
    }

    fin= sizeof(unsigned)-ini;

    if(fin>0)
    {
        memcpy(((char*)&tam_aux)+ini, cola->vec, fin);
    }

    cola->pri= fin>0? fin: cola->pri+ini;

    ini= MINIMO(MAX-cola->pri,tam_elem);

    if(ini>0)
    {
        memcpy((char*)elem, cola->vec+cola->pri, ini);
    }

    fin= tam_elem-ini;

    if(fin>0)
    {
        memcpy((char*)elem, cola->vec+ini, fin);
    }

    cola->pri = fin>0? fin : cola->pri+tam_elem;

    return TODO_OK;
}


////////////////////////////////////////////////////////////////////////


int ver_tope(tcola* cola, void* elem, unsigned tam_elem)
{
    unsigned tam_aux, ini, fin, npri;

    npri=cola->pri;

    if(cola->tam_disp==MAX)
    {
        return ERROR;
    }

    ini=MINIMO(MAX-cola->pri, sizeof(unsigned));

    if(ini>0)
    {
        memcpy(((char*)&tam_aux), cola->vec+cola->pri, ini);
    }

    fin= sizeof(unsigned)-ini;

    if(fin>0)
    {
        memcpy(((char*)&tam_aux)+ini, cola->vec, fin);
    }

    npri= fin>0? fin: cola->pri+ini;

    ini= MINIMO(MAX-cola->pri,tam_elem);

    if(ini>0)
    {
        memcpy((char*)elem, cola->vec+npri, ini);
    }

    fin= tam_elem-ini;

    if(fin>0)
    {
        memcpy((char*)elem, cola->vec+ini, fin);
    }

    return TODO_OK;


}
///// FALTA DESACOLAR  Y VER EL PRIMERO DE LA COLA
