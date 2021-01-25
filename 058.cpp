#include <iostream>
#include <vector>
#include <unordered_set>

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

bool fast_is_prime(vector<int>& primes, int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	for (int p: primes) {
		if (n%p==0) return 0;
		if (p*p >= n) break;
	}
	return 1;
}

int main() {
	vector<int> primes = gen_primes(10000000);
	int last_diag = 1;
	int delta = 2;
	int primes_seen = 0;
	int total_seen = 1;
	while (1) {
		for (int i = 0; i < 4; i++) {
			// std::cout << last_diag << std::endl;
			total_seen++;
			if (fast_is_prime(primes, last_diag)) {
				primes_seen++;
			}
			last_diag += delta;
		}
		if (((double) primes_seen) / total_seen < 0.1) {
			std::cout << delta+1 << std::endl;
			return 0;
		}
		delta += 2;
	}
}
