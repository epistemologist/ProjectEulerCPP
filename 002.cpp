#include <iostream>
using namespace std;

int main() {
	int a = 1;
	int b = 1;
	int temp;
	int out = 0;
	while (a < 4000000) {
		temp = a;
		a = b;
		b = temp+b;
		if (a % 2 == 0) {
			out += a;
		}
	}
	std::cout << out << std::endl;
	return 0;
}
