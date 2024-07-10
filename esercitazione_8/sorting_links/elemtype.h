#ifndef ELEMTYPE_ADRESS_H 
#define ELEMTYPE_ADRESS_H 

#include <stdio.h>
#include <string.h>

struct Address {
    char name[40];
    char street[50];
    int  number;
    char city[30];
    char province[3];
    char postal_code[6];
};
typedef struct Address ElemType;

// Elemcompare ritorna il risultato della strcmp perché andiamo a confrontare 2 indirizzi 
// in base all'ordine alfabetico del campo nome di ogni Adress
int ElemCompare(const ElemType* e1, const ElemType* e2);


// la funzione ElemCopy non varia rispetto a quella usate per elemtype int, infatti la struct 
// Adress è composta da array statici e non allocati dinamicamente, dunque quando effettuiamo 
// l'operazione tra due struct Adress quello che succede di default è che si venga a creare una 
// copia di questi array, mentre se fossero stati allocati dinamicamente con l'assegnamento semplicemente 
// si andava a copiare l'indirizzo della zona di memoria contenente i dati. 
ElemType ElemCopy(const ElemType* e);

void ElemSwap(ElemType* e1, ElemType* e2);

// non essendoci memoria allocata dinamicamente non ci sarà bisogno di effettuare nessuna free
void ElemDelete(ElemType* e);

void ElemWrite(const ElemType* e, FILE* f);
void ElemWriteStdout(const ElemType* e);


#endif /* ELEMTYPE_ADRESS_H */