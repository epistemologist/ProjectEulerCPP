#include <iostream>
using namespace std;

int main() {
	int out = 0;
	for (int i = 0; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			out += i;
		}
	}
	std::cout << out << std::endl;
	return 0;
}
