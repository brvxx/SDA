#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void stampastelle(int n) {
	for (int j = 0; j < n; ++j) {	// j = 0 assegnamento --> 1 
		printf("*");				// j < n --> n + 1 controlli della condizione 
	}								// n*2 --> due istruzioni eseguite n volte che viene eseguito il for (++j e printf)
}									
									// funzione di costo stampastelle --> 1 + n + 1 + 2n = 3n + 2


int main(void) {
	int rows, elems; // due semplici dichiarazioni, valgono 0 
	
	printf("quante stelline vuoi stampare? ");			// 1 
	scanf("%d", &elems);								// 1
	printf("quante righe di stelline vuoi cucciolo? "); // 1
	scanf("%d", &rows);									// 1 

	for (int i = 0; i < rows; i++) {					// i = 0 --> 1 perchè assegnamento 
		stampastelle(elems);							// i < rows --> per comodità il valore rows lo chiameremo m --> sono m + 1 controlli 
	}													// poi abbiamo stampastelle e l'incremento della i effettuati m volte --> m(3n + 2 + 1)
}

// funzione di costo totale --> 5 + m + 1 + m(3n + 3) --> 6 + 4m + 3mn 