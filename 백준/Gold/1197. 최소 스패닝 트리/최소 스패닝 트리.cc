#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> edges;
int parent[100001];
int v,e,a,b,c;
long long ret;
bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}
int getRoot(int a){
    if(parent[a]==a) return a;
    return parent[a] = getRoot(parent[a]);
}
bool unionEdges(int a, int b){
    int rootA = getRoot(a);
    int rootB = getRoot(b);
    if(rootA == rootB) return false;
    parent[rootB] = rootA;
    return true;
}
int main()
{
    cin>>v>>e;
    for(int i=1; i<=v; i++){
        parent[i] = i;
    }
    for(int i=0; i<e; i++){
        cin>>a>>b>>c;
        edges.push_back(make_tuple(a,b,c));
    }
    
    sort(edges.begin(),edges.end(),cmp);
    
    for(auto it : edges){
        if(unionEdges(get<0>(it),get<1>(it))){
            ret += get<2>(it);
        }
    }
    cout<<ret<<"\n";
    return 0;
}
