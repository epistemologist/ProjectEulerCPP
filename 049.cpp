#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <iterator>
#include <algorithm>
using namespace std;

string sort_digits(int n) {
	string s = to_string(n);
	std::sort(s.begin(), s.end());
	return s;
}

bool is_prime(unsigned long n) {
	if (n <= 2) return n==2 ? 1 : 0;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	// Generate small primes
	vector<int> small_primes;
	for (int i = 1000; i < 10000; i++) {
		if (is_prime(i)) small_primes.push_back(i);
	}
	unordered_set<int> prime_set(small_primes.begin(), small_primes.end());
	// Generate all increasing arithemtic sequences and find any with repeated digits
	for (int i = 0; i < small_primes.size(); i++) {
		for (int j = i+1; j < small_primes.size(); j++) {
			int p = small_primes[i];
			int q = small_primes[j];
			int r = q + (q-p);
			if (p == 1487) continue; // Mentioned already in problem
			if (prime_set.find(r) != prime_set.end()) {
				// Sequence found, determine if the three are permutations of each other
				string p_digits = sort_digits(p);
				string q_digits = sort_digits(q);
				string r_digits = sort_digits(r);
				if (p_digits.compare(q_digits) == 0 && p_digits.compare(r_digits) == 0) std::cout << p << q << r << std::endl;
			}
		}
	}
}
