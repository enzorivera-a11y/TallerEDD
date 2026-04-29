#include <iostream>
#include <cctype>
using namespace std;
#include "Menu.h"

menu::menuInicial(Reproductor& reproductor)
{
    do
    {
        cout << "Bienvenido a nuestro Reproductor \n"
        << "Qué quieres hacer hoy? \n"
        << "Reproducir/Pausar (W) \n"
        << "Anterior (Q) \n"
        << "Siguiente (E) \n"
        << "Aleatorio (S) \n"
        << "Repetición (R) \n"
        << "Menú de playlist (A) \n"
        << "Menú de canciones (L) \n"
        << "Salir (X) \n";

        cout << "Elija una opción: " << endl;
        char opcion;
        cin >> opcion;

        opcion = toupper(opcion);

        switch (opcion)
        {
        case 'W':
        case 'Q':
        case 'E':
        case 'S':
        case 'R':

        case 'A':
        case 'L':
        case 'X':
            cout << "Hasta la próxima"<< endl;
            break;
        default:
            cout << "Opción no válida"<< endl;

        }
    } while (opcion != "X");

}





