#include<iostream>
#include<vector>
#include<algorithm>
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
	A[0] = false; A[1] = false;
	return A;
}

int main() {
	int out = 0;
	vector<bool> primes = gen_primes(10000000);
	vector<int> primes_list;
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i]) primes_list.push_back(i);
	}
	for (int p: primes_list) {
		bool trunc_prime = true;
		string s = to_string(p);
		for (int i = 0; i < s.length(); i++) {
			for (string temp: {s.substr(0,i), s.substr(i,s.size()-i)}) {
				if (temp.length() > 0) {
					if (!primes[stoi(temp)]) trunc_prime = false;
				}
			}
		}
		if (trunc_prime && p > 10) out += p;
	}
	std::cout << out << std::endl;
	return 0;
}
