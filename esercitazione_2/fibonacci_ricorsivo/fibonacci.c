#include <string.h>
#include <stdlib.h>

int FibonacciRicorsivo(int n, int* mem) {
	if (n == 0 || n == 1) {
		return n;			//if (n == 0) return 0; if (n == 1) return 1; -> caso base -> nel concreto significa metti in posizione 1 un 1 e in 0 uno 0 
	}

	if (mem[n - 1] == 0) {		//se non abbiamo mai svolto questo passaggio allora lo andiamo a fare
		mem[n - 1] = FibonacciRicorsivo(n - 1, mem);
	}
	
	if (mem[n - 2] == 0) {
		mem[n - 2] = fibonacciricorsivo(n - 2, mem);  //serve solo per sovrascrivere uno 0 ad un altro 0 --> lo teniamo per correttezza formale
	}							

	/*   ^
		 |
	passaggio non necessario --> le varie chiamate ricorsive dell'if sopra coprono tutti i valori della sequenza da
	mem[1] a mem [n - 1] (il valore prima di quello cercato), quindi l'unico valore rimasto fuori è quello corrispondente a mem[0], il
	quale dovrebbe essere zero, ma questo lo è già senza modificarlo poichè abbiamo effettuato una allocazione di memoria attraverso 
	la calloc */
	
	return mem[n - 1] + mem[n - 2];   //avessi fatto return FibonacciRicorsivo(n - 2) + FibonacciRicorsibo(n - 1) durante 
}									  //l'esecuzione di f(n - 2) sarei andato a ripercorrere passi già percorsi per le chiamate ricorsive di f(n - 1) 

int Fibonacci(int n) {
	if (n < 0) {
		return -1;
	}

	int* mem = calloc(n , sizeof(int));
	int res = FibonacciRicorsivo(n, mem);

	free(mem);
	
	return res;
}