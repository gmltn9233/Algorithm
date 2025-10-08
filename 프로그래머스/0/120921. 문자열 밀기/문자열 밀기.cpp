#include <bits/stdc++.h>

using namespace std;

int solution(string A, string B) {
    int answer = 101;
    if(A.length()!=B.length()) return -1;
    for(int i=0; i<A.length(); i++){
        string now = B.substr(i)+B.substr(0,i);
        if(A==now) answer = min(answer,i);
    }
    if(answer == 101) return -1;
    return answer;
}