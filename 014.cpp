#include <iostream>

int collatz_length(unsigned long N) {
	int out = 1;
	for (; N != 1; out++) {
		if (N%2 == 0) {
			N /= 2;
		} else {
			N = 3*N + 1;
		}
	}
	return out;
}

int main() {
	int out = 0;
	int max_length = 0;
	for (int i = 1; i < 1000000; i++) {
		int temp = collatz_length((unsigned long) i);
		if (temp > max_length) {
			out = i;
			max_length = temp;
		}
	}
	std::cout << out << std::endl;
}
