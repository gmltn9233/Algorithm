#include <bits/stdc++.h>
int answer;
using namespace std;
vector<int> node[18];
vector<int> Info;

void dfs(vector<int> next_nodes , int sheep, int wolf){
    answer = max(answer,sheep);
    for(auto next : next_nodes){
        cout<<next<<"\n";
        vector<int> next_copy = next_nodes;
        next_copy.erase(find(next_copy.begin(),next_copy.end(),next));
        
        for(auto it : node[next]){
            next_copy.push_back(it);
        }
        
        if(Info[next]==1){
            if(sheep > wolf+1){
                dfs(next_copy, sheep, wolf+1);
            }
            
        }else{
            dfs(next_copy, sheep + 1, wolf);
        }
    }
    return;
}
int solution(vector<int> info, vector<vector<int>> edges) {
    Info = info;
    for(auto edge : edges){
        node[edge[0]].push_back(edge[1]);
    }
    dfs(node[0],1,0);
    return answer;
}