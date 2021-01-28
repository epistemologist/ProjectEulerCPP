#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <cmath>
#define ull unsigned long long int

using namespace std;

vector<string> unique_permutations(string s) {
	unordered_set<string> out;
	do {
		out.insert(s);
	} while (next_permutation(s.begin(), s.end()));
	return vector<string>(out.begin(), out.end());
}

int count_cubes(unordered_set<ull>& cubes, ull i) {
	string s = to_string(i*i*i);
	int out = 0;
	for (string s: unique_permutations(s)) {
		if (cubes.find(stoull(s)) != cubes.end()) out++;
	}
	return out;
}


// For debugging purposes
void print_cubes(unordered_set<ull>& cubes, ull i) {
	string s = to_string(i*i*i);
	for (string s: unique_permutations(s)) {
		if (cubes.find(stoull(s)) != cubes.end()) {
			std::cout << s << " " << cbrt(stoull(s)) << std::endl;
		}
	}
}


int main() {
	unordered_set<ull> cubes;
	for (ull i = 0; i < 1000000; i++) {
		cubes.insert(i*i*i);
	}
	for (ull i = 0; i < 1000000; i++) {
		if (count_cubes(cubes, i) == 5) {
			print_cubes(cubes, i);
			std::cout << i*i*i << std::endl;
			return 0;
		}
	}
}
