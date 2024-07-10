#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

void StazioniServizioRec(size_t n , double m, size_t i, double dst_tot, double dst_curr, double dst_max, const double* prezzi, const double* dst, int* vcurr, int* vbest, double p_curr, double* p_best) {

	if (dst_tot + (dst_max - dst_curr) >= m) {	// se la distanza percosa fino ad adesso sommata alla distanza ancora percorribile con il carburante corrente è maggiore della distanza totale da percorre 
												// siamo di fronte ad una soluzione 
		for (size_t j = i; j < n; ++j) {
			vcurr[j] = 0;						// se il carburante da qui in poi ci basta per arrivare a destinazione, sicuramente non ha senso fare il pieno nelle prossime stazioni
		}
		
		if (p_curr < *p_best) {
			*p_best = p_curr; 
			memcpy(vbest, vcurr, n * sizeof(int));
		}
		return;
	}

	if (i == n) {	//caso in cui sei all'ultima stazione ma i kilometri di autonomia non ti bastano per arrivare a destinazione 
		return; 
	}

	dst_curr += dst[i]; 
	dst_tot += dst[i];

	if (dst_curr > dst_max) {	// caso in cui le stazioni sono troppo distanti tra loro, quindi che anche con un pieno non si possa passare dalla stazione i-esima alla (i + 1)-esima 
		return;
	}

	if ((i < n - 1) && (dst_curr + dst[i + 1] <= dst_max)) {
		vcurr[i] = 0;
		StazioniServizioRec(n, m, i + 1, dst_tot, dst_curr, dst_max, prezzi, dst, vcurr, vbest, p_curr, p_best);
	}

	vcurr[i] = 1; 
	p_curr += dst_curr * 0.05 * prezzi[i];
	dst_curr = 0; 
	StazioniServizioRec(n, m, i + 1, dst_tot, dst_curr, dst_max, prezzi, dst, vcurr, vbest, p_curr, p_best);

}



void StazioniServizio(double m, const double* d, const double* p, size_t n) {

	size_t i = 0; 
	double dst_tot = 0;				// distanza percorsa
	double dst_curr = 0;			// distanza dall'ultimo pieno 
	double dst_max = 30 / 0.05;		// massima distanza percorribile con un pieno (data dalle condizioni del problema) 

	int* vcurr = calloc(n, sizeof(int));
	int* vbest = calloc(n, sizeof(int));

	double p_curr = 0; 
	double p_best = DBL_MAX;

	StazioniServizioRec(n, m, i, dst_tot, dst_curr, dst_max, p, d, vcurr, vbest, p_curr, &p_best);

	if (p_best == DBL_MAX) {
		printf("non esistono soluzioni");
	}
	else {
		for (size_t j = 0; j < n; ++j) {
			if (vbest[j] == 1) {
			printf("%zu ", j);
			}
		}
		printf("\nSpesa totale: %lf euro", p_best);
	}


	free(vcurr);
	free(vbest); 
}