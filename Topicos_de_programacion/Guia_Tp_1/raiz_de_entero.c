#define VALOR_ABSOLUTO(a) (a)>0 ? a : a*(-1)

float raiz_de_entero(int num, float tol)
{
    float tnuevo, tant=1, dif;

    tnuevo=((num/tant)+tant)/2;

    dif=tnuevo-tant;

    while(VALOR_ABSOLUTO(dif)>tol)
    {
        tant=tnuevo;

        tnuevo=((num/tant)+tant)/2;

        dif=tnuevo-tant;
    }

    return tnuevo;
}
