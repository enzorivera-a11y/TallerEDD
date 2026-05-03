#include <iostream>
#include <cctype>
#include "Menu.h"
#include "../classes/Reproductor.h"

using namespace std;

void menuInicial(Reproductor& reproductor)
{
    char opcion;
    cout<< "\n=====Bienvenido a nuestro Reproductor=====\n"
    <<"Que deseas hacer hoy?"<<endl;

    do {
        cout
             << "Reproducir/Pausar (W)\n"
             << "Anterior (Q)\n"
             << "Siguiente (E)\n"
             << "Aleatorio (S)\n"
             << "Repeticion (R)\n"
             << "Menu de playlist (A)\n"
             << "Menu de canciones (L)\n"
             << "Salir (X)\n"
        <<"Elija una opcion: ";

        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion)
        {
        case 'W':
            reproductor.playPause();
            reproductor.mostrarActual();
            break;

        case 'Q':
            reproductor.Back();
            reproductor.mostrarActual();
            break;

        case 'E':
            reproductor.Next();
            reproductor.mostrarActual();
            break;

        case 'S':
            reproductor.toggleMixRand();
            break;

        case 'R':
            reproductor.ChangeRepeatMode();
            break;

        case 'A':
            menuPlaylist(reproductor);
            break;

        case 'L':
            menuCanciones(reproductor);
            break;

        case 'X':
            cout << "Hasta la próxima\n";
            break;

        default:
            cout << "Opción no válida\n";
        }

    } while (opcion != 'X');
}

void menuPlaylist(Reproductor& reproductor) {
    cout << "Menú playlist no implementado aún\n";
}

void menuCanciones(Reproductor& reproductor) {
    cout << "Menú canciones no implementado aún\n";
}