#include <bits/stdc++.h>

using namespace std;
int dp[502][502];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    if(triangle.size()==1) return triangle[0][0];
    else if (triangle.size()==2) return triangle[0][0]+max(triangle[1][0],triangle[1][1]);
    else{
        for(int i=0; i<triangle[triangle.size()-1].size(); i++){
            dp[triangle.size()-1][i]=triangle[triangle.size()-1][i];
        }
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                dp[i][j] =triangle[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
                //cout<<i<<","<<j<<":"<<dp[i][j]<<"\n";
            }
        }
    }
    
    return dp[0][0];
}