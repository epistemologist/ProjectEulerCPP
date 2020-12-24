#include <iostream>
using namespace std;

bool is_prime(unsigned long n) {
	if (n <= 2) {
		return (n == 2) ? 0 : 1;
	}
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	unsigned long out = 600851475143;
	for (int i = 3; ; i += 2) {
		while (out % i == 0) {
			out /= i;
		}
		if (is_prime(out)) {
			break;
		}
	}
	std::cout << out << std::endl;
	return 0;
}
