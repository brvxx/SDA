#include "minheap.h"

size_t ConnectRopes(Heap* ropes) {
	size_t sum = 0; 

	
	while (ropes->size > 1) {
		int rope1 = 0; 
		int rope2 = 0; 

		// metto in rope1 la corda dalla lunghezza minore 
		rope1 = ropes->data[0]; 

		// swappo l'ultima corda con la prima e decremento la size, perchè la prima corda
		// non farà più parte della minheap ed effettuo una movedown sulla corda messa in 
		// prima posizione affinchè torni nella posizione corretta nella heap
		ropes->data[0] = ropes->data[ropes->size - 1]; 
		ropes->size--;
		HeapMinMoveDown(ropes, 0);

		// ora posso prendere la seconda corda più corta che si troverà sempre in prima posizione 
		rope2 = ropes->data[0]; 

		// sommo le corde 1 e 2, il risultato lo sovrascrivo alla ex corda 2 che tanto non esiste più
		// effettuo ancora una movedown
		rope2 += rope1; 
		sum += rope2; 
		 
		ropes->data[0] = rope2; 
		HeapMinMoveDown(ropes, 0); 
	}

	return sum;
}