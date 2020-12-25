#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	// Read file
	string line;
	vector<string> numbers;
	ifstream file ("./data/013.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.size() > 0) numbers.push_back(line);
		}
		file.close();
	}
	// Sum the numbers;
	int digit_sums[50];
	for (string n: numbers) {
		for (int i = 0; i < 50; i++) {
			digit_sums[i] += n.at(i) - '0';
		}
	}
	// Propogate carries
	for (int i = 49; i > 0; i--) {
		if (digit_sums[i] > 10) {
			int temp = digit_sums[i];
			digit_sums[i] %= 10;
			digit_sums[i-1] += temp/10;
		}
	}
	string sum;
	for (int i: digit_sums) {
		sum += to_string(i);
	}
	std::cout << sum.substr(0,10) << std::endl;
}
