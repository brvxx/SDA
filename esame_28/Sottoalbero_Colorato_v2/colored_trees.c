#include <stdbool.h>

#include "tree.h"

// funzione che verifica che tutti i nodi del sottoalbero t, siano del suo stesso colore (color è proprio il colore del nodo t) 
static bool IsSameColor(const Node* t, int h, int* altezza, int* nodi, char color) {
	if (TreeIsEmpty(t)) {
		if (h > *altezza) {
			*altezza = h; 
		}
		return true; 
	}
	if (*TreeGetRootValue(t) != color) {
		return false; 
	}
	(*nodi)++; 
	
	return IsSameColor(TreeLeft(t), h + 1, altezza, nodi, color) && IsSameColor(TreeRight(t), h + 1, altezza, nodi, color);

}

static void BiggestColoredTreeRec(const Node* t, const Node** res, int* altezza_max, int* nodi_max) {
	if (TreeIsEmpty(t)) {
		return; 
	}

	int altezza_curr = 0; 
	int nodi_curr = 0; 
	bool same_color = IsSameColor(t, 0, &altezza_curr, &nodi_curr, *TreeGetRootValue(t)); 

	if (same_color) { // abbiamo trovato una soluzione, verifichiamo sia la migliore
		if ((nodi_curr > *nodi_max) ||
				(nodi_curr == *nodi_max && altezza_curr > *altezza_max)) {

			// aggiorniamo la soluzione migliore se ne abbiamo trovata una più buona 
			*res = t; 
			*nodi_max = nodi_curr; 
			*altezza_max = altezza_curr; 
		}
		return; 
	}

	BiggestColoredTreeRec(TreeLeft(t), res, altezza_max, nodi_max); 
	BiggestColoredTreeRec(TreeRight(t), res, altezza_max, nodi_max);
}

const Node* BiggestColoredTree(const Node* t) {

	const Node* res = NULL; 

	int altezza_max = 0; 
	int nodi_max = 0; 

	BiggestColoredTreeRec(t, &res, &altezza_max, &nodi_max); 

	return res; 
}