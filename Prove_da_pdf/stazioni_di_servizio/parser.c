#include "parser.h"

void parse(const char* filename, struct config_data* data) {
	FILE* f = fopen(filename, "r");
	char buf[256] = { 0 };
	char* val;

	while (fgets(buf, 256, f)) {
		buf[strcspn(buf, "=")] = 0;
		val = buf + strcspn(buf, "=") + 1;
		if (strcmp(buf, "nstazioni") == 0) {
			sscanf(val, "%d", &(data->stazioni));
		}
		else if (strcmp(buf, "capacita") == 0) {
			sscanf(val, "%d", &(data->serbatoio));
		}
		else if (strcmp(buf, "consumo") == 0) {
			sscanf(val, "%lf", &(data->consumo));
		}
		else if (strcmp(buf, "distanze") == 0) {
			data->distanze = calloc(data->stazioni, sizeof(int));

			val = strtok(val, ",");
			data->distanze[0] = atoi(val);

			for (int i = 1; i < data->stazioni; ++i) {
				val = strtok(NULL, ",");
				data->distanze[i] = atoi(val);
			}
		}
		else if (strcmp(buf, "prezzi") == 0) {
			data->prezzi = calloc(data->stazioni, sizeof(int));

			val = strtok(val, ",");
			data->prezzi[0] = atoi(val);

			for (int i = 1; i < data->stazioni; ++i) {
				val = strtok(NULL, ",");
				data->prezzi[i] = atoi(val);
			}
		}
	}
	fclose(f);
}
void data_free(struct config_data* data) {
	if (data == NULL) {
		return;
	}
	free(data->distanze);
	free(data->prezzi);
}