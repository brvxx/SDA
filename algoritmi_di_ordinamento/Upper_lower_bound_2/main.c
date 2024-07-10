// Questi algoritmi sono sostanzialmente della alternative ai due algoritmi di ricerca upper e lower 
// bound già visti nel file 1 


#include <stdio.h>

int lower_bound(int* arr, int low, int high, int target) {
	int mid; 
	
	while (low < high) {
		mid = (low + high) / 2; 
		
		if (arr[mid] >= target) {
			high = mid;  // tengo mid diventa il valore di high poichè è una possibile soluzione --> l'indice mid è valido per essere lower bound 
		}
		else {
			low = mid + 1; 
		}
	}
	if (arr[low] < target) {	// caso in cui il target era maggiore di tutti i numeri della sequenza --> limite non esiste
		return -1; 
	}
	return low; 
}

int upper_bound(int* arr, int low, int high, int target) {
	int mid;

	while (low < high) {
		mid = (low + high) / 2;

		if (arr[mid] > target) {
			high = mid;   
		}
		else {
			low = mid + 1;
		}
	}
	if (arr[low] <= target) { // mettiamo anche l'uguale perchè per definizione l'upper bound dovrà essere strettamente maggiore, se sono uguali non va bene
		return -1;
	}
	return low;

}
int main(void) {

	int vec[] = { 1, 2 , 3, 3, 5, 8, 8, 10, 10, 11, 12 };
	int N = sizeof(vec) / sizeof(vec[0]);
	int target = 0;

	int l_bound = lower_bound(vec, 0, N - 1, target);
	int u_bound = upper_bound(vec, 0, N - 1, target);

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