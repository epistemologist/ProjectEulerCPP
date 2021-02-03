#include <iostream>
#include <vector>
using namespace std;

// Following "Concrete Mathematics" p117-120, we use the Stern Brocot Tree

// We traverse it like a binary search tree until we find the element that we want with the largest allowed denominator

int MAX_DEN = 1000001;

void recurse(int p1, int q1, int p2, int q2, int& num_out, int& den_out) {
	int next_p = p1+p2;
	int next_q = q1+q2;
	if (next_q >= MAX_DEN) return;
	// printf("%d %d %d %d\n", p1, q1, p2, q2);
	// std::cout << next_p << '/' << next_q << std::endl;
	num_out = next_p;
	den_out = next_q;
	if (next_p * 7 < next_q * 3) return recurse(next_p, next_q, p2, q2, num_out, den_out);
	return recurse(p1, q1, next_p, next_q, num_out, den_out);
}

int main() {
	int num;
	int den;
	recurse(0,1,1,1,num,den);
	std::cout << num << std::endl;
}
