#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> digits{0,1,2,3,4,5,6,7,8,9};
	int count = 0;
	do {
		count++;
		if (count == 1000000) break;
	} while (next_permutation(digits.begin(), digits.end()));
	for (int i: digits) {
		std::cout << i;
	}
	std::cout << std::endl;
	return 0;
}
