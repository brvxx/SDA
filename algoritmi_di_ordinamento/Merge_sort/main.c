// Questo algorimto di ordinamento si chiama Merge sort; l'algoritmo funziona sulla base della
// tecnica "divide et impera", che consiste sostanzialemente nel dividere VIRTUALMENTE in due il 
// vettore di partenza (divide) per poi andare ad operare su questi nuovi vettori di lunghezza 
// dimezzata (impera). L'obbiettivo è quello di dividere il vettore di partenza in sottovettori 
// di lunghezza di volta in volta dimezzata grazie alla ricorsione, fino ad arrivare a vettori 
// singoli di lunghezza 1 e di conseguenza già oridnati. A qeusto punto avviene il merging vero 
// e proprio, infatti salendo la ricorsione attraverso una funzione ausiliaria di merging vengono
// uniti tra di loro i vari sottovettori già ordinati fino ad arrivare alla ultima fusione dei due
// sottovettori derivanti dalla prima divisione. 

#include <stdio.h>

#define N 8

void Merge(int* A, int first, int mid, int last) {
	
	int B[N] = { 0 };	// vettore ausiliaro per fare merging
	int i = first;		// indice primo sottovettore
	int j = mid + 1;	// indice secondo sottovettore
	int k;				// indice nuovo vettore per fare merging 

	for (k = first; i <= mid && j <= last; ++k) {		// il for gira finchè non si è finito di inserire TUTTI gli elementi di uno dei due sottovettrori
		if (A[i] < A[j]) {								// anche perchè i rimanenti dell'altro sottovettore essendo già ordinati possono essere aggiunti alla 
			B[k] = A[i];								// fine così come sono 
			++i; 
		}
		else {			// A[i] >= A[j]
			B[k] = A[j];
			++j;
		}
	}

	// aggiunta di tutti gli elementi di quel sottovettore che non è stato itneramente letto (solo 1 dei due while girerà) 

	while (i <= mid) {
		B[k] = A[i];
		++i;
		++k;
	}

	while (j <= last) {
		B[k] = A[j];
		++j;
		++k;
	}

	for (i = first; i <= last; i++) {
		A[i] = B[i];
	}
}

void MergeSort(int* A, int first, int last) {
	if (first < last) {
		int mid = (first + last) / 2;		// o equivalentemente first + (last - first)/2 
		MergeSort(A, first, mid);
		MergeSort(A, mid + 1, last); 
		Merge(A, first, mid, last);
	}
}

int main(void) {

	int vec[] = { 3, 2, 9, 11 , 1, 10, 7, 4 };

	MergeSort(vec, 0, N - 1);

	for (int i = 0; i < N; ++i) {
		printf("%d ", vec[i]);
	}

	return 0;
}