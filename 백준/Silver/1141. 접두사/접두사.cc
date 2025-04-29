/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n,cnt;
vector<string> v;
bool isX(string a, string b){
    if(a.size() > b.size()) swap(a, b); // 항상 a가 짧거나 같게
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1; i>=1; i--){
    
        if(!isX(v[i],v[i-1])){
            
            ++cnt;
        }
    }
    cnt++;
    cout<<cnt;
    return 0;
}