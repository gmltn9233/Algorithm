#include <bits/stdc++.h>
using namespace std;

int n;
int a[26][26];
int visited[26][26];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> v;
int cnt;

void dfs(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(visited[ny][nx] || a[ny][nx] == 0) continue;
        visited[ny][nx] = 1;
        ++cnt;
        dfs(ny, nx);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1 && visited[i][j] == 0) {
                cnt = 1; // 시작점도 세야 하므로 1로 초기화
                visited[i][j] = 1;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for(int num : v) {
        cout << num << "\n";
    }

    return 0;
}