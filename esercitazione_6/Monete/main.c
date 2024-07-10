#include <stdlib.h>
#include <stdio.h>

extern int* Monete(const int* tagli, size_t tagli_size, int budget);

main(void) {

	const int tagli[] = { 50, 20, 10, 5, 2, 1 }; 
	size_t tagli_size = sizeof(tagli) / sizeof(tagli[0]); 
	
	int budget = 3; 

	int* res = Monete(tagli, tagli_size, budget); 
	if (res) {
		printf("per raggiungere il budget di %d centesimi la combinazione migliore di monete sara':\n\n", budget);
		for (size_t i = 0; i < tagli_size; ++i) {
			if (res[i]) {
				printf("%d monete/a da %d centesimi\n\n", res[i], tagli[i]); 
			}
		}
	}
	else {
		printf("ERROR: parametri non passati correttamente alla funzione\n\n");
	}

	return 0; 
}