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

void GestorArchivos::guardarEstado(Reproductor& rep)
{
    ofstream file("data/status.cfg");

    if (!file.is_open())
    {
        cout << "Error al guardar estado" << endl;
        return;
    }

    file << "current_song=" << rep.getIndexActual() << endl;
    file << "is_playing=" << rep.getPlaying() << endl;
    file << "shuffle=" << rep.getMix() << endl;
    file << "repeat_mode=" << rep.getRepeatMode() << endl;

    file.close();
}

void GestorArchivos::cargarEstado(Reproductor& rep)
{
    ifstream file("data/status.cfg");

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
        if (line.find("current_song=") == 0)
            current = stoi(line.substr(13));

        else if (line.find("is_playing=") == 0)
            playing = stoi(line.substr(11));

        else if (line.find("shuffle=") == 0)
            mixRand = stoi(line.substr(8));

        else if (line.find("repeat_mode=") == 0)
            repeat = stoi(line.substr(12));
    }

    file.close();

    rep.SetEstado(current, playing, mixRand, repeat);
}
