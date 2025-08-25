#include <bits/stdc++.h>
using namespace std;
int n;
long long num;
vector<long long> v,v2;
set<long long> st;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        v.push_back(num);
        st.insert(num);
    }
    vector<long long> v2(st.begin(),st.end());
    for(auto it : v){
        cout<<lower_bound(v2.begin(),v2.end(),it)-v2.begin()<<" ";
    }

    return 0;
}