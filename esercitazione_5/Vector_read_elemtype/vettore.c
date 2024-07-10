#include <stdio.h>
#include <stdlib.h>

#include "vettore.h"
#include "elemtype.h"


Vector* VectorRead(const char* filename) {
	FILE* f = fopen(filename, "r"); 
	if (f == NULL) {
		return NULL; 
	}

	Vector* res = malloc(sizeof(Vector)); 
	res->data = malloc(1 * sizeof(ElemType));
	res->size = 0; 
	res->capacity = 1; 

	size_t i = 0; // indice di scorrimento del vettore di ElemType 
	while (ElemRead(f, res->data + i) == 1) {
		res->size++; 
		if (res->size == res->capacity) {
			res->capacity *= 2; 
			res->data = realloc(res->data, res->capacity * sizeof(ElemType));
		}
		++i; 
	}
	
	fclose(f);
	return res; 
}


Vector* VectorReadSorted(const char* filename) {
	FILE* f = fopen(filename, "r"); 
	if (f == NULL) {
		return NULL; 
	}

	Vector* res = malloc(1 * sizeof(Vector));
	res->data = malloc(1 * sizeof(ElemType)); 
	res->capacity = 1; 
	res->size = 0; 

	ElemType tmp; 
	size_t j, i = 0; 

	while (ElemRead(f, &tmp) == 1) {
		res->size++; 
		if (res->size == res->capacity) {
			res->capacity *= 2; 
			res->data = realloc(res->data, res->capacity * sizeof(ElemType));
		}

		j = i; 

		while (j > 0 && ElemCompare(&tmp, res->data + j - 1) < 0) {
			res->data[j] = ElemCopy(res->data + j - 1);
			j--; 
		}
		res->data[j] = ElemCopy(&tmp);

		ElemDelete(&tmp); 
		++i; 
	}

	fclose(f); 
	return res; 
}