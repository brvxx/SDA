#include <stdlib.h> 

#include "gioielli.h"

extern Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);

int main(void) {

	size_t size = 0; 
	Gioiello* res = CompraGioielli("gioielli_1.txt", 100, &size);

	return 0; 
}
