//
// Created by Enzod on 03-07-2026.
//

#ifndef TALLEREDD_NODOTRIE_H
#define TALLEREDD_NODOTRIE_H

#include "../classes/Cancion.h"
#include "ListaEnlazada.h"

class NodoTrie
{
public:

    NodoTrie* hijos[256];

    bool finPalabra;

    ListaEnlazada<int> canciones;

    NodoTrie()
    {
        finPalabra = false;

        for(int i = 0; i < 256; i++)
        {
            hijos[i] = nullptr;
        }
    }
};



#endif //TALLEREDD_NODOTRIE_H
