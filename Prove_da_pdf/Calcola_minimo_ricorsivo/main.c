#include <stdlib.h>
#include <stdio.h>

int calcolaminimo(int* v, size_t n, size_t k) {
	
	//int pos_min = 0; 

	//for (size_t i = 1; i < n; ++i) {
	//	if (v[i] < v[pos_min]) {
	//		pos_min = i; 
	//	}
	//}

	//return v[pos_min];					//come trovare il minimo senza ricorsività


	/*if (n == 1) {
		return v[0];
	}

	int min_n1 = calcolaminimo(v, n - 1);

	return (v[n - 1] < min_n1) ? v[n - 1] : min_n1;*/   //caso in cui fissiamo il primo elemento dell'array come minimo


	/*if (n == 1) {
		return v[k];
	}

	int min = calcolaminimo(v, n - 1, k);

	return min < v[k - n + 1] ? min : v[k - n + 1];*/   //caso in cui fissiamo l'ultimo elemento dell'array come minimo

	if (n == 1) {
		return v[0];					//senza usare la variabile k superflua
	}

	int min = calcolaminimo(v + 1, n - 1, k);  //è come fare &v[1]

	return min < v[0] ? min : v[0];
}


int main(void) {

	int arr[] = { 70, 23, 7 , 9, 75, 1 }; 
	size_t size = 6; 
	size_t last_pos = 5; 

	int res = calcolaminimo(arr, size, last_pos); 

	printf("il minimo del vettore e': %d", res);

	return 0; 
}