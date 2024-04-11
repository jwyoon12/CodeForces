// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Mike has a sequence A  = [a1, a2, ..., an] of length n.He considers the sequence B  = [b1, b2, ..., bn] beautiful if the gcd of all its elements is bigger than 1, i.e. .
//
//Mike wants to change his sequence in order to make it beautiful.In one move he can choose an index i(1 ≤ i  < n), delete numbers ai, ai  + 1 and put numbers ai  - ai  + 1, ai  + ai  + 1 in their place instead, in this order.He wants perform as few operations as possible.Find the minimal number of operations to make sequence A beautiful if it's possible, or tell him that it is impossible to do so.
//
//	is the biggest non - negative number d such that d divides bi for every i(1 ≤ i ≤ n).
//
//	Input
//	The first line contains a single integer n(2 ≤ n ≤ 100 000) — length of sequence A.
//
//	The second line contains n space - separated integers a1, a2, ..., an(1 ≤ ai ≤ 109) — elements of sequence A.
//
//	Output
//	Output on the first line "YES" (without quotes) if it is possible to make sequence A beautiful by performing operations described above, and "NO" (without quotes) otherwise.
//
//	If the answer was "YES", output the minimal number of moves needed to make sequence A beautiful.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int isGCD(int a, int b) {

	return b==0? a : isGCD(b,a%b);
}

int main()
{
	//std::set<int> bst;
	int input_number;
	cin >> input_number;
	vector<int> A(input_number);
	// 1 2 3 4 5를 입력받아 A를 만드는 법, 엔터를 눌러야 다음 줄로 내려간다.
	// 엔터를 누르지 않았기 때문에 같은 줄에서 여러 개의 입력을 받는다.
	for (int i = 0; i < input_number; i++) 
	{
		cin >> A[i];
	}
	// 여기서보면, 주어진 리스트가 이미 gcd(b1,b2,...,bn)>1 인 경우를 검사한다. ---(1)
	int gccd = A[0];
	bool all_good = true;
	for (int i = 0; i < input_number; i++)
	{
		gccd = isGCD(gccd, A[i]);
		if (gccd == 1) {
			all_good = false;
			break;
		}
	}
	if (all_good == true) {
		cout << "Yes" << endl << 0 << endl;
		return 0;
	}

	int count = 0;
	// 홀짝 연산의 특징 gcd가 되려면 모두 짝수로 만들면 된다. 그리고 임의의 수는 최대 2번의 위에 기술된 연산을 거쳐 
	// 모두 짝수로 만들 수 있다. ---(2)
	// (2)를 하고 나서, 전부 짝수로 바뀌기 때문에 (1)로 다시 검사를 안 해도 된다.
	// 짝수가 아닌 다른 수로 맞춘다면 a_i - a_(i+1), a_i + a_(i+1)을 연산하면 다른 수의 최대공약수가 되리라는 보장이 없다. 
	// 예를 들어 3의 배수로 맞춘다면.. 나머지가 0,1,2가 되는 경우가 있을 텐데 mod1 + mod1, mod2 + mod2, mod1 - mod2, mod0+mod1,mod0+mod2 등등이
	// mod0이 되지 않기에 추가 연산이 필요하다. 반면에 짝수로 맞추면 mod0, mod1의 경우만 있어 최대 2번 연산하면 두 임의의 수를 mod0으로 만들 수 있다.
	for (int i = 0; i < input_number-1; i++)
	{
		if (A[i] % 2 == 0) continue; // 원소가 음수인 경우에도 gcd가 계산 가능하다. (몫을 음수로 주어서)
		while (A[i] % 2 != 0) {
			A[i] = A[i] - A[i + 1];
			A[i + 1] = A[i] + 2 * A[i + 1];
			count++;
		}
	}
	if (A[input_number-1] % 2 != 0) count += 2;
	
	cout << "Yes" << endl;
	cout << count << endl;

	// cout << "No" << endl;
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
