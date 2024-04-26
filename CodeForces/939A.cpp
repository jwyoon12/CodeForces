#include <string>
#include <vector>
#include <iostream>

using namespace std;

int func(int q, vector<int> a) {
	vector<int> temp(q+1);
	while(temp.size() > a.size()){
		for (int i = a.size()-1; i >= 1; i--)
		{
			if (temp.size() > a[i]) {
				temp.erase(temp.begin() + a[i]);
			}
		}
	}
	return temp.size()-1;
}

int main()
{
	int numTestCase;
	cin >> numTestCase;
	int p, q;
	vector<int> ans;
	for (int i = 1; i <= numTestCase; i++)
	{
		cin >> p >> q;
		vector<int> a(p+1);
		vector<int> n(q+1);
		for (int j = 1; j <= p; j++)
		{
			cin >> a[j];
		}
		for (int k = 1; k <= q; k++)
		{
			cin >> n[k];
			ans.push_back(func(n[k], a));
		}
	}
	for (auto& a : ans) cout << a << " ";
	return 0;
}
