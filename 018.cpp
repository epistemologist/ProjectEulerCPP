#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	// Read file
	vector<vector<int>> triangle;
	vector<int> row;
	string line;
	string num;
	ifstream file ("./data/018.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			while (getline(ss, num, ' ')) {
				row.push_back(stoi(num));
			}
			triangle.push_back(row);
			row = vector<int>();
		}
	}
	// Calculate maximum path sum
	for(;;) {
		if (triangle.size() == 1) break;
		int N = triangle.size();
		for (int i = 0; i < triangle[N-2].size(); i++) {
			triangle[N-2][i] += std::max(triangle[N-1][i], triangle[N-1][i+1]);
		}
		triangle.pop_back();
	}
	std::cout << triangle[0][0] << std::endl;
	return 0;
}
