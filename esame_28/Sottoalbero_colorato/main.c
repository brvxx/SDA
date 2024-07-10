#include "tree.h"

extern const Node* BiggestColoredTree(const Node* t);

int main(void) {
	ElemType arr[] = { 'r', 'g', 'b' };

	Node* t = TreeCreateRoot(&(char){'r'}, 
					TreeCreateRoot(&(char){'b'}, 
						TreeCreateRoot(&(char){'b'}, NULL, NULL),
						TreeCreateRoot(&(char){'b'}, 
							NULL, 
							TreeCreateRoot(&(char){'g'}, NULL, NULL))),
					TreeCreateRoot(&(char){'g'}, 
						NULL, 
						TreeCreateRoot(&(char){'g'}, NULL, NULL)));

	TreeWriteStdoutPreOrder(t); 

	const Node* res = BiggestColoredTree(t); 
	
	TreeWriteStdoutPreOrder(res);

	TreeDelete(t); 

	return 0; 
}