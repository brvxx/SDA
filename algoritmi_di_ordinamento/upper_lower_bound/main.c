// I seguenti algoritmi sfruttano la ricerca binaria per trovare l'upper bound (limite superiore) e il lower bound (limite inferiore) 
// di un determinato elemento all'interno di un'array ordinato. Ma cosa sono questi due valori? 
// Per definizione si definisce lower bound il più piccolo indice tale che l'elemento in quella posizione all'interno dell'array sia 
// maggiore o uguale al nostro target; Invece si definisce upper bound il più piccolo indice tale che l'elemento in quella posizione 
// sia strettamente maggiore del nostro target. 
// Sostanzialmente il lower bound sarà l'indice in cui andrebbe inserito il target all'interno del vettore senza alterare l'ordinamento. 
// ovviamente spostando i rimanenti elementi di 1 a destra. 
// 
// Tutto questo viene implementato con approccio iterativo data la semplicità dell'algoritmo

#include <stdio.h>



int lower_bound(int* arr, int target, int size) {
	int ans = -1; // questa sarà l'indice soluzione, se non viene variata significa che il limite inferiore non esiste e dunque ritorniamo -1 
	int low = 0; 
	int high = size - 1; 
	int mid; 

	while (low <= high) {
		mid = (low + high) / 2;
		
		if (arr[mid] >= target) { // questa potrebbe essere la soluzione quindi aggiorniamo ans 
			ans = mid; 
			high = mid - 1; 
		}
		else {					  // caso in cui arr[mid] < target --> sicuramente mid non è un indice valido per essere lower bound
			low = mid + 1; 
		}
	}
	return ans; 
}


int upper_bound(int* arr, int target, int size) {
	int ans = -1; 
	int low = 0;
	int high = size - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] > target) { // questa potrebbe essere la soluzione quindi aggiorniamo ans 
			ans = mid;
			high = mid - 1;
		}
		else {					 // caso in cui arr[mid] <= target --> sicuramente mid non è un indice valido per essere upper bound
			low = mid + 1;
		}
	}
	return ans;
}


int main(void) {

	int vec[] = { 1, 2 , 3, 3, 5, 8, 8, 10, 10, 11, 12 };
	int N = sizeof(vec) / sizeof(vec[0]);
	int target = 23; 

	int l_bound = lower_bound(vec, target, N);
	int u_bound = upper_bound(vec, target, N);
	
	if (l_bound == -1) {
		printf("non esiste il lower bound del valore %d\n\n", target); 
	}
	else {
		printf("il lower bound di %d e' l'indice %d\n\n", target, l_bound);
	}

	if (u_bound == -1) {
		printf("non esiste l'upper bound del valore %d\n\n", target);
	}
	else {
		printf("l'upper bound di %d e' l'indice %d\n\n", target, u_bound);
	}

	return 0; 
}
