#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

void print_vector(vector<int> arr) {
	for (int i: arr) {
		std::cout << i << ",";
	}
}

int gcd(int x, int y) {
	return __gcd(x,y);
}

int main() {
	int MAX = 1500000;
	int m_max = (int) sqrt(MAX);
	map<int, int> triangle_counts;
	for (int m = 1; m <= m_max; m++) {
		for (int n = 1; n < m; n++) {
			if (gcd(m,n) == 1 && (m+n)%2 == 1) {
				int a = m*m-n*n;
				int b = 2*m*n;
				int c = m*m+n*n; // Primitive Pythagorean triple
				for (int k = 1; k*c <= MAX; k++) {
					int A = k*a;
					int B = k*b;
					int C = k*c;
					vector<int> triple = {A,B,C};
					triangle_counts[A+B+C]++;
				}
			}
		}
	}
	int out = 0;
	for (auto i: triangle_counts) {
		if (i.first <= MAX && i.second == 1) {
			out++;
		}
	}
	std::cout << out << std::endl;
}
