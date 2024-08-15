#include<bits/stdc++.h> 
using namespace std;
vector<string> answer;
// 시간을 정수(분)으로 변환
int timeToInt(string s){
    return (60 * stoi(s.substr(0, 2))) + stoi(s.substr(3));
}

bool cmp(vector<string> v1, vector<string>v2){
    return  timeToInt(v1[1]) < timeToInt(v2[1]);
}
vector<string> solution(vector<vector<string>> plans) {
    // 시작시간 기준으로 정렬
    sort(plans.begin(), plans.end(), cmp);
    
    // 처리못한 과제
    stack<pair<string,int>> s;
    
    // 첫번째 과제 기준으로 초기화
    string prev = plans[0][0];
    int end_time = timeToInt(plans[0][1]) + stoi(plans[0][2]);
    
    for(int i=1; i<plans.size(); i++){
        // 다음 시작시간까지 과제 성공
        if(timeToInt(plans[i][1]) >= end_time){
            answer.push_back(prev);
            // 남은 시간
            int t = timeToInt(plans[i][1]) - end_time;
            while(t>0 && !s.empty()){
                if(s.top().second<=t){
                    answer.push_back(s.top().first);
                    t-= s.top().second;
                    s.pop();
                }
                else{
                    s.top().second-= t;
                    t=0;
                }
            }
        }
        else{
            // 완료하지 못함
            s.push({prev,end_time - timeToInt(plans[i][1])});
        }
        prev = plans[i][0];
        end_time = timeToInt(plans[i][1]) + stoi(plans[i][2]);
    }
    answer.push_back(prev);
    
    while(!s.empty()){
        answer.push_back(s.top().first);
        s.pop();
    }

    return answer;
}