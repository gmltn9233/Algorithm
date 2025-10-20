#include <bits/stdc++.h>

using namespace std;
int time_to_int(string s){
    return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
}
vector<int> v;
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    
    vector<pair<int,int>> int_time;
    for(auto book : book_time){
        int s = time_to_int(book[0]);
        int e = time_to_int(book[1]);
        int_time.push_back({s,e});
    }
    sort(int_time.begin(),int_time.end());
    for(auto book : int_time){
        int s = book.first;
        int e = book.second;
        //cout<<s/60<<":"<<s%60<<","<<e/60<<":"<<e%60<<"\n";
    
        if(v.size()==0) v.push_back(e+10);
        else{
            bool flag = false;
            //cout<<"방 탐색\n";
            for(auto &it : v){
                //cout<<it/60<<":"<<it%60<<"\n";
                if(it <= s){
                    //cout<<"기존 방에 추가\n";
                    it = e+10;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                //cout<<"새로운 방에 추가\n";
                v.push_back(e+10);
            }
        }
        
    }
    return v.size();
}