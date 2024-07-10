#include <stdio.h>

#define DIM 8

void Print(int* colonna, int nsol) { // funzione di stampa per le soluzioni 
	printf("soluzione %d) \n\n", nsol);
	
	for (int k = 0; k < DIM; ++k) {
		for (int l = 0; l < DIM; ++l) {
			if (k == colonna[l]) {
				printf("* ");
			}
			else {
				printf("- ");
			}
		}
		printf("\n");
	}
	printf("\n");
	
}

void Queens(int j, int* riga, int* diag_1, int* diag_2, int* colonna, int* nsol, int* calls) {
	(*calls)++;
	
		// i è indice di riga
	for (int i = 0; i < DIM; ++i) { 
		
		if (riga[i] == 0 && diag_1[i - j + DIM - 1] == 0 && diag_2[i + j] == 0) {
			
			// il DIM - 1 aggiunto ad i + j nella dereferenziazione di diag_1 serve per evitare di avere indici negativi
			// in quanto non avrebbe senso andare a leggere in memoria in posizione negativa all'interno di un vettore
			colonna[j] = i; 
			
			// dichiariamo le zone non più accessibili a seguito del posizionamento di questa regina
			riga[i] = 1;					
			diag_1[i - j + DIM - 1] = 1;
			diag_2[i + j] = 1;

			// effettuiamo la chiamata ricorsiva accertandoci di non andare poi a scrivere oltre alla lunghezza di int *colonna
			if (j < DIM - 1) {  
				Queens(j + 1, riga, diag_1, diag_2, colonna, nsol, calls);
			}
			else {	// se j == DIM - 1 --> siamo riusciti a posizionare n regine --> SOLUZIONE TROVATA
				(*nsol)++;
				Print(colonna, *nsol);
			}

			// ripristiniamo i vettori di controllo per le successive chiamate che non avranno più una regina nella casella i,j
			riga[i] = 0; 
			diag_1[i - j + DIM - 1] = 0; 
			diag_2[i + j] = 0;
		}
	}

}

int main(void) {

	// vettori di controllo posizioni occupate, in ogni slot potrà essere messo solo uno 0 o un 1 affinchè questo ci dica se 
	// se la riga/diagonale presa in conderazione è sotto attacco da una regina piazzata precedentemente
	int riga[DIM] = { 0 };
	int diag_1[DIM * 2 - 1] = { 0 };	// diagonali che "scendono" da sx a dx --> differenza di indici costante 
	int diag_2[DIM * 2 - 1] = { 0 };	// diagonali che "salgono" da sx a dx --> somma di indici costante

	// vettore soluzione che rappresenta le n colonne della scacchiera, ogni valore al suo interno rappresenta la riga in cui
	// viene posizionata la regina nella corrispondente colonna (denotata dallo slot del vettore)
	int colonna[DIM] = { 0 };
	
	int j = 0; // indice di colonna 
	int nsol = 0; // contatore di soluzioni ammesse 
	int calls = 0; // chiamate totali a funzione Queens --> per tenere traccia dell'efficienza dell'algoritmo 

	printf("possibili scacchiere %dx%d dove le %d regine non si minacciano a vicenda: \n\n", DIM, DIM, DIM);
	Queens(j, riga, diag_1, diag_2, colonna, &nsol, &calls);




	return 0; 
}