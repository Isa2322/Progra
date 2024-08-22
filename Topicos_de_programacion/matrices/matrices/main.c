#include "header.h"

int main()
{
    int matriz[5][5]={{11,12,13,14,15},{21,22,23,24,25},{31,32,33,34,35},{41,42,43,44,45},{51,52,53,54,55}};
    int matriz_par[FIL][FIL];
    int matriz_identidad[5][5]={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
    int matriz_res[5][5];
    int i, j, cont=1;


    for(i=0;i<FIL;i++)
    {
        for(j=0;j<FIL;j++)
        {
            matriz_par[i][j]=cont;
            cont++;
        }
    }

    producto_matricial(matriz,5,5,matriz_par,5,5,matriz_res,5,5);
    recorrer_filas_columnas(matriz_res,5);


    return 0;
}
