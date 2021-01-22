#include <iostream>

double factorial(int n) {
	double out = 1;
	for (int i = 1; i <= n; i++) {
		out *= i;
	}
	return out;
}

double ncr(int n, int k) {
	return factorial(n) / factorial(k) / factorial(n-k);
}

int main() {
	int out = 0;
	for (int n = 1; n <= 100; n++) {
		for (int r = 1; r <= n; r++) {
			if (ncr(n,r) > 1000000) out++;
		}
	}
	std::cout << out << std::endl;
}
