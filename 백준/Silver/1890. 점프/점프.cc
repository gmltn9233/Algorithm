#include <bits/stdc++.h>
using namespace std;

int n;
int a[101][101];
long long dp[101][101];

long long go(int y, int x) {
    if (y >= n || x >= n) return 0; // 범위를 벗어나면 경로 없음
    if (y == n - 1 && x == n - 1) return 1; // 도착지점에 도달하면 경로 1개 추가

    long long &ret = dp[y][x];
    if (ret != -1) return ret; // 이미 계산된 값이면 반환

    ret = 0; // 초기화
    int now = a[y][x];
    if (now > 0) {
        ret += go(y + now, x); // 아래로 이동
        ret += go(y, x + now); // 오른쪽으로 이동
    }

    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // DP 배열 초기화
    fill(&dp[0][0], &dp[0][0] + 101 * 101, -1);

    // 경로 계산 및 출력
    cout << go(0, 0) << '\n';

    return 0;
}
