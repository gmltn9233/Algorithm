#include <bits/stdc++.h>

using namespace std;
vector<int> d;
vector<int> p;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    vector<int> d, p;

    for(int i=0; i<n; i++){
        if(deliveries[i] > 0) d.push_back(i);
        if(pickups[i] > 0) p.push_back(i);
    }
    
    while(!d.empty() || !p.empty()){
        int d_distance = d.empty() ? 0 : d.back()+1;
        int p_distance = p.empty() ? 0 : p.back()+1;
        int distance = max(d_distance, p_distance);

        int amount = cap;

        // 배달
        while(amount && !d.empty()){
            int idx = d.back();
            if(deliveries[idx] <= amount){
                amount -= deliveries[idx];
                deliveries[idx] = 0;
                d.pop_back();
            } else {
                deliveries[idx] -= amount;
                amount = 0;
            }
        }

        amount = cap;

        // 수거
        while(amount && !p.empty()){
            int idx = p.back();
            if(pickups[idx] <= amount){
                amount -= pickups[idx];
                pickups[idx] = 0;
                p.pop_back();
            } else {
                pickups[idx] -= amount;
                amount = 0;
            }
        }

        answer += (long long)distance * 2;
    }
    return answer;
}