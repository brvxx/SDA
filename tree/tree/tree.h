#ifndef TREE_H 
#define TREE_H 

#include <stdbool.h>

#include "elemtype.h"

struct Node {
	ElemType value; 
	struct Node* left; 
	struct Node* right;
};

typedef struct Node Node; 

// funzioni primitive 
Node* TreeCreateEmpty(void); 
Node* TreeCreateRoot(const ElemType* e, Node* l, Node* r); 
const ElemType* TreeGetRootValue(const Node* n);
Node* TreeLeft(const Node* n);
Node* TreeRight(const Node* n);
void TreeDelete(Node* n);

// predicati 
bool TreeIsEmpty(const Node* n);
bool TreeIsLeaf(const Node* n);

// funzioni non primitive
void TreeWritePreOrder(const Node* n, FILE* f);
void TreeWriteStdoutPreOrder(const Node* n);
void TreeWriteInOrder(const Node* n, FILE* f);
void TreeWriteStdoutInOrder(const Node* n);
void TreeWritePostOrder(const Node* n, FILE* f);
void TreeWriteStdoutPostOrder(const Node* n);

#endif /* TREE_H */