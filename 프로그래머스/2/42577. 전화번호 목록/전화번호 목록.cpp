#include<bits/stdc++.h>

using namespace std;
map<string,int> mp;
bool solution(vector<string> phone_book) {
    for(int i=0; i<phone_book.size(); i++){
        mp[phone_book[i]] = i;
    }
    for(auto it: mp){
        //cout<<it.first<<"\n";
        for(int j=1; j<it.first.size(); j++){
            string s = it.first.substr(0,j);
            //cout<<s<<'\n';
            if(mp.find(s) != mp.end()){
                return false;
            }   
        }
    }
    return true;
}