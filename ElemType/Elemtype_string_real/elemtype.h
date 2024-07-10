// Questo file conterrà tutte le dichiarazioni delle funzioni usate e le definizioni dei nuovi tipi usati 

#ifndef ELEMTYPE_H
#define ELEMTYPE_H

#include <stdlib.h>

typedef struct {
	size_t size;		// lunghezza della stringa
	char* data;			// vettore di char
} string;

typedef string ElemType;  // introduciamo finalmente l'elemtype come tipo generico --> in questo caso "maschera" il tipo string


// tutte le funzioni sono rinominate per essere pure loro universali, così quando si cambierà il tipo di dato nascosto da ElemType andrò solo a cambiare le loro implementazioni 

ElemType ElemCopy(const ElemType* e);
int ElemCompare(const ElemType* a, const ElemType* b);
void ElemSwap(ElemType* a, ElemType* b);
void ElemDelete(ElemType* e);


#endif /* ELEMTYPE_H */