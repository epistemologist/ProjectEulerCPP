#include <iostream>
#include <string>
using namespace std;

int main() {
	string c = "";
	for (int i = 1; i <= 1000000; i++) {
		c += to_string(i);
	}
	int out = 1;
	c = "x" + c;
	for (int i: {1,10,100,1000,10000,100000,1000000}) {
		out *= c.at(i) - '0';
	}
	std::cout << out << std::endl;
	return 0;
}

