#include <bits/stdc++.h>

using namespace std;
int parent[101];
int ret;
bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int checkParent(int a){
    if(parent[a] == a) return a;
    return parent[a] = checkParent(parent[a]);
}

void go(int a, int b, int w){
    if(checkParent(a) == checkParent(b)) return;
    parent[checkParent(b)] = checkParent(a);
    ret += w;
}

int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(),costs.end(),cmp);
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    for(int i=0; i<costs.size(); i++){
        go(costs[i][0],costs[i][1], costs[i][2]);
    }
    
    return ret;
}