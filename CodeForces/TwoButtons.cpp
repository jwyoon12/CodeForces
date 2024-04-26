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
    // 곰곰히 생각해보면 n=5000, m=10000이 가능하고, n=9999, m=10000이면
    //n은 대략 20000-2 가능하고, n=10000, m=9999면 0부터 2*n개의 배열이 필요하니 
    //20001개이다.
    //배열을 잡아두지 않고 생성 때마다 배열을 늘리는 방식을 택했을 때, 길이를 log로 나누어야 하는데서
    // 어려움이 발생. 
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