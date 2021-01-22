#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <map>
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
	for (int i: primes) {
		if (i == n || i*i > n) break;
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}


vector<string> gen_masks(int n) {
	vector<string> out;
	string n_str = to_string(n);
	for (int i = 0; i < 10; i++) {
		char c = i+48;
		string s_copy = n_str;
		replace(s_copy.begin(), s_copy.end(), c, '.');
		out.push_back(s_copy);
	}
	return out;
}

vector<int> fill_masks(string s) {
	vector<int> out;
	for (int i = 0; i < 10; i++) {
		char c = i+48;
		string s_copy = s;
		replace(s_copy.begin(), s_copy.end(), '.', c);
		out.push_back(stoi(s_copy));
	}
	return out;
}

/*
int main() {
	vector<int> primes = gen_primes(200000);
	unordered_set<int> prime_set(primes.begin(), primes.end());
	map<string, unordered_set<int>> masks; // masks["1."] -> {10,11,12,...,19}
	for (int p: primes) {
		std::cout << p << std::endl;
		for (string s: gen_masks(p)) {
			if (masks.count(s) > 0) {
				if (masks[s].find(p) == masks[s].end()) {
					masks[s].insert(p);
				}
			} else {
				unordered_set<int> tmp;
				tmp.insert(p);
				masks.insert(std::pair<string, unordered_set<int>>(s,tmp));
			}
		}
	}
	int out = 100000000;
	for (auto &i: masks) {
		unordered_set<int> family = i.second;
		std::cout << i.first << " ";
		for (int j: family) {
			std::cout << j << ",";
		}
		std::cout << " " << family.size() << std::endl;
		std::cout << std::endl;
	}	
}
*/

int main() {
	vector<int> primes = gen_primes(1000000);
	// First, generate small masks
	for (int p: primes) {
		for (string mask: gen_masks(p)) {
			// Then fill in the masks and count the primes
			vector<int> potential_primes;
			for (int i: fill_masks(mask)) {
				if (fast_is_prime(primes, i) && i >= p) potential_primes.push_back(i);
			}
			if (potential_primes.size() == 8) {
				std::cout << p << std::endl; 
				/*
				std::cout << mask << std::endl;
				for (int i: potential_primes) {
					std::cout << i << ",";
				}
				std::cout << std::endl;
				*/
				return 0;
			}
		}
	}
}
