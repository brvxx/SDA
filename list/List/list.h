// Questo file contiene tutte le dichiarazioni delle funzioni che definiscono l'ADT Lista

#ifndef LIST_H
#define LIST_H 

#include <stdio.h>
#include <stdbool.h>

#include "elemtype.h"

struct Item {
	ElemType value;
	struct Item* next; 
};

typedef struct Item Item; 

// funzioni primitive
Item* ListCreateEmpty(void); 
Item* ListInsertHead(const ElemType* e, Item* i);
const ElemType* ListGetHeadValue(Item* i); 
Item* ListGetTail(const Item* i); 

// funzioni non primitive
Item* ListInsertBack(const ElemType* e, Item* i); 
void ListDelete(Item* i);
void ListWrite(const Item* i, FILE* f); 
void ListWriteStdout(const Item* i); 

// predicati 
bool ListIsEmpty(const Item* i); 

#endif /* LIST_H */


