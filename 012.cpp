#include <iostream>

int num_divisors(int n) {
	int out = 0;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			out+=2;
			if (i*i==n) {
				out--;
			}
		}
	}
	return out;
}

int main() {
	for (int i = 1;; i++) {
		if (num_divisors(i*(i+1)/2) > 500) {
			std::cout << i*(i+1)/2 << std::endl;
			break;
		}
	}
	return 0;
}

