#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
// For debugging
/*
void print_vec(vector<vector<int>> temp) {
	for (vector<int> row : temp) {
		for (int elem: row) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
}
*/
int main() {
	// Read file
	string line;
	string num;
	vector<vector<int>> grid;
	vector<int> row;
	ifstream file ("./data/011.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream ss(line);
			while (getline(ss, num, ' ')) {
				row.push_back(stoi(num));
			}
			grid.push_back(row);
			row = vector<int>();
		}
	}
	// Find maximum product
	unsigned long max_product = 0;
	unsigned long temp;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i+3 < 20) {
				temp = (unsigned long) grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
				if (temp > max_product) max_product = temp;
			}
			if (j+3 < 20) {
				temp = (unsigned long) grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
				if (temp > max_product) max_product = temp;
			}
			if (i+3 < 20 && j+3 < 20) {
				temp = (unsigned long) grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
				if (temp > max_product) max_product = temp;
			}
			if (i-3>0 && j+3<20) {
				temp = (unsigned long) grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3];
				if (temp > max_product) max_product = temp;
			}
		}
	}
	std::cout << max_product << std::endl;
	return 0;
}
