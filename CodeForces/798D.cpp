// CodeForces.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
const int N = 1e5;
struct Node {
	int val;
	int id;
} a[N], b[N];

bool cmp(Node a, Node b) {
	return a.val > b.val;
}

int main()
{
	unordered_map<int, int> AB;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		a[i].id = i;
		cin >> a[i].val;
	}
	for (int i = 1; i <= n; i++)
	{
		b[i].id = i;
		cin >> b[i].val;
	}
	sort(a+1, a + n+1, cmp); // a의 인덱스 0부터 n까지 cmp를 기준으로 true이면 비교
	cout << n / 2 + 1 << endl << a[1].id;
	for (int i = 2; i <= n; i+=2)
	{
		if (i < n) {
			if (b[a[i + 1].id].val <= b[a[i].id].val) cout << "" << a[i].id;
			else cout << "" << a[i + 1].id;
		}
		else cout << "" << a[i].id; // 2부터 n까지가 홀수 개수인 경우
	}
	cout << endl;


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
