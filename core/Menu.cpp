#include <iostream>
#include <cctype>
#include <limits>
#include <string>

#include "Menu.h"
#include "../classes/Reproductor.h"
#include "../data_structures//ListaEnlazada.h"
#include "../classes/GestorArchivos.h"

using namespace std;

char leerChar()
{
    string input;
    getline(cin, input);

    if(input.empty())
        return '\0';

    return toupper(input[0]);
}

string leerLinea()
{
    string input;
    getline(cin, input);
    return input;
}

pair<char, int> leerComando()
{
    string input;
    getline(cin, input);

    if(input.empty())
        return {'\0', -1};

    char op = toupper(input[0]);

    int num = -1;

    if(input.size() > 1)
    {
        try {
            num = stoi(input.substr(1));
        }
        catch(...)
        {
            num = -1;
        }
    }

    return {op, num};
}

void menuInicial(Reproductor& reproductor)
{

    GestorArchivos gestor;


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
             << "Buscar canciones (F)\n"
             << "TOP 10 Artistas y Canciones (T)\n"
             << "Salir (X)\n"
        <<"Elija una opcion: ";


        opcion = leerChar();
        if (opcion == '\0') continue;

        switch (opcion)
        {
        case 'W':
            reproductor.playPause();
            reproductor.mostrarActual();
            gestor.guardarEstado(reproductor);
            cout << "\n";
            break;

        case 'Q':
            reproductor.Back();
            reproductor.mostrarActual();
            gestor.guardarEstado(reproductor);
            cout << "\n";
            break;

        case 'E':
            reproductor.Next();
            reproductor.mostrarActual();
            gestor.guardarEstado(reproductor);
            cout << "\n";
            break;

        case 'S':
            reproductor.toggleMixRand();
            gestor.guardarEstado(reproductor);
            cout << "\n";
            break;

        case 'R':
            reproductor.ChangeRepeatMode();
            gestor.guardarEstado(reproductor);
            cout << "\n";
            break;

        case 'A':
            menuPlaylist(reproductor);
            cout << "\n";
            break;

        case 'L':
            menuCanciones(reproductor);
            cout << "\n";
            break;

        case 'F':
            menuBusqueda(reproductor);
            cout << "\n";
            break;

        case 'T':
            //pendiente
            break;

        case 'X':
            cout << "Hasta la proxima\n";
            break;

        default:
            cout << "Opción no válida\n";
        }

    } while (opcion != 'X');
}

void menuPlaylist(Reproductor& reproductor) {
    cout << "===Bienvenido al Menu Playlist===\n";
    ListaEnlazada<Cancion> playlist = reproductor.getPlaylist();
    char opcion;
    int pos;

    cout << "Cancion actual"<<endl;
    reproductor.mostrarActual();
    cout  << "Lista de Reproduccion Actual: \n";
    if (playlist.tamano() != 0)
    {
        for (int i = 0; i < playlist.tamano(); i++)
        {
            Cancion song = playlist.obtener(i);

            cout << i + 1 << ". " << song.getNombre() << " - " << song.getArtista()<<endl;
        }
    }else
    {
        cout <<"Lista de Reproducción actual: \n";
        cout << "Vacía \n";
        cout << "\n=Opciones=:\n";
        cout << "V: Volver\n";
        cout << "Elija una opcion: ";
    }
    cout << "\n=Opciones=\n";
    cout << "S<num>: Saltar a la cancion\n";
    cout << "V: Volver al menu principal\n";
    cout << "Elija una opcion: ";

    opcion = leerChar();

    if (opcion == 'V') {return;}
    if (opcion == 'S')
    {
        int pos;
        try
        {
            pos = stoi(leerLinea());
        } catch (...)
        {
            cout << "Numero invalido\n";
            return;
        }

        if (pos >= 1 && pos <= playlist.tamano())
        {
            reproductor.moverseHaciaCancion(pos-1);
        }else{ cout << "Posicion inválida\n";}
    }else{cout << "Opción inválida \n";}
}

void menuCanciones(Reproductor& reproductor)
{
    while (true)
    {
        cout << "===Bienvenido al Menu de Canciones===\n";

        ListaEnlazada<Cancion> lista = reproductor.getLista();

        cout << "Cancion actual\n";
        reproductor.mostrarActual();

        cout << "Canciones registradas:\n";

        for (int i = 0; i < lista.tamano(); i++)
        {
            Cancion song = lista.obtener(i);
            cout << i + 1 << ". " << song.getNombre()
                 << " - " << song.getArtista() << endl;
        }

        cout << "\n=Opciones=\n";
        cout << "R<num>: Reproducir\n";
        cout << "A<num>: Agregar\n";
        cout << "D<num>: Eliminar\n";
        cout << "N: Agregar canción\n";
        cout << "V: Volver\n";
        cout << "Elija una opcion: ";

        string input = leerLinea();

        if (input.empty()) continue;

        char op = toupper(input[0]);

        if (op == 'V') return;

        if (op == 'N')
        {
            cout << "Agregar canción (pendiente)\n";
            continue;
        }

        if (input.size() < 2)
        {
            cout << "Formato inválido\n";
            continue;
        }

        int pos;
        try {
            pos = stoi(input.substr(1));
        } catch (...) {
            cout << "Número inválido\n";
            continue;
        }

        if (pos < 1 || pos > lista.tamano())
        {
            cout << "Posición inválida\n";
            continue;
        }

        int idx = pos - 1;

        switch (op)
        {
        case 'R':
            reproductor.playSong(idx);
            break;

        case 'A':
            reproductor.agregarSong(idx);
            break;

        case 'D':
            cout << "Eliminar (pendiente)\n";
            break;

        default:
            cout << "Opción inválida\n";
            break;
        }
    }
}

void menuBusqueda(Reproductor& reproductor)
{
    bool seguir = true;
    while(seguir)
    {
        cout << "\n===== BUSQUEDA =====\n";
        cout << "Buscar: ";

        string texto = leerLinea();

        if (texto.empty())
        {
            cout << "Búsqueda vacía\n";
            continue;
        }

        ListaEnlazada<int> resultados =
                reproductor.buscarCanciones(texto);

        if(resultados.tamano() == 0)
        {
            cout << "\nNo se encontraron canciones.\n";
        }
        else
        {
            cout << "\nResultados:\n\n";

            for(int i = 0; i < resultados.tamano(); i++)
            {
                Cancion c =
                    reproductor.getLista().obtener(resultados.obtener(i));

                cout
                << i + 1
                << ". "
                << c.getNombre()
                << " - "
                << c.getArtista()
                << endl;
            }
        }

        cout << "\n";
        cout << "R<num> Reproducir\n";
        cout << "A<num> Agregar\n";
        cout << "F Buscar nuevamente\n";
        cout << "V Volver\n";
        cout << "Elija una opcion: ";

        auto cmd = leerComando();

        char accion = cmd.first;
        int numero = cmd.second;

        if(accion == 'V')
            return;

        if(accion == 'F')
            continue;

        if (numero == -1)
        {
            cout << "Comando invalido\n";
            continue;
        }


        if(numero < 1 || numero > resultados.tamano())
        {
            cout << "Numero invalido\n";
            continue;
        }

        int indice = resultados.obtener(numero - 1);

        if(accion == 'R')
        {
            reproductor.playSong(indice);
            return;
        }
        else if(accion == 'A')
        {
            reproductor.agregarSong(indice);
            return;
        }
    }
}


