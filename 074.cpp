#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> FACTORIAL = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int get_factorial_sum(int n) {
	int out = 0;
	for (char i: to_string(n)) {
		out += FACTORIAL[i-'0'];
	}
	return out;
}

int get_period(int n) {
	unordered_set<int> chain;
	int next_term = n;
	chain.insert(n);
	while (1) {
		next_term = get_factorial_sum(next_term);
		if (chain.count(next_term) != 0) return chain.size();
		chain.insert(next_term);
	}
}

int main() {
	int out = 0;
	for (int i = 1; i < 1000000; i++) {
		if (get_period(i) == 60) out++;
	}
	std::cout << out << std::endl;
}
