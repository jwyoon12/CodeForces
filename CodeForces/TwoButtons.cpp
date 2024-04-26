#include<iostream>
//#include<vector>
//#include<string>
//#include<cctype>
//#include<algorithm>
//#include<queue>
//
//using namespace std;
//
//int main() {
//	int n, m;
//	int routeA = 0;
//	int routeB = 0;
//	cin >> n >> m;
//
//	if (n > m) cout << n - m;
//	else {
//		int k = n;
//		while (k < m) {
//			k *= 2;
//			routeA++;
//		}
//		if (n>1){
//			n = n - 1;
//			routeB++;
//			while (n < m) {
//				n *= 2;
//				routeB++;
//			}
//			cout << min(routeA + k - m, routeB + n - m);
//		}
//		else {
//			cout << routeA + k - m;
//		}
//	}
//	return 0;
//}
//
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    // ������ �����غ��� n=5000, m=10000�� �����ϰ�, n=9999, m=10000�̸�
    //n�� �뷫 20000-2 �����ϰ�, n=10000, m=9999�� 0���� 2*n���� �迭�� �ʿ��ϴ� 
    //20001���̴�.
    //�迭�� ��Ƶ��� �ʰ� ���� ������ �迭�� �ø��� ����� ������ ��, ���̸� log�� ������� �ϴµ���
    // ������� �߻�. 
    int v[20001];
    memset(v, -1, sizeof(v));
    v[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == m) {
            cout << v[u] << endl;
            return 0;
        }

        int a = 2 * u;
        if (a <= 20000 && v[a] == -1) {
            v[a] = v[u] + 1;
            q.push(a);
        }

        int b = u - 1;
        if (b > 0 && v[b] == -1) {
            v[b] = v[u] + 1;
            q.push(b);
        }
    }

    return 0;
}