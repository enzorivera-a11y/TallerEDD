//
// Created by Enzod on 18-04-2026.
//

#ifndef TALLEREDD_CANCION_H
#define TALLEREDD_CANCION_H

#include <string>
using namespace std;

class Cancion {
public:
    int id;
    string nombre;
    string artista;
    string album;
    int agno;
    int duracion;
    string ubi_arch;

    Cancion();

    Cancion(int id, string nombre, string artista, string album, int agno, int duracion, string ubi_arch);

    string getNombre();
    string getArtista();
};



#endif
