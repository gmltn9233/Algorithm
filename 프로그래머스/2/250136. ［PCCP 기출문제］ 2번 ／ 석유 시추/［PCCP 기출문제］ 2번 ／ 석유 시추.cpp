#include <bits/stdc++.h>

using namespace std;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n,m;
int visited[501][501];
vector<vector<int>> Land;
int mp[501];
bool isVisited[501];
void bfs(int Y, int X){
    
    queue<int> sizeQ;
    sizeQ.push(X);
    queue<pair<int,int>> q;
    q.push({Y,X});
    
    while(q.size()){
        auto it = q.front();
        int y = it.first;
        int x = it.second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(visited[ny][nx]) continue;
            if(Land[ny][nx]==1){
                q.push({ny,nx});
                sizeQ.push(nx);
                visited[ny][nx] = 1;
            }
        }
    }
    
    int size = sizeQ.size();
    
    fill(&isVisited[0],&isVisited[0]+501,false);
    //cout<<size<<"\n";
    while(sizeQ.size()){
        auto it = sizeQ.front();
        if(!isVisited[it]){
            mp[it]+= size;
            isVisited[it] = true;
        }
        sizeQ.pop();
    }
}

int solution(vector<vector<int>> land) {
    Land = land;
    n = land.size();
    m = land[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && land[i][j]==1){
                visited[i][j]=1;
                bfs(i,j);
            }
        }
    }
    
    int answer = 0;
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<mp[i][j].first<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"---------------\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<mp[i][j].second<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    for(int i=0; i<m; i++){
        answer = max(answer, mp[i]);
    }
    
    
    return answer;

}