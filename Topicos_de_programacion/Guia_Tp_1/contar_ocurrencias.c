int contar_ocurrencias(char* cad, char* elem)
{
    char *ref;
    int cont=0;

    ref=elem;

    while(*cad!='\0')
    {
        while(*cad==*elem)
        {
            cad++;
            elem++;

            if(*elem=='\0')
                cont++;
        }

        cad++;
        elem++;
        elem=ref;
    }

    return cont;
}
