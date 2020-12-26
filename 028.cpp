#include <iostream>
using namespace std;

int main() {
	int out = 0;
	for (int n = 0; n <= 500; n++) {
		out += (n==0) ? 1 : 4*(2*n+1)*(2*n+1)-12*n;
	}
	std::cout << out << std::endl;
}
