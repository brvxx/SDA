#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static bool PowerRec(int num, int* cnt) {
	if (num == 1) {
		return true; 
	}
	if (num % 4 != 0 || num == 0) {
		return false; 
	}

	(*cnt)++; 
	num /= 4; 

	return PowerRec(num, cnt); 
}

int main(int argc, char** argv) {
	if (argc != 2) {
		return 1; 
	}

	char* endptr; 
	int num = strtol(argv[1], &endptr, 10); 

	int cnt = 0; 
	bool res = PowerRec(num, &cnt); 

	res ? printf("4^%d = %d", cnt, num) : printf("!p4");

	return 0; 
}