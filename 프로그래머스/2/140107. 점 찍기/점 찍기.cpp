#include <bits/stdc++.h>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long max_dis = d-(d%k);
    answer += (d/k+1);
    long long prev = max_dis;
    for(long long x=k; x<=max_dis; x+=k){
        int num = 0;
        for(long long y=prev; y>=0; y-=k){
            //cout<<"y: "<<y<<", x:"<<x<<"\n";
            long long dis = y*y + x*x;
            num = y;
            if((long long)d*d >= dis){
                //cout<<"기준:"<<y<<","<<x<<"\n";
                answer += (y/k+1);
                break;
            }
        }
        prev = num;
    }
    return answer;
}

