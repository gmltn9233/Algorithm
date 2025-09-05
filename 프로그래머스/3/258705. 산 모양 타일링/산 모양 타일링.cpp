#include <bits/stdc++.h>

using namespace std;
const int NUM = 10007;
vector<int> topS;
int N;
int go(int idx){
    if(idx >= 2*(N+1)){
        if(idx == 2*(N+1)){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int ret = 0;
    // 짝수일때
    if(idx%2==0){
        ret = (go(idx+1)+go(idx+2))%NUM;
    }
    // 홀수일때
    else{
        ret = (go(idx+2)+go(idx+3))%NUM;
        if(topS[(idx-1)/2]==1){
            ret =(ret + go(idx+2))%NUM;
        }
    }
    
    return ret%NUM;
}
int solution(int n, vector<int> tops) {
    N=n;
    topS = tops;
    
    int answer = go(0);
    return answer;
}

// 1.짝수일때
// 삼각형 +1
// 마름모 +2

// 2.홀수일때
// 삼각형 +2
// 마름모 +3
// 다이아 +2


