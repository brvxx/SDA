#include "torrecartoni.h"

void TorreCartoniRec(const Cartone* c, size_t n, int i, unsigned c_height, unsigned* m_height, int cnt, int* m_cnt, unsigned weights, int* vcurr, int* vbest, int* pacchi_presi) {
	
	for (int j = 0; j < (int)n; ++j) {
		if (weights <= c[j].l && pacchi_presi[j] == 0) {
			vcurr[i] = j;
			pacchi_presi[j] = 1;
			weights += c[j].p;
			c_height += c[j].a;
			cnt++;
			
			if (c_height > *m_height) {
				*m_height = c_height;
				*m_cnt = cnt;
				memcpy(vbest, vcurr,n * sizeof(int));
			}

			if (i < (int) (n - 1)) {
				TorreCartoniRec(c, n, i + 1, c_height, m_height, cnt, m_cnt, weights, vcurr, vbest, pacchi_presi);
			}
			pacchi_presi[j] = 0;
			weights -= c[j].p;
			c_height -= c[j].a;
			cnt--;
		}
	}
}

void TorreCartoni(const Cartone* c, size_t n) {
	if (c == NULL) {
		return; 
	}

	int i = 0; 
	unsigned c_height = 0;	
	unsigned m_height = 0;
	unsigned weights = 0; 
	int cnt = 0; 
	int m_cnt = 0; 
	int* vcurr = calloc(n, sizeof(int));
	int* vbest = calloc(n, sizeof(int));
	int* pacchi_presi = calloc(n, sizeof(int));

	TorreCartoniRec(c, n, i, c_height, &m_height, cnt, &m_cnt, weights, vcurr, vbest, pacchi_presi);

	for (int j = 0; j < m_cnt ; ++j) {
		printf("%d\n", vbest[j]);
	}
	printf("Altezza: %d cm", m_height);

	free(vcurr);
	free(vbest);
	free(pacchi_presi);
	
	return; 
}