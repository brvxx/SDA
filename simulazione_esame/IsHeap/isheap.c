#include <stdlib.h>
#include <string.h>

#include "minheap.h"

Heap* HeapifyMinHeap_(const ElemType* v, size_t v_size) {
    // Costruisco la heap con gli elementi del vettore v
    Heap* h = HeapCreateEmpty();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType) * (v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    // Chiamo la HeapMinMoveDown a partire dai nodi nel penultimo livello
    // dell'albero fino alla radice, per garantire che tutti i nodi rispettino 
    // le proprietà (min-)heap. Non serve chiamare la HeapMinMoveDown sulle
    // foglie perché non avrebbe alcun effetto.
    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        HeapMinMoveDown(h, i);
    }
    return h;
}

// la logica dietro questo procedimento è che: se a me viene passata una min-heap, allora andando a fare
// l'heapify del vettore data di questa "heap" allora questa nuova heap creata avrà il campo data IDENTICO 
// a quello della heap passata alla funzione. invece se la "heap" passata non è una heap, significa che la 
// heap creata dall'heapify del vettore della heap passata per parametro produrrà un vettore diverso da quello 
// contenuto in data della heap passata

bool IsHeap(const Heap* h) {
    Heap* tmp = HeapifyMinHeap_(h->data, h->size); 

    if (memcmp(h->data, tmp->data, h->size * sizeof(ElemType)) == 0) {
        HeapDelete(tmp); 
        return true; 
    }
    else {
        HeapDelete(tmp); 
        return false; 
    }
}