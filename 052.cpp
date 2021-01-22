#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;
string sort_string(int n) {
	string s = to_string(n);
	sort(s.begin(), s.end());
	return s;
}

int main() {
	for (int i = 1;; i++) {
		bool flag = true;
		for (int k = 1; k < 7; k++) {
			if (sort_string(i).compare(sort_string(k*i))) flag = false;
		}
		if (flag) {
			std::cout << i <<std::endl;
			return 0;
		}
	}
}
