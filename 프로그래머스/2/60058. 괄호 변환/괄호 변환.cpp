#include<bits/stdc++.h>

using namespace std;

bool check(string p){
    stack<char> s;
    for(char c : p){
        if(c=='('){
            s.push(c);
        }
        if(s.size()){
            if(c==')'){
                if(s.top()=='('){
                    s.pop();
                }
            }
        }
    }
    if(s.size()){
        return false;
    }
    else{
        return true;
    }
}
string go(string p){
    if(check(p)) return p;
    int i=0,cnt1 = 0, cnt2 =0;
    for(i=0; i<p.size(); i++){
        if(p[i]=='(') cnt1 ++;
        else{
            cnt2 ++;
        }
        if(cnt1 == cnt2 )break;
    }
    string b = p.substr(0,i+1);
    string c = p.substr(i+1);
    if(check(b)){
        return b + go(c);
    }
    else{
        string ret = "";
        ret +='(';
        ret += go(c);
        ret +=')';
        for(int i=1; i<b.size()-1; i++){
            if(b[i]==')'){
                ret+='(';
            }
            else ret +=')';
        }
        return ret;
    }
}
string solution(string p) {
    string answer = go(p);
    return answer;
}