#include <bits/stdc++.h>

using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m;
int visited[104][104];
pair<int,int> s,e,l;
int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    int answer = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j]=='S'){
                s = {i,j};
            }
            if(maps[i][j]=='E'){
                e = {i,j};
            }
            if(maps[i][j]=='L'){
                l = {i,j};
            }
        }
    }
    queue<pair<int,int>> q;
    q.push({s.first, s.second});
    visited[s.first][s.second] = 1;
    bool flag1 = false;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(visited[ny][nx]) continue;
            if(maps[ny][nx]=='X') continue;
            if(maps[ny][nx]=='L') flag1 = true;
            visited[ny][nx] = visited[y][x]+1;
            q.push({ny,nx});
        }
    }
    if(!flag1) return -1;
    int mid = visited[l.first][l.second]-1;
    fill(&visited[0][0], &visited[0][0]+104*104,0);
    
    q.push({l.first, l.second});
    visited[l.first][l.second] = 1;
    
    bool flag2 = false;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(visited[ny][nx]) continue;
            if(maps[ny][nx]=='X') continue;
            if(maps[ny][nx]=='E') flag2 = true;
            visited[ny][nx] = visited[y][x]+1;
            q.push({ny,nx});
        }
    }
    if(!flag2) return -1;
    
    return mid + visited[e.first][e.second]-1;
}