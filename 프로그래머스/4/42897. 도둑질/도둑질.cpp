#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int n =money.size();
    vector<int> dp1(n,0), dp2(n,0);
    // case 1 : 0번집 털고 마지막 x
    dp1[0] = money[0];
    dp1[1] = money[0];
    for(int i=2; i<n-1; i++){
        dp1[i] = max(dp1[i-2]+money[i], dp1[i-1]);
    }
    // case 2 : 1번집부터 털기
    dp2[1] = money[1];
    dp2[2] = max(money[1], money[2]);
    for(int i=3; i<n; i++){
        dp2[i] = max(dp2[i-2]+money[i], dp2[i-1]);
    }
    
    int answer = max(dp1[n-2],dp2[n-1]);
    return answer;
}