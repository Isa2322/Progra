#ifndef HEADER_TP_H_INCLUDED
#define HEADER_TP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include<curl/curl.h>
#include "cJSON.h"

#define TODO_OK 0
#define ERROR_CONFIG 1
#define ERROR_DE_MEMORIA 2

#define TAM 100
#define CANT 50
#define URL "https://6648df864032b1331becab06.mockapi.io/AyED/Api"
#define MAX_OPCIONES 4
#define MAX_PREGUNTAS 50
#define MAX_TEXT 256

typedef struct
{
    char     pregunta[MAX_TEXT];
    char     respcorrecta[MAX_TEXT];
    char     opciones[MAX_OPCIONES][MAX_TEXT];
    int      num_opciones;
} Pregunta;

typedef struct
{
    char    nombre[TAM];
    char    respuestas[8];
    int     tiempo[8];
    int     puntos[8];
} jugador;

typedef struct s_nodo
{
    void        *info;
    unsigned    tam_info;
    struct      s_nodo *sig;
} t_nodo;

typedef t_nodo *t_lista;


int carga_config            (int* rounds, int* cant_rounds);
int carga_participantes     (t_lista *lista,int* n_participantes);
void crear_lista            (t_lista *lista);
int lista_vacia             (t_lista *lista);
void vaciar_lista           (t_lista *lista);
int poner_sig               (t_lista *lista, const void *elem, unsigned tam_elem);
int randomizer              (t_lista *lista, int num);
void menu                   (char *opcion);
void dificultad             (int *dif);
void jugarRondas(int n_participantes,int tiempo_ronda,int rondas,int nivel_dif, t_lista *lista, Pregunta preguntas[]);
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
int obtener_preguntas(int niveldif, Pregunta preguntas[], int *num_preguntas);
int informe_arch_ganador(t_lista *lista, Pregunta preguntas[], int rondas, int n_participantes);
void calcular_puntaje(t_lista *lista, Pregunta preguntas[], int rondas, int n_participantes, jugador act[][8]);
void determinar_ganador(t_lista *lista, int rondas, int n_participantes, jugador act[][8]);
#endif // HEADER_TP_H_INCLUDED
