///jugar.cpp:

#include <iostream>
#include "funciones.h"
#include "jugar.h"
#include "eventos.h"
#include <cstdlib>
#include <ctime>
#include "rlutil.h"

using namespace std;


// Función principal del juego
void jugar()
{
    //string nombre = "probando";
    string nombre;
    cout<<"Ingrese su nombre"<<endl;
    cin>>nombre;
    system("cls");

    // Lista de enemigos
    Enemigo enemigos[] =
    {
        {"Goblin", 4, 2},
        {"Pirata", 5, 2},
        {"Orco", 6, 3},
        {"Ladron", 8, 5},
        {"Vampiro", 15, 5},
        {"Elfo Oscuro", 15, 5},
        {"Hombre Lobo", 17, 6},
        {"Lider Cultista", 20, 7},
        {"Demonio", 25, 8},
        {"Dragon", 30, 10}

    };
    int numeroEnemigos = sizeof(enemigos) / sizeof(enemigos[0]);

    Heroe heroe = seleccionarPersonaje();
    system("cls");
    cout << "Has elegido jugar como " << heroe.nombre << "!" << endl;
    if (heroe.nombre == "Mago"){
    dibujarMago();
    }
    if (heroe.nombre=="Paladin"){
    dibujarPaladin();
    }
    cout << "Salud: " << heroe.salud << ", Ataque: " << heroe.ataque << endl;
    cout << "Habilidad especial: " << heroe.habilidadEspecial<<endl;
    cout << "Habilidad Definitiva: "<<heroe.habilidadDefinitiva<<endl;
    rlutil::anykey();
    system("cls");


    for (int i = 0; i < numeroEnemigos; i++)
    {
       bool victoria = combatir(heroe.nombre, heroe.salud, heroe.ataque, heroe.oro, enemigos[i], heroe.nombre, heroe.habilidadEspecial, heroe.habilidadDefinitiva);

       if (!victoria)
        {
            return;
        }

        if (i < numeroEnemigos - 1)
        {
            seleccionarRecompensa(heroe.salud, heroe.ataque, heroe.oro);

            ejecutarEventoAleatorio(heroe.salud, heroe.ataque, heroe.oro);

            MostrarMercadoCada(heroe.salud, heroe.ataque, heroe.oro);
        }
    }
    mostrarVictoria(nombre);
}

