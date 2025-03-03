#include <bits/stdc++.h>
using namespace std;
const int INF = 98764321;
int N,M;
int dp[41][121][121];
vector<vector<int>> v;
int go(int idx, int a, int b){
    if(a>=N || b>=M) return INF;
    if(idx==v.size()){
        return 0;
    }
    
    int &ret = dp[idx][a][b];
    if(ret!=-1) return ret;
    
    ret = INF;
    ret = min(ret,go(idx+1,a+v[idx][0],b)+v[idx][0]);
    ret = min(ret,go(idx+1,a,b+v[idx][1]));
    
    return ret;
}

int solution(vector<vector<int>> info, int n, int m) {
    v = info;
    N = n;
    M = m;
    int answer = 0;
    memset(dp,-1,sizeof(dp));
    answer = go(0,0,0);
    if(answer == INF) answer = -1;
    return answer;
}

