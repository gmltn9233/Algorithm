#include <bits/stdc++.h>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            triangle[i][j] = triangle[i][j] + max(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}