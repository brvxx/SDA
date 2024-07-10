int DivisioneRec(int a, int b) {

	if (b > a) {
		return 0;
	}

	return 1 + DivisioneRec(a - b, b);
}

int Divisione(int a, int b) {
	
	if (b <= 0 || a < 0) {
		return -1;
	}

	return DivisioneRec(a, b);
}