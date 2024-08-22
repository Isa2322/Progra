char* concatenar_string(char* vec1, char* vec2)
{
    char *str;

    str=vec1;

    while(*str!=0)
    {
        str++;
    }

    while(*vec2!=0)
    {
        *str=*vec2;
        str++;
        vec2++;
    }
    str++;
    *str=0;

    return vec1;
}
