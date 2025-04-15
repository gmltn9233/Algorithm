#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int arr[100004];
long long preSum[100004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        preSum[i] = preSum[i-1] + arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << preSum[b] - preSum[a-1] << "\n";
    }

    return 0;
}