#include "tree.h"

extern Node* TreeRead(const char* filename);

int main(void) {

	Node* t = TreeRead("Albero1.txt"); 

	TreeWriteStdoutPreOrder(t); 

	TreeDelete(t); 

	return 0; 
}