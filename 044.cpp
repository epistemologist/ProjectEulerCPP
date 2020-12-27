#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int P(int n) {
	return n*(3*n-1)/2;
}

bool is_pentagonal(int n) {
	double temp = (sqrt(24*n+1)+1)/6;
	return abs(temp-floor(temp)) < 1e-8;
}

int main() {
	for (int i = 1;; i++) {
		for (int j = 1; j < i; j++) {
			if (is_pentagonal(P(i)+P(j)) && is_pentagonal(abs(P(i)-P(j)))) {
				std::cout << abs(P(i)-P(j)) << std::endl;
				return 0;
			}
		}
	}
	return 0;
}

