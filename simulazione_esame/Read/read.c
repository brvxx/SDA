#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "tree.h"

static Node* TreeReadRec(FILE* f) {
	char tmp; 
	int ret = fscanf(f, " %c", &tmp); 

	if (ret != 1) {
		return NULL; 
	}

	if (tmp == '.') { // siamo giunti ad una foglia --> caso base 
		fscanf(f, " %c", &tmp); 
		return TreeCreateRoot(&tmp, NULL, NULL); 
	}

	Node* t = TreeCreateRoot(&tmp, NULL, NULL); 

	t->left = TreeReadRec(f); 
	t->right = TreeReadRec(f); 

	return t; 
}

Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r"); 
	if (f == NULL) {
		return NULL; 
	}
	
	Node* res = TreeReadRec(f); 
	
	fclose(f); 
	return res; 
}