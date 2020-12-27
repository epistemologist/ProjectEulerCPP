#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_triangular(int n) {
	// n is triangular <=> 8*n+1 is square
	int temp = sqrt(8*n+1);
	return (temp*temp)==8*n+1;
}
int main() {
	// Read file
	ifstream file ("./data/042_words.txt");
	vector<string> words;
	string temp;
	string word;
	if (file.is_open()) {
		while (getline(file, temp)) {
			stringstream ss(temp);
			while (getline(ss, word, ',')) {
				words.push_back(word);
			}
		}
	}
	int out = 0;
	for (string s: words) {
		int word_total = 0;
		for (char i: s) {
			word_total += i - 'A' + 1;
		}
		if (is_triangular(word_total)) out++;
	}
	std::cout << out << std::endl;
	return 0;
}
