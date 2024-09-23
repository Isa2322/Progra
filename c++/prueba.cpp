#include <iostream>

using namespace std;

/*
using std::cout;
using std::endl;
*/

/// ACA VAN LAS CLASES///

class Pokemon ///ABAJO VAN LOS ATRIBUTOS
{
    public: ///Puede ser privado
        string nombre;
        float peso;

    ///Estos son el constructor y los metodos

    public: ///Los metodos debenser publicos para poder usarlos en otra parte del proyecto
        Pokemon(string nombre, float peso);/// Esto es un constructor ///Van en el orden que los declare arriba los datos y su tipo

        void Saludo();
};

Pokemon::Pokemon(string _nombre, float _peso) /// De la clase Pokemon, voy a usar mi constructor para inicializarlo
{
    nombre = _nombre;
    peso = _peso;
}

void Pokemon::Saludo()
{
    cout<<"El Pokemon que te saluda es: "<<nombre<<" y el pesa: "<<peso<<"Kg\n";
}

/// Herencia ///
/// Clase hija

class Pokemons_Fuego : public Pokemon
{
public:
    int vida;
    char genero;

public:
    Pokemons_Fuego(string, float, int, char);
    //void Mostrar_pokemon();
    ///Polimorfismo
    void Saludo();
};

Pokemons_Fuego::Pokemons_Fuego(string _nombre, float _peso, int _vida, char _genero) : Pokemon(_nombre, _peso) /// A la derecha pongo el constructor del que quiero heredar datos
{
    vida = _vida;
    genero = _genero;
}

///void Pokemons_Fuego::Mostrar_pokemon()
void Pokemons_Fuego::Saludo()
{
    Pokemon::Saludo();
    cout<<"El pokemon tiene "<<vida<<" puntos de vida y su genero es: "<<genero;
}

int main()
{
    /*
    printf("Hola Mundo C\n");

    std::cout << "Hola mundo C++";*/ /// sin el "using namespace std;"

    /*Pokemon poke1 = Pokemon("Treecko", 5.15); ///Nombre de la clase (tipo de dato) y nombre del objeto (varaiable)

    poke1.Saludo();

    ///Otra forma de crear un objeto
    Pokemon poke2("Torchic",3.12);
    poke2.Saludo();
    */

    Pokemons_Fuego poke3("Mudkip", 7.6, 24, 'M');

    ///poke3.Mostrar_pokemon();
    poke3.Saludo();


    return 0;
}
