#include "header_cola.h"

void lote_de_pruebas()
{
    FILE* pf;
    t_movimientos* aux;
    t_movimientos movimientos[45] = {
        // Cliente Alice
        {"Alice", 'D', 1500},
        {"Alice", 'E', 3000},

        // Cliente Bob
        {"Bob", 'D', 2000},
        {"Bob", 'E', 2500},
        {"Bob", 'D', 1500},

        // Cliente Carol
        {"Carol", 'D', 1000},
        {"Carol", 'D', 4500},

        // Cliente Dave
        {"Dave", 'E', 2200},
        {"Dave", 'D', 1200},
        {"Dave", 'E', 3500},

        // Cliente Eve
        {"Eve", 'D', 4700},
        {"Eve", 'E', 1500},
        {"Eve", 'D', 2000},
        {"Eve", 'E', 2700},
        {"Eve", 'D', 4000},

        // Cliente Frank
        {"Frank", 'D', 1350},
        {"Frank", 'E', 2450},

        // Cliente Grace
        {"Grace", 'E', 3125},
        {"Grace", 'D', 2800},
        {"Grace", 'D', 4000},

        // Cliente Helen
        {"Helen", 'E', 2200},
        {"Helen", 'D', 1900},
        {"Helen", 'E', 2150},
        {"Helen", 'D', 3100},

        // Cliente Ian
        {"Ian", 'D', 2300},
        {"Ian", 'E', 1500},
        {"Ian", 'D', 4200},

        // Cliente Jane
        {"Jane", 'E', 2000},
        {"Jane", 'D', 3000},
        {"Jane", 'E', 1800},

        // Cliente Kyle
        {"Kyle", 'D', 1200},
        {"Kyle", 'D', 3600},

        // Cliente Laura
        {"Laura", 'E', 3300},
        {"Laura", 'D', 2300},
        {"Laura", 'E', 4400},
        {"Laura", 'D', 1000},

        // Cliente Mike
        {"Mike", 'D', 2900},
        {"Mike", 'E', 1700},
        {"Mike", 'D', 4500},

        // Cliente Nancy
        {"Nancy", 'E', 2000},
        {"Nancy", 'D', 2100},
        {"Nancy", 'E', 1900},

        // Cliente Oscar
        {"Oscar", 'D', 3100},
        {"Oscar", 'E', 2800},
        {"Oscar", 'D', 1200},
    };

    aux=movimientos;
    pf=fopen("banco.dat","wb");

    if(!pf)
        exit(1);
    // Mostrar los movimientos
    for (int i = 0; i < 45; i++) {
        printf("Cliente: %s, Tipo: %c, Importe: %d\n",aux->nombre_cliente, aux->tipo_mov, aux->importe);
        fwrite(aux,sizeof(t_movimientos),1,pf);
     //   aux+=sizeof(t_movimientos);
        aux++;
    }

    fclose(pf);
}
