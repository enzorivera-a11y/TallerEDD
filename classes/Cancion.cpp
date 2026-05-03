#include "Cancion.h"


Cancion::Cancion() {
    id = 0;
    nombre = "";
    artista = "";
    album = "";
    agno = 0;
    duracion = 0;
    ubi_arch = "";
}

Cancion::Cancion(int id, string nombre, string artista, string album, int agno, int duracion, string ubi_arch)
{
    this->id = id;
    this->nombre = nombre;
    this->artista = artista;
    this->album = album;
    this->agno = agno;
    this->duracion = duracion;
    this->ubi_arch = ubi_arch;
}
#include "Cancion.h"

std::string Cancion::getNombre() {
    return nombre;
}

std::string Cancion::getArtista() {
    return artista;
}