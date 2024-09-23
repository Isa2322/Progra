///43.094.671_Atamiranda_Isaias

#include "parcial_header.h"

void crear_pila(t_pila* pila)
{
    *pila = NULL;
}


//////////////////////////////////////////////////////////////


int pila_vacia(t_pila* pila)
{
    return *pila == NULL;
}


//////////////////////////////////////////////////////////////


int apilar(t_pila* pila, void* dato, unsigned tam)
{
    t_nodo *nue;
    nue = malloc(sizeof(t_nodo));

    if(!nue)
        return SIN_MEM;

    nue->dato=malloc(tam);

    if(!nue->dato)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->dato, dato, tam);
    nue->cb=tam;
    nue->sig= *pila;
    *pila=nue;

    return TODO_OK;
}


//////////////////////////////////////////////////////////////


int desapilar(t_pila* pila, void* dato, unsigned tam)
{
    t_nodo *aux;

    aux=*pila;

    if(pila==NULL)
        return VACIA;

    *pila=aux->sig;

    memcpy(dato, aux->dato, MINIMO(tam, aux->cb));
    free(aux->dato);
    free(aux);

    return TODO_OK;
}


//////////////////////////////////////////////////////////////


void vaciar_pila(t_pila* pila)
{
    t_nodo *aux;

    while(*pila)
    {
        aux=*pila;
        *pila=aux->sig;

        free(aux->dato);
        free(aux);
    }
}


//////////////////////////////////////////////////////////////


int generar_archivos(int n_meses)
{
    FILE *pf_stock;
    FILE *pf_p_ok;
    FILE *pf_prox_venc;
    t_producto act, menor, aux;
    t_pila pila;
    t_fecha hoy= {03,07,2024};
    int stock=0, vence=0;


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
    fseek(pf_stock, 0L, SEEK_SET);
    fseek(pf_stock, 0L, SEEK_CUR);

    while(!feof(pf_stock))
    {
        fread(&act, sizeof(t_producto), 1, pf_stock);

        vence=vence_pronto(hoy, act.fecha, n_meses);

        apilar(&pila, &act, sizeof(t_producto));

        if(vence==VENCE_PROX)
        {
            ///fseek(pf_stock, m_offset, SEEK_SET);///
            ///fseek(pf_stock, 0L, SEEK_CUR);///
            menor=act;
            fread(&act, sizeof(t_producto), 1, pf_stock);

            while(strcmp(act.cod_prod, menor.cod_prod) == 0 && !feof(pf_stock)) /// apilar hasta que cambie el codigo o se acabe el archivo
            {
                apilar(&pila, &act,sizeof(t_producto));
                fread(&act, sizeof(t_producto), 1, pf_stock);
            }                                                   /// desapilarlo en una variable e ir escribiendo en el arch nuevo (vence prox)
            while(!pila_vacia(&pila))
            {
                desapilar(&pila, &aux, sizeof(t_producto));
                fprintf(pf_prox_venc,"%s|%s|%d|%d %d %d|%d\n",aux.cod_prod, aux.desc, aux.lote, aux.fecha.dia, aux.fecha.mes, aux.fecha.anio, aux.cant);
            }
            menor=act;
            fseek(pf_stock, -sizeof(t_producto), SEEK_CUR);
            fseek(pf_stock, 0L, SEEK_CUR);
            stock=0;
            ///m_offset=ftell(pf_stock);///
            /// vacio la pila
            vaciar_pila(&pila);
        }
        else
        {
            if((strcmp(act.cod_prod, menor.cod_prod) != 0) || feof(pf_stock)) /// Guardo solo el menor en el arch de productos ok
            {
                menor.cant=stock;
                fwrite(&menor, sizeof(t_producto), 1, pf_p_ok);
                stock=0;
                ///m_offset=ftell(pf_stock);///
                ///vacio la pila
                vaciar_pila(&pila);
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


    if(menor.cod_prod != act.cod_prod)
    {
        menor.cant=stock;
        fwrite(&menor, sizeof(t_producto), 1, pf_p_ok);
    }

    vaciar_pila(&pila);


    fclose(pf_stock);
    fclose(pf_p_ok);

    /*while(!pila_vacia(&pila))/// esto no iria porque ya esta implementado arriba
    {
        desapilar(&pila, &act, sizeof(t_producto));
        fprintf(pf_prox_venc,"%s|%s|%d|%d %d %d|%d\n",act.cod_prod, act.desc, act.lote, act.fecha.dia, act.fecha.mes, act.fecha.anio, act.cant);
    }*/

    fclose(pf_prox_venc);
    vaciar_pila(&pila);

    return TODO_OK;
}


int vence_pronto(t_fecha fecha_hoy, t_fecha fecha_prod, int meses)
{
    fecha_prod.anio-=fecha_hoy.anio;
    fecha_prod.mes-=fecha_hoy.mes;
    fecha_prod.dia-=fecha_hoy.dia;

    if(fecha_prod.dia < 1)
        fecha_prod.mes-=1;

    if(fecha_prod.mes < 1)
    {
        fecha_prod.anio-=1;
        fecha_prod.mes+=12;
    }

    if(fecha_prod.anio<0)
        return VENCE_PROX;

    if(fecha_prod.mes<meses)
        return VENCE_PROX;

    return NO_VENCE_PROX;
}

int compara_fechas(t_fecha f1, t_fecha f2)
{
    if(f1.anio < f2.anio)
        return ES_MENOR;

    if(f1.mes < f2.mes)
        return ES_MENOR;

    if(f1.dia < f2.dia)
        return ES_MENOR;

    return 0;
}

void mostrar_stock()
{
    FILE *pf;
    t_producto act;

    system("cls");

    pf=fopen("stock.dat","rb");
    if(!pf)
    {
        puts("No existe el archivo");
        return;
    }

    while(fread(&act, sizeof(t_producto), 1, pf) == 1)
    {
        printf("Cod:%s\tDesc:%s\tLote:%d\tFecha: %d/%d/%d\tStock:%d\t\t\t\n",act.cod_prod, act.desc, act.lote, act.fecha.dia, act.fecha.mes, act.fecha.anio, act.cant);
    }


    fclose(pf);
    system("pause");
    menu();
}


void mostrar_prod_ok()
{
    FILE *pf;
    t_producto act;

    system("cls");

    pf=fopen("prod_ok.dat","rb");
    if(!pf)
    {
        puts("No existe el archivo");
        return;
    }

    fread(&act, sizeof(t_producto), 1, pf);

    while(fread(&act, sizeof(t_producto), 1, pf) == 1)
    {
        printf("Codigo:%s\nDescripcion:%s\nLote:%d\nFecha de vencimiento: %d/%d/%d\nStock:%d\n\n\n\n",act.cod_prod, act.desc, act.lote, act.fecha.dia, act.fecha.mes, act.fecha.anio, act.cant);
        fread(&act, sizeof(t_producto), 1, pf);
    }

    fclose(pf);

    system("pause");
    menu();
}

void mostrar_arch_texto()
{
    FILE *pf;
    pf=fopen("prod_a_vencer.txt","rt");
    char aux[50];

    system("cls");

    if(!pf)
    {
        puts("No existe el archivo");
        return;
    }

    while(fgets(aux,50,pf))
    {
        printf(aux);
    }

    fclose(pf);

    system("pause");
    menu();
}


void menu()
{
    system("cls");
    int op, n_meses=2;
    printf("1) Generar archivos\n2) Ver archivos\n0) Salir\n");
    scanf("%d",&op);
    fflush(stdin);

    if(op==1)
    {
        if(generar_archivos(n_meses) != TODO_OK)
            puts("No se generaron los archivos correctamente");
        else
            puts("Se generaron los archivos correctamente");
    }
    else if(op == 2)
        mostrar_arch();
    else
        return;

}


void mostrar_arch()
{
    int op;

    system("cls");
    printf("1)Mostrar productos ok\n2)Mostrar productos a vencer\n3)Mostrar stock\n0) Salir\n");
    scanf("%d",&op);
    fflush(stdin);

    if(op==1)
        mostrar_prod_ok();
    else if(op == 2)
        mostrar_arch_texto();
    else if(op==3)
        mostrar_stock();
    else
        return;
}
