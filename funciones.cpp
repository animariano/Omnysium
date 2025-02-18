///funciones.cpp:

#include<iostream>
#include "funciones.h"
#include "rlutil.h"
#include "eventos.h"
#include "dados.h"



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
    cout << "Poco ataque y salud, pero con hechizos de potenciacion poderosos. " << endl;
    rlutil::setColor(rlutil::BROWN);
    cout << "3- Berserker. ";
    rlutil::setColor(rlutil::WHITE);
    cout << "Poderosos ataques, incluso a costa de su propia salud. " << endl;


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
    else if (eleccion == 3)
    {
        return crearBerserker();
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
    return {"Paladin", 6, 3, 0, "Curar (Recupera 4 de salud)", "Golpe Sanador (Hace dano y te curas la misma cantidad)"};
}

Heroe crearMago()
{
    return {"Mago", 6, 1, 0, "Bola de Fuego (Hace la mitad de tu dano directo)", "Escudo de Fuego (Devuelve 2 de dano cada vez que recibes un ataque)"};
}
Heroe crearBerserker()
{
    return {"Berserker", 6, 4, 0, "Cabezaso (Hace el doble de dano, pero pierdes la mitad de tu salud)", "Arremetida Suicida (Hace el triple de dano pero quedas a 1 de salud)"};
}

void dubujarCuadrado(int posx, int posy, int tam) {
	for (int y = 1; y <= tam / 2; y++) {
		for (int x = 1; x <= tam; x++) {
			rlutil::locate(x + posx, y + posy);
			cout << (char)219;
		}
	}
}

// Las siguientes 3 funciones pertenecen a Brian Lara. https://github.com/TheRegext/dibujar-dados-consola

void dibujarDado(int posx, int posy, int num, int tam) {
	rlutil::setColor(rlutil::WHITE);
	dubujarCuadrado(posx, posy);


	rlutil::setBackgroundColor(rlutil::WHITE);
	rlutil::setColor(rlutil::BLACK);

	switch (num)
	{
	case 1:
		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;
		break;

	case 2:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;


		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;

	case 3:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;


	case 4:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;

	case 5:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 + 1);
		cout << (char)254;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;


	case 6:
		rlutil::locate(posx + tam / 4 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 4 / 4 + 1);
		cout << (char)220;

		rlutil::locate(posx + tam / 2 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam - tam / 4, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		rlutil::locate(posx + tam / 4 + 1, posy + tam / 2 - tam / 4 / 4);
		cout << (char)223;

		break;

	default:
		break;
	}
	rlutil::setBackgroundColor(rlutil::BLACK);

	rlutil::setColor(rlutil::GREY);
	// sombra

	for (int y = posy + 2; y <= posy + tam / 2 + 1; y++) {
		rlutil::locate(posx + tam + 1, y);
		cout << (char)219;
	}


	for (int x = posx + 2; x <= posx + tam + 1; x++) {
		rlutil::locate(x, posy + tam / 2 + 1);
		cout << (char)223;
	}

	rlutil::locate(posx + tam + 1, posy + 1);
	cout << (char)220;

	rlutil::locate(2, 20);

}
// Función para lanzar un dado
int lanzarDado(int posx, int posy, int tam) {
    int resultado = rand() % 6 + 1;

    dibujarDado(posx, posy, resultado, tam);

    return resultado;
}


void lanzarDadoConAnimacion(int posx, int posy, int tam) {
    for (int i = 0; i < 10; i++) {
        int resultadoTemporal = rand() % 6 + 1;
        dibujarDado(posx, posy, resultadoTemporal, tam);
        rlutil::msleep(100); // Pausa breve para la animación
       // rlutil::cls();       // Limpia la consola antes de dibujar el siguiente dado
    }

    int resultadoFinal = lanzarDado(posx, posy, tam); // Llama a la función original para el resultado final
   // cout << "¡El resultado final del dado es: " << resultadoFinal << "!" << endl;
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
    //system("pause>null");
}


void usarHabilidadEspecial(string clase, int& ataqueHeroe, int& saludHeroe, int& saludEnemigo)
{
    if (clase == "Paladin")
    {
        saludHeroe = min(saludHeroe + 3, 12); //cantidad sanada, maximo de vida
        cout << "Usas la habilidad especial: Curacion. Tu salud ahora es " << saludHeroe << "." << endl;
    }
    else if (clase == "Mago")
    {
        int dano = ataqueHeroe/2;
        saludEnemigo -= dano;
        cout << "Lanzas una Bola de Fuego y haces " << dano << " de dano al enemigo!" << endl;
    }
    else if (clase == "Berserker")
    {
        int dano = ataqueHeroe*2;
        saludEnemigo -= dano;
        saludHeroe = saludHeroe/2;
        cout << "Tomas al enemigo y le das un fuerte cabezaso, le haces "<< dano << " y debido a la fuerza te lastimas. Pierdes la mitad de tu salud."<<endl;
    }
}

//usar habilidad definitiva (1 solo uso)
bool habilidadUsada = false;
bool escudoDeFuego = false;

void usarHabilidadDefinitiva(string clase, int &ataqueHeroe, int &saludHeroe, int &saludEnemigo)
{
    if (habilidadUsada == true)
    {
        cout << "Ya has usado tu habilidad definitiva." << endl;
        return;
    }

    if (clase == "Paladin")
    {
        int dano = ataqueHeroe;
        saludHeroe = saludHeroe+3;
        saludEnemigo -= dano;
        cout << "Usas la habilidad Definitiva: Golpe Sanador. Haces "<<dano<<" de dano al enemigo!"<<endl;
        cout << "Tu salud ahora es " << saludHeroe << "." << endl;
        habilidadUsada = true;
    }
    else if (clase == "Mago")
    {
        escudoDeFuego = true;
        cout << "Has activado el escudo de fuego. Cualquier enemigo que te ataque recibira 2 de dano." << endl;
        habilidadUsada = true;
    }
    else if (clase == "Berserker")
    {
        int dano = ataqueHeroe*3;
        saludEnemigo -= dano;
        saludHeroe = 1;
        cout << "Te abalanzas al enemigo con toda tu fuerza y le haces "<< dano << " y debido a la fuerza te lastimas. A duras penas sigues vivo..."<<endl;
        habilidadUsada = true;
    }
}


// Función para manejar el combate
bool combatir(string& nombre, int& saludHeroe, int& ataqueHeroe, int& oroAcumulado, Enemigo enemigo, string claseHeroe, string habilidadEspecial, string habilidadDefinitiva)
{
    cout << "Te topas con " << enemigo.nombre << " con " << enemigo.salud << " de salud y "
         << enemigo.ataque << " de ataque. Debes pelear!" << endl;
    rlutil::anykey();
    system("cls");

    while (saludHeroe > 0 && enemigo.salud > 0)
    {
        // Turno del héroe
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
        cout << " ||| " << enemigo.nombre << " Salud : " << enemigo.salud << " | Ataque: " << enemigo.ataque << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "1- Atacar: Hace " << ataqueHeroe << " de dano (1 a 3 para acertar)." << endl;
        cout << "2- Usar habilidad especial: " << habilidadEspecial << endl;
        if (habilidadUsada==false)
        {
            cout << "3- Usar habilidad Definitiva: " << habilidadDefinitiva<< endl;
        }

        int eleccion;
        cin >> eleccion;

        if (eleccion == 1)
        {
            if (nombre=="Mago")
            {
                cout << "Has atacado, haras dano igual a tu lanzamiento multiplicado por tu ataque..." << endl;
                rlutil::anykey();
                lanzarDadoConAnimacion(5, 8);
                int dano = lanzarDado(5, 8);
                cout << "Tu dano sera de: "<<dano*ataqueHeroe<<". Ahora debes sacar 3 o menos para lograr conectar a tu enemigo."<< endl;
                rlutil::anykey();
                lanzarDadoConAnimacion(5, 8);
                int resultado = lanzarDado(5, 8);
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

            if (nombre=="Paladin" || nombre=="Berserker" )
            {

                cout << "Has atacado, debes hacer un lanzamiento 3 o menos para acertar..." << endl;
                rlutil::anykey();
                lanzarDadoConAnimacion(5, 8);
                int resultado = lanzarDado(5, 8);
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
        else if (eleccion == 3)
        {
            usarHabilidadDefinitiva(claseHeroe, ataqueHeroe, saludHeroe, enemigo.salud);
        }
        else
        {
            cout << "Opcion no valida, atacas normalmente." << endl;
            enemigo.salud -= ataqueHeroe;
        }

        rlutil::anykey();
        system("cls");

        // Turno del enemigo (si sigue vivo)

        if (enemigo.salud > 0)
        {
            cout << "Turno del enemigo!" << endl;
           // lanzarDadoConAnimacion(5, 8);
            int resultado = lanzarDado(5, 8);
          //  int accionEnemigo = lanzarDado(6);
           // accionEnemigo = lanzarDado(6);
           int accionEnemigo = resultado;
            if (accionEnemigo==6)
            {

                if(enemigo.nombre == "Pirata" || enemigo.nombre == "Ladron"){
                    cout << "El "<< enemigo.nombre << " te engana y en vez de atacarte te roba tu oro!" << endl;
                    oroAcumulado = 0;
                    cout << "Tu oro ha desaparecido!" <<endl;
                    rlutil::anykey();
                    system("cls");
                }

                if(enemigo.nombre == "Goblin" || enemigo.nombre == "Orco" || enemigo.nombre == "Hombre Lobo" || enemigo.nombre == "Elfo Oscuro"){
                    cout << "El "<<enemigo.nombre<<" te ataca con un golpe critico! Debes hacer un lanzamiento de 3 o menos para esquivar!" << endl;
                    rlutil::anykey();
                    lanzarDadoConAnimacion(5, 8);
                    int resultado = lanzarDado(5, 8);
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
               // lanzarDadoConAnimacion(5, 8);
                int resultado = lanzarDado(5, 8);
                cout << "Te ataca, debes hacer un lanzamiento de 3 o menos para esquivar..." << endl;
                rlutil::anykey();
                lanzarDadoConAnimacion(5, 8);
                resultado = lanzarDado(5, 8);
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
                    if (escudoDeFuego==true)
                    {
                        cout << "Tu escudo de fuego lastima al enemigo y le hace 2 de dano. " << endl;
                        enemigo.salud-=2;
                    }

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

void mercado(int &saludHeroe, int &ataqueHeroe, int &oroAcumulado)
{
    cout << "Bienvenido al mercado! Deseas adquirir algun objeto para continuar tu viaje?" << endl;
    cout << "Oro disponible: ";
    rlutil::setColor(rlutil::YELLOW);
    cout << oroAcumulado;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << "Objetos disponibles:" << endl;
    cout << "1- Comprar pocion de salud (+2 salud) por 3 de oro." << endl;
    cout << "2- Comprar espada de hierro (+1 ataque) por 5 de oro." << endl;
    cout << "3- Comprar armadura de cuero (+3 salud) por 5 de oro." << endl;
    cout << "4- Comprar espada de acero (+2 ataque) por 8 de oro." << endl;
    cout << "5- Comprar armadura de placas (+4 salud) por 8 de oro." << endl;
    cout << "6- Salir." << endl;
    cout << endl;
    int eleccion;
    cin >> eleccion;
    switch (eleccion)
    {
    case 1:
        if (oroAcumulado >= 3)
        {
            saludHeroe += 2;
            oroAcumulado -= 3;
            cout << "Has comprado una pocion de salud. Tu salud ahora es " << saludHeroe << "." << endl;
        }
        else
        {
            cout << "No tienes suficiente oro para comprar la pocion." << endl;
        }
        break;
    case 2:
        if (oroAcumulado >= 5)
        {
            ataqueHeroe += 1;
            oroAcumulado -= 5;
            cout << "Has comprado una espada de hierro. Tu ataque ahora es " << ataqueHeroe << "." << endl;
        }
        else
        {
            cout << "No tienes suficiente oro para comprar la espada." << endl;
        }
        break;
    case 3:
        if (oroAcumulado >= 5)
        {
            saludHeroe += 3;
            oroAcumulado -= 5;
            cout << "Has comprado una armadura de cuero. Tu salud ahora es " << saludHeroe << "." << endl;
        }
        else
        {
            cout << "No tienes suficiente oro para comprar la armadura." << endl;
        }
        break;
    case 4:
        if (oroAcumulado >= 8)
        {
            ataqueHeroe += 2;
            oroAcumulado -= 8;
            cout << "Has comprado una espada de acero. Tu ataque ahora es " << ataqueHeroe << "." << endl;
        }
        else
        {
            cout << "No tienes suficiente oro para comprar la espada." << endl;
        }
        break;
    case 5:
        if (oroAcumulado >= 8)
        {
            saludHeroe += 4;
            oroAcumulado -= 8;
            cout << "Has comprado una armadura de placas. Tu salud ahora es " << saludHeroe << "." << endl;
        }
        else
        {
            cout << "No tienes suficiente oro para comprar la armadura." << endl;
        }
        break;
    case 6:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
    system("pause");
    system("cls");
}

//hace que el mercado salga cada x combates
void MostrarMercadoCada(int &saludHeroe, int &ataqueHeroe, int &oroAcumulado)
{
    static int contador = 0;
    contador++;
    if (contador % 2 == 0)
    {
        mercado(saludHeroe, ataqueHeroe, oroAcumulado);
    }
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



