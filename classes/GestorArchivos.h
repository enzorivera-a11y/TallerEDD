

#ifndef TALLEREDD_GESTORARCHIVOS_H
#define TALLEREDD_GESTORARCHIVOS_H

#include "Cancion.h"
#include "../data_Structures/ListaEnlazada.h"

class GestorArchivos
{
    public:
    ListaEnlazada<Cancion> cargarCanciones();
};


#endif //TALLEREDD_GESTORARCHIVOS_H
