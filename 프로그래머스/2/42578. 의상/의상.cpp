#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int solution(vector<vector<string>> clothes) {
    for(vector<string> c : clothes){
        mp[c[1]]++;
    }
    int answer = 1;
    for(auto it : mp){
        answer *= (it.second+1);
    }
    --answer;
    return answer;
}