//
// Created by Enzod on 18-04-2026.
//

#include "Reproductor.h"
#include "Cancion.h"
#include <iostream>

using namespace std;

void Reproductor::setLista(ListaEnlazada<Cancion> lista) {
    this->lista = lista;
    this->actual = this->lista.getCabeza();
}

Reproductor::Reproductor() {
    actual = nullptr;
    Playing =false;
    mixRand =false;
    RepeatMode= 0;
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
            actual = lista.getCabeza();
        }else {
            cout << "Fin de la lista" << endl;
        }
    }
}

void Reproductor::Back() {
    if (actual == nullptr || actual == lista.getCabeza()) return;

    Nodo<Cancion>* temp= lista.getCabeza();

    while (temp->next != actual) {
        temp = temp->next;
    }

    actual=temp;
}

void Reproductor::toggleMixRand() {
    if (lista.tamano() == 0)
    {
        return;
    }

    mixRand= !mixRand;

    if (mixRand) {
        cout<< "Mix ON"<< endl;
    }else {
        cout<< "Mix OFF"<< endl;
    }
}

void Reproductor::ChangeRepeatMode() {
    RepeatMode = (RepeatMode+1)%3;

    cout<< "Repeat Mode:"<< endl;
}

void Reproductor::mostrarActual() {
    if (actual == nullptr) {
        cout << "No hay canciones"<< endl;
        return;
    }

    cout << "Reproduciendo:"
    << actual->dato.getNombre()
    << "-"
    << actual->dato.getArtista()
    << endl;

}

int Reproductor::getIndexActual() {
    Nodo<Cancion>* temp= lista.getCabeza();
    int index= 0;

    while (temp!= actual) {
        temp = temp->next;
        index++;
    }

    return index;
}

void Reproductor::SetEstado(int index, bool play, bool mix, int repeat) {
    this->Playing = play;
    this->mixRand=mix;
    this->RepeatMode=repeat;

    actual =lista.getCabeza();

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

int Reproductor::getRepeatMode() {
    return RepeatMode;
}

ListaEnlazada<Cancion>& Reproductor::getLista() {
    return lista;
}
void Reproductor::moverseHaciaCancion(int pos)
{
    if (lista.tamano() == 0) {
        return;
    }

    if (pos >= 0 && pos < lista.tamano()) {
        actual = lista.getCabeza();

        for (int i=0;i<pos;i++)
        {
            actual=actual->next;
        }
        Playing = true;
    }
}



