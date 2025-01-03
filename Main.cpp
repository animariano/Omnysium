///main menu:

#include<iostream>
#include <ctime>
#include "funciones.h"
#include "jugar.h"
#include "rlutil.h"

using namespace std;

int main()
{
    int opcion;
    srand(time(0));
    string nombre;

    do{
        rlutil::cls();
        cout << "     BIENVENIDO A OMNYSIUM!" << endl<<endl;
        cout << "   |\\                     /)" << endl;
        cout << "  /\\_\\\\__               (_//" << endl;
        cout << " |   `>\\-`     _._       //`)" << endl;
        cout << "  \\ /` \\\\  _.-`:::`-._  //" << endl;
        cout << "   `    \\|`    :::    `|/" << endl;
        cout << "         |     :::     |" << endl;
        cout << "         |.....:::.....|" << endl;
        cout << "         |:::::::::::::|" << endl;
        cout << "         |     :::     |" << endl;
        cout << "         \\     :::     /" << endl;
        cout << "          \\    :::    /" << endl;
        cout << "           `-. ::: .-'" << endl;
        cout << "            //`:::`\\\\" << endl;
        cout << "           //   '   \\\\" << endl;
        cout << "          |/         \\\\" << endl;
        cout << "------------------------------" << endl;
        cout << "1- Jugar" << endl;
        cout << "------------------------------" << endl;
        cout << "0- Salir" << endl;
        cout<<endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;


        switch(opcion)
        {
        case 1:
            system("cls");
            jugar();
            break;
        case 0:
            cout << "Fin del programa. Gracias por jugar" << endl;
            break;
        default:
            cout << "El numero ingresado no realiza ninguna operacion. Por favor, vuelva a ingresar un numero."<< endl;
            rlutil::anykey();
        }


    }while(opcion != 0);
    return 0;
}
