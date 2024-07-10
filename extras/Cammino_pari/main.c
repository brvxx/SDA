// L'obbiettivo di questo programma è dato un albero (Node* t) individuare il cammino con il
// maggior numero di nodi dal valore pari e ritornare la somma di tutti i nodi appartenenti a 
// quel cammino. Nota che con percorso si intende un cammino che vada dalla radice ad una delle 
// foglie. A parità di numeri di elementi pari il cammino da scegliere sarà quello per il quale 
// la somma dei valori dia il risultato maggiore. Dunque se un albero non contiene numeri pari 
// allora tutti i cammini avranno lo stesso numero di pari (0), dunque la funzione ritornerà la 
// il valore del cammino dalla somma maggiore. 

#include "tree.h"

extern int cammino_pari(const Node* t); 

int main(void) {

	ElemType arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	Node* t1 = TreeCreateRoot(arr + 1,
		TreeCreateRoot(arr + 9,
			TreeCreateRoot(arr + 3, NULL, NULL),
			TreeCreateRoot(arr + 5, NULL, NULL)),
		TreeCreateRoot(arr + 1,
			TreeCreateRoot(arr + 3, NULL, NULL),
			TreeCreateRoot(arr + 2, NULL, NULL)));

	TreeWriteStdoutPreOrder(t1);

	int res = cammino_pari(t1);

	printf("la somam dei valori del cammino con piu' numeri pari e': %d", res);

	TreeDelete(t1);

	return 0;
}