#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
	string a = "1";
	string b = "1";
	string temp;
	int i;
	for (i = 1; a.length() < 1000; i++) {
		temp = a;
		a = b;
		b = add_string(temp,b);
	}
	std::cout << i << std::endl;
	return 0;
}
