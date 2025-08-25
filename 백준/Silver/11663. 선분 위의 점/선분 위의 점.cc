#include <bits/stdc++.h>
using namespace std;
int n,m;
long long num,a,b;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<m; i++){
        cin>>a>>b;
        cout<<upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a)<<"\n";
    }

    return 0;
}