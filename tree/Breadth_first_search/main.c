// In questo file andremo ad implementare la visita di un albero per ampiezza, ossia
// visiteremo e scriveremo in output tutti i nodi dell'albero procedendo livello per livello. 
// Questo tipo di visita per essere effettuata al meglio necessita di appoggiarsi ad una 
// struttura dati ausiliaria, quale la coda, sostanzialmente una lista in cui vale il principio
// FIFO (first-in, first-out) ossia che il primo elemento che uscirà dalla coda sarà proprio 
// il primo elemento ad essere stato messo nella coda (l'opposto del principio di funzionamento 
// di uno stack) 

#include "stdlib.h"

#include "queue.h"

void TreeWriteBreadthFirst(const Node* t, FILE* f) {
	ItemQ* queue = QueueCreateEmpty(); 

	// Creazione di un ElemTypeQ temporaneo per non avere warnings dovuti alla constness
	ElemTypeQ* root = &t; 

	// inserimento del primo nodo dell'albero nella coda, nota che dal momento che 
	// l'elemtypeQ della coda sono proprio Node*, allora dovendo passare un puntatore
	// a elemtypeQ allora passerò l'indirizzo di t  

	fprintf(f, "Albero in ampiezza: "); 

	// se l'albero è vuoto allora non facciamo nulla 
	if (t == NULL) {
		fprintf(f, "vuoto!\n"); 
		return;
	}

	queue = Enqueue(root, queue);
	ItemQ* q = queue; // puntatore alla testa della coda, ci servirà per liberare alla fine la coda  
	while (!QueueIsEmpty(queue)) {
		Node* tmp = *QueueTop(queue); 
		// stampo il valore del node in testa alla coda 
		fprintf(f, "\t");
		ElemWrite(TreeGetRootValue(tmp), f); 

		// "togliamo" il primo ItemQ della coda dalla coda
		queue = Dequeue(queue); 

		t = tmp;
		// incodiamo se esistono i due figli della testa della coda (Se esistono) 
		tmp = TreeLeft(t);
		if (!TreeIsEmpty(tmp)) {
			queue = Enqueue(&tmp, queue);
		}
		tmp = TreeRight(t); 
		if (!TreeIsEmpty(tmp)) {
			queue = Enqueue(&tmp, queue); 
		}
	}
	fprintf(f, "\n"); 
	QueueDelete(q);
}

Node* TreeCreateFromVectorRec(const int* arr, size_t size, int i) {
	// caso base, sto provando ad aggiungere un nodo ma non ci sono 
	// più elementi del vettore da aggiungere. 
	if (i >= size) {
		return NULL;
	}

	Node* l = TreeCreateFromVectorRec(arr, size, i * 2 + 1); 
	Node* r = TreeCreateFromVectorRec(arr, size, i * 2 + 2); 

	return TreeCreateRoot(arr + i, l, r);
}

Node* TreeCreateFromVector(const int* arr, size_t size) {
	return TreeCreateFromVectorRec(arr, size, 0);
}



int main(void) {

	int arr[] = { 0, 1, 2 , 3, 4, 5 ,6, 7, 8, 9 }; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	Node* res = TreeCreateFromVector(arr, size);

	TreeWriteStdoutPreOrder(res); 
	TreeWriteStdoutPostOrder(res); 
	TreeWriteStdoutInOrder(res); 
	TreeWriteBreadthFirst(res, stdout); 

	TreeDelete(res); 

	return 0; 
}