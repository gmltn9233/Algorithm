#include <bits/stdc++.h>

using namespace std;
vector<int> discounts;
int n,max_user,max_amount;
vector<vector<int>> Users;
vector<int> Emoticons;
void check(){
    //cout<<"---------check-------------------\n";
    int now_amount=0;
    int now_user=0;
    int purchase_amount = 0;
    for(auto user : Users){
        int idx = 0;
        now_amount=0;
        for(auto discount : discounts){
            //cout<<user[0]<<","<<discount<<"\n";
            if(user[0] <= discount){
                now_amount += Emoticons[idx]*(100-discount)/100;
            }
            idx++;
        }
        if(now_amount >= user[1]){
            ++now_user;
        }
        else{
            purchase_amount += now_amount;
            //cout<<"purchase_amount: "<<purchase_amount<<"\n";
        }
    }
    //cout<<"now_user: "<<now_user<<"\n";
    
    if (now_user > max_user || 
    (now_user == max_user && purchase_amount > max_amount)) {
        max_user = now_user;
        max_amount = purchase_amount;
    }
}
void go(int idx){
    if(idx == n){
        check();
        return;
    }
    for(int i=1; i<=4; i++){
        discounts.push_back(i*10);
        go(idx+1);
        discounts.pop_back();
    }
    return;
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    Users = users;
    Emoticons = emoticons;
    n = emoticons.size();
    vector<int> answer;
    go(0);
    answer.push_back(max_user);
    answer.push_back(max_amount);
    return answer;
}


// 목표 1. 이모티콘 플러스 가입자 최대
// 목표 2. 이모티콘 판매액 최대

// 1 <= n <= 100
// 1 <= m <= 7

// 할인율 (10,20,30,40%)
// 사용자 행동
// 1. 기준 할인율보다 높을 시 모두 구매
// 2. 구매 비용의 합이 기준보다 높을 시 이모티콘 플러스 서비스 가입

// 사용자의 최대 구매액수를 채울만큼 할인하되, 가능한 할인 중 최소가 되도록


// 
