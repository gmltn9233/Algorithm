#include<bits/stdc++.h>

using namespace std;

//len개 단위로 잘랐을때 압축한 길이 return
int go(string s, int len){
    string answer = "";
    string prev = "";
    int cnt = 1;
    for(int i=0; i<len; i++){
        prev += s[i];
    }
    for(int i=len; i<=s.size()-len; i+=len){
        string now = "";
        for(int j=i; j<i+len; j++){
            now += s[j];
        }
        //같다면
        if(!prev.compare(now)){
            cnt ++;
        }
        //다르다면
        else{
            if(cnt>1){
                answer +=to_string(cnt);
                answer +=prev;
            }
            else{
                answer +=prev;
            }
            cnt = 1;
        }
        prev = now;
    }
    //마지막은 비교를 못하므로 처리
    if(cnt==1){
        answer += prev;
    }
    else{
        answer += to_string(cnt);
        answer +=prev;
    }
    if(s.size()%len){
        for(int i=(s.size()/len)*len; i<s.size(); i++){
            answer +=s[i];
        }
    }
    //cout<<answer<<"\n";
    //cout<<answer.size()<<"\n";
    return answer.size();
}
int solution(string s) {
    int answer = s.size();
    for(int i=1; i<=s.size()/2; i++){
        //cout<<"idx: "<<i<<"\n";
        answer = min(answer,go(s,i));
    }
    return answer;
}

