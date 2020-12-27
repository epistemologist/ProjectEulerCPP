#include <iostream>
#include <utility>
using namespace std;

int coin_amounts[] = {1,2,5,10,20,50,100,200};
int memo[200][8];
// Recursive function with memoization
int ways(int n, int max_denom) {
	int original_n = n;
	int original_max = max_denom;
	if (max_denom <= 0) return 1;
	if (memo[n][max_denom] != 0) return memo[n][max_denom];
	int out = 0;
	while (n >= 0) {
		out += ways(n, max_denom-1);
		n -= coin_amounts[max_denom];
	}
	memo[original_n][original_max] = out;
	return out;
}

int main() {
	std::cout << ways(200, 7) << std::endl;
	return 0;
}
