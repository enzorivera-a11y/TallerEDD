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
            << "Menu de Rankings TOP (T)\n"
             << "Salir (X)\n"
        <<"Elija una opcion: ";

        cin >> opcion;
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
          case 'T':
            menuRanking(reproductor);
            cout << "\n";
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
        cin >> opcion;
        opcion = toupper(opcion);
    }
    cout << "\n=Opciones=\n";
    cout << "S<num>: Saltar a la cancion\n";
    cout << "V: Volver al menu principal\n";
    cout << "Elija una opcion: ";

    cin >> opcion;
    opcion = toupper(opcion);

    if (opcion == 'V') {return;}
    if (opcion == 'S')
    {
        cin >> pos;

        if (pos >= 1 && pos <= playlist.tamano())
        {
            reproductor.moverseHaciaCancion(pos-1);
        }else{ cout << "Posicion inválida\n";}
    }else{cout << "Opción inválida \n";}
}

void menuCanciones(Reproductor& reproductor)
{
    cout << "===Bienvenido al Menu de Canciones===\n";
    ListaEnlazada<Cancion> lista = reproductor.getLista();
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
        cin >> opcion;
        opcion = toupper(opcion);

        if (opcion == 'V') {return;}
        if (opcion == 'N')
        {

        }

    }
    cout << "\n=Opciones=\n";
    cout << "R<num>: Reproducir cancion seleccionada\n";
    cout << "A<num>: Agregar cancion seleccionada al final de la lista\n";
    cout << "N: Agregar cancion al registro\n";
    cout << "D<num>: Eliminar cancion seleccionada\n";
    cout << "V: Volver al menu principal\n";
    cout << "Elija una opcion: ";


    cin >> opcion;
    opcion = toupper(opcion);

        switch (opcion)
        {
        case 'R':
            cin >> pos;
            if (pos >= 1 && pos <= lista.tamano())
            {
                reproductor.playSong(pos-1);
            }
            else
            {
                cout << "Posicion invalida\n";
            }
            break;
        case 'A':
            cin >> pos;
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
            cout << "\n";
            break;
        case 'D':
            cin >> pos;
            cout << "\n";
            break;
        case 'V':
            cout << "\n";
            return;
        default:
            cout << "Opcion invalida o no disponible";
        }
}

void menuRanking(Reproductor& reproductor) {
    char opcion;
    ListaEnlazada<Cancion> listaGeneral = reproductor.getLista();
    int totalCanciones = listaGeneral.tamano();
    do {
        cout << "Ranking TOP" << endl;
        cout << "C - Top 10 canciones mas escuchadas" << endl;
        cout << "A - Top 10 artistas mas escuchados" << endl;
        cout << "V - Volver al menu principal" << endl;
        cout << "Ingrese Opcion: ";
        cin >> opcion;
        opcion = toupper(opcion);
        if (opcion == 'C') {//-----------------------
            if (totalCanciones == 0) {
                cout << "No hay canciones en el sistema" << endl;
                continue;
            }
            ArbolHeap heap(totalCanciones);
            for (int i = 0; i < totalCanciones; i++) {
                Cancion cancion = listaGeneral.obtener(i);
                
                CancionRanking ranking;
                ranking.id = cancion.getId();
                ranking.nombre = cancion.getNombre();
                ranking.artista = cancion.getArtista();
                ranking.reproducciones = reproductor.obtenerReproducciones(ranking.id);
                
                heap.insertar(ranking);
            }
            cout << "TOP 10 CANCIONES MAS ESCUCHADAS: " << endl;
            CancionRanking top[10];
            int cantidadMostrada;
            
            if (heap.obtenerTamano() < 10) {
                cantidadMostrada = heap.obtenerTamano();
            } else {
                cantidadMostrada = 10;
            }
            for (int i = 0; i < cantidadMostrada; i++) {
                top[i] = heap.extraerMaximo();
                cout << (i + 1) << ". [" << top[i].reproducciones << "] " << top[i].nombre << " - " << top[i].artista << endl;
            }
            cout << " " << endl;
            char subOpcion;
            cout << "Opciones:" << endl;
            cout << "R<num> - Reproducir cancion seleccionada del Top" << endl;
            cout << "A<num> - Agregar cancion seleccionada al final de la lista de reproduccion" << endl;
            cout << "V - Volver al submenu de Rankings" << endl;
            cout << "Seleccione una accion (Ej: R 1 o V): ";
            cin >> subOpcion;
            subOpcion = toupper(subOpcion);
            if (subOpcion == 'R') { //------
                int numeroTOP;
                cin >> numeroTOP;
                if (numeroTOP >= 1 && numeroTOP <= cantidadMostrada) {
                    string buscarID = top[numeroTOP - 1].id;
                    
                    int indiceReal = -1;
                    for (int i = 0; i < totalCanciones; i++) {
                        if (listaGeneral.obtener(i).getId() == buscarID) {
                            indiceReal = i;
                            break;
                        }
                    }
                    if (indiceReal != -1) {
                        reproductor.playSong(indiceReal);
                        cout << "Reproduciendo cancion" << endl;
                        reproductor.mostrarActual();
                    }
                } else {
                    cout << "Numero fuera de rango" << endl;
                }
            }
            else if (subOpcion == 'A') { // -----
                int numeroTOP;
                cin >> numeroTOP;
                if (numeroTOP >= 1 && numeroTOP <= cantidadMostrada) {
                    string buscarID = top[numeroTOP - 1].id;
                    int indiceReal = -1;
                    for (int i = 0; i < totalCanciones; i++) {
                        if (listaGeneral.obtener(i).getId() == buscarID) {
                            indiceReal = i;
                            break;
                        }
                    }
                    if (indiceReal != -1) {
                        reproductor.agregarSong(indiceReal);
                        cout << "Cancion añadida" << endl;
                    }
                } else {
                    cout << "Numero fuera de rango" << endl;
                }
            }
        }
        else if (opcion == 'A') {
            cout << "LOOOL" << endl;
        }
        else if (opcion != 'V') {
            cout << "Opcion no valida" << endl;
        }
    } while (opcion != 'V');
}
