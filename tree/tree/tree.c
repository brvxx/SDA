// file che contiene le implementazioni delle funzioni primitive e non usate 
// lavore sul tipo di dato astratto albero 
//
// Ricorda che anche se noi chiamiamo tutto Node, nell'effettivo ogni Node è da 
// considerarsi come un albero, infatti ci sarà un Node* che sarà l'effettiva radice 
// del nostro albero in quanto tale, ma tutti gli altri nodi altro non sono che radici 
// di sottoalberi di quell'albero.


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

// funzione che crea un albero vuoto 

Node* TreeCreateEmpty(void) {
	return NULL; 
}


// funzione che dato un elemtype e due sotto alberi crea un nuovo albero avente per radice 
// l'elemtype passato e come figli i due sottoalberi

Node* TreeCreateRoot(const ElemType* e, Node* l, Node* r) {
	Node* t = malloc(sizeof(Node)); 
	t->value = ElemCopy(e); 
	t->left = l; 
	t->right = r; 
	return t; 
}


// predicato che ci dice se un albero sia vuoto o meno --> nel concreto controlla che il puntatore 
// sia NULL o meno. Se l'albero passato è vuoto (Node* NULL) allora la funzione ritorna true

bool TreeIsEmpty(const Node* n) {
	return n == NULL;
}


// funzione che ritorna un puntatore all'elemento contenuto nella radice dell'albero passato. Ovviamente 
// se l'albero passato è vuoto allora la funzione esce con un errore, poiché impossibile leggere la radice 
// di un albero vuoto

const ElemType* TreeGetRootValue(const Node* n) {
	if (TreeIsEmpty(n)) {
		printf("ERROR: Alla funzione 'GetRootValueTree()' e' stato passato un albero vuoto (NULL).\n");
		exit(1);
	}
	else {
		return &n->value;
	}
}


// funzione che ritorna un puntatore al nodo figlio SINISTRO dell'albero passato per riferimento come parametro.
// nota che anche se l'albero passato come parametro fosse vuoto la funzione comunque ritorna NULL e non un errore 
// come accadeva con la GetTail per le liste  

Node* TreeLeft(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL; 
	}
	else {
		return n->left; 
	}
}


// funzione che ritorna un puntatore al nodo figlio DESTRO dell'albero passato per riferimento come parametro.
Node* TreeRight(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	else {
		return n->right;
	}
}


// predicato che ritorna true se e solo se entrambe i figli (dx e sx) del nodo passato per riferimento sono NULL, dunque 
// il nodo considerato si può considerare una foglia dell'albero. 

bool TreeIsLeaf(const Node* n) {
	return TreeLeft(n) == NULL && TreeRight(n) == NULL;
}


// funzione che elimina completamente il nostro albero andando a liberare la memoria allocata nell'heap sia per 
// ogni node, ma anche per tutti gli elemtype che compongono l'albero. Infatti se ElemType "nasconde" un tipo standard 
// la seconda operazione è sostanzialmente inutile, ma per casi di ElemType più complessi la cosa è necessaria. 

void TreeDelete(Node* n) {
	if (TreeIsEmpty(n)) {
		return n; 
	}

	Node* l = TreeLeft(n); 
	Node* r = TreeRight(n); 
	
	ElemDelete(&(n->value)); 

	free(n); 

	TreeDelete(l); 
	TreeDelete(r); 
}


// funzione complementare alla TreeWritePreOrder --> è la funzione che esegue il processo ricorsivo della lettura 
// dei nodi dell'albero in pre-ordine. nota che la funzione è static onde evitare che venga per caso chiamata da qualche 
// altra parte fuori da questo file. Infatti la keyword 'static' serve a limitare la visibilità della funzione, rendendola 
// visibile solo all'interno di questo file e non negli altri. 

static void TreeWritePreOrderRec(const Node* n, FILE* f) {
	if (TreeIsEmpty(n)) {
		return;
	}
	fprintf(f, "\t"); 

	ElemWrite(TreeGetRootValue(n), f);		// scrivo valore del nodo corrente 
	TreeWritePreOrderRec(TreeLeft(n), f);	// chiamata ricorsiva su sottoalbero di sx 
	TreeWritePreOrderRec(TreeRight(n), f);	// chiamata ricorsiva su sottoalbero di dx
}


// funzione per la stampa dei nodi dell'albero attraverso una visita in pre-ordine, quindi scrivendo prima il nodo visitato 
// poi il figlio più a sx e via dicendo. I vari valori dei nodi dell'albero vengono scritti separati da un tab, e la loro scrittura 
// dipende dall'elemtype che si sta usando.

void TreeWritePreOrder(const Node* n, FILE* f) {
	fprintf(f, "albero in PreOrdine: "); 
	if (TreeIsEmpty(n)) {
		fprintf(f, "vuouto!");
	}
	else {
		TreeWritePreOrderRec(n, f); 
	}
	fprintf(f, "\n"); 
}


// funzione che stampa in PreOrdine l'albero passato per riferimento direttamente su stdout

void TreeWriteStdoutPreOrder(const Node* n) {
	TreeWritePreOrder(n, stdout);
}


// stesso procedimento ma per la visita e stampa in ordine 

static void TreeWriteInOrderRec(const Node* n, FILE* f) {
	if (TreeIsEmpty(n)) {
		return;
	}

	TreeWriteInOrderRec(TreeLeft(n), f);

	fprintf(f, "\t"); 
	ElemWrite(TreeGetRootValue(n), f);

	TreeWriteInOrderRec(TreeRight(n), f);

}

void TreeWriteInOrder(const Node* n, FILE* f) {
	fprintf(f, "Albero in Ordine: ");
	if (TreeIsEmpty(n)) {
		fprintf(f, "vuoto!");
	}
	else {
		TreeWriteInOrderRec(n, f);
	}
	fprintf(f, "\n");
}

void TreeWriteStdoutInOrder(const Node* n) {
	TreeWriteInOrder(n, stdout);
}


// stessa cosa ma per la stampa in pre ordine

static void TreeWritePostOrderRec(const Node* n, FILE* f) {
	if (TreeIsEmpty(n)) {
		return;
	}

	TreeWritePostOrderRec(TreeLeft(n), f);
	TreeWritePostOrderRec(TreeRight(n), f);

	fprintf(f, "\t"); ElemWrite(TreeGetRootValue(n), f);
}

void TreeWritePostOrder(const Node* n, FILE* f) {
	fprintf(f, "Albero in PostOrdine: ");
	if (TreeIsEmpty(n)) {
		fprintf(f, "vuoto!");
	}
	else {
		TreeWritePostOrderRec(n, f);
	}
	fprintf(f, "\n");
}

void TreeWriteStdoutPostOrder(const Node* n) {
	TreeWritePostOrder(n, stdout);
}