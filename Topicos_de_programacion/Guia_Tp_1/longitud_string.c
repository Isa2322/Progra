int longitud_string(char* vec)
{
    int cont=0;

    while(*vec!='\0')
    {
        cont++;
        vec++;
    }

    return cont;
}
