#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}


int main() {
	int s, n;
	cin >> s >> n;
	vector<int> dragon(2);
	vector<vector<int>> dragons(n);
	for (int i = 0; i < n; i++)
	{
		int dragon_str, bonus;
		cin >> dragon_str >> bonus;
		dragon[0] = dragon_str;
		dragon[1] = bonus;
		dragons[i] = dragon;
	}
	std::sort(dragons.begin(), dragons.end(), compare);
	for (int i = 0; i < n; i++)
	{
		if (s > dragons[i][0]) {
			s += dragons[i][1];
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

