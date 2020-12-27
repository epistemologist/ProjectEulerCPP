#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cancellable(int num, int den) {
	if (num >= den) return false;
	if (num % 11 == 0 || den % 11 == 0) return false;
	if (num % 10 == 0 || den % 10 == 0) return false;
	string num_string = to_string(num);
	string den_string = to_string(den);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (num_string.at(i) == den_string.at(j)) {
				int n = num_string.at(abs(1-i)) - '0';
				int d = den_string.at(abs(1-j)) - '0';
				if (n*den == d*num) return true;
			}
		}
	}
	return false;
}

int main() {
	int n = 1;
	int d = 1;
	for (int num = 10; num < 100; num++) {
		for (int den = 10; den < 100; den++) {
			if (cancellable(num, den)) {
				n *= num;
				d *= den;
			}
		}
	}
	std::cout << d / __gcd(n,d) << std::endl;
}
