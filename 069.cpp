#include <iostream>
#include <vector>

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
	vector<int> totient = generate_totient(1000000);
	double ratio = 0;
	int out = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (1.*i/totient[i] > ratio) {
			ratio = 1.*i/totient[i];
			out = i;
		}
	}
	std::cout << out << std::endl;
}
