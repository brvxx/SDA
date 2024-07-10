 /*
 In questo file implementiamo un algoritmo di sorting (selection sort) ma non applicato ad un vettore, bensì ad una 
 lista. Quello che andremo a fare non è modificare il valore dei vari item in modo tale che alla fine la lista risulti 
 oridnata, ma andremo ad aggiornare i vari puntatori in modo tale che alla fine del processo la lista sia ordinata, senza 
 che il campo value di nessun item sia stato modificato. L'unica cosa che verrà modificata dei vari item sarà il campo 
 next. 
 
 L'algoritmo di sorting in questo caso sarà un selection sort applicato portando a sinistra tutte le volte l'item con il campo 
 value dal valore minimo.
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
	Item* head = &fake_head; // head è un puntatore al ultimo elemento ordinato della lista, allo start sarà la fake_head

	for (int j = 0; j < len - 1; ++j) {
		Item* min_prev = head;		// min_prev è il puntatore all'item precedente di min 
		Item* min = min_prev->next; // min è il puntatore all'item di valore minimo nella lista (SENZA CONSIDERARE GLI ITEMS GIA' ORDINATI)
		Item* prev = min;			// puntatore all'item precedente di quello corrente
		Item* curr = prev->next;		// puntatore all'item corrente 
			
		while (!ListIsEmpty(curr)) {
			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(min)) < 0) {
				min = curr; 
				min_prev = prev; 
			}

			prev = curr;
			curr = curr->next;
		}
		if (min_prev != head) {
			min_prev->next = min->next; 
			min->next = head->next; 
			head->next = min; 
		}
		// la testa ora sarà il prossimo elemento, ossia quello che abbiamo appena 
		// ordinato 
		head = head->next; 
		ListWriteStdout(fake_head.next);
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