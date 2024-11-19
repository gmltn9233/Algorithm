#include<bits/stdc++.h>

using namespace std;
map<string,int> mp;
bool solution(vector<string> phone_book) {
    for(string s : phone_book){
        mp[s]++;
    }
    for(auto it : mp){
        for(int j=1; j<it.first.size(); j++){
            string s = it.first.substr(0,j);
            if(mp.find(s)!=mp.end()){
                return false;
            }
        }
    }
    return true;
}