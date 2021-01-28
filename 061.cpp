#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <stack>
using namespace std;

const int LENGTH = 6;

// Utility function for getting string from vector;

string to_string(vector<int> v) {
	string out;
	for (int i: v) {
		out += to_string(i) + ",";
	}
	return out;
}

vector<int> get_neighbors(map<int,int>& fig_numbers, int N) {
	vector<int> out;
	for (auto i: fig_numbers) {
		if (N%100 == (i.first)/100) out.push_back(i.first);
	}
	return out;
}

// Recursive Search
vector<int> search(map<int,int>& fig_numbers, bitset<LENGTH> found, vector<int> out) {
	// std::cout << to_string(out) << " " << found << std::endl;
	// Base Case
	if (out.empty()) {
		for (auto i: fig_numbers) {
			int N = i.first;
			int n = i.second;
			bitset<LENGTH> tmp_found(found);
			tmp_found.set(n);
			out.push_back(N);
			vector<int> tmp = search(fig_numbers, tmp_found, out);
			if (!tmp.empty()) return tmp;
			out.pop_back();
		}
	}
	// Termination Criterion: out is of valid length
	if (out.size() == LENGTH) {
		// Make sure it's cyclic!
		if (found.all() && out[out.size()-1]%100 == out[0]/100) return out; 
		else return vector<int>();
	}
	// Recursive case
	for (int next: get_neighbors(fig_numbers, out[out.size()-1])) {
		bitset<LENGTH> tmp_found(found);
		tmp_found.set(fig_numbers[next]);
		out.push_back(next);
		vector<int> tmp = search(fig_numbers, tmp_found, out);
		if (!tmp.empty()) return tmp;
		out.pop_back();
	}
	// Failed
	return vector<int>();
}

int main() {
	map<int,int> fig_pairs;
	for (int i = 0; i <= 200; i++) {
		vector<int> polygonal_nums = {
			(i*(i-1))/2, i*i, (i*(3*i-1))/2, i*(2*i-1), (i*(5*i-3))/2, i*(3*i-2)
		};
		for (int j = 0; j < polygonal_nums.size(); j++) {
			if (1000 <= polygonal_nums[j] && polygonal_nums[j] < 10000) {
				fig_pairs.insert(pair<int,int>(polygonal_nums[j],j));
			}
		}
	}
	vector<int> out;
	vector<int> found = search(fig_pairs, bitset<LENGTH>() ,out);
	int sum = 0;
	for (int i: found) sum += i;
	std::cout << sum << std::endl;
}
