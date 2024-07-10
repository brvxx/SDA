// Questo file conterr� tutte le dichiarazioni delle funzioni usate e le definizioni dei nuovi tipi usati 

#ifndef ELEMTYPE_H
#define ELEMTYPE_H

#include <stdlib.h>

typedef int ElemType;  // introduciamo finalmente l'elemtype come tipo generico --> in questo caso "maschera" il tipo int


// tutte le funzioni sono rinominate per essere pure loro universali, cos� quando si cambier� il tipo di dato nascosto da ElemType andr� solo a cambiare le loro implementazioni 

ElemType ElemCopy(const ElemType* e);
int ElemCompare(const ElemType* a, const ElemType* b);
void ElemSwap(ElemType* a, ElemType* b);
void ElemDelete(ElemType* e);


#endif /* ELEMTYPE_H */
