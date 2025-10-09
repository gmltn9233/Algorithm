#include <bits/stdc++.h>
using namespace std;
set<int>dp[9];
int solution(int N, int number) {
    for(int i=1; i<=8; i++){
        int num = 0;
        for(int j=0; j<i; j++){
            num = num*10 + N;
        }
        dp[i].insert(num);
        for(int j=1; j<i; j++){
            for(auto a : dp[j]){
                for(auto b : dp[i-j]){
                    dp[i].insert(a+b);
                    dp[i].insert(a*b);
                    dp[i].insert(a-b);
                    if(b!=0) dp[i].insert(a/b);
                }
            }
        }
        if(dp[i].count(number)) return i;
    }
    return -1;
}