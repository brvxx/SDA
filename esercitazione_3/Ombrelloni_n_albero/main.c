#include <stdio.h>

extern int Ombrelloni(int k, int n);

int main(void) {

	int n = 4;
	int k = 2;



	printf("i modi in cui posizionare %d ragazzi su %d ombrelloni senza che due ragazzi siano adiacenti sono: \n\n", k, n);
	int res = Ombrelloni(k, n);



	return 0;
}