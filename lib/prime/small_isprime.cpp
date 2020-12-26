bool is_prime(unsigned long n) {
	if (n <= 2) return n==2 ? 1 : 0;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}
