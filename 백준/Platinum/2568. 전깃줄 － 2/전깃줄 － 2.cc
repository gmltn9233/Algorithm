#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<pair<int,int>> v,v2;
vector<int> lis;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(), v.end());
    
    for(auto it : v){
        auto idx = lower_bound(lis.begin(),lis.end(), it.second);
        if(idx == lis.end()){
            lis.push_back(it.second);
            v2.push_back({lis.size()-1,it.first});
        }else{
            *idx = it.second;
            v2.push_back({idx-lis.begin(),it.first});
        }
    }
    
    stack<int> st;
    int len = lis.size();
    cout<<n-len<<"\n";
    len--;
    for(int i=v2.size()-1; i>=0; i--){
        if(v2[i].first == len){
            len --;
        }else{
            st.push(v2[i].second);
        }
        
    }
    
    vector<int> ret;
    
    while(st.size()){
        ret.push_back(st.top());
        st.pop();
    }
    
    sort(ret.begin(),ret.end());
    for(auto it : ret){
        cout<<it<<"\n";
    }
    return 0;
}