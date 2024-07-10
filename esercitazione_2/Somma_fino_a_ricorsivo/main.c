//Creare il file somma.c che consenta di utilizzare la seguente funzione :
//extern intSommaFinoA(intn);
//La funzione accetta come parametro un numero intero positivo ne ritorna
//la somma dei primi n numeri naturali (0 escluso) calcolata ricorsivamente.
//Nel caso che n sia minore o uguale a 0 la funzione deve ritornare - 1.

#include <stdio.h>

int SommaFinoAricorsivo(int n, int sum) {

	if (n == 1) {
		return sum + 1;
	}

	return SommaFinoAricorsivo(n - 1, n + sum);    //utile usare la ricorsione di coda perchè il compilatore
													   //è in grado di ottimizzare tutti i return -> una volta arrivato alla fine 
											           //ritorna direttamente il risultato senza risalire lo stack 
}


int SommaFinoA(int n) {

	if (n <= 0) {			//se ho da effettuare un controllo sui parametri passati alla funzione, spesso conviene creare una funzione intermedia (proxy)
		return -1;			//che faccia il controllo -> evito di effettuare il controllo all'inizio di ogni chiamata ricorsiva (spreco di risorse)
	}

	return SommaFinoAricorsivo(n, 0);
}


int main(void) {

	int n = 5; 
	int res = SommaFinoA(n);
	
	printf("la somma dei primi %d numeri e': %d", n, res);
	
	return 0; 
}















