#include <iostream>
#include <cctype>
#include "Menu.h"
#include "../classes/Reproductor.h"
#include "../data_structures//ListaEnlazada.h"

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
    cout << "===Bienvenido al Menu Playlist\n";
    ListaEnlazada<Cancion> lista = reproductor.getLista();
    char opcion;
    int pos;

    cout << "Actual: ";
    reproductor.mostrarActual();
    /*Actual: canción actual - artista*/
    cout  << "Lista de Reproduccion Actual: \n";
    if (lista.tamano() != 0)
    {
        for (int i = 0; i < lista.tamano(); i++)
        {
            Cancion song = lista.obtener(i);

            cout << song.getNombre() << " - " << song.getArtista()<<endl;
        }
    }else
    {
        cout <<"Lista de Reproducción actual: \n";
        cout << "Vacía \n";
        cout << "\n=Opciones=:\n";
        cout << "V: Volver\n";
        cout << "Elija una opcion: ";
        cin >> opcion;
        opcion = toupper(opcion);
    }
    cout << "\n=Opciones=\n";
    cout << "S<num>: Saltar a la cancion\n";
    cout << "V: Volver\n";
    cout << "Elija una opcion: ";

    cin >> opcion;
    opcion = toupper(opcion);

    if (opcion == 'V') {return;}
    if (opcion == 'S')
    {
        cin >> pos;

        if (pos >= 1 && pos <= lista.tamano())
        {
            reproductor.moverseHaciaCancion(pos-1);
        }else{ cout << "Posicion inválida\n";}
    }else{cout << "Opción inválida \n";}
}

void menuCanciones(Reproductor& reproductor) {
    cout << "Menú canciones no implementado aún\n";
}