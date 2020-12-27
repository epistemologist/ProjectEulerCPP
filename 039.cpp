#include <iostream>
using namespace std;

int num_triangles(int p) {
	int out = 0;
	for (int a = 1; a < p; a++) {
		for (int b = 1; b < a; b++) {
			int c = p-a-b;
			if (c > 0 && a*a + b*b == c*c) out++;
		}
	}
	return out;
}

int main() {
	int out = 0;
	int max_sols = 0;
	for (int i = 1; i < 1000; i++) {
		int temp = num_triangles(i);
		if (temp > max_sols) {
			out = i;
			max_sols = temp;
		}
	}
	std::cout << out << std::endl;
}
