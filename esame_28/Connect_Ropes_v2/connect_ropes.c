#include "minheap.h"

size_t ConnectRopes(Heap* ropes) {
	size_t sum = 0; 

	
	while (ropes->size > 1) {
		int rope1 = 0; 
		int rope2 = 0; 

		// metto in rope1 la corda dalla lunghezza minore 
		rope1 = ropes->data[0]; 

		// swappo l'ultima corda con la prima e decremento la size, perch� la prima corda
		// non far� pi� parte della minheap ed effettuo una movedown sulla corda messa in 
		// prima posizione affinch� torni nella posizione corretta nella heap
		ropes->data[0] = ropes->data[ropes->size - 1]; 
		ropes->size--;
		HeapMinMoveDown(ropes, 0);

		// ora posso prendere la seconda corda pi� corta che si trover� sempre in prima posizione 
		rope2 = ropes->data[0]; 

		// sommo le corde 1 e 2, il risultato lo sovrascrivo alla ex corda 2 che tanto non esiste pi�
		// effettuo ancora una movedown
		rope2 += rope1; 
		sum += rope2; 
		 
		ropes->data[0] = rope2; 
		HeapMinMoveDown(ropes, 0); 
	}

	return sum;
}