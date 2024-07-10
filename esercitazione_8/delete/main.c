#include "list.h"

extern Item* Delete(Item* i, const char* name);

int main(void) {

	ElemType arr[] = {
		{.name = "Marco", .street = "via Yemen", .number = 22, .city = "Bologna", .province = "BO", .postal_code = "41120"},
		{.name = "Marcone", .street = "via Mogus", .number = 23, .city = "Napoli", .province = "FN", .postal_code = "41111"},
		{.name = "Aldonissimo", .street = "via Fructus", .number = 18, .city = "Brescia", .province = "BS", .postal_code = "41122"},
		{.name = "Fortnite", .street = "via Neri", .number = 88, .city = "Modena", .province = "MO", .postal_code = "41120"},
		{.name = "Caserta", .street = "via Inshallah", .number = 80, .city = "Varese", .province = "VA", .postal_code = "41103"}
	};
	size_t size = sizeof(arr) / sizeof(arr[0]);

	Item* l1 = ListCreateEmpty();
	for (size_t i = 0; i < size; ++i) {
		l1 = ListInsertBack(l1, arr + i);
	}

	Item* res = Delete(l1, "Marco");
	ListWriteStdout(res); 

	ListDelete(res);

	return 0;
}