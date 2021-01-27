#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#define ull unsigned long long int

using namespace std;

bool is_prime(unsigned long n) {
	if (n <= 2) return n==2 ? 1 : 0;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}


ull mod_pow(ull a, ull n, ull mod) {
	ull out = 1;
	a %= mod;
	while (n > 0) {
		if (n % 2 == 1) {
			out = (out*a) % mod;
		}
		n >>= 1;
		a = (a*a) % mod;
	}
	return out;
}

bool witness(ull n, ull d, ull a) {
	ull x = mod_pow(a,d,n);
	if (x == 1 || x == n-1) return true;
	while (d != n-1) {
		x = (x*x) % n;
		d *= 2;
		if (x == 1) return false;
		if (x == n-1) return true;
	}
	return false;
}

bool miller_rabin(ull n) {
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;
	ull d = n-1;
	while (d%2 == 0) d/=2;
	for (ull a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (!witness(n, d, a)) return false;
	}
	return true;
}



bool check_primes(vector<int> primes) {
	for (int i = 0; i < primes.size(); i++) {
		for (int j = 0; j < primes.size(); j++) {
			ull ij = stoull(to_string(primes[i]) + to_string(primes[j]));
			// std::cout << ij << " " << miller_rabin(ij) << std::endl;
			if (i!=j && !miller_rabin(ij)) return false;
		}
	}
	return true;
}

int main() {
	vector<int> primes;
	map<int, vector<int>> prime_pairs;
	map<int, unordered_set<int>> prime_sets;
	for (int i = 2; i < 10000; i++) {
		if (is_prime(i)) primes.push_back(i);
	}
	for (int i = 0; i < primes.size(); i++) {
		vector<int> tmp;
		for (int j = i+1; j < primes.size(); j++) {
			string i_str = to_string(primes[i]);
			string j_str = to_string(primes[j]);
			ull ij = stoull(i_str+j_str);
			ull ji = stoull(j_str+i_str);
			if (miller_rabin(ij) && miller_rabin(ji)) {
				tmp.push_back(primes[j]);
			}
		}
		if (!tmp.empty()) {
			unordered_set<int> tmp_set(tmp.begin(), tmp.end());
			prime_pairs.insert(pair<int, vector<int>>(primes[i], tmp));
			prime_sets.insert(pair<int, unordered_set<int>>(primes[i], tmp_set));
		}
	}
//	std::cout << prime_pairs.size() << std::endl;
	for (auto p1: primes) {
		for (auto p2: prime_pairs[p1]) {
			for (auto p3: prime_pairs[p2]) {
				for (auto p4: prime_pairs[p3]) {
					for (auto p5: prime_pairs[p4]) {
						vector<int> p = {p1,p2,p3,p4,p5};
						if (check_primes(p)) {
							// printf("%d %d %d %d %d\n", p1,p2,p3,p4,p5);
							int sum = p1+p2+p3+p4+p5;
							std::cout << sum << std::endl;
							return 0;
						}
					}
				}
			}
		}
	}
}

