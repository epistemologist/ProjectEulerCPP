#include <iostream>
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
	int out = 0;
	for (int i = 2; i < 10000; i++) {
		int temp = d(i);
		if (d(temp) == i && temp != i) {
			out += i;
		}
	}
	std::cout << out << std::endl;
	return 0;
}

