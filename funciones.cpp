///funciones.cpp:

#include<iostream>
#include "funciones.h"
#include "rlutil.h"
#include "eventos.h"


using namespace std;

Heroe seleccionarPersonaje()
{
    cout << "Selecciona tu personaje:" << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "1- Paladin. ";
    rlutil::setColor(rlutil::WHITE);
    cout << "Un guerrero con ataque y salud equilibrados y la habilidad de curar." << endl;
    rlutil::setColor(rlutil::RED);
    cout << "2- Mago. ";
    rlutil::setColor(rlutil::WHITE);
    cout << "Poco ataque y salud, pero con hechizos de potenciacion poderosos(en Desarrollo)." << endl;

    int eleccion;
    cin >> eleccion;

    if (eleccion == 1)
    {
        return crearPaladin();
        cout<< endl;
    }
    else if (eleccion == 2)
    {
        return crearMago();
        cout<< endl;
    }
    else
    {
        cout << "Opcion no valida. Seleccionando Paladin por defecto." << endl;
        return crearPaladin();
    }
}


Heroe crearPaladin()
{
    return {"Paladin", 6, 3, 0, "Curar. "};
}

Heroe crearMago()
{
    return {"Mago", 6, 1, 0, "Bola de Fuego. "};
}

// Funci�n para lanzar un dado
int lanzarDado(int caras)
{
    return rand() % caras + 1;
}

// Funcion para mostrar el estado actual del heroe.
void mostrarEstado(string nombre,int saludHeroe, int oroAcumulado)
{
    system("cls");
    cout << "\t" << "--------------------------\n";
    cout << "\t" << "JUGADOR:  " << nombre << endl;
    cout << "\t" << "SALUD ACTUAL: " << saludHeroe << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "\t" << "ORO ACUMULADO: " << oroAcumulado << " PUNTOS" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "\t" << "--------------------------\n";
    system("pause>null");
}


void usarHabilidadEspecial(string clase, int& ataqueHeroe, int& saludHeroe, int& saludEnemigo)
{
    if (clase == "Paladin")
    {
        saludHeroe = min(saludHeroe + 3, 12); //no excede el m�ximo
        cout << "Usas la habilidad especial: Curacion. Tu salud ahora es " << saludHeroe << "." << endl;
    }
    else if (clase == "Mago")
    {
        int dano = ataqueHeroe + 3; // Bola de fuego hace 3 m�s de dano
        saludEnemigo -= dano;
        cout << "Lanzas una Bola de Fuego y haces " << dano << " de dano al enemigo!" << endl;
    }
}


// Funci�n para manejar el combate
bool combatir(string& nombre, int& saludHeroe, int& ataqueHeroe, int& oroAcumulado, Enemigo enemigo, string claseHeroe)
{
    cout << "Te topas con " << enemigo.nombre << " con " << enemigo.salud << " de salud y "
         << enemigo.ataque << " de ataque. Debes pelear!" << endl;
    rlutil::anykey();
    system("cls");

    while (saludHeroe > 0 && enemigo.salud > 0)
    {
        // Turno del h�roe
        cout << "Es tu turno, " << nombre << " | Tu Salud: ";
        if (saludHeroe < 6)
        {
            rlutil::setColor(rlutil::RED);
            cout << saludHeroe;
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREEN);
            cout << saludHeroe;
            rlutil::setColor(rlutil::WHITE);
        }
        cout << " | Salud " << enemigo.nombre << ": " << enemigo.salud << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "1- Atacar: Hace " << ataqueHeroe << " de dano (1 a 3 para acertar)." << endl;
        cout << "2- Usar habilidad especial." << endl;

        int eleccion;
        cin >> eleccion;

        if (eleccion == 1)
        {
            if (nombre=="Mago")
            {
                cout << "Has atacado, haras dano igual a tu lanzamiento multiplicado por tu ataque..." << endl;
                rlutil::anykey();
                int  dano = lanzarDado(6);
                cout << "Tu dano sera de: "<<dano*ataqueHeroe<<". Ahora debes sacar 3 o menos para lograr conectar a tu enemigo."<< endl;
                rlutil::anykey();
                int resultado=lanzarDado(6);
                cout << "Resultado del dado: " << resultado << endl;
                if (resultado <= 3)
                {
                    cout << "Ataque exitoso! Hiciste " << ataqueHeroe*dano << " de dano." << endl;
                    enemigo.salud -= ataqueHeroe*dano;
                }
                else
                {
                    cout << "Ataque fallido!" << endl;
                }
            }

            if (nombre=="Paladin")
            {

                cout << "Has atacado, debes hacer un lanzamiento 3 o menos para acertar..." << endl;
                rlutil::anykey();
                int  resultado = lanzarDado(6);
                cout << "Resultado del dado: " << resultado << endl;
                if (resultado <= 3)
                {
                    cout << "Ataque exitoso! Hiciste " << ataqueHeroe << " de dano." << endl;
                    enemigo.salud -= ataqueHeroe;
                }
                else
                {
                    cout << "Ataque fallido!" << endl;
                }
            }

        }
        else if (eleccion == 2)
        {
            usarHabilidadEspecial(claseHeroe, ataqueHeroe, saludHeroe, enemigo.salud);
        }
        else
        {
            cout << "Opcion no valida, atacas normalmente." << endl;
            enemigo.salud -= ataqueHeroe;
        }

        system("pause");
        system("cls");

        // Turno del enemigo (si sigue vivo)
        if (enemigo.salud > 0)
        {
            cout << "Turno del enemigo!" << endl;
            int accionEnemigo = lanzarDado(6);
            accionEnemigo = lanzarDado(6);
            if (accionEnemigo==6)
            {
                if(enemigo.nombre == "Goblin")
                {
                    cout << "Te ataca con un golpe critico! Debes hacer un lanzamiento de 3 o menos para esquivar!" << endl;
                    rlutil::anykey();
                    int resultado = lanzarDado(6);
                    cout << "Resultado del dado: " << resultado << endl;

                    if (resultado <= 3)
                    {
                        cout << "Esquive exitoso! " << endl;
                    }
                    else
                    {
                        rlutil::setColor(rlutil::RED);
                        cout << "No pudiste evadir su ataque y te hizo " << enemigo.ataque*2 << " de dano." << endl;
                        saludHeroe -= (enemigo.ataque*2);
                        rlutil::setColor(rlutil::WHITE);
                    }
                    rlutil::anykey();
                    system("cls");
                }
                if(enemigo.nombre == "Pirata"){
                    cout << "El pirata te engana y en vez de atacarte te roba tu oro!" << endl;
                    oroAcumulado = 0;
                    cout << "Tu oro ha desaparecido!" <<endl;
                    rlutil::anykey();
                    system("cls");
                }

                if(enemigo.nombre == "Orco"){
                    cout << "Te ataca con un golpe critico! Debes hacer un lanzamiento de 3 o menos para esquivar!" << endl;
                    rlutil::anykey();
                    int resultado = lanzarDado(6);
                    cout << "Resultado del dado: " << resultado << endl;

                    if (resultado <= 3)
                    {
                        cout << "Esquive exitoso! " << endl;
                    }
                    else
                    {
                        rlutil::setColor(rlutil::RED);
                        cout << "No pudiste evadir su ataque y te hizo " << enemigo.ataque*2 << " de dano." << endl;
                        saludHeroe -= (enemigo.ataque*2);
                        rlutil::setColor(rlutil::WHITE);
                    }
                    rlutil::anykey();
                    system("cls");
                }

            }

            else
            {
                int resultado = lanzarDado(6);
                cout << "Te ataca, debes hacer un lanzamiento de 3 o menos para esquivar..." << endl;
                rlutil::anykey();
                resultado = lanzarDado(6);
                cout << "Resultado del dado: " << resultado << endl;

                if (resultado <= 3)
                {
                    cout << "Esquive exitoso! " << endl;
                }
                else
                {
                    rlutil::setColor(rlutil::RED);
                    cout << "No pudiste evadir su ataque y te hizo " << enemigo.ataque << " de dano." << endl;
                    saludHeroe -= enemigo.ataque;
                    rlutil::setColor(rlutil::WHITE);
                }
                rlutil::anykey();
                system("cls");
            }
        }
    }

    // Resultado del combate
    if (saludHeroe > 0)
    {
        oroAcumulado += 3;
        cout << "Derrotaste a " << enemigo.nombre << "! Ganaste 3 de oro." << endl;
        mostrarEstado(nombre, saludHeroe, oroAcumulado);
        return true;
    }
    else
    {

        cout << "Fuiste derrotado por " << enemigo.nombre << ". Mejor suerte la proxima..." << endl;
        mostrarDerrota();

        return false;
    }
}


void ejecutarEventoAleatorio(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado)
{
    int indice = rand() % CANTIDAD_EVENTOS; // Selecciona un evento aleatorio
    Evento eventoSeleccionado = eventos[indice];

    cout << "Evento encontrado: " << eventoSeleccionado.nombre << endl;

    eventoSeleccionado.efecto(saludHeroe, ataqueHeroe, oroAcumulado);

    system("pause");
    system("cls");
}


void seleccionarRecompensa(int& saludHeroe, int& ataqueHeroe, int& oroAcumulado)
{
    rlutil::setColor(rlutil::YELLOW);
    cout << "       __________" << endl;
    cout << "        /\\____;;___\\" << endl;
    cout << "       | /         /" << endl;
    cout << "       `. ())oo() ." << endl;
    cout << "        |\\(%()*^^()^\\" << endl;
    cout << "       %| |-%-------|" << endl;
    cout << "      % \\ | %  ))   |" << endl;
    cout << "      %  \\|%________|" << endl;
    cout << "      %%%%" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<endl;
    cout << "Elige tu recompensa:" << endl;
    cout << "1- Incrementar ataque (+1)." << endl;
    cout << "2- Incrementar salud (+2)" << endl;
    cout << endl;
    int eleccion;
    cin >> eleccion;

    if (eleccion == 1)
    {
        ataqueHeroe += 1;
        cout << "Tu ataque ha incrementado a " << ataqueHeroe << "." << endl;
    }
    else if (eleccion == 2)
    {
        saludHeroe += 2;
        cout << "Tu salud ha incrementado a " << saludHeroe << "." << endl;
    }

    system("pause");
    system("cls");
}


void mostrarVictoria(string nombre)
{
    system("cls");
    cout << "Felicidades " << nombre << "! Derrotaste a todos los enemigos y completaste el juego!" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << "                        |>>>" << endl;
    cout << "                                  |" << endl;
    cout << "                    |>>>      _  _|_  _         |>>>" << endl;
    cout << "                    |        |;| |;| |;|        |" << endl;
    cout << "                _  _|_  _    \\\\.    .  /    _  _|_  _" << endl;
    cout << "               |;|_|;|_|;|    \\\\:. ,  /    |;|_|;|_|;|" << endl;
    cout << "               \\\\..      /    ||;   . |    \\\\.    .  /" << endl;
    cout << "                \\\\.  ,  /     ||:  .  |     \\\\:  .  /" << endl;
    cout << "                 ||:   |_   _ ||_ . _ | _   _||:   |" << endl;
    cout << "                 ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |" << endl;
    cout << "                 ||:   ||.    .     .      . ||:  .|" << endl;
    cout << "                 ||: . || .     . .   .  ,   ||:   |       \\,/" << endl;
    cout << "                 ||:   ||:  ,  _______   .   ||: , |            /`\\" << endl;
    cout << "                 ||:   || .   /+++++++\\    . ||:   |" << endl;
    cout << "                 ||:   ||.    |+++++++| .    ||: . |" << endl;
    cout << "              __ ||: . ||: ,  |+++++++|.  . _||_   |" << endl;
    cout << "     ____--`~    '--~~__|.    |+++++__|----~    ~`---,              ___" << endl;
    cout << "-~--~                   ~---__|,--~'                  ~~----_____-~'   `~----~~" << endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}


void mostrarDerrota()
{

    cout << "                      Has muerto!"<<endl;
    rlutil::setColor(rlutil::RED);
    cout << "                       ______" << endl;
    cout << "                    .-\"      \"-." << endl;
    cout << "                   /            \\" << endl;
    cout << "       _          |              |          _" << endl;
    cout << "      ( \\         |,  .-.  .-.  ,|         / )" << endl;
    cout << "       > \"=._     | )(__/  \\__)( |     _.=\" <" << endl;
    cout << "      (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)" << endl;
    cout << "             \"=._ (_     ^^     _)\"_=." << endl;
    cout << "                 \"=\\__|IIIIII|__/=\"" << endl;
    cout << "                _.=\"| \\IIIIII/ |\"=._" << endl;
    cout << "      _     _.=\"_.=\"\\          /\"=._\"=._     _" << endl;
    cout << "     ( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )" << endl;
    cout << "      > _.=\"                            \"=._ <" << endl;
    cout << "     (_/                                  \\_)" << endl;
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}


void dibujarMago()
{
    rlutil::setColor(rlutil::RED);
    cout << "         /^\\     " << endl;
    cout << "    /\\   \"V\"     " << endl;
    cout << "   /__\\   I      " << endl;
    cout << "  //..\\\\  I     " << endl;
    cout << "  \\].`[/  I     " << endl;
    cout << "  /l\\/j\\  (]    " << endl;
    cout << " /. ~~ ,\\/I     " << endl;
    cout << " \\\\L__j^\\/I     " << endl;
    cout << "  \\/--v}  I     " << endl;
    cout << "  |    |  I     " << endl;
    cout << "  |    |  I     " << endl;
    cout << "  |    l  I     " << endl;
    cout << "_/j  L l\\_!" << endl;
    cout<< endl;
    rlutil::setColor(rlutil::WHITE);
}


void dibujarPaladin()
{
    rlutil::setColor(rlutil::YELLOW);
    cout << "  / \\     " << endl;
    cout << "  | |     " << endl;
    cout << "  |.|     " << endl;
    cout << "  |.|     " << endl;
    cout << "  |:|      __" << endl;
    cout << ",_|:|_,   /  )" << endl;
    cout << "  (Oo    / _I_" << endl;
    cout << "   +\\ \\  || __|" << endl;
    cout << "      \\ \\||___|" << endl;
    cout << "        \\ /.:.\\-\\" << endl;
    cout << "         |.:. /-----\\" << endl;
    cout << "         |___|::oOo::|" << endl;
    cout << "         /   |:<_T_>:|" << endl;
    cout << "        |_____\\ ::: /" << endl;
    cout << "         | |  \\ \\:/" << endl;
    cout << "         | |   | |" << endl;
    cout << "         \\ /   | \\___" << endl;
    cout << "         / |   \\_____\\" << endl;
    cout << "         `-'" << endl;
    cout << endl;
    rlutil::setColor(rlutil::WHITE);

}


