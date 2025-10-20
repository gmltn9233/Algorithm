#include <bits/stdc++.h>
using namespace std;

int get_distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for (auto &ball : balls) {
        int x = ball[0];
        int y = ball[1];
        int min_d = INT_MAX;

        // 1️⃣ 위쪽 벽 반사 (y -> 2n - y)
        if (!(startX == x && startY < y))
            min_d = min(min_d, get_distance(startX, startY, x, 2 * n - y));

        // 2️⃣ 아래쪽 벽 반사 (y -> -y)
        if (!(startX == x && startY > y))
            min_d = min(min_d, get_distance(startX, startY, x, -y));

        // 3️⃣ 오른쪽 벽 반사 (x -> 2m - x)
        if (!(startY == y && startX < x))
            min_d = min(min_d, get_distance(startX, startY, 2 * m - x, y));

        // 4️⃣ 왼쪽 벽 반사 (x -> -x)
        if (!(startY == y && startX > x))
            min_d = min(min_d, get_distance(startX, startY, -x, y));

        answer.push_back(min_d);
    }

    return answer;
}