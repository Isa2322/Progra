#include "Cabe.h"

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

int creararchivo(int n,int t, int r)
{
    FILE*archtxt=fopen("Configuracion_Inicial","wt");
    if(archtxt==NULL)
    {
        printf("Error al abrir el archivo \n");
        return 1;
    }

fprintf(archtxt, "Configuracion inicial :\%d round\n%d segundos por round\n%d Participantes",r,t,n);
fclose(archtxt);
return 0;
}

///

void mostrarmenu()
{
    printf("\nSelecione una opcion....\n");
    printf("\n[A]Jugar\n");
    printf("\n[B]Salir\n");
}

///

void cambiar(char a[],char b[])
{
    char aux[CANT];
    strcpy(aux,a);
    strcpy(a,b);
    strcpy(b,aux);
}

///

void sortearparticipantes(int participantes , char vec[][CANT])
{
    unsigned i,j;
    srand(time(NULL));
    for(i=0;i<participantes;i++)
    {
        j=rand()%(i+1);
        cambiar(vec[i],vec[j]);
    }
    printf("ORDEN DE JUEGO\n");
    for ( i = 0; i < participantes; i++)
    {
        printf("%d: %s\n", i + 1, vec[i]);
    }
}

///

void ingresarparticipantes(int cantidad, char nombres[][CANT])
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el nombre del participante %d: ", i + 1);
        scanf("%s", nombres[i]);
        fflush(stdin);
    }
}

///

void jugarRondas(int participantes,int tiempo,int rondas,char vec[][CANT],int niveldif)
{
    int i, totalrondas, tiempo_transcurrido = 0,num_preguntas = 0;
    char respuesta,arrancar;
    Pregunta preguntas[MAX_PREGUNTAS];
    jugador *jug;
    fflush(stdin);
    for(i=0;i<participantes;i++)
        {
            totalrondas=0;
            if (!obtenerPreguntas(niveldif, preguntas, &num_preguntas))
            {
                printf("No se pudieron obtener las preguntas\n");
                return;
            }
            printf("ARRANCA %s ¿Estas listo?(si para continuar) : ",vec[i]);
            scanf("%c",&arrancar);
            fflush(stdin);
            while(totalrondas<rondas)
            {
                Pregunta *pregunta = &preguntas[totalrondas];
                printf("Pregunta: %s\n", pregunta->pregunta);
                for (int j = 0; j < pregunta->num_opciones; j++)
                    {
                        printf("%s\n", pregunta->opciones[j]);
                    }

                DWORD start_time = GetTickCount();// Configurar temporizador para 10 segundos)
                tiempo_transcurrido = 0;
                while (!_kbhit() && tiempo_transcurrido < tiempo)
                {
                    tiempo_transcurrido = (GetTickCount() - start_time) / 1000;
                    if (tiempo_transcurrido >= tiempo)
                    {
                        printf("\nTiempo agotado. Avanzando automáticamente...\n");
                    }
                }
                if (_kbhit())
                {
                    do
                    {
                        scanf("%c",&respuesta);
                        fflush(stdin);
                        respuesta=toupper(respuesta);
                    }while(respuesta!='A' && respuesta!='B' && respuesta!='C'&& respuesta!='D');
                    printf("TIEMPO DE RESPUESTA: %d",tiempo_transcurrido );
                }



            totalrondas++;
        }
        system("pause");
        system("cls");
     }
}
void obtenerpuntaje(char respuesta,Pregunta *pregunta,int tiempo,int part,int tiempores[])
{
        if(respuesta==*pregunta->respcorrecta)
         {
            printf("ACIERTO");
         }
        else
            printf("DESACIERTO XD");
}

/**implementar la api**/
int obtenerPreguntas(int niveldif, Pregunta preguntas[], int *num_preguntas) {
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
