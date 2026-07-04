#ifndef ARBOLHEAP_H_INCLUDED
#define ARBOLHEAP_H_INCLUDED
#include <string>
struct CancionRanking {
    int id;
    std:: string nombre;
     std::string artista;
    int reproducciones;
};

class ArbolHeap{

private:
    CancionRanking* lista;
    int capacidad;
    int total;

    void ajustarAb(int i);
public:
    ArbolHeap(int cap);
    ~ArbolHeap();
    void insertar(CancionRanking item);
    CancionRanking obtentermax();
    int obtenertotal();


};

#endif // ARBOLHEAP_H_INCLUDED
