/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>ch[26];
string s;
char a;
int q,l,r;
map<char,int> mp;
void find(char a, int l, int r){
    int leftNum = 0;
    int rightNum = 0;
    vector<pair<int,int>> v = ch[a-'a'];
    for(auto at : v){
        // cout<<at.first<<","<<l<<"\n";
        if(at.first >= l){
            break;
        }
        leftNum = at.second;
    }
    //cout << "left: " << leftNum << "\n";
    for(int i=ch[a-'a'].size()-1; i>=0; i--){
        if(ch[a-'a'][i].first <= r){
            rightNum = ch[a-'a'][i].second;
            break;
        }
    }
    //cout<<"right: "<<rightNum<<"\n";
    cout<<rightNum - leftNum<<"\n";
}
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++;
        ch[s[i]-'a'].push_back({i,mp[s[i]]});
    }
    cin>>q;
    while(q--){
        cin>>a>>l>>r;
        find(a,l,r);
    }
    return 0;
}
