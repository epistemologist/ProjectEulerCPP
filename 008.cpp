#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string number;
	// Read file
	string line;
	ifstream file ("./data/008.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			number += line;
		}
		file.close();
	}
	// Loop through substrings
	unsigned long max_product = 0;
	for (int i = 0; i < number.length()-13; i++) {
		string substring = number.substr(i, 13);
		unsigned long product = 1;
		for (char j: substring) {
			product *= (j - '0');
		}
		if (max_product < product) max_product = product;
	}
	std::cout << max_product << std::endl;
	return 0;
}
