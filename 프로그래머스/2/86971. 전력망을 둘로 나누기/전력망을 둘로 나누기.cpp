#include <bits/stdc++.h>
using namespace std;
vector<int> v[101];
int cnt,ret=101;
void bfs(int v1, int v2){
    int visited[101];
    fill(visited,visited+101,0);
    queue<int> q;
    q.push(v1);
    visited[v1]=1;
    visited[v2]=1;
    while(q.size()){
        int node = q.front();
        q.pop();
        for(int i=0; i<v[node].size(); i++){
            int node2 = v[node][i];
            if(visited[node2]) continue;
            cnt++;
            q.push(node2);
            visited[node2]=1;
        }
    }
}
int solution(int n, vector<vector<int>> wires) {
    for(int i=0; i<wires.size();i++){
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=0; i<wires.size();i++){
        cnt =1;
        int v1= wires[i][0];
        int v2= wires[i][1];
        bfs(v1,v2);
        ret=min(ret,abs(cnt-(n-cnt)));
    }
    return ret;
}