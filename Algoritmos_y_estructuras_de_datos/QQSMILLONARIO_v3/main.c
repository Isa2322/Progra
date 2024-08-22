#include "header_tp.h"

int main()
{
    int n_participantes, rondas, tiempo_ronda, nivel_dif;
    char opcion;
    t_lista lista;
    Pregunta preguntas[MAX_PREGUNTAS];
    crear_lista(&lista);
    carga_config(&rondas, &tiempo_ronda);
    menu(&opcion);

    while(opcion=='A')
    {
        carga_participantes(&lista, &n_participantes);
        dificultad(&nivel_dif);
        jugarRondas(n_participantes, tiempo_ronda, rondas, nivel_dif, &lista, preguntas);
        menu(&opcion);
    }

    vaciar_lista(&lista);
    return 0;
}
