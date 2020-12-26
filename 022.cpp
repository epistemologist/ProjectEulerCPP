#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	// Read file
	ifstream file ("./data/022_names.txt");
	vector<string> names;
	string temp;
	string name;
	if (file.is_open()) {
		while (getline(file, temp)) {
			stringstream ss(temp);
			while (getline(ss, name, ',')) {
				names.push_back(name);
			}
		}
	}
	std::sort(names.begin(), names.end());
	int out = 0;
	for (int i = 0; i < names.size(); i++) {
		int name_total = 0;
		for (char j: names[i]) {
			name_total += j - 'A' + 1;
		}
		out += (i+1)*name_total;
	}
	std::cout << out << std::endl;
	return 0;
}
