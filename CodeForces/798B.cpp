// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Mike has a string s consisting of only lowercase English letters. He wants to change exactly one character from the string so that the resulting one is a palindrome.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void implement(string &change_s) {
	queue<char> temp;
	for (int i = 0; i < change_s.size(); i++)
	{
		temp.push(change_s[i]);
	}
	char q1 = temp.front();
	temp.push(q1);
	temp.pop();
	
	int index = 0;
	while (!temp.empty()) {
		change_s[index]= temp.front();
		temp.pop();
		index++;
	}

}

int main()
{
	int input_number;
	cin >> input_number;
	vector<string> s(input_number);
	vector<int> vec1(input_number, 51);
	int max_count = 0;
	for (int i = 0; i < input_number; i++) cin >> s[i];

	for (int i = 0; i < input_number; i++)
	{
		
		int count = 0;
		for (int j = 0; j < input_number; j++)
		{
			string change_s = s[j];
			int threshold = 0;
			while (change_s != s[i]) {
				implement(change_s);
				count += 1;
				threshold += 1;
				if (threshold > s[j].size()) {
					cout << -1;
					return 0;
				}
			}
		}
		vec1[i] = count;
	}
	cout << *min_element(vec1.begin(),vec1.end());
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
