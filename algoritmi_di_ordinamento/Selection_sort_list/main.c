 /*
 In questo file implementiamo un algoritmo di sorting (selection sort) ma non applicato ad un vettore, bensì ad una 
 lista. Quello che andremo a fare non è modificare il valore dei vari item in modo tale che alla fine la lista risulti 
 oridnata, ma andremo ad aggiornare i vari puntatori in modo tale che alla fine del processo la lista sia ordinata, senza 
 che il campo value di nessun item sia stato modificato. L'unica cosa che verrà modificata dei vari item sarà il campo 
 next. 
 
 L'algoritmo di sorting in questo caso sarà un selection sort applicato portando a destra tutte le volte l'item con il campo 
 value dal valore massimo, nell'altro file procederemo mettendo l'item di valore minore tutto a sinistra.
 */

#include "list.h"

int ListGetLen(const Item* i) {
	int res = 0; 
	while (!ListIsEmpty(i)) {
		++res; 
		i = ListGetTail(i); 
	}
	return res; 
}

Item* NaiveSortList(Item* i) {
	int len = ListGetLen(i); 
	// item fittizio che è come se stesse prima della testa, ci aiuterà un sacco per evitare di gestire 
	// casi che coinvolgono la vera testa della lista 
	Item fake_head = { .next = i }; 

	// il for procede fino a len - 1, perché tanto ordinando i primi n - 1 numeri l'ultimo sarà già ordinato 
	for (int k = 0; k < len - 1; ++k) {
		Item* prev_max = &fake_head;	// puntatore al item precedente del massimo 
		Item* max = prev_max->next;		// puntatore all'item dal valore massimo 
		Item* curr = max->next;			// puntatore all'item corrente 
		Item* prev = max;				// puntatore all'item precedente di quello corrente

		// facciamo partire j da 1 perchè ovviamente il curr no partirà dal primo elemento ma dal secondo 
		// in quanto il primo ipotizziamo sia massimo all'inizio, per evitare di fare un confronto inutile 
		// tra curr e max. inoltre j andrà fino a len - k, perchè a ogni giro del for primario avremo sempre 
		// un elemento in più a fine della lista già ordinato da NON TOCCARE. 
		for (int j = 1; j < len - k; ++j) {
			// confronto tra l'item corrente e il massimo, se curr è maggiore allora aggiorniamo max e max_prev
			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(max)) > 0) {
				max = curr; 
				prev_max = prev; 
			}

			// ci spostiamo alla coppia di item della lista successivi 
			prev = curr; 
			curr = curr->next; 
		}

		// se prev == max allora l'elemento massimo si trova già in posizione corretta --> non faccio nulla, altrimenti 
		// vado a mettere appopsto i collegamenti 
		if (prev != max) {				
			prev_max->next = max->next;	
			prev->next = max; 
			max->next = curr; 
		}
		
		/*ListWriteStdout(fake_head.next);  --> x debug */
	}

	return fake_head.next; 
}

int main(void) {

	ElemType arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty(); 
	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i); 
	}
	ListWriteStdout(l1); 
	l1 = NaiveSortList(l1); 
	ListWriteStdout(l1); 

	ListDelete(l1);

	return 0; 
}