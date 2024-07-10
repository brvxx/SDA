#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>


typedef struct {
	double costo;
	int itinerario; 
	int* stazioni;
} plan;

void pianifica(plan curr, plan* best, int dst_tot, int dst_pieno, int dst_curr, double dst_max ,double consumo, int n, int i, int* dst, int* prezzi, int* nsol) {

	if (dst_curr + (dst_max - dst_pieno) >= dst_tot) {	// questa condizione è come se venisse letta subito dopo il passaggio per una stazione --> se è verificata siamo arrivati in fondo
														// nota che grazie a questo controllo, piuttosto che un i == n stiamo andando a tagliare quelle soluzioni inutili, ossia quelle che comprendono una fermata
														// in prossimità dell'ultima stazone la quale però è anche l'arrivo quindi è inutile. 
		(*nsol)++;
		printf("percorso %d: \n\n", *nsol);
		for (int k = i; k < n; ++k) {
			curr.stazioni[k] = 0; 
		}
		for (int j = 0; j < n; ++j) {
			if (curr.stazioni[j] == 0) {
				printf("stazione %d:   no\n", j + 1);
			}
			else {
				printf("stazione %d:   si\n", j + 1); 
			}
		}
		printf("\ncosto totale carburante: %.2lf euro\n\n", curr.costo);
		
		if (curr.costo < best->costo) {
			best->costo = curr.costo; 
			best->itinerario = *nsol;
			memcpy(best->stazioni, curr.stazioni, n * sizeof(int));
		}
		
		return; 
	}

	dst_pieno += dst[i];
	dst_curr += dst[i];

	if (dst_pieno > dst_max) {
		return;
	}

	if ((i < n - 1) && (dst_pieno + dst[i + 1] <= dst_max)) {
		curr.stazioni[i] = 0; 
		pianifica(curr, best, dst_tot, dst_pieno, dst_curr, dst_max, consumo, n, i + 1, dst, prezzi, nsol);
	}
	
	curr.stazioni[i] = 1;
	curr.costo += dst_pieno * consumo * prezzi[i];   // calcolo il prezzo della fermata con questa moltiplicazione poichè il consumo ci dice quanti litri di carburante vengono consumati ad ogni km percorso, allora 
													// moltiplicando i kilometri percorsi dall'ultima stazione fino ad ora per il consumo (otteniamo i litri consumati) e infine per il prezzo al litro otteniamo la cifra giusta 
	dst_pieno = 0;
	pianifica(curr, best, dst_tot, dst_pieno, dst_curr, dst_max, consumo, n, i + 1, dst, prezzi, nsol);


}

int main(void) {
	
	int tragitto = 0;		// distanza totale da percorrere
	int serbatoio = 0;		// capacità serbatoio 
	double consumo = 0;		// cosnumo medio in litri per kilometro percorso 
	int stazioni = 0;		// numero di stazioni totali durante il tragitto
	double dst_max = 0;		// massima distanza percorribile con un pieno (dipende dal consumo del veicolo)
	int nsol = 0; 

	printf("quante sono le stazioni sul percorso? ");
	scanf("%d", &stazioni);
	printf("\n");
	
	plan current = { 0, 0, calloc(stazioni, sizeof(int)) };	 // struct che conterrà la soluzione corrente, con il prezzo della benzina fino ad una data stazione e la lista delle stazioni prese 
	plan best = { DBL_MAX, 0, calloc(stazioni, sizeof(int)) };	 // struct che conterrà la migliore tra le soluzioni accettabili 

	int* dst = calloc(stazioni, sizeof(int));
	int* prezzi = calloc(stazioni, sizeof(int));

	printf("capacita' serbatoio del veicolo in litri? ");
	scanf("%d", &serbatoio);

	printf("\nconsumo medio di carburante ogni chilometro (in litri): ");
	scanf("%lf", &consumo);

	dst_max = serbatoio / consumo;	

	printf("\ndistanza della stazione 1 dal punto di partenza: ");	// reperiamo da linea di comando le varie distanze tra stazioni di servizio e il rispettivo costo del carburante 
	scanf("%d", &dst[0]);
	tragitto += dst[0];
	printf("costo carburante al litro: ");
	scanf("%d", &prezzi[0]);
	printf("\n");
	for (int j = 1; j < stazioni; ++j) {
		printf("distanza della stazione %d dalla stazione %d: ", j + 1, j);
		scanf("%d", &dst[j]);
		tragitto += dst[j];
		printf("costo carburante al litro della stazione: ");
		scanf("%d", &prezzi[j]);
		printf("\n");
	}

	for (int i = 0; i < stazioni; ++i) {																		// riepilogo dei dati inseriti dall'utente 
		printf("distanza stazione %d: %d     prezzo carburante: %d euro/l\n", i + 1, dst[i], prezzi[i]);
	}
	printf("\ndistanza totale da percorrere: %d\n\n\n", tragitto);
	
	printf("calcolare i percorsi possibili? (si/no): ");
	char risposta[10] = { 0 };
	scanf("%s", risposta);
	if (strcmp(risposta, "si") == 0 || strcmp(risposta, "sì") == 0 || strcmp(risposta, "Si") == 0 || strcmp(risposta, "Sì") == 0 || strcmp(risposta, "SI") == 0) {
		pianifica(current, &best, tragitto, 0, 0, dst_max, consumo, stazioni, 0, dst, prezzi, &nsol);
	}
	
	if (best.costo == DBL_MAX) {
		printf("\n\nimpossibile giungere alla destinazione con l'attuale configurazione di stazioni\n\n");
	}
	else {
		printf("\nil migliore itinerario e' il numero %d, con un costo totale di %.2lf euro\n\n", best.itinerario, best.costo);
	}

	free(dst);
	free(prezzi);
	free(current.stazioni);
	free(best.stazioni);
	return 0; 
}