# PlayerSona - Reproductor Musical en C++

> Proyecto desarrollado para el Taller de Estructuras de Datos.

PlayerSona es un reproductor musical ejecutado completamente desde consola, desarrollado en **C++**. El proyecto implementa manualmente diversas estructuras de datos, permitiendo administrar canciones, playlists, búsquedas rápidas y estadísticas de reproducción.

---

# Integrantes

- Enzo Rivera Flores
- Iván Cosse Viloria
- Diego Guerra Estay

---

# Descripción

El objetivo del proyecto es desarrollar un reproductor musical aplicando estructuras de datos implementadas manualmente y programación orientada a objetos.

El sistema permite:

- Reproducir canciones
- Administrar playlists
- Buscar canciones por nombre o artista
- Gestionar un catálogo musical
- Obtener el Top 10 de artistas y canciones más reproducidas

Todas las estructuras utilizadas fueron implementadas por los integrantes del proyecto, respetando las restricciones del taller.

---

# Funcionalidades

## Reproducción

- Play / Pause
- Canción siguiente
- Canción anterior
- Mostrar canción actual
- Reproducir canción específica

---

## Playlist

- Visualizar playlist actual
- Saltar a una canción específica
- Agregar canciones al final
- Reordenamiento aleatorio (Shuffle)

---

## Sistema de búsqueda

El proyecto incorpora un "Árbol Trie", permitiendo búsquedas rápidas tanto por:

- Nombre de canción
- Nombre del artista

La búsqueda funciona mediante **subcadenas**, por ejemplo:

Buscar:

```
sheeran
```

Resultado:

```
Shivers - Ed Sheeran
Bad Habits - Ed Sheeran
Perfect - Ed Sheeran
Shape of You - Ed Sheeran
```

También funciona para fragmentos internos.

Ejemplo:

```
wave
```

Resultado:

```
Heat Waves
```

---

## Modos de reproducción

### Shuffle

- Activa/desactiva reproducción aleatoria.
- Solo mezcla las canciones restantes de la playlist.

### Repeat

Tres modos disponibles:

- OFF
- Repeat One
- Repeat All

---

## Persistencia

El estado del reproductor se guarda automáticamente.

Se conserva:

- Canción actual
- Estado Play/Pause
- Shuffle
- Repeat

Al reiniciar el programa, la reproducción continúa desde el estado anterior.

---

# Estructuras de datos implementadas

## Lista Enlazada

Utilizada para:

- Catálogo de canciones
- Playlist
- Resultados de búsqueda
- Listas auxiliares

Operaciones implementadas:

- Inserción
- Eliminación
- Modificación
- Obtención por índice
- Limpieza
- Recorrido

---

## Árbol Trie

Utilizado para indexar:

- Nombre de canciones
- Nombre de artistas

Características:

- Inserción de todos los sufijos.
- Búsqueda por cualquier parte del texto.
- Evita recorrer secuencialmente todas las canciones.


## Árbol AVL

Utilizado para almacenar información ordenada de artistas.

Características:

- Árbol auto balanceado.
- Inserciones eficientes.
- Mantiene altura logarítmica.


```

## Heap

Utilizado para generar:

- Top 10 artistas
- Top 10 canciones

Permite mantener los elementos con mayor cantidad de reproducciones.

---

# Organización del proyecto

TallerEDD/
│
├── classes/
│   ├── Artista.*
│   ├── Cancion.*
│   ├── GestorArchivos.*
│   └── Reproductor.*
│
├── core/
│   ├── Menu.*
│
├── data/
│   ├── music_source.txt
│   └── status.cfg
│
├── data_structures/
│   ├── Nodo.h
│   ├── NodoAVL.h
│   ├── NodoTrie.h
│   ├── ListaEnlazada.h
│   ├── ArbolAVL.*
│   ├── ArbolTrie.*
│   └── ArbolHeap.*
│
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

# Funcionamiento

Al iniciar el programa:

1. Se cargan las canciones desde el archivo de datos.
2. Se construye el índice Trie.
3. Se construyen las estructuras auxiliares.
4. Se restaura el estado del reproductor.
5. Se muestra el menú principal.

El usuario interactúa mediante comandos de teclado.

---

# Menú principal

```
W  Reproducir / Pausar

Q  Canción anterior

E  Canción siguiente

S  Shuffle

R  Cambiar modo Repeat

A  Menú Playlist

L  Menú Canciones

F  Buscar canciones

T  Top 10

X  Salir
```

---

# Archivos utilizados

## music_source.txt

Almacena todas las canciones.

Formato:

```
id,nombre,artista,album,año,duracion,ruta
```

Ejemplo:

```
1,Fire Dance,Vivid BAD Squad,...
```

---

## status.cfg

Guarda el estado del reproductor.

Ejemplo:

```
current_song=4
playing=1
shuffle=0
repeat=2
```

---

# Compilación

## CLion

Abrir el proyecto y ejecutar:

```
Build → Build Project
```

---

## CMake

```bash
cmake .
cmake --build .
```

---

# ▶ Ejecución

Windows

```
PlayerSona.exe
```

Linux

```bash
./PlayerSona
```

---

# Restricciones del proyecto

El proyecto fue desarrollado respetando las condiciones del taller:

- Sin utilizar estructuras de datos de la STL.
- Implementación manual de listas enlazadas.
- Implementación manual de árboles.
- Uso de templates.
- Programación orientada a objetos.
- Persistencia mediante archivos.
- Modularización mediante clases.
