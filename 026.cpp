#include <iostream>
#include <algorithm>
using namespace std;

int period_length(int n) {
	if (__gcd(n, 10) != 1) return -1;
	int temp = 10;
	int out;
	for (out = 1; temp != 1; out++) {
		temp *= 10;
		temp %= n;
	}
	return out;
}

int main() {
	int out = 0;
	int max_length = 0;
	for (int i = 2; i < 1000; i++) {
		int temp = period_length(i);
		if (max_length < temp) {
			out = i;
			max_length = temp;
		}
	}
	std::cout << out << std::endl;
	return 0;
}
