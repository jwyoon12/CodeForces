// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

string Multiply(string str1, string str2)
{

	if (!str1.size() || !str2.size()) return "0";

	int N = max(str1.size(), str2.size());
	// 0 padding
	str1.insert(0, string(N - str1.size(), '0'));
	str2.insert(0, string(N - str2.size(), '0'));

	string result = string(2 * N, '0');

	int total_sum = 0;
	int right_exp = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		// right를 고정시키고, left의 자리 수를 하나씩 올리며 계산함. 따라서, result에 수가 있을 수 있음.
		int right = int(str2[i] - '0');
		int carry = 0;
		int left_exp = 0;

		int k = N + i; 		

		for (int j = N - 1; j >= 0; j--)
		{
			int left = int(str1[j] - '0');
			int product = 0;

			int sum = left * right + int(result[k] - '0') + carry; // int(result[k]-'0') 부분이 트리키 하다. 
			carry = sum / 10;
			result[k] = char(sum % 10 + '0');
			k -= 1;
		}
		//result의 k 자리 수에 carry 대입
		result[k] = char(carry + '0');
	}
	// 0 padding이 있는 부분을 뺀 나머지만 result로 반환
	int i = 0;
	while (result[i] == '0')i += 1;
	result = result.substr(i, 2 * N - i);
	return result;
}

int main() {

	vector<int> vec(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> vec[i];
	}
	int n = vec[0];
	int m = vec[1];
	int a = vec[2];

	//cin >> n >> m >> a; // 이렇게 입력 받는 법이 있다.

	// 굳이 사이즈 크게 해서 만들려고 하지 말자. 안 맞는다
	//unsigned long long abcsd = row*col;
	if (m%a ==0 && n%a == 0){
		cout << Multiply(to_string(m / a) , to_string(n / a));
	}
	else if (m % a == 0 && n % a != 0) {
		cout <<Multiply(to_string(m / a ) , to_string(n / a + 1));
	}
	else if (m % a != 0 && n % a == 0) {
		cout << Multiply(to_string(m / a + 1) , to_string(n / a));
	}
	else {
		cout << Multiply(to_string(m / a + 1) , to_string(n / a + 1));
	}
	//if (m % a == 0 && n % a == 0) {
	//	cout << to_string(row*col);
	//}
	//else if (m % a == 0 && n % a != 0) {
	//	cout << to_string(row * (col+1));
	//}
	//else if (m % a != 0 && n % a == 0) {
	//	cout << to_string((row+1) * col);
	//}
	//else {
	//	cout << to_string((row+1) * (col+1));
	//}

	return 0;
}


//int main() {
//	unsigned long long n, m, a;
//	cin >> n >> m >> a;
//	unsigned long long value = ceil((double)m / a) * ceil((double)n / a);
//	cout << value;
//	return 0;
//}