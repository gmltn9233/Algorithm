#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    
    // DP 테이블을 triangle 크기에 맞게 할당
    vector<vector<int>> dp = triangle;

    // 아래에서부터 위로 올라가면서 각 위치의 최대 경로를 계산
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
        }
    }

    // dp[0][0]에 최종적으로 최대값이 저장됨
    return dp[0][0];
}
