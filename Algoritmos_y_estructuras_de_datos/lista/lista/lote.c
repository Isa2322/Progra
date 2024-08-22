#include "header_lista.h"

void lote(t_lista *lista)
{
    t_jugadores jugadores[26], *aux;
    t_lista *ini=lista;
    int i;

    strcpy(jugadores[0].nombre, "Lionel");
    strcpy(jugadores[0].apellido, "Messi");
    strcpy(jugadores[0].posicion, "Delantero");
    strcpy(jugadores[0].equipo, "Paris Saint-Germain");
    jugadores[0].numero = 30;

    strcpy(jugadores[1].nombre, "Cristiano");
    strcpy(jugadores[1].apellido, "Ronaldo");
    strcpy(jugadores[1].posicion, "Delantero");
    strcpy(jugadores[1].equipo, "Manchester United");
    jugadores[1].numero = 7;

    strcpy(jugadores[2].nombre, "Carlos");
    strcpy(jugadores[2].apellido, "Tevez");
    strcpy(jugadores[2].posicion, "Delantero");
    strcpy(jugadores[2].equipo, "Boca Juniors");
    jugadores[2].numero = 10;

    strcpy(jugadores[3].nombre, "Juan Roman");
    strcpy(jugadores[3].apellido, "Riquelme");
    strcpy(jugadores[3].posicion, "Mediocampista");
    strcpy(jugadores[3].equipo, "Boca Juniors");
    jugadores[3].numero = 10;

    strcpy(jugadores[4].nombre, "Martin");
    strcpy(jugadores[4].apellido, "Palermo");
    strcpy(jugadores[4].posicion, "Delantero");
    strcpy(jugadores[4].equipo, "Boca Juniors");
    jugadores[4].numero = 9;

    strcpy(jugadores[5].nombre, "Kylian");
    strcpy(jugadores[5].apellido, "Mbappe");
    strcpy(jugadores[5].posicion, "Delantero");
    strcpy(jugadores[5].equipo, "Paris Saint-Germain");
    jugadores[5].numero = 7;

    strcpy(jugadores[6].nombre, "Neymar");
    strcpy(jugadores[6].apellido, "Jr");
    strcpy(jugadores[6].posicion, "Delantero");
    strcpy(jugadores[6].equipo, "Paris Saint-Germain");
    jugadores[6].numero = 10;

    strcpy(jugadores[7].nombre, "Luka");
    strcpy(jugadores[7].apellido, "Modric");
    strcpy(jugadores[7].posicion, "Mediocampista");
    strcpy(jugadores[7].equipo, "Real Madrid");
    jugadores[7].numero = 10;

    strcpy(jugadores[8].nombre, "Sergio");
    strcpy(jugadores[8].apellido, "Ramos");
    strcpy(jugadores[8].posicion, "Defensa");
    strcpy(jugadores[8].equipo, "Paris Saint-Germain");
    jugadores[8].numero = 4;

    strcpy(jugadores[9].nombre, "Robert");
    strcpy(jugadores[9].apellido, "Lewandowski");
    strcpy(jugadores[9].posicion, "Delantero");
    strcpy(jugadores[9].equipo, "Barcelona");
    jugadores[9].numero = 9;

    strcpy(jugadores[10].nombre, "Manuel");
    strcpy(jugadores[10].apellido, "Neuer");
    strcpy(jugadores[10].posicion, "Portero");
    strcpy(jugadores[10].equipo, "Bayern Munich");
    jugadores[10].numero = 1;

    strcpy(jugadores[11].nombre, "Kevin");
    strcpy(jugadores[11].apellido, "De Bruyne");
    strcpy(jugadores[11].posicion, "Mediocampista");
    strcpy(jugadores[11].equipo, "Manchester City");
    jugadores[11].numero = 17;

    strcpy(jugadores[12].nombre, "Virgil");
    strcpy(jugadores[12].apellido, "van Dijk");
    strcpy(jugadores[12].posicion, "Defensa");
    strcpy(jugadores[12].equipo, "Liverpool");
    jugadores[12].numero = 4;

    strcpy(jugadores[13].nombre, "Eden");
    strcpy(jugadores[13].apellido, "Hazard");
    strcpy(jugadores[13].posicion, "Delantero");
    strcpy(jugadores[13].equipo, "Real Madrid");
    jugadores[13].numero = 7;

    strcpy(jugadores[14].nombre, "Antoine");
    strcpy(jugadores[14].apellido, "Griezmann");
    strcpy(jugadores[14].posicion, "Delantero");
    strcpy(jugadores[14].equipo, "Atletico Madrid");
    jugadores[14].numero = 8;

    strcpy(jugadores[15].nombre, "Paulo");
    strcpy(jugadores[15].apellido, "Dybala");
    strcpy(jugadores[15].posicion, "Delantero");
    strcpy(jugadores[15].equipo, "Roma");
    jugadores[15].numero = 21;

    strcpy(jugadores[16].nombre, "Harry");
    strcpy(jugadores[16].apellido, "Kane");
    strcpy(jugadores[16].posicion, "Delantero");
    strcpy(jugadores[16].equipo, "Tottenham Hotspur");
    jugadores[16].numero = 10;

    strcpy(jugadores[17].nombre, "Sadio");
    strcpy(jugadores[17].apellido, "Mane");
    strcpy(jugadores[17].posicion, "Delantero");
    strcpy(jugadores[17].equipo, "Bayern Munich");
    jugadores[17].numero = 17;

    strcpy(jugadores[18].nombre, "Mohamed");
    strcpy(jugadores[18].apellido, "Salah");
    strcpy(jugadores[18].posicion, "Delantero");
    strcpy(jugadores[18].equipo, "Liverpool");
    jugadores[18].numero = 11;

    strcpy(jugadores[19].nombre, "Karim");
    strcpy(jugadores[19].apellido, "Benzema");
    strcpy(jugadores[19].posicion, "Delantero");
    strcpy(jugadores[19].equipo, "Al-Ittihad");
    jugadores[19].numero = 9;

    strcpy(jugadores[20].nombre, "Gerard");
    strcpy(jugadores[20].apellido, "Pique");
    strcpy(jugadores[20].posicion, "Defensa");
    strcpy(jugadores[20].equipo, "Retirado");
    jugadores[20].numero = 3;

    strcpy(jugadores[21].nombre, "Sergio");
    strcpy(jugadores[21].apellido, "Busquets");
    strcpy(jugadores[21].posicion, "Mediocampista");
    strcpy(jugadores[21].equipo, "Inter Miami");
    jugadores[21].numero = 5;

    strcpy(jugadores[22].nombre, "Frenkie");
    strcpy(jugadores[22].apellido, "de Jong");
    strcpy(jugadores[22].posicion, "Mediocampista");
    strcpy(jugadores[22].equipo, "Barcelona");
    jugadores[22].numero = 21;

    strcpy(jugadores[23].nombre, "Pedri");
    strcpy(jugadores[23].apellido, "González");
    strcpy(jugadores[23].posicion, "Mediocampista");
    strcpy(jugadores[23].equipo, "Barcelona");
    jugadores[23].numero = 8;

    strcpy(jugadores[24].nombre, "Luis");
    strcpy(jugadores[24].apellido, "Suárez");
    strcpy(jugadores[24].posicion, "Delantero");
    strcpy(jugadores[24].equipo, "Gremio");
    jugadores[24].numero = 9;

    strcpy(jugadores[25].nombre, "Gianluigi");
    strcpy(jugadores[25].apellido, "Donnarumma");
    strcpy(jugadores[25].posicion, "Portero");
    strcpy(jugadores[25].equipo, "Paris Saint-Germain");
    jugadores[25].numero = 99;


    for(i=0; i<26; i++)
    {
        aux= &(jugadores[i]);
        poner_al_inicio(lista, aux, sizeof(t_jugadores));
    }

    lista=ini;
}
