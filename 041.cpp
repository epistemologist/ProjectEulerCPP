#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<bool> gen_primes(int max_limit) {
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
	A[0] = false; A[1] = false;
	return A;
}

bool is_pandigital(string s) {
	string temp = s;
	std::sort(temp.begin(), temp.end());
	for (int i = 0; i < s.size(); i++) {
		if (temp.at(i) != '0'+i+1) {
			return false;
		}
	}
	return true;
}

int main() {
	vector<bool> primes = gen_primes(87654321);
	for (int i = primes.size()-1; i >= 0; i--) {
		if (primes[i] && is_pandigital(to_string(i))) {
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}




