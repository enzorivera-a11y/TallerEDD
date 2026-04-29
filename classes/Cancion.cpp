#include "Cancion.h"

Cancion::Cancion()
{
    id = 0;
    agno = 0;
    duracion = 0;
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
