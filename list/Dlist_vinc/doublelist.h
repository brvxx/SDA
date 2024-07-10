// dichiarazioni delle funzioni utilizzate per lavorare con liste doppiamente concatenate, ossia che ogni item della
// lista ha sia un puntatore all'item successivo della lista (come già accadeva per le linked list) ma anche un puntatotre
// all'item precedente (doppio collegamento). 
//
// VARIANTE 1 (utilizzo della struttura ausiliaria List) 

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "elemtype.h"

#include <stdbool.h>
#include <stdio.h>

// struttura principale delle liste, l'Item è sostanzialmente l'elemento singolo della lista, 
// come accennato sopra avrà sta volta un doppio collegamento, all'item successivo e precedente 
struct Item {
    ElemType value;
    struct Item *next;
    struct Item *prev;
};
typedef struct Item Item;

// struttura secondaria che dovrebbe rappresentare la lista nella sua interezza, dunque con un puntatore 
// al primo item, un puntatore all'ultimo item e la lunghezza totale della lista, dunque il numero totale 
// di Items presenti nella lista. è sostanzialmente una struttura esterna alla lista, che però ci fornisce 
// informazioni fondamentali su questa
struct List {
    Item *first;
    Item *last;
    size_t len;
};
typedef struct List List;

List *ListCreateEmpty(void);
Item *ListGetFirst(List *l);
Item *ListGetLast(List *l);

void ListInsertHead(const ElemType *e, List *l);
bool ListIsEmpty(const List *l);
void ListInsertBack(List *l, const ElemType *e);
void ListDelete(List *l);

const ElemType *ItemGetValue(const Item *i);
Item *ItemGetNext(const Item *i);
bool ItemIsEmpty(const Item *i);

void ListWrite(const List *l, FILE *f);
void ListWriteStdout(const List *l);

#endif /* DOUBLELIST_H */
