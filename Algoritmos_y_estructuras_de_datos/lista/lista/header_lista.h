#ifndef HEADER_LISTA_H_INCLUDED
#define HEADER_LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM 1
#define VACIA 2
#define INSUFICIENTES_ELEMENTOS 3
#define TODO_OK 0
#define MINIMO( X , Y ) ((X)<(Y)?(X):(Y))

typedef struct s_nodo
{
    void *info;
    unsigned tam_info;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo *t_lista;

typedef struct
{
    char nombre[15];
    char apellido[15];
    char posicion[15];
    char equipo[50];
    unsigned numero;
}t_jugadores;




void crear_lista(t_lista *lista);
int lista_vacia(const t_lista *lista);
int lista_llena(const t_lista *lista, unsigned tam_elem);
void vaciar_lista(t_lista *lista);
int poner_al_inicio(t_lista *lista, void* info_nue, unsigned tam_info_nue);
int poner_al_final(t_lista *lista, void* info_nue, unsigned tam_info_nue);
int sacar_primero(t_lista *lista, void *elem, unsigned tam_elem);
int sacar_ultimo(t_lista *lista, void *elem, unsigned tam_elem);

void lote(t_lista *lista);
void mostrar_jugadores(t_lista *lista);
void cambiar_numeros(void *lista);
void my_map(t_lista* lista, void accion(void*));
void eliminar_sig(t_lista *lista);
void my_filter(t_lista *lista, int filtro(void*));
void mostrar(t_lista *lista);

int filtro_solo_arqueros(void *nodo);
int filtro_solo_defensores(void *nodo);
int filtro_solo_volantes(void *nodo);
int filtro_solo_delanteros(void *nodo);


int cmp_dorsal(void* nodo_1, void* nodo_2);
void ordenar_lista_asc(t_lista *lista, int (*cmp)(void*, void*));

#endif // HEADER_LISTA_H_INCLUDED
