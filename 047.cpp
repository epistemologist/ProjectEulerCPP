#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

bool is_prime(unsigned long n) {
	if (n <= 2) return n==2 ? 1 : 0;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

vector<int> prime_factors(long n) {
	vector<int> out;
	for (int i = 2; i <= n; i++) {
		if (n%i == 0 && is_prime(i)) {
			out.push_back(i);
			while (n%i==0) n /= i;
		}
		if (n == 1) break;
	}
	return out;
}

int main() {
	int prev_seen[] = {0,0,0,0};
	int goal_array[] = {4,4,4,4};
	int i;
	for (i = 2;;i++) {
		int temp = prime_factors(i).size();
		for (int j = 0; j < 4 ; j++) prev_seen[j] = prev_seen[j+1];
		prev_seen[3] = temp;
		// printf("%d [%d, %d, %d, %d]\n", i, prev_seen[0], prev_seen[1], prev_seen[2], prev_seen[3]);
		if (std::equal( begin(prev_seen), end(prev_seen), begin(goal_array))) break;
	}
	std::cout << i-3 << std::endl;
}

