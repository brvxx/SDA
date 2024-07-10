// Questo file contiene tutte le implementazioni delle funzioni dichiarate nel relativo .h

#include <stdlib.h>

#include "list.h"


// funzione che "crea" una lista vuota, sostanzialmente ritorna un puntatore a NULL 

Item* ListCreateEmpty(void) {
	return NULL; 
}



// funzione che ci permettere di aggiungere un Item in testa alla lista, � sostanzialmente 
// la funzione costruttrice della lista (alloca memoria) 

Item* ListInsertHead(const ElemType* e, Item* i) {
	Item* t = malloc(sizeof(Item)); 
	t->value = ElemCopy(e);  // copio l'ElemType passato per riferimento dentro il valore dell'Item in testa 
	t->next = i; 
	return t; 
}



// funzione che ritorna il valore della testa della lista 

const ElemType* ListGetHeadValue(Item* i) {
	if (ListIsEmpty(i)) {
		printf("ERROR: alla funzione ' ListGetHeadValue' � stata passata una lista"
			"vuota (null pointer)\n");
		exit(1); 
	}
	else {
		return &i->value;
	}
}



// funzione che ritorna la lista passata ma privata della testa

Item* ListGetTail(const Item* i) {
	if (ListIsEmpty(i)) {
		printf("ERROR: alla funzione ' ListGetTail' � stata passata una lista"
			"vuota (null pointer)\n");
		exit(2);
	}
	else {
		return i->next; 
	}
}



// funzione che inserisce un nuovo elemento nella lista per� alla fine, nota che in quanto funzione di inserimento 
// sar� considerata una funzione costruttrice e quindi anche esssa alloca memoria 

Item* ListInsertBack(const ElemType* e, Item* i) {
	Item* n = ListInsertHead(e, ListCreateEmpty()); // alloco memoria per l'Item attraverso la InsertHead

	if (ListIsEmpty(i)) {
		return n; 
	}

	Item* tmp = i;  // dovendo scorrere la lista fino in fondo ho bisogno di salvarmi l'indirizzo della testa --> uso una var temporanea 

	while (!ListIsEmpty(ListGetTail(tmp))) {	// va avanti finch� non arriva ad una lista di 1 elemento 
		tmp = ListGetTail(tmp); 
	}
	tmp->next = n;
	return i; 
}



// funzione che libera la memoria allocata per la lista e i vari values di ogni Item (perch� nella insert si fa uso della ElemCopy) 

void ListDelete(Item* item) {
	while (!ListIsEmpty(item)) {
		Item* tmp = item;
		item = ListGetTail(item);			// i = i->next
		ElemDelete(&tmp->value);	// libero la memoria allocata per l'ElemType
		free(tmp);					// libero la memoria allocata per l'Item 
	}
}



// funzione che scrive su file tutti gli elmenti della lista

void ListWrite(const Item* i, FILE* f) {
	fprintf(f, "[");  
	
	while (!ListIsEmpty(i)) {
		ElemWrite(&i->value, f); 
		i = ListGetTail(i); 
		if (!ListIsEmpty(i)) {
			fprintf(f, ", "); 
		}
	}
	fprintf(f, "]\n");
}



// funzione che scrive tutti gli elementi di una lista su stdout 

void ListWriteStdout(const Item* i) {
	ListWrite(i, stdout);
}



// predicato che ci dice se la lista passata sia vuota o meno 
// ritorna 1 se la lista � vuota, 0 altrimenti 

bool ListIsEmpty(const Item* i) {
	return i == NULL; // se l'espressione � vera vale 1, 0 altrimenti
}