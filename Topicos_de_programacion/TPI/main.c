#include "header.h"

int main()
{
    FILE *pf_descifrado, *pf_clave, *pf_cifrado;

   // pf_descifrado=fopen("Texto_a_cifrar.txt","rt");
    pf_clave=fopen("Clave_cifrado.txt","rt");
    pf_cifrado=fopen("texto_encriptado.txt","rt");

    if(pf_descifrado==NULL || pf_clave==NULL || pf_cifrado==NULL)
    {
        fclose(pf_cifrado);
        fclose(pf_descifrado);
        fclose(pf_clave);
        exit (1);
    }

    desencriptar_afin(pf_cifrado,pf_clave);

    //fclose(pf_descifrado);
    fclose(pf_clave);
    fclose(pf_cifrado);


    return 0;
}
