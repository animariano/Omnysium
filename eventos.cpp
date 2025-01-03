///Eventos.cpp
#include "eventos.h"
#include "funciones.h"
#include "rlutil.h"
#include <iostream>
using namespace std;

// Efectos de los eventos


void trampa(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado) {
    cout << "Te has encontrado con una trampa!" << endl;
    cout << "Lanza el dado para intentar esquivarla. Necesitas sacar un 3 o menos." << endl;

    rlutil::anykey();
    int resultado = lanzarDado(6);
    cout << "Resultado del dado: " << resultado << endl;

    if (resultado <= 3) {
        cout << "Esquivas la trampa con exito!" << endl;
    } else {
        int dano = 2;
        saludHeroe -= dano;
        rlutil::setColor(rlutil::RED);
        cout << "No lograste esquivar la trampa. Pierdes " << dano << " de salud." << endl;
        rlutil::setColor(rlutil::WHITE);

        if (saludHeroe <= 0) {
            cout << "Tu salud ha caido a 0. ¡Es el fin de tu aventura!" << endl;
            mostrarDerrota();
            system("pause");
            return;
        }
    }

    system("pause");
    system("cls");

    }


void equipoEncontrado(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado) {
    cout << "Encontraste un equipo abandonado! Ganas +1 de ataque." << endl;
    ataqueHeroe += 1;
}

void oroEncontrado(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado) {
    cout << "Descubriste un cofre escondido lleno de oro!" << endl;
    oroAcumulado += 5;
}

void fuenteSalud(int& saludHeroe, int&ataqueHeroe, int& OroAcumulado){
    cout << "Descubriste una con poderes curativos! Duplicas tu salud!" << endl;
    saludHeroe += saludHeroe;
}

// Definición de la lista de eventos
Evento eventos[] = {
    {"Trampa Oculta", "Una trampa escondida que podria dañarte.", trampa},
    {"Equipo Abandonado", "Encuentras equipo que mejora tu ataque.", equipoEncontrado},
    {"Cofre del Tesoro", "Un cofre escondido lleno de oro.", oroEncontrado},
    {"Fuente de Salud" , "Una fuente curativa.", fuenteSalud}
};

const int CANTIDAD_EVENTOS = sizeof(eventos) / sizeof(eventos[0]);
