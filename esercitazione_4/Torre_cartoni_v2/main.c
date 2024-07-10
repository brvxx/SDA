#include "torrecartoni.h"

extern void TorreCartoni(const Cartone* c, size_t n);

int main(void) {

	Cartone arr[] = {
		{.p = 10,.a = 20,.l = 40 },
		{.p = 10,.a = 10,.l = 9},
		{.p = 9,.a = 3,.l = 5 }
	}; 
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	TorreCartoni(arr, size); 

	return 0; 
}