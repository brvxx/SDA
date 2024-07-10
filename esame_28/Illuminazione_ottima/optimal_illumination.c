#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int max_(int a, int b) {
	if (a > b) {
		return a; 
	}
	else {
		return b; 
	}
}
int min_(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

static void SetLamp(int* spazi_presi, bool flag, int sx, int dx, int* spazi_curr) {
	if (flag) {
		for (int i = sx; i <= dx; ++i) {
			spazi_presi[i] += 1; 
			if (spazi_presi[i] == 1) {
				(*spazi_curr)++; 
			}
		}
	}
	else {
		for (int i = sx; i <= dx; ++i) {
			spazi_presi[i] -= 1;
			if (spazi_presi[i] == 0) {
				(*spazi_curr)--;
			}
		}
	}
}

static void IlluminationRec(int meters, int r, int i, const int* light, int size, int* spazi_presi, 
			bool* vcurr, bool* vbest, int spazi_tot, int spazi_curr, int lampioni_curr, int* lampioni_best) {
	
	if (spazi_curr == spazi_tot && lampioni_curr < *lampioni_best) {
		memcpy(vbest, vcurr, size * sizeof(bool));
		*lampioni_best = lampioni_curr;
		return; 
	}
	if (i == size) {
		return; 
	}
	// modellazione problema con albero binario --> o accendo il lampione light[i] oppure non lo accendo 


	vcurr[i] = false; 
	IlluminationRec(meters, r, i + 1, light, size, spazi_presi, vcurr, vbest, spazi_tot, spazi_curr, lampioni_curr, lampioni_best); 

	vcurr[i] = true; 
	SetLamp(spazi_presi, true, max_(0, light[i] - r), min_(meters - 1, light[i] + r - 1), &spazi_curr);
	IlluminationRec(meters, r, i + 1, light, size, spazi_presi, vcurr, vbest, spazi_tot, spazi_curr, lampioni_curr + 1, lampioni_best);

	// reimposto tutti i parametri a come erano prima dell'accensione
	SetLamp(spazi_presi, false, max_(0, light[i] - r), min_(meters - 1, light[i] + r - 1), &spazi_curr);
	vcurr[i] = false;
}

bool* OptimalIllumination(int M, int R, const int* light, size_t light_size) {
	int* spazi_presi = calloc(M, sizeof(int)); 
	bool* vcurr = calloc(light_size, sizeof(bool)); 
	bool* vbest = calloc(light_size, sizeof(bool)); 
		
	int lamp_best = INT_MAX; 
	int spazi_tot = M;
	
	IlluminationRec(M, R, 0, light, (int)light_size, spazi_presi, vcurr, vbest, spazi_tot, 0, 0, &lamp_best); 

	free(spazi_presi); 
	free(vcurr); 
	
	if (lamp_best == INT_MAX) {
		free(vbest);
		return NULL;
	}
	 
	return vbest; 
}