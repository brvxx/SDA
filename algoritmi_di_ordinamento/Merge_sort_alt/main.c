// questo algroitmo è sempre del tipo merge sort, solo che comporta una piccola modifica all'interno 
// della funzione merge, in quanto non si andrà a creare più un vettore inutilmente lungo ma ne verranno 
// creati due, esattamente della lunghezza dei due sottovettori trovati. Per il resto è tutto sostanzialmente 
// identico. 

#include <stdio.h>
#include <stdlib.h>

#define N 8

void merge(int* A, int first, int mid, int last) {
	
	int i, j, k;			  // i indice di L, j indice di R, k indice di A (vettore originale) 
	int n1 = mid - first + 1; // lunghezza primo sottovettore (1 aggiunto per correggere la dimensione --> dovuto al calcolo di mid non sempre al centro ma spostato a dx) 
	int n2 = last - mid;	  // lunghezza secondo sottovettore

	int* L = calloc(n1, sizeof(int));	// vettori temporanei per contenre copie dei due sottovettori 
	int* R = calloc(n2, sizeof(int));

	for (i = 0; i < n1; ++i) {			// copia dati dal vettore originale ai due vettori temporanei 
		L[i] = A[first + i];
	}
	for (j = 0; j < n2; ++j) {
		R[j] = A[mid + 1 + j]; 
	}
	
	i = 0; 
	j = 0; 
	k = first; 

	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		A[k] = L[i];
		++i;
		++k; 
	}

	while (j < n2) {
		A[k] = R[j];
		++j;
		++k;
	}

	free(L);
	free(R);
}

void merge_sort(int* A, int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;		// o equivalentemente first + (last - first)/2 
		merge_sort(A, first, mid);
		merge_sort(A, mid + 1, last);
		merge(A, first, mid, last);
	}
}

int main(void) {

	int vec[] = { 3, 2, 9, 11 , 1, 10, 7, 4 };

	merge_sort(vec, 0, N - 1);

	for (int i = 0; i < N; ++i) {
		printf("%d ", vec[i]);
	}

	return 0;
}