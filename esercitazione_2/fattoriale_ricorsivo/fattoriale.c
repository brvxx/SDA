unsigned long long FattorialeRicorsivo(int n) {
	if (n == 0) {
		return 1;
	}

	return n * FattorialeRicorsivo(n - 1);
}

unsigned long long Fattoriale(int n) {
	if (n < 0) {
		return 0;
	}

	return FattorialeRicorsivo(n);
}