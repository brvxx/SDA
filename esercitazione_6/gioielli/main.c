#include "gioielli.h" 

int main(void) {

	size_t size; 
	float budget = 121; 
	Gioiello* res = CompraGioielli("gioielli_1.txt", budget, &size);

	printf("la soluzione dell'algoritmo greedy contiene %zu gioielli\n\n", size);
	for (size_t i = 0; i < size; ++i) {
		printf("codice gioiello: %d,  peso gioiello %f, prezzo gioiello %f\n\n", res[i].codice, res[i].peso, res[i].prezzo);
	}

	free(res);
	return 0; 
}