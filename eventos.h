#ifndef EVENTOS_H_INCLUDED
#define EVENTOS_H_INCLUDED

#include <string>
using namespace std;

struct Evento {
    std::string nombre;
    std::string descripcion;
    void (*efecto)(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado);
};

// Declaraciones de las funciones de efectos
void trampa(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado);
void equipoEncontrado(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado);
void oroEncontrado(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado);
void fuenteSalud(int& saludHeroe, int&ataqueHeroe, int& OroAcumulado);

// Declaraci�n de la lista de eventos
extern Evento eventos[];
extern const int CANTIDAD_EVENTOS; // Declaraci�n del tama�o de la lista

#endif
