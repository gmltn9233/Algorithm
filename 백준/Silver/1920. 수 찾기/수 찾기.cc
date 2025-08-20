#include <bits/stdc++.h>
using namespace std;
int n,m;
long long num;
set<long long> a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        a.insert(num);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>> num;
        if(a.find(num)!=a.end()) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    
    return 0;
}