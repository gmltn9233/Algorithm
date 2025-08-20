#include <bits/stdc++.h>
using namespace std;
int n;
long long num;
vector<long long> v,v2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            v2.push_back(v[i]+v[j]);
        }
    }
    
    sort(v2.begin(),v2.end());
    
    for(int i=n-1; i>=0; i--){
        for(int j=i; j>=0; j--){
            if(binary_search(v2.begin(),v2.end(),v[i]-v[j])){
                cout<<v[i];
                return 0;
            }
        }
    }
    
    
    return 0;
}