#include <bits/stdc++.h>
using namespace std;
int n,num,ret=1,cnt=1;
vector<pair<int,int>> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        v.push_back({num,i});
    }
    sort(v.begin(),v.end());
    
    
    for(int i=1; i<n; i++){
        if(v[i-1].second < v[i].second){
            cnt++;
            ret = max(ret,cnt);
        }else{
            cnt = 1;
        }
    }
    
    cout<<n-ret;
    
    
    return 0;
}


