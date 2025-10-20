#include <bits/stdc++.h>

using namespace std;
int n,m;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[104][104];
int num;
vector<int> answer;
vector<string> Maps;
void dfs(int y, int x){
    //cout<<y<<","<<x<<"\n";
    //cout<<num<<"\n";
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        if(ny< 0 || ny>=n || nx<0 || nx>=m) continue;
        if(visited[ny][nx]) continue;
        if(Maps[ny][nx]=='X') continue;
        visited[ny][nx] = 1;
        num += (Maps[ny][nx]-'0');
        //cout<<ny<<","<<nx<<"방문\n";
        dfs(ny,nx);
    }
}
vector<int> solution(vector<string> maps) {
    Maps=maps;
    n = maps.size();
    m = maps[0].length();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]==0 && maps[i][j]!='X'){
                //cout<<i<<","<<j<<"\n";
                num = maps[i][j]-'0';
                visited[i][j] = 1;
                dfs(i,j);
                answer.push_back(num);
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.size()==0) return {-1};
    else return answer;
}