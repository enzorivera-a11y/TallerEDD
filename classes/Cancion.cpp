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

string Cancion::getNombre() const {
    return nombre;
}

string Cancion::getArtista() const{
    return artista;
}

int Cancion::getId() const{
    return id;
}

string Cancion::getAlbum() const {
    return album;
}

int Cancion::getAgno() const{
    return agno;
}

int Cancion::getDuracion() const{
    return duracion;
}

string Cancion::getUbiArchivo() const{
    return ubi_arch;
}

