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

    // Hijos del Trie (ASCII)
    NodoTrie* hijos[128];

    // Indica si termina una palabra
    bool finPalabra;

    // Canciones asociadas a esta palabra
    ListaEnlazada<Cancion> canciones;

    NodoTrie()
    {
        finPalabra = false;

        for(int i = 0; i < 128; i++)
        {
            hijos[i] = nullptr;
        }
    }
};



#endif //TALLEREDD_NODOTRIE_H
