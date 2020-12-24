#include <iostream>
#include <numeric>
using namespace std;

// Note: compile with g++ -std=c++17 005.cpp && ./a.out

int main() {
	int out = 1;
	for (int i = 2; i <= 20; i++) {
		out = std::lcm(out, i);
	}
	std::cout << out << std::endl;
	return 0;
}
