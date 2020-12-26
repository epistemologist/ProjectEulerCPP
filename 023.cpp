#include <iostream>
#include <unordered_set>
using namespace std;

int d(int n) {
	int out = 1;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			out += i;
			out += n/i;
		}
		if (i*i == n) {
			out -= i;
		}
	}
	return out;
}

int main() {
	unordered_set<int> abundant_nums;
	int MAX = 28123;
	// Find all abundant numbers below given maximums
	for (int i = 0; i < MAX; i++) {
		if (d(i) > i) {
			abundant_nums.insert(i);
		}
	}
	std::cout << abundant_nums.size() << std::endl;
	// Find all numbers that cannot be written as the sum of two abundant numbers
	int out = 0;
	for (int i = 24; i < MAX; i++) {
		bool can_sum = true;
		for (int j = 1; j < i; j++) {
			if (abundant_nums.count(j) > 0 && abundant_nums.count(i-j) > 0) {
				can_sum = false;
			}
		}
		if (can_sum) {
			out += i;
//			std::cout << i << std::endl;
		}
	}
	return 0;
}
