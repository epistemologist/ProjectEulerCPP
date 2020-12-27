#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

string bin_string(int n) {
	string out = bitset<128>(n).to_string();
	out.erase(0, out.find_first_not_of('0'));
	return out;
}

bool palindrome(string s) {
	string temp = s;
	reverse(temp.begin(), temp.end());
	return temp == s;
}

int main() {
	int out = 0;
	for (int i = 1; i < 1000000; i++) {
		if (palindrome(to_string(i)) && palindrome(bin_string(i))) {
			out += i;
		}
	}
	std::cout << out << std::endl;
	return 0;
}
