#include <stdlib.h>

#include "pulce.h"

const Item* CalcolaPercorso(const Item* start, size_t n) {
	if (DListIsEmpty(start)) {
		return NULL;
	}
	else if (DListGetTail(start) == NULL && DListGetPrev(start) == NULL) {
		return start; 
	}
	int jumps_curr;

	// flag che ci dice la direzione in cui andare: 
	// se direction == true --> muoviti a dx 
	// se direction == false --> muoviti a sx
	bool direction; 

	while (n > 0) {

		jumps_curr = *DListGetHeadValue(start);
		if (!jumps_curr) {
			break; 
		}
		else if (jumps_curr > 0) {
			direction = true; 
		}
		else {
			direction = false; 
		}

		for (int i = 0; i < abs(jumps_curr); ++i) {
			// aggiungo il "rimbalzo" ai bordi della lista
			if (direction == true && DListGetTail(start) == NULL) {
				direction = false; 
			}
			else if (direction == false && DListGetPrev(start) == NULL) {
				direction = true; 
			}

			if (direction) {
				start = DListGetTail(start); 
			}
			else {
				start = DListGetPrev(start);
			}
	
			n--; 
			if (n == 0) {
				break; 
			}
		}
	}
	return start; 
}