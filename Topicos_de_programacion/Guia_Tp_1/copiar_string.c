char* copiar_string( char* str1, char* str2)
{
    char *ini;

    ini=str1;

    while(*str2!=0)
    {
        *str1=*str2;
        str1++;
        str2++;
    }

    *str1='\0';

    return ini;
}
