#include <bits/stdc++.h>

using namespace std;
int a[33];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    fill(a,a+33,1);
    for(auto it : lost){
        a[it]--;
    }
    for(auto it : reserve){
        a[it]++;
    }
    for(int i=1; i<=n; i++){
        if(a[i]==0){
            if(a[i-1]==2){
                a[i] = 1;
                a[i-1] = 1;
                continue;
            }
            if(a[i+1]==2){
                a[i] = 1;
                a[i+1] = 1;
                continue;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(a[i]>=1) ++answer;
    }
    return answer;
}