#define _CRT_SECURE_NO_WARNINGS
#include "doublelist.h"

#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                           Item & Primitives                               */
/*****************************************************************************/

Item *DListCreateEmpty(void) {
    return NULL;
}

// funzione che inserisce un item in testa alla lista
Item *DListInsertHead(const ElemType *e, Item *i) {
    Item *n = malloc(sizeof(Item));
    n->value = ElemCopy(e);
    n->next = i;
    n->prev = NULL;
    
    // aggiorniamo il collegamento dell'item successivo (se esiste) 
    if (!DListIsEmpty(i)) {
        i->prev = n;
    }
    return n;
}

// predicato che controlla se una lista (item*) è vuota o no
bool DListIsEmpty(const Item *i) {
    return i == NULL;
}

const ElemType *DListGetHeadValue(const Item *i) {
    if (DListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'DListGetHead()' e' stata passata una lista vuota (NULL).\n");
        exit(1);
    }
    else {
        return &i->value;
    }
}

// funzione che ci torna un puntatore al prossimo elemento della lista, è la GetTail tradizionale 
Item *DListGetTail(const Item *i) {
    if (DListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetTail()' e' stata passata una lista vuota (NULL).\n");
        exit(2);
    }
    else {
        return i->next;
    }
}

// funzione che ci torna un puntatore all'elemento precedente di quello passato come parametro 
Item* DListGetPrev(const Item* i) {
    if (DListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'DListGetHead()' e' stata passata una lista vuota (NULL).\n");
        exit(3);
    }
    else {
        return i->prev;
    }
}

Item *DListInsertBack(Item *i, const ElemType *e) {

    // creo il nuovo nodo da aggiungere alla lista, uso la 
    // insert head ad una lista nulla per comodità 
    Item *n = DListInsertHead(e, DListCreateEmpty());

    if (DListIsEmpty(i)) {
        return n;
    }

    Item *tmp = i;
    // scorro la lista finché il prossimo item dell'item corrente è NULL, ossia 
    // vado avanti finché non arrivo all'ultimo item della lista 
    while (!DListIsEmpty(DListGetTail(tmp))) {
        tmp = DListGetTail(tmp);
    }

    tmp->next = n;
    n->prev = tmp;
    return i;
}

// funzione che a prescindere dalla posizione in cui ci troviamo nella 
// lista ritorna il primo elemento, ossia quello che ha NULL come prev
static const Item* DListGetFirst(const Item* i) {
    if (DListIsEmpty(i)) {
        return NULL;
    }

    while (!DListIsEmpty(i->prev)) {
        i = i->prev;
    }

    return i;
}

void DListDelete(Item *i) {

    i = (Item*)DListGetFirst(i);

    while (!DListIsEmpty(i)) {
        Item *tmp = i;
        i = i->next;
        ElemDelete(&tmp->value);
        free(tmp);
    }
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void DListWrite(const Item *i, FILE *f) {
    
    i = DListGetFirst(i);
    
    fprintf(f, "[");
    while (!DListIsEmpty(i)) {
        ElemWrite(&i->value, f);
        i = DListGetTail(i);
        if (!DListIsEmpty(i)) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void DListWriteStdout(const Item *i) {
    DListWrite(i, stdout);
}