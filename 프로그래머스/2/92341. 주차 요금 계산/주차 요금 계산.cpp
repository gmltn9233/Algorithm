#include <bits/stdc++.h>

using namespace std;
vector<int> in[10004];
vector<int> out[10004];
set<int> car_num;
vector<string> split(string s){
    vector<string> v;
    string token = "";
    for(char c : s){
        if(c==' '){
            if(!token.empty()){
                v.push_back(token);
                token="";
            }
        }else{
            token+=c;
        }
    }
    if(!token.empty()) v.push_back(token);
    return v;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    //fill(&out[0],&out[0]+10004,23*60+59);
    // 1. record
    for(string record : records){
        vector<string> s = split(record);
        //cout<<s[0]<<","<<s[1]<<","<<s[2]<<"\n";
        int time = stoi(s[0].substr(0,2))*60+stoi(s[0].substr(3));
        int num = stoi(s[1]);
        car_num.insert(num);
        //cout<<time<<","<<num<<"\n";
        if(s[2]=="IN"){
            in[num].push_back(time);
        }else{
            out[num].push_back(time);
        }
    }
    
    // 2. calculate
    for(auto it : car_num){
        if(out[it].size()!=in[it].size()) out[it].push_back(23*60+59);
        int gap = 0;
        for(int i=0; i<out[it].size(); i++){
            gap += out[it][i] - in[it][i];
        }
        
        //cout<<it<<","<<gap<<"\n";
        int price = 0;
        if(gap < fees[0]) answer.push_back(fees[1]);
        else{
            price = fees[1]+(gap-fees[0])/fees[2]*fees[3];
            if((gap-fees[0])%fees[2]) price += fees[3];
            answer.push_back(price);
        }
    }
    return answer;
}