#include <iostream>
#include "classes/GestorArchivos.h"
#include "classes/Reproductor.h"
#include "core/Menu.h"

using namespace std;

int main() {
    GestorArchivos gestor;

    ListaEnlazada<Cancion> canciones = gestor.cargarCanciones();

    cout << "Canciones cargadas: " << canciones.tamano() << endl;

    Reproductor reproductor;
    reproductor.setLista(canciones);

    menuInicial(reproductor);

    return 0;
}
