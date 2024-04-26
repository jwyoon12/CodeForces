
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
// 연속적으로 봐야하는게 중요한 문제이다. 
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }
    

    int sum = 0;
    int j = 0;
    int max_read = j;
    int i = 0;

    while(j<n)
    {
        sum += books[j];
        while (sum > t) {
            sum -= books[i];
            i++;
        }
        max_read = max(max_read, j - i + 1);
        j++;
       
    }
    cout << max_read;
    return 0;
}