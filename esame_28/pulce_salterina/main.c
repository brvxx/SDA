#include <stdlib.h>
#include <time.h>

#include "pulce.h"

int main(void) {

	ElemType arr[] = { 2, -3, 4, 1, 0, 5, -12, 3 };
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Item* l1 = DListCreateEmpty(); 
	for (size_t i = 0; i < size; ++i) {
		l1 = DListInsertBack(l1, arr + i); 
	}
	printf("lista usata: "); 
	DListWriteStdout(l1); 

	const Item* tmp = l1; 

	// randomizziamo lo start della pulce all'interno della lista
	srand((unsigned)time(NULL));
	int min = 0; 
	int max = (int)size; 
	int start = rand() % (max - min + 1) + min;
	
	// faccio puntare l1 all'item di partenza per la pulce 
	for (int i = 1; i < 3; ++i) {
		tmp = DListGetTail(tmp); 
	}
	printf("\nla pulce parte dall'item della lista numero %d, quindi l'elemento: ", 3); 
	ElemWriteStdout(DListGetHeadValue(tmp)); 
	printf("\n\n");

	// numero massimo di salti che permettiamo di fare alla pulce
	size_t jumps = 13;

	tmp = CalcolaPercorso(tmp, jumps);

	printf("la pulce si e' fermata sull'item dal valore: "); 
	ElemWriteStdout(DListGetHeadValue(tmp)); 
	printf("\n\n"); 

	DListDelete(l1);
	return 0; 
}