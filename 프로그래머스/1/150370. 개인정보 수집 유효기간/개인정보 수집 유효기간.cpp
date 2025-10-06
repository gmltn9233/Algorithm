#include <bits/stdc++.h>

using namespace std;
int day_to_int(string s){
    return stoi(s.substr(0,4))*12+stoi(s.substr(5,2));
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> mp;
    for(auto it : terms){
        char term = it[0];
        int duration = stoi(it.substr(2));
        mp[term] = duration;
    }
    
    int today_int = day_to_int(today);
    for(int i=0; i<privacies.size(); i++){
        int duration = day_to_int(privacies[i].substr(0,10))+mp[privacies[i][privacies[i].size()-1]];
        // cout<<2021*12+07+12<<"\n";
        // cout<<day_to_int(privacies[i].substr(0,10))<<"\n";
        // cout<<privacies[i][privacies[i].size()-1]<<"\n";
        // cout<<mp[privacies[i][privacies[i].size()-1]]<<"\n";
        // cout<<today_int<<","<<duration<<"\n";
        if(today_int > duration) answer.push_back(i+1);
        if(today_int == duration){
            //cout<<stoi(today.substr(8,2))<<","<<stoi(privacies[i].substr(8,2))<<"\n";
            if(stoi(today.substr(8,2))>stoi(privacies[i].substr(8,2))-1) answer.push_back(i+1);
        }
    }
    
    return answer;
}