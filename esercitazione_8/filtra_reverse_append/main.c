#include "list.h"

extern Item* Filtra(const Item* i, const char* city);
extern Item* Reverse(const Item* i); 
extern Item* Append(const Item* i1, const Item* i2);
extern Item* AppendMod(Item* i1, Item* i2); 

int main(void) {

	ElemType arr[] = {
		{.name = "Marco", .street = "via Yemen", .number = 22, .city = "Modena", .province = "BO", .postal_code = "41120"},
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

	ListWriteStdout(l1); 
	printf("\n\n"); 

	Item* filtered = Filtra(l1, "Modena"); 
	ListWriteStdout(filtered);
	printf("\n\n"); 

	Item* reverse = Reverse(l1); 
	ListWriteStdout(reverse); 
	printf("\n\n"); 

	Item* append = Append(l1, filtered); 
	ListWriteStdout(append); 

	ListDelete(l1);
	ListDelete(filtered);
	ListDelete(reverse);
	ListDelete(append);

	return 0;

}