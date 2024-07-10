#include "elemtype.h"

int main(void) {

	ElemType test[] = {
		{.name = "Marco", .street = "via Yemen", .number = 88, .city = "Fortnite", .province = "Bo", .postal_code = "41100"}, 
		{.name = "Marcone", .street = "via Yemen", .number = 88, .city = "Fortnite", .province = "Bo", .postal_code = "41100"},
		{.name = "Aldonissmo", .street = "via Yemen", .number = 88, .city = "Fortnite", .province = "Bo", .postal_code = "41100"}
	};
	int res = ElemCompare(&test[1], &test[1]);
	printf("il valore della compare e': %d\n\n", res);
	ElemWriteStdout(test);
	printf("\n\n"); 

	return 0; 
}