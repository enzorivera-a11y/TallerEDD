//
// Created by Enzod on 18-04-2026.
//

#ifndef TALLEREDD_NODO_H
#define TALLEREDD_NODO_H

template <typename T>
class Nodo
{
    public:
    T dato;
    Nodo<T>* next;

    Nodo(T dato)
    {
        this->dato = dato;
        this->next = nullptr;

    }
};
#endif //TALLEREDD_NODO_H
