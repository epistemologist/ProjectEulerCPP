#include <iostream>
using namespace std;

bool is_prime(unsigned long n) {
	if (n <= 2) return n==2 ? 1 : 0;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	for (int n = 9;;n++) {
		// Try to write n = p + 2*s*s
		bool goldbach = true;
		for (int s = 1; 2*s*s <= n && goldbach; s++) {
			int p = n-2*s*s;
			if (is_prime(p)) {
				goldbach = false;
			}
		}
		if (goldbach && n%2 != 0 && !is_prime(n)) {
			std::cout << n << std::endl;
			return 0;
		}
	}
}
