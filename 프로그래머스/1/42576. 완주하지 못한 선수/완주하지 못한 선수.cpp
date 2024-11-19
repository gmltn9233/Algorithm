#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(string s : participant){
        mp[s]++;
    }
    for(string s : completion){
        mp[s]--;
    }
    for(auto it : mp){
        if(it.second != 0){
            answer += it.first;
        }
    }
    return answer;
}