#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
vector<string> v1,v2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s;
        v1.push_back(s);
    }
    for(int i=0; i<m; i++){
        cin>>s;
        v2.push_back(s);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<string> answer;
    for(int i=0,j=0; i<n && j<m;){
        if(v1[i]==v2[j]){
            answer.push_back(v1[i]);
            ++i,++j;
        }else{
            if(v1[i] > v2[j]){
                j++;
            }else{
                i++;
            }
        }
    }
    
    cout<<answer.size()<<"\n";
    for(auto it : answer){
        cout<<it<<"\n";
    }
    return 0;
}