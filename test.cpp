#include <iostream>  
#include <cstdlib>
#include <ctime>
#define ull unsigned long long int

using namespace std;

ull mod_pow(ull a, ull n, ull mod) {
	a %= mod;
	ull out = 1;
	while (n > 0) {
		if (n & 1) {
			out = out * a % mod;
		}
		a = a*a % mod;
		n >>= 1;
	}
	return out;
}

bool miller_rabin(ull n) {
	if (n%2 == 0) return 0;
	ull r = 0;
	ull d = n-1;
	while (d % 2 == 0) {
		r++;
		d /= 2;
	}
	for (int a: {2,3,5,7,11,13,17,19,23,29,31,37,41}) {
		ull x = mod_pow(a,d,n);
		if (x == 1 || x == n-1) continue;
		for (int j = 0; j < r-1; j++) {
			x = (x*x) % n;
			if (x == n-1) continue;
		}
		return 0;
	}
	return 1;
}


int main() {
	std::cout << miller_rabin(1400000249) << std::endl;
}

