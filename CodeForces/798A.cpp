// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Mike has a string s consisting of only lowercase English letters. He wants to change exactly one character from the string so that the resulting one is a palindrome.

//A palindrome is a string that reads the same backward as forward, for example strings "z", "aaa", "aba", "abccba" are palindromes, but strings "codeforces", "reality", "ab" are not.
//
//Input
//The first and single line contains string s(1 ≤  | s | ≤ 15).
//
//Output
//Print "YES" (without quotes) if Mike can change exactly one character so that the resulting string is palindrome or "NO" (without quotes) otherwise.'

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

	int count = 0;
	int start = 0;
	int last = s.size() - 1;
	while (start < last)
	{
		if (s[start] != s[last]) count += 1;
		start++;
		last--;
	}
		
	if (count == 0 && last == start ) cout << "Yes" << endl; 
	else if(count == 1 && last == start) cout << "Yes" << endl;
	else if (count == 1 && last < start) cout << "Yes" << endl;
	else cout << "No" << endl;
		
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
