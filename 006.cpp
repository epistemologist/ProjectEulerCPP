#include <iostream>

int main() {
	int out = 0;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 1; i <= 100; i++) {
		sum1 += i;
		sum2 += i*i;
	}
	std::cout << sum1*sum1 - sum2 << std::endl;
	return 0;
}
