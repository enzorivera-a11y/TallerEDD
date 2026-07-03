#ifndef TALLEREDD_ARTISTA_H
#define TALLEREDD_ARTISTA_H

#include <string>
#include "../data_structures/ArbolAVL.h"
#include "Cancion.h"

using namespace std;

struct ComparadorCancionTitulo {
    bool operator()(const Cancion* a, const Cancion* b) const {
        if (a->getNombre() != b->getNombre()) {
            return a->getNombre() < b->getNombre();
        }
        return a->getId() < b->getId();
    }
};

class Artista {
public:
    string nombre;
    int reproduccionesTotales;
    ArbolAVL<Cancion*, ComparadorCancionTitulo> A_canciones;

    Artista() : nombre(""), reproduccionesTotales(0) {}
    Artista(string n) : nombre(n), reproduccionesTotales(0) {}
};

#endif // TALLEREDD_ARTISTA_H
