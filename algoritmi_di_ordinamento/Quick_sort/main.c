/*
		Questo algoritmo di ordinamento si chiama quick sort e sostanzialmente il suo funzionamento si basa sul 
		concetto di pivot. Infatti l'obbiettivo è quello di spezzare il vettore di volta in volta in due sottovettori 
		divisi da un pivot (perno), ovvero un elemento che si trova già nella sua corretta posizione una volta che il 
		vettore è ordinato. Il pivot è un elemento che viene scelto a caso (noi per comodità sceglieremo l'ultimo elemento
		del vettore) e quello che faremo è fare in modo che ogni volta il pivot abbia alla sua sinistra elementi minori 
		di lui e alla sua destra elementi maggiori, così che questo si trovi già nel suo posto definitivo. 
		Ovviamente questo algoritmo si appoggia alla ricorsione, infatti trovato il pivot e ordinato nel modo giusto 
		bisognerà ripetere il processo all'interno dei due nuovi sottovettori che si vengono a creare (divisi dal pivot) 
		finchè non si arriverà a dei vettori di lunghezza uno che saranno considerati ordinati. 
*/


#include <stdio.h>

#define N 10

void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

int partition(int arr[], int low, int high) {	// è quella funzione che ci permette di mettere nel posto giusto il pivot 
	
	int pivot = arr[high];		// per comodità poniamo l'ultimo elemento del vettore come pivot 
	int i = low - 1;			// i sarà l'indice che ci punta sempre all'ultimo elemento tra quelli minori o uguali del pivot
	int j;						// indice che tiene traccia della lettura all'interno del vettore

	for (j = low; j <= high; ++j) {
		if (arr[j] <= pivot) {
			++i;				// perchè stiamo per andare ad aggiungere in posizione i un elemento più piccolo del pivot
			if (i < j) {		// effettuiamo questo controllo onde evitare swap superflue, infatti all'inizio della lettura se il primo elemento è <= pivot i e j saranno uguali 
				
				swap(arr + i, arr + j);		// nota che in arr[i] prima dello swap sicuramente c'è un elemento maggiore del pivot
			}
		}
	}

	return i; 
}


void quick_sort(int arr[], int low, int high) {
	
	if (low < high) {							// se low fosse == high significherebbe che staremmo provando a lavorare su un vettore di lunghezza 1, ma ciò non ha senso 
		int piv = partition(arr, low, high);	// in quanto per definzione questo è già ordinato

		// chiamata ricorsiva sui due sottovettori generati dal pivot 
		quick_sort(arr, low, piv - 1);			
		quick_sort(arr, piv + 1, high);
	}
}

int main(void) {

	int vec[] = { 3, 2, 5, 4, 1, 8, 7, 6, 9, 0 };

	quick_sort(vec, 0, N - 1);

	for (int i = 0; i < N; ++i) {
		printf("%d ", vec[i]);
	}

	return 0;
}