//
// Created by Enzod on 18-04-2026.
//

#include "Reproductor.h"
#include "Cancion.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void Reproductor::setLista(ListaEnlazada<Cancion> lista) {
    this->lista = lista;

    for (int i = 0; i < lista.tamano(); i++)
    {
        playlist.insertarFinal(lista.obtener(i));
    }
    actual = this->playlist.getCabeza();

    construirIndiceBusqueda();
}

Reproductor::Reproductor() {
    actual = nullptr;
    Playing =false;
    mixRand =false;
    RepeatMode= 0;

    srand(time(nullptr));
}

void Reproductor:: playPause() {
    Playing= !Playing;
}

void Reproductor:: Next() {
    if (actual == nullptr) return;

    if (RepeatMode== 1) {
        return;
    }

    if (actual->next != nullptr) {
        actual = actual->next;
    }else {

        if (RepeatMode== 2) {
            actual = playlist.getCabeza();
            if (mixRand)
            {
                mezclarRestantes();
            }
        }else {
            cout << "Fin de la lista" << endl;
        }
    }
}

void Reproductor::Back() {
    if (actual == nullptr || actual == playlist.getCabeza()) return;

    Nodo<Cancion>* temp= playlist.getCabeza();

    while (temp!= nullptr && temp->next != actual) {
        temp = temp->next;
    }

    actual=temp;
}

void Reproductor::toggleMixRand() {
    if (playlist.tamano() == 0 || actual == nullptr)
    {
        return;
    }

    mixRand = !mixRand;

    if (mixRand) {
        mezclarRestantes();
        cout << "Mix ON" << endl;
    } else {
        cout << "Mix OFF" << endl;
    }
}

void Reproductor::ChangeRepeatMode() {
    RepeatMode = (RepeatMode+1)%3;

        if (RepeatMode == 0)
        {
            cout << "Repeat Mode: OFF"<<endl;
        }
        else if (RepeatMode == 1)
        {
            cout << "Repeat Mode: ONE"<< endl;
        }
        else if (RepeatMode == 2)
        {
            cout << "Repeat Mode: ALL"<<endl;
        }


}

void Reproductor::agregarSong(int index)
{
if (index < 0 || index >= lista.tamano())
{
    cout << "Cancion invalida \n";
    return;
}
    Cancion elegida = lista.obtener(index);
    playlist.insertarFinal(elegida);

    if (actual == nullptr)
    {
        actual = playlist.getCabeza();

    }
    cout << "Cancion añadida al final de la playlist\n";
}

void Reproductor::mostrarActual() {
    if (actual == nullptr) {
        cout << "No hay canciones. Deteniendo reproducción"<< endl;
        return;
    }
    string estado = getState();

    if (Playing)
    {
        cout << "Reproduciendo";
    }else
    {
        cout << "Reproduccion en pausa \n"
        <<"Cancion actual";
    }

    if (!estado.empty())
    {
        cout << "(" + estado + ")";
    }

    cout << ": "
    <<actual->dato.getNombre()
    << " - "
    << actual->dato.getArtista()
    << endl;

}

int Reproductor::getIndexActual() {
    Nodo<Cancion>* temp = playlist.getCabeza();
    int index = 0;

    while (temp != nullptr) {
        if (temp == actual) {
            return index;
        }

        temp = temp->next;
        index++;
    }

    return -1;
}

ListaEnlazada<Cancion>& Reproductor::getPlaylist()
{
    return playlist;
}

void Reproductor::SetEstado(int index, bool play, bool mix, int repeat) {
    this->Playing = play;
    this->mixRand=mix;
    this->RepeatMode=repeat;

    actual =playlist.getCabeza();

    for (int i=0;i<index && actual!=nullptr;i++) {
        actual=actual->next;
    }
}

bool Reproductor::getPlaying() {
    return Playing;
}
bool Reproductor::getMix() {
    return mixRand;
}

string Reproductor::getState()
{
    string RM = "";
    if (mixRand)
    {
        RM += "S";
    }

    if (RepeatMode == 1)
    {
        if (!RM.empty()){RM += " - ";}
        RM += "R1";
    }
    else if (RepeatMode == 2)
    {
        if (!RM.empty()){RM += " - ";}
        RM += "RA";

    }


    return RM;
}
int Reproductor::getRepeatMode()
{
    return RepeatMode;
}

ListaEnlazada<Cancion>& Reproductor::getLista() {
    return lista;
}
void Reproductor::moverseHaciaCancion(int pos)
{
    if (playlist.tamano() == 0) {
        return;
    }

    if (pos >= 0 && pos < playlist.tamano()) {
        actual = playlist.getCabeza();

        for (int i = 0; i < pos; i++)
        {
            actual = actual->next;
        }

        Playing = true;
    }
}

void Reproductor::mezclarPL()
{
    int number = playlist.tamano();

    if (number <= 1){return;}

    for (int i= number - 1 ; i>0;i--)
    {
        int j = rand() % (i+1);

        Cancion temp = playlist.obtener(i);
        playlist.mod(i, playlist.obtener(j));
        playlist.mod(j, temp);
    }
}

void Reproductor::playSong(int index)
{
    if (index< 0 || index >= lista.tamano())
    {
        cout << "Cancion invalida\n";
        return;
    }

    Cancion selec = lista.obtener(index);

    playlist.clean();

    playlist.insertarFinal(selec);

    for (int i=0;i<lista.tamano();i++)
    {
        if ( i != index)
        {
            playlist.insertarFinal(lista.obtener(i));
        }
    }
    if (playlist.tamano() > 1)
    {
        for (int i=playlist.tamano() -1;i>1;i--)
        {
            int j = 1 + rand() % i;

            Cancion temporal = playlist.obtener(i);
            playlist.mod(i, playlist.obtener(j));
            playlist.mod(j, temporal);
        }
    }
    actual = playlist.getCabeza();
    Playing = true;

    cout << "Cancion elegida ya en reproduccion\n";
}


void Reproductor::mezclarRestantes()
{
    int total = playlist.tamano();

    if (total <= 1 || actual == nullptr)
    {
        return;
    }

    int indiceActual = getIndexActual();

    int inicio = indiceActual + 1;

    if (inicio >= total)
    {
        return;
    }

    for (int i = total - 1; i > inicio; i--)
    {
        int j = inicio + rand() % (i - inicio + 1);

        Cancion temp = playlist.obtener(i);
        playlist.mod(i, playlist.obtener(j));
        playlist.mod(j, temp);
    }

    actual = playlist.getCabeza();

    for (int i = 0; i < indiceActual; i++)
    {
        actual = actual->next;
    }
}

void Reproductor::construirIndiceBusqueda()
{
    for (int i = 0; i < lista.tamano(); i++)
    {
        A_canciones.insertar(lista.obtener(i), i);
    }
}


ListaEnlazada<int> Reproductor::buscarCanciones(string texto)
{
    return A_canciones.buscar(texto);
}


int Reproductor::obtenerReproducciones(int idCancion) {
    ifstream arch("ranking.txt");
    if (!arch.is_open()) {
        return 0;
    }
    string linea;
    while (getline(arch,linea)) {
        stringstream ss(linea);
        int idactual;
        int cantidadReprod;
        ss>>idactual>>cantidadReprod;
        
        if (idactual == idCancion) {
            archivo.close();
            return cantidadRep;
        }
    }
    arch.close();
    return 0;
}


