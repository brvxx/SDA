#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#include "parser.h"

typedef struct {
	double costo;
	int percorso;
	int* stazioni;
} plan;

void pianifica(plan curr, plan* best, struct config_data* data, int i, int delta, int* nsol) {
	
	if (i == data->stazioni) {
		(*nsol)++;
		printf("\n\nPercorso %d)  \n", *nsol);
		for (int j = 0; j < data->stazioni; ++j) {
			if (curr.stazioni[j] == 1) {
				printf("stazione %d: si\n", j + 1);
			}
			else {
				printf("stazione %d: no\n", j + 1);
			}
		}
		printf("costo totale carburante: %.2lf euro", curr.costo);

		if (curr.costo < best->costo) {
			best->costo = curr.costo;
			memcpy(best->stazioni, curr.stazioni, data->stazioni * sizeof(int));
			best->percorso = *nsol; 
		}
		return;
	}

	delta += data->distanze[i];
	if (delta > data->serbatoio / data->consumo) {  //se ho superato i kilometri massimi percorribili con un pieno non posso andare avanti
		return;
	}

	curr.stazioni[i] = 0;
	pianifica(curr, best, data, i + 1, delta, nsol);

	curr.costo += delta * data->consumo * data->prezzi[i];		// faccio rifornimento nella i-esima stazione 
	delta = 0;
	curr.stazioni[i] = 1;
	pianifica(curr, best, data, i + 1, delta, nsol);

}

int main(void) {

	struct config_data eddu = { 0 };
	parse("config.cfg", &eddu);
	printf("numero di stazioni: %d\n\ncapacita' serbatoio: %dl\nconsumo: %.2lfl/km\n\n", eddu.stazioni, eddu.serbatoio, eddu.consumo);
	for (int i = 0; i < eddu.stazioni; ++i) {
		printf("stazione %d)  distanza: %d km   costo benzina %d euro/litro\n", i, eddu.distanze[i], eddu.prezzi[i]);
	}
	
	plan current = { 0, 0, calloc(eddu.stazioni, sizeof(int))};
	plan best = { DBL_MAX, 0, calloc(eddu.stazioni, sizeof(int))};
	
	char buf[10] = { 0 };
	printf("\ncalcolare i percorsi disponibili? (si/no)  ");
	scanf("%s", buf);

	int nsol = 0; 
	if (strcmp(buf, "si") == 0 || strcmp(buf, "sì") == 0 || strcmp(buf, "Si") == 0 || strcmp(buf, "sì") == 0 || strcmp(buf, "SI") == 0) {
		pianifica(current, &best, &eddu, 0, 0, &nsol);
	}

	printf("\n\nIl percorso meno dispendioso e' il numero %d, che comprende le stazioni:\n", best.percorso);
	for (int l = 0; l < eddu.stazioni; ++l) {
		if (best.stazioni[l] == 1) {
			printf("stazione %d\n", l + 1);
		}
	}
	printf("costo totale: %.2lf euro\n\n", best.costo);

	data_free(&eddu);
	free(current.stazioni);
	free(best.stazioni);
	return 0; 
}