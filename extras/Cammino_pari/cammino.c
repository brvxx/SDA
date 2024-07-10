#include "tree.h"

static void cammino_pari_rec(const Node* t, int pari_curr, int sum_curr, int* pari_best, int* somma_best) {
	if (TreeIsEmpty(t)) {
		if ((pari_curr > *pari_best) ||
				(pari_curr == *pari_best && sum_curr > *somma_best)) {
			
			*pari_best = pari_curr; 
			*somma_best = sum_curr; 
		}
		return; 
	}
	if (t->value % 2 == 0) {
		++pari_curr;
	}
	
	cammino_pari_rec(TreeLeft(t), pari_curr, sum_curr + t->value, pari_best, somma_best); 
	cammino_pari_rec(TreeRight(t), pari_curr, sum_curr + t->value, pari_best, somma_best);
}

int cammino_pari(const Node* t) {

	int somma = 0; 
	int pari = -1;

	cammino_pari_rec(t, 0, 0, &pari, &somma); 

	return somma; 
}