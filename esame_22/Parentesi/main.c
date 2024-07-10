#include <stdio.h>

extern int Parentesi(int n);

int main(void) {

	int res = Parentesi(3); 
	printf("numero totale di soluzioni: %d", res); 

	return 0; 
}