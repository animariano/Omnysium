///Eventos.cpp
#include "eventos.h"
#include "funciones.h"
#include "rlutil.h"
#include "dados.h"
#include <iostream>
using namespace std;

// Efectos de los eventos


void trampa(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado) {
    cout << "Te has encontrado con una trampa!" << endl;
    cout << "Lanza el dado para intentar esquivarla. Necesitas sacar un 3 o menos." << endl;

    rlutil::anykey();
    lanzarDadoConAnimacion(5, 8);
    int resultado = lanzarDado(5, 8);
    cout << "Resultado del dado: " << resultado << endl;

    if (resultado <= 3) {
        cout << "Esquivas la trampa con exito!" << endl;
        rlutil::anykey();
    } else {
        int dano = 2;
        saludHeroe -= dano;
        rlutil::setColor(rlutil::RED);
        cout << "No lograste esquivar la trampa. Pierdes " << dano << " de salud." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();

        if (saludHeroe <= 0) {
            cout << "Tu salud ha caido a 0. ¡Es el fin de tu aventura!" << endl;
            mostrarDerrota();
            return;
        }
    }
    system("cls");
    }


void equipoEncontrado(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado) {
    cout << "Encontraste un equipo abandonado! Ganas +1 de ataque." << endl;
    ataqueHeroe += 1;
    rlutil::anykey();
}

void oroEncontrado(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado) {
    cout << "Descubriste un cofre escondido lleno de oro!" << endl;
    oroAcumulado += 5;
    rlutil::anykey();
}

void fuenteSalud(int& saludHeroe, int&ataqueHeroe, int& OroAcumulado){
    cout << "Descubriste una con poderes curativos! Duplicas tu salud!" << endl;
    saludHeroe += saludHeroe;
    rlutil::anykey();
}

void cuevaMisteriosa(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado) {
    cout << "Has entrado a una cueva misteriosa. Dentro de ella, encuentras tres caminos que conducen a diferentes destinos." << endl;
    cout << "Elige sabiamente:" << endl;
    cout << "1- Un sendero oscuro, lleno de ecos siniestros." << endl;
    cout << "2- Un pasillo iluminado por una luz dorada." << endl;
    cout << "3- Un tunel cubierto de raices y vegetacion." << endl;

    int eleccion;
    cin>>eleccion;
    switch (eleccion) {
        case 1:{
            cout << "El sendero oscuro te lleva a una trampa. Una roca cae desde el techo!" << endl;
            cout << "Intentas esquivarla..." << endl;
            rlutil::anykey();
            lanzarDadoConAnimacion(5, 8);
            int resultado = lanzarDado(5, 8);
            if (resultado<= 3) {
                cout << "Esquivaste la roca justo a tiempo! Sales ileso." << endl;
            } else {
                int dano = 5;
                saludHeroe -= dano;
                rlutil::setColor(rlutil::RED);
                cout << " La roca te golpea! Pierdes " << dano << " de salud." << endl;
                rlutil::setColor(rlutil::WHITE);

                if (saludHeroe <= 0) {
                    cout << "Tu salud ha caído a 0. Es el fin de tu aventura." << endl;
                    mostrarDerrota();
                    return;
                }
            }
                cout << "En el fondo del sendero, encuentras un cuchillo en el suelo..."<<endl;
                cout << "1- Tomarlo."<<endl;
                cout << "2- Dejarlo."<<endl;
                int eleccion2;
                cin>>eleccion2;
                if(eleccion2==1){
                    saludHeroe += 2;
                    ataqueHeroe += 2;
                    cout << "Lo tomas y te sientes rejuvenecido y mas fuerte, aunque con una extrana sensacion..."<<endl;
                    cout << "Tu salud y ataque se ve incrementado."<<endl;
                }
                else {
                    cout << "Te marchas..."<<endl;
                }
            break;
            }
        case 2:{
            cout << "Sigues la luz dorada y encuentras un cofre lleno de oro." << endl;
            int oroEncontrado = 10;
            oroAcumulado += oroEncontrado;
            cout << "Ganas " << oroEncontrado << " de oro. Tu oro acumulado es ahora: " << oroAcumulado << endl;
            break;
            }
        case 3:{
            cout << "El tunel lleno de vegetacion te conduce a una planta curativa." << endl;
            int curacion = 4;
            saludHeroe += curacion;
            cout << "Usas la planta para curarte. Recuperas " << curacion << " de salud. Tu salud actual es: " << saludHeroe << endl;
            break;
            }
    }

    system("pause");
    system("cls");
}

// Definición de la lista de eventos
Evento eventos[] = {
    {"Trampa Oculta", "Una trampa escondida que podria dañarte.", trampa},
    {"Equipo Abandonado", "Encuentras equipo que mejora tu ataque.", equipoEncontrado},
    {"Cofre del Tesoro", "Un cofre escondido lleno de oro.", oroEncontrado},
    {"Fuente de Salud" , "Una fuente curativa.", fuenteSalud},
    {"Cueva Misteriosa", "Tres caminos con diferentes destinos.", cuevaMisteriosa}
};

const int CANTIDAD_EVENTOS = sizeof(eventos) / sizeof(eventos[0]);
