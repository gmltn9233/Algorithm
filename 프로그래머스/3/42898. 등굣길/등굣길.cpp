#include<bits/stdc++.h>
using namespace std;
const long long NUM = 1000000007;
int M,N;
int dy[2] = {0,1};
int dx[2] = {1,0};
long long dp[102][102];
bool isPuddles[102][102];
long long go(int y, int x){
    if(y>N || x>M) return 0;
    if(y==N && x==M) return 1; 
    long long &ret= dp[y][x];
    if(ret!=-1) return ret;
    
    ret = 0;
    if(!isPuddles[y+1][x]){
        ret += go(y+1,x)%NUM;
    }
    if(!isPuddles[y][x+1]){
        ret += go(y,x+1)%NUM;
    }
    return ret%NUM;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    M=m;
    N=n;
    for(auto it : puddles){
        isPuddles[it[1]][it[0]] = true;
    }
    
    memset(dp,-1,sizeof(dp));
    
    int answer = go(1,1);
    return answer;
}