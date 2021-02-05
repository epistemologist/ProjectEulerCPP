#include <iostream>
#include <vector>

using namespace std;

int pow(int n) {
	return 1 - ((n & 1) << 1); // Returns (-1)^n
}

// OEIS A001318
// a(n) = (6*n^2 + 6*n + 1)/16 - (2*n + 1)*(-1)^n/16
int g(int n) {
	return (6*n*n+6*n+1 - (2*n+1)*pow(n))/16;
}

// We use Euler's pentagonal theorem

int main() {
	int MOD = 1000000;
	vector<int> POWERS = {1,1,-1,-1};
	vector<int> p = {1,1};
	while (p.size() < 56000) {
		int n = p.size();
		int next_term = 0;
		for (int i = 1; g(i) <= n; i++) {
			next_term += POWERS[(i-1)%4]*p[n-g(i)];
			next_term += MOD;
			next_term %= MOD;
		}
		p.push_back(next_term);
		if (next_term == 0) {
			std::cout << p.size()-1 << std::endl;
			return 0;
		}
	}
}

