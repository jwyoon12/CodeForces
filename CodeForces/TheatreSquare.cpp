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
		// right�� ������Ű��, left�� �ڸ� ���� �ϳ��� �ø��� �����. ����, result�� ���� ���� �� ����.
		int right = int(str2[i] - '0');
		int carry = 0;
		int left_exp = 0;

		int k = N + i; 		

		for (int j = N - 1; j >= 0; j--)
		{
			int left = int(str1[j] - '0');
			int product = 0;

			int sum = left * right + int(result[k] - '0') + carry; // int(result[k]-'0') �κ��� Ʈ��Ű �ϴ�. 
			carry = sum / 10;
			result[k] = char(sum % 10 + '0');
			k -= 1;
		}
		//result�� k �ڸ� ���� carry ����
		result[k] = char(carry + '0');
	}
	// 0 padding�� �ִ� �κ��� �� �������� result�� ��ȯ
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

	//cin >> n >> m >> a; // �̷��� �Է� �޴� ���� �ִ�.

	// ���� ������ ũ�� �ؼ� ������� ���� ����. �� �´´�
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