#include "parcial_header.h"

/*int bkup(int n_meses)
{
    FILE *pf_stock;
    FILE *pf_p_ok;
    FILE *pf_prox_venc;
    t_producto act, menor;
    t_pila pila;
    t_fecha hoy= {03,07,2024};
    int stock=0, vence=0, m_offset=0;


    pf_stock=fopen("stock.dat","rb");
    if(!pf_stock)
        return ERROR_ARCHIVO;

    pf_p_ok=fopen("prod_ok.dat","wb");
    if(!pf_p_ok)
    {
        fclose(pf_stock);
        return ERROR_ARCHIVO;
    }

    pf_prox_venc=fopen("prod_a_vencer.txt","wt");
    if(!pf_prox_venc)
    {
        fclose(pf_p_ok);
        fclose(pf_stock);
        return ERROR_ARCHIVO;
    }

    crear_pila(&pila);

    fread(&act, sizeof(t_producto), 1, pf_stock);
    menor=act;
    fseek(pf_stock, -sizeof(t_producto), SEEK_SET);
    fseek(pf_stock, 0L, SEEK_CUR);

    while(!feof(pf_stock))
    {
        fread(&act, sizeof(t_producto), 1, pf_stock);
    }*/

    /*while(!feof(pf_stock))
    {
        fread(&act, sizeof(t_producto), 1, pf_stock);

        vence=vence_pronto(hoy, act.fecha, n_meses);

        ///apilar

        if(vence==VENCE_PROX)
        {
            fseek(pf_stock, m_offset, SEEK_SET);///
            fseek(pf_stock, 0L, SEEK_CUR);///
            fread(&act, sizeof(t_producto), 1, pf_stock);
            menor=act;
            while(strcmp(act.cod_prod, menor.cod_prod) == 0 && !feof(pf_stock)) /// apilar hasta que cambie el codigo o se acabe el archivo
            {
                apilar(&pila, &act,sizeof(t_producto));
                fread(&act, sizeof(t_producto), 1, pf_stock);
            }                                                   /// desapilarlo en una variable e ir escribiendo en el arch nuevo (vence prox)
            menor=act;
            fseek(pf_stock, -sizeof(t_producto), SEEK_SET);
            fseek(pf_stock, 0L, SEEK_CUR);
            stock=0;
            m_offset=ftell(pf_stock);///
            /// vacio la pila
        }
        else
        {
            if((strcmp(act.cod_prod, menor.cod_prod) != 0) || (!feof(pf_stock))) /// Guardo solo el menor en el arch de productos ok
            {
                menor.cant=stock;
                fwrite(&menor, sizeof(t_producto), 1, pf_p_ok);
                stock=0;
                m_offset=ftell(pf_stock);///
                ///vacio la pila
            }
            else
            {
                stock+=act.cant;

                if(compara_fechas(act.fecha, menor.fecha)==ES_MENOR)
                    menor=act;
            }
        }
    }

    /// si sale sin escribir el ultimo registro pregunto si vence prox
    /// si vence prox escribo la pila en el archivo de vence prox
    /// si no, escribo solo el menor en productos ok
    /// vacio la lista


    fclose(pf_stock);
    fclose(pf_p_ok);

    while(!pila_vacia(&pila))/// esto no iria porque ya esta implementado arriba
    {
        desapilar(&pila, &act, sizeof(t_producto));
        fprintf(pf_prox_venc,"%s|%s|%d|%d %d %d|%d\n",act.cod_prod, act.desc, act.lote, act.fecha.dia, act.fecha.mes, act.fecha.anio, act.cant);
    }

    fclose(pf_prox_venc);
    vaciar_pila(&pila);

    return TODO_OK;
}
*/
