#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    int i = 0;
    for(; i<enemy.size(); i++){
        //cout<<"i:"<<i<<" enemy[i]: "<<enemy[i]<<", n: "<<n<<" k: "<<k<<"\n";
        if(n<enemy[i]){
            //cout<<"큼\n";
            if(k>0) k--;
            else return i;
            
            if(pq.size()){
                if(pq.top() > enemy[i]){
                    n += pq.top() - enemy[i];
                    pq.pop();
                    pq.push(enemy[i]);
                }
            }
        }else{
            //cout<<enemy[i]<<" 삽입\n";
            pq.push(enemy[i]);
            n -= enemy[i];
        }
    }
    return enemy.size();
}
// 진행하면서 현재까지의 원소 내림차순 저장
// 진행불가 시 k 소모해서 진행
