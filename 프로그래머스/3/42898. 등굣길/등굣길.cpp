#include <bits/stdc++.h>
using namespace std;
const long long NUM = 1000000007;
int dp[102][102];
int mp[102][102];
int dy[2] = {0,1};
int dx[2] = {1,0};
int M,N;
vector<vector<int>> Puddles;
int go(int y, int x){
    //cout<<y<<","<<x<<"\n";
    if(y==N &&x==M) return 1;
    
    int &ret = dp[y][x];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=0; i<2; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>N || nx>M) continue;
        if(mp[ny][nx]==1) continue;
        ret += go(ny,nx)%NUM;
    }
    
    return ret%NUM;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    N=n;
    M=m;
    for(auto it : puddles){
        mp[it[1]][it[0]]=1;
    }
    int answer = 0;
    memset(dp,-1,sizeof(dp));
    return go(1,1);
}