#include <bits/stdc++.h>
using namespace std;
int n;
long long num;
vector<long long> v2;
vector<pair<int,long long>> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        auto it = lower_bound(v2.begin(),v2.end(),num);
        if(it==v2.end()){
            v2.push_back(num);
            v.push_back({v2.size()-1,num});
        }
        else{
            *it = num;
            v.push_back({it-v2.begin(),num});
        } 
    }
    
    int len = v2.size();
    cout<<len<<"\n";
    stack<long long> st;
    --len;
    for(int i=v.size()-1; i>=0; i--){
        //cout<<"i: "<<i<<" num:"<<v[i].second<<" idx: "<<v[i].first<<"\n";
        if(v[i].first==len){
            len--;
            st.push(v[i].second);
        }
    }
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}