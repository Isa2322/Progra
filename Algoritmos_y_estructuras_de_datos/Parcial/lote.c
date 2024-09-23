///43.094.671_Atamiranda_Isaias
#include "parcial_header.h"

void lote_prueba()
{
    FILE *pf;
    t_producto m_lote[]=
    {
        {"abc1", "producto 1", 26, {24, 02, 2024}, 8},
        {"bfm5", "producto 2", 06, {24, 12, 2024}, 9},
        {"bfm5", "producto 2", 02, {24, 06, 2023}, 5},
        {"cjk4", "producto 3", 11, {04, 12, 2023}, 5},
        {"dzu6", "producto 4", 01, {18, 12, 2022}, 6},
        {"exg8", "producto 5", 21, {13, 06, 2024}, 7},
        {"exg8", "producto 5", 21, {13, 11, 2024}, 7},
        {"etg9", "producto 7", 21, {13, 06, 2025}, 7}
    };

    pf=fopen("stock.dat", "wb");

    if(!pf)
        return;

    //for(i=0; i<7; i++)
    {
        fwrite(m_lote, sizeof(m_lote), 1, pf);
    }

    fclose(pf);
}
