PlayerSona: Reproductor de Música vía consola

## Integrantes

Enzo Rivera Flores - Iván Cosse Viloria

## Descripción

PlayerSona es un reproductor musical desarrollado en C++ para consola.
El proyecto implementa listas enlazadas manualmente sin utilizar STL.
Permite gestionar playlists, reproducir canciones, usar modo aleatorio,
modo repetición y persistencia mediante archivos.
También incluye manejo de canciones registradas y almacenamiento de estado.

---

## Diagrama de clases

```txt
+-------------------+
|     Cancion       |
+-------------------+
| id                |
| nombre            |
| artista           |
| album             |
| anio              |
| duracion          |
| ruta              |
+-------------------+

          ▲
          |
+-------------------+
|      Nodo<T>      |
+-------------------+
| dato              |
| next              |
+-------------------+

          ▲
          |
+--------------------------+
|   ListaEnlazada<T>       |
+--------------------------+
| inicio                   |
| num                      |
+--------------------------+
| insertarFinal()          |
| obtener()                |
| eliminar()               |
| limpiar()                |
| modificar()              |
+--------------------------+

          ▲
          |
+--------------------------+
|      Reproductor         |
+--------------------------+
| lista                    |
| playlist                 |
| actual                   |
| Playing                  |
| mixRand                  |
| RepeatMode               |
+--------------------------+
| playPause()              |
| Next()                   |
| Back()                   |
| toggleMixRand()          |
| ChangeRepeatMode()       |
| mostrarActual()          |
| moverseHaciaCancion()    |
+--------------------------+

          ▲
          |
+--------------------------+
|    GestorArchivos        |
+--------------------------+
| cargarCanciones()        |
| guardarEstado()          |
| cargarEstado()           |
+--------------------------+
```

---

## Estructura del proyecto

```txt
TallerEDD/
│
├── classes/
│   ├── Cancion.h
│   ├── Cancion.cpp
│   ├── Reproductor.h
│   ├── Reproductor.cpp
│   ├── GestorArchivos.h
│   └── GestorArchivos.cpp
│
├── core/
│   ├── Menu.h
│   └── Menu.cpp
│
├── data/
│   ├── music_source.txt
│   └── status.cfg
│
├── data_structures/
│   ├── Nodo.h
│   └── ListaEnlazada.h
│
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

## Funcionamiento de la aplicación

El programa inicia cargando las canciones registradas desde el archivo
`music_source.txt` y el estado previo del reproductor desde `status.cfg`.

El usuario interactúa mediante un menú principal que permite:

* reproducir o pausar canciones
* avanzar o retroceder canciones
* activar modo aleatorio
* activar modos de repetición
* gestionar playlists
* gestionar canciones registradas

El reproductor mantiene dos listas independientes:

* `lista`: catálogo completo de canciones
* `playlist`: lista de reproducción actual

El estado de reproducción se muestra dinámicamente mediante indicadores como:

```txt
Reproduciendo (S-R1): Fire Dance - Vivid BAD Squad
```

Donde:

* `S` representa modo aleatorio activado
* `R1` representa repetir una canción
* `RA` representa repetir toda la playlist

---

## Funcionalidades implementadas

### Reproducción

* Play / Pause
* Siguiente canción
* Canción anterior
* Mostrar canción actual

### Playlist

* Visualización de playlist actual
* Saltar a canción específica (`S<num>`)
* Agregar canciones al final de la playlist (`A<num>`)

### Registro de canciones

* Mostrar canciones registradas
* Agregar nuevas canciones (`N`)
* Eliminar canciones (`D<num>`)
* Reproducir canción específica (`R<num>`)

### Modos de reproducción

#### Modo Aleatorio

* Se activa/desactiva con `S`
* Mezcla las canciones restantes de la playlist una sola vez

#### Modo Repetición

* OFF
* Repetir una (`R1`)
* Repetir todas (`RA`)

### Persistencia

El programa guarda automáticamente:

* canción actual
* estado de reproducción
* modo aleatorio
* modo repetición

mediante el archivo:

```txt
status.cfg
```
(Ubicado en "cmake-build-debug")

---

## Compilación

### CLion

Abrir el proyecto con CLion y ejecutar:

```txt
Build → Build Project
```

### Compilación manual (g++)

```bash
g++ main.cpp classes/*.cpp core/*.cpp -o NeoPlayer
```

---

## Ejecución

### Windows

```txt
PlayerSona.exe
```

### Linux / Mac

```bash
./PlayerSona
```

---

## Archivos utilizados

### music_source.txt

Contiene el registro de canciones del programa.

Formato:

```txt
id,nombre,artista,album,anio,duracion,ruta
```

Ejemplo:

```txt
1,Fire Dance,Vivid BAD Squad,Fire Dance Single,2025,210,C:/musica/fire.mp3
```

---

### status.cfg

Guarda el estado actual del reproductor.

Ejemplo:

```txt
current_song=0
is_playing=1
shuffle=0
repeat_mode=2
```

---

Uso de CMake

El proyecto utiliza CMake para automatizar la compilación de múltiples
archivos fuente y facilitar el desarrollo dentro de CLion.

---

Restricciones del proyecto

El proyecto fue desarrollado respetando las restricciones del taller:

* sin uso de STL para estructuras de datos
* implementación manual de listas enlazadas
* uso de templates
* persistencia mediante archivos
* programación orientada a objetos
