#include <iostream>
#include <cmath>

bool is_pentagonal(long n) {
	double temp = (sqrt(24*n+1)+1)/6;
	return (temp-floor(temp)) < 1e-12;
}

int main() {
	// Note that all hexagonal numbers are triangular
	for (int i = 144;; i++) {
		if (is_pentagonal(i*(2*i-1))) {
			std::cout << i*(2*i-1) << std::endl;
			return 0;
		}
	}
}
