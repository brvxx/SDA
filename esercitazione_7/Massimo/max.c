#include "elemtype.h"
#include "list.h"

const ElemType* MaxElement(const Item* i) {
	if (ListIsEmpty(i)) {
		return NULL; 
	}

	// imposto come indirizzo dell'elemento massimo l'indirizzo dell'elemento del primo item 
	const ElemType* max = ListGetHeadValue(i); 
	i = ListGetTail(i);

	// scorro tutta la lista facendo confrontando la testa della lista e l'elemendo all'indirizzo max, se la testa è maggiore 
	// allora max punterà all'elemento della testa di i
	while (!ListIsEmpty(i)) {
		if (ElemCompare(ListGetHeadValue(i), max) > 0) {
			max = ListGetHeadValue(i);
		}
		i = ListGetTail(i);
	}

	return max; 
}

// note sull'esercizio: 
// la complessità computazionale di questo algoritmo sarà O(n), se la lista fosse passata con elementi in ordine crescente la 
// complessità sarebbe comunque O(n) perchè per trovare l'indirizzo dell'elemento con valore maggiore dovrei comunque arrivare 
// all'ultimo elemento della lista, la quale è una struttura dati tale per cui per giungere all'ultimo item dovrei passare necessariamente 
// per tutti gli n - 1 item precedenti. Invece se la lista fosse passata in ordine decrescente la complessità computazionale sarebbe 
// stata costante (pari a 1), basterebbe ritornare il valore della testa della lista (O(n^0) --> complessità costante) 