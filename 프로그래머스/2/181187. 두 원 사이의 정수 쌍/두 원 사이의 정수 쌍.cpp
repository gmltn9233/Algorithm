#include <bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int i=0; i<=r2; i++){
        long long max_num = floor(sqrt(pow(r2,2)-pow(i,2)));
        long long min_num = 0;
        if (i<=r1){
            min_num = ceil(sqrt(pow(r1,2)-pow(i,2)));
        }
        
        answer += (max_num-min_num+1);
    }
    answer *=4;
    long long minus = 0;
    if(r1==0){
        minus = 4*r2+3;
    }else{
        minus = 4*(r2-r1+1);
    }
    
    
    return answer-minus;
}

//r1^2 - x^2 <= y^2 <= r2^2 - x^2

