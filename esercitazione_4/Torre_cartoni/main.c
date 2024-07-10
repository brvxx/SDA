#include "torrecartoni.h"

int main(void) {

	size_t n = 3; 
	Cartone v[] = { {.p = 10,.a = 20,.l = 40 }, {.p = 10,.a = 10,.l = 8 }, {.p = 9,.a = 3,.l = 5 } };

	TorreCartoni(v, 3);


	return 0;
}