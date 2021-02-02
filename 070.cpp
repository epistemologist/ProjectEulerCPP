#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// code from https://medium.com/@iamcrypticcoder/calculate-euler-function-using-sieve-dbff3cf82847
vector<int> generate_totient(int MAX) {
	vector<int> out(MAX+1, 0);
	out[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		if (out[i] == 0) {
			out[i] = i-1;
			for (int j = (i << 1); j <= MAX; j += i) {
				if (out[j] == 0) out[j] = j;
				out[j] = out[j] / i * (i-1);
			}
		}
	}
	return out;
}

int main() {
	vector<int> totient = generate_totient(10000000);
	double ratio = 10000;
	int out = 0;
	for (int i = 2; i < 10000000; i++) {
		string str_i = to_string(i);
		string str_totient = to_string(totient[i]);
		double ratio_tmp = 1.*i/totient[i];
		if (is_permutation(str_i.begin(), str_i.end(), str_totient.begin(), str_totient.end())) {
			if (ratio_tmp < ratio) {
				ratio = ratio_tmp;
				out = i;
			}
		}
	}
	std::cout << out << std::endl;
}
