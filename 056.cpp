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

string multiply_ten(string s, int n) {
	string out = s;
	for (int i = 0; i < n; i++) out += "0";
	return out;
}

string multiply_string(string s1, string s2) {
	vector<string> mult_table;
	mult_table.push_back("0");
	string x = s1;
	for (int i = 1; i < 10; i++) {
		mult_table.push_back(x);
		x = add_string(x, s1);
	}
	vector<string> temp;
	string s2_reverse;
	s2_reverse.assign(s2);
	std::reverse(s2_reverse.begin(), s2_reverse.end());
	for (int i = 0; i < s2_reverse.size(); i++) {
		temp.push_back(multiply_ten(mult_table[s2_reverse[i]-'0'],i));
	}
	string out = "0";
	for (string i: temp) {
		out = add_string(out, i);
	}
	return out;
}

int pow_digit_sum(int a, int b) {
	string tmp = "1";
	for (int i = 0; i < b; i++) {
		tmp = multiply_string(tmp, to_string(a));
	}
	int out = 0;
	for (int i = 0; i < tmp.length(); i++) {
		out += tmp.at(i) - '0';
	}
	return out;
}

int main() {
	int out = 0;
	for (int a = 1; a < 100; a++) {
		for (int b = 1; b < 100; b++) {
			int tmp = pow_digit_sum(a,b);
			if (out < tmp) out = tmp;
		}
	}
	std::cout << out << std::endl;
}
