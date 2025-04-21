#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[101][101];
bool visited[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int dfs(int y, int x, char ch) {
    visited[y][x] = true;
    int cnt = 1;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (visited[ny][nx] || a[ny][nx] != ch) continue;
        cnt += dfs(ny, nx, ch);
    }
    return cnt;
}

int main() {
    cin >> m >> n; // 가로, 세로 순
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            a[i][j] = row[j];
        }
    }

    int white = 0, black = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                int size = dfs(i, j, a[i][j]);
                if (a[i][j] == 'W') white += size * size;
                else black += size * size;
            }
        }
    }

    cout << white << " " << black << "\n";
    return 0;
}