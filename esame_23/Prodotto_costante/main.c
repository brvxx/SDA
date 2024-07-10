#include <stdio.h>
#include <math.h>

extern int* RisolviProdotto(int n, const int* s);

int main(void) {

	int values[] = { -1, 2, 5, 8, 9, 16, 18, 40, 45 };
	int size = sizeof(values) / sizeof(values[0]); 

	int* res = RisolviProdotto((int)sqrt(size), values); 

	int size_sq = (int)sqrt(size); 

	for (int i = 0; i < size_sq; ++i) {
		for (int j = i * size_sq; j < size_sq * i + size_sq; ++j) {
			printf("%d ", res[j]);
		}
		printf("\n"); 
	}

	return 0; 
}