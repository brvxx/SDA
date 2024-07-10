#include "sum_dlist.h"

const Item* DlistGetLast(const Item* i) {
	if (DListIsEmpty(i)) {
		return NULL; 
	}
	while (!DListIsEmpty(DListGetTail(i))) {
		i = DListGetTail(i); 
	}
	return i; 
}

Item* DListSum(const Item* i1, const Item* i2) {
	
	Item* res = DListCreateEmpty(); 
	
	i1 = DlistGetLast(i1); 
	i2 = DlistGetLast(i2); 

	int add_1 = 0; 
	int add_2 = 0; 
	int sum = 0; 
	int carry = 0; 

	while (!DListIsEmpty(i1) || !DListIsEmpty(i2)) {
		add_1 = 0; 
		add_2 = 0; 
		if (!DListIsEmpty(i1)) {
			add_1 = i1->value; 
		}
		if (!DListIsEmpty(i2)) {
			add_2 = i2->value;
		}
		if(carry){
			// aggiungo il riporto al primo addendo
			add_1 += 1;
			carry--; 
		}
		
		sum = add_1 + add_2; 
		// se il valore della somma delle cifre correnti 
		// è strettamente maggiore di 9 allora avremo il 
		// riporto alla somma successiva
		if (sum > 9) {
			sum %= 10; 
			++carry; 
		}
		// aggiungo il valore della somma delle due cifre 
		// alla nuova lista risultato 
		res = DListInsertHead(&sum, res); 
		
		if (!DListIsEmpty(i1)) {
			i1 = DListGetPrev(i1); 
		}
		if (!DListIsEmpty(i2)) {
			i2 = DListGetPrev(i2);
		}

	}
	// aggiungo il caso in cui ho il resto nell'ultima somma di cifre
	if (carry) {
		res = DListInsertHead((ElemType[]) { 1 }, res);
	}

	return res; 
}