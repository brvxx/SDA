#ifndef VECTOR_H 
#define VECTOR_H 

#include <stdlib.h>

#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

Vector* VectorRead(const char* filename);
Vector* VectorReadSorted(const char* filename);

#endif /* VECTOR_H */