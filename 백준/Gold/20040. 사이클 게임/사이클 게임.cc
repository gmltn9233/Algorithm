#include <bits/stdc++.h>
using namespace std;
int n,m;
int parent[1000001];
int find(int idx){
    if(idx == parent[idx]) return idx;
    return find(parent[idx]);
}
void merge(int a, int b){
    int A = find(a);
    int B = find(b);
    if(A==B) return;
    parent[B] = A;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b)){
            cout<<i+1;
            return 0;
        }else{
            merge(a,b);
        }
    }
    cout<<0;
    
    return 0;
}