#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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

// Inspired by https://euler.stephan-brumme.com/toolbox/#bignum

class BigInt {
	string n;
public:
	BigInt(const string& initial) : n(initial) {}

	friend ostream& operator<<(ostream& out, const BigInt& num);

	BigInt operator+(const BigInt& other) const {
		return BigInt(add_string(n, other.n));
	}

	BigInt operator*(const BigInt& other) const {
		return BigInt(multiply_string(n, other.n));
	}

	bool operator<(const BigInt& other) {
		if (n.length() < other.n.length()) return true;
		if (n.length() > other.n.length()) return false;
		for (int i = n.length()-1; i >= 0; i--) {
			if (n.at(i) < other.n.at(i)) return true;
		}
		return false;
	}

	bool operator==(const BigInt& other) {
		return n.compare(other.n) == 0;
	}

};

std::ostream& operator<<(ostream& out, const BigInt& num) {
	out << num.n;
	return out;
}

