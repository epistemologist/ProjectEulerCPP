#include <iostream>
using namespace std;

int day_of_week(int y, int m, int d) {
	/*
	from Wikipedia:
	1 <= m <= 12, y > 1752
	*/
	int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
	if (m < 3) y--;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d)%7;
}

int main() {
	int out = 0;
	for (int y = 1901; y <= 2000; y++) {
		for (int m = 1; m <= 12; m++) {
			if (day_of_week(y,m,1) == 0) out++;
		}
	}
	std::cout << out << std::endl;
	return 0;
}
