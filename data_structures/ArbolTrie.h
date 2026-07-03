#ifndef TALLEREDD_ARBOLTRIE_H
#define TALLEREDD_ARBOLTRIE_H

#include <string>

#include "../classes/Cancion.h"
#include "NodoTrie.h"
#include "ListaEnlazada.h"

using namespace std;

class ArbolTrie
{
private:


    NodoTrie* raiz;

    string minusculas(string texto);

    void insertarTexto(string texto, Cancion* cancion);

    void insertarSufijos(string texto, Cancion* cancion);

    bool existeCancion(ListaEnlazada<Cancion*>& lista, Cancion* cancion);

public:

    ArbolTrie();

    void insertar(Cancion* cancion);

    ListaEnlazada<Cancion*> buscar(string texto);
};

#endif
