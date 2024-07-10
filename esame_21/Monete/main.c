#include <stdlib.h>
#include <stdio.h>

extern int CombinaMonete(int b, const int* m, size_t m_size);

int main(void) {
	int m[] = { 1, 2, 50, 10, 5, 20 };
	size_t size = sizeof(m) / sizeof(m[0]); 
	int b = 4; 

	int res = CombinaMonete(b, m, size); 

	printf("\nnumero totale di soluzioni: %d\n\n", res); 

	return 0; 
}