#include <bits/stdc++.h>

using namespace std;
int gift_score[52];
map<string,int> mp;
int gift_list[52][52];
int gift[52];
vector<string> get_name(string s){
    vector<string> names;
    int idx = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ') idx = i;
    }
    names.push_back(s.substr(0,idx));
    names.push_back(s.substr(idx+1));
    return names;
}
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    
    for(int i=0; i<friends.size(); i++){
        mp[friends[i]]=i+1;
    }
    for(auto it : gifts){
        vector<string> s = get_name(it);
        string from = s[0];
        string to = s[1];
        
        gift_score[mp[from]]++;
        gift_score[mp[to]]--;
        gift_list[mp[from]][mp[to]]++;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if((gift_list[i][j]==0 && gift_list[j][i]==0) || gift_list[i][j]==gift_list[j][i]){
                if(gift_score[i] < gift_score[j]) gift[j]++;
                if(gift_score[i] > gift_score[j]) gift[i]++;
            }
            else{
                gift_list[i][j]<gift_list[j][i] ? gift[j]++ : gift[i]++;
            }
        }
        // for(auto it : friends){
        //     for(auto itt : friends){
        //         int from = mp[it];
        //         int to = mp[itt];
        //         cout<<it<<":"<<gift_list[from][to]<<","<<itt<<":"<<gift_list[to][from]<<"\n";
        //     }
        // }
        for(int i=1; i<=n; i++){
            answer = max(answer,gift[i]/2);
        }
    }
    
    
    
    return answer;
}
