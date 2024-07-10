int fact(int n) {
	int p = 1; 
	while (n-- > 0) { // mossa tattica del Vincy LOL 
		p *= n;
	}
	return p; 
}

int main(void) {
	int i = 3, y; 

	y = fact(i); 

	return 0; 
}