// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <list>

using namespace std;
bool isRXCY(string abs) {
	if (abs[0] == 'R') {
		int i = 1;
		while (true) {
			if (i == abs.size()) return false;
			else if ((abs[i] >= 'A') && (abs[i - 1] < 'A')) return true;
			i++;
		}
	}
	return false;
}
string convert2nonRXCY(string str) {
	int i = 0;
	while (str[i] != 'C' && i < str.size()) i++;
	string X = str.substr(1, i-1);
	string Y = str.substr(i+1, str.size()-i-1);

	//int k = stoi(Y); 아래 for문을 stoi로 간단하게 만들 수 있다. string -> integer
	int Yint = 0;
	int exp = 1;
	for (int i = Y.size() - 1; i >= 0; i--)
	{
			Yint += int(Y[i] - '0') * exp;
			exp *= 10;
	}
	
	string result = "";
	while (Yint > 0) {
		
		int mod = (Yint-1) % 26;
		result = char('A' + mod) + result;
		Yint = (Yint - 1) / 26;
		
	}
	return result + X;
}

string convert2RXCY(string str) {
	int i = 0;
	while ((str[i] >= 'A') && i<str.size()) i++;
	string X = str.substr(0, i);
	string Y = str.substr(i, str.size() - i);

	int result = 0;
	for (char c : X) {
		result = result * 26 + (c - 'A' + 1);
	}
	X = to_string(result);
	return "R" + Y + "C" + X;
}

int main() {
	int n;
	cin >> n;
	vector<string> stringList;
	string input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		stringList.push_back(input);
	}
	for(const auto& str : stringList){
		if (isRXCY(str)) {
			cout << convert2nonRXCY(str) << endl;
		}
		else {
			cout << convert2RXCY(str) << endl;
		}
	}
	return 0;
}
