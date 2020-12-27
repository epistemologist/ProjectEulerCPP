#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
	if (n < 2) return 1;
	return n * factorial(n-1);
}

int main() {
	int out = 0;
	for (int i = 10; i < 1e7; i++) {
		int temp = 0;
		for (char j: to_string(i)) {
			temp += factorial(j-'0');
		}
		if (temp == i) out += i;
	}
	std::cout << out << std::endl;
}
