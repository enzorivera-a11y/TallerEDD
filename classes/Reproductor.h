//
// Created by Enzod on 18-04-2026.
//

#ifndef TALLEREDD_REPRODUCTOR_H
#define TALLEREDD_REPRODUCTOR_H

#endif //TALLEREDD_REPRODUCTOR_H

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

    void setLista(ListaEnlazada<Cancion> lista);

    void playPause();
    void Next();
    void Back();

    void toggleMixRand();
    void ChangeRepeatMode();

    void mostrarActual();

    // funciones para el status.ctg (en revision)
    int getIndexActual();
    bool getPlaying();
    bool getMix();
    int getRepeatMode();

    void SetEstado(int index,bool play,bool mix,int repeat);
};
