#include<bits/stdc++.h>

using namespace std;
map<string,int> mp;
map<string,vector<pair<int,int>>> mp1;
vector<int> answer;
bool cmp(pair<int,int> a, pair<int,int>b){
    if(a.first == b.first){
        a.second<b.second;
    }
    return a.first>b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();
    for(int i=0; i<n; i++){
        mp[genres[i]]+=plays[i];
        mp1[genres[i]].push_back({plays[i],i});
    }
    vector<pair<int,string>> v;
    for(auto it: mp){
        v.push_back({it.second,it.first});
    }
    sort(v.begin(),v.end(),greater<pair<int,string>>());

    for(int i=0; i<v.size(); i++){
        vector<pair<int,int>> v2 = mp1[v[i].second];
        sort(v2.begin(),v2.end(),cmp);
        answer.push_back(v2[0].second);
        if(v2.size()>1){
            answer.push_back(v2[1].second);
        }
        
    }
    return answer;
}