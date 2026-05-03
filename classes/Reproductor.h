//
// Created by Enzod on 18-04-2026.
//

#ifndef TALLEREDD_REPRODUCTOR_H
#define TALLEREDD_REPRODUCTOR_H

#include "../data_structures/ListaEnlazada.h"
#include "Cancion.h"

class Reproductor {
private:
    ListaEnlazada<Cancion> lista;
    Nodo<Cancion>* actual;

    bool Playing;
    bool mixRand;
    int RepeatMode;

public:
    Reproductor();

    ListaEnlazada<Cancion>& getLista();
    void setLista(ListaEnlazada<Cancion> lista);
    void moverseHaciaCancion(int pos);

    void playPause();
    void Next();
    void Back();

    void toggleMixRand();
    void ChangeRepeatMode();

    void mostrarActual();

    int getIndexActual();
    bool getPlaying();
    bool getMix();
    int getRepeatMode();

    void SetEstado(int index,bool play,bool mix,int repeat);
};


#endif
