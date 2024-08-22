#include "header.h"

void recorrer_diagonal(int mat[][FIL], int filas)
{
    int i=0, j=0, cont=0;

    printf("%d\n",mat[i][j]);
    printf("\n");

    j++;

    if(filas%2==0)
    {
        while(cont==0)
        {
            while(j>=0 && cont==0)
            {
                printf("%d\n",mat[i][j]);
                j--;
                i++;
            }

            j++;
            i--;

            printf("\n");

            if(j==0 && i==filas-1)
            {
                cont++;
                j++;
            }
            else
            {
                i++;

                while(i>=0 && cont==0)
                {
                    printf("%d\n",mat[i][j]);
                    i--;
                    j++;
                }

                i++;
                j--;

                printf("\n");

                j++;

            }
        }
        cont=0;
        while(cont==0)
        {
            while(j<filas && cont==0)
            {
                printf("%d\n",mat[i][j]);
                i--;
                j++;
            }

            i++;
            j--;

            printf("\n");

            if(i==filas-1 && j==filas-1)
                cont++;
            else
            {
                i++;

                while(i<filas && cont==0)
                {
                    printf("%d\n",mat[i][j]);
                    j--;
                    i++;
                }

                j++;
                i--;

                printf("\n");

                j++;
            }

        }
    }
    else
    {
        while(cont==0)
        {
            while(j>=0 && cont==0)
            {
                printf("%d\n",mat[i][j]);
                j--;
                i++;
            }

            j++;
            i--;

            printf("\n");

            i++;

            while(i>=0 && cont==0)
            {
                printf("%d\n",mat[i][j]);
                i--;
                j++;
            }

            i++;
            j--;

            printf("\n");

            if(i==0 && j==filas-1)
            {
                cont++;
                i++;
            }
            else
                j++;

        }

        cont=0;

        while(cont==0)
        {
            while(i<filas && cont==0)
            {
                printf("%d\n",mat[i][j]);
                j--;
                i++;
            }

            j++;
            i--;

            printf("\n");

            j++;

            while(j<filas && cont==0)
            {
                printf("%d\n",mat[i][j]);
                i--;
                j++;
            }

            i++;
            j--;

            printf("\n");

            if(i==filas-1 && j==filas-1)
                cont++;

            i++;
        }
    }

}
