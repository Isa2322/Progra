int comparar_string(char* vec1, char* vec2)
{
    int comparador=0;

    do
    {
        if(*vec1>*vec2)

            comparador=1;

        else

            if(*vec1<*vec2)

            comparador=-1;

        vec1++;
        vec2++;
    }
    while(comparador==0 && (*vec1!='\0' || *vec2!='\0'));

    return comparador;
}
