#include <bits/stdc++.h>
using namespace std;

int n, m, x_1, y_1, x_2, y_2;
int a[1026][1026];
int preSum[1026][1026];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> y_1 >> x_1 >> y_2 >> x_2;
        cout << preSum[y_2][x_2] - preSum[y_1 - 1][x_2] - preSum[y_2][x_1 - 1] + preSum[y_1 - 1][x_1 - 1] << "\n";
    }

    return 0;
}