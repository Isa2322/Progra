#include "header_recursividad.h"

int factorial(int n)
{
    //revisar que sea >0

    if(n<=0)
        return 1;

    return (factorial(n-1)*n);
}


int sumatoria(int n)
{
    if(n==1)
        return 1;

    return sumatoria(n-1)+n;
}


int fibonacci(int n)
{
    if(n<=0)
        return 0;

    if(n==1)
        return 1;

    return (fibonacci(n-1)+fibonacci(n-2));
}

void string_vert(char *ini)
{
    if(*ini == '\0')
        return;

    printf("%c \n",*ini);
    return string_vert(ini+1);
}

void string_vert_inv(char *ini)
{
    if(*ini != '\0')
        string_vert_inv(ini+1);

    printf("%c \n",*ini);
    return;
}

void string_vert_norm_inv(char *ini)
{
    if(*ini != '\0')
    {
        printf("%c \n",*ini);
        string_vert_norm_inv(ini+1);
    }

    printf("%c \n",*ini);
    return;
}

void string_red(char *ini)
{
    printf("%s \n",ini);

    if(*ini != '\0')
        string_red(ini+1);

    return;
}

void string_aum(char *ini)
{
    if(*ini != '\0')
        string_vert_inv(ini+1);

    printf("%s \n",ini);
    return;
}

void n_entero_inv(int n)
{
    printf("%d \n",n%10);
    if(n>10)
        n_entero_inv(n/10);

    return;
}

void n_entero(int n)
{
    if(n>=10)
        n_entero(n/10);

    printf("%d \n",n%10);
    return;
}

void n_entero_inv_norm(int n)
{
    printf("%d \n",n%10);
    if(n>=10)
        n_entero_inv_norm(n/10);

    printf("%d \n",n%10);
    return;
}

void numeros_4(int n)
{
    printf("%d \n",n);
    if(n>=10)
    {
        numeros_4(n/10);
    }
    printf("%d \n",n);
    return;
}


void numeros_5(int n)
{
    if(n>9)
        numeros_5(n/10);

    printf("%d \n", n);
    return;
}

int es_palindromo(char* ini)
{
    char *fin;

    fin= ini + strlen(ini);
    fin--;

    if(_es_palindromo(ini, fin) == 0)
        return 1;
    else
        return 0;
}

int _es_palindromo(char* ini, char* fin)
{
    if(ini >= fin)
    {
        return 0;
    }

    if(toupper(*ini) == toupper(*fin))
    {
        return (_es_palindromo(ini+1, fin-1));
    }
    else
    {
        if((*ini) == ' ')
            return(_es_palindromo(ini+1, fin));

        if((*fin) == ' ')
            return(_es_palindromo(ini, fin-1));
    }

    return (*ini)-(*fin);

}
