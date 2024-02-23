#include<bits/stdc++.h>
using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int visited[103][103];
int x,y;
queue<pair<int,int>> q;
int solution(vector<vector<int> > maps)
{
    int n= maps.size();
    int m= maps[0].size();
    visited[0][0]=1;
    q.push({0,0});
    while(q.size()){
        tie(y,x)=q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]||maps[ny][nx]==0)continue;
            visited[ny][nx]=visited[y][x]+1;
            q.push({ny,nx});
        }
    }
    int answer = -1;
    if(visited[n-1][m-1]){
        answer=visited[n-1][m-1];
    }
    return answer;
}