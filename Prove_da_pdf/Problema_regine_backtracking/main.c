#include <stdio.h>

#define DIM 4

void PrintSolution(int* colonna, int nsol) {
	printf("soluzione numero %d: \n\n", nsol);
	for (int k = 0; k < DIM; ++k) {
		for (int l = 0; l < DIM; ++l) {
			if (k == colonna[l]) {
				printf("1 ");
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	printf("\n\n");

}

void Queens(int j, int* riga, int* colonna, int* diag_princ, int* diag_sec, int* nsol) {

	for (int i = 0; i < DIM; ++i) {
		
		if ((riga[i] == 0) && (diag_princ[i - j + DIM - 1] == 0) && (diag_sec[i + j] == 0)) {

			colonna[j] = i;
			riga[i] = 1;
			diag_princ[i - j + DIM - 1] = 1;
			diag_sec[i + j] = 1;

			if (j < DIM - 1) {
				Queens(j + 1, riga, colonna, diag_princ, diag_sec, nsol);
			}
			else {
				(*nsol)++;
				PrintSolution(colonna, *nsol);

			}
			riga[i] = 0;
			diag_princ[i - j + DIM - 1] = 0;
			diag_sec[i + j] = 0;
		}
		
	}
}

int main(void) {

	int riga[DIM] = { 0 };
	int diag_princ[DIM * 2 - 1] = { 0 };
	int diag_sec[DIM * 2 - 1] = { 0 };
	int colonna[DIM] = { 0 };
	int j = 0; 

	int nsol = 0;

	printf("possibili posizioni di %d regine all'interno di una scacchiera %dx%d che nessuna possa catturarne un'altra: \n\n\n", DIM, DIM, DIM);
	Queens(j, riga, colonna, diag_princ, diag_sec, &nsol);

	


	return 0; 
}