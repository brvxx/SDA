#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "doublelist.h"

// La funzione elimina il nodo di indirizzo to_be_deleted 
// dalla lista. Si assume che il nodo to_be_deleted sia
// sempre presente in l. Quello che facciamo poi sarà andare a
// mettere apposto i collegamenti tra l'item precedente e successivo 
// a quello eliminato 
void ItemDelete(List *l, Item *to_be_deleted) {
    
    Item *prev = to_be_deleted->prev;
    Item *next = to_be_deleted->next;

    // se l'item da eliminare non era il primo della lista 
    if (prev) {
        prev->next = next;
    } else {    // se l'item da eliminare era il primo della lista 
        l->first = next;
    }

    // se l'item da eliminare non era l'ultimo della lista 
    if (next) { 
        next->prev = prev;
    } else {    // se l'item da eliminare era l'ultimo della lista 
        l->last = prev;
    }

    // Costo computazionale? O(1);
}
// estremamente più semplice rispetto al metodo utilizzato per le liste concatenate 
// normalmente 



int main(void) {

    ElemType e[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    size_t e_size = sizeof(e)/sizeof(ElemType);
    List *l  = ListCreateEmpty();
    List *l2 = ListCreateEmpty();
    

    for(size_t j = 0; j < e_size; ++j) {
        ListInsertBack(l, e + j);
    }

    // Ora possiamo iterare la lista al contrario, a partire dall'ultimo elemento.
    Item *tmp = ListGetLast(l);
    printf("[");
    while (!ItemIsEmpty(tmp)) {
        ElemWrite(ItemGetValue(tmp), stdout);
        tmp = tmp->prev;
        if (tmp) {
            printf(", "); 
        }
    }
    printf("]\n");

    for (size_t j = 0; j < e_size; ++j) {
        ListInsertHead(e + j, l2);
    }
    
    ListWrite(l, stdout);
    ListWrite(l2, stdout);

    ListDelete(l);
    ListDelete(l2);

    return 0;
}