#include "tree.h"

// se l'albero è BST senza nessuna altra considerazione allora possiamo dare per buono che 
// valga la proprietà left <= root < right --> dunque andando tutto a destra per cercare il 
// massimo dell'albero, non solo troveremo il nodo massimo, ma se esistessero eventuali altri
// nodi dallo stesso valore la funzione ritorna quello più vicino alla radice (lvl più alto), 
// perché gli eventuali "doppioni" si troverebbero nel livello inferiore a sx del nodo trovato
const ElemType* BstTreeMax(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL; 
	}

	while (!TreeIsEmpty(TreeRight(n))) {
		n = TreeRight(n); 
	}
	return TreeGetRootValue(n); 
}

static void TreeMaxRec(const Node* n, const ElemType** max, int lvl_curr, int* lvl_min) {
	if (TreeIsEmpty(n)) {
		return; 
	}
	if (ElemCompare(TreeGetRootValue(n), *max) > 0 ||
		(ElemCompare(TreeGetRootValue(n), *max) == 0 && lvl_curr < *lvl_min)) {
		*max = TreeGetRootValue(n);
		*lvl_min = lvl_curr; 
	}

	TreeMaxRec(TreeLeft(n), max, lvl_curr + 1, lvl_min); 
	TreeMaxRec(TreeRight(n), max, lvl_curr + 1, lvl_min);

}

const ElemType* TreeMax(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL; 
	}
	const ElemType* max = TreeGetRootValue(n); 
	int lvl_min = 0; 
	TreeMaxRec(n, &max, 0, &lvl_min); 
	return max; 
}
