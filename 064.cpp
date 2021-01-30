#include <iostream>
#include <vector>
#include <cmath>

// Algorithm from https://en.wikipedia.org/w/index.php?title=Methods_of_computing_square_roots&diff=735222189&oldid=735168876#Continued_fraction_expansion

int get_period(int S) {
	int m = 0;
	int d = 1;
	int a0 = (int) sqrt(S);
	if (a0*a0 == S) return 0;
	int a = a0;
	int out = 0;
	while (a != 2*a0) {
		m = d*a-m;
		d = (S-m*m)/d;
		a = (a0+m)/d;
		out++;
	}
	return out;
}

int main() {
	int out = 0;
	for (int i = 1; i <= 10000; i++) {
		if (get_period(i) % 2 == 1) out++;
	}
	std::cout << out << std::endl;
}
