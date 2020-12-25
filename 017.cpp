#include <iostream>
#include <string>
#include <vector>
using namespace std;

string num_to_words(int n) {
	vector<string> small_nums{ "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	vector<string> teens{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	if (n < 20) {
		return small_nums[n];
	} else if (n < 100) {
		return teens[n/10] + small_nums[n%10];
	} else if (n%100 == 0) {
		return small_nums[n/100] + "hundred";
	} else if (n < 1000) {
		return small_nums[n/100] + "hundredand" + num_to_words(n%100);
	} else if (n == 1000) {
		return "onethousand";
	} else {
		return "";
	}
}

int main() {
	string out;
	for (int i = 0; i <= 1000; i++) {
		out += num_to_words(i);
	}
	std::cout << out.size() << std::endl;
	return 0;
}
