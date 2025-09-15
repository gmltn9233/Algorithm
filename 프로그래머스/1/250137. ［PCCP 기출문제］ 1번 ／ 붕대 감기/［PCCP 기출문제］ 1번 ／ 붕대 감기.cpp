#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int max_health = health;
    int cnt = 0;
    int idx = 0;
    for(int i=1; i<=1000; i++){
        if(idx == attacks.size()) break;
        if(i==attacks[idx][0]){
            health-=attacks[idx][1];
            if(health<=0){
                return -1;
            }
            idx++;
            cnt = 0;
        }else{
            cnt++;
            health=min(max_health,health+bandage[1]);
            if(cnt==bandage[0]){
                cnt = 0;
                health=min(max_health,health+bandage[2]);
            }
        }
        //cout<<"time: "<<i<<", health: "<<health<<"\n";
    }
    return health;
}