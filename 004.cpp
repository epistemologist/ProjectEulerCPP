#include <iostream>
#include <string>
using namespace std;

int main() {
	int out = 0;
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			string product = std::to_string(i*j);
			if (product == string(product.rbegin(), product.rend())) {
				if (out < i*j) out = i*j;
			}
		}
	}
	std::cout << out << std::endl;
	return 0;
}
