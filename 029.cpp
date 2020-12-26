#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

int main() {
	unordered_set<double> powers;
	for (int a = 2; a <= 100; a++) {
		for (int b = 2; b <= 100; b++) {
			powers.insert(pow(a,b));
		}
	}
	std::cout << powers.size() << std::endl;
	return 0;
}
