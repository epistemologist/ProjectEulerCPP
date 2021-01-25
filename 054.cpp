#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;

// This one is gonna be a doozy...


// Generate the cards
string VALUES = "23456789TJQKA";
string SUITS = "HCSD";

vector<string> gen_cards() {
	vector<string> cards;
	for (char i: VALUES) {
		for (char j: SUITS) {
			std::string tmp;
			tmp += i; tmp += j; cards.push_back(tmp);
		}
	}
	return cards;
}


vector<string> CARDS = gen_cards();

// Generate all possible hands
// Inspired by Rosetta Code
vector<vector<string>> gen_hands() {
	string bitmask = "1111100000000000000000000000000000000000000000000000";
	vector<vector<string>> out;
	do {
		vector<string> tmp;
		for (int i = 0; i < 52; i++) {
			if (bitmask[i] == '1') tmp.push_back(CARDS[i]);
		}
		out.push_back(tmp);
	} while (std::prev_permutation(bitmask.begin(), bitmask.end()));
	return out;
}

vector<vector<string>> HANDS = gen_hands();

// Utility functions
string get_values(vector<string> hand) {
	string out = "";
	for (string i: hand) out += i[0];
	return out;
}

string get_suits(vector<string> hand) {
	string out = "";
	for (string i: hand) out += i[1];
	return out;
}

bool all_same_suits(vector<string> hand) {
	string suits = get_suits(hand);
	return std::count(suits.begin(), suits.end(), suits.at(0)) == 5;
}

// Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
int is_royal_flush(vector<string> hand) {
	return (get_values(hand).compare("TJQKA") == 0 && all_same_suits(hand)) ? 1 : -1;
}

// Straight Flush: All cards are consecutive values of same suit.
vector<string> gen_straight_flush_values() {
	vector<string> out;
	for (int i = 0; i < VALUES.length() - 4; i++) {
		out.push_back(VALUES.substr(i, 5));
	}
	return out;
}

auto STRAIGHT_FLUSH_VALUES = gen_straight_flush_values();

int is_straight_flush(vector<string> hand) {
	if (all_same_suits(hand)) {
		for (int i = 0; i < STRAIGHT_FLUSH_VALUES.size(); i++) {
			if (STRAIGHT_FLUSH_VALUES[i].compare(get_values(hand)) == 0) {
				return i;
			}
		}
	}
	return -1;
}

// Four of a Kind: Four cards of the same value.

map<string, int> gen_four_kind_values() {
	map<string, int> out;
	for (int i = 0; i < VALUES.length(); i++) {
		for (int j = 0; j < VALUES.length(); j++) {
			if (i!=j) {
				string tmp(4, VALUES[i]);
				tmp.resize(5, VALUES[j]);
				std::sort(tmp.begin(), tmp.end());
				do {
					// std::cout << tmp << " " << i << std::endl;
					out.insert(pair<string, int>(tmp, i));
				} while (std::next_permutation(tmp.begin(), tmp.end()));
			}
		}
	}
	return out;
}

map<string, int> FOUR_KIND_VALUES = gen_four_kind_values();

int is_four_of_a_kind(vector<string> hand) {
	string vals = get_values(hand);
	return FOUR_KIND_VALUES.find(vals) == FOUR_KIND_VALUES.end() ? -1 : FOUR_KIND_VALUES[vals];
}

// Full House: Three of a kind and a pair.

map<string, int> gen_full_house_values() {
	map<string, int> out;
	for (int i = 0; i < VALUES.length(); i++) {
		for (int j = 0; j < VALUES.length(); j++) {
			if (i!=j) {
				string tmp(3, VALUES[i]);
				tmp.resize(5, VALUES[j]);
				std::sort(tmp.begin(), tmp.end());
				do {
					// std::cout << tmp << " " << i << std::endl;
					out.insert(pair<string, int>(tmp, i));
				} while (std::next_permutation(tmp.begin(), tmp.end()));
			}
		}
	}
	return out;
}

auto FULL_HOUSE_VALUES = gen_full_house_values();

int is_full_house(vector<string> hand) {
	string vals = get_values(hand);
	return FULL_HOUSE_VALUES.find(vals) == FULL_HOUSE_VALUES.end() ? -1 : FULL_HOUSE_VALUES[vals];
}

// Flush: All cards of the same suit.

int is_flush(vector<string> hand) {
	if (all_same_suits(hand)) {
//		return VALUES.find(get_values(hand).at(4));
		return 1;
	}
	return -1;
}

// Straight: All cards are consecutive values.
int is_straight(vector<string> hand) {
	string vals = get_values(hand);
	for (int i = 0; i < VALUES.length()-4; i++) {
		if (VALUES.substr(i,5).compare(vals) == 0) return i;
	}
	return -1;
}

// Three of a Kind: Three cards of the same value.

int is_three_of_a_kind(vector<string> hand) {
	string vals = get_values(hand);
	for (int i = 0; i < VALUES.length(); i++) {
		if (std::count(vals.begin(), vals.end(), VALUES.at(i)) == 3) return i;
	}
	return -1;
}

// Two Pairs: Two different pairs.

map<string,int> gen_two_pair_values() {
	map<string, int> out;
	for (int pair1 = 0; pair1 < VALUES.length(); pair1++) {
		char p1 = VALUES.at(pair1);
		for (int pair2 = pair1+1; pair2 < VALUES.length(); pair2++) {
			char p2 = VALUES.at(pair2);
			for (int k = 0; k < VALUES.length(); k++) {
				if (k != pair1 && k != pair2) {
					string vals(2 , p1);
					vals.resize(4, p2);
					vals.resize(5, VALUES.at(k));
					std::sort(vals.begin(), vals.end());
					do {
						out.insert(pair<string,int>(vals, pair2));
					} while (std::next_permutation(vals.begin(), vals.end()));
				}
			}
		}
	}
	return out;
}

map <string,int> TWO_PAIR_VALUES = gen_two_pair_values();

int is_two_pair(vector<string> hand) {
	string vals = get_values(hand);
	return TWO_PAIR_VALUES.find(vals) == TWO_PAIR_VALUES.end() ? -1 : TWO_PAIR_VALUES[vals];
}

// One Pair: Two cards of the same value.

int is_one_pair(vector<string> hand) {
	string vals = get_values(hand);
	for (int i = 0; i < VALUES.length(); i++) {
		if (std::count(vals.begin(), vals.end(), VALUES.at(i)) == 2) return i;
	}
	return -1;
}

// High Card: Highest value card.

int high_card(vector<string> hand) {
	string vals = get_values(hand);
	for (int i = VALUES.length() - 1; i >= 0; i--) {
		if (vals.find(VALUES.at(i)) != string::npos) return i;
	}
	return -1;
}

// Function to score hand
vector<int> score_hand(vector<string> hand) {
	vector<int> out = {
		high_card(hand),
		is_one_pair(hand),
		is_two_pair(hand),
		is_three_of_a_kind(hand),
		is_straight(hand),
		is_flush(hand),
		is_full_house(hand),
		is_four_of_a_kind(hand),
		is_straight_flush(hand),
		is_royal_flush(hand)
	};
	for (int i = out.size() - 1; i >= 0; i--) {
		if (out[i] != -1) return {i, out[i]};
	}
	return vector<int>();
}

// Function to compare two hands

bool compare_hands(vector<string> hand1, vector<string> hand2) {
	// Returns true if hand1 beats hand2
	vector<int> score1 = score_hand(hand1);
	vector<int> score2 = score_hand(hand2);
	if (score1[0] > score2[0]) return true;
	else if (score1[0] == score2[0]) {
		if (score1[1] > score2[1]) {
			return true;
		}
	}
	return false;
}

/*
In the text file provided, the cards are not provided in any order; therefore, let's write a function to sort the hand so we can encode any hand by their values and their suits
*/

pair<string,string> encode_hand(vector<string> hand) {
	string vals = get_values(hand);
	std::sort(vals.begin(), vals.end());
	string suits = get_suits(hand);
	std::sort(suits.begin(), suits.end());
	return pair<string,string>(vals, suits);
}

map<pair<string, string>, vector<string>> gen_hand_encodings(vector<vector<string>>& hands) {
	map<pair<string, string>, vector<string>> out;
	for (vector<string> hand: hands) {
		pair<string, string> encoding = encode_hand(hand);
		out.insert(pair<pair<string,string>, vector<string>>(encoding, hand));
	}
	return out;
}

map<pair<string, string>, vector<string>>  HAND_ENCODINGS = gen_hand_encodings(HANDS);


// Utility function to print a hand and to convert hand to string

void print_hand(vector<string> hand) {
	for (string card: hand) {
		std::cout << card << ",";
	}
	std::cout << std::endl;
}

string hand_to_string(vector<string> hand) {
	string out = "";
	for (string card: hand) {
		out += card + ",";
	}
	return out;
}


int main() {
	string line;
	string card;
	vector<vector<string>> hands1;
	vector<vector<string>> hands2;
	ifstream file ("./data/054_hands.txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			vector<string> hand1;
			vector<string> hand2;
			stringstream ss(line);
			for (int i = 0; getline(ss, card, ' '); i++) {
				if (i < 5) hand1.push_back(card);
				else hand2.push_back(card);
			}
			hands1.push_back(hand1);
			hands2.push_back(hand2);
		}
	}
	int wins = 0;
	for (int i = 0; i < 1000; i++) { 
		vector<string> hand1 = HAND_ENCODINGS[encode_hand(hands1[i])];
		vector<string> hand2 = HAND_ENCODINGS[encode_hand(hands2[i])];
		wins += compare_hands(hand1, hand2) ? 1 : 0;
	}
	std::cout << wins << std::endl;
}

