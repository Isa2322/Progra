char* normalizar_string(char* str)
{
    char *inic, *aux;

    inic=str;


    while(*str!=0)
    {
        while(*inic==' ')
        {
            *str=*(str+1);
            str++;
            inic=str;
        }

        aux=str;

        while(*str==' ' && *(str+1)==' ')
        {
            while(*str!=0)
            {
                str++;
                *str=*(str+1);
            }

            str=aux;

        }

        while(*str==' ' && *(str+1)=='\0')
        {
            *str=*(str+1);
            str--;
        }


        str++;
    }

    return inic;
}
