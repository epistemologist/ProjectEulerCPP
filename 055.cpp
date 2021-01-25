#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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

bool is_lychrel(int n) {
	string s = to_string(n);
	for (int i = 0; i <= 50; i++) {
//		std::cout << s << " " << string(s.rbegin(), s.rend()) << std::endl;
		if (i>0 && s.compare(string(s.rbegin(), s.rend())) == 0) return false;
		s = add_string(s, string(s.rbegin(), s.rend()));
	}
	return true;
}

int main() {
	int out = 0;
	for (int i = 1; i < 10000; i++) {
		if (is_lychrel(i)) {
			out++;
		}
	}
	std::cout << out << std::endl;
}
