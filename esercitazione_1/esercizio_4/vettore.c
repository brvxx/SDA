#include "vettore.h"

void Push(struct vettore* v, int d) {
	v->size++;
	v->data = realloc(v->data, v->size * sizeof(int));
	v->data[v->size - 1] = d; 
}

int Pop(struct vettore* v) {
	
	int res = v->data[0];
	v->size--;
	memmove(v->data, v->data + 1, v->size * sizeof(int));
	v->data = realloc(v->data, v->size * sizeof(int));

	return res;
}