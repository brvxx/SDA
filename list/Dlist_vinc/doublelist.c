#define _CRT_SECURE_NO_WARNINGS
#include "doublelist.h"

#include <string.h>
#include <stdlib.h>

// funzione che crea una LISTA (non un item) vuota
List *ListCreateEmpty(void) {
    List *l = malloc(sizeof(List)); // alloco memoria per la "lista" 
    l->first = NULL;
    l->last = NULL;
    l->len = 0;
    return l;
}

// funzione che ritorna il PUNTATORE AL PRIMO ITEM della lista 
Item *ListGetFirst(List *l) {
    return l->first;
}

// funzione che ritorna il PUNTATORE AL PRIMO ITEM della lista 
Item *ListGetLast(List *l) {
    return l->last;
}

// funzione che mette in testa alla lista un item contenente come campo value l'elemtype passato per parametro, 
// inoltre la funzione inevitabilmente aggiorna la struttura lista
void ListInsertHead(const ElemType *e, List *l) {
   
    // mettiamo apposto l'item 
    Item *n = malloc(sizeof(Item));
    n->value = ElemCopy(e);
    n->next = ListGetFirst(l);
    n->prev = NULL;

    // mettiamo apposto la lista

    // aggiorno il secondo item della lista (ex primo item della lista, dunque item puntato da l->first (ovviamente se esisteva))
    // facendo sì che il suo elemento precedente sia quello appena messo in testa alla lista 
    if (l->first) {
        l->first->prev = n;
    }
    // aggiorno la lunghezza della lista 
    l->len++;
    // aggiorno il primo elemento della lista
    l->first = n;

    // se la lista era vuota, allora il primo elemento ora sarà da considerare anche come ultimo, dunque aggiorno 
    // il campo l->last facendolo puntare a n (item appena inserito in testa alla lista)
    if (!l->last) {
        l->last = n;
    }
}

// predicato che ci dice se la lista è vuota o meno
bool ListIsEmpty(const List *l) {
    return l->len == 0;
}

// funzione che inserisce un item alla fine della lista e aggiorna i puntatori first e last della struttura lista 
// nota che il funzionamento è praticamente identico a quello della inserthead
void ListInsertBack(List *l, const ElemType *e) {
    
    // allochiamo memoria per l'item da inserire 
    Item *n = malloc(sizeof(Item));
    n->value = ElemCopy(e);
    n->next = NULL;
    n->prev = l->last;

    // incrementiamo la lunghezza della lista 
    l->len++;

    // se esiste già un item considerato l'ultimo della lista ora ovviamente non lo sarà più e il suo campo 
    // next putnerà all'item appena aggiunto 
    if (l->last) {
        l->last->next = n;
    }
    
    // SOLO DOPO aver aggiornato l'ex ulitmo elemento possiamo aggiornare l'ultimo elemento della lista 
    l->last = n;

    // se la lista era vuota allora l'ultimo elemento sarà anche il primo 
    if (!l->first) {
        l->first = n;
    }
}

// funzione che libera la memoria allocata per una lista 
void ListDelete(List *l) {
    // prendiamo l'indirizzo del primo item della lista 
    Item *i = ListGetFirst(l);


    while (!ItemIsEmpty(i)) {
        Item *tmp = i;
        
        // passiamo all'item successivo della lista dopo aver salvato in tmp quello corrente
        // per poterlo liberare
        i = i->next; // ItemGetNext(i);
        ElemDelete(&tmp->value);
        free(tmp);
    }
    // ovviamente con l'aggiunta di questa struttura ausiliaria List, dovremo fare un ulteriore free
    free(l);
}


// predicato che ci dice se un item è vuoto o meno 
bool ItemIsEmpty(const Item *i) {
    return i == NULL;
}

// dato un determinato item la funzione ci restituisce un puntatore al campo value dell'item in questione 
const ElemType *ItemGetValue(const Item *i) {
    if (ItemIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetHead()' e' stata passata una lista vuota (NULL).\n");
        exit(1);
    }
    else {
        return &i->value;
    }
}

// funzione che dato un puntatore ad item ci restituisce un puntatore all'item successivo nella lista
Item *ItemGetNext(const Item *i) {
    if (ItemIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetTail()' e' stata passata una lista vuota (NULL).\n");
        exit(2);
    }
    else {
        return i->next;
    }
}


// funzione che scrive su file la lista nella modalità: [a1, a2, a3, a4, ..., an]
void ListWrite(const List *l, FILE *f) {
    fprintf(f, "[");
    Item *i = l->first;
    while (!ItemIsEmpty(i)) {
        ElemWrite(&i->value, f);
        i = ItemGetNext(i);
        if (!ItemIsEmpty(i)) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

// funzione che appoggiandosi alla ListWrite scrive direttamente tutti gli elementi della lista su stdout 
void ListWriteStdout(const List *l) {
    ListWrite(l, stdout);
}