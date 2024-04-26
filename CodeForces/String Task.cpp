#include<iostream>
#include<vector>
#include<string>
#include<cctype>

using namespace std; 

int main() {
	string input;
	cin >> input;
	int translate = int('a' - 'A');
	//vector<char> vowels;
	//vowels.push_back('a');
	//vowels.push_back('e');
	//vowels.push_back('i');
	//vowels.push_back('o');
	//vowels.push_back('u');
	//vowels.push_back('y');
	string vowels = "aeiouy";

	bool vowel_flags;
	for (auto& el : input) {

		vowel_flags = false;

		//if (el < 'a') {
		//	el = (int(el) + translate);
		//}
		el = tolower(el);

		for (auto& vowel : vowels) {
			if (el == vowel) {
				vowel_flags = true;
			}
		}

		if (!vowel_flags) {
			cout << "." << el;
		}

	}
	
	return 0;
}