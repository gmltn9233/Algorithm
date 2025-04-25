#include <bits/stdc++.h>
using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<unordered_set<int>> dp(9); // dp[i] : N을 i번 써서 만들 수 있는 수들의 집합

    for (int i = 1; i <= 8; i++) {
        int repeated = 0;
        for (int j = 0; j < i; j++) repeated = repeated * 10 + N;
        dp[i].insert(repeated); // NNN...

        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        if (dp[i].count(number)) return i;
    }

    return -1;
}