#include <stdlib.h>

#include "tree.h"

static void PopulatingNextRec(Node* t, int* cnt, Node*** res) {
	if (TreeIsEmpty(t)) {
		return; 
	}
	PopulatingNextRec(TreeLeft(t), cnt, res); 

	(*cnt)++; 
	int tmp = *cnt; 
	*res = realloc(*res, tmp * sizeof(Node*)); 
	(*res)[tmp - 1] = t; 

	PopulatingNextRec(TreeRight(t), cnt, res);
}

void PopulatingNext(Node* t) {
	Node** res = NULL; 

	int cnt = 0; 

	PopulatingNextRec(t, &cnt, &res); 

	for (int i = 0; i < cnt - 1; ++i) {
		res[i]->next = res[i + 1]; 
	}

	free(res); 
}

/*
osservazione: perché alla funzione ricorsiva passiamo un triplo puntatore piuttosto che un double pointer a Node?

Perché vogliamo far si che la variabile res possa essere modificata, e che la modifica venga vista in tutte le istanze
della ricorsione, piuttosto che nelle singole chiamate. se res (parametro della funzione) fosse un Node**, andando a fare 
res = realloc(res, tmp *  sizeof(Node*)); andremo ad aggiornare effettivamente res, ma questo solo nella chiamata corrente
e per le eventuali chiamate successive. Risalendo però la ricorsione res non verrà aggiornato ma varrà ancora NULL. Ragion per
la quale dobbiamo passare l'indirizzo di questo double pointer, così che aggiorniamo solo il contenuto della memoria punata da res,
quindi dereferenziandolo in altre chiamate avremmo sempre il contenuto di memoria giusto. 

*/