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

    void insertarTexto(string texto, int indice);

    void insertarSufijos(string texto, int indice);

    bool existeIndice(ListaEnlazada<int>& lista, int indice);

public:

    ArbolTrie();

    void insertar(Cancion cancion, int indice);

    ListaEnlazada<int> buscar(string texto);
};

#endif
