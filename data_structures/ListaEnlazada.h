//
// Created by Enzod on 18-04-2026.
//

#ifndef TALLEREDD_LISTAENLAZADA_H
#define TALLEREDD_LISTAENLAZADA_H

#include "Nodo.h"

template <typename T>
class ListaEnlazada {
    private:
    Nodo<T> *inicio;
    int num;

    public:
    ListaEnlazada()
    {
        inicio = nullptr;
        num = 0;
    }

    Nodo<T>* getCabeza() {
        return inicio;
    }

    void vaciar()
    {
        Nodo<T>* temp;
        while (inicio != nullptr)
        {
            temp = inicio;
            inicio = inicio->next;
            delete temp;
        }
        num = 0;
    }

    void insertarFinal(T dato)
    {
        Nodo<T>* nodoNuevo = new Nodo<T>(dato);

        if (inicio == nullptr)
        {
            inicio = nodoNuevo;
        }else
        {
            Nodo<T>* current = inicio;
            while (current->next != nullptr)
            {
                current = current->next;
            }

            current -> next = nodoNuevo;

        }
        num++;
    }
    int tamano() const
    {
        return num;
    }
    T obtener(int pos) const
    {   Nodo<T> *current = inicio;

        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        return current -> dato;

    }

    void clean()
    {
        Nodo<T>* current = inicio;
        while (current != nullptr)
        {
            Nodo<T>* temp = current;
            current = current->next;
            delete temp;
        }
        inicio = nullptr;
        num = 0;

    }

    void mod(int pos, T data)
    {
        if (pos < 0 || pos >= num)
        {
            return;
        }
        Nodo<T>* current = inicio;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
        current -> dato = data;
    }
};

#endif //TALLEREDD_LISTAENLAZADA_H
