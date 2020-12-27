#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check_string(string s) {
	return stoi(s.substr(1,3)) % 2 == 0 &&
		stoi(s.substr(2,3)) % 3 == 0 &&
		stoi(s.substr(3,3)) % 5 == 0 &&
		stoi(s.substr(4,3)) % 7 == 0 &&
		stoi(s.substr(5,3)) % 11 == 0 &&
		stoi(s.substr(6,3)) % 13 == 0 &&
		stoi(s.substr(7,3)) % 17 == 0;
}

int main() {
	long out = 0;
	string digits = "1234567890";
	do {
		if (check_string(digits)) {
			out += stol(digits);
		}
	} while (std::next_permutation(digits.begin(), digits.end()));
	std::cout << out << std::endl;
}
