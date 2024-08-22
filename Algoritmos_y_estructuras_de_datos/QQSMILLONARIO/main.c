#include"Cabe.h"

int main()
{
    int participantes,tiempo,rondas,niveldif;
    char texto[TAM],opcion;
    FILE*archtxt;

    printf("Ingrese la cantidad de participantes: ");
    scanf("%d",&participantes);
    char vec[participantes][CANT];
    printf("Ingrese la cantidad maxima de tiempo: ");
    scanf("%d",&tiempo);
    printf("Ingrese las rondas totales: ");
    scanf("%d",&rondas);
    creararchivo(participantes,tiempo,rondas);
    archtxt=fopen("Configuracion_Inicial","rt");
    if(archtxt==NULL)
    {
        printf("Error al abrir el archivo \n");
        return 1;
    }
while(fgets(texto,sizeof(texto),archtxt)!=NULL)
        printf("%s",texto);
do
{
    mostrarmenu();
    do
    {
    scanf("%c",&opcion);
    fflush(stdin);
    opcion=toupper(opcion);
    }while(opcion!='A' && opcion!='B');

    if(opcion=='A')
    {
        ingresarparticipantes( participantes,vec);
        do
        {
        printf("Ingrese el nivel de dificultad ((1)facil,(2)medio,(3)dificil): ");
        scanf("%d",&niveldif);
        }while(niveldif<1 || niveldif>3);
        sortearparticipantes(participantes,vec);
        jugarRondas(participantes,tiempo,rondas,vec,niveldif);
    }
    else
        printf("FIN DEL JUEGO");
}while(opcion=='A');

return 0;

}
