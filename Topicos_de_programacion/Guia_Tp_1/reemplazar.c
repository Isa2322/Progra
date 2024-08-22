char* reemplazar(char* cad, char* elem, char* nuevo)
{
    char *inic, *ref, *reemp, *aux, aux1, aux2;
    int cont=0;

    ref=elem;
    reemp=cad;
    inic=cad;

    while(*cad!='\0')
    {
        while(*cad==*elem)
        {
            cad++;
            elem++;

            if(*elem=='\0')
            {
                cad=reemp;



                while(*nuevo!=0)
                {
                    *cad=*nuevo;
                    cad++;
                    nuevo++;

                    if(*cad==' ' && *nuevo!=0)
                    {
                        aux=cad;

                        while(*(cad)!=0)
                        {
                            aux1=*cad;
                            cad++;
                            aux2=*cad;
                            *cad=aux1;
                            aux2=aux1;
                        }
                    }

                }
            }
        }

        reemp++;
        cad++;
        elem=ref;
    }

    return ref;
}
