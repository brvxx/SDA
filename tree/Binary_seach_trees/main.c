// in questo file implementiamo qualche algoritmo per la gestione degli alberi binari 
// di ricerca, ossia quegli alberi i cui elementi sono disposti in maniera ordinata. 
// infatti OGNI nodo è tale che tutti i nodi del suo sottoalbero di sinistra (ovviamente
// se non è foglia) avranno valore minore o uguale al suo, mentre tutti i nodi del sottoalbero 
// di destra avranno valore strettamente maggiore del suo. 

#include <stdbool.h>
#include <stdlib.h>

#include "tree.h"

Node* TreeCreateFromVectorRec(const int* arr, size_t size, int i) {
	// caso base, sto provando ad aggiungere un nodo ma non ci sono 
	// più elementi del vettore da aggiungere. 
	if (i >= size) {
		return NULL;
	}

	Node* l = TreeCreateFromVectorRec(arr, size, i * 2 + 1);
	Node* r = TreeCreateFromVectorRec(arr, size, i * 2 + 2);

	return TreeCreateRoot(arr + i, l, r);
}

Node* TreeCreateFromVector(const int* arr, size_t size) {
	return TreeCreateFromVectorRec(arr, size, 0);
}

// funzione che dato un elemtype ti dice se questo è presente come valore in un qualche 
// nodo dell'albero passato per parametro
bool BstSearch(const ElemType* e, const Node* n) {
	bool res = false; 
	
	while (!TreeIsEmpty(n)) {
		if (ElemCompare(e, TreeGetRootValue(n)) == 0) {
			res = true; 
			break; 
		}

		// se l'elemento da cercare è STRETTAMENTE minore del nodo corrente allora 
		// dobbiamo continuare la ricerca a sinistra, ossia nel sottoalbero contenente 
		// nodi dal valore minore del nodo corrente
		if (ElemCompare(e, TreeGetRootValue(n)) < 0) {
			n = TreeLeft(n); 
		}
		else {	// elemento da cercare maggiore in valore del nodo corrente 
			n = TreeRight(n); 
		}
	}

	// se l'elemento non viene trovato allora res sarà false
	return res; 
}

// stessa funzione di ricerca ma con approccio ricorsivo
bool BstSearchRec(const ElemType* e, const Node* n) {
	// casi base
	if (TreeIsEmpty(n)) {
		return false; 
	}
	if (ElemCompare(e, TreeGetRootValue(n)) == 0) {
		return true;
	}

	// processo ricorsivo 
	if (ElemCompare(e, TreeGetRootValue(n)) < 0) {
		return BstSearchRec(e, TreeLeft(n));
	}
	else {
		return BstSearchRec(e, TreeRight(n)); 
	}
}


// funzione che dato un albero BST ritorna un puntatore all'elemento di valore
// massimo
ElemType* BstMax(Node* n) {
	if (TreeIsEmpty(n)) {
		printf("ERROR: Alla funzione 'BstMax()' e' stato passato un albero vuoto (NULL).\n");
		exit(1);
	}
	// ovviamente vado solo a destra perché l'elemento più grande sarà
	// quello più a destra di tutti
	while (!TreeIsEmpty(TreeRight(n))) {
		n = TreeRight(n); 
	}
	return &n->value; 
}

// funzione che dato un albero BST ritorna un punatotre all'elemento di valore 
// minimo

ElemType* BstMin(Node* n) {
	if (TreeIsEmpty(n)) {
		printf("ERROR: Alla funzione 'BstMin()' e' stato passato un albero vuoto (NULL).\n");
		exit(1);
	}

	while (!TreeIsEmpty(TreeLeft(n))) {
		n = TreeLeft(n); 
	}
	return &n->value; 
}

// funzione che inserisce un nuovo nodo all'interno dell'albero contenente il
// valore passato come parametro. ovviamente l'inserimento deve rispettare l'ordinamento 
// BST
Node* BstInsert(const ElemType* e, Node* n) {
	Node* tmp = n; 

	while (!TreeIsEmpty(tmp)) {
		if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
			if (TreeIsEmpty(TreeLeft(tmp))) {
				tmp->left = TreeCreateRoot(e, NULL, NULL); 
				break; 
			}
			tmp = TreeLeft(tmp); 
		}
		else {	// elemento maggiore rispetto a quello del nodo corrente 
			if (TreeIsEmpty(TreeRight(tmp))) {
				tmp->right = TreeCreateRoot(e, NULL, NULL);
				break;
			}
			tmp = TreeRight(tmp);
		}

	}
	return n; 
}

// Altra funzione di inserimento ordinato ma con approccio ricorsivo
Node* BstInsertRec(const ElemType* e, Node* n) {
	// caso base 
	if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL); 
	}

	if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
		n->left = BstInsertRec(e, TreeLeft(n)); 
	}
	else {
		n->right = BstInsertRec(e, TreeRight(n));
	}
	// man mano che risalgo la ricorsione ritorno sottoalberi
	// che conterranno anche l'elemento d'aggiungere
	return n; 
}

int main(void) {

	int arr[] = { 6, 3, 7 , 1, 5, 8 ,9, 0, 2, 4 }; // scritto già ordinato affinché sia BST 
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Node* res = TreeCreateFromVector(arr, size);

	TreeWriteStdoutPreOrder(res);
	TreeWriteStdoutPostOrder(res);
	TreeWriteStdoutInOrder(res);
	printf("\n"); 

	// search 
	ElemType test = 9; 
	bool pres = BstSearchRec(&test, res);

	pres ? printf("il valore %d e' presente all'interno dell'albero", test) : printf("il valore %d NON e' presente all'interno dell'albero", test); 
	printf("\n\n"); 

	// search max/min 

	ElemType* max = BstMax(res); 
	ElemType* min = BstMin(res); 

	printf("il valore max e il min dell'albero sono rispettivamente: \n");
	ElemWriteStdout(max); 
	printf("\n");
	ElemWriteStdout(min); 
	printf("\n\n");

	// insert oridinato
	ElemType test_1 = 6;
	res = BstInsertRec(&test_1, res);
	TreeWriteStdoutInOrder(res); 

	TreeDelete(res);

	return 0;
}