#include <iostream>

#define ull unsigned long long

int main() {
	ull out = 0;
	ull MOD = 10000000000;
	for (int i = 1; i <= 1000; i++) {
		ull temp = 1;
		for (int j = 1; j <= i; j++) {
			temp *= i;
			if (temp > MOD) temp %= MOD;
		}
		out += temp;
	}
	std::cout << out%MOD << std::endl;
}
