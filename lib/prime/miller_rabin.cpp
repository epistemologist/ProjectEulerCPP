#define ull unsigned long long int

// Adapted from https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/

ull mod_pow(ull a, ull n, ull mod) {
	ull out = 1;
	a %= mod;
	while (n > 0) {
		if (n % 2 == 1) {
			out = (out*a) % mod;
		}
		n >>= 1;
		a = (a*a) % mod;
	}
	return out;
}

bool witness(ull n, ull d, ull a) {
	ull x = mod_pow(a,d,n);
	if (x == 1 || x == n-1) return true;
	while (d != n-1) {
		x = (x*x) % n;
		d *= 2;
		if (x == 1) return false;
		if (x == n-1) return true;
	}
	return false;
}

bool miller_rabin(ull n) {
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;
	ull d = n-1;
	while (d%2 == 0) d/=2;
	for (ull a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (!witness(n, d, a)) return false;
	}
	return true;
}
