#pragma once
#include <string>


struct Enemigo
{
    std::string nombre;
    int salud;
    int ataque;
};

struct Heroe {
    std::string nombre;
    int salud;
    int ataque;
    int oro;
    std::string habilidadEspecial; //por ahora una sola
};



Heroe seleccionarPersonaje();
Heroe crearPaladin();
Heroe crearMago();
Heroe crearBerserker();


int lanzarDado(int caras) ;
void mostrarEstado(std::string nombre,int saludHeroe, int oroAcumulado);
bool combatir(std::string& nombre, int& saludHeroe, int& ataqueHeroe, int& oroAcumulado, Enemigo enemigo, std::string habilidadEspecial);
void seleccionarRecompensa(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado);
void ejecutarEventoAleatorio(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado);
void usarHabilidadEspecial(std::string clase, int &ataqueHeroe, int &saludHeroe, int &saludEnemigo, std::string habilidadEspecial);
void mostrarVictoria(std::string nombre);
void mercado(int &saludHeroe, int &ataqueHeroe, int &oroAcumulado);
void MostrarMercadoCada(int &saludHeroe, int &ataqueHeroe, int &oroAcumulado);
void mostrarDerrota();
void dibujarMago();
void dibujarPaladin();
