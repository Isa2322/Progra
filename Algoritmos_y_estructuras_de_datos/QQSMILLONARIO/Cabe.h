#ifndef CABE_H_INCLUDED
#define CABE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <conio.h>
#include <windows.h>
#include<curl/curl.h>
#include "cJSON.h"


#define TAM 100
#define CANT 50
#define URL "https://6648df864032b1331becab06.mockapi.io/AyED/Api"
#define MAX_OPCIONES 4
#define MAX_PREGUNTAS 50
#define MAX_TEXT 256

typedef struct
{
    char pregunta[MAX_TEXT];
    char respcorrecta[MAX_TEXT];
    char opciones[MAX_OPCIONES][MAX_TEXT];
    int num_opciones;
} Pregunta;

typedef struct
{
    char respuesta;
    int tiempo;
}jugador;

typedef struct s_nodo
{
    void *info;
    unsigned tam_info;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo *t_lista;

int creararchivo(int n,int r, int t);
void mostrarmenu();
void sortearparticipantes(int participantes,char vec[][CANT]);
void cambiar(char a[],char b[]);
void jugarRondas(int cantidadParticipantes, int tiempoMaximo, int rondas, char nombres[][CANT],int niveldif);
void ingresarparticipantes(int cantidad,char nombres[][CANT]);
int obtenerPreguntas(int niveldif, Pregunta preguntas[], int *num_preguntas);
void obtenerpuntaje(char respuesta,Pregunta *pregunta,int tiempo,int part,int tiempores[]);
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

#endif // CABE_H_INCLUDED
