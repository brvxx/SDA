int Minimo(const int* v, int v_size) {
	
	if (v_size == 1) {
		return v[0];
	}
	
	int minimo = Minimo(v + 1, v_size - 1);
	
	return minimo < v[0] ? minimo : v[0];
}