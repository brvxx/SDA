#include "minheap.h"

size_t ConnectRopes(Heap* ropes) {

	size_t costo = 0; 
	
	size_t rope1 = 0;
	size_t rope2 = 0; 
	size_t new_rope = 0; 

	while (ropes->size > 1) {
		rope1 = ropes->data[0];
		ElemSwap(HeapGetNodeValue(ropes, 0), HeapGetNodeValue(ropes, (int)ropes->size - 1)); 
		--ropes->size; 
		HeapMinMoveDown(ropes, 0); // riporto alla sua posizione l'elemento messo in testa --> costo O(logn) (costo movedown) 
		
		rope2 = ropes->data[0]; 
		new_rope = rope1 + rope2; 
		
		costo += new_rope; 
		
		ropes->data[0] = (int)new_rope;
		HeapMinMoveDown(ropes, 0); // porto in poizione corretta la nuova corda che sovrascriverà il valore della ex rope 2 --> costo O(logn) 
	}

	return costo; 
}	

// dal momento che il while gira esattamente n - 1 volte e che il costo del blocco di comandi all'interno del for è somma di costi che asintoticamente 
// sono al massimo log2n, il costo totale della procedura sarà O(n*log2n)