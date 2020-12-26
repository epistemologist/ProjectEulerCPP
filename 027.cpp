#include <iostream>
using namespace std;

bool is_prime(long n) {
	if (n < 2) return false;
	if (n == 2) return true;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	int a_max, b_max;
	int max_primes = 1;
	for (int b=-1000; b<=1000; b++) {
		for (int a=-999; a<=999; a++) {
			if (!is_prime(b)) continue;
			int n = 0;
			while (is_prime(n*n + a*n + b)) {
				n++;
			}
			if (n > max_primes) {
				a_max = a;
				b_max = b;
				max_primes = n;
			}
		}
	}
	std::cout << a_max*b_max << std::endl;
}

