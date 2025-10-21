#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey>0){
        int now = storey%10;
        if(now > 5){
            answer += 10-now;
            storey = storey/10 +1;
        }
        else if(now < 5){
            answer += now;
            storey /= 10;
        }
        else{
            answer += now;
            int next = (storey/10)%10;
            if(next >=5) storey = storey/10 +1;
            else storey/=10;
        }
    }
    return answer;
}