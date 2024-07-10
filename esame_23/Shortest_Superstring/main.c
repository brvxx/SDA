#include <stdlib.h>
#include <stdio.h>

extern char* SolveSuperstring(const char** v, size_t v_size);

int main(void) {

	char* arr[] = { "ABCDH", "DHE", "BCDH", "HEF" };
	size_t size = sizeof(arr) / sizeof(arr[0]); 

	char* res = SolveSuperstring(arr, size); 

	printf("%s", res); 

	return 0; 
}