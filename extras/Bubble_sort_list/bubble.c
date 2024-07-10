#include "list.h"

int ListGetLen(Item* i) {
	int res = 0; 
	while (!ListIsEmpty(i)) {
		res++; 
		i = ListGetTail(i); 
	}
	return res; 
}

Item* ListBubbleSort(Item* i) {

	Item fake_head = { .next = i }; 
	int len = ListGetLen(i); 
	bool done = false; 

	while (!done) {
		done = true; 
		Item* prev = &fake_head; 
		Item* curr = prev->next;

		// dal momento che stiamo lavorando on un bubble sort, non ha senso 
		// ogni volta far arrivare curr a NULL, infatti ad ogni giro del while 
		// primario l'ultimo elemento viene messo nella posizione corretta
		for (int i = 0; i < len - 1; ++i) {
			Item* fol = curr->next; 
			Item* folfol = fol->next; 

			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(fol)) > 0) {
				done = false; 
				
				prev->next = fol; 
				fol->next = curr; 
				curr->next = folfol; 

				prev = fol; 
				// nota che curr non dovrà essere aggiornato se viene effettuato lo swap, 
				// perché viene portato avanti e sarà il prossimo elemento da confrontare 
			}
			else { // caso in cui non viene effettuato lo swap
				prev = curr; 
				curr = fol; 
			}
		}
		len--; 
	}
	
	return fake_head.next; 
}