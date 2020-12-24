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
	int p = 3;
	int count = 2;
	for (;;p+=2) {
		if (is_prime(p)) count++;
		if (count > 10001) break;
	}
	std::cout << p << std::endl;
	return 0;
}
