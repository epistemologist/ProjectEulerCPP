#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned char> xor_encrypt(vector<unsigned char> plaintext, vector<unsigned char> key) {
	vector<unsigned char> out;
	for (int i = 0; i < plaintext.size(); i++) {
		out.push_back(plaintext[i] ^ key[i%key.size()]);
	}
	return out;
}

bool is_printable(vector<unsigned char> string) {
	unsigned char min_char = *min_element(string.begin(), string.end());
	unsigned char max_char = *max_element(string.begin(), string.end());
	return 32 >= min_char && max_char >= 128;
}


void guess_key(vector<unsigned char> bytes) {
	string word = "the";
	for (unsigned char b1 = 'a'; b1 <= 'z'; b1++) {
		for (unsigned char b2 = 'a'; b2 <= 'z'; b2++) {
			for (unsigned char b3 = 'a'; b3 <= 'z'; b3++) {
				vector<unsigned char> key = {(unsigned char) b1, (unsigned char) b2, (unsigned char) b3};
				vector<unsigned char> plaintext = xor_encrypt(bytes, key);
				string plaintext_string(plaintext.begin(), plaintext.end());
				int min_char = *min_element(plaintext.begin(), plaintext.end());
				int max_char = *max_element(plaintext.begin(), plaintext.end());
				if (plaintext_string.find(word) != string::npos && max_char < 127) {
					std::cout << "key: " << string(key.begin(), key.end()) << std::endl;
					std::cout << "plaintext: " << string(plaintext.begin(), plaintext.end()) << std::endl;
					std::cout << std::endl;
				}
			}
		}
	}
}

int main() {
	vector<unsigned char> bytes;
	string byte;
	ifstream file ("./data/059_cipher.txt");
	if (file.is_open()) {
		while (getline(file, byte)) {
			bytes.push_back((unsigned char) stoi(byte));
		}
	}
	// guess_key(bytes);
	/*
	Outputs
	key: exp
	plaintext: An extract taken from the introduction of one of Euler's most celebrated papers, "De summis serierum reciprocarum" [On the sums of series of reciprocals]: I have recently found, quite unexpectedly, an elegant expression for the entire sum of this series 1 + 1/4 + 1/9 + 1/16 + etc., which depends on the quadrature of the circle, so that if the true sum of this series is obtained, from it at once the quadrature of the circle follows. Namely, I have found that the sum of this series is a sixth part of the square of the perimeter of the circle whose diameter is 1; or by putting the sum of this series equal to s, it has the ratio sqrt(6) multiplied by s to 1 of the perimeter to the diameter. I will soon show that the sum of this series to be approximately 1.644934066842264364; and from multiplying this number by six, and then taking the square root, the number 3.141592653589793238 is indeed produced, which expresses the perimeter of a circle whose diameter is 1. Following again the same steps by which I had arrived at this sum, I have discovered that the sum of the series 1 + 1/16 + 1/81 + 1/256 + 1/625 + etc. also depends on the quadrature of the circle. Namely, the sum of this multiplied by 90 gives the biquadrate (fourth power) of the circumference of the perimeter of a circle whose diameter is 1. And by similar reasoning I have likewise been able to determine the sums of the subsequent series in which the exponents are even numbers.
	*/
	vector<unsigned char> key = {'e', 'x', 'p'};
	vector<unsigned char> plaintext = xor_encrypt(bytes, key);
	int out = 0;
	for (auto i: plaintext) {
		out += i;
	}
	std::cout << out << std::endl;
}

