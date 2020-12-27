#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<bool> gen_primes(int max_limit) {
	vector<bool> A(max_limit);
	std::fill(begin(A), end(A), true);
	for (int i = 2; i*i < max_limit; i++) {
		if (A[i]) {
			for (int j = i*i; j < max_limit; j += i) {
				A[j] = false;
			}
		}
	}
	return A;
}

bool circular_prime(int n, vector<bool> &primes) {
	string n_string = to_string(n);
	for (int i = 0; i < n_string.length(); i++) {
		if (!primes[stoi(n_string)]) return false;
		std::rotate(n_string.begin(), n_string.begin()+1, n_string.end());
	}
	return true;
}

int main() {
	vector<bool> primes = gen_primes(1000000);
	int out = 0;
	for (int i = 2; i < 1000000; i++) {
		if (circular_prime(i, primes)) out++;
	}
	std::cout << out << std::endl;
}
