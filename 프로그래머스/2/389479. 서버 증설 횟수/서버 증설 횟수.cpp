#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    map<int,int> mp;
    int now = 0;
    int ret = 0;
    for(int i=0; i<24; i++){
        //cout<<"-----------idx: "<<i<<"\n";
        if(mp[i]!=0){
            //cout<<"서버 close\n";
            now -= mp[i];
        }
        //cout<<"now: "<<(now+1)*m<<'\n';
        // 증설해야한다면
        if(players[i] >= (now+1)*m){
            //cout<<"증설해야합니다!\n";
            int plus = (players[i]-((now+1)*m))/m + 1;
            //cout<<plus<<"만큼 증설\n";
            now += plus;
            mp[i+k] = plus;
            ret +=plus;
        }
    }
    return ret;
}