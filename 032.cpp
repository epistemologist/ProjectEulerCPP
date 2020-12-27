#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	string digits = "123456789";
	unordered_set<int> candidates;
	int out = 0;
	do {
		for (int i = 1; i < 8; i++) {
			for (int j = 1; j < i && i+j < 9; j++) {
				int a = stoi(digits.substr(0,i));
				int b = stoi(digits.substr(i,j));
				int c = stoi(digits.substr(i+j));
				if (a*b == c) candidates.insert(c);
			}
		}
	} while (std::next_permutation(digits.begin(), digits.end()));
	for (int i: candidates) out += i;
	std::cout << out << std::endl;
}
