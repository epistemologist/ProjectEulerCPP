#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// From GeeksforGeeks
string add_string(string s1, string s2) {
	if (s1.length() > s2.length()) {
		std::swap(s1, s2);
	}
	string out = "";
	int n1 = s1.length();
	int n2 = s2.length();
	int diff = n2-n1;
	int carry = 0;
	for (int i = n1-1; i >= 0; i--) {
		int sum = ((s1[i]-'0')+(s2[i+diff]-'0')+carry);
		out.push_back(sum%10 + '0');
		carry = sum/10;
	}
	for (int i = n2-n1-1; i >= 0; i--) {
		int sum = ((s2[i]-'0')+carry);
		out.push_back(sum%10 + '0');
		carry = sum/10;
	}
	if (carry) out.push_back(carry+'0');
	std::reverse(out.begin(), out.end());
	return out;
}

int main() {
	// Generate numerators: https://oeis.org/A001333
	// a(n) = 2 a(n-1) + a(n-2), a(0) = a(1) = 1
	vector<string> numerators = {"1", "1"};
	while (numerators.size() < 1002) {
		string tmp = numerators[numerators.size()-1];
		tmp = add_string(tmp, tmp);
		tmp = add_string(tmp, numerators[numerators.size()-2]);
		numerators.push_back(tmp);
	}
	// Generate denominators: https://oeis.org/A000129
	// same reccurence, except a(0) = 0, a(1) = 1
	vector<string> denominators = {"0", "1"};
	while (denominators.size() < 1002) {
		string tmp = denominators[denominators.size()-1];
		tmp = add_string(tmp, tmp);
		tmp = add_string(tmp, denominators[denominators.size()-2]);
		denominators.push_back(tmp);
	}
	int out = 0;
	for (int i = 2; i < 1002; i++) {
		if (numerators[i].length() > denominators[i].length()) out++;
	}
	std::cout << out << std::endl;
}
