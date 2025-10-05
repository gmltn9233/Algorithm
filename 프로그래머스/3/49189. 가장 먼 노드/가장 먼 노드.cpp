#include <bits/stdc++.h>

using namespace std;
set<int> routes[20002];
int visited[20002];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(auto it : edge){
        routes[it[0]].insert(it[1]);
        routes[it[1]].insert(it[0]);
    }
    
    queue<int> q;
    
    q.push(1);
    while(q.size()){
        int to = q.front();
        q.pop();
        for(auto it : routes[to]){
            if(visited[it]) continue;
            visited[it]=visited[to]+1;
            //cout<<it<<","<<visited[it]<<"\n";
            q.push(it);
        }
    }
    int max_answer = 0;
    for(int i=2; i<=n; i++){
        max_answer = max(max_answer,visited[i]);
    }
    
    for(int i=2; i<=n; i++){
        if(visited[i]==max_answer) ++answer;
    }
    return answer;
}