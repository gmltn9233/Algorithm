#include <bits/stdc++.h>

using namespace std;
int n,m,k,cnt,ret;
int a[104][104];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[104][104];
void dfs(int y, int x){
    visited[y][x] = 1;
    
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        if(ny < 1 || ny > n || nx < 1 || nx > m) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx]==0) continue;
        dfs(ny,nx);
        ++cnt;
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0; i<k; i++){
        int y,x;
        cin>>y>>x;
        a[y][x] = 1;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j]==1 && visited[i][j]==0){
                cnt = 1;
                dfs(i,j);
                ret = max(ret,cnt);
            }
        }
    }
    
    cout<<ret;
    return 0;
}