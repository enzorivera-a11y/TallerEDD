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

void ArbolTrie::insertarTexto(string texto, int indiceCancion)
{
    texto = minusculas(texto);

    NodoTrie* actual = raiz;

    for(char c: texto)
    {
        unsigned char caracter = static_cast<unsigned char>(c);

        if(actual->hijos[caracter] == nullptr)
        {
            actual->hijos[caracter] = new NodoTrie();
        }

        actual = actual->hijos[caracter];

        if(!existeIndice(actual->canciones, indiceCancion))
        {
            actual->canciones.insertarFinal(indiceCancion);
        }
    }

    actual->finPalabra = true;
}

void ArbolTrie::insertarSufijos(string texto, int indice)
{
    texto = minusculas(texto);

    for(int i = 0; i < texto.size(); i++)
    {
        string sufijo = texto.substr(i);

        insertarTexto(sufijo, indice);
    }
}

void ArbolTrie::insertar(Cancion cancion, int indice)
{
    insertarSufijos(cancion.getNombre(), indice);

    insertarSufijos(cancion.getArtista(), indice);
}

bool ArbolTrie::existeIndice(ListaEnlazada<int>& lista, int indice)
{
    Nodo<int>* actual = lista.getCabeza();

    while(actual != nullptr)
    {
        if(actual->dato == indice)
        {
            return true;
        }

        actual = actual->next;
    }

    return false;
}

ListaEnlazada<int> ArbolTrie::buscar(string texto)
{
    ListaEnlazada<int> resultado;

    texto = minusculas(texto);

    NodoTrie* actual = raiz;

    for(int i = 0; i < texto.size(); i++)
    {
        unsigned char indice = static_cast<unsigned char>(texto[i]);


        if(actual->hijos[indice] == nullptr)
        {
            return resultado;
        }

        actual = actual->hijos[indice];
    }

    Nodo<int>* aux = actual->canciones.getCabeza();

    while(aux != nullptr)
    {
        if(!existeIndice(resultado, aux->dato))
        {
            resultado.insertarFinal(aux->dato);
        }

        aux = aux->next;
    }

    return resultado;
}