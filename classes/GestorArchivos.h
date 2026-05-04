

#ifndef TALLEREDD_GESTORARCHIVOS_H
#define TALLEREDD_GESTORARCHIVOS_H

#include "Cancion.h"
#include "../data_Structures/ListaEnlazada.h"
#include "Reproductor.h"

class GestorArchivos
{
    public:
    ListaEnlazada<Cancion> cargarCanciones();
    void guardarEstado(Reproductor& rep);
    void cargarEstado(Reproductor& rep);

};



#endif //TALLEREDD_GESTORARCHIVOS_H
