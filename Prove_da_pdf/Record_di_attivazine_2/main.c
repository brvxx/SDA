#include <stdio.h>
#include <stdlib.h>
int f(int i, int j, int k)
{
	int* a;
	a = (int*)malloc(3 * sizeof(int));
	if (i - j >= k + j) return i + 2;
	*a = 2 * f(j - k, i, j);
	*(a + 1) = *a + k;
	printf("\nValori: %d %d", *a, *(a + 1));
	return (*(a));
}
int main()
{
	int a = 1, b = 2;
	printf("\nRisultato: %d", f(a, b, a + b) + f(a, b, b - a));
}