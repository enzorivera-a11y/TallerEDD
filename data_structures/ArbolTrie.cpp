#include "ArbolTrie.h"

ArbolTrie::ArbolTrie()
{
    raiz = new NodoTrie();
}

string ArbolTrie::minusculas(string texto)
{
    for(int i = 0; i < texto.size(); i++)
    {
        if(texto[i] >= 'A' && texto[i] <= 'Z')
        {
            texto[i] = texto[i] + 32;
        }
    }

    return texto;
}

void ArbolTrie::insertarTexto(string texto, Cancion* cancion)
{
    texto = minusculas(texto);

    NodoTrie* actual = raiz;

    for(int i = 0; i < texto.size(); i++)
    {
        int indice = (int)texto[i];

        if(actual->hijos[indice] == nullptr)
        {
            actual->hijos[indice] = new NodoTrie();
        }

        actual = actual->hijos[indice];
    }

    actual->finPalabra = true;

    actual->canciones.insertarFinal(cancion);
}

void ArbolTrie::insertarSufijos(string texto, Cancion* cancion)
{
    texto = minusculas(texto);

    for(int i = 0; i < texto.size(); i++)
    {
        string sufijo = texto.substr(i);

        insertarTexto(sufijo, cancion);
    }
}

void ArbolTrie::insertar(Cancion* cancion)
{
    insertarSufijos(cancion->getNombre(), cancion);

    insertarSufijos(cancion->getArtista(), cancion);
}

bool ArbolTrie::existeCancion(ListaEnlazada<Cancion*>& lista, Cancion* cancion)
{
    Nodo<Cancion*>* actual = lista.getCabeza();

    while(actual != nullptr)
    {
        if(actual->dato->id == cancion->id)
        {
            return true;
        }

        actual = actual->next;
    }

    return false;
}

ListaEnlazada<Cancion*> ArbolTrie::buscar(string texto)
{
    ListaEnlazada<Cancion*> resultado;

    texto = minusculas(texto);

    NodoTrie* actual = raiz;

    for(int i = 0; i < texto.size(); i++)
    {
        int indice = (int)texto[i];

        if(actual->hijos[indice] == nullptr)
        {
            return resultado;
        }

        actual = actual->hijos[indice];
    }

    Nodo<Cancion*>* aux = actual->canciones.getCabeza();

    while(aux != nullptr)
    {
        if(!existeCancion(resultado, aux->dato))
        {
            resultado.insertarFinal(aux->dato);
        }

        aux = aux->next;
    }

    return resultado;
}