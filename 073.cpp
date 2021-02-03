#include <iostream>
#include <vector>

using namespace std;

// Note that this sequence is a Farey sequence
// We use https://en.wikipedia.org/wiki/Farey_sequence#Next_term to generate the corresponding terms

bool check_fraction(int num, int den) {
	return (2*num < den) && (den < 3*num);
}

int main() {
	int out = 0;
	int n = 12000;
	int a = 0; int b = 1; int c = 1; int d = n;
	int new_a, new_b, new_c, new_d; // Temporary variables
	while (c <= n) {
		int k = (n+b) / d;
		new_a = c; new_b = d, new_c = k*c-a; new_d = k*d-b; // Find new values
		a = new_a; b = new_b; c = new_c; d = new_d; // Update values
		if (check_fraction(a,b)) out++;
	}
	std::cout << out << std::endl;
}

