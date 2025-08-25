#include <bits/stdc++.h>
using namespace std;
int n;
long long num;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        auto it = lower_bound(v.begin(),v.end(),num);
        if(it == v.end()) v.push_back(num);
        else *it = num;
    }
    cout<<v.size();
    return 0;
}