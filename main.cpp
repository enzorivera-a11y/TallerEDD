#include <iostream>

#include "classes/GestorArchivos.h"
using namespace std;

int main() {
    GestorArchivos gestor;

    ListaEnlazada<Cancion> canciones = gestor.cargarCanciones();

    cout<< "Canciones cargadas: " << canciones.tamano() << endl;

    return 0;





    }
