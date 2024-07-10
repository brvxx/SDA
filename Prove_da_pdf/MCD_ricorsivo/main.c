#include <stdio.h>

int McdRicorsivo(int m, int n) {
	
	if (m == n) {
		return m;  
	}

	return m > n ? McdRicorsivo(m - n, n) : McdRicorsivo(m, n - m);

}

int main(void) {

	int val_1 = 36; 
	int val_2 = 15; 

	int res = McdRicorsivo(val_1, val_2);

	printf("il massimo comune divisore tra i valori %d e %d e': %d", val_1, val_2, res);
	return 0;
}