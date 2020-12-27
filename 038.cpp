#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string concat_product(int n) {
	string out = "";
	int i = 1;
	while (out.length() < 9) {
		out += to_string(n*i);
		i++;
	}
	return out;
}

bool is_pandigital(string s) {
	string temp = s;
	std::sort(temp.begin(), temp.end());
	return temp == "123456789";
}

int main() {
	string out = "123456789";
	for (int i = 2; i < 1e6; i++) {
		string temp = concat_product(i);
		if (out < temp && is_pandigital(temp)) {
			out = temp;
		}
	}
	std::cout << out << std::endl;
	return 0;
}
