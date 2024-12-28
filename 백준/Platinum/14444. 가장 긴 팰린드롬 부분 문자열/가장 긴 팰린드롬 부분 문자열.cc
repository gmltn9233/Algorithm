#include <bits/stdc++.h>
using namespace std;

int manacher(const string& s) {
    // 문자열 변환: "abc" -> "#a#b#c#"
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }

    int n = t.size();
    vector<int> p(n, 0); // 팰린드롬 반경 저장
    int c = 0, r = 0;    // 중심(c), 오른쪽 경계(r)

    for (int i = 0; i < n; i++) {
        // i가 r 안에 있으면 대칭성을 이용해 초기 반경 설정
        if (i < r) {
            p[i] = min(r - i, p[2 * c - i]);
        }

        // 팰린드롬 반경 확장
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
            p[i]++;
        }

        // r을 업데이트
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }

    // p 배열에서 최대 값 찾기
    return *max_element(p.begin(), p.end());
}

int main() {
    string s;
    cin >> s;
    cout << manacher(s) << endl;
    return 0;
}
