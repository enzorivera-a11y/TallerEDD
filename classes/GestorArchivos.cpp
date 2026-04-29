#include "GestorArchivos.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

ListaEnlazada<Cancion> GestorArchivos::cargarCanciones()
{
    ListaEnlazada<Cancion> canciones;
    ifstream archivo("../data/music_source.txt");
    if (!archivo.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
        return canciones;
    }
    string line;

    while (getline(archivo,line))
    {
        stringstream ss(line);

        string id, nombre, artista, album, agno, duracion, ubi_arch;

        getline(ss, id, ',');
        getline(ss, nombre, ',');
        getline(ss, artista, ',');
        getline(ss, album, ',');
        getline(ss, agno, ',');
        getline(ss, duracion, ',');
        getline(ss, ubi_arch, ',');

        /*1,Fire Dance,Vivid BAD Squad,Fire Dance Single,2025,210,C:/musica/fire.mp3
         *id = "1"
         *nombre = "Fire Dance"
         *artista = Vivid BAD Squad"
         *album = "Fire Dance Single"
         *agno = "2025"
         *duracion = "210"
         *ubi_arch = "C:/musica/fire.mp3" */

        Cancion song(stoi(id), nombre, artista, album, stoi(agno), stoi(duracion), ubi_arch );

        canciones.insertarFinal(song);





    }
    archivo.close();

    return canciones;
}
