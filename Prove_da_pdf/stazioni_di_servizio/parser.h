#ifndef PARSER_H_
#define PARSER_H_

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct config_data {
	int stazioni; 
	int serbatoio; 
	double consumo; 
	int* distanze; 
	int* prezzi; 
};

void parse(const char* filename, struct config_data* data);
void data_free(struct config_data* data);

#endif /* PARSER_H_ */
