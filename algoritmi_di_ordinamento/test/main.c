// Metto all'interno di questo progetto una serie di algoritmi che sostanzialmente servono 
// per cercare un determinato elemento all'interno di un'vettore, ma non uno qualsiasi, bensì
// uno già ordinato. Grazie a questo espediente noi siamo in grado di velocizzare a livello 
// temporale notevolmente la ricerca. Il meccanismo di funzionamento è il seguente, se ho una 
// sequenza ordinata di elementi A = { a1, a2, ... , an } tali che a1 <= a2 <= ... <= an , allora 
// se b è l'elemento che voglio cercare all'interno di A, mi basterà prendere l'elemento esattamente 
// a metà della sequenza e confrontarlo con b. Se sono uguali allora so che b appartiene alla 
// sequenza e so pure la sua posizione, mentre se b < an/2 andrò a rieffetuare la ricerca nella 
// sottosequeza di sinistra , se b > an/2 in quella di destra, reiterando questo processo fino a 
// trovare un solo elemento che può essere b se b apparteneva alla sequenza, se no sarà qualcos'altro 

#include <stdio.h> 

#define N 9 

int BinSearchRec(int A[], int first, int last, int target) {

	if (first <= last) {
		int mid = (first + last) / 2; 
		int middle = A[mid];
		if (middle == target) {			// caso base --> b trovato 
			return mid;
		}
		else if (middle < target) {		// cerco a destra
			return BinSearchRec(A, mid + 1, last, target);		// ogni volta aumentiamo first
		}
		else {							// cerco a sinistra		
			return BinSearchRec(A, first, mid - 1, target);		// ogni volta diminuiamo last 
		}
	}
	return -1;
}

// stessa funzione ma non ricorsiva --> utilizzo di un ciclo  

int BinSearch(int A[], int first, int last, int target) {

	int mid, middle;
	while (first <= last) {
		mid = (first + last) / 2; // mediana
		middle = A[mid];
		if (middle == target) {
			return mid; // trovato
		}
		else if (middle < target) { // cerco a destra
			first = mid + 1;
		}
		else {		// cerco a sinistra
			last = mid - 1;
		}

	}
	return -1; // non trovato
}



// Questo invece è un algoritmo che sfrutta sempre la ricerca binaria ma per trovare il limite inferiore di un certo elemento
// target 

int lower_bound(int arr[], int first, int last, int target)
{
	int mid;
	int low = first;
	int high = last;


	while (low < high) {

		mid = (low + high)/ 2;		// trovo la mediana del vettore (elemento di mezzo) 

		if (target <= arr[mid]) {	// se l'elemento di mezzo è maggiore o uguale, allora questo diventa il nuovo estremo superiore
			high = mid;				// nota che non sarà mid - 1 perchè mid potrebbe essere appunto uguale a target e dobbiamo preservare la posizione 
		}
		else {						// se target > arr[mid] sostanzialmente tutte le posizioni da mid COMPRESO in poi possiamo ignorarle 
			low = mid + 1;
		}
	}

	if (low < last && arr[low] < target) {
		low++;
	}

	return low;
}


int main(void) {

	int vec[] = { 1, 3, 5, 6, 6 , 7, 7, 32, 44 };
	int target = 100; 

	/*int res = BinSearchRec(vec, 0, N - 1, target);

	if (res == -1) {
		printf("il valore %d non e' presente all'interno della sequenza\n", target);
	}
	else {
		printf("il valore %d e' presente all'interno della sequeza in posizione %d \n\n", target, res + 1);
	}*/

	int low_bound = lower_bound(vec, 0, N - 1, target);

	printf("il limite inferiore di %d e' il valore %d alla posizione %d \n", target, vec[low_bound], low_bound + 1); // il più 1 serve solo per far partire 
																													 // le posizioni da 1 piuttosto che 0
	return 0; 
}


















