int contar_ocurrencias_solapamiento(char* cad, char* elem)
{
    char *ref, *sol;
    int cont=0;

    ref=elem;
    sol=elem;

    while(*cad!='\0')
    {
        while(*cad==*elem || sol!=ref)
        {
            cad++;
            elem++;

            if(*cad==*sol && *elem!=0)
                sol++;
            else
                sol=ref;


            if(*elem=='\0')
            {
                cont++;
                elem=ref;
            }

            if(*sol=='\0' && sol!=elem)
                cont++;
        }

        if(*cad!='\0')
        {
            elem=ref;
            sol=ref;
            cad++;
        }

    }

    return cont;
}
