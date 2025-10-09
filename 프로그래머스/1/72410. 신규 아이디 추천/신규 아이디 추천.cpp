#include <bits/stdc++.h>

using namespace std;
bool check(char c){
    if((c>='a'&& c<='z') || isdigit(c) || c=='-' || c=='_' || c=='.') return true;
    return false;
}
string solution(string new_id) {
    // 1. 소문자 치환
    for(auto &it : new_id){
        if(it >= 'A' && it <= 'Z') it = it-'A'+'a';
    }
    
    // 2. 규격 외 제거
    string now = "";
    for(auto it : new_id){
        if(check(it)) now+= it;
    }
    new_id = now;
    
    
    // 3. 연속된 . 제거
    now = new_id[0];
    for(int i=1; i<new_id.length(); i++){
        if(new_id[i]=='.' && new_id[i-1]=='.') continue;
        now += new_id[i];
    }
    new_id = now;
    
    // 4. 처음이나 끝 . 제거
    if(new_id.front()=='.') new_id.erase(0,1);
    if(new_id.back()=='.') new_id.pop_back();
    
    // 5. 빈 문자열
    if(new_id.empty()) new_id ="a";
    
    // 6. 길이
    if(new_id.length() >=16) new_id = new_id.substr(0,15);
    
    if(new_id.back()=='.') new_id.pop_back();
    
    // 7. 길이 2자 이하
    while(new_id.length() < 3){
        new_id+= new_id.back();
    }
    return new_id;
}