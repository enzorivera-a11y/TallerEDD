#include <iostream>
#include "classes/GestorArchivos.h"
#include "classes/Reproductor.h"
#include "core/Menu.h"

using namespace std;

int main() {
    GestorArchivos gestor;

    ListaEnlazada<Cancion> canciones = gestor.cargarCanciones();

    Reproductor reproductor;
    reproductor.setLista(canciones);
    gestor.cargarEstado(reproductor);


    menuInicial(reproductor);

    gestor.guardarEstado(reproductor);

    return 0;
}
