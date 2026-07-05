#include "ArbolHeap.h"

ArbolHeap::ArbolHeap(int a){
    capacidad = a;
    lista = new CancionRanking[1+capacidad];
    total = 0;
}
ArbolHeap::~ArbolHeap(){
    delete[] lista;
}

void ArbolHeap::ajustarAb(int i){
    int maximo = i;
    int izquierdo = 2*i;
    int derecho = 2* i +1;
    if (izquierdo <= total && lista[izquierdo].reproducciones > lista[maximo].reproducciones)
        maximo = izquierdo;
    if (derecho <= total && lista[derecho].reproducciones > lista[maximo].reproducciones)
        maximo = derecho;
    if(maximo != i){//BURBUJAAA
        CancionRanking temporal = lista[i];
        lista[i] = lista[maximo];
        lista[maximo] = temporal;
        ajustarAb(maximo);
    }
}
void ArbolHeap::insertar(CancionRanking item) {
    if (total >= capacidad) {
        return;
    }
    total++;
    int i = total;
    lista[i] = item;

    while (i > 1 && lista[i / 2].reproducciones < lista[i].reproducciones) {
        CancionRanking temporal = lista[i];
        lista[i] = lista[i / 2];
        lista[i / 2] = temporal;
        i = i / 2;
    }
}

CancionRanking ArbolHeap::obtentermax() {
    if (total == 0) {
        return {"", "", "", -1};
    }
    CancionRanking maximo = lista[1];
    lista[1] = lista[total];
    total--;
    ajustarAb(1);
    return maximo;
}

int ArbolHeap::obtenertotal() {
    return total;
}
