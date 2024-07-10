 /**
 * 
 * la strategia è partire dall'alto, prendiamo il primo pacco senza problemi perché sopra di lui sicuramente 
 * non avrà nulla, il secondo pacco invece di metterlo sopra lo mettiamo sotto, quindi l'unica condizione che 
 * deve veriifcare è che il peso del pacco superiore sia inferiore del suo limite. Se questo accade allora possiamo
 * vedere i due pacchi impilati correttamente come un nuovo pacco unico, dal peso pari alla somma dei due pacchi 
 * impilati e verificare che il terzo pacco che stiamo aggiungendo alla base abbia limite superiore a questo peso 
 * e via dicendo. 
 *
 * Se fossimo partiti dal basso, quindi aggiungendo pacchi in cima, ogni volta che andavamo ad aggiungere un pacco 
 * sarebbe stato necessario controllare di non aver superato il limite di TUTTI i pacchi precedenti.
 *
 **/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "torrecartoni.h"

static void TorreCartoniRec(const Cartone* c, int n, int i, int peso_curr, int altezza_curr, int* altezza_best,
								int* vcurr, int* vbest, bool* pacchi_presi, int cnt, int* cnt_best) {

	if (altezza_curr > *altezza_best) {
		memcpy(vbest, vcurr, n * sizeof(int)); 
		*altezza_best = altezza_curr; 
		*cnt_best = cnt; 
	}
	
	if (i == n) {
		return;
	}

	for (int j = 0; j < n; ++j) {
		if (peso_curr <= (int)c[j].l && !pacchi_presi[j]) {
			vcurr[i] = j; 
			peso_curr += c[j].p;
			altezza_curr += c[j].a; 

			pacchi_presi[j] = true; 

			TorreCartoniRec(c, n, i + 1, peso_curr, altezza_curr, altezza_best, vcurr, vbest, pacchi_presi, cnt + 1, cnt_best); 

			peso_curr -= c[j].p; 
			altezza_curr -= c[j].a; 

			pacchi_presi[j] = false; 
		}
	}
}

void TorreCartoni(const Cartone* c, size_t n) {
	if (n == 0) {
		return; 
	}
	
	int* vcurr = calloc(n, sizeof(int)); 
	int* vbest = calloc(n, sizeof(int));
	bool* pacchi_presi = calloc(n, sizeof(bool));

	int altezza = 0; 
	int cnt = 0; 
	TorreCartoniRec(c, (int)n, 0, 0, 0, &altezza, vcurr, vbest, pacchi_presi, 0, &cnt); 

	for (int i = 0; i < cnt; ++i) {
		printf("%d\n", vbest[i]);
	}
	printf("Altezza: %d cm\n", altezza);

	free(pacchi_presi);
	free(vcurr); 
	free(vbest); 

	return; 
}