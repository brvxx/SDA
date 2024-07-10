#include <stdlib.h>
#include <stdio.h>

extern int OptimalSubarray(const int* v, size_t n);

int main(void) {

	int v[] = { 1, 2, 1, -100, 5, 6 };
	size_t size = sizeof(v) / sizeof(v[0]); 

	int res = OptimalSubarray(v, size); 

	printf("%d", res);

	return 0; 
}