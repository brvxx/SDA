// Questo file contiene tutte le dichiarazioni delle funzioni necessarie per lavorare su il tipo di dato opaco ElemType

#ifndef ELEMTYPE_H
#define ELEMTYPE_H

#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;  // in questo caso il tipo "mascherato" da elemtype è proprio un int (poco utile come cosa) 


// dichiarazioni delle primitive del tipo Elemtype 

ElemType ElemCopy(const ElemType* e);
int ElemCompare(const ElemType* a, const ElemType* b);
void ElemSwap(ElemType* a, ElemType* b);
void ElemDelete(ElemType* e);
void ElemWrite(const ElemType* e, FILE* f);
void ElemWriteStdout(const ElemType* e);


#endif /* ELEMTYPE_H */
