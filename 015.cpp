#include <iostream>
using namespace std;
unsigned long long memo[40][40];
unsigned long long ncr(int n, int k) {
	if (k == 0 || k == n) return 1;
	if (memo[n][k] != 0) return memo[n][k];
	else {
		memo[n][k] = ncr(n-1,k-1) + ncr(n-1,k);
		return memo[n][k];
	}
}

int main() {
	std::cout << ncr(40,20) << std::endl;
}
