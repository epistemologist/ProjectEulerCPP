#include <iostream>
#include <vector>

using namespace std;

// Simple dynamic programming
int main() {
	int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	vector<int> out(100,0);
	out[0] = 1;

	for (int p: primes) {
		for (int i = 0; i < out.size(); i++) {
			if (i >= p) out[i] += out[i-p];
		}
	}

	for (int i = 0; i < out.size(); i++) {
		if (out[i] > 5000) {
			std::cout << i << std::endl;
			return 0;
		}
	}
}
