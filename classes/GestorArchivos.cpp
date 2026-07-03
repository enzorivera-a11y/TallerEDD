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

        Cancion song(stoi(id), nombre, artista, album, stoi(agno), stoi(duracion), ubi_arch );

        canciones.insertarFinal(song);
    }
    archivo.close();

    return canciones;
}

void GestorArchivos::guardarEstado(Reproductor& rep)
{
    ofstream file("status.cfg");

    if (!file.is_open())
    {
        cout << "Error al guardar estado" << endl;
        return;
    }

    file << "Current=" << rep.getIndexActual() << endl;
    file << "Playing=" << rep.getPlaying() << endl;
    file << "Mix=" << rep.getMix() << endl;
    file << "Repeat=" << rep.getRepeatMode() << endl;

    file.close();
}

void GestorArchivos::cargarEstado(Reproductor& rep)
{
    ifstream file("status.cfg");

    if (!file.is_open())
    {
        rep.SetEstado(0, false, false, 0);
        return;
    }

    string line;
    int current = 0;
    int playing = 0;
    int mixRand = 0;
    int repeat = 0;

    while (getline(file, line))
    {
        if (line.find("Current=") == 0)
            current = stoi(line.substr(string("Current=").length()));

        else if (line.find("Playing=") == 0)
            playing = stoi(line.substr(string("Playing=").length()));

        else if (line.find("Mix=") == 0)
            mixRand = stoi(line.substr(string("Mix=").length()));

        else if (line.find("Repeat=") == 0)
            repeat = stoi(line.substr(string("Repeat=").length()));
    }
}

void GestorArchivos::agregarSongArchivo(const Cancion& song)
{
    ofstream file("../data/music_source.txt", ios::app);

    if (!file.is_open())
    {
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    file
        <<song.getId()<<","
        <<song.getNombre()<<","
        <<song.getArtista()<<","
        <<song.getAlbum()<<","
        <<song.getAgno() << ","
        <<song.getDuracion()<<","
        <<song.getUbiArchivo()
        <<endl;

    file.close();
}
