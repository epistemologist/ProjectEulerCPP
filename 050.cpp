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

int sum(vector<int>& part_sums, int L, int R) { // O(1)
	return part_sums[R] - part_sums[L];
}

int main() {
	vector<int> primes = gen_primes(1000000);
	vector<int> part_sums;
 	unordered_set<int> primes_set(primes.begin(), primes.end());
 	int total = 0;
 	part_sums.push_back(total);
 	for (int i: primes) {
		total += i;
		part_sums.push_back(total);
 	}
	int max_run = 0;
	int out = 0;
	for (int L = 0; L < primes.size(); L++) {
		for (int R = L; R < primes.size(); R++) {
			int curr_sum = sum(part_sums, L, R);
			if (curr_sum > 1000000) break;
			if (primes_set.find(curr_sum) != primes_set.end()) {
				int curr_run = R-L;
				if (max_run < curr_run) {
					out = curr_sum;
					max_run = curr_run;
				}
			}
		}
	}
	std::cout << out << std::endl;
}
