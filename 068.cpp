#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// We use this numbering scheme for the 5-gon ring
// https://i.imgur.com/UirgbcE.png


bool check(vector<int> a) {
	vector<int> sums = {
		a[0]+a[1]+a[2],
		a[2]+a[3]+a[4],
		a[4]+a[5]+a[7],
		a[6]+a[7]+a[8],
		a[1]+a[6]+a[9]
	};
	for (int i = 1; i < sums.size(); i++) {
		if (sums[i] != sums[0]) return false;
	}
	return true;
}

string get_string(vector<int> a) {
	vector<vector<int>> triplets = {
		{a[0],a[1],a[2]},
		{a[3],a[2],a[4]},
		{a[5],a[4],a[7]},
		{a[8],a[7],a[6]},
		{a[9],a[6],a[1]}
	};
	vector<int> external_nodes = {a[0], a[3], a[5], a[8], a[9]};
	int min_external_node = *min_element(external_nodes.begin(), external_nodes.end());
	while (triplets[0][0] != min_external_node) {
		rotate(triplets.begin(), triplets.begin()+1, triplets.end());
	}
	vector<int> sums;
	for (vector<int> i: triplets) {
		for (int j: i) {
			sums.push_back(j);
		}
	}
	string out = "";
	for (int i: sums) {
		out += to_string(i);
	}
	return out;
}

int main() {
	vector<int> ring = {1,2,3,4,5,6,7,8,9,10};
	vector<unsigned long long int> valid_strings;
	do {
		if (check(ring)) {
			string s = get_string(ring);
			if (s.length() == 16) valid_strings.push_back(stoull(s));
		}
	} while (next_permutation(ring.begin(), ring.end()));
	std::cout << *max_element(valid_strings.begin(), valid_strings.end()) << std::endl;
}
