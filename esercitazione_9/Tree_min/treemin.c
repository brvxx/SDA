#include "tree.h"

// se l'albero è BST senza nessuna altra considerazione allora possiamo dare per buono che 
// valga la proprietà left <= root < right --> dunque andando tutto a sinistra per cercare il 
// minimo dell'albero, non solo troveremo il nodo minimo, ma se esistessero eventuali altri
// nodi dallo stesso valore la funzione ritorna quello più lontano dalla radice (lvl più basso), 
// perché gli eventuali "doppioni" si troverebbero nei livelli superiori rispetto al nodo trovato 
const ElemType* BstTreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	while (!TreeIsEmpty(TreeLeft(n))) {
		n = TreeLeft(n);
	}
	return TreeGetRootValue(n);
}

static void TreeMinRec(const Node* n, const ElemType** min, int lvl_curr, int* lvl_max) {
	if (TreeIsEmpty(n)) {
		return;
	}
	if (ElemCompare(TreeGetRootValue(n), *min) < 0 ||
		(ElemCompare(TreeGetRootValue(n), *min) == 0 && lvl_curr > *lvl_max)) {
		*min = TreeGetRootValue(n);
		*lvl_max = lvl_curr;
	}

	// facciamo prima la chiamata a destra perché dovremmo ritornare il nodo più
	// a destra
	TreeMinRec(TreeRight(n), min, lvl_curr + 1, lvl_max);
	TreeMinRec(TreeLeft(n), min, lvl_curr + 1, lvl_max);

}

const ElemType* TreeMin(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	const ElemType* min = TreeGetRootValue(n);
	int lvl_max = 0;
	TreeMinRec(n, &min, 0, &lvl_max);
	return min;
}
