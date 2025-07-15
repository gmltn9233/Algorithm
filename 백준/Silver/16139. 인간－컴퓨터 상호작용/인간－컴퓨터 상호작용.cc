/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
string s;
int ret[26][200001];
map<char,int> mp;
int q,l,r;
char c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
        for(int j=0; j<26; j++){
            ret[j][i]=mp['a'+j];
        }
    }
    cin>>q;
    while(q--){
        cin>>c>>l>>r;
        if(l==0) cout<< ret[c-'a'][r]<<"\n";
        else cout<<ret[c-'a'][r]-ret[c-'a'][l-1]<<"\n";
    }

    return 0;
}