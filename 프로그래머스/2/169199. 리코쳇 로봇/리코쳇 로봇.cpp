#include <bits/stdc++.h>

using namespace std;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int n,m;
pair<int,int> start_point, end_point;
int mp[102][102];
int visited[102][102];
pair<int,int> go(int y, int x, int dir){
    pair<int,int> tmp ={y,x};
    //cout<<"start----------\n";
    while(true){
        int ny = y+dy[dir];
        int nx = x+dx[dir];
        if(ny<0 || ny>=n || nx<0 || nx>=m) break;
        if(mp[ny][nx]) break;
        y = ny;
        x = nx;
        tmp = {ny,nx};
        //cout<<ny<<","<<nx<<"\n";
    }
    //cout<<"end----------\n";
    return tmp;
}
int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='R'){
                start_point = {i,j};
            }
            if(board[i][j]=='G'){
                end_point = {i,j};
            }
            if(board[i][j]=='D'){
                mp[i][j]=1;
            }
        }
    }
    visited[start_point.first][start_point.second]=1;
    queue<pair<int,int>> q;
    q.push({start_point.first, start_point.second});
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        //cout<<y<<","<<x<<"\n";
        q.pop();
        for(int dir=0; dir<4; dir++){
            pair<int,int> next = go(y,x,dir);
            //cout<<dir<<"방향\n";
            int ny = next.first;
            int nx = next.second;
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(visited[ny][nx]) continue;
            if(ny==end_point.first && nx==end_point.second) return visited[y][x];
            visited[ny][nx] = visited[y][x]+1;
            //cout<<ny<<","<<nx<<"이동\n";
            q.push({ny,nx});
        }
    }
    
    return -1;
}