#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    for(vector<string> v : db){
        mp[v[0]]=v[1];
    }
    for(auto it : mp){
        if(it.first == id_pw[0]){
            if(it.second == id_pw[1]) return "login";
            else return "wrong pw";
        }
    }
    return "fail";
}