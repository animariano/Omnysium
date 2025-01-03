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
        {"Dragon", 10, 5}
    };
    int numeroEnemigos = sizeof(enemigos) / sizeof(enemigos[0]);

    /**     definido directamente en el eventos.h, pero lo dejo aca para ir viendo...
    Evento eventos[] =
    {
        {"Trampa Oculta", "Una trampa escondida que podría dañarte.", trampa},
        {"Equipo Abandonado", "Encuentras equipo que mejora tu ataque.", equipoEncontrado},
        {"Cofre del Tesoro", "Un cofre escondido lleno de oro.", oroEncontrado},
        {"Fuente de Salud" , "Una fuente curativa.", fuenteSalud}
    };
    */

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
    rlutil::anykey();
    system("cls");


    for (int i = 0; i < numeroEnemigos; i++)
    {
       bool victoria = combatir(heroe.nombre, heroe.salud, heroe.ataque, heroe.oro, enemigos[i], heroe.nombre);

       if (!victoria)
        {
            return;
        }

        if (i < numeroEnemigos - 1)
        {
            seleccionarRecompensa(heroe.salud, heroe.ataque, heroe.oro);

            ejecutarEventoAleatorio(heroe.salud, heroe.ataque, heroe.oro);
        }
    }
    mostrarVictoria(nombre);
}

