#include "elemtype.h"
#include "list.h"

const ElemType* MaxElement(const Item* i) {
	if (ListIsEmpty(i)) {
		return NULL; 
	}

	// imposto come indirizzo dell'elemento massimo l'indirizzo dell'elemento del primo item 
	const ElemType* max = ListGetHeadValue(i); 
	i = ListGetTail(i);

	// scorro tutta la lista facendo confrontando la testa della lista e l'elemendo all'indirizzo max, se la testa � maggiore 
	// allora max punter� all'elemento della testa di i
	while (!ListIsEmpty(i)) {
		if (ElemCompare(ListGetHeadValue(i), max) > 0) {
			max = ListGetHeadValue(i);
		}
		i = ListGetTail(i);
	}

	return max; 
}

// note sull'esercizio: 
// la complessit� computazionale di questo algoritmo sar� O(n), se la lista fosse passata con elementi in ordine crescente la 
// complessit� sarebbe comunque O(n) perch� per trovare l'indirizzo dell'elemento con valore maggiore dovrei comunque arrivare 
// all'ultimo elemento della lista, la quale � una struttura dati tale per cui per giungere all'ultimo item dovrei passare necessariamente 
// per tutti gli n - 1 item precedenti. Invece se la lista fosse passata in ordine decrescente la complessit� computazionale sarebbe 
// stata costante (pari a 1), basterebbe ritornare il valore della testa della lista (O(n^0) --> complessit� costante) 