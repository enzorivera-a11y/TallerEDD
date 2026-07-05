#include <iostream>
#include <cctype>
#include <limits>
#include <string>

#include "Menu.h"
#include "../classes/Reproductor.h"
#include "../data_structures//ListaEnlazada.h"
#include "../classes/GestorArchivos.h"
using namespace std;
#include "../classes/ArbolHeap.h"


void menuRanking(Reproductor& reproductor) {
    char opcion;
    ListaEnlazada<Cancion> listaGeneral = reproductor.getLista();
    int totalCanciones = listaGeneral.tamano();
    do {
        cout<<" " <<endl;
        cout << "Ranking TOP" << endl;
        cout << "C - Top 10 canciones mas escuchadas" << endl;
        cout << "A - Top 10 artistas mas escuchados" << endl;
        cout << "V - Volver al menu principal" << endl;
        cout<<" " <<endl;
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
using namespace std;
                CancionRanking ranking;
                ranking.id = cancion.id;
                ranking.nombre = cancion.getNombre();
                ranking.artista = cancion.getArtista();
                ranking.reproducciones = reproductor.obtenerReproducciones(ranking.id);
                heap.insertar(ranking);
            }
            cout << "TOP 10 CANCIONES MAS ESCUCHADAS: " << endl;
            cout<<" " <<endl;
            CancionRanking top[10];
            int cantidadMostrada;
            if (heap.obtenertotal() < 10) {
                cantidadMostrada = heap.obtenertotal();
            } else {
                cantidadMostrada = 10;
            }
            for (int i = 0; i < cantidadMostrada; i++) {
                top[i] = heap.obtentermax();
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
                    int buscarID = top[numeroTOP - 1].id;
                    int indiceReal = -1;
                    for (int i = 0; i < totalCanciones; i++) {
                        if (listaGeneral.obtener(i).getID() == buscarID) {
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
                    int buscarID = top[numeroTOP - 1].id;
                    int indiceReal = -1;
                    for (int i = 0; i < totalCanciones; i++) {
                        if (listaGeneral.obtener(i).getID() == buscarID) {
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
        if (opcion == 'V'){
            char extra;
            cin.get(extra);
            }
    } while (opcion != 'V');
}

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

