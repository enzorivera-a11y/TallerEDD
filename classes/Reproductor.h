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
    ListaEnlazada<Cancion> playlist;
    Nodo<Cancion>* actual;

    bool Playing;
    bool mixRand;
    int RepeatMode;

public:
    Reproductor();


    Nodo<Cancion>* getCabezaActual();

    ListaEnlazada<Cancion>& getLista();
    ListaEnlazada<Cancion>& getPlaylist();
    void setLista(ListaEnlazada<Cancion> lista);
    void moverseHaciaCancion(int pos);

    void playPause();
    void Next();
    void Back();

    void toggleMixRand();
    void ChangeRepeatMode();

    void mostrarActual();

    void agregarSong(int index);

    int getIndexActual();
    bool getPlaying();
    bool getMix();
    string getState();
    int getRepeatMode();

    void SetEstado(int index,bool play,bool mix,int repeat);
    void generarMixRand();

    void mezclarPL();
    void playSong(int index);

    void mezclarRestantes();
};


#endif
