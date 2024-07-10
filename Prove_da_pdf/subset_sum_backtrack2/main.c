#include <stdio.h>

void CarrelloBacktrack(int n, int i, int* vcurr, int* w, int sum, int goal, int rimanenza, int* nsol, int* calls) {

	(*calls)++;

	if (sum == goal) {			// caso in cui siamo in corrispondenza di una soluzione 
		printf("%d) [", *nsol);
		(*nsol)++;

		for (int j = 0; j < i; ++j) {
			printf("%d ", vcurr[j]);
		}
		for (int j = i; j < n; ++j) {
			printf("0 ");
		}
		puts("] \n");
		return;			// ritorniamo perchè non avrebbe senso da qui in avanti aggiungere elementi con un dato peso, avendo già trovato 
	}					// una soluzione, sforeremmo il limite.
	 
	if (i == n) {		// condizione sostanzialmente inutile, serve solo nel caso in cui la sommma di tutti i pesi sin dall'inizio non
		return;			// sia in grado di arrivare all'obbiettivo, inevitabilmente alla fine ricadremmo in questa condizione dopo aver
	}					// considerato una soluzione con tutti gli elementi possibili (ovviamente non valida) 

	rimanenza -= w[i];
	if (sum + rimanenza >= goal && (i == n - 1 || (i < n - 1 && sum + w[i + 1] <= goal))) {
		vcurr[i] = 0;
		CarrelloBacktrack(n, i + 1, vcurr, w, sum, goal, rimanenza, nsol, calls);
	}
		// prima di tutto si controlla che sia sensato escludere questo elemento, quindi verificando che la somma fino all'elemento precedente (sum)
		// più la somma di tutto quello che viene dopo (rimanenza) sia maggiore ancora dell'obbiettivo, il secondo controllo invece va a controllare
		// che la somma fino al precedente più il prossimo valore prendibile sia minore dell'obbiettivo (ovviamente se esiste un elemento successivo a
		// quello corrente); Solo se tutte e due le condizioni sono verificate procediamo a non prendere l'elemento in posizione i-esima. Se la prima 
		// condizione non fosse verificata non avrebbe proprio senso andare avanti perchè se saltando l'elemento corrente la somma di quelli successivi
		// più i precedenti è inferiore al risultato allora andare avanti non prendendo l'elemento corrente sarebbe solo uno spreco di risorse; Se salto
		// l'elemento corrente, anche se prendessi TUTTI quelli successivi non arrivrei al risultato. Invece la seconda scelta è pura potatura, infatti
		// è logico pensare che (SE E SOLO SE L'ARRAY PASSATO é ORDINATO IN MODO CRESCENTE DI PESO) se la somma corrente più l'elemento della chiamata 
		// successiva sfora l'obbiettivo non ha manco senso andare avanti infatti così come quell'elemento anche tutti i successivi sforerebbero, quindi
		// sicuramente non verrebbero presi come elementi validi per la soluzione grazie alla condizione 2 (vedi sotto). Si noti che la seconda condizione 
		// ha senso solo nel caso in cui non si prenda l'elemento corrente (quindi quando mettiamo 0), perchè solo in questo modo la sum alla prossima chiamata
		// sarebbe rimasta invariata e avrebbe resa vera sempre la condizone; infatti nell'if successivo c'è sempre il caso che aggiungendo l'elemento corrente
		// si arrivi proprio ad una soluzione e ci si fermi lì, quindi non bisogna guardare direttamente guardare l'elemento successivo al corrente.
		
	if (sum + w[i] <= goal) {																 
		vcurr[i] = 1;																		
		CarrelloBacktrack(n, i + 1, vcurr, w, sum + w[i], goal, rimanenza, nsol, calls);
	}

		// l'unica condizione da verificare nel prendere l'elemento corrente è che aggiungendo questo siamo ancora sotto all'obbiettivo o al più lo abbiamo
		// raggiunto.
}

int main(void) {

	int elems = 4;
	int i = 0;
	int sln[4] = { 0 };
	int weights[] = { 7 , 11, 13, 24 };
	int sum = 0;
	int goal = 31;
	int rimanenza = 55;
	int nsol = 0;
	int calls = 0; 

	printf("possibili carrelli con un costo di %d: \n\n", goal);
	CarrelloBacktrack(elems, i, sln, weights, sum, goal,rimanenza, &nsol, &calls);
	printf("i totali carrelli possibli sono quindi %d , chiamate totali: %d\n\n ", nsol, calls);


	return 0;
}