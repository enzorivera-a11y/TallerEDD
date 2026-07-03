#include <iostream>
#include <cctype>
#include "Menu.h"
#include "../classes/Reproductor.h"
#include "../data_structures//ListaEnlazada.h"
#include "../classes/GestorArchivos.h"

using namespace std;

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
            <<"Buscar canciones y/o artistas(F)\n"
             << "Salir (X)\n"
        <<"Elija una opcion: ";

        if (!(cin >> opcion))
        {
            cin.clear();
            cout << "Entrada inválida. \n";
            return;
        }
        opcion = toupper(opcion);

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
    const ListaEnlazada<Cancion>& playlist = reproductor.getPlaylist();
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
        if (!(cin >> opcion))
        {
            cin.clear();
            cout << "Entrada inválida. \n";
            return;
        }
        opcion = toupper(opcion);
    }
    cout << "\n=Opciones=\n";
    cout << "S<num>: Saltar a la cancion\n";
    cout << "V: Volver al menu principal\n";
    cout << "Elija una opcion: ";

    if (!(cin >> opcion))
    {
        cin.clear();
        cout << "Entrada inválida. \n";
        return;
    }
    opcion = toupper(opcion);

    if (opcion == 'V') {return;}
    if (opcion == 'S')
    {
        if (!(cin >> pos))
        {
            cin.clear();
            cout << "Entrada inválida. \n";
            return;
        }

        if (pos >= 1 && pos <= playlist.tamano())
        {
            reproductor.moverseHaciaCancion(pos-1);
            reproductor.mostrarActual();
        }else{ cout << "Posicion inválida\n";}
    }else{cout << "Opción inválida \n";}
}

void menuCanciones(Reproductor& reproductor)
{
    cout << "===Bienvenido al Menu de Canciones===\n";
    ListaEnlazada<Cancion>& lista = reproductor.getLista();
    char opcion;
    int pos;

    cout << "Cancion actual"<<endl;
    reproductor.mostrarActual();
    cout  << "Canciones registradas: \n";
    if (lista.tamano() != 0)
    {
        for (int i = 0; i < lista.tamano(); i++)
        {
            Cancion song = lista.obtener(i);

            cout << i + 1 << ". " << song.getNombre() << " - " << song.getArtista()<<endl;
        }
    }else{
        cout <<"Canciones registradas: \n";
        cout << "Vacía \n";
        cout << "\n=Opciones=:\n";
        cout << "N: Agregar cancion al registro\n";
        cout << "V: Volver\n";
        cout << "Elija una opcion: ";
        if (!(cin >> opcion))
    {
        cin.clear();
        cout << "Entrada inválida. \n";
        return;
    }
        opcion = toupper(opcion);

        if (opcion == 'V') {return;}
        if (opcion == 'N') {}


    }
    cout << "\n=Opciones=\n";
    cout << "R<num>: Reproducir cancion seleccionada\n";
    cout << "A<num>: Agregar cancion seleccionada al final de la lista\n";
    cout << "N: Agregar cancion al registro\n";
    cout << "D<num>: Eliminar cancion seleccionada\n";
    cout << "V: Volver al menu principal\n";
    cout << "Elija una opcion: ";


    if (!(cin >> opcion))
    {
        cin.clear();
        cout << "Entrada inválida. \n";
        return;
    }
    opcion = toupper(opcion);

        switch (opcion)
        {
        case 'R':
            if (!(cin >> pos))
            {
                cin.clear();
                cout << "Entrada inválida. \n";
                return;
            }
            if (pos >= 1 && pos <= lista.tamano())
            {
                reproductor.playSong(pos-1);
                reproductor.mostrarActual();
            }
            else
            {
                cout << "Posicion invalida\n";
            }
            break;
        case 'A':
            if (!(cin >> pos))
            {
                cin.clear();
                cout << "Entrada inválida. \n";
                return;
            }
            if (pos >= 1 && pos <= lista.tamano())
            {
                reproductor.agregarSong(pos-1);
            }
            else
            {
                cout << "Posicion invalida\n";
            }
            break;
        case 'N':
            {
                GestorArchivos gestor;
                string nombre;
                string artista;
                string album;
                string ubi_arch;

                int agno;
                int duracion;

                cout << "Nombre de la cancion: ";
                getline(cin >> ws, nombre);

                cout << "Artista de la cancion: ";
                getline(cin, artista);

                cout << "Album de la cancion: ";
                getline(cin, album);

                cout << "Año de lanzamiento: ";
                if (!(cin >> agno))
                {
                    cin.clear();
                    cout << "Entrada inválida.\n";
                    return;
                }

                cout << "Duración (segundos): ";
                if (!(cin >> duracion))
                {
                    cin.clear();
                    cout << "Entrada inválida.\n";
                    return;
                }

                cout << "Ruta del archivo: ";
                getline(cin >> ws, ubi_arch);

                int nuevoId;

                if (lista.tamano() == 0)
                {
                    nuevoId = 1;
                }else
                {
                    nuevoId = lista.obtener(lista.tamano() -1).getId() +1;
                }

                Cancion nueva(
                    nuevoId,
                    nombre,
                    artista,
                    album,
                    agno,
                    duracion,
                    ubi_arch);
                reproductor.agregarSongRegistro(nueva);
                gestor.agregarSongArchivo(nueva);
                cout << "Canción agregada correctamente.\n";
                gestor.guardarEstado(reproductor);

                cout << "\n";
                break;
            }
        case 'D':
            if (!(cin >> pos))
            {
                cin.clear();
                cout << "Entrada inválida. \n";
                return;
            }
            cout << "\n";
            break;
        case 'V':
            cout << "\n";
            return;
        default:
            cout << "Opcion invalida o no disponible";
        }
}


