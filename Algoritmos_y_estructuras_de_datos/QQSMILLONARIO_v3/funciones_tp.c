#include "header_tp.h"

void crear_lista(t_lista *lista)
{
    *lista=NULL;
}

int lista_vacia(t_lista *lista)
{
    return (*lista==NULL);
}

void vaciar_lista(t_lista *lista)
{
    t_nodo *aux;

    if(*lista==NULL)
        return;

    while((*lista)->sig != NULL)
    {
        aux=*lista;
        *lista= aux->sig;
        free(aux);
    }
}

int poner_sig(t_lista *lista, const void *elem, unsigned tam_elem) //pongo un nuevo nodo a continuacion del que esta apuntado
{
    t_nodo *nue;

    nue=malloc(sizeof(t_nodo));

    if(!nue)
    {
        return ERROR_DE_MEMORIA;
    }

    nue->info=malloc(tam_elem);

    if(!(nue->info))
    {
        free(nue);
        return ERROR_DE_MEMORIA;
    }

    memcpy(nue->info, elem, tam_elem);
    nue->tam_info=tam_elem;

    if((*lista) == NULL)
    {
        nue->sig=nue;
        (*lista)=nue;
        return TODO_OK;
    }

    nue->sig=(*lista)->sig;
    (*lista)->sig=nue;

    return TODO_OK;
}

int randomizer(t_lista *lista, int num) //lo que hago aca es avanzar un numero n de nodos y luego declarar ese como el primero
{
    if(*lista == NULL)
        return ERROR_DE_MEMORIA;

    t_nodo *aux;

    int i, j;

    srand(time(NULL));
    j=rand()%num;

    aux=*lista;

    for(i=0; i<j; i++)
    {
        aux=aux->sig;
    }
    *lista=aux;

    return TODO_OK;
}

void sig_lista(t_lista *lista)
{
    t_nodo *aux;

    aux=(*lista)->sig;
    (*lista)=aux;
}

int carga_config(int* rounds, int* cant_rounds)
{
    FILE *config;
    config=fopen("config.txt","rt");
    if(!config)
    {
        puts("Error al cargar las configuraciones");
        return ERROR_CONFIG;
    }

    fscanf(config,"Rounds: %d\nTiempo por round: %d",rounds, cant_rounds);

    fclose(config);

    if(*rounds<4 && *rounds<7)
    {
        puts("Error al cargar las configuraciones");
        return ERROR_CONFIG;
    }

    return TODO_OK;
}

int carga_participantes(t_lista *lista,int* n_participantes)
{
    int i;

    do
    {
        printf("Ingrese la cantidad de participantes: ");
        scanf("%d",n_participantes);
        fflush(stdin);
        system("cls");
    }
    while(*n_participantes<1);

    for(i=0; i<(*n_participantes); i++)
    {
        jugador nuevo_j;

        printf("Ingrese el nombre del participante %d: ", i + 1);
        scanf("%s", nuevo_j.nombre);
        fflush(stdin);
        nuevo_j.puntos[i]=0;

        if(i>2)
        {
            randomizer(lista,i+1);
        }

        poner_sig(lista, &nuevo_j, sizeof(jugador));
    }

    return TODO_OK;
}

void menu(char *opcion)
{
    printf("\nSelecione una opcion....\n");
    printf("\n[A]Jugar\n");
    printf("\n[B]Salir\n");

    do
    {
        scanf("%c",opcion);
        fflush(stdin);
        (*opcion)=toupper(*opcion);
    }
    while((*opcion)!='A' && (*opcion)!='B');

}

void dificultad(int *dif)
{
    do
    {
        printf("Ingrese el nivel de dificultad ((1)facil,(2)medio,(3)dificil): ");
        scanf("%d",dif);
        fflush(stdin);
    }
    while((*dif)<1 || (*dif)>3);
}

void determinar_ganador(t_lista *lista, int rondas, int n_participantes, jugador act[][8])
{
int tot=0,mayor=0,ganadores[n_participantes], num_ganadores = 0,pos,i,r;
    for (i = 0; i < n_participantes; i++) // Calcular el total de puntos para cada jugador
    {
        for (r = 0; r < rondas; r++)
        {
            tot += act[i]->puntos[r];
        }
        if (tot > mayor)
        {
            mayor = tot;
            num_ganadores = 0;
            ganadores[num_ganadores++] = i;
        }
        else
        {
            if (tot == mayor)
            {
                ganadores[num_ganadores++] = i;
            }

        }
        tot = 0;
    }
    if (num_ganadores > 0)
    {
        printf("Los ganadores son:\n");
        for (i = 0; i < num_ganadores; i++)
        {
              pos= ganadores[i];
            for (r = 0; r < pos; r++)
            {
                sig_lista(lista);
            }
            memcpy(&act[pos][0], (*lista)->info, sizeof(jugador));
            printf("%s con %d puntos\n", act[pos][0].nombre, mayor);
        }
    }
    else
    {
        printf("No hay ganador.\n");
    }
}
void calcular_puntaje(t_lista *lista, Pregunta preguntas[], int rondas, int n_participantes, jugador act[][8])
 {
    int i, r, mejor_tiempo,empate;
    for (r = 0; r < rondas; r++)
    {
        empate=0;
        mejor_tiempo = 11;
        for (i = 0; i < n_participantes; i++)
        {
            if (act[i]->respuestas[r] == preguntas[r].respcorrecta[0])
            {
                act[i]->puntos[r] = 1;
                if (act[i]->tiempo[r] <= mejor_tiempo)
                {
                    if(act[i]->tiempo[r] == mejor_tiempo)
                    {
                        empate=1;
                    }
                mejor_tiempo = act[i]->tiempo[r];
                }
            }
            else
            {
                if(act[i]->respuestas[r]==' ')
                {
                    act[i]->puntos[r] =0;
                }
                else
                {
                    act[i]->puntos[r] = -2;
                }
            }
        }
        for (i = 0; i < n_participantes; i++)
        {
            if ((act[i]->tiempo[r] == mejor_tiempo) && (act[i]->respuestas[r] == preguntas[r].respcorrecta[0]))
            {
                if(empate==1)
                {
                    act[i]->puntos[r] += 1;
                }
                else
                    act[i]->puntos[r] += 2;
            }
            else
            {
                if((act[i]->respuestas[r] == preguntas[r].respcorrecta[0]))
                {
                    act[i]->puntos[r] += 1;
                }
            }
        }
    }
    determinar_ganador(lista,rondas,n_participantes,act);
}
void jugarRondas(int n_participantes,int tiempo_ronda,int rondas,int nivel_dif, t_lista *lista, Pregunta preguntas[])
{
    int r, num_preguntas=0, j, hay_resp, tiempo_respuesta, i;
    char respuesta;
    jugador act[n_participantes][8];
    Pregunta *pregunta;
    clock_t start_time;

    if (!obtener_preguntas(nivel_dif, preguntas, &num_preguntas))
    {
        printf("No se pudieron obtener las preguntas\n");
        return;
    }

    for(i=0; i<n_participantes; i++)
    {
        memcpy(&act[i][0], (*lista)->info, sizeof(jugador));
        printf("Turno de %s.\n Estas listo/a? \n ", act[i][0].nombre);
        fflush(stdin);
        system("pause");
        system("cls");
        for(r=0; r<rondas; r++)
        {
            printf("Ronda %d\n",r+1);
            pregunta=&preguntas[r];
            printf("Pregunta: %s\n", pregunta->pregunta);
            for(j=0; j<pregunta->num_opciones; j++)
            {
                printf("%s\n", pregunta->opciones[j]);
            }
            tiempo_respuesta=0;
            hay_resp=0;
            start_time=clock();
            while(((clock()-start_time)/CLOCKS_PER_SEC)<tiempo_ronda)
            {
                if(kbhit())
                {
                    respuesta=getchar();
                    respuesta=toupper(respuesta);
                    fflush(stdin);
                    tiempo_respuesta=(clock()-start_time)/CLOCKS_PER_SEC;
                    hay_resp=1;
                    break;
                }
            }

            if(!hay_resp)
            {
                printf("\nTiempo agotado. Siguiente pregunta...\n");
                respuesta=' '; // Sin respuesta
                tiempo_respuesta=tiempo_ronda;
            }

            act[i]->respuestas[r]=respuesta;
            act[i]->tiempo[r]=tiempo_respuesta;
            printf("%d\n", act[i]->tiempo[r]);
        }
        lista=&(*lista)->sig;
        //system("pause");
        system("cls");
    }
    calcular_puntaje(lista, preguntas, rondas, n_participantes, act);
}

int informe_arch_ganador(t_lista *lista, Pregunta preguntas[], int rondas, int n_participantes)
{
    int i, j, max=-1, empate=0;
    char str[35];
    jugador *act;
    FILE *pf;
    time_t rawtime;
    struct tm *timeinfo;

    act=malloc(sizeof(jugador));
    if(!act)
        return ERROR_DE_MEMORIA;


    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(str, 35, "informe-juego_%Y-%m-%d-%H%M.txt", timeinfo);

    pf=fopen(str,"wt");
    fclose(pf);

    free(act);
    return TODO_OK;
}

///

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char **readBuffer = (char **)userp;
    *readBuffer = realloc(*readBuffer, strlen(*readBuffer) + realsize + 1);   // Redimensionar el buffer para agregar los nuevos datos
    if (*readBuffer == NULL)
    {
        printf("Error al reasignar memoria\n");
        return 0;
    }
    strncat(*readBuffer, contents, realsize);// Copiar los nuevos datos al buffer
    return realsize;
}

///
/**implementar la api**/
int obtener_preguntas(int niveldif, Pregunta preguntas[], int *num_preguntas)
{
    int count = 0, level;
    CURL *curl;
    CURLcode res;
    char *readBuffer = malloc(1);
    if (readBuffer == NULL)
    {
        printf("Error al asignar memoria\n");
        return 0;
    }
    readBuffer[0] = '\0';  // Inicializar el buffer como cadena vacía
    curl_global_init(CURL_GLOBAL_DEFAULT);// Inicializar el manejo de curl
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, URL);// Establecer la URL de la solicitud GET
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);// Desactivar la verificación del certificado SSL
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);// Establecer la función de retorno de llamada para manejar la respuesta
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);// Realizar la solicitud HTTP GET
        if (res != CURLE_OK)// Verificar si la solicitud fue exitosa
        {
            fprintf(stderr, "Error en la solicitud: %s\n", curl_easy_strerror(res));
            free(readBuffer);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 0;
        }
        cJSON *root = cJSON_Parse(readBuffer);// Parsear la respuesta JSON
        if (root == NULL)
        {
            fprintf(stderr, "Error al parsear el JSON: %s\n", cJSON_GetErrorPtr());
            free(readBuffer);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return 0;
        }
        cJSON *question;// Asumiendo que root es un array de objetos JSON
        cJSON_ArrayForEach(question, root)
        {
            cJSON *nivel = cJSON_GetObjectItem(question, "nivel");
            if (nivel != NULL)
            {
                level = cJSON_GetNumberValue(nivel);
                if (level == niveldif && count < MAX_PREGUNTAS)// Filtrar las preguntas por nivel de dificultad deseado
                {
                    cJSON *text = cJSON_GetObjectItem(question, "pregunta");
                    if (text != NULL)
                    {
                        strcpy(preguntas[count].pregunta, cJSON_GetStringValue(text));
                        preguntas[count].num_opciones = MAX_OPCIONES; // Obtener opciones dinámicamente
                        strcpy(preguntas[count].opciones[0], cJSON_GetStringValue(cJSON_GetObjectItem(question, "opcion_1")));
                        strcpy(preguntas[count].opciones[1], cJSON_GetStringValue(cJSON_GetObjectItem(question, "opcion_2")));
                        strcpy(preguntas[count].opciones[2], cJSON_GetStringValue(cJSON_GetObjectItem(question, "opcion_3")));
                        strcpy(preguntas[count].opciones[3], cJSON_GetStringValue(cJSON_GetObjectItem(question, "opcion_4")));
                        strcpy(preguntas[count].respcorrecta,cJSON_GetStringValue(cJSON_GetObjectItem(question, "resp_correcta")));
                        count++;
                    }
                }
            }
        }

        *num_preguntas = count;
        cJSON_Delete(root);// Liberar memoria
        free(readBuffer);
    }
    else
    {
        free(readBuffer);
        curl_global_cleanup();
        return 0;
    }
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 1;
}
