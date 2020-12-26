int divisor_sum(int n) {
	int out = 1;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			out += i;
			out += n/i;
		}
		if (i*i == n) {
			out -= i;
		}
	}
	return out;
}
