#include <bits/stdc++.h>
using namespace std;
int n,m,num;
int parent[202];
vector<int> edges[201];
vector<int> travels;
bool flag;
int find(int idx){
    if(parent[idx] == idx) return idx;
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
    
    cin>>n;
    cin>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>num;
            if(num==1){
                edges[i].push_back(j);
            }
        }
    }
    
    
    // 초기화
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    
    // Union
    for(int i=1; i<=n; i++){
        for(auto edge : edges[i]){
            if(find(i) != find(edge)){
                merge(i,edge);
            }
        }
    }
    
    for(int i=0; i<m; i++){
        cin>>num;
        travels.push_back(num);
    }
    
    int prev = find(travels[0]);
    
    for(int i=1; i<travels.size(); i++){
        if(prev != find(travels[i])){
            flag = true;
            break;
        }
    }
   
    if(flag) cout<<"NO";
    else cout<<"YES";
    return 0;
}