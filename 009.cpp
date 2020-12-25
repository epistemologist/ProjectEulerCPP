#include <iostream>
using namespace std;

int main() {
	for (int c = 1; c < 1000; c++) {
		for (int b = 1; b < c; b++) {
			for (int a = 1; a < b; a++) {
				if (a+b+c == 1000 && a*a+b*b == c*c) {
					std::cout << (unsigned long) a*b*c << std::endl;
					break;
				}
			}
		}
	}
	return 0;
}
