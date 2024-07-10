int ProdottoRicorsivo(int a, int b) {

	if (b == 0) {
		return 0;
	}

	return a + ProdottoRicorsivo(a, b - 1);
}

int Prodotto(int a, int b) {

	if (b < 0 || a < 0) {
		return -1;
	}

	return ProdottoRicorsivo(a, b);
}