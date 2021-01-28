#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#define ull unsigned long long int

using namespace std;

int main() {
	map<string, vector<ull>> cube_strings;
	for (ull i = 1; i < 10000; i++) {
		ull c = i*i*i;
		string sorted_cube = to_string(c);
		sort(sorted_cube.begin(), sorted_cube.end());
		cube_strings[sorted_cube].push_back(i);
		if (cube_strings[sorted_cube].size() == 5) {
			vector<ull> tmp = cube_strings[sorted_cube];
			ull i_original = *min_element(tmp.begin(), tmp.end());
			std::cout << i_original*i_original*i_original << std::endl;
			return 0;
		}
	}
}
