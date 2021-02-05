#include <iostream>
#include <vector>

using namespace std;

// These numbers are https://oeis.org/A000041

// We use the formula: a(n) = (1/n) * Sum_{k=0..n-1} sigma(n-k)*a(k), where sigma(k) is the sum of divisors of k

long sigma(int k) {
	long out = 0;
	for (int i = 1; i*i <= k; i++) {
		if (k%i == 0) {
			out += i+k/i;
			if (i*i==k) out -= i;
		}
	}
	return out;
}

int main() {
	vector<long> a = {1,1};
	while (a.size() <= 100) {
		long n = a.size();
		long next_term = 0;
		for (int k = 0; k < n; k++) {
			next_term += sigma(n-k)*a[k];
		}
		next_term /= n;
		a.push_back(next_term);
	}
	std::cout << a[100]-1 << std::endl;
}
