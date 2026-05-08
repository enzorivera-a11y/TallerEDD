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
    ofstream file("status.cfg");

    if (!file.is_open())
    {
        cout << "Error al guardar estado" << endl;
        return;
    }

    cout << "Guardando estado..." << endl;

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
            current = stoi(line.substr(8));

        else if (line.find("Playing=") == 0)
            playing = stoi(line.substr(8));

        else if (line.find("Mix=") == 0)
            mixRand = stoi(line.substr(4));

        else if (line.find("Repeat=") == 0)
            repeat = stoi(line.substr(7));
    }

    file.close();

    rep.SetEstado(current, playing, mixRand, repeat);
}
