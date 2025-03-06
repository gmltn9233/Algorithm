#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int a[51][51];
vector<pair<int,int>> now;
int Y,X;
map<char,vector<pair<int,int>>> mp;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int visited[51][51];

void dfs(int y, int x, char target){
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        if(ny<0 || ny>=Y || nx<0 ||nx>=X) continue;
        if(visited[ny][nx]) continue;
        if(v[ny][nx]==target){
            now.push_back({ny,nx});
            visited[ny][nx]=1;
        }
        
        if(a[ny][nx]==1){
            visited[ny][nx]=1;
            dfs(ny,nx,target);
        }
    }
    
}
void lift(char target){
    // 초기화
    fill(&visited[0][0], &visited[0][0]+51*51, 0);
    now.clear();
    
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            if(i==0 || i==Y-1 || j==0 || j==X-1){
                if(v[i][j]==target){
                    now.push_back({i,j});
                    visited[i][j]=1;
                }
                if(a[i][j]==1){
                    visited[i][j]=1;
                    dfs(i,j,target);
                }
            }
        }
    }
    
    for(auto it : now){
        a[it.first][it.second]=1;
    }
    
}

void crane(char target){
    for(auto at : mp[target]){
        a[at.first][at.second]=1;
    }
}

int countChar(){
    int ret = 0;
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            if(a[i][j]==0) ++ret;
        }
    }
    return ret;
}

void printNow(int idx){
    cout<<"idx: "<<idx+1<<"\n";
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}

int solution(vector<string> storage, vector<string> requests) {
    v = storage;
    Y = storage.size();
    X = storage[0].size();
    for(int i=0; i<Y; i++){
        for(int j=0; j<X; j++){
            char c = storage[i][j];
            mp[c].push_back({i,j});
        }
    }
    int idx = 0;
    for(string request : requests){
        // 지게차
        if(request.size()==1){
            lift(request[0]);
        }
        // 크레인
        else{
            crane(request[0]);
        }
        // printNow(idx);
        // idx++;
        
    }
    
    int answer = countChar();
    
    
    return answer;
}