// I due prossimi algoritmi implementati all'interno di questo file non sono degli algoritmi di ordinamento, ma sono algoritmi 
// che si appoggiano proprio su questi per poter svolgere certe azioni in modo molto più veloce. 
// l'algoritmo in questione si chiama binary search, il quale viene usato per trovare la posizione di un determinato elemento 
// all'interno di un vettore ordinato. Il fatto che il vettore sia ordinato può sembrare una caratteristica di poco conto in un 
// algoritmo di ricerca, ma non è così; Infatti, possso evitare di andare a scorrere tutto il vettore per trovare l'elemento in 
// questione sfruttando proprio l'ordinamento. 
// Si sceglie un elemento proprio a metà del vettore, che chiameremo an/2, se questo elemento uguale all'elemnto cercato, allora 
// siamo apposto perchè di conseguenza abbiamo ance trovato la posizione dell'elemento che cercavamo, se è maggiore di b (elemento 
// cercato) allora restringo la mia ricerca nel sottovettore che va da 0 ad an/2 - 1 mentre se è minore al sottovettore successivo. 
// Procedendo in questo modo posso iterare il meccanismo di ricerca in modo ricorsivo per poter giungere sicuramente alla soluzione 
// a forza di dimezzare il vettore. 
// 
// il vantaggio di questo procedimento è proprio a livello di complessità temporale, infatti supponendo che il vettore di partenza 
// avesse lunghezzza n, se avessi proceduto con una ricerca standard scorrendo tutto il vettore la complessità sarebbe stata O(n) mentre
// con l'algoritmo di ricerca binaria la complessità cala a O(log(n)) in quanto ad ogni chiamata ricorsiva il vettore viene dimezzato e 
// non diminuito di una unità. 


#include <stdio.h>

#define N 11


// approccio ricorsivo 

int binary_search_rec(int* arr, int first, int last, int target) {
	
	//if (first == last) {				// attenzione!!! questa scrittura è sbagliata, poichè è possibile che first == last non accada mai, esempio: 
	//	if (arr[first] == target) {		// first = 0, last = 1 --> mid = 0, e il vettore è {1, 2} e il target è 0. a questo punto si entrerebbe nella 
	//		return first;				// condizione target < arr[mid] e dunque si chiamerebbe la funzione con first = 0 e last = mid - 1 = - 1 --> il 
	//	}								// programma andrebbe in loop. 
	//	else {
	//		return -1; 
	//	}
	//}

	if (first <= last) { 
		int mid = (first + last) / 2; 
		
		if (target == arr[mid]) {
			return mid; 
		}
		if (target < arr[mid]) {
			return binary_search_rec(arr, first, mid - 1, target); // ovviamente mid lo escludo poichè sicuramente non è l'elemento cercato
		}
		else {	// target > arr[mid]
			return binary_search_rec(arr, mid + 1, last, target);
		}
	}
	return -1; // first ha superato last quindi gli indici si sono incorciati e l'elemento per forza non è nel vettore
}

// approccio iterativo

int binary_search(int* arr, int first, int last, int target) {

	int mid; 

	while (first <= last) {
		mid = (first + last) / 2; 

		if (target == arr[mid]) {
			return mid; 
		}
		if (target < arr[mid]) {
			last = mid - 1;
		}
		else {
			first = mid + 1; 
		}
	}

	return -1; 
}

int main(void) {

	int vec[] = { 1, 2, 3, 4, 5, 11, 12, 14, 14, 19, 21 }; 
	int target = 14; 

	int pos = binary_search(vec, 0, N - 1, target);

	if (pos == -1) {
		printf("l'elemento %d non e' presenta all'interno del vettore", target);
	}
	else {
		printf("l'elemento %d e' presente all'interno della sequenza in posizione %d", target, pos + 1); 
	}

	return 0; 
}