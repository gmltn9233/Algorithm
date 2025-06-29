#include <bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int>> edges;
int parent[100001];
int n,m,a,b,c,ret,num;
bool cmp(tuple<int,int,int> a, tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}
int findRoot(int a){
    if(parent[a]==a) return a;
    return parent[a] = findRoot(parent[a]);
}
bool unionEdges(int a, int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA == rootB) return false;
    parent[rootB] = rootA;
    return true;
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        edges.push_back(make_tuple(a,b,c));
    }
    
    sort(edges.begin(),edges.end(),cmp);
    
    for(auto it : edges){
        if(unionEdges(get<0>(it),get<1>(it))){
            ret += get<2>(it);
            num = max(num,get<2>(it));
        }
    }


    cout<<ret-num<<"\n";
    return 0;
}

// N 개의 집과 M 개의 길
