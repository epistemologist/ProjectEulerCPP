#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

regex gen_regex(string number) {
	string out = "[\\d]*";
	for (char i: number) {
		out += i;
		out += "[\\d]*";
	}
	return regex(out);
}

bool check_string(string s, vector<regex>& regexes) {
	for (regex r: regexes) {
		if (!regex_match(s,r)) return 0;
	}
	return 1;
}

int main() {
	string line;
	vector<regex> regexes;
	ifstream file ("./data/079_keylog.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.size() > 0) regexes.push_back(gen_regex(line));
		}
		file.close();
	}
	for (int i = 1;;i++) {
		/*
		cat 079_keylog.txt | sort | uniq -u gives that the password probably starts with a 7
		*/
		if (to_string(i)[0] == '7') {
			if (check_string(to_string(i), regexes)) {
				std::cout << i << std::endl;
				return 0;
			}
		}
//		if (i%10000 == 0) printf("%d\n", i);
	}
}
