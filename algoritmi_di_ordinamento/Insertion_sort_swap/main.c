// Questo algoritmo di ordinamento è chiamato insertion sort, ed ha un principio di funzionamento 
// leggermente diverso dagli altri citati come il selection o bubble; infatti, invece di cercare 
// ogni volta il maggiore tra n - i elementi per poterlo portare ad un estremo del vettore con 
// questo algoritmo si cerca di costruire il vettore direttamente ordinato; 
// Si parte considerando il primo elemento del vettore già come ordinato per poi aggiungere il
// secondo direttamente nella sua posizione ordinata, quindi lo si confronta con il primo e lo si
// mette prima se minore o lo si lascia lì se maggiore. Poi l'algoritmo procede così per tutti gli 
// altri elementi, ogni volta aggiungendoli nella corretta posizione per mantenere l'ordinamento del 
// vettore che si sta creando. 
// Nota che è sostanzialmente il metodo che si userebbe per ordinare un mazzo di carte, estraendo una 
// carta alla volta e inserendola nel mazzetto ordinato che si sta pian piano creando. 



#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a; 
	*a = *b; 
	*b = tmp; 
}

void InsertionSort(int* v, int dim) {
	int tmp, i, j;

	for (i = 1; i < dim; ++i) {	
		j = i;
		
		while (j > 0 && v[j - 1] > v[j]) {
			swap(v + j, v + j - 1);	// se l'elemento da aggiungere non è il maggiore della nuova sequenza allora bisogna swappare a 
									// destra tutti gli elementi maggiori, così che alla fine l'elemento si trovi già nella posizione giusta

			--j;					// j dovrà sempre essere l'indice dell'elemento che sto ordinando 
		}						
	}
}

int main(void) {

	int vec[] = { 41, 11, 3, 2 , 11, 44, 100, 23 };
	int dim = 8;

	InsertionSort(vec, dim);

	for (int i = 0; i < dim; ++i) {
		printf("%d ", vec[i]);
	}

	return 0;
}