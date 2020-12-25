#include <iostream>
#include <vector>
using namespace std;

vector<int> gen_primes(int max_limit) {
	vector<bool> A(max_limit);
	vector<int> out;
	std::fill(begin(A), end(A), true);
	for (int i = 2; i*i < max_limit; i++) {
		if (A[i]) {
			for (int j = i*i; j < max_limit; j += i) {
				A[j] = false;
			}
		}
	}
	for (int i = 2; i < A.size(); i++) {
		if (A[i]) {
			out.push_back(i);
		}
	}
	return out;
}

int main() {
	vector<int> primes = gen_primes(2000000);
	unsigned long long out = 0;
	for (int p: primes) {
		out += p;
	}
	std::cout << out << std::endl;
	return 0;
}
