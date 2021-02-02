#include <vector>

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
